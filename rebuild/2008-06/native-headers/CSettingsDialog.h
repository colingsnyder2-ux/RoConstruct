#pragma once
// >>> native-status (generated) -- do not edit >>>
// CSettingsDialog | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9910e88e | roc native-status --write
#include "CSelectionPropGrid.h"
#include "CSettingsExplorer.h"
#include "CSettingsPropGrid.h"

// Inactive layout recovery. CRuntimeClass 0081bd90 (DYNCREATE, size 0x3d4, base getter 0041f9b0 ->
// CDialog::GetThisClass). Constructor 00466e10 (CDialog(122, parent); CXTSplitterWnd 00708c50 at
// +0x74; +0x18c = 0; CSettingsPropGrid at +0x190) and destructor 00466ca0 (~CSelectionPropGrid on
// +0x190, ~CXTSplitterWnd 00708280 on +0x74, ~CDialog). OnInitDialog 00467030 stores the
// GetPane(0,0) explorer pointer at +0x18c. Message map 0081c120: BN_CLICKED 1002 -> 00466c00.
class CSettingsDialog : public CDialog {
    DECLARE_DYNCREATE(CSettingsDialog)
    DECLARE_MESSAGE_MAP()
public:
    CSettingsDialog(CWnd* parent = NULL);
    virtual ~CSettingsDialog();
    virtual BOOL OnInitDialog();
    afx_msg void OnResetSettings();

    CXTSplitterWnd splitter;          // +0x74
    CSettingsExplorer* explorer;      // +0x18c
    CSettingsPropGrid propGrid;       // +0x190
};
