// >>> native-status (generated) -- do not edit >>>
// MarshalWindowRegistry | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0c1a580d | roc native-status --write
#include "util/MarshaledListener.h"
#include <map>

namespace RBX {
extern std::map<DWORD, CMarshalWindow*> marshalWindows;
extern ATL::CCriticalSection marshalRegistryLock;

CMarshalWindow* __cdecl acquireMarshalWindow()
{
    ATL::CCritSecLock lock(marshalRegistryLock);
    DWORD thread = GetCurrentThreadId();
    std::map<DWORD, CMarshalWindow*>::iterator it = marshalWindows.find(thread);
    if (it != marshalWindows.end()) {
        ++it->second->references;
        CMarshalWindow* result = it->second;
        lock.Unlock();
        return result;
    }
    CMarshalWindow* result = new CMarshalWindow(thread);
    marshalWindows[thread] = result;
    ++result->references;
    lock.Unlock();
    return result;
}

void __cdecl releaseMarshalWindow(CMarshalWindow* window)
{
    ATL::CCritSecLock lock(marshalRegistryLock);
    if (--window->references == 0) {
        marshalWindows.erase(window->threadId);
        window->DestroyWindow();
    }
}
}
