#pragma once
#include "Vector3.h"
#include <vector>
#include "EngineDef.h"
namespace NLS
{
using namespace NLS::Maths;
namespace Engine
{
class NLS_ENGINE_API NavigationPath
{
public:
    NavigationPath() {}
    ~NavigationPath() {}

    void Clear()
    {
        waypoints.clear();
    }
    void PushWaypoint(const Vector3& wp)
    {
        waypoints.emplace_back(wp);
    }
    bool PopWaypoint(Vector3& waypoint)
    {
        if (waypoints.empty())
        {
            return false;
        }
        waypoint = waypoints.back();
        waypoints.pop_back();
        return true;
    }

protected:
    std::vector<Vector3> waypoints;
};
} // namespace Engine
} // namespace NLS
