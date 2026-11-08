// >>> native-status (generated) -- do not edit >>>
// MyXTPCommandBars | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 09b4cdea | roc native-status --write
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include "MyXTPCommandBars.h"
IMPLEMENT_DYNCREATE(MyXTPCommandBars, CXTPCommandBars)

CXTPToolBar* MyXTPCommandBars::AddCustomBar(LPCTSTR caption, UINT id, BOOL tearOff)
{
    CXTPToolBar* bar = CXTPCommandBars::AddCustomBar(caption, id, tearOff);
    if (id == 0x3ed) bar->EnableDocking(0x10);
    return bar;
}
