// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Inactive 2008-06 recovery of the CPropGrid translation unit rows in 00438000..0043c000
// (one TU, as the original lays them out: CPropGrid members, CPropGrid::Item, SelectionGroup::remove,
// the addItem<Editor> attachments and the XItem<T> constructors).
// Built against the committed native headers, all included read-only: CPropGrid.h, SelectionGroup.h,
// PropertyGridItems.h, v8datamodel/DataModel.h, v8tree/Instance.h, v8tree/PropertyChanged.h.
// Current intake verifies 15 byte/data-exact rows. Other emitted rows remain useful near matches, not proof.
#include "PropertyGridItems.h"
#include "SelectionGroup.h"
#include "reflection/object.h"
#include "util/Name.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "v8datamodel/DataModel.h"
#include <G3D/Color3.h>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>

BEGIN_MESSAGE_MAP(CPropGrid, CXTPPropertyGrid)
    ON_WM_CREATE()
    ON_MESSAGE(WM_USER + 101, OnUpdate)
END_MESSAGE_MAP()

// 004385f0: WM_CREATE handler (message map 008145dc).
int CPropGrid::OnCreate(LPCREATESTRUCT)
{
    if (Default() == -1) return -1;
    SetTheme((XTPPropertyGridPaintTheme)6);
    XTPImageManager()->InternalAddRef();
    SetImageManager(XTPImageManager());
    return 0;
}

// 00438630
CXTPPropertyGridItem* CPropGrid::getCategory(const RBX::Name& name)
{
    CXTPPropertyGridItem* category = FindItem(name.c_str());
    if (!category) {
        category = AddCategory(name.c_str());
        category->Expand();
    }
    return category;
}

// 004391d0 (and the virtual-call thunk 00438010 for &CPropGrid::addProperty, slot 90)
void CPropGrid::rebuild(const RBX::Reflection::ClassDescriptor* descriptor)
{
    boost::recursive_mutex::scoped_lock lock(RBX::Reflection::sync());
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&CPropGrid::rebuild, this, _1));
    std::for_each(descriptor->RBX::Reflection::PropertyContainer::descriptors_begin(),
                  descriptor->RBX::Reflection::PropertyContainer::descriptors_end(),
                  boost::bind(&CPropGrid::addProperty, this, descriptor, _1));
}

// 00439370
void CPropGrid::onEvent(const RBX::Instance*, RBX::PropertyChanged event)
{
    boost::recursive_mutex::scoped_lock lock(mutex);
    if (!dirty) {
        std::map<const RBX::Reflection::PropertyDescriptor*, Item*>::const_iterator found =
            propertyItems.find(&event.getDescriptor());
        if (found != propertyItems.end()) pendingItems.insert(found->second);
        requestUpdate();
    }
}

// 00439cd0
void CPropGrid::removeInstance(boost::shared_ptr<RBX::Instance> instance)
{
    RBX::Notifier<RBX::Instance, RBX::PropertyChanged>::disconnect(instance, this);
    groups.remove(instance.get());
}

// 00439d70: WM_USER+101 handler.
LRESULT CPropGrid::OnUpdate(WPARAM, LPARAM)
{
    if (items.size() == 0) {
        CXTPPropertyGridUpdateContext context;
        BeginUpdate(context);
        rebuild(&RBX::Reflection::ClassDescriptor::rootDescriptor());
        EndUpdate(context);
    }
    std::vector<Item*> all;
    std::set<Item*> pending;
    {
        boost::recursive_mutex::scoped_lock lock(mutex);
        if (dirty) {
            all = items;
            dirty = false;
        } else {
            pending = pendingItems;
            pendingItems.clear();
        }
        posted = false;
    }
    {
        RBX::DataModel::Lock lock(dataModel);
        std::for_each(all.begin(), all.end(), std::bind2nd(std::mem_fun(&Item::update), &groups));
        std::for_each(pending.begin(), pending.end(), std::bind2nd(std::mem_fun(&Item::update), &groups));
    }
    for (int i = 0; i < GetCategories()->GetCount(); ++i) {
        CXTPPropertyGridItem* category = GetCategories()->GetAt(i);
        CXTPPropertyGridItems* children = category->GetChilds();
        bool hidden = true;
        for (int j = 0; j < children->GetCount(); ++j) {
            if (!children->GetAt(j)->IsHidden()) {
                hidden = false;
                break;
            }
        }
        category->SetHidden(hidden);
    }
    // The original calls 0x6fb910, CXTPPropertyGrid::Refresh (the XTP recipe body is exact there), not
    // RedrawControl: both are 5-byte calls, so a relocation-masked compare cannot tell them apart.
    Refresh();
    return 0;
}

// 0043a070
CPropGrid::Item::Item(const RBX::Reflection::PropertyDescriptor* descriptor, CPropGrid* owner)
    : grid(owner)
{
    addClass(&descriptor->owner);
}

// 00439600
void CPropGrid::Item::addClass(const RBX::Reflection::ClassDescriptor* descriptor)
{
    classes.push_back(descriptor);
    std::for_each(descriptor->derivedClasses_begin(), descriptor->derivedClasses_end(),
                  boost::bind(&Item::addClass, this, _1));
}

namespace RBX {
// 00439660
void SelectionGroup::remove(Instance* instance)
{
    const Reflection::ClassDescriptor* key = &instance->getDescriptor();
    iterator found = find(key);
    if (found != end()) {
        std::vector<boost::shared_ptr<Instance> >::iterator current =
            std::find(found->second.begin(), found->second.end(), shared_from(instance));
        if (current != found->second.end()) found->second.erase(current);
    }
}
}

// XItem<T> constructors 0043a0f0 (bool), 0043a650 (float), 0043ab10 (int), 0043af00 (Color3), 0043b860 (string).
template XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<bool>*, CPropGrid*);
template XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<float>*, CPropGrid*);
template XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<int>*, CPropGrid*);
template XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>*, CPropGrid*);
template XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::XItem(
    const RBX::Reflection::PropertyDescriptor*, CPropGrid*);

// CPropGrid::addItem<Editor> 00439810 (XBoolItem), 00439940 (Color3), 00439a70 (enum), 00439ba0 (float).
template void CPropGrid::addItem(XBoolItem*);
template void CPropGrid::addItem(XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >*);
template void CPropGrid::addItem(XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>*);
template void CPropGrid::addItem(XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >*);
