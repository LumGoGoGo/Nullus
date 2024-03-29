#pragma once
#include "Matrix4.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "EngineDef.h"
#include <vector>
#include "Component.h"

using std::vector;

using namespace NLS::Maths;

namespace NLS
{
namespace Engine
{
class NLS_ENGINE_API Transform :public Component
{
public:
    Transform();
    ~Transform();

    Transform& SetPosition(const Vector3& worldPos);
    Transform& SetScale(const Vector3& worldScale);
    Transform& SetOrientation(const Quaternion& newOr);

    Vector3 GetPosition() const
    {
        return position;
    }

    Vector3 GetScale() const
    {
        return scale;
    }

    Quaternion GetOrientation() const
    {
        return orientation;
    }

    Matrix4 GetMatrix() const
    {
        return matrix;
    }
    void UpdateMatrix();

protected:
    Matrix4 matrix;
    Quaternion orientation;
    Vector3 position;

    Vector3 scale;
};
} // namespace Engine
} // namespace NLS
