// 2008-06 native RBX::MergeBinder (inactive); evidence in native-headers/v8datamodel/MergeBinder2008.h.
// Verified by tests/record_native_misc_leaves.py: constructor 00443e50, the inline virtuals emitted with the vtable
// (announceID 0063fad0, announceIDREF 00443eb0, resolveRefs 00443d60, processID 004440a0, processIDREF 00444a70)
// and the std::vector<IDREFItem> members they instantiate.
// >>> native-status (generated) -- do not edit >>>
// MergeBinder | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src b95d2151 | roc native-status --write
#include "v8datamodel/MergeBinder2008.h"

namespace RBX
{
	// 00443e50
	MergeBinder::MergeBinder()
	{
	}
}
