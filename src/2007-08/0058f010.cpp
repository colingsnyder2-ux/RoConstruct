// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_unit_d410a85bdaf1f32f.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Object.h"
#include "v8tree/Instance.h"
#include "v8datamodel/FlagStand.h"

struct RocProbeFlagStandService : RBX::FlagStandService
{
	RocProbeFlagStandService();
	char pad[60];
};

template boost::shared_ptr<RocProbeFlagStandService> RBX::Creatable<RBX::Instance>::create<RocProbeFlagStandService>();
