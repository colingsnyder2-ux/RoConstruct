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
	// 00558eb0. Batch 36: exact with the openrbx util/Association.h statement form (separate iter / end locals, iter
	// first, while loop): the end iterator's container stays in a stack slot as in the target. Rejected in batch 32:
	// the plain for loop re-reading items.end() (219 B), std::for_each with boost::checked_deleter (148 B), a hoisted
	// `end` local built before begin() (212 B).
	// ~Association body: native-headers/util/Association.h (inline there); instantiated out of line below.
}

template RBX::Association<RBX::Instance>::~Association();
