// >>> native-status (generated) -- do not edit >>>
// GuidRegistryMutex | 2008-06 | inactive
// unmapped (no binary link) | by -
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
