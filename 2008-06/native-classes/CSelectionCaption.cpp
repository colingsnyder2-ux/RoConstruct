#include "CSelectionCaption.h"
#include "v8datamodel/SelectionChanged.h"

IMPLEMENT_DYNAMIC(CSelectionCaption, CXTCaption)

BEGIN_MESSAGE_MAP(CSelectionCaption, CWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CSelectionCaption::CSelectionCaption()
{
}

bool CSelectionCaption::filter(const RBX::Selection*, const RBX::SelectionChanged&,
                               const RBX::Selection*, const RBX::SelectionChanged&)
{
    return true;
}

BOOL CSelectionCaption::PreCreateWindow(CREATESTRUCT& create)
{
    return CWnd::PreCreateWindow(create);
}

BOOL CSelectionCaption::Create(LPCTSTR text, DWORD style, const RECT& bounds, CWnd* parent, UINT id)
{
    return CStatic::Create(text, style, bounds, parent, id);
}

int CSelectionCaption::OnCreate(LPCREATESTRUCT)
{
    if (Default() == -1) return -1;
    refresh();
    return 0;
}

void CSelectionCaption::onMarshaledEvent(const RBX::Selection*, RBX::SelectionChanged)
{
    updateCaption();
}
