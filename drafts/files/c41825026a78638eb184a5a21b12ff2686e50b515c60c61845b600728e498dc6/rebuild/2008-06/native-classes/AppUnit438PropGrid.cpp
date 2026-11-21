// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
// Inactive 2008-06 recovery of the CPropGrid translation unit rows in 00438000..0043c000
// (one TU, as the original lays them out: CPropGrid members, CPropGrid::Item, SelectionGroup::remove,
// the addItem<Editor> attachments and the XItem<T> constructors).
// Built against the committed native headers, all included read-only: CPropGrid.h, SelectionGroup.h,
// PropertyGridItems.h, v8datamodel/DataModel.h, v8tree/Instance.h, v8tree/PropertyChanged.h.
// Other emitted rows remain useful near matches, not proof.
// Flags: the XItem constructors call std::string::c_str through its import (0043a119), hence std-noinline-string.
#include "PropertyGridItems.h"
#include "CPropertyGridItemBrickColor.h"
#include "v8datamodel/BrickColor.h"
#include "util/TextureId.h"
#include "util/Sound.h"
#include "SelectionGroup.h"
#include "reflection/object.h"
#include "util/Name.h"
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "v8datamodel/DataModel.h"
#include "DataModelLock.cpp"
#include <G3D/Color3.h>
#include <G3D/Vector3.h>
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
// 0043c020 (Vector3), 0043c440 (enum), 0043c9b0 (SoundId), 0043cfa0 (TextureId); BrickColor 0043b400 is the explicit
// specialization in PropertyGridItems2008.cpp.
template XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>*, CPropGrid*);
template XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>::XItem(
    const RBX::Reflection::EnumPropertyDescriptor*, CPropGrid*);
template XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>*, CPropGrid*);
template XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::XItem(
    const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>*, CPropGrid*);

// CPropGrid::addItem<Editor> 00439810 (XBoolItem), 00439940 (Color3), 00439a70 (enum), 00439ba0 (float).
template void CPropGrid::addItem(XBoolItem*);
template void CPropGrid::addItem(XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >*);
template void CPropGrid::addItem(XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>*);
template void CPropGrid::addItem(XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >*);

// XItem<T>::getValue (non-virtual): the selected instance's value under the DataModel lock.
// 0043a1e0 (bool), 0043a730 (float), 0043abc0 (int), 0043c0d0 (Vector3), 0043b510 (Color3; the BrickColor update
// 0043b5b0 calls the same folded body); enum 0043c510 and string 0043b930 are specialized below.
template<class T, class GridItem, class Descriptor>
T XItem<T, GridItem, Descriptor>::getValue(RBX::Instance* instance)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    return descriptor->getValue(instance);
}

// 0043c510: EnumPropertyDescriptor::getEnumValue (descriptor slot 14).
template<>
int XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>::getValue(RBX::Instance* instance)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    return descriptor->getEnumValue(instance);
}

// 0043b930: string rows read through PropertyDescriptor::getStringValue (descriptor slot 7).
template<>
std::string XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::getValue(RBX::Instance* instance)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    return descriptor->getStringValue(instance);
}

// 0043b9d0: string rows write through PropertyDescriptor::setStringValue (descriptor slot 8).
template<>
void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::writeValue(RBX::Instance* instance, const std::string& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setStringValue(instance, value);
}

// XItem<T>::update (CPropGrid::Item slot 0): shows the common value of every selected instance of the
// row's classes, or an empty value when they differ; hides the row when nothing is selected.
// 0043a3b0 (bool), 0043a870 (float), 0043ac60 (int), 0043b0d0 (Color3), 0043b5b0 (BrickColor),
// 0043bc20 (string), 0043c170 (Vector3), 0043c6a0 (enum).
template<class T, class GridItem, class Descriptor>
void XItem<T, GridItem, Descriptor>::update(RBX::SelectionGroup* group)
{
    // value is constructed before found is cleared (0043b5d1: BrickColor 0xc2 store, then found = 0).
    T value;
    bool found = false;
    // The originals read group's end iterator once, before the loop (0043a3c2).
    const RBX::SelectionGroup::iterator groupEnd = group->end();
    // Iterator constness is codegen evidence: const outer / non-const inner is the only combination that
    // reproduces the outer-loop reload order (this, then end) of all eight instantiations (0043a5e1, 0043b319).
    for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(), end = classes.end(); it != end; ++it) {
        // The class key is copied to a local first (0043a43a: mov ecx, [ebx]; find takes its address).
        const RBX::Reflection::ClassDescriptor* descriptor = *it;
        RBX::SelectionGroup::iterator instances = group->find(descriptor);
        if (instances == groupEnd)
            continue;
        for (std::vector<boost::shared_ptr<RBX::Instance> >::iterator i = instances->second.begin(), iend = instances->second.end(); i != iend; ++i) {
            if (!found) {
                value = getValue(i->get());
                displayValue(value);
            } else if (!equalValues(value, getValue(i->get()))) {
                // Non-virtual SDK call in every instantiation (0043a618, 0043b350, 0043bf0f: call 007119f0).
                CXTPPropertyGridItem::SetValue("");
                SetHidden(FALSE);
                return;
            }
            found = true;
        }
    }
    SetHidden(!found);
}

template bool XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::getValue(RBX::Instance*);
template float XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::getValue(RBX::Instance*);
template int XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::getValue(RBX::Instance*);
template G3D::Vector3 XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::getValue(RBX::Instance*);

template void XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::update(RBX::SelectionGroup*);
template void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::update(RBX::SelectionGroup*);
template void XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::update(RBX::SelectionGroup*);
template void XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>::update(RBX::SelectionGroup*);
template void XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >::update(RBX::SelectionGroup*);
template void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::update(RBX::SelectionGroup*);
template void XItem<RBX::BrickColor, CPropertyGridItemBrickColor, RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >::update(RBX::SelectionGroup*);

// XItem<T>::OnValueChanged (primary slot 25, inline in PropertyGridItems.h): 004414e0 (Color3), 00441560 (BrickColor),
// 004415d0 (string), 00441660 (Vector3).
template void XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >::OnValueChanged(CString);
template void XItem<RBX::BrickColor, CPropertyGridItemBrickColor, RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >::OnValueChanged(CString);
template void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::OnValueChanged(CString);
template void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::OnValueChanged(CString);
template void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::update(RBX::SelectionGroup*);
