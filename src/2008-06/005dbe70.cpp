// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_7fa1cc852ffd36f8.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#include "humanoid/Humanoid.h"
namespace RBX {
void Humanoid::setHealth(float value) {
 const float clamped=G3D::clamp(value,0.0f,(*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1ac)));
 if((*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1a8)) != clamped) {
  (*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1a8))=clamped;
  raisePropertyChanged(propHealth);
  // Native imDead is bit1; preserve all other observed packed flags.
  if((*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1a8))==0.0f && !(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+0x1e8)&2)) {
   *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this)+0x1e8)|=2;
   event_Died.fire(this);
  }
 }
}
}
