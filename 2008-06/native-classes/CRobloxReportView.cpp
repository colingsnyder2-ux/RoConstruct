// >>> native-status (generated) -- do not edit >>>
// CRobloxReportView | 2008-06 | 4 byte-exact, inactive (not link-selected)
// 4/7 mapped addresses byte-exact | 3 unproved | no mapped strings | by king_originala (+3) (mixed 4)
// <<< native-status | src 530e5cd3 | roc native-status --write
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

// Original 00458700 (open, 669 vs 700 bytes): every statement aligns; the original emits a separate release of
// the argument for the early return and tail-merges it into the final release, this build jumps to the common one.
void CRobloxReportView::setDataModel(boost::shared_ptr<RBX::DataModel> dataModel)
{
    if (dataModel == this->dataModel)
        return;
    if (this->dataModel) {
        RBX::DataModel::Lock lock(this->dataModel);
        // ServiceProvider::find<RunService>(provider) inline form (null test, member find 00452c80; result unused).
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

// Original 004582f0 (open, 388 vs 391 bytes): identical except operator new(0xb0) - sizeof(CStatsItemRecord) needs
// the record layout (see the header).
void CRobloxReportView::onMarshaledEvent(const RBX::Instance*, RBX::ChildAdded event)
{
    CXTPReportControl& control = GetReportCtrl();
    boost::shared_ptr<RBX::Stats::Item> item = boost::shared_dynamic_cast<RBX::Stats::Item>(event.child);
    if (!item)
        return;
    CStatsItemRecord* record = new CStatsItemRecord(item, dataModel);
    record->SetExpanded(TRUE);
    control.AddRecord(record);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
