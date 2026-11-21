// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// RBX::Association<Instance>::~Association 00558eb0 (inactive). The donor util/Association.h (read-only) declares
// ~Association() without a body; Instance's `assoc` member (v8tree/Instance.h) is destroyed through it.
// Identity: registry 00558eb0 ??1?$Association@VInstance@RBX@@@RBX@@QAE@XZ; it lies in the Instance unit range
// (0055xxxx) next to the Instance lifetime bodies. Shape read from the binary: items is the
// std::vector<Item*> at +0 (aux proxy +0, _Myfirst +0xc, _Mylast +0x10, _Myend +0x14); every non-null item is
// deleted through Item's virtual scalar deleting destructor (slot 0, push 1), then the vector frees its buffer and
// its _Container_base_aux proxy.
#include "v8tree/Instance.h"

namespace RBX
{
	// 00558eb0. PARKED near miss (3 hypotheses, batch 32): this plain loop is 219 B vs 230 B; the target keeps the
	// end iterator's container pointer in a stack slot and calls _invalid_parameter_noinfo through the import slot
	// every time, where this build caches the import pointer in a register. Rejected: std::for_each with
	// boost::checked_deleter (148 B, unchecked iterators); a hoisted `end` local (212 B, end() built before begin()).
	template<typename Associated>
	Association<Associated>::~Association()
	{
		for (std::vector<Item*>::iterator iter = items.begin(); iter != items.end(); ++iter)
		{
			delete *iter;
		}
	}
}

template RBX::Association<RBX::Instance>::~Association();
