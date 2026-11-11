#pragma once
// >>> native-status (generated) -- do not edit >>>
// PropertyGridItems2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d6ef5665 | roc native-status --write
// Inactive recovery of the remaining Studio property-grid editor rows (2008-06).
// Extends PropertyGridItems.h (XItem<T, GridItem, Descriptor>) without changing it.
// Every layout below comes from the original editor factory 00440e30 (operator new sizes),
// the constructors (vptr and field stores) and the RTTI hierarchies of the primary vtables.
#include "PropertyGridItems.h"
#include "CPropertyGridItemBrickColor.h"
#include "v8datamodel/BrickColor.h"
#include "util/TextureId.h"
#include "util/Sound.h"
#include <G3D/Vector3.h>

// RTTI 0081480c: XBrickColorItem : XItem<RBX::BrickColor, CPropertyGridItemBrickColor, ...>, Item at +0x118.
// Factory 00440e30 allocates 0x13c (== the XItem base, no own fields); constructor 0043d560 only
// calls XItem constructor 0043b400 and stores the three vptrs.
typedef XItem<RBX::BrickColor, CPropertyGridItemBrickColor, RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor> >
    BrickColorItemBase;
// CPropertyGridItemBrickColor takes (CString caption, COLORREF): 0043b400 passes the descriptor name and 0,
// so this XItem constructor is an explicit specialization (generic body passes three SDK arguments).
template<>
BrickColorItemBase::XItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* property, CPropGrid* grid);
class XBrickColorItem : public BrickColorItemBase {
public:
    XBrickColorItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>* property, CPropGrid* grid);
    // Primary slot 26 (0043d5b0): only override of the XItem table 00813dc4.
    virtual BOOL OnDrawItemValue(CDC& dc, CRect rcValue);
};

typedef XItem<G3D::Vector3, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3> > Vector3ItemBase;

// RTTI 00814ae4: Vector3ComponentItem : XItem<G3D::Vector3, CXTPPropertyGridItem, ...>, Item at +0x10c.
// Vector3Item::OnAddChildItem 0043dae0 allocates 0x140; constructor 0043d7d0 (ret 0xc) stores the
// component index at +0x130 and zeroes the cached vector at +0x134/+0x138/+0x13c (fldz), then sets
// the caption (+0xac) to "x"/"y"/"z" by index. Slots 57-60 (0043d930/0043d8c0/0043d890/0043da10)
// override the XItem<G3D::Vector3> table 0081409c.
class Vector3ComponentItem : public Vector3ItemBase {
public:
    int component;
    G3D::Vector3 value;

    Vector3ComponentItem(const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* property, CPropGrid* grid, int component);
    virtual G3D::Vector3 readValue();
    virtual void displayValue(const G3D::Vector3& v);
    virtual bool equalValues(const G3D::Vector3& left, const G3D::Vector3& right);
    virtual void writeValue(RBX::Instance*, const G3D::Vector3&);
};

// RTTI 0081497c: Vector3Item : XItem<G3D::Vector3, CXTPPropertyGridItem, ...>, Item at +0x10c.
// Factory allocates 0x13c: XItem base 0x130 + three Vector3ComponentItem pointers +0x130..+0x138
// (constructor 0043d6c0 zeroes them; OnAddChildItem 0043dae0 fills them; update 0043d790 walks them).
class Vector3Item : public Vector3ItemBase {
public:
    Vector3ComponentItem* components[3];

    Vector3Item(const RBX::Reflection::TypedPropertyDescriptor<G3D::Vector3>* property, CPropGrid* grid);
    virtual void update(RBX::SelectionGroup* group);    // Item slot 0: 0043d790
protected:
    virtual BOOL OnAfterEdit(CString& strValue);       // primary slot 37: 0043d710
    virtual void OnAddChildItem();                     // primary slot 51: 0043dae0
};

// RTTI 00814f24: EnumItem : XItem<int, CXTPPropertyGridItemEnum, EnumPropertyDescriptor>, Item at +0x114.
// Factory allocates 0x138 (== the XItem base); constructor 0043e3a0 adds one constraint per enum item.
typedef XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor> EnumItemBase;
class EnumItem : public EnumItemBase {
public:
    EnumItem(const RBX::Reflection::EnumPropertyDescriptor* property, CPropGrid* grid);
};

typedef XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor> StringItemBase;

// RTTI 00814c4c: RefItem : XItem<std::string, CXTPPropertyGridItem, PropertyDescriptor>, Item at +0x10c.
// Factory allocates 0x134 for a dynamic_cast RefPropertyDescriptor; constructor 0043db80 stores that
// descriptor again at +0x130 and makes the row read-only.
class RefItem : public StringItemBase {
public:
    const RBX::Reflection::RefPropertyDescriptor* refDescriptor;

    RefItem(const RBX::Reflection::RefPropertyDescriptor* property, CPropGrid* grid);
    virtual void OnValueChanged(CString value) {}       // primary slot 25: 0043dbf0
    virtual void update(RBX::SelectionGroup* group);   // Item slot 0: 0043dc00
};

// RTTI 00814dbc: ScriptItem : XItem<std::string, CXTPPropertyGridItem, PropertyDescriptor>, Item at +0x10c.
// Factory allocates 0x130 (== the XItem base) for one specific descriptor (00975770); constructor
// 0043df50 adds the expand button, removes the edit box and shows "(Script)".
class ScriptItem : public StringItemBase {
public:
    ScriptItem(const RBX::Reflection::PropertyDescriptor* property, CPropGrid* grid);
    virtual void OnValueChanged(CString value) {}       // primary slot 25: 0043dbf0 (folded with RefItem)
    virtual void update(RBX::SelectionGroup* group);   // Item slot 0: 0043dff0
protected:
    virtual void OnInplaceButtonDown(CXTPPropertyGridInplaceButton* pButton);  // primary slot 52: 0043e140
};

// RTTI 00815214 / 008150ac: ContentItem<T> : XItem<T, CXTPPropertyGridItem, TypedPropertyDescriptor<T> >.
// No own fields (Texture/Sound rows allocate 0x130 == the XItem base). Constructors 0043ea20 / 0043e840
// add a combo button and the constraints "Browse..." (image ID_FILE_OPEN) and "Clear" (data 1,
// image ID_EDIT_CLEAR). Slot 25 (0043e960, shared) dispatches on the chosen constraint; slot 62 is a
// new pure virtual (_purecall in both tables) implemented by TextureItem 00441d60 / SoundItem 00441bc0.
template<class T>
class ContentItem : public XItem<T, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<T> > {
    typedef XItem<T, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<T> > Base;
public:
    ContentItem(const RBX::Reflection::TypedPropertyDescriptor<T>* property, CPropGrid* grid)
        : Base(property, grid)
    {
        this->SetFlags(this->GetFlags() | xtpGridItemHasComboButton);
        this->GetConstraints()->AddConstraint("Browse...", 0, ID_FILE_OPEN);
        this->GetConstraints()->AddConstraint("Clear", 1, ID_EDIT_CLEAR);
    }
    virtual void OnValueChanged(CString value)
    {
        // 0043e960 numbers the T(value) temporary's unwind state before T()'s: default precedes case 1.
        switch (this->GetConstraints()->GetCurrent()) {
        case 0:
            browse();
            break;
        default:
            this->applyValue(T(value));
            break;
        case 1:
            this->applyValue(T());
            break;
        }
    }
    virtual void browse() = 0;
};

// RTTI 00815524: TextureItem : ContentItem<RBX::TextureId>; constructor 00440db0 shows "(Texture)".
class TextureItem : public ContentItem<RBX::TextureId> {
public:
    TextureItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* property, CPropGrid* grid);
    virtual void browse();                              // slot 62: 00441d60
};

// RTTI 008153b4: SoundItem : ContentItem<RBX::Soundscape::SoundId>; constructor 00440d30 shows "(Sound)".
class SoundItem : public ContentItem<RBX::Soundscape::SoundId> {
public:
    SoundItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* property, CPropGrid* grid);
    virtual void browse();                              // slot 62: 00441bc0
};
