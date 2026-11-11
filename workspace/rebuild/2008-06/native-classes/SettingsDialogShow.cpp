// >>> native-status (generated) -- do not edit >>>
// SettingsDialogShow | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9a454061 | roc native-status --write
#include "CSettingsDialog.h"
#include "v8datamodel/GlobalSettings.h"

void showSettingsDialog(CWnd* parent)
{
    if (AfxMessageBox(136, MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK) {
        CSettingsDialog dialog(parent);
        if (dialog.DoModal() == IDOK) {
            AfxMessageBox(142, MB_ICONINFORMATION);
            RBX::GlobalSettings::singleton()->saveState();
        }
    }
}
