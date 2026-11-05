// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_materialarrayresizeef4b721af20a79aa.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Array.h"
struct Element {virtual void first();virtual ~Element();char storage[52];Element();};
template void G3D::Array<Element>::resize(int,bool);
