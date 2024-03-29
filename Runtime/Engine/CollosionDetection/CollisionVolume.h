#pragma once
#include "EngineDef.h"
#include "Component.h"
namespace NLS
{
enum class NLS_ENGINE_API VolumeType
{
    AABB = 1,
    OBB = 2,
    Sphere = 4,
    Mesh = 8,
    Capsule = 16,
    Compound = 32,
    Invalid = 256
};

class NLS_ENGINE_API CollisionVolume : public Engine::Component
{
public:
    CollisionVolume()
    {
        type = VolumeType::Invalid;
    }
    ~CollisionVolume() {}

    VolumeType type;
};
} // namespace NLS