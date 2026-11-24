// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string
// Flags: the originals call CSimpleStringT::operator PCXSTR (mfc90 #910: 0043d97e, 0043d710, 004384b0, 00438580)
// and std::string::c_str (0043e3a0, 00437d30) through their imports, hence the two noinline include paths.
#include "PropertyGridItems2008.h"
#include <stdio.h>
#include "util/Utilities.h"
#include "v8tree/Instance.h"
#include "DataModelLock.cpp"
#include <algorithm>
#include <boost/bind.hpp>

namespace RBX {
// 0058c5c0 (CameraHistory.cpp): commits a ChangeHistoryService waypoint; not declared in a shared header (same local
// declaration as CSelectionTreeCtrl.cpp / AppUnit660_2008GroupDragTool.cpp).
void recordCameraHistory(const char* name, const Instance* context);
}

// 0043b400: CPropertyGridItemBrickColor is built from the descriptor name and colour 0.
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

// 0043d930: the original calls CSimpleStringT::operator PCXSTR through mfc90 ordinal 910 (mfc-noinline-pcxstr flag).
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

// 0043e3a0. Parked near-miss (305 B vs 281 B): with the imported c_str (std-noinline-string flag) and the end
// iterator read once, every load, check and call matches in order; the remaining difference is register
// assignment only: the original spills this ([esp + 0x10], reloaded for m_pConstraints +0xc4 every pass and for
// the return value) and holds _invalid_parameter_noinfo in ebp; this unit keeps this in ebp.
// Batch 39 rejected (all 305 B, same register assignment): postfix it++; the loop in a file-local helper
// (static inline: not inlined, 107 B; __forceinline: 305 B); separate iter/end locals with a while loop.
EnumItem::EnumItem(const RBX::Reflection::EnumPropertyDescriptor* property, CPropGrid* grid)
    : EnumItemBase(property, grid)
{
    // 0043e3a0: the end iterator is read once before the loop ([esp + 0x30] / [esp + 0x14]).
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

// 0043dff0. Parked near-miss (313 of 329 bytes): with the separate end local (accepted; frame 0x24 and every
// stack slot now match) the only difference is the original's leading group != NULL check (cmp [esp + 0x28], 0
// -> _invalid_parameter_noinfo at 0043dff3, the _Tree iterator _Plist validation hoisted out of the loop); this
// unit's group->end() elides it. Rejected: group->end() != found (operand order; no change).
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

// 0043dc00. Parked near-miss (810 of 835 bytes, same frame 0x58 and prologue stores; diverges in register
// assignment: the original keeps this in ebp and the outer begin container in edi). Accepted steps: hoisted
// group end, uninitialized first, separate outer end local. Rejected: a separate inner end local
// (iend = instances->second.end(): frame 0x5c, bl/found moves to a stack byte).
void RefItem::update(RBX::SelectionGroup* group)
{
    bool found = false;
    RBX::Instance* first;   // the original never zeroes it (only the EH flag at 0043dc20); assigned while !found
    // The original reads group's end iterator (+0x18 head, +0 container) once, before the loop (0043dc28).
    const RBX::SelectionGroup::iterator groupEnd = group->end();
    // Separate begin/end iterator locals: the original keeps both on the stack (0043dc4e..0043dc6b).
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

// 0043e140: ScriptItem::OnInplaceButtonDown (primary slot 52). Guarded draft, never compiled yet.
// Remaining blocker: the call target 0044ae00 is a CRobloxApp member (thiscall on AfxGetApp(), ret 8: one
// boost::shared_ptr<RBX::Script> by value; it opens a document through the template at app+0x58 and hands it
// the script via 0044a9c0) whose identity is a placeholder (func_0044ae00) and which CRobloxApp.h does not
// declare. The name openScript below is provisional. Target evidence: grid->groups end read once before the
// loop (0043e15b), groups.find 0043a320, inner shared_ptr<Instance> walk (add ebx, 8 at 0043e321),
// dynamic_cast to the type descriptor 0092e1c8 (RBX::Script, the row exists only for Script's source),
// shared_from 00618a40 and the AfxGetApp module-state read (0043e2fb).
// Measured 2026-11-20 (batch 27) with a scratch-only `struct : CWinApp { void openScript(boost::shared_ptr<RBX::Script>); }`
// stand-in for the CRobloxApp call (not kept): 603 = 603 bytes, same calls / checked-iterator tests / EH states; two
// scheduling swaps remain (the map `this` add before the second find argument push at 0043e210, and the two
// iterator reloads at the outer loop tail). The key copy into a local (`descriptor`, esp+0x10 in the target) is
// confirmed: find(*it) straight from the iterator is 592 bytes (rejected).
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

// XItem<int, CXTPPropertyGridItemEnum, EnumPropertyDescriptor> specializations
// XItem<int,Enum>::update 0043c6a0 is defined in AppUnit438PropGrid.cpp.
// XItem<int,Enum>::applyValue 004402d0 is the generic template below (explicit instantiation at the end of the unit).

// XItem<string, CXTPPropertyGridItem, PropertyDescriptor> specializations
// 00438450 (94 B): GetValue (00437ed0) into a temporary, CSimpleStringT::operator PCXSTR through mfc90 #910, then the
// basic_string(const char*) import straight into the return slot. "return std::string((LPCTSTR)GetValue());" is
// relocation-masked IDENTICAL here (verified 2026-11-19 xi06), but dropping CT2A also drops this unit's only
// references to the ATL/MFC COMDATs AfxCrtErrorCheck 00401680 and Checked::tcsncpy_s 00401810 (exact here at
// baseline). Batch 49: both COMDATs are now exact in CWorkspaceRegistration.cpp and ValueConverter.cpp, so the
// trade is free and the plain body is used.
template<>
std::string XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::readValue()
{
    return std::string((LPCTSTR)GetValue());
}
template<>
void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::displayValue(std::string const& v)
{
    SetValue(v.c_str());
}
// XItem<string>::writeValue 0043b9d0 and update 0043bc20 are defined in AppUnit438PropGrid.cpp.
// XItem<string>::applyValue 0043fc00 is the generic template below (explicit instantiation at the end of the unit).

// XItem<BrickColor, CPropertyGridItemBrickColor, TypedPropertyDescriptor<BrickColor>> specializations
// XItem<BrickColor>::update 0043b5b0 is defined in AppUnit438PropGrid.cpp.
// XItem<BrickColor>::applyValue 0043f890 is the generic template below (explicit instantiation at the end of the unit).

// XItem<Soundscape::SoundId, CXTPPropertyGridItem, TypedPropertyDescriptor<SoundId>> specializations
template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::update(RBX::SelectionGroup*) {}
// XItem<SoundId>::applyValue 0043e4c0 is the generic template below (explicit instantiation at the end of the unit).
template<>
void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::writeValue(RBX::Instance*, RBX::Soundscape::SoundId const&) {}

// XItem<TextureId, CXTPPropertyGridItem, TypedPropertyDescriptor<TextureId>> specializations
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::update(RBX::SelectionGroup*) {}
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::applyValue(RBX::TextureId const&) {}
template<>
void XItem<RBX::TextureId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId> >::writeValue(RBX::Instance*, RBX::TextureId const&) {}

// XItem<Vector3, CXTPPropertyGridItem, TypedPropertyDescriptor<Vector3>> specializations
// XItem<Vector3>::update 0043c170 is defined in AppUnit438PropGrid.cpp.
// XItem<Vector3>::applyValue 0043ff70 is the generic template below (explicit instantiation at the end of the unit).
template<>
void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::writeValue(RBX::Instance*, G3D::Vector3 const&) {}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>;
template class std::_Vector_val<RBX::Reflection::ClassDescriptor const *,std::allocator<RBX::Reflection::ClassDescriptor const *> >;

// XItem<T>::applyValue (non-virtual; called by OnValueChanged with readValue's result): 0043ead0 (bool),
// 0043ee40 (float), 0043f1c0 (int). Collects every selected instance of the row's classes into a local vector
// (push_back 00420110, ~vector 005a2fe0), writes the value to each through the virtual writeValue (vcall thunk, bound
// with shared_ptr::get, std::for_each 0043c940), then under the DataModel lock records a ChangeHistoryService
// waypoint named after the property (0058c5c0) and marks the DataModel dirty (IDataState::setDirty at +0x1f0, slot 0).
// A std::exception is reported with AfxMessageBox(e.what()) (catch funclet 0043ee1d).
// Parked near-miss (2026-11-19 xi06): all three instantiations are the target size (871 / 881 / 875 B) and differ
// only in scheduling: the target loads grid ([this + 0x13c]) before pushing find's two arguments (0043ebb3) and uses
// ecx/edx for the push_back argument (0043ec70); this unit pushes first and uses edx/eax. Accepted: end read before
// begin. Rejected: grid->groups.find(*it) without the key copy (859 B, frame 0x70); inner const_iterator (no change).
// Batch 29 (xi01): rejected find(static_cast<const ClassDescriptor*>(*it)) (the cast temporary is elided: same
// 859 B / frame 0x70 as the no-copy form). Three hypotheses rejected: parked.
// Batch 36: the openrbx Client/win/PropGrid.cpp XItem::FUN_00443670 shape (a `SelectionGroup& groups = grid->groups`
// reference taken after the key copy, then `if (found != groupEnd) { ... }`) makes bool 0043ead0 exact (grid loaded
// before find's arguments). float 0043ee40 / int 0043f1c0 stay near misses (881 / 875 B, same size): only the inner
// loop latch orders `mov eax, [ebp - 0x24]` before the `mov ebx, [_invalid_parameter_noinfo]` reload (target after,
// 0043f00f / 0043f38f); the source is the same template, so that is not a statement-order difference.
template<class T, class GridItem, class Descriptor>
void XItem<T, GridItem, Descriptor>::applyValue(const T& value)
{
    try {
        std::vector<boost::shared_ptr<RBX::Instance> > instances;
        // grid->groups' end iterator is read once, before the loop (0043eb1e).
        const RBX::SelectionGroup::iterator groupEnd = grid->groups.end();
        // The classes end iterator is read before begin (0043eb2a: [this + 0x134] first).
        const std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator end = classes.end();
        for (std::vector<const RBX::Reflection::ClassDescriptor*>::const_iterator it = classes.begin(); it != end; ++it) {
            const RBX::Reflection::ClassDescriptor* descriptor = *it;
            RBX::SelectionGroup& groups = grid->groups;
            RBX::SelectionGroup::iterator found = groups.find(descriptor);
            if (found != groupEnd) {
                for (std::vector<boost::shared_ptr<RBX::Instance> >::iterator i = found->second.begin(), iend = found->second.end(); i != iend; ++i)
                    instances.push_back(*i);
            }
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
// 0043e4c0 (registry placeholder func_0043e4c0, 892 B): the SoundId instantiation, called by SoundItem::browse 00441bc0
// (AppLeftovers.cpp) and the SoundId OnValueChanged; its bind 0043e730 / for_each 0043e771 helpers lie in the
// AppUnit438PropGrid.cpp range.
template void XItem<RBX::Soundscape::SoundId, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> >::applyValue(const RBX::Soundscape::SoundId&);
// 0043ff70 (registry placeholder func_0043ff70, 862 B): the Vector3 instantiation (for_each 0043b390, the same
// 12-byte value shape as Color3 0043f530); called from XItem<Vector3>::OnValueChanged 00441660.
template void XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> >::applyValue(const G3D::Vector3&);
// 004402d0 (registry placeholder func_004402d0, 875 B): the enum instantiation (for_each 0043c940, shared with the
// int row); called from XItem<int,Enum>::OnValueChanged 00441770.
template void XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor>::applyValue(const int&);
// 0043f530 Color3, 0043f890 BrickColor and 0043fc00 std::string instantiations (batch 45 proposal; callers are the
// OnValueChanged bodies 004414e0 / 00441560 / 004415d0 instantiated in AppUnit438PropGrid.cpp).
template void XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >::applyValue(const G3D::Color3&);
template void XItem<RBX::BrickColor, CPropertyGridItemBrickColor, RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >::applyValue(const RBX::BrickColor&);
template void XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::applyValue(const std::string&);
