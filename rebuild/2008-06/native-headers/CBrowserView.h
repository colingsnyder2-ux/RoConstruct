#pragma once
#include <XTToolkitPro.h>
#include <list>
#include <string>
#include "CWebToolbox.h"

// RTTI (vtable 0080d814) gives CBrowserView : CXTPCommandBarsSiteBase<CSecureHtmlView>, single
// inheritance. Constructor 004108b0 and destructor 00410950 prove the members below; offsets are
// the stores they make. Only members the code writes or reads are named.
class CBrowserView : public CXTPCommandBarsSiteBase<CSecureHtmlView> {
    DECLARE_DYNCREATE(CBrowserView)
public:
    std::list<std::string> pages;  // +0xfc: list constructor 00410830, destructor 0055e5f0
    CXTPControlComboBox* addressBox;  // +0x118: created by OnCreateControl for command 0x80c9
    CXTPToolBar toolBar;           // +0x11c: CXTPToolBar constructor 006c1da0, destructor 006c1eb0
    CComPtr<IUnknown> external;    // +0x2c4: own EH state; released after address is destroyed
    bool canGoBack;                // +0x2c8: OnCommandStateChange(CSC_NAVIGATEBACK)
    bool canGoForward;             // +0x2c9: OnCommandStateChange(CSC_NAVIGATEFORWARD)
    CString address;               // +0x2cc
    CBrowserView();                // 004108b0
    virtual ~CBrowserView();       // 00410950
    virtual void OnNavigateComplete2(LPCTSTR url);            // 00410ea0
    virtual void OnTitleChange(LPCTSTR title);                // 0040e560
    virtual void OnDocumentComplete(LPCTSTR url);             // 0040dfd0
    virtual void OnCommandStateChange(long command, BOOL enable);  // 0040dfe0
    virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO* info);       // 0040dfb0
protected:
    afx_msg int OnCreate(LPCREATESTRUCT create);              // 0040e5b0, WM_CREATE
    afx_msg void OnSize(UINT type, int cx, int cy);           // 0040e040, WM_SIZE
    afx_msg void OnStop();                                    // 0040e930, command 0x80bb
    afx_msg void OnUpdateStop(CCmdUI* ui);                    // 0040e940
    afx_msg void OnHome();                                    // 0040e790, command 0x80bd
    afx_msg void OnUpdateHome(CCmdUI* ui);                    // 0040e130
    afx_msg void OnRefresh();                                 // 0040e7d0, command 0x80bc
    afx_msg void OnUpdateAlways(CCmdUI* ui);                  // folded into 0042e550
    afx_msg void OnBack();                                    // 0040e920, command 0x80ba
    afx_msg void OnUpdateBack(CCmdUI* ui);                    // 0040e0d0
    afx_msg void OnForward();                                 // 0040e7e0, command 0x80b9
    afx_msg void OnUpdateForward(CCmdUI* ui);                 // 0040e0f0
    afx_msg void OnGo();                                      // 0040e7f0, command 0x80ca
    afx_msg void OnUpdateGo(CCmdUI* ui);                      // 0040e110
    afx_msg void OnAddressExecute(NMHDR* header, LRESULT* result);  // 0040eda0, CBN_XTP_EXECUTE 0x80c9
    afx_msg int OnCreateControl(LPCREATECONTROLSTRUCT create);  // 0040e670, WM_XTP_BEFORECREATECONTROL
    afx_msg BOOL OnEraseBkgnd(CDC* dc);                       // folded into 006e8870
    DECLARE_MESSAGE_MAP()
};

// RTTI (vtables 0080da6c and 0080dcac): both derive from CBrowserView only and override no
// virtual besides GetRuntimeClass; their constructors 00410c40 and 00410cd0 set the start page.
class CIDEBrowserView : public CBrowserView {
    DECLARE_DYNCREATE(CIDEBrowserView)
public:
    CIDEBrowserView();             // 00410c40
};

class CPlayBrowserView : public CBrowserView {
    DECLARE_DYNCREATE(CPlayBrowserView)
public:
    CPlayBrowserView();            // 00410cd0
};
