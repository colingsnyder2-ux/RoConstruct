// Shortcut (owner-authorized): CRobloxView's runtime class and message map live in a unit that was never recovered.
// INFERRED: standard window-message entries for the handlers the header declares (map entries themselves not recovered).
#include "CRobloxView.h"
IMPLEMENT_DYNCREATE(CRobloxView, CView)
BEGIN_MESSAGE_MAP(CRobloxView, CView)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_WM_DESTROY()
    ON_WM_SETFOCUS()
    ON_WM_ERASEBKGND()
    ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()
