// =============================================================================
// IObjectSafetyRobloxImpl.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/IObjectSafetyRobloxImpl.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <afx.h>
#include "CApp2008.h"

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::GetInterfaceSafetyOptions(
    REFIID iid, DWORD* supported, DWORD* enabled)
{
    CApp* owner = static_cast<CApp*>(this);
    if (!supported || !enabled) return E_POINTER;
    IUnknown* object;
    HRESULT result = owner->GetUnknown()->QueryInterface(iid, reinterpret_cast<void**>(&object));
    if (SUCCEEDED(result)) {
        object->Release();
        if (checkSite()) {
            *supported = 1;
            *enabled = 0;
        } else {
            *supported = 1;
            *enabled = currentSafety;
        }
    } else {
        *supported = 0;
        *enabled = 0;
    }
    return result;
}

template<>
HRESULT __stdcall IObjectSafetyRobloxImpl<CApp, 1>::SetInterfaceSafetyOptions(
    REFIID iid, DWORD mask, DWORD enabled)
{
    CApp* owner = static_cast<CApp*>(this);
    IUnknown* object;
    if (FAILED(owner->GetUnknown()->QueryInterface(iid, reinterpret_cast<void**>(&object))))
        return E_NOINTERFACE;
    object->Release();
    if (mask & ~1) return E_FAIL;
    HRESULT result = checkSite();
    if (result != S_OK) return result;
    currentSafety = (currentSafety & ~mask) | (mask & enabled);
    return S_OK;
}

#ifdef NATIVE_CAPP_CREATEGAME_PENDING
#include "CRobloxApp.h"
#include "CRobloxDoc.h"
#include "CRobloxView.h"
#include <exception>

extern const CLSID browserAppClass;                                                  // 00816508
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const char*, HRESULT);     // 00429330
extern HRESULT __cdecl reportWorkspaceSiteError(REFCLSID, const std::exception&);    // 00429360
// INFERRED: 00406da0, name provisional (placeholder func_00406da0).
HRESULT __cdecl createWorkspaceObject(ATL::CComObject<CWorkspace>** result, IUnknown* outer);

STDMETHODIMP CApp::CreateGame(WINDOW_TYPE type, IWorkspace** result)
{
    AFX_MANAGE_STATE(AfxGetAppModuleState());
    CRobloxDoc* doc = NULL;
    try {
        HRESULT hr = checkSite();
        if (hr) return hr;
        CWorkspace* workspace;
        CRobloxApp* app = static_cast<CRobloxApp*>(AfxGetApp());
        switch (type) {
        case NoWindowType: {
            ATL::CComObject<CWorkspace>* object;
            hr = createWorkspaceObject(&object, 0);
            if (hr) return reportWorkspaceSiteError(browserAppClass, "Couldn't create workspace", hr);
            workspace = object;
            break;
        }
        case PlayWindowType: {
            doc = app->getPlayDocument();   // 0044bbf0: needs a CRobloxApp.h declaration (proposal)
            workspace = doc->workspace;
            POSITION pos = doc->GetFirstViewPosition();
            if (pos) {
                CView* view = doc->GetNextView(pos);
                if (view) {
                    if (CRobloxView* robloxView = dynamic_cast<CRobloxView*>(view))
                        robloxView->showToolbox(false, true);
                    view->GetParentFrame()->ShowWindow(SW_SHOW);
                    ::SetForegroundWindow(view->m_hWnd);
                }
            }
            break;
        }
        default:
            return reportWorkspaceSiteError(browserAppClass, "requested WindowType is invalid", ERROR_INVALID_PARAMETER);
        }
        ATL::CComPtr<IWorkspace> iworkspace(workspace);
        hr = iworkspace.CopyTo(result);
        if (FAILED(hr)) return reportWorkspaceSiteError(browserAppClass, "iworkspace.CopyTo failed", hr);
        return S_OK;
    } catch (std::exception& e) {
        if (doc) doc->OnCloseDocument();
        return reportWorkspaceSiteError(browserAppClass, e);
    }
}
#endif

#include "CWorkspace.h"

template<class T, DWORD Supported>
HRESULT __stdcall IObjectSafetyRobloxImpl<T, Supported>::GetInterfaceSafetyOptions(
    REFIID iid, DWORD* supported, DWORD* enabled)
{
    T* owner = static_cast<T*>(this);
    if (!supported || !enabled) return E_POINTER;
    IUnknown* object;
    HRESULT result = static_cast<IWorkspace*>(owner)->QueryInterface(iid, reinterpret_cast<void**>(&object));
    if (SUCCEEDED(result)) {
        object->Release();
        if (checkSite()) {
            *supported = Supported;
            *enabled = 0;
        } else {
            *supported = Supported;
            *enabled = currentSafety;
        }
    } else {
        *supported = 0;
        *enabled = 0;
    }
    return result;
}

template<class T, DWORD Supported>
HRESULT __stdcall IObjectSafetyRobloxImpl<T, Supported>::SetInterfaceSafetyOptions(
    REFIID iid, DWORD mask, DWORD enabled)
{
    T* owner = static_cast<T*>(this);
    IUnknown* object;
    if (FAILED(static_cast<IWorkspace*>(owner)->QueryInterface(iid, reinterpret_cast<void**>(&object))))
        return E_NOINTERFACE;
    object->Release();
    if (mask & ~Supported) return E_FAIL;
    HRESULT result = checkSite();
    if (result != S_OK) return result;
    currentSafety = (currentSafety & ~mask) | (mask & enabled);
    return S_OK;
}

template class IObjectSafetyRobloxImpl<CWorkspace, 1>;
