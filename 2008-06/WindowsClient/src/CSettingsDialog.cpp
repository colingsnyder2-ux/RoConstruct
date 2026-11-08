// >>> native-status (generated) -- do not edit >>>
// CSettingsDialog | 2008-06 | linked
// 4/4 exact by name (100%) | 4/4 exact bodies | no strings | verified 2026-11-07| by king_originala (+2) (mixed 3)
// <<< native-status | src a9685516 | roc native-status --write
#include "CSettingsDialog.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/Selection.h"

IMPLEMENT_DYNCREATE(CSettingsDialog, CDialog)

BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
    ON_BN_CLICKED(1002, &CSettingsDialog::OnResetSettings)
END_MESSAGE_MAP()

// Original 00466e10.
CSettingsDialog::CSettingsDialog(CWnd* parent)
    : CDialog(122, parent),
      explorer(NULL)
{
}

// Original 00466ca0.
CSettingsDialog::~CSettingsDialog() {}

// Original 00466c00.
void CSettingsDialog::OnResetSettings()
{
    AfxMessageBox(143, MB_ICONINFORMATION);
    RBX::GlobalSettings::singleton()->eraseSettingsStore();
    EndDialog(IDCANCEL);
}

// Original 00467030.
BOOL CSettingsDialog::OnInitDialog()
{
    if (!CDialog::OnInitDialog())
        return FALSE;
    if (!splitter.CreateStatic(this, 1, 2))
        return FALSE;
    if (!splitter.CreateView(0, 0, const_cast<CRuntimeClass*>(&CSettingsExplorer::classCSettingsExplorer), CSize(200, 200), NULL))
        return FALSE;
    explorer = (CSettingsExplorer*)splitter.GetPane(0, 0);
    explorer->setRoot(RBX::GlobalSettings::singleton().get());
    propGrid.Create(CRect(0, 0, 0, 0), &splitter, splitter.IdFromRowCol(0, 1));
    RBX::Selection* selection = RBX::ServiceProvider::create<RBX::Selection>(RBX::GlobalSettings::singleton().get());
    propGrid.setSelection(selection);
    {
        CRect rect;
        GetDlgItem(1001)->GetWindowRect(&rect);
        ScreenToClient(&rect);
        splitter.MoveWindow(&rect);
    }
    return TRUE;
}
