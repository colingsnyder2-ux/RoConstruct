#include <stddef.h>
#include "CSettingsDialog.h"
// Size from CRuntimeClass 0081bd90 (0x3d4) and CreateObject 00466fa0 (operator new 0x3d4); offsets from
// constructor 00466e10 and destructor 00466ca0; +0x18c also from OnInitDialog 00467030.
typedef char SettingsDialogSize[sizeof(CSettingsDialog) == 0x3d4 ? 1 : -1];
typedef char SettingsDialogBase[sizeof(CDialog) == 0x74 ? 1 : -1];
typedef char SettingsDialogSplitter[offsetof(CSettingsDialog, splitter) == 0x74 ? 1 : -1];
typedef char SettingsDialogExplorer[offsetof(CSettingsDialog, explorer) == 0x18c ? 1 : -1];
typedef char SettingsDialogPropGrid[offsetof(CSettingsDialog, propGrid) == 0x190 ? 1 : -1];
// CXTSplitterWnd: 0x74..0x18c; its theme-host subobject vtable 0085c054 at +0xdc (ctor 00708c50).
typedef char XTSplitterWndSize[sizeof(CXTSplitterWnd) == 0x118 ? 1 : -1];
// CSettingsPropGrid == CSelectionPropGrid (CRuntimeClass 0081358c size 0x244); shared_ptr at +0x23c.
typedef char SettingsPropGridSize[sizeof(CSettingsPropGrid) == 0x244 ? 1 : -1];
typedef char SettingsPropGridSelection[offsetof(CSettingsPropGrid, selection) == 0x23c ? 1 : -1];
