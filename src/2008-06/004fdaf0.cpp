// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_headbuildertypes0a151120971a9ebd.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/Vector3.h"
// from server: 84% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" {
    __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}

struct Control {
    virtual ~Control();
    volatile long references;
    void release();
};

struct Handle {
    Control *pointer;
    ~Handle();
};

inline Handle::~Handle()
{
    if (pointer && InterlockedDecrement(&pointer->references) == 0) {
        pointer->release();
        if (pointer)
            delete pointer;
    }
}

typedef G3D::Vector3 Vector;
inline const float& minimum(const float& a, const float& b)
{
    return a < b ? a : b;
}

struct SurfaceTypes {unsigned value;SurfaceTypes():value(0){}};
struct Base {
    virtual ~Base();
    char padding[28];
    Base(const Handle&, Vector, SurfaceTypes);
};

struct CylinderBuilder : Base {
    float radius;
    int value;
    CylinderBuilder(Handle, Vector, SurfaceTypes, int, float);
    virtual ~CylinderBuilder();
};

CylinderBuilder::CylinderBuilder(
    Handle handle, Vector size,
    SurfaceTypes purpose, int suppliedValue, float suppliedRadius)
    : Base(handle, Vector(minimum(size.z, size.x), size.y, minimum(size.z, size.x)), purpose),
      radius(suppliedRadius),
      value(suppliedValue)
{
}
