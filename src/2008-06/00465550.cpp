#include "CScriptEditor.h"
#include "script/Script.h"
#include "v8datamodel/DataModel.h"
#include "util/ContentProvider.h"
#include <boost/iostreams/copy.hpp>
#include <sstream>

void CScriptEditor::reload()
{
    if (!m_hWnd)
        return;
    loading = true;
    if (script) {
        try {
            boost::recursive_mutex::scoped_lock lock(*mutex);
            embedded = script->getScriptId().toString().size() == 0;
            if (embedded) {
                GetCtrl().SetText(script->getEmbeddedCode().c_str());
            } else {
                std::auto_ptr<std::istream> input = RBX::ServiceProvider::create<RBX::ContentProvider>(script.get())->getContent(script->getScriptId());
                std::ostringstream output;
                boost::iostreams::copy(*input, output, 4096);
                GetCtrl().SetText(output.str().c_str());
            }
            GetCtrl().SetReadOnly(running || !embedded);
        } catch (std::exception& e) {
            CString message;
            message.Format("An error occurred while getting the script\n\n%s", e.what());
            GetCtrl().SetText(message);
            GetCtrl().SetReadOnly(FALSE);
        }
    } else {
        GetCtrl().SetText("");
    }
    GetCtrl().SetSavePoint();
    loading = false;
}
