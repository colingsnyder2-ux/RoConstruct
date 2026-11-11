// >>> native-status (generated) -- do not edit >>>
// GuidRegistryMutex | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by auto (+2) (mixed 2)
// <<< native-status | src 25589d8e | roc native-status --write
#include <windows.h>
#include "util/GuidRegistry.h"

namespace RBX {
void* newGuidRegistryCriticalSection();

GuidRegistryMutex::GuidRegistryMutex() : handle(0), criticalSection(false), count(0)
{
    criticalSection = true;
    handle = newGuidRegistryCriticalSection();
}

void GuidRegistryMutex::lock()
{
    if (criticalSection)
        EnterCriticalSection(static_cast<CRITICAL_SECTION*>(handle));
    else
        WaitForSingleObject(handle, INFINITE);
    ++count;
    if (count > 1) {
        if (criticalSection)
            LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(handle));
        else
            ReleaseMutex(handle);
    }
}

void GuidRegistryMutex::unlock()
{
    if (--count != 0) return;
    if (criticalSection)
        LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(handle));
    else
        ReleaseMutex(handle);
}
}
