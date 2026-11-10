#pragma once
// Inactive native 2008-06 recovery: Marshaller, a hidden ATL window that runs queued functions on the thread that
// created it (posted with message 0x465). Declared in the DHTMLWindowService translation unit.
#include <afxwin.h>
#include <atlbase.h>
#include <atlwin.h>
#include <deque>
#include <boost/function.hpp>
#include <boost/thread/mutex.hpp>

// RTTI of vtable 0080eccc: Marshaller : CWindowImpl<Marshaller, CWindow, CWinTraits<0x56000000, 0>> (the default
// CControlWinTraits) : CWindowImplBaseT : CWindowImplRoot : CWindow (+4 m_hWnd), CMessageMap.
// sizeof 0x54: 0041b6f0 news 0x54 before the constructor 0041b310. Constructor: CWindowImpl members (+4 m_hWnd,
// +0x14 the dynamic thunk pointer, +0x18 m_pCurrentMsg, +0x1c m_dwState, +0x20 m_pfnSuperWindowProc = DefWindowProc)
// then vptr 0080eccc, +0x24 = 0, the deque at +0x2c (its aux proxy new(4), +0x3c..+0x48 = 0), the boost::mutex at
// +0x4c (ctor 00594c90), then +0x28 = the argument and Create(NULL, NULL, NULL, WS_POPUP) (00419a40).
// Destructor 0041a250: ~mutex (00594cb0), ~deque (00419b40 then delete of the proxy), the thunk free (007a600b).
// Vtable slots: 0 ProcessWindowMessage 0041b1e0, 1 ??_G 0041b3d0, 2 GetWindowProc 0041a400 (returns the
// CWindowImplBaseT WindowProc 0041a2d0), 3 OnFinalMessage 00432a70 (`delete this` through slot 1).
class Marshaller : public ATL::CWindowImpl<Marshaller>
{
public:
    explicit Marshaller(DWORD threadId);   // 0041b310
    ~Marshaller();                         // 0041a250 (virtual through CWindowImplRoot)

    // GetWndClassInfo's static (0092c5b0): CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, COLOR_WINDOW + 1, class name
    // 0080ecac "Roblox.Marshaller".
    DECLARE_WND_CLASS("Roblox.Marshaller")

    BEGIN_MSG_MAP(Marshaller)
        MESSAGE_HANDLER(0x465, onExecute)
    END_MSG_MAP()

    // 0041a410: pops the front function under the mutex and calls it (bad_function_call when empty).
    LRESULT onExecute(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
    // 0041a530 (function by value, ret 0x20): pushes it under the mutex, then PostMessage(m_hWnd, 0x465, 0, 0).
    void post(boost::function0<void> function);

    virtual void OnFinalMessage(HWND hWnd);   // 00432a70

    long useCount;                                // +0x24 (0 in the constructor; 0041b6f0 increments it)
    DWORD threadId;                               // +0x28 (constructor argument; 0041b6f0 passes GetCurrentThreadId())
    // +0x2c (0041a410 front/pop_front, 0041a530 push_back). Element boost::function0<void>, not function<void()>:
    // 0041a410 assigns through function0's operator= (00554470), not the derived copy-and-swap one.
    std::deque<boost::function0<void> > queue;
    boost::mutex mutex;                           // +0x4c
};
