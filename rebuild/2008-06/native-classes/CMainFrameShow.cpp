#include "CMainFrame.h"

BOOL CMainFrame::showFrame(int command)
{
    windowPosition.LoadWindowPos(this, "CMainFrameV2", NULL);
    if (command) command = windowPosition.showCmd;
    return ShowWindow(command) != FALSE;
}
