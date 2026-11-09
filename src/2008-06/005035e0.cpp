// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_rendersurfacenativeptr2f4580779ea02c3c.cpp

// Candidate translation unit (score above; library headers required).
#include <windows.h>
#include "G3D/ReferenceCount.h"
#include "G3D/Array.h"
#include "G3D/CoordinateFrame.h"

namespace RBX {
namespace Render {

struct Control : G3D::ReferenceCountedObject { virtual ~Control(); };
typedef G3D::ReferenceCountedPointer<Control> ControlPtr;

class RenderSurface {
public:
    G3D::CoordinateFrame cframe;
    int flags;
    int a;
    float b;
    int c;
    ControlPtr shader;
    RenderSurface() : a(0), b(0), c(0) {}
    __forceinline ~RenderSurface() {}
};

void (G3D::Array<RenderSurface>::*forceResize)(int, bool) = &G3D::Array<RenderSurface>::resize;
}
}
