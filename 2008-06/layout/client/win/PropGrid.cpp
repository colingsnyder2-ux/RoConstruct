#include "PropertyGridItems2008.h"
#include <stdio.h>
#include "util/Utilities.h"
#include "v8tree/Instance.h"
#include "../../../native-classes/DataModelLock.cpp"
#include <algorithm>
#include <boost/bind.hpp>

namespace RBX {
void recordCameraHistory(const char* name, const Instance* context);
}

template<>
BrickColorItemBase::XItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* property, CPropGrid* grid)
    : CPropertyGridItemBrickColor(property->name.c_str(), 0),
      CPropGrid::Item(property, grid), descriptor(property)
{
    m_bHidden = TRUE;
    SetReadOnly(property->isReadOnly());
}

XBrickColorItem::XBrickColorItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* property, CPropGrid* grid)
    : BrickColorItemBase(property, grid)
{
}

BOOL XBrickColorItem::OnDrawItemValue(CDC& dc, CRect rcValue)
{
    if (GetValue() == "")
        return FALSE;
    return CXTPPropertyGridItemColor::OnDrawItemValue(dc, rcValue);
}

Vector3Item::Vector3Item(const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* property, CPropGrid* grid)
    : Vector3ItemBase(property, grid)
{
    components[0] = components[1] = components[2] = NULL;
}

void Vector3Item::update(RBX::SelectionGroup* group)
{
    Vector3ItemBase::update(group);
    for (int i = 0; i < 3; ++i)
        if (components[i])
            components[i]->update(group);
}

BOOL Vector3Item::OnAfterEdit(CString& strValue)
{
    G3D::Vector3 value(0.0f, 0.0f, 0.0f);
    std::string text(strValue);
    return RBX::StringConverter<G3D::Vector3>::convertToValue(text, value);
}

void Vector3Item::OnAddChildItem()
{
    CXTPPropertyGridItem::OnAddChildItem();
    for (int i = 0; i < 3; ++i) {
        components[i] = new Vector3ComponentItem(descriptor, grid, i);
        AddChildItem(components[i]);
    }
}

Vector3ComponentItem::Vector3ComponentItem(const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* property, CPropGrid* grid, int component)
    : Vector3ItemBase(property, grid), component(component), value(0.0f, 0.0f, 0.0f)
{
    switch (component) {
    case 0: m_strCaption = "x"; break;
    case 1: m_strCaption = "y"; break;
    case 2: m_strCaption = "z"; break;
    }
}

bool Vector3ComponentItem::equalValues(const G3D::Vector3& left, const G3D::Vector3& right)
{
    return left[component] == right[component];
}

void Vector3ComponentItem::displayValue(const G3D::Vector3& v)
{
    value = v;
    char text[32];
    sprintf(text, "%.3g", v[component]);
    SetValue(CString(text));
}

G3D::Vector3 Vector3ComponentItem::readValue()
{
    G3D::Vector3 result = value;
    if (RBX::StringConverter<float>::convertToValue((LPCTSTR)GetValue(), result[component]))
        return result;
    return value;
}

void Vector3ComponentItem::writeValue(RBX::Instance* instance, const G3D::Vector3& v)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    G3D::Vector3 current = descriptor->getValue(instance);
    current[component] = v[component];
    descriptor->setValue(instance, current);
}

EnumItem::EnumItem(const RBX::Reflection::EnumPropertyDescriptor* property, CPropGrid* grid)
    : EnumItemBase(property, grid)
{
    for (std::vector<const RBX::Reflection::EnumDescriptor::Item*>::const_iterator it = property->enumDescriptor.begin(),
         end = property->enumDescriptor.end(); it != end; ++it)
        GetConstraints()->AddConstraint((*it)->name.c_str(), (*it)->value);
}

RefItem::RefItem(const RBX::Reflection::RefPropertyDescriptor* property, CPropGrid* grid)
    : StringItemBase(property, grid), refDescriptor(property)
{
    SetReadOnly(TRUE);
}

ScriptItem::ScriptItem(const RBX::Reflection::PropertyDescriptor* property, CPropGrid* grid)
    : StringItemBase(property, grid)
{
    SetFlags(GetFlags() | xtpGridItemHasExpandButton);
    SetFlags(GetFlags() & ~xtpGridItemHasEdit);
    SetValue("(Script)");
}

TextureItem::TextureItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* property, CPropGrid* grid)
    : ContentItem<RBX::TextureId>(property, grid)
{
    SetValue("(Texture)");
}

SoundItem::SoundItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* property, CPropGrid* grid)
    : ContentItem<RBX::Soundscape::SoundId>(property, grid)
{
    SetValue("(Sound)");
}

// Type-specific XItem operations (explicit specializations; the generic template declares them only).
template<>
RBX::BrickColor BrickColorItemBase::readValue()
{
    COLORREF clr = GetColor();
    const float scale = 1.0f / 255.0f;
    return RBX::BrickColor::closest(G3D::Color3(GetRValue(clr) * scale, GetGValue(clr) * scale, GetBValue(clr) * scale));
}

template<>
void BrickColorItemBase::displayValue(const RBX::BrickColor& value)
{
    G3D::Color4uint8 color = value.color4uint8();
    SetColor(RGB(color.r, color.g, color.b));
}

template<>
void BrickColorItemBase::writeValue(RBX::Instance* instance, const RBX::BrickColor& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setValue(instance, value);
}

template<>
G3D::Vector3 Vector3ItemBase::readValue()
{
    G3D::Vector3 value(0.0f, 0.0f, 0.0f);
    if (RBX::StringConverter<G3D::Vector3>::convertToValue((LPCTSTR)GetValue(), value))
        return value;
    return G3D::Vector3(0.0f, 0.0f, 0.0f);
}

template<>
void Vector3ItemBase::displayValue(const G3D::Vector3& value)
{
    char text[256];
    sprintf(text, "%.3g, %.3g, %.3g", value.x, value.y, value.z);
    SetValue(CString(text));
}

template<>
int EnumItemBase::readValue()
{
    return GetEnum();
}

template<>
void EnumItemBase::displayValue(const int& value)
{
    SetEnum(value);
}

template<>
void EnumItemBase::writeValue(RBX::Instance* instance, const int& value)
{
    RBX::DataModel::Lock lock(grid->dataModel);
    descriptor->setEnumValue(instance, value);
}

template<>
RBX::TextureId XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::readValue()
{
    return RBX::TextureId((LPCTSTR)GetValue());
}

template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::displayValue(const RBX::TextureId& value)
{
    SetValue(CString(value.c_str()));
}

template<>
RBX::Soundscape::SoundId XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::readValue()
{
    return RBX::Soundscape::SoundId((LPCTSTR)GetValue());
}

template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::displayValue(const RBX::Soundscape::SoundId& value)
{
    SetValue(CString(value.c_str()));
}

void ScriptItem::update(RBX::SelectionGroup* group)
{
    for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(), end = classes.end(); it != end; ++it) {
        const RBX::Reflection::ClassDescriptor* descriptor = *it;
        RBX::SelectionGroup::iterator found = group->find(descriptor);
        if (found != group->end() && found->second.size() > 0) {
            SetHidden(FALSE);
            return;
        }
    }
    SetHidden(TRUE);
}

void RefItem::update(RBX::SelectionGroup* group)
{
    bool found = false;
    RBX::Instance* first;   // the original never zeroes it (only the EH flag at 0043dc20); assigned while !found
    const RBX::SelectionGroup::iterator groupEnd = group->end();
    for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(), end = classes.end(); it != end; ++it) {
        const RBX::Reflection::ClassDescriptor* descriptor = *it;
        RBX::SelectionGroup::iterator instances = group->find(descriptor);
        if (instances == groupEnd)
            continue;
        for (std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator i = instances->second.begin(); i != instances->second.end(); ++i) {
            if (!found) {
                first = static_cast<RBX::Instance*>(refDescriptor->getRefValue(i->get()));
                displayValue(first ? first->getName() : std::string(""));
            } else if (first != refDescriptor->getRefValue(i->get())) {
                SetValue("");
                SetHidden(FALSE);
                return;
            }
            found = true;
        }
    }
    SetHidden(!found);
}

#ifdef NATIVE_SCRIPTITEM_OPEN_PENDING
void ScriptItem::OnInplaceButtonDown(CXTPPropertyGridInplaceButton*)
{
    const RBX::SelectionGroup::iterator groupEnd = grid->groups.end();
    for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(), end = classes.end(); it != end; ++it) {
        const RBX::Reflection::ClassDescriptor* descriptor = *it;
        RBX::SelectionGroup::iterator instances = grid->groups.find(descriptor);
        if (instances == groupEnd)
            continue;
        for (std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator i = instances->second.begin(), iend = instances->second.end(); i != iend; ++i)
            if (RBX::Script* script = dynamic_cast<RBX::Script*>(i->get()))
                static_cast<CRobloxApp*>(AfxGetApp())->openScript(RBX::shared_from(script));
    }
}
#endif

template<>
void XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>::applyValue(int const&) {}

template<>
std::string XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::readValue()
{
    return std::string(CT2A(GetValue()));
}
template<>
void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::displayValue(std::string const& v)
{
    SetValue(v.c_str());
}
template<>
void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::applyValue(std::string const&) {}

template<>
void XItem<RBX::BrickColor, CPropertyGridItemBrickColor, RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >::applyValue(RBX::BrickColor const&) {}

// XItem<Soundscape::SoundId, CXTPPropertyGridItem, TypedPropertyDescriptor<SoundId>> specializations
template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::update(RBX::SelectionGroup*) {}
template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::applyValue(RBX::Soundscape::SoundId const&) {}
template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::writeValue(RBX::Instance*, RBX::Soundscape::SoundId const&) {}

// XItem<TextureId, CXTPPropertyGridItem, TypedPropertyDescriptor<TextureId>> specializations
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::update(RBX::SelectionGroup*) {}
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::applyValue(RBX::TextureId const&) {}
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::writeValue(RBX::Instance*, RBX::TextureId const&) {}

template<>
void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::applyValue(G3D::Vector3 const&) {}
template<>
void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::writeValue(RBX::Instance*, G3D::Vector3 const&) {}

template class RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>;
template class std::_Vector_val<RBX::Reflection::ClassDescriptor const *,std::allocator<RBX::Reflection::ClassDescriptor const *> >;

template<class T, class GridItem, class Descriptor>
void XItem<T, GridItem, Descriptor>::applyValue(const T& value)
{
    try {
        std::vector<boost::shared_ptr<RBX::Instance> > instances;
        const RBX::SelectionGroup::iterator groupEnd = grid->groups.end();
        const std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator end = classes.end();
        for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(); it != end; ++it) {
            const RBX::Reflection::ClassDescriptor* descriptor = *it;
            RBX::SelectionGroup::iterator found = grid->groups.find(descriptor);
            if (found == groupEnd)
                continue;
            for (std::vector<boost::shared_ptr<RBX::Instance> >::iterator i = found->second.begin(), iend = found->second.end(); i != iend; ++i)
                instances.push_back(*i);
        }
        std::for_each(instances.begin(), instances.end(),
                      boost::bind(&XItem::writeValue, this, boost::bind(&boost::shared_ptr<RBX::Instance>::get, _1), value));
        if (grid->dataModel) {
            RBX::DataModel::Lock lock(grid->dataModel);
            RBX::recordCameraHistory(descriptor->name.c_str(), grid->dataModel);
            grid->dataModel->setDirty(true);
        }
    } catch (std::exception& e) {
        AfxMessageBox(e.what());
    }
}

template void XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> >::applyValue(const bool&);
template void XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::applyValue(const float&);
template void XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::applyValue(const int&);
