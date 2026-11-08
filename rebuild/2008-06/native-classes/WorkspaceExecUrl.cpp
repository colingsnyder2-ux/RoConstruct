// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
#include <afxwin.h>
#include <atlbase.h>
#include <sstream>
#include <boost/iostreams/copy.hpp>
#include "util/NativeContentProvider.h"
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include <G3D/format.h>

extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);
extern const CLSID workspaceSiteErrorContext;

HRESULT __stdcall CWorkspace::ExecUrlScript(BSTR url, VARIANT a, VARIANT b, VARIANT c, VARIANT d, SAFEARRAY** result) {
    try {
        AFX_MANAGE_STATE(AfxGetAppModuleState());
        std::ostringstream stream;
        try {
            CStringA path(url);
            std::auto_ptr<std::istream> content(RBX::ServiceProvider::create<RBX::ContentProvider>(dataModel.get())->getContent(RBX::ContentId((const char*)path)));
            boost::iostreams::copy(*content, stream, 4096);
        } catch (std::exception& e) {
            std::string message = G3D::format("Failed to get URL, %s", e.what());
            return reportWorkspaceSiteError(workspaceSiteErrorContext, message.c_str(), 0);
        }
        return execScript(stream.str().c_str(), a, b, c, d, result);
    } catch (CException* e) {
        char buffer[255];
        e->GetErrorMessage(buffer, 255);
        std::string message = G3D::format("CException %s", buffer);
        return reportWorkspaceSiteError(workspaceSiteErrorContext, message.c_str(), 0);
    } catch (ATL::CAtlException e) {
        std::string message = G3D::format("CAtlException %d", e.m_hr);
        return reportWorkspaceSiteError(workspaceSiteErrorContext, message.c_str(), 0);
    } catch (...) {
        return reportWorkspaceSiteError(workspaceSiteErrorContext, "Unexpected exception", 0);
    }
}
