// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_e3d64f543a38d6a9.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "roc_unit_ea83e629b1338927.cpp")
#pragma include_alias("v8world/World.h", "roc_unit_b0ca8f08e1d06783.cpp")
#include "v8datamodel/Gyro.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/World.h"
namespace RBX {
void BodyMover::onEvent(const RunService* source, Stepped event) {
 if(world && part.lock() && preventBodySleep()) world->ticklePrimitive(part.lock()->getPrimitive(),true);
}
}
