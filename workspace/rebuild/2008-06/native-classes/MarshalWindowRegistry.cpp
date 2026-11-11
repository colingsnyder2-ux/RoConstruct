// >>> native-status (generated) -- do not edit >>>
// MarshalWindowRegistry | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7c00941d | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CWindowImplBaseT<ATL::CWindow,ATL::CWinTraits<1442840576,0> >;
