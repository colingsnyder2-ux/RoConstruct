// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "util/RunStateOwner.h"

namespace RBX
{
	void RunService::addRunView(IRunView* runView)
	{
		boost::mutex::scoped_lock lock(viewMutex);
		views[runView] = true;
	}
}
