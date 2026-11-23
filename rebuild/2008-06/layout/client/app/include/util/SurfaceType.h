#pragma once

namespace RBX
{
    enum SurfaceType
    {
        // Donor order; ROTATE_V == 7 (RightMotorTool::applyToSurface pushes 7).
        NO_SURFACE,
        GLUE,
        WELD,
        STUDS,
        INLET,
        SPAWN_deprecated,
        ROTATE,
        ROTATE_V,
        ROTATE_P,
        NUM_SURF_TYPES
    };
}
