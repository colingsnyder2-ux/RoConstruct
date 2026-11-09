// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_unit_253bf25ff1aa272b.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Object.h"
#include "v8tree/Instance.h"
#include "v8datamodel/Gyro.h"

struct RocProbeBodyVelocity : RBX::BodyVelocity
{
	RocProbeBodyVelocity();
	char pad[0x10];
};

template boost::shared_ptr<RocProbeBodyVelocity> RBX::Creatable<RBX::Instance>::create<RocProbeBodyVelocity>();
