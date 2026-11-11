// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-import-length
// >>> native-status (generated) -- do not edit >>>
// CRobloxViewHelp | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 50172d02 | roc native-status --write
#include "CRobloxView.h"
#include <algorithm>

// Helpers in the browser-view unit: 004060d0 builds the site address, 0040e160 appends a path,
// 0040f050 opens the popup window for it.
CString applicationBaseUrl();
class CBrowserView;
CBrowserView* showBrowserPopup(RECT, CWnd*, CString, IDispatch*);

// 00459570: help popup, centred in the client area with a 12 pixel margin.
// 0040f050 takes a trailing int (0); 004060d0 takes none.
void CRobloxView::showHelp() {
    RECT client;
    ::GetClientRect(window.m_hWnd, &client);
    ::InflateRect(&client, -12, -12);
    client.right = (client.right - client.left) / 2;
    int height = client.bottom - client.top;
    client.bottom = std::min(480, height) - client.top;
    showBrowserPopup(client, &window, applicationBaseUrl() + "/Game/Help.aspx", NULL);
}

