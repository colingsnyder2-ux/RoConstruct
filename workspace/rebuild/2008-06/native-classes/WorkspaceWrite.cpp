// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr
// >>> native-status (generated) -- do not edit >>>
// WorkspaceWrite | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/3 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 13a5ff3f | roc native-status --write
#include <afxwin.h>
#include <afxdisp.h>
#include "CWorkspace.h"
#include "CContent.h"
#include "v8xml/XmlElement.h"

extern const CLSID workspaceSiteErrorContext;
extern void __cdecl reportWorkspaceHResult(int, HRESULT, const char*, int);
extern __declspec(noreturn) void __cdecl raiseWorkspaceError(HRESULT, REFCLSID);
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);

#define CHECK_RESULT(expr, line) ((void)(!(expr) || (reportWorkspaceHResult(1, (expr), ".\\Workspace.cpp", line), raiseWorkspaceError((expr), workspaceSiteErrorContext), 0)))

HRESULT __stdcall CWorkspace::Write(IContent** result) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    try {
        ATL::CComObject<CContent>* object;
        {
            ATL::CComObject<CContent>* p;
            CHECK_RESULT(ATL::CComObject<CContent>::CreateInstance(&p), 300);
            __assume(p != 0);
            IContent* q = p;
            __assume(q != 0);
            object = static_cast<ATL::CComObject<CContent>*>(q);
        }
        CHECK_RESULT(write(writeXmlModel().get(), object->stream), 304);
        ATL::CComPtr<IContent> p(object);
        CHECK_RESULT(p.CopyTo(result), 308);
    } catch (const std::exception& e) {
        return reportWorkspaceSiteError(workspaceSiteErrorContext, e.what(), 0);
    } catch (CException* e) {
        HRESULT hr = COleException::Process(e);
        e->Delete();
        return hr;
    }
    return S_OK;
}

HRESULT __stdcall CWorkspace::WriteSelection(IContent** result) {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    try {
        ATL::CComObject<CContent>* object;
        {
            ATL::CComObject<CContent>* p;
            CHECK_RESULT(ATL::CComObject<CContent>::CreateInstance(&p), 331);
            __assume(p != 0);
            IContent* q = p;
            __assume(q != 0);
            object = static_cast<ATL::CComObject<CContent>*>(q);
        }
        CHECK_RESULT(write(writeXmlSelection().get(), object->stream), 334);
        ATL::CComPtr<IContent> p(object);
        CHECK_RESULT(p.CopyTo(result), 338);
    } catch (const std::exception& e) {
        return reportWorkspaceSiteError(workspaceSiteErrorContext, e.what(), 0);
    } catch (CException* e) {
        HRESULT hr = COleException::Process(e);
        e->Delete();
        return hr;
    }
    return S_OK;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class ATL::CComPtrBase<IContent>;
