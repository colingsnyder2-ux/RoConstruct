// =============================================================================
// RobloxReportView.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/win/RobloxReportView.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::disconnect(
            stats,
            static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
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
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::connect(
            stats,
            static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
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
        RBX::Instance* recordValue = static_cast<CStatsItemRecord*>(records->GetAt(i))->getItem();
        if (recordValue == event.child.get()) {
            records->RemoveAt(i);
            break;
        }
    }
}

CString f(bool includeDate);
double sub_00455d70();

// INFERRED: the benchmark log statics of this unit. Only 00456c30 / 00456820 reference them: 0096dbb1 is a bss bool
static bool benchmarkEnabled = false;      // 0096dbb1
static double benchmarkStart = -1.0;       // 00932028
static float benchmarkInterval = 60.0f;    // 00931800
static FILE* benchmarkFile = NULL;         // 0096dd84

void CRobloxReportView::updateStats()
{
    RBX::DataModel::Lock lock(dataModel);
    GetReportCtrl().Populate();
    GetReportCtrl().RedrawControl();
    if (benchmarkEnabled) {
        if (benchmarkStart < 0)
            benchmarkStart = sub_00455d70();
        else if (sub_00455d70() - benchmarkStart > benchmarkInterval * 1.01) {
            if (!benchmarkFile) {
                CString name = "c:\\roblox_bench_" + f(false) + ".txt";
                benchmarkFile = fopen(name, "wt");
                if (!benchmarkFile)
                    throw std::exception("Cannot open benchmark file " + name);
            }
            CXTPReportRecords* records = GetReportCtrl().GetRecords();
            fprintf(benchmarkFile, "WallTime = %s\n", f(false));
            logRecords(records, "");
            fflush(benchmarkFile);
        }
    }
}

// Original 00456820 (1038 B, registry placeholder; INFERRED name logRecords): writes "<indent><name> = <value>\n" for
void CRobloxReportView::logRecords(CXTPReportRecords* records, CString indent)
{
    for (int i = 0; i < records->GetCount(); ++i) {
        CXTPReportRecord* record = records->GetAt(i);
        CStatsItemRecord::CNameItem* name;
        CStatsItemRecord::CValueItem* value;
        for (int j = 0; j < record->GetItemCount(); ++j) {
            CXTPReportRecordItem* item = record->GetItem(j);
            if (dynamic_cast<CStatsItemRecord::CNameItem*>(item))
                name = dynamic_cast<CStatsItemRecord::CNameItem*>(item);
            if (dynamic_cast<CStatsItemRecord::CValueItem*>(item))
                value = dynamic_cast<CStatsItemRecord::CValueItem*>(item);
        }
        if (value->GetCaption(NULL) != "" && name->GetCaption(NULL) != "Render" && name->GetCaption(NULL) != "Sound") {
            CString line = indent + name->GetCaption(NULL) + " = " + value->GetCaption(NULL) + "\n";
            fprintf(benchmarkFile, "%s", (LPCSTR)line);
        }
        if (name->GetCaption(NULL) != "Render" && name->GetCaption(NULL) != "Sound") {
            if (CXTPReportRecords* children = record->GetChilds())
                logRecords(children, indent + name->GetCaption(NULL) + "::");
        }
    }
}

template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
