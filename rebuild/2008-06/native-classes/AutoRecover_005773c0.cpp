// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"

namespace RBX
{
	// INFERRED: layout from the disassembly: mutex shared_ptr at +0 (px) / +4 (pn), lock at +8.
	// delete lock runs scoped_lock::~scoped_lock inline (if locked: mutex->unlock(), the call to 0x5630e0
	// is the folded recursive_mutex::unlock), then operator delete. The shared_ptr member destructor
	// (interlocked use/weak count decrements, dispose/destroy virtual calls) is emitted inline after it.
	DataModel::Lock::~Lock()
	{
		delete lock;
	}
}
