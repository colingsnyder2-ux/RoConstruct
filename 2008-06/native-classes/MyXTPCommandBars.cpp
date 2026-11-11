// >>> native-status (generated) -- do not edit >>>
// MyXTPCommandBars | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by tester (+1) (chatgpt:gpt-6.1-sol)
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
