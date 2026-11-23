// =============================================================================
// MarshalWindow.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/MarshalWindow.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "util/MarshalWindow.h"
#include "util/EventDataBase.h"

namespace RBX
{
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
