// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// CWorkspaceExecScript | 2008-06 | inactive
// 0/1 exact by name (0%) | 0/1 exact bodies | no strings | verified 2026-11-07| by king_originala (deepseek:deepseek-chat)
// <<< native-status | src 8d53b9d9 | roc native-status --write
#include <afxwin.h>
#include <atlstr.h>
#include <string>
#include "CWorkspace.h"
#include "util/ContentProvider.h"

HRESULT __stdcall CWorkspace::ExecScript(BSTR script, VARIANT a, VARIANT b, VARIANT c, VARIANT d, SAFEARRAY** result) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    BSTR original = script;
    std::string text(static_cast<const char*>(CStringA(original)));
    if (RBX::ContentProvider::isUrl(text))
        return ExecUrlScript(original, a, b, c, d, result);
    return execScript(text.c_str(), a, b, c, d, result);
}
