// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// DocumentLoadFromString | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 878ca781 | roc native-status --write
#include <afxwin.h>
#include "CRobloxDoc.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "reflection/type.h"

int CRobloxDoc::loadFromString(std::string text)
{
    RBX::DataModel::Lock lock(getDataModel());
    RBX::Reflection::ValueCollection args;
    try {
        getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(
            RBX::Security::LocalGUI, text.c_str(), "Doc script", args);
        return 1;
    } catch (std::exception&) {
        return 0;
    }
}
