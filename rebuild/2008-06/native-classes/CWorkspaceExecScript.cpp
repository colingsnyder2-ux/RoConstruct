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
