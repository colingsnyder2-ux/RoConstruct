#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

IMPLEMENT_DYNAMIC(CRobloxReportView, CXTPReportView)

// Entry order from the AFX_MSGMAP_ENTRY table at 008187b8 (base 006c6890 CXTPReportView::GetThisMessageMap).
BEGIN_MESSAGE_MAP(CRobloxReportView, CXTPReportView)
    ON_WM_CREATE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

// Original 00457a40.
CRobloxReportView::CRobloxReportView()
    : timer(0)
{
}

// Original 00458b70.
CRobloxReportView::~CRobloxReportView()
{
    setDataModel(boost::shared_ptr<RBX::DataModel>());
}

// Original 00455fd0: two read-only columns ("Name" tree column, "Value"), no group-by box.
int CRobloxReportView::OnCreate(LPCREATESTRUCT cs)
{
    if (CXTPReportView::OnCreate(cs) == -1)
        return -1;
    CXTPReportControl& control = GetReportCtrl();
    control.ShowGroupBy(FALSE);
    control.GetReportHeader()->AllowColumnSort(FALSE);
    control.GetReportHeader()->AllowColumnRemove(FALSE);
    control.GetReportHeader()->SetAutoColumnSizing(TRUE);
    CXTPReportColumn* name = control.AddColumn(new CXTPReportColumn(0, _T("Name"), 200));
    name->SetTreeColumn(TRUE);
    name->SetEditable(FALSE);
    CXTPReportColumn* value = control.AddColumn(new CXTPReportColumn(1, _T("Value"), 200));
    value->SetEditable(FALSE);
    return 0;
}

// Original 00456e60.
void CRobloxReportView::OnTimer(UINT_PTR id)
{
    updateStats();
    CXTPReportView::OnTimer(id);
}

// Original 004589c0.
void CRobloxReportView::OnInitialUpdate()
{
    CXTPReportView::OnInitialUpdate();
    CRobloxDoc* document = static_cast<CRobloxDoc*>(m_pDocument);
    if (document)
        setDataModel(document->getDataModel());
    else
        setDataModel(boost::shared_ptr<RBX::DataModel>());
}

