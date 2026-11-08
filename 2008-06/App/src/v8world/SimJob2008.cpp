// 2008-06 native RBX::SimJob / AssemblySimJob (inactive); evidence in native-headers/v8world/SimJob2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows: SimJob() 005e50f0, ~SimJob 005e5150, the scalar deleting
// destructor 005e5190 (vtable 0083f72c is emitted here), AssemblySimJob(assembly) 005e51e0 (vtable 0083f73c; its
// slots 1 / 2 fold into 0074eed0).
// >>> native-status (generated) -- do not edit >>>
// SimJob2008 | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 67053efb | roc native-status --write
#include "v8world/SimJob2008.h"

namespace RBX
{
	// 005e50f0
	SimJob::SimJob()
	{
	}

	// 005e5150
	SimJob::~SimJob()
	{
	}

	// 005e51e0
	AssemblySimJob::AssemblySimJob(Assembly* assembly)
		: assembly(assembly)
	{
	}
}
