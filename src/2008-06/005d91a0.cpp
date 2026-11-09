// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_humanoidlooknative_623a631e44af4f7a.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Matrix3.h>
using namespace G3D;
struct Part{const Matrix3& getMatrix();};
struct S{void* getPart();float f();};
extern const float scale_828b60;
extern "C" float __cdecl angle(const Vector3&);
float S::f(){void*p=getPart();if(p){Part* part=(Part*)((char*)p+0x228);if(part){const Matrix3& matrix=part->getMatrix();float scale=scale_828b60;return angle(matrix.getColumn(2)*scale);}}return 0.0f;}
