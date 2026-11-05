// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_unit_ca19479c3dfe08f3.cpp

// Candidate translation unit (score above; library headers required).
#pragma pack(push,1)
#include "util/Object.h"
#include "v8tree/Instance.h"
#pragma pack(pop)

struct RocProbeInstancePacked : RBX::Instance
{
	RocProbeInstancePacked();
	virtual const RBX::Name& getClassName() const;
	char pad[2];
};

template boost::shared_ptr<RocProbeInstancePacked> RBX::Creatable<RBX::Instance>::create<RocProbeInstancePacked>();
