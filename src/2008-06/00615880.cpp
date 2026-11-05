// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_arrowdistancelimit_8be1892c193d15f1.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
using namespace G3D;
struct Object { const CoordinateFrame& getTransform(); };
extern Object* __cdecl resolve(void*);
extern const double threshold;
struct S { char padding[24];void* object;int f(const Vector3&);};
int S::f(const Vector3& point){if(resolve(object)){Object* p=resolve(object);float distance=p?(p->getTransform().translation-point).magnitude():0.0f;if(threshold>distance)return 1;}return 0;}
