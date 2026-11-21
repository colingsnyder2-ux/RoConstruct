// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: RBX::RunService::sub_005550a0 (placeholder name for 005550a0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include "util/RunStateOwner.h"

void RBX::RunService::sub_005550a0(double throttle)
{
    boost::mutex::scoped_lock lock(viewMutex);
    for (std::map<IRunView*, bool>::iterator it = views.begin(); it != views.end(); ++it)
        it->first->AdjustThrottle(throttle);
}
