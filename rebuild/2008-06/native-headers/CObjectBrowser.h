#pragma once
#include "CClassTreeView.h"

// Inactive layout recovery: the object browser view hosting the three reflection panes.
// CRuntimeClass 00812520 (name "CObjectBrowser" 008124a8, size 0x288, schema 0xffff, CreateObject 00433950
// allocating 0x288, base getter 006c4cb0 = jmp CView::GetThisClass import, an identical-COMDAT fold);
// RTTI vtable 00812794 (101 slots; CObjectBrowser : CView, single inheritance, offset 0). CView (mfc90) is 0x58.
// Constructor 00433420: CView::CView, vtable, then CXTSplitterWnd::CXTSplitterWnd (00708c50) on +0x58 and +0x170
// (EH states 0, 1); destructor 00433480: CXTSplitterWnd::~CXTSplitterWnd (00708280) on +0x170 then +0x58, then
// CView::~CView. 0x170 - 0x58 = 0x288 - 0x170 = 0x118 = sizeof(CXTSplitterWnd) (XTP 11.2.2).
// OnCreate 00433b80: +0x58 is CreateStatic'd 1x2 on the view (pane 0,0 = CClassTreeView 00812504), +0x170 is
// CreateStatic'd 2x1 inside its pane (0,1) (CMemberTreeView 0081253c over CDeclarationView 008124e8); the panes
// are then linked through CClassTreeView +0xa8/+0xac and CMemberTreeView +0xb0. Member names provisional.
// Message map 00812b64: base CView::GetThisMessageMap import; WM_SIZE (sig 0x19 AfxSig_vwii) 004339d0,
// WM_CREATE (sig 0xd AfxSig_is) 00433b80.
class CObjectBrowser : public CView {
    DECLARE_DYNCREATE(CObjectBrowser)
    DECLARE_MESSAGE_MAP()
public:
    CObjectBrowser();                                         // 00433420
    virtual ~CObjectBrowser();                                // 00433480 (deleting 004339b0)
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);           // slot 27, 00463910 (fold, shared with CScriptEditor)
    virtual void OnInitialUpdate();                           // slot 91, 004334f0
    virtual void OnDraw(CDC* pDC);                            // slot 95, 0070bdf0 (empty body, shared `ret 4` fold)

    afx_msg int OnCreate(LPCREATESTRUCT cs);                  // 00433b80
    afx_msg void OnSize(UINT nType, int cx, int cy);          // 004339d0

    CXTSplitterWnd classSplitter;                             // +0x58, 1x2: class tree | memberSplitter
    CXTSplitterWnd memberSplitter;                            // +0x170, 2x1: member tree over declaration view
};
