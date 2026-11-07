#pragma once
// >>> native-status (generated) -- do not edit >>>
// CWebToolbox | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1d262003 | roc native-status --write
#include "CSecureHtmlView.h"
#include <atlbase.h>

// Inactive layout recovery from CRuntimeClass 0081c4a8 (size 0x100, CreateObject 0046a850, base
// CSecureHtmlView), vtable 0081c4f4, the inlined constructor in CreateObject (CSecureHtmlView
// constructor 00465a60, vtable, +0xfc = 0) and the deleting destructor 0046a7e0 (vtable, release
// of +0xfc, ~CSecureHtmlView 00465a80). CRobloxView::showToolbox (004596a0) creates it through the runtime class, stores the
// workspace at +0xfc and the view's render window at +0xf8.
class CWebToolbox : public CSecureHtmlView {
    DECLARE_DYNCREATE(CWebToolbox)
    DECLARE_MESSAGE_MAP()
public:
    CWebToolbox();
    virtual ~CWebToolbox();
    virtual void OnInitialUpdate();                                            // 0046a710
    virtual void OnActivateView(BOOL activate, CView* activateView, CView* deactiveView); // 0046a6a0
    virtual HRESULT OnGetExternal(LPDISPATCH* dispatch);                       // 0046a8e0
    virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO* info);                        // 0046a680
    virtual HRESULT OnDocWindowActivate(BOOL activate);                        // 0046a640
    virtual HRESULT OnFrameWindowActivate(BOOL activate);                      // 0046a660
    void OnGetMinMaxInfo(MINMAXINFO* info);                                    // 0046a7a0
    void OnSetFocus(CWnd* oldWnd);                                             // 0046a6d0
    int OnMouseActivate(CWnd* desktopWnd, UINT hitTest, UINT message);         // 0046a6f0
    void showPage(int page);                                                   // 0046a590, called by CRobloxView 00459810
    void OnLButtonUp(UINT flags, CPoint point);                                // 0046a7c0 (folded)
    void OnActivate(UINT state, CWnd* other, BOOL minimized);                  // 0046a7c0 (folded)

    CWnd* owner;                    // +0xf8, set to &CRobloxView::window by 004596a0; receives SetFocus in every handler
    CComPtr<IDispatch> external;    // +0xfc, nulled by the constructor, released by the destructor, returned by OnGetExternal
};
