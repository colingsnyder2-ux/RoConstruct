// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_498526c4f91048e5.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("humanoid/Humanoid.h", "roc_unit_e9db1b469837baf4.cpp")
#include "humanoid/Humanoid.h"
namespace RBX {
extern Reflection::PropDescriptor<Humanoid,float> propMaxHealth;
void Humanoid::setMaxHealth(float value) {
 if((*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1ac)) != value) {
  (*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1ac)) = value;
  raisePropertyChanged(::RBX::propMaxHealth);
 }
}
}
