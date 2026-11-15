// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
#include "CBrowserView.h"
#include <Controls/XTFunctions.h>

CBrowserView* showBrowserPopup(RECT rect, CWnd* parent, CString url, IDispatch* external)
{
    CFrameWnd* frame = new CFrameWnd;
    frame->Create(NULL, NULL, WS_OVERLAPPEDWINDOW, CRect(0, 0, 0, 0), parent, NULL, 0, NULL);
    frame->ModifyStyleEx(WS_EX_CLIENTEDGE, WS_EX_TOOLWINDOW);
    CBrowserView* view = dynamic_cast<CBrowserView*>(XTFuncCreateView(frame, const_cast<CRuntimeClass*>(&CBrowserView::classCBrowserView), NULL, NULL, AFX_WS_DEFAULT_VIEW, NULL, AFX_IDW_PANE_FIRST));
    view->external = external;
    const char* value = url;
    view->homeUrl = value;
    view->Navigate(value);
    parent->ClientToScreen(&rect);
    frame->SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_NOZORDER);
    frame->InitialUpdateFrame(NULL, TRUE);
    return view;
}
