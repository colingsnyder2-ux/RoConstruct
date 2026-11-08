#pragma once
// >>> native-status (generated) -- do not edit >>>
// CBrowserView | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src b4667890 | roc native-status --write
#include "CSecureHtmlView.h"
#include <XTToolkitPro.h>
#include <atlbase.h>
#include <algorithm>
#include <list>
#include <string>

class CBrowserViewExternal;

// Inactive layout recovery from CRuntimeClass 0080cf58 (size 0x2d0, CreateObject 00410d60, no base
// pointer: RUNTIME_CLASS base is the template site class), RTTI of vtable 0080d814 (CBrowserView :
// CXTPCommandBarsSiteBase<CSecureHtmlView> : CSecureHtmlView : CHtmlView, all at offset 0), the
// constructor 004108b0 (CSecureHtmlView 00465a60, +0xf8 = 0, list ctor at +0xfc, +0x118 = 0,
// CXTPToolBar ctor at +0x11c, +0x2c4 = 0, bytes +0x2c8/+0x2c9 = 0, CString ctor at +0x2cc) and the
// destructor 00410950 (CString dtor +0x2cc, Release of +0x2c4, ~CXTPToolBar +0x11c, ~list +0xfc,
// ~CXTPCommandBarsSiteBase<CSecureHtmlView> 0040e230). Deleting destructor 00410e80 is shared
// (identical-COMDAT folded) by CIDEBrowserView and CPlayBrowserView, which add no members.
class CBrowserView : public CXTPCommandBarsSiteBase<CSecureHtmlView> {
    DECLARE_DYNCREATE(CBrowserView)
    DECLARE_MESSAGE_MAP()
public:
    enum {
        ID_BROWSER_FORWARD = 0x80b9,
        ID_BROWSER_BACK = 0x80ba,
        ID_BROWSER_STOP = 0x80bb,
        ID_BROWSER_REFRESH = 0x80bc,
        ID_BROWSER_HOME = 0x80bd,
        ID_BROWSER_ADDRESS = 0x80c9,
        ID_BROWSER_GO = 0x80ca,
    };
    CBrowserView();                                                             // 004108b0
    virtual ~CBrowserView();                                                    // 00410950
    virtual void OnInitialUpdate();                                             // 0040ed50
    virtual HRESULT OnGetExternal(LPDISPATCH* dispatch);                        // 0040fff0
    virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO* info);                         // 0040dfb0
    virtual void OnNavigateComplete2(LPCTSTR url);                              // 00410ea0
    virtual void OnBeforeNavigate2(LPCTSTR url, DWORD flags, LPCTSTR targetFrameName,
                                   CByteArray& postedData, LPCTSTR headers, BOOL* cancel); // 004109e0
    virtual void OnCommandStateChange(long command, BOOL enable);               // 0040dfe0
    virtual void OnTitleChange(LPCTSTR text);                                   // 0040e560
    virtual void OnDocumentComplete(LPCTSTR url);                               // 0040dfd0

    BOOL OnEraseBkgnd(CDC* dc);                                                 // 006e8870 (folded)
    void OnSize(UINT type, int cx, int cy);                                     // 0040e040
    int OnCreate(LPCREATESTRUCT cs);                                            // 0040e5b0
    void OnStop();                                                              // 0040e930
    void OnUpdateStop(CCmdUI* ui);                                              // 0040e940
    void OnHome();                                                              // 0040e790
    void OnUpdateHome(CCmdUI* ui);                                              // 0040e130
    void OnRefresh();                                                           // 0040e7d0
    void OnUpdateRefresh(CCmdUI* ui);                                           // 0042e550 (folded)
    void OnBack();                                                              // 0040e920
    void OnUpdateBack(CCmdUI* ui);                                              // 0040e0d0
    void OnForward();                                                           // 0040e7e0
    void OnUpdateForward(CCmdUI* ui);                                           // 0040e0f0
    void OnGo();                                                                // 0040e7f0
    void OnUpdateGo(CCmdUI* ui);                                                // 0040e110
    void OnAddressExecute(NMHDR* nm, LRESULT* result);                          // 0040eda0
    int OnCreateControl(LPCREATECONTROLSTRUCT create);                          // 0040e670

    std::list<std::string> history;          // +0xfc: push_back in OnBeforeNavigate2, trimmed past 50, searched by OnNavigateComplete2
    CXTPControlComboBox* addressCombo;       // +0x118: created by OnCreateControl for ID_BROWSER_ADDRESS
    CXTPToolBar toolBar;                     // +0x11c: CreateToolBar in OnCreate, laid out by OnSize
    CComPtr<IDispatch> external;             // +0x2c4: created by OnGetExternal, released by the destructor
    bool canGoBack;                          // +0x2c8: OnCommandStateChange(CSC_NAVIGATEBACK)
    bool canGoForward;                       // +0x2c9: OnCommandStateChange(CSC_NAVIGATEFORWARD)
    CString homeUrl;                         // +0x2cc: set by the subclass constructors, navigated by OnInitialUpdate/OnHome
};

// CRuntimeClass 0080cf74 (size 0x2d0, CreateObject 00410dc0, base CBrowserView), vtable 0080da6c.
class CIDEBrowserView : public CBrowserView {
    DECLARE_DYNCREATE(CIDEBrowserView)
public:
    CIDEBrowserView();                                                          // 00410c40
};

// CRuntimeClass 0080cf90 (size 0x2d0, CreateObject 00410e20, base CBrowserView), vtable 0080dcac.
class CPlayBrowserView : public CBrowserView {
    DECLARE_DYNCREATE(CPlayBrowserView)
public:
    CPlayBrowserView();                                                         // 00410cd0
};
