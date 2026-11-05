// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_365f050840f24fe4.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_cc3dd87ed7e7c246.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "roc_unit_ea83e629b1338927.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_1deee9af9b5e9e77.cpp")
#pragma include_alias("v8kernel/Body.h", "roc_unit_bb57aef6b00c1d00.cpp")
#pragma include_alias("v8kernel/SimBody.h", "roc_unit_369efb0ca936ab52.cpp")
#include "v8datamodel/Gyro.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "v8kernel/Body.h"
namespace RBX {
void BodyForce::computeForce(const float dt, bool throttling) { Body* root = part.lock()->getPrimitive()->getBody()->getRoot(); root->accumulateForceAtBranchCofm(force); }
}
