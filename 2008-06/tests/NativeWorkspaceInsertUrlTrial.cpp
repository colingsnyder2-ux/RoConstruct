#include <afxwin.h>
#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
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
