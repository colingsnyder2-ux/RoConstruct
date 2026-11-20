// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
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
// PARKED (batch 29, measured with the MarshaledListener.h fix in a scratch copy): rejected the whole body inside
// `if (dataModel != this->dataModel)` and the /Oi /Ot flag set (both still 669 B, same first divergence 0045872f).
// The duplicate definition formerly in CRobloxReportViewDataModel.cpp was removed (same body, same result).
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

// Original 00456250 (183 B, registry placeholder; vtable of the ChildRemoved listener base, slot 2). Byte-identical
// (relocs masked) once util/MarshaledListener.h compiles (measured against a scratch copy without its stray '}').
// The record's item (+0xa8) is private to CStatsItemRecord, hence the raw read; an inline const accessor
// `getItem()` in CStatsItemRecord (proposal for the CRobloxReportView.h owner) keeps this byte-identical too.
// (The ChildAdded handler 004582f0 is in CRobloxReportViewChildAdded.cpp.)
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

#ifdef NATIVE_CROBLOXREPORTVIEW_LOGRECORDS_PENDING
// PENDING: updateStats calls the record dump 00456820, a CRobloxReportView member (thiscall, ret 8) that the
// read-only native-headers/CRobloxReportView.h does not declare. Proposal for its owner, inside CRobloxReportView:
//     void logRecords(CXTPReportRecords* records, CString indent); // 00456820, INFERRED name
// Both bodies below were measured against a scratch header copy with that declaration and the
// util/MarshaledListener.h stray-brace fix: updateStats byte-identical (relocs masked); logRecords 1038 = 1038 B,
// identical except the self-recursive call, which the comparison shows as the target's direct call against this
// object's relocation. The mfc-noinline-pcxstr include (CString conversions through mfc90 #910, as in the target)
// keeps every other body of this unit identical.

// File-local helpers of the original unit, defined in other native units for now: the timestamp formatter 00456120
// (CRobloxReportViewTime.cpp) and the wall-clock seconds 00455d70 (WF_range_00455d70_00455d70_00455d70.cpp).
CString f(bool includeDate);
double sub_00455d70();

// INFERRED: the benchmark log statics of this unit. Only 00456c30 / 00456820 reference them: 0096dbb1 is a bss bool
// that no code writes (the log is compiled in but off), 00932028 a .data double initialised to -1.0 (first sample
// time), 00931800 a .data float 60.0 (seconds between samples, compared as `* 1.01`), 0096dd84 the FILE*.
static bool benchmarkEnabled = false;      // 0096dbb1
static double benchmarkStart = -1.0;       // 00932028
static float benchmarkInterval = 60.0f;    // 00931800
static FILE* benchmarkFile = NULL;         // 0096dd84

// Original 00456c30 (559 B, registry name updateStats): under the DataModel lock repopulates and redraws the report;
// when the (disabled) benchmark log is on, the first call records the start time and every later call past
// 1.01 * interval opens "c:\roblox_bench_<time>.txt" once (std::exception on failure) and appends the wall time and
// the record tree. The exception message stays a CString temporary converted in the throw expression (EH state 6
// covers it; a named const char* local was rejected: extra frame slot and early destruction).
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
// every record whose value caption is not empty, skipping the "Render" and "Sound" subtrees, and recurses into child
// records with the indent extended by "<name>::". The name / value items are found by dynamic_cast over the
// record's items (TypeDescriptors 00932114 CNameItem, 00932168 CValueItem; the last match wins).
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
#endif

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
