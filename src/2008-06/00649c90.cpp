// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_dd2422abcf7803d1.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/Face.h", "roc_unit_cb2f7321c0df2e4f.cpp")
#include "util/Face.h"
namespace RBX { G3D::Vector3 Face::getAxis(int i) const {
 RBXASSERT((i==0)||(i==1)); return i==0 ? getU() : getV();
} }
