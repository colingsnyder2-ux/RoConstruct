#pragma once
// 2008-06 native SurfaceType enum. Used by PartInstance surfaces and reflection.

namespace RBX
{
    enum SurfaceType
    {
        NO_SURFACE = 0,
        STUDS = 1,
        INLET = 2,
        WELD = 3,
        GLUE = 4
    };
}