// >>> native-status (generated) -- do not edit >>>
// CMainFrameToolbars | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 53d8fd43 | roc native-status --write
#include "CMainFrame.h"

// Hidden-command table recovered from original data.
UINT nativeHiddenCommands[26] = {
    0xe100, 0xe102, 0x8025, 0x80b7, 0xe123, 0xe120, 0x8005, 0x8010,
    0x8011, 0x805d, 0x805e, 0xe800, 0x88b9, 0xe801, 0x8042, 0x8018,
    0x800f, 0x809f, 0x80bf, 0x803d, 0x8061, 0x80a5, 0x8013, 0x8014,
    0x8047, 0xe130
};

bool CMainFrame::initializeToolbars(bool loadIcons)
{
    CXTPCommandBars* bars = GetCommandBars();
    CXTPMenuBar* menu = bars->SetMenu("Menu Bar", 0x80);
    if (!menu) return false;
    menu->SetFlags(0x1700, 0);
    CXTPToolBar* standard = bars->Add("Standard", (XTPBarPosition)0, NULL);
    if (!standard || !standard->LoadToolBar(0x80, loadIcons)) return false;
    CXTPToolBar* mouse = bars->Add("Mouse", (XTPBarPosition)0, NULL);
    if (!mouse || !mouse->LoadToolBar(0x87, loadIcons)) return false;
    CXTPToolBar* test = bars->Add("Test", (XTPBarPosition)0, NULL);
    if (!test || !test->LoadToolBar(0x89, loadIcons)) return false;
    CXTPToolBar* camera = bars->Add("Camera", (XTPBarPosition)0, NULL);
    if (!camera || !camera->LoadToolBar(0x91, loadIcons)) return false;
    CXTPToolBar* command = bars->Add("Command", (XTPBarPosition)1, NULL);
    if (!command || !command->LoadToolBar(0x96, loadIcons)) return false;
    command->EnableDocking(0x73);
    command->SetVisible(FALSE);
    DockRightOf(test, standard);
    DockRightOf(mouse, test);
    bars->HideCommands(nativeHiddenCommands, 26);
    bars->GetCommandBarsOptions()->bAlwaysShowFullMenus = TRUE;
    CXTPCommandBar::s_nExpandDelay = 0x1194;
    bars->GetCommandBarsOptions()->bToolBarAccelTips = TRUE;
    return true;
}
