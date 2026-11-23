// =============================================================================
// Workspace.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/Workspace.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <afxwin.h>
#include "CWorkspace.h"

HRESULT __stdcall CWorkspace::Close() {
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    cleanup();
    return S_OK;
}

#include "util/NativeContentProvider.h"
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

#include <afxdisp.h>
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

template class ATL::CComPtrBase<IContent>;
