// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_arrowdistancenative_dbd0b9de14035125.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
using namespace G3D;
struct Object { const CoordinateFrame& getTransform(); };
extern Object* __cdecl findObject(void*);
struct ArrowTool { char padding[0x18];void* object;float distance(const Vector3&);};
float ArrowTool::distance(const Vector3& point){Object* p=findObject(object);if(p)return (p->getTransform().translation-point).magnitude();return 0.0f;}
