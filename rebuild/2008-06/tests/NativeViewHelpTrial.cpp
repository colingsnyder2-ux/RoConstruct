// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
#pragma inline_depth(0)
#include "CRobloxView.h"
#include <algorithm>
#pragma inline_depth(255)

CString applicationBaseUrl();
class CBrowserView;
CBrowserView* showBrowserPopup(RECT, CWnd*, CString, IDispatch*);

void CRobloxView::showHelp()
{
    RECT client;
    ::GetClientRect(window.m_hWnd, &client);
    ::InflateRect(&client, -12, -12);
    client.right = (client.right - client.left) / 2;
    int height = client.bottom - client.top;
    client.bottom = std::min(480, height) - client.top;
    showBrowserPopup(client, &window, applicationBaseUrl() + "/Game/Help.aspx", NULL);
}
