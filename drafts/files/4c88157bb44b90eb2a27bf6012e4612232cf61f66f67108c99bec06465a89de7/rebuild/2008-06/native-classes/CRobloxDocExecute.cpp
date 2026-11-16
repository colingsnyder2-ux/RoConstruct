// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include <afxwin.h>
#include <XTToolkitPro.h>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "util/ContentProvider.h"
#include "util/StandardOut.h"
#include <sstream>
namespace RBX {
// INFERRED: 00453c30 calls the stream-copy helper with a 4096-byte buffer.
void copyStream(std::istream&, std::ostream&, int);
}
// Original 00453c30: command-bar script execution and ten-entry history.
void CRobloxDoc::handle_453c30(NMHDR* notification, LRESULT* result)
{
    CXTPControlComboBox* combo = static_cast<CXTPControlComboBox*>(
        reinterpret_cast<NMXTPCONTROL*>(notification)->pControl);
    if (combo->GetType() != xtpControlComboBox) return;
    std::string script(combo->GetEditText());
    if (combo->GetListBoxCtrl()->FindStringExact(-1, script.c_str()) == -1) {
        combo->GetListBoxCtrl()->InsertString(0, script.c_str());
        if (combo->GetListBoxCtrl()->GetCount() > 10)
            combo->DeleteItem(combo->GetListBoxCtrl()->GetCount() - 1);
    }
    combo->SetEnabled(FALSE);
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_OUTPUT, "> %s", script.c_str());
    try {
        if (RBX::ContentProvider::isUrl(script)) {
            std::auto_ptr<std::istream> stream(RBX::ServiceProvider::create<RBX::ContentProvider>(getDataModel().get())->getContent(RBX::ContentId(script)));
            std::ostringstream buffer;
            RBX::copyStream(*stream, buffer, 4096);
            script = buffer.str();
        }
        RBX::DataModel::Lock lock(getDataModel());
        RBX::ServiceProvider::create<RBX::ScriptContext>(workspace->getDataModel().get())->executeInNewThread(
            static_cast<RBX::Security::Identities>(3), script.c_str(), "Cmd");
    } catch (...) {}
    combo->SetEnabled(TRUE);
    combo->GetEditCtrl()->SendMessage(EM_SETSEL, 0, -1);
    combo->GetEditCtrl()->SendMessage(EM_SCROLLCARET, 0, 0);
    combo->GetEditCtrl()->SetFocus();
    *result = TRUE;
}

