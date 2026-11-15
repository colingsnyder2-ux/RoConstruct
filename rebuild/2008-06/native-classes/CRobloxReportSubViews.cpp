#include "CRobloxReportSubViews.h"
#include "CRobloxDoc.h"

// Original 00405aa0 (cdecl), recovered in ActiveDocument.cpp; historical name unknown.
void setActiveDocument(bool active, CRobloxDoc* document);

IMPLEMENT_DYNCREATE(CRobloxReportDocView, CRobloxReportView)

// Original 00456310.
void CRobloxReportDocView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
    CXTPReportView::OnActivateView(bActivate, pActivateView, pDeactiveView);
    if (bActivate)
        setActiveDocument(true, static_cast<CRobloxDoc*>(m_pDocument));
    else if (pActivateView != pDeactiveView)
        setActiveDocument(false, static_cast<CRobloxDoc*>(m_pDocument));
}

IMPLEMENT_DYNCREATE(CRobloxReportPaneView, CRobloxReportView)

BEGIN_MESSAGE_MAP(CRobloxReportPaneView, CRobloxReportView)
END_MESSAGE_MAP()

// Original 00458c80.
CRobloxReportPaneView::CRobloxReportPaneView()
{
}

// Original 00458a00: the base OnInitialUpdate body, then ActiveDocView::refresh inline (virtual update through
// the ActiveDocView vptr at +0x3d4 with the shared model 0096c25c and an empty previous model).
void CRobloxReportPaneView::OnInitialUpdate()
{
    CXTPReportView::OnInitialUpdate();
    CRobloxDoc* document = static_cast<CRobloxDoc*>(m_pDocument);
    if (document)
        setDataModel(document->getDataModel());
    else
        setDataModel(boost::shared_ptr<RBX::DataModel>());
    ActiveDocView* view = this;
    view->update(activeDocDataModel, boost::shared_ptr<RBX::DataModel>());
}

// Original 00458a90.
void CRobloxReportPaneView::update(boost::shared_ptr<RBX::DataModel> current, boost::shared_ptr<RBX::DataModel>)
{
    setDataModel(current);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Instance,RBX::ChildAdded>;
template class RBX::Listener<RBX::Instance,RBX::ChildRemoved>;
