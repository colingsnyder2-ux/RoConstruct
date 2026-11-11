#pragma once
// >>> native-status (generated) -- do not edit >>>
// CBrowserFrameWnd | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8dff816b | roc native-status --write
#include <XTToolkitPro.h>

// Inactive layout/lifecycle recovery of the browser shell frame.
//
// RTTI CBrowserFrameWnd : CXTPFrameWnd : CXTPFrameWndBase<CFrameWnd> : CXTPCommandBarsSiteBase<CFrameWnd> : CFrameWnd
// (vtable 0081225c, 103 slots). CRuntimeClass 00811e90 (name 00811e70, size 0xec, schema 0xffff,
// CreateObject 00433280, base getter 00432fb0 = jmp CXTPFrameWnd::GetThisClass). CreateObject calls operator new(0xec),
// CXTPFrameWnd::CXTPFrameWnd (006e1960) and stores only the vptr; the deleting destructor 00433240 stores the
// CXTPFrameWndBase vptr (00812054) and calls the site-base destructor 00432fd0 (which releases the command bars at
// +0xe8) before operator delete. sizeof(CXTPFrameWnd) is 0xec, so the class adds no data members.
// Own vtable slots: 0 GetRuntimeClass 00432fc0, 1 deleting destructor 00433240, 12 GetMessageMap 00433270.
// Slots 68 PreTranslateMessage 00433030, 71 OnWndMsg 004330c0, 82 LoadFrame 004331c0 and 92 OnSetPreviewMode 00433210
// are the XTP header templates inherited unchanged (the same addresses fill the CXTPFrameWndBase vtable 00812054).
// Message map 008121f0 (base CFrameWnd): WM_DESTROY -> CFrameWnd::OnDestroy, WM_CREATE -> OnCreate 00433130,
// WM_NCDESTROY -> CWnd::OnNcDestroy.
class CBrowserFrameWnd : public CXTPFrameWnd {
    DECLARE_DYNCREATE(CBrowserFrameWnd)
public:
    CBrowserFrameWnd() {}
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()
};
