// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CWorkspaceExecScriptHelper | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 92e18ba6 | roc native-status --write
#include <afxwin.h>
#include <atlbase.h>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "script/ScriptContext.h"
#include "reflection/type.h"
#include "LuaArgs.h"
#include <G3D/format.h>

typedef char LuaArgsSizeCheck[sizeof(LuaArgs) == 24 ? 1 : -1];
typedef char LuaValueSizeCheck[sizeof(RBX::Reflection::Value) == 8 ? 1 : -1];

extern SAFEARRAY* __cdecl makeSafeArray(RBX::Reflection::ValueCollection*);
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID workspaceSiteErrorContext;

HRESULT CWorkspace::execScript(const char* script, VARIANT a, VARIANT b, VARIANT c, VARIANT d, SAFEARRAY** result) {
    HRESULT hr = checkSite();
    if (hr)
        return hr;
    try {
        RBX::DataModel::Lock lock(dataModel);
        LuaArgs args;
        args.push(a);
        args.push(b);
        args.push(c);
        args.push(d);
        std::auto_ptr<RBX::Reflection::ValueCollection> ret = getDataModel()->create<RBX::ScriptContext>()->executeInNewThread(RBX::Security::TrustedCOM, script, 0, args.values);
        if (result)
            *result = makeSafeArray(ret.get());
        return S_OK;
    } catch (std::exception& e) {
        std::string s(script);
        std::string msg = G3D::format("DoExecScript failed because %s.  %s", e.what(), s.substr(0, 64).c_str());
        hr = reportWorkspaceSiteError(workspaceSiteErrorContext, msg.c_str(), 0);
    }
    return hr;
}
