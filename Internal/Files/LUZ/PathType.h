#pragma once

#include <cstdint>

enum class PathType : uint32_t {
    Movement,
    MovingPlatform,
    Property,
    Camera,
    Spawner,
    Showcase,
    Race,
    Rail
};