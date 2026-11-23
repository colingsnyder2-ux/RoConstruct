// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/datamodel-2008
// 2008-06 RBX::DataModel::getMutex() const (00464710). The static DataModel::getMutex(Instance*) 00464750
// (Inferred_00464750.cpp) calls it out of line after the DataModel dynamic_cast (call at 0046479b), so it is a separate
// out-of-line member and not inlined there.
#include "v8datamodel/DataModel.h"

namespace RBX
{
	// 00464710 (registry placeholder func_00464710): copies the shared_ptr<recursive_mutex> member (+0x25c / count
	// +0x260, lock xadd) into the return slot; ret 4.
	boost::shared_ptr<boost::recursive_mutex> DataModel::getMutex() const
	{
		return mutex;
	}
}
