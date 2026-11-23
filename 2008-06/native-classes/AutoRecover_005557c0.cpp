// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/RunStateOwner.h"

namespace RBX
{
	// 005557c0: viewMutex (+0x280) lock, views[runView] = true (map operator[] 005556d0), unlock.
	void RunService::addRunView(IRunView* runView)
	{
		boost::mutex::scoped_lock lock(viewMutex);
		views[runView] = true;
	}
}
