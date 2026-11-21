// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /D_ATL_APARTMENT_THREADED /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// IObjectSafetyRobloxImpl<CApp, 1> (2008-06 VCApp unit). Retired in batch 29: both slots are byte-exact in
// CAppObjectSafety.cpp (GetInterfaceSafetyOptions 00407690, SetInterfaceSafetyOptions 00407720, proved again in
// batch 29). The bodies formerly here did not compile under VC9 (nullptr, C2065) and called an invented
// FinalConstruct where the target calls checkSite (00407500, the CApp instance of 00403b60), so they are removed
// rather than duplicated. Recovery_00407690_IObjectSafetyRobloxImplRecovery_00407690.cpp is a second stale copy of
// the same two specializations (retirement proposal).
#include <afx.h>
#include "CApp2008.h"

// 004078a0 (745 B): CApp::CreateGame (IApp slot 7, ?CreateGame@CApp@@UAGJW4WindowType@@PAPAUIWorkspace@@@Z; the
// registry still holds the placeholder func_004078a0). Identity: VCApp unit (native-asm), `this` is the IApp
// subobject (checkSite through this-0x10, the IObjectSafetyRobloxImpl<CApp,1> base, CApp instance 00407500),
// strings 0080b4cc "Couldn't create workspace", 0080b4e8 "requested WindowType is invalid" (0x57 =
// ERROR_INVALID_PARAMETER) and 0080b4b0 "iworkspace.CopyTo failed" (E_POINTER), all reported against
// browserAppClass 00816508 through reportWorkspaceSiteError 00429330; catch funclet calls doc vtable +0x84
// (CDocument::OnCloseDocument) when the play document was obtained, then reportWorkspaceSiteError(GUID,
// std::exception&) 00429360. PlayWindowType: 0044bbf0 on AfxGetApp() (CRobloxApp: m_pDocManager +0x58 ->
// CIDEDocManager::playTemplate +0x24 -> getPlayDocument 0044b9a0), CRobloxDoc::workspace +0x94, first view via
// GetFirstViewPosition/GetNextView (vtable +0x68/+0x6c), dynamic_cast<CRobloxView*> (RTTI 009289f4 -> 00928a08)
// ->showToolbox(false, true) 004596a0, GetParentFrame()->ShowWindow(SW_SHOW), SetForegroundWindow(m_hWnd).
// PARKED (batch 30, three layout hypotheses rejected): a measured build (with a probe-only declaration of 0044bbf0)
// is 742 vs 745 B with every instruction equal except block placement: the target lays the NoWindowType case
// after the shared CComPtr tail and keeps iworkspace in [ebp+8], this build places it before the tail and uses
// [ebp+0xc]. Rejected: (1) case order PlayWindowType before NoWindowType (identical output), (2) if/else-if chain
// (cmp/jne lowering instead of the target's sub/je switch), (3) default label first (identical output).
// Blockers to land it unguarded: CRobloxApp.h (proposal-only) lacks a declaration of 0044bbf0 (11 B thiscall,
// returns the play CRobloxDoc*), and 00406da0 (cdecl, (CComObject<CWorkspace>** out, unused second argument),
// a CComObject<CWorkspace>::CreateInstance variant without the null test) has no registry name or declaration.
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
