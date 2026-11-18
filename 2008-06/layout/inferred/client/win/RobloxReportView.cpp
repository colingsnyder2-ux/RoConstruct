#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

IMPLEMENT_DYNAMIC(CRobloxReportView, CXTPReportView)

BEGIN_MESSAGE_MAP(CRobloxReportView, CXTPReportView)
    ON_WM_CREATE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

CRobloxReportView::CRobloxReportView()
    : timer(0)
{
}

CRobloxReportView::~CRobloxReportView()
{
    setDataModel(boost::shared_ptr<RBX::DataModel>());
}

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

void CRobloxReportView::OnTimer(UINT_PTR id)
{
    updateStats();
    CXTPReportView::OnTimer(id);
}

void CRobloxReportView::OnInitialUpdate()
{
    CXTPReportView::OnInitialUpdate();
    CRobloxDoc* document = static_cast<CRobloxDoc*>(m_pDocument);
    if (document)
        setDataModel(document->getDataModel());
    else
        setDataModel(boost::shared_ptr<RBX::DataModel>());
}

void CRobloxReportView::setDataModel(boost::shared_ptr<RBX::DataModel> dataModel)
{
    if (dataModel == this->dataModel)
        return;
    if (this->dataModel) {
        RBX::DataModel::Lock lock(this->dataModel);
        if (const RBX::ServiceProvider* provider = this->dataModel.get())
            provider->find<RBX::RunService>();
        RBX::Notifier<RBX::Instance, RBX::ChildAdded>::disconnect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::disconnect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
        RBX::MarshaledListener<RBX::Instance, RBX::ChildAdded>::detach();
        RBX::MarshaledListener<RBX::Instance, RBX::ChildRemoved>::detach();
        GetReportCtrl().GetRecords()->RemoveAll();
    }
    GetReportCtrl().Populate();
    stats.reset();
    this->dataModel = dataModel;
    if (this->dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        stats = RBX::shared_from<RBX::Instance>(RBX::ServiceProvider::create<RBX::Stats::StatsService>(this->dataModel.get()));
        timer = ::SetTimer(m_hWnd, 1, 333, NULL);
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::connect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
        RBX::Notifier<RBX::Instance, RBX::ChildAdded>::connect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
        RBX::ServiceProvider::create<RBX::RunService>(this->dataModel.get());
    } else if (m_hWnd) {
        ::KillTimer(m_hWnd, timer);
    }
}

void CRobloxReportView::onMarshaledEvent(const RBX::Instance* source, RBX::ChildRemoved event)
{
    CXTPReportRecords* records = GetReportCtrl().GetRecords();
    for (int i = records->GetCount() - 1; i >= 0; --i) {
        RBX::Instance* recordValue = *(RBX::Instance* const*)((char*)records->GetAt(i) + 0xa8);
        if (recordValue == event.child.get()) {
            records->RemoveAt(i);
            break;
        }
    }
}

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
