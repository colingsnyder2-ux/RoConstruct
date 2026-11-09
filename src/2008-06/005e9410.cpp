// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_0ec1b5c0a1712ab3.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/World.h", "roc_unit_b0ca8f08e1d06783.cpp")
#pragma include_alias("v8world/SleepStage.h", "roc_unit_b68f0395c49caace.cpp")
#include "v8world/World.h"
#include "v8world/JointStage.h"
#include "v8world/SleepStage.h"
namespace RBX {
SleepStage* World::getSleepStage() { return rbx_static_cast<SleepStage*>((*reinterpret_cast<JointStage* const*>(reinterpret_cast<const char*>(this) + 0x88))->findStage(IStage::SLEEP_STAGE)); }
void World::ticklePrimitive(Primitive* p, bool recursive) { Assembly* assembly = p->getAssembly(); if (assembly) getSleepStage()->onWakeUpRequest(assembly, recursive); }
}
