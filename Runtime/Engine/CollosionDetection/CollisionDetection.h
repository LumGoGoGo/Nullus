#pragma once

#include "Camera.h"
#include "Plane.h"

#include "Transform.h"
#include "GameObject.h"

#include "AABBVolume.h"
#include "OBBVolume.h"
#include "SphereVolume.h"
#include "CapsuleVolume.h"
#include "Ray.h"
#include "EngineDef.h"
using NLS::Camera;
using namespace NLS::Maths;
using namespace NLS::Engine;
namespace NLS
{
class NLS_ENGINE_API CollisionDetection
{
public:
    struct ContactPoint
    {
        Vector3 localA;
        Vector3 localB;
        Vector3 normal;
        float penetration;
    };
    struct CollisionInfo
    {
        GameObject* a;
        GameObject* b;
        mutable int framesLeft;

        ContactPoint point;

        void AddContactPoint(const Vector3& localA, const Vector3& localB, const Vector3& normal, float p)
        {
            point.localA = localA;
            point.localB = localB;
            point.normal = normal;
            point.penetration = p;
        }

        // Advanced collision detection / resolution
        bool operator<(const CollisionInfo& other) const
        {
            size_t otherHash = (size_t)other.a->GetWorldID() + ((size_t)other.b->GetWorldID() << 32);
            size_t thisHash = (size_t)a->GetWorldID() + ((size_t)b->GetWorldID() << 32);

            if (thisHash < otherHash)
            {
                return true;
            }
            return false;
        }

        bool operator==(const CollisionInfo& other) const
        {
            if (other.a == a && other.b == b)
            {
                return true;
            }
            return false;
        }
    };

    static bool SphereCapsuleIntersection(
        const CapsuleVolume& volumeA, const Engine::Transform& worldTransformA,
        const SphereVolume& volumeB, const Engine::Transform& worldTransformB, CollisionInfo& collisionInfo);

    // TODO ADD THIS PROPERLY
    static bool RayBoxIntersection(const Ray& r, const Vector3& boxPos, const Vector3& boxSize, RayCollision& collision);

    static Ray BuildRayFromMouse(const Camera& c);

    static bool RayIntersection(const Ray& r, GameObject& object, RayCollision& collisions);


    static bool RayAABBIntersection(const Ray& r, const Engine::Transform& worldTransform, const AABBVolume& volume, RayCollision& collision);
    static bool RayOBBIntersection(const Ray& r, const Engine::Transform& worldTransform, const OBBVolume& volume, RayCollision& collision);
    static bool RaySphereIntersection(const Ray& r, const Engine::Transform& worldTransform, const SphereVolume& volume, RayCollision& collision);
    static bool RayCapsuleIntersection(const Ray& r, const Engine::Transform& worldTransform, const CapsuleVolume& volume, RayCollision& collision);


    static bool RayPlaneIntersection(const Ray& r, const Plane& p, RayCollision& collisions);

    static bool AABBTest(const Vector3& posA, const Vector3& posB, const Vector3& halfSizeA, const Vector3& halfSizeB);


    static bool ObjectIntersection(GameObject* a, GameObject* b, CollisionInfo& collisionInfo);


    static bool AABBIntersection(const AABBVolume& volumeA, const Engine::Transform& worldTransformA,
                                 const AABBVolume& volumeB, const Engine::Transform& worldTransformB, CollisionInfo& collisionInfo);

    static bool SphereIntersection(const SphereVolume& volumeA, const Engine::Transform& worldTransformA,
                                   const SphereVolume& volumeB, const Engine::Transform& worldTransformB, CollisionInfo& collisionInfo);

    static bool AABBSphereIntersection(const AABBVolume& volumeA, const Engine::Transform& worldTransformA,
                                       const SphereVolume& volumeB, const Engine::Transform& worldTransformB, CollisionInfo& collisionInfo);

    static bool OBBIntersection(const OBBVolume& volumeA, const Engine::Transform& worldTransformA,
                                const OBBVolume& volumeB, const Engine::Transform& worldTransformB, CollisionInfo& collisionInfo);

    static Vector3 Unproject(const Vector3& screenPos, const Camera& cam);

    static Vector3 UnprojectScreenPosition(Vector3 position, float aspect, float fov, const Camera& c);
    static Matrix4 GenerateInverseProjection(float aspect, float fov, float nearPlane, float farPlane);
    static Matrix4 GenerateInverseView(const Camera& c);

protected:
private:
    CollisionDetection() {}
    ~CollisionDetection() {}
};
} // namespace NLS
