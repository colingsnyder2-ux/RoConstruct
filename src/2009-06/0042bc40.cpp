// from server: 100% by EspClaude
// from server: 83% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_b9513eee8a0b1183.cpp

// Candidate translation unit (score above; library headers required).

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* (__stdcall *MonitorFromWindow)(void*, unsigned long);

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> SharedHandle;

struct Logger { void message(int, const char*); };
typedef boost::shared_ptr<Logger> SharedLogger;
SharedLogger __cdecl getService();
struct CWndLike { void refresh(); };
CWndLike* __stdcall fromHandle(void*);

struct CWrapperView {
    char padding0[0x20];
    void* window;
    char padding1[0xdc];
    void* monitor;
    void getMonitorInfo();
};

void CWrapperView::getMonitorInfo()
{
    monitor = MonitorFromWindow(window, 2);
    if (!monitor)
        getService()->message(2,
               "CMainFrameFrameWnd::getMonitorInfo MonitorFromWindow returned NULL");
    fromHandle(window)->refresh();
}
