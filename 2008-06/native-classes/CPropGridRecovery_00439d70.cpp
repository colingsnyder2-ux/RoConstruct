// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
#include "PropertyGridItems2008.h"
#include "script/Script.h"
#include "v8datamodel/DataModel.h"
#include "DataModelLock.cpp"
#include <algorithm>
#include <functional>

// 00439d70: WM_USER+101 handler. This body was previously recovered in
// AppUnit438PropGrid.cpp; it is consolidated here with the property factory.
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
    Refresh();
    return 0;
}

// 00440e30: primary vftable slot 90, reached through the 00438010 thunk.
<<<<<<< HEAD
// Parked near-miss (1313 of 1321 B). Every cast, allocation size (0x144, 0x130 x2, 0x13c x3, 0x138, 0x134,
=======
// Relocation-masked IDENTICAL (1321 B) since 2026-11-19 xi06 with the inline bIsPublic test below. Earlier note (1313 of 1321 B): every cast, allocation size (0x144, 0x130 x2, 0x13c x3, 0x138, 0x134,
>>>>>>> mew/claude/optimistic-shannon-0xccuy
// 0x130 x4), constructor order, the 00975770 Script source compare and the addItem<T> calls line up; the only
// source difference is isPublic(): the original tests the bit inline (test byte ptr [esi + 0x10], bl with ebx = 1
// at 00440e64, ebx then reused as unwind state 1 at 00440f0c), and no out-of-line PropertyDescriptor::isPublic
// exists in the identity registry, while core header reflection/property.h declares it out of line (one extra
// call; ebp is then unused, shifting every frame slot by 4). Blocker: header proposal
// "bool isPublic() const { return bIsPublic; }" in reflection/property.h (core header owner).
void CPropGrid::addProperty(const RBX::Reflection::ClassDescriptor* descriptor,
                            const RBX::Reflection::PropertyDescriptor* property)
{
    if (property->owner != *descriptor)
        return;
    // INFERRED: inline bIsPublic test (bit 0 of the byte at +0x10, 00440e64), the same codegen analog as
    // CMemberTreeView::addProperty 004352a0; core reflection/property.h declares isPublic() out of line (proposal:
    // "bool isPublic() const { return bIsPublic; }"), and no out-of-line isPublic exists in the identity registry.
    if (!(reinterpret_cast<const unsigned char*>(property)[0x10] & 1))
        return;

    if (const RBX::Reflection::TypedPropertyDescriptor<bool>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<bool>*>(property)) {
        addItem(new XBoolItem(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<float>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<float>*>(property)) {
        addItem(new XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<int>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<int>*>(property)) {
        addItem(new XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>*>(property)) {
        addItem(new XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>*>(property)) {
        addItem(new XBrickColorItem(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>*>(property)) {
        addItem(new Vector3Item(typed, this));
        return;
    }
    if (const RBX::Reflection::EnumPropertyDescriptor* typed =
            dynamic_cast<const RBX::Reflection::EnumPropertyDescriptor*>(property)) {
        addItem(new EnumItem(typed, this));
        return;
    }
    if (const RBX::Reflection::RefPropertyDescriptor* typed =
            dynamic_cast<const RBX::Reflection::RefPropertyDescriptor*>(property)) {
        addItem(new RefItem(typed, this));
        return;
    }
    if (property == &RBX::Script::prop_EmbeddedSourceCode) {
        addItem(new ScriptItem(property, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>*>(property)) {
        addItem(new TextureItem(typed, this));
        return;
    }
    if (const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* typed =
            dynamic_cast<const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>*>(property)) {
        addItem(new SoundItem(typed, this));
        return;
    }
    if (property->hasStringValue())
        addItem(new XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>(property, this));
}
