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
