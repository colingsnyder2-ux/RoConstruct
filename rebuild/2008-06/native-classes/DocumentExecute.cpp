// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include <afxwin.h>
#include <afxole.h>
#include <afxcmn.h>
#include <afxext.h>
#include <afxmt.h>
#include <XTToolkitPro.h>
#include <sstream>
#include <boost/iostreams/copy.hpp>
#include "util/NativeContentProvider.h"
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "util/StandardOut.h"

void CRobloxDoc::handle_453c30(NMHDR* header, LRESULT* result)
{
    CXTPControlComboBox* combo = static_cast<CXTPControlComboBox*>(reinterpret_cast<NMXTPCONTROL*>(header)->pControl);
    if (combo->GetType() != xtpControlComboBox) return;
    std::string script(combo->GetEditText());
    if (combo->FindString(-1, script.c_str()) == -1) {
        combo->InsertString(0, script.c_str());
        if (combo->GetCount() > 10) combo->DeleteItem(combo->GetCount() - 1);
    }
    combo->SetEnabled(FALSE);
    RBX::StandardOut::singleton()->print(RBX::MESSAGE_OUTPUT, "> %s", script.c_str());
    try {
        if (RBX::ContentProvider::isUrl(script)) {
            std::auto_ptr<std::istream> stream(RBX::ServiceProvider::create<RBX::ContentProvider>(getDataModel().get())->getContent(RBX::ContentId(script)));
            std::ostringstream buffer;
            boost::iostreams::copy(*stream, buffer, 4096);
            script = buffer.str();
        }
        RBX::DataModel::Lock lock(getDataModel());
        workspace->getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(RBX::Security::CmdLine, script.c_str(), "Cmd");
    } catch (std::exception&) {}
    combo->SetEnabled(TRUE);
    combo->GetEditCtrl()->SetSel(0, -1);
    combo->GetEditCtrl()->SetFocus();
    *result = 1;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::iostreams::detail::basic_buffer<char,std::allocator<char> >;
