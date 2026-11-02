#include "CInsertObjectDialog.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/DataModel.h"
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <algorithm>

IMPLEMENT_DYNAMIC(CInsertObjectDialog, CDialog)

BEGIN_MESSAGE_MAP(CInsertObjectDialog, CDialog)
    ON_NOTIFY(NM_DBLCLK, 1000, &CInsertObjectDialog::OnNMDblclk)
END_MESSAGE_MAP()

CInsertObjectDialog::CInsertObjectDialog(boost::shared_ptr<RBX::Instance> parent, CWnd* parentWindow)
    : CDialog(parent ? 107 : 214, parentWindow),
      parent(parent),
      className("")
{
}

CInsertObjectDialog::~CInsertObjectDialog() {}

BOOL CInsertObjectDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    list.SetFocus();
    return FALSE;
}

void CInsertObjectDialog::OnNMDblclk(NMHDR*, LRESULT* result)
{
    OnOK();
    *result = 0;
}

int CALLBACK CInsertObjectDialog::compareItems(LPARAM first, LPARAM second, LPARAM)
{
    return RBX::Name::compare(
        const_cast<RBX::Name&>(reinterpret_cast<RBX::Instance*>(first)->getClassName()),
        const_cast<RBX::Name&>(reinterpret_cast<RBX::Instance*>(second)->getClassName()));
}

void CInsertObjectDialog::DoDataExchange(CDataExchange* exchange)
{
    DDX_Control(exchange, 1000, list);
    if (exchange->m_bSaveAndValidate) {
        POSITION position = list.GetFirstSelectedItemPosition();
        if (position) {
            int item = list.GetNextSelectedItem(position);
            className = list.GetItemText(item, 0);
            selected = RBX::shared_from(reinterpret_cast<RBX::Instance*>(list.GetItemData(item)));
        }
    } else if (list.GetItemCount() == 0) {
        list.SetView(LV_VIEW_LIST);
        list.ModifyStyle(0, LVS_ALIGNLEFT);
        list.SetImageList(&images, LVSIL_SMALL);
        addClasses(RBX::Reflection::ClassDescriptor::rootDescriptor());
        list.SortItems(&CInsertObjectDialog::compareItems, 0);
    }
}

// Draft: 711 of 713 bytes (register allocation only) under the c_str/PCXSTR/compare noinline profile.
void CInsertObjectDialog::addClasses(const RBX::Reflection::ClassDescriptor& descriptor)
{
    if (descriptor.name != RBX::Name::declare<&RBX::sDataModel>()) {
        RBX::Reflection::Metadata::Class* metadata = RBX::Metadata::Reflection::singleton()->lookup(descriptor, false);
        AuthoringSettings& settings = AuthoringSettings::singleton();
        bool show = metadata && (!metadata->unknown_131 || settings.showDepricatedObjects)
            && (!metadata->unknown_132 || settings.showPreliminaryObjects) && metadata->unknown_130;
        if (show) {
            boost::shared_ptr<RBX::Instance> instance;
            try {
                instance = RBX::AbstractFactoryProduct<RBX::Instance>::create(descriptor.name);
            } catch (std::exception&) {
            }
            if (instance) {
                bool allowed;
                if (parent)
                    allowed = instance->canSetParent(parent.get());
                else
                    allowed = dynamic_cast<RBX::Service*>(instance.get()) != NULL;
                if (allowed) {
                    instances.push_back(instance);
                    int item = list.InsertItem(0, descriptor.name.c_str(), metadata->getImageIndex());
                    list.SetItem(item, 0, LVIF_PARAM, NULL, 0, 0, 0, reinterpret_cast<LPARAM>(instance.get()));
                    if (descriptor.name.name.compare(className) == 0)
                        list.SetItemState(item, LVIS_SELECTED, LVIS_SELECTED);
                }
            }
        }
    }
    std::for_each(descriptor.derivedClasses_begin(), descriptor.derivedClasses_end(),
                  boost::lambda::bind(&CInsertObjectDialog::addClasses, this, *boost::lambda::_1));
}
