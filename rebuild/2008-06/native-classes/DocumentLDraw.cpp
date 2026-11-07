// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// DocumentLDraw | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 40604b52 | roc native-status --write
#include <afxwin.h>
#include <afxdlgs.h>
#include <sstream>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "reflection/type.h"
#include "util/LDrawParser.h"

void CRobloxDoc::handle_454c90()
{
    CString filter;
    filter.LoadString(0x8d);
    CFileDialog dlg(TRUE, "ldr", 0, 6, filter, 0, 0, TRUE);
    if (dlg.DoModal() == IDOK) {
        RBX::LDraw2Lua::LDrawParser parser(dlg.GetPathName());
        std::ostringstream stream(std::ios_base::out);
        parser.parse(stream);
        stream.flush();
        try {
            RBX::DataModel::Lock request(workspace->getDataModel());
            RBX::Reflection::ValueCollection args;
            std::string script = stream.str();
            getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(RBX::Security::LocalGUI, script.c_str(), "LDraw", args);
        } catch (std::exception& e) {
            AfxMessageBox(e.what(), MB_ICONHAND);
        }
    }
}
