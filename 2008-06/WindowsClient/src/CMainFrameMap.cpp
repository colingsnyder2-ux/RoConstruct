// >>> native-status (generated) -- do not edit >>>
// CMainFrameMap | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 8bc57265 | roc native-status --write
#include "CMainFrame.h"

// Native map at 00811624. Address-named handlers remain unresolved.
BEGIN_MESSAGE_MAP(CMainFrame, CXTPMDIFrameWnd)
    ON_WM_ACTIVATE()
    ON_WM_GETMINMAXINFO()
    ON_WM_ACTIVATEAPP()
    ON_WM_CREATE()
    ON_COMMAND(0x88b9, handle_42fbf0)
    ON_MESSAGE(0x2aad, handle_4314e0)
    ON_WM_CLOSE()
    ON_WM_PAINT()
    ON_COMMAND(0x809f, handle_42fbb0)
    ON_UPDATE_COMMAND_UI(0x809f, handle_42e550)
    ON_COMMAND(0x8042, handle_42fb80)
    ON_UPDATE_COMMAND_UI(0x8042, handle_42e550)
    ON_COMMAND(0x8018, handle_42e5e0)
    ON_UPDATE_COMMAND_UI(0x8018, handle_42e550)
    ON_COMMAND(0x800f, handle_42e610)
    ON_UPDATE_COMMAND_UI(0x800f, handle_42e550)
    {0x2861, 0, 0, 0, AfxSig_i_v_s, (AFX_PMSG)(AFX_PMSGW)(static_cast<int (AFX_MSG_CALL CWnd::*)(void*)>(&CMainFrame::handle_42fcf0))},
    {0x285e, 0, 0, 0, AfxSig_i_v_s, (AFX_PMSG)(AFX_PMSGW)(static_cast<int (AFX_MSG_CALL CWnd::*)(void*)>(&CMainFrame::handle_42fe00))},
    ON_NOTIFY(0x64, 0x8d, handle_431260)
    ON_UPDATE_COMMAND_UI(0x8d, handle_4300d0)
    ON_NOTIFY(0x64, 0x26dd, handle_431160)
    ON_UPDATE_COMMAND_UI(0x26dd, handle_42e550)
    ON_WM_DESTROY()
    ON_COMMAND(0x80bf, handle_42ecf0)
    ON_UPDATE_COMMAND_UI(0x80bf, handle_42e550)
    ON_UPDATE_COMMAND_UI(0xbb, handle_42ed00)
    ON_UPDATE_COMMAND_UI(0xbe, handle_42ed00)
    ON_UPDATE_COMMAND_UI(0xd1, handle_42ed00)
    ON_UPDATE_COMMAND_UI(0xbd, handle_42ed20)
    ON_UPDATE_COMMAND_UI(0xbc, handle_42edd0)
    ON_COMMAND(0x80ff, handle_430bd0)
    ON_COMMAND(0x80dd, handle_42ee80)
    ON_UPDATE_COMMAND_UI(0x80dd, handle_42e550)
    ON_COMMAND(0x80f3, handle_42ee90)
    ON_UPDATE_COMMAND_UI(0x80f3, handle_42e550)
    ON_UPDATE_COMMAND_UI(0x80f5, handle_42eec0)
    ON_COMMAND(0x80f5, handle_4314c0)
    ON_COMMAND(0x80f4, handle_431ce0)
    ON_UPDATE_COMMAND_UI(0x80f4, handle_42eef0)
    ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()

// Original 006c4ce0 is an import thunk to CWnd::Default.
void CMainFrame::OnPaint() { Default(); }
