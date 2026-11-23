// =============================================================================
// SettingsDialog.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/SettingsDialog.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "CSettingsDialog.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/Selection.h"

IMPLEMENT_DYNCREATE(CSettingsDialog, CDialog)

BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
    ON_BN_CLICKED(1002, &CSettingsDialog::OnResetSettings)
END_MESSAGE_MAP()

CSettingsDialog::CSettingsDialog(CWnd* parent)
    : CDialog(122, parent),
      explorer(NULL)
{
}

CSettingsDialog::~CSettingsDialog() {}

void CSettingsDialog::OnResetSettings()
{
    AfxMessageBox(143, MB_ICONINFORMATION);
    RBX::GlobalSettings::singleton()->eraseSettingsStore();
    EndDialog(IDCANCEL);
}

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
