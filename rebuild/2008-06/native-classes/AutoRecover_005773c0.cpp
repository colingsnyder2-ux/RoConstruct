// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"

namespace RBX
{
	// 005773c0: delete the scoped_lock (unlocks if held), then the inlined shared_ptr<recursive_mutex> member dtor.
	DataModel::Lock::~Lock()
	{
		delete lock;
	}
}
