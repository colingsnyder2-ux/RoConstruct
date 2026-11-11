// >>> native-status (generated) -- do not edit >>>
// CMainFrameShow | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c5f0f9a7 | roc native-status --write
#include "CMainFrame.h"

BOOL CMainFrame::showFrame(int command)
{
    windowPosition.LoadWindowPos(this, "CMainFrameV2", NULL);
    if (command) command = windowPosition.showCmd;
    return ShowWindow(command) != FALSE;
}
