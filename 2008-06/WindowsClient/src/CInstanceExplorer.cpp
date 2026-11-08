// >>> native-status (generated) -- do not edit >>>
// CInstanceExplorer | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 9c070ae2 | roc native-status --write
#include "CInstanceExplorer.h"
#include "CSettingsExplorer.h"
#include "v8datamodel/Selection.h"
#include <boost/get_pointer.hpp>
#include "v8datamodel/GlobalSettings.h"

IMPLEMENT_DYNCREATE(CInstanceExplorer, CXTPReportView)

// Entry order from the AFX_MSGMAP_ENTRY table at 0080fa88 (base 006c6890 CXTPReportView::GetThisMessageMap).
BEGIN_MESSAGE_MAP(CInstanceExplorer, CXTPReportView)
    ON_WM_CREATE()
    ON_NOTIFY(XTP_NM_REPORT_SELCHANGED, XTP_ID_REPORT_CONTROL, OnReportSelChanged)
END_MESSAGE_MAP()

namespace {
// Local guard: 00421a50 keeps {&populating, old value} on the stack (EH state 0) and writes the old value back
// on exit. Shared-header note: a util ScopedAssign<T> would own this.
template<class T>
class ScopedAssign {
    T& value;
    T oldValue;
public:
    ScopedAssign(T& target, const T& newValue) : value(target), oldValue(target) { value = newValue; }
    ~ScopedAssign() { value = oldValue; }
};
}

// Original 00421940.
CInstanceExplorer::CInstanceExplorer()
    : populating(false)
{
}

// Original 00421bc0.
CInstanceExplorer::~CInstanceExplorer()
{
    setRoot(NULL);
}

// Original 00420990: one tree column "Name" (300 wide).
int CInstanceExplorer::OnCreate(LPCREATESTRUCT cs)
{
    if (CXTPReportView::OnCreate(cs) == -1)
        return -1;
    CXTPReportControl& control = GetReportCtrl();
    control.GetReportHeader()->AllowColumnSort(TRUE);
    control.GetReportHeader()->AllowColumnRemove(FALSE);
    control.GetReportHeader()->SetAutoColumnSizing(TRUE);
    CXTPReportColumn* name = control.AddColumn(new CXTPReportColumn(0, _T("Name"), 300));
    name->SetTreeColumn(TRUE);
    name->SetEditable(FALSE);
    return 0;
}

// Original 00421a50.
void CInstanceExplorer::setRoot(RBX::Instance* instance)
{
    ScopedAssign<bool> assign(populating, true);
    RBX::Notifier<RBX::Instance, RBX::DescendantAdded>::disconnect(root, static_cast<RBX::Listener<RBX::Instance, RBX::DescendantAdded>*>(this));
    RBX::Notifier<RBX::Instance, RBX::DescendantRemoving>::disconnect(root, static_cast<RBX::Listener<RBX::Instance, RBX::DescendantRemoving>*>(this));
    GetReportCtrl().GetRecords()->RemoveAll();
    root = RBX::shared_from(instance);
    RBX::Notifier<RBX::Instance, RBX::DescendantAdded>::connect(root, static_cast<RBX::Listener<RBX::Instance, RBX::DescendantAdded>*>(this));
    RBX::Notifier<RBX::Instance, RBX::DescendantRemoving>::connect(root, static_cast<RBX::Listener<RBX::Instance, RBX::DescendantRemoving>*>(this));
    GetReportCtrl().Populate();
}

// Original 00420fb0.
void CInstanceExplorer::onMarshaledEvent(const RBX::Instance*, RBX::DescendantAdded event)
{
    GetReportCtrl().AddRecord(new CInstanceRecord(RBX::shared_from(event.instance.get())));
    populate();
}

// Original 00420c20.
void CInstanceExplorer::onMarshaledEvent(const RBX::Instance*, RBX::DescendantRemoving event)
{
    CXTPReportRecords* records = GetReportCtrl().GetRecords();
    for (int i = records->GetCount() - 1; i >= 0; --i) {
        CInstanceRecord* record = static_cast<CInstanceRecord*>(records->GetAt(i));
        if (record->instance.get() == event.instance.get()) {
            records->RemoveAt(i);
            break;
        }
    }
    populate();
}

// Original 00421d00 (exact, with Selection::setSelection<vector<Instance*>::iterator> 00420d20, once the shared
// v8datamodel/Selection.h template reads addToSelection(boost::get_pointer(*first)); its current first->get()
// cannot be instantiated for raw Instance* iterators). The vector holds raw pointers: push_back stores 4 bytes.
void CInstanceExplorer::OnReportSelChanged(NMHDR*, LRESULT*)
{
    RBX::Selection* selection = RBX::ServiceProvider::create<RBX::Selection>(root.get());
    std::vector<RBX::Instance*> instances;
    CXTPReportSelectedRows* rows = GetReportCtrl().GetSelectedRows();
    POSITION position = rows->GetFirstSelectedRowPosition();
    while (position) {
        CInstanceRecord* record = static_cast<CInstanceRecord*>(rows->GetNextSelectedRow(position)->GetRecord());
        instances.push_back(record->instance.get());
    }
    selection->setSelection(instances.begin(), instances.end());
}

// Original 00420db0.
CInstanceRecord::CInstanceRecord(boost::shared_ptr<RBX::Instance> instance)
    : instance(instance)
{
    AddItem(new CNameItem(instance.get()));
    AddItem(new CXTPReportRecordItemText(instance->getClassName().c_str()));
}

// Original 00420ee0.
CInstanceRecord::~CInstanceRecord()
{
}

// Original 00420790.
CString CInstanceRecord::CNameItem::GetCaption(CXTPReportColumn*)
{
    return instance->getName().c_str();
}

IMPLEMENT_DYNCREATE(CSettingsExplorer, CInstanceExplorer)

// Original 00466d40 (both listener slots): only GlobalSettings items are explored.
void CSettingsExplorer::onEvent(const RBX::Instance* source, RBX::DescendantAdded event)
{
    if (dynamic_cast<RBX::GlobalSettings::Item*>(event.instance.get()))
        RBX::MarshaledListener<RBX::Instance, RBX::DescendantAdded>::onEvent(source, event);
}

void CSettingsExplorer::onEvent(const RBX::Instance* source, RBX::DescendantRemoving event)
{
    if (dynamic_cast<RBX::GlobalSettings::Item*>(event.instance.get()))
        RBX::MarshaledListener<RBX::Instance, RBX::DescendantRemoving>::onEvent(source, event);
}
