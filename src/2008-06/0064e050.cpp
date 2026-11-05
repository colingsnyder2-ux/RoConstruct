// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_toolraynative_6f4459e1166a22b5.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Ray.h"
#include "G3D/CoordinateFrame.h"
using namespace G3D;
struct Camera { Ray transform(const Ray&); };
struct S {
 char padding[0x130]; Ray ray; char remaining[0x18]; Camera* camera;
 void update(); CoordinateFrame frame();
};
CoordinateFrame S::frame(){
 update(); Ray r;
 if(camera)r=camera->transform(ray);
 CoordinateFrame result(r.origin);
 result.lookAt(r.origin+r.direction);
 return result;
}
