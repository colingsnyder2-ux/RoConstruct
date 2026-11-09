// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_7576742091a0fd5e.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afxwin.h>
#include <afxext.h>

class Splitter : public CSplitterWnd {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setStyle(DWORD style);
    char pad[0x118 - sizeof(CSplitterWnd)];
};

class CClassTreeView : public CView { public: static const CRuntimeClass classCClassTreeView; };
class CMemberTreeView : public CView { public: static const CRuntimeClass classCMemberTreeView; };
class CDeclarationView : public CView { public: static const CRuntimeClass classCDeclarationView; };

class TreeLink : public CView {
public:
    char pad[0xa8 - sizeof(CView)];
    CWnd* memberView;
    CWnd* declarationView;
    CWnd* declarationView2;
};

class CObjectBrowser : public CView {
public:
    Splitter m_wndSplitter;
    Splitter m_wndSplitter2;
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

int CObjectBrowser::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CView::OnCreate(lpCreateStruct) == -1)
        return -1;
    if (!m_wndSplitter.CreateStatic(this, 1, 2, WS_CHILD | WS_VISIBLE, AFX_IDW_PANE_FIRST))
        return -1;
    m_wndSplitter.setStyle(4);
    CCreateContext context;
    context.m_pCurrentDoc = m_pDocument;
    if (!m_wndSplitter.CreateView(0, 0, (CRuntimeClass*)&CClassTreeView::classCClassTreeView, CSize(200, 600), &context))
        return -1;
    if (!m_wndSplitter2.CreateStatic(&m_wndSplitter, 2, 1, WS_CHILD | WS_VISIBLE | WS_BORDER, m_wndSplitter.IdFromRowCol(0, 1)))
        return -1;
    if (!m_wndSplitter2.CreateView(0, 0, (CRuntimeClass*)&CMemberTreeView::classCMemberTreeView, CSize(300, 200), &context))
        return -1;
    if (!m_wndSplitter2.CreateView(1, 0, (CRuntimeClass*)&CDeclarationView::classCDeclarationView, CSize(100, 190), &context))
        return -1;
    TreeLink* classes = (TreeLink*)m_wndSplitter.GetPane(0, 0);
    TreeLink* members = (TreeLink*)m_wndSplitter2.GetPane(0, 0);
    CWnd* declarations = m_wndSplitter2.GetPane(1, 0);
    classes->memberView = members;
    classes->declarationView = declarations;
    members->declarationView2 = declarations;
    return 0;
}
