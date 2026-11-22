// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Narrow include: util/MarshalWindow.h (CMarshalWindow) instead of util/MarshaledListener.h, whose stray '}'
// (core header, proposal filed) breaks every includer. The two declarations below match MarshaledListener.h exactly.
#include "util/MarshalWindow.h"
#include <map>

namespace RBX {
CMarshalWindow* __cdecl acquireMarshalWindow();
void __cdecl releaseMarshalWindow(CMarshalWindow*);
extern std::map<DWORD, CMarshalWindow*> marshalWindows;
extern ATL::CCriticalSection marshalRegistryLock;

// 00432ce0
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

// 00432bd0
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
