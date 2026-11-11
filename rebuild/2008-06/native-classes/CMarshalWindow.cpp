// >>> native-status (generated) -- do not edit >>>
// CMarshalWindow | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7bada83a | roc native-status --write
#include "util/MarshalWindow.h"
#include "util/EventDataBase.h"

namespace RBX {
CMarshalWindow::CMarshalWindow(DWORD thread) : references(0)
{
    threadId = thread;
    Create(NULL, NULL, NULL, WS_POPUP);
}

void CMarshalWindow::post(EventDataBase* event)
{
    PostMessage(WM_USER + 101, 0, reinterpret_cast<LPARAM>(event));
}

CMarshalWindow::~CMarshalWindow()
{
}

void CMarshalWindow::OnFinalMessage(HWND)
{
    delete this;
}

LRESULT CMarshalWindow::OnMarshalEvent(UINT, WPARAM, LPARAM value, BOOL&)
{
    EventDataBase* event = reinterpret_cast<EventDataBase*>(value);
    event->execute();
    delete event;
    return 0;
}

LRESULT CMarshalWindow::OnDestroy(UINT, WPARAM, LPARAM, BOOL& handled)
{
    ATL::CCritSecLock lock(criticalSection);
    MSG message;
    for (;;) {
        HWND window = m_hWnd;
        if (!::PeekMessage(&message, window, WM_USER + 101, WM_USER + 101, PM_REMOVE)) break;
        delete reinterpret_cast<EventDataBase*>(message.lParam);
    }
    handled = FALSE;
    lock.Unlock();
    return 0;
}
}
