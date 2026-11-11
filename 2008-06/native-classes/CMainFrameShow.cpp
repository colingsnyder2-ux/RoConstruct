// >>> native-status (generated) -- do not edit >>>
// CMainFrameShow | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src c5f0f9a7 | roc native-status --write
#include "CMainFrame.h"

BOOL CMainFrame::showFrame(int command)
{
    windowPosition.LoadWindowPos(this, "CMainFrameV2", NULL);
    if (command) command = windowPosition.showCmd;
    return ShowWindow(command) != FALSE;
}
