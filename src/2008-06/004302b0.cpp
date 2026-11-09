// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_monitor_a9d426968a6ebe33.cpp

// Candidate translation unit (score above; library headers required).

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* (__stdcall *MonitorFromWindow)(void*, unsigned long);

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> SharedHandle;

SharedHandle __cdecl getService();
void __cdecl report(void*, int, const char*, ...);

struct CWrapperView {
    char padding0[0x20];
    void* window;
    char padding1[0xd8];
    void* monitor;
    void getMonitorInfo();
};

void CWrapperView::getMonitorInfo()
{
    monitor = MonitorFromWindow(window, 2);
    if (!monitor)
        report(getService().get(), 2,
               "CMainFrameFrameWnd::getMonitorInfo MonitorFromWindow returned NULL");
}