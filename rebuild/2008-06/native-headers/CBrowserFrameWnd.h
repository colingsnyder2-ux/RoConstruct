#pragma once
#include <XTToolkitPro.h>

// Declarations only. CRuntimeClass 00811e90 (size 0xec, CreateObject 00433280: CXTPFrameWnd::CXTPFrameWnd 006e1960,
// vtable 0081225c), RTTI CBrowserFrameWnd : CXTPFrameWnd : CXTPFrameWndBase<CFrameWnd> : CXTPCommandBarsSiteBase<CFrameWnd>,
// deleting destructor 00433240. No own members (allocation size equals the XTP base). Own vtable bodies (unrecovered):
// slots 12 (message map 00433270), 68 00433030, 71 004330c0, 82 004331c0, 95 00433210.
class CBrowserFrameWnd : public CXTPFrameWnd {
    DECLARE_DYNCREATE(CBrowserFrameWnd)
    DECLARE_MESSAGE_MAP()
public:
    CBrowserFrameWnd();
};
