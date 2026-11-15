#pragma once
#include <afxwin.h>

// Inactive layout recovery of the two MDI child frames.
//
// CChildFrame: RTTI CChildFrame : CMDIChildWnd : CFrameWnd : CWnd : CCmdTarget : CObject (vtable 0080e4a4,
// 105 slots; the AFX_MSGMAP messageMap 0080e648 follows it). CRuntimeClass 0080e468 ("CChildFrame" 0080e430,
// size 0xf0, schema 0xffff, CreateObject 00412c90, base getter 00412ae0 = jmp CMDIChildWnd::GetThisClass).
// CreateObject calls operator new(0xf0), CMDIChildWnd::CMDIChildWnd (mfc90) and stores only the vptr; the
// deleting destructor 00412c60 stores the vptr and calls CFrameWnd::~CFrameWnd. sizeof(CMDIChildWnd) is
// 0xf0, so the class adds no data members. Own vtable slots: 0 GetRuntimeClass 00412af0, 1 deleting dtor
// 00412c60, 12 GetMessageMap 00412c50, 27 PreCreateWindow 00412b00, 87 ActivateFrame 00412b40. Message map
// entries 0080e650: WM_CREATE (AfxSig_is) -> OnCreate 00412b90.
class CChildFrame : public CMDIChildWnd {
    DECLARE_DYNCREATE(CChildFrame)
public:
    CChildFrame() {}
    virtual ~CChildFrame();
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
    virtual void ActivateFrame(int nCmdShow = -1);
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()
};

// CRbxChildFrame: RTTI CRbxChildFrame : CChildFrame : ... (vtable 0080e684, 105 slots; messageMap 0080e828
// follows it, base map getter 00412c50 = CChildFrame::GetThisMessageMap). CRuntimeClass 0080e484
// ("CRbxChildFrame" 0080e420, size 0xf0, schema 0xffff, CreateObject 00412cf0, base getter 00412af0 folded
// with CChildFrame::GetRuntimeClass). CreateObject allocates 0xf0 like CChildFrame: no own members. Own
// slots: 0 GetRuntimeClass 00412b80, 12 GetMessageMap 00412f20; slot 1 is CChildFrame's deleting destructor
// 00412c60 (identical code folded). Message map entries 0080e830: WM_GETMINMAXINFO -> OnGetMinMaxInfo
// 00412e60.
class CRbxChildFrame : public CChildFrame {
    DECLARE_DYNCREATE(CRbxChildFrame)
public:
    CRbxChildFrame() {}
protected:
    afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
    DECLARE_MESSAGE_MAP()
};
