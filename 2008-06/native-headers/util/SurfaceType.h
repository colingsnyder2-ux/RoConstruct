#pragma once
// 2008-06 native SurfaceType enum. Used by PartInstance surfaces and reflection.

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