#undef NOMINMAX
#include "CInstanceExplorer.h"
#include "CSettingsExplorer.h"
#include "v8datamodel/Selection.h"
#include <boost/get_pointer.hpp>
#include "v8datamodel/GlobalSettings.h"

IMPLEMENT_DYNCREATE(CInstanceExplorer, CXTPReportView)

BEGIN_MESSAGE_MAP(CInstanceExplorer, CXTPReportView)
    ON_WM_CREATE()
    ON_NOTIFY(XTP_NM_REPORT_SELCHANGED, XTP_ID_REPORT_CONTROL, OnReportSelChanged)
END_MESSAGE_MAP()

namespace {
template<class T>
class ScopedAssign {
    T& value;
    T oldValue;
public:
    ScopedAssign(T& target, const T& newValue) : value(target), oldValue(target) { value = newValue; }
    ~ScopedAssign() { value = oldValue; }
};
}

CInstanceExplorer::CInstanceExplorer()
    : populating(false)
{
}

CInstanceExplorer::~CInstanceExplorer()
{
    setRoot(NULL);
}

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

void CInstanceExplorer::onMarshaledEvent(const RBX::Instance*, RBX::DescendantAdded event)
{
    GetReportCtrl().AddRecord(new CInstanceRecord(RBX::shared_from(event.instance.get())));
    populate();
}

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

CInstanceRecord::CInstanceRecord(boost::shared_ptr<RBX::Instance> instance)
    : instance(instance)
{
    AddItem(new CNameItem(instance.get()));
    AddItem(new CXTPReportRecordItemText(instance->getClassName().c_str()));
}

CInstanceRecord::~CInstanceRecord()
{
}

CString CInstanceRecord::CNameItem::GetCaption(CXTPReportColumn*)
{
    return instance->getName().c_str();
}

IMPLEMENT_DYNCREATE(CSettingsExplorer, CInstanceExplorer)

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

#include <afxwin.h>
#include <afxdlgs.h>
#include <fstream>
#include "InsertDecal.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Decal.h"
#include "util/ContentProvider.h"
#include "util/ImageContent.h"
#include "v8datamodel/Workspace.h"

using namespace RBX;
namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
}

static __declspec(noinline) ContentId registerImageFile(const char* path)
{
    std::ifstream file(path, std::ios::in | std::ios::binary);
    return registerImageContent(file, getMimeType(path));
}

__forceinline const CString& InsertDecal::prepareImage(const CString& path)
{
    if (dataModel) ServiceProvider::create<ContentProvider>(static_cast<const ServiceProvider*>(dataModel));
    return path;
}

void InsertDecal::doIt(IDataState*)
{
    CString filter;
    filter.LoadString(132);
    CFileDialog dialog(TRUE, NULL, NULL, 0, filter, NULL, 0, TRUE);
    if (dialog.DoModal() == IDOK) {
        ContentId content = registerImageFile(prepareImage(dialog.GetPathName()));
        boost::shared_ptr<Decal> instance = createInstance();
        instance->setTexture(content);
        instance->setName(std::string(dialog.GetFileTitle()));
        instance->setParent(getTarget());
        (dataModel ? dataModel->create<Selection>() : 0)->setSelection(instance.get());
        recordCameraHistory(getName().c_str(), workspace.get());
    }
}

#include <stdexcept>
#include <G3D/format.h>
#include "InsertObject.h"
#include "CInsertObjectDialog.h"

Instance* InsertObject::target() const {
    Selection* selected = ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel));
    size_t count = selected->size();
    if (count == 1) return selected->front().get();
    if (count == 0) return dataModel->getWorkspace();
    return NULL;
}
void InsertObject::doIt(IDataState*) {
    if (!target()) throw std::runtime_error("InsertObject: Target Instance is NULL");
    boost::shared_ptr<Instance> parent = shared_from(target());
    CInsertObjectDialog dialog(parent, NULL);
    dialog.className = AfxGetApp()->GetProfileString("InsertObject", "ClassName", NULL).GetBuffer();
    if (dialog.DoModal() == IDOK) {
        const char* (CString::*convert)() const = &CString::operator const char*;
        AfxGetApp()->WriteProfileString("InsertObject", "ClassName", (dialog.className.*convert)());
        boost::shared_ptr<Instance> instance = dialog.selected;
        if (!instance) {
            CString error; error.Format(133, dialog.className);
            std::string message((error.*convert)());
            throw std::runtime_error(message);
        }
        if (parent && !parent->canAddChild(instance.get()))
            throw std::runtime_error(G3D::format("%s cannot be a child of %s", instance->getClassNameStr().c_str(), parent->getName().c_str()));
        instance->setParent(parent.get());
        ServiceProvider::create<Selection>(static_cast<const ServiceProvider*>(dataModel))->setSelection(instance.get());
        recordCameraHistory(getName().c_str(), dataModel);
    }
}
