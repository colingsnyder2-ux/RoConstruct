// >>> native-status (generated) -- do not edit >>>
// CObjectBrowser | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src c7f8d5b8 | roc native-status --write
#include "CObjectBrowser.h"
#include <algorithm>

IMPLEMENT_DYNCREATE(CObjectBrowser, CView)

BEGIN_MESSAGE_MAP(CObjectBrowser, CView)
    ON_WM_SIZE()
    ON_WM_CREATE()
END_MESSAGE_MAP()

CObjectBrowser::CObjectBrowser()
{
}

CObjectBrowser::~CObjectBrowser()
{
}

BOOL CObjectBrowser::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs) != FALSE;
}

void CObjectBrowser::OnInitialUpdate()
{
    CView::OnInitialUpdate();
}

void CObjectBrowser::OnDraw(CDC* pDC)
{
}

// Original 004339d0: keeps the member pane's height when the browser grows or shrinks (clamped to [50, cy - 150]).
// Not exact (210 vs 212 bytes): the original evaluates cy - (bottom - top); this compiles to top - bottom + cy.
void CObjectBrowser::OnSize(UINT nType, int cx, int cy)
{
    CView::OnSize(nType, cx, cy);
    if (nType != SIZE_MINIMIZED && classSplitter.m_hWnd) {
        CRect rect;
        classSplitter.GetClientRect(&rect);
        int delta = cy - rect.Height();
        classSplitter.MoveWindow(0, 0, cx, cy, TRUE);
        if (memberSplitter.m_hWnd) {
            int current, minimum;
            memberSplitter.GetRowInfo(0, current, minimum);
            int height = current + delta;
            height = (std::min)(cy - 150, height);
            height = (std::max)(50, height);
            memberSplitter.SetRowInfo(0, height, 0);
            memberSplitter.RecalcLayout();
        }
    }
}

// Original 00433b80. The original pushes the pane CRuntimeClass addresses directly (_RUNTIME_CLASS), not the
// out-of-line GetThisClass() calls that RUNTIME_CLASS expands to under _AFXDLL.
int CObjectBrowser::OnCreate(LPCREATESTRUCT cs)
{
    if (CView::OnCreate(cs) == -1)
        return -1;
    if (!classSplitter.CreateStatic(this, 1, 2))
        return -1;
    classSplitter.SetSplitterStyle(XT_SPLIT_NOBORDER);
    CCreateContext context;
    context.m_pCurrentDoc = GetDocument();
    if (!classSplitter.CreateView(0, 0, _RUNTIME_CLASS(CClassTreeView), CSize(200, 600), &context))
        return -1;
    if (!memberSplitter.CreateStatic(&classSplitter, 2, 1, WS_CHILD | WS_VISIBLE | WS_BORDER, classSplitter.IdFromRowCol(0, 1)))
        return -1;
    if (!memberSplitter.CreateView(0, 0, _RUNTIME_CLASS(CMemberTreeView), CSize(300, 200), &context))
        return -1;
    if (!memberSplitter.CreateView(1, 0, _RUNTIME_CLASS(CDeclarationView), CSize(100, 190), &context))
        return -1;
    CClassTreeView* classView = static_cast<CClassTreeView*>(classSplitter.GetPane(0, 0));
    CMemberTreeView* memberView = static_cast<CMemberTreeView*>(memberSplitter.GetPane(0, 0));
    CDeclarationView* declarationView = static_cast<CDeclarationView*>(memberSplitter.GetPane(1, 0));
    classView->memberView = memberView;
    classView->declarationView = declarationView;
    memberView->declarationView = declarationView;
    return 0;
}
