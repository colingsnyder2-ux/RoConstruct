// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_1113eac196384b7f.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/Face.h", "roc_unit_cb2f7321c0df2e4f.cpp")
#include "util/Face.h"
namespace RBX {
bool Face::hasOverlap(const Face& f0, const Face& f1, float byAtLeast) {
 for(int i=0; i<2; ++i) {
  G3D::Vector3 axis=f0.getAxis(i);
  float f0min,f0max;
  f0.minMax(f0.c0,axis,f0min,f0max);
  float f1min,f1max;
  f1.minMax(f0.c0,axis,f1min,f1max);
  if(f1max-byAtLeast < f0min) return false;
  if(f1min+byAtLeast > f0max) return false;
 }
 return true;
}
}
