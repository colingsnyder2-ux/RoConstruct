// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// WorkspaceInsertUrl | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 57fc59bf | roc native-status --write
#include <afxwin.h>
#include "util/NativeContentProvider.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"

extern HRESULT validateWorkspaceSiteUrl(const wchar_t*);
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID workspaceSiteErrorContext;

void CWorkspace::insert(RBX::ContentId id, bool tree) {
    std::auto_ptr<std::istream> content(RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get())->getContent(id));
    insert(*content, tree);
}

HRESULT __stdcall CWorkspace::Insert(BSTR url) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    try {
        HRESULT result = validateWorkspaceSiteUrl(url);
        if (result) {
            CStringA message;
            message.Format("Untrusted Url: %s", CStringA(url));
            return reportWorkspaceSiteError(workspaceSiteErrorContext, message, result);
        }
        insert(RBX::ContentId(CStringA(url)), false);
        return S_OK;
    } catch (const std::exception& e) {
        return reportWorkspaceSiteError(workspaceSiteErrorContext, e.what(), 0);
    }
}
