#pragma once
#include "CPropGrid.h"
#include "reflection/property.h"

// Native RTTI proves this three-parameter family and both bases. Constructor
// recovery only: editor overrides and their full virtual bindings remain open.
template<class T, class GridItem, class Descriptor>
class XItem : public GridItem, public CPropGrid::Item {
public:
    const Descriptor* descriptor;

    XItem(const Descriptor* property, CPropGrid* grid)
        : GridItem(property->name.c_str(), 0, 0),
          CPropGrid::Item(property, grid), descriptor(property)
    {
        m_bHidden = TRUE;
        SetReadOnly(property->isReadOnly());
    }
    virtual void update(RBX::SelectionGroup*);
    virtual void OnValueChanged(CString value)
    {
        GridItem::OnValueChanged(value);
        // The temporary goes straight to applyValue: 004414e0/00441660 push readValue's returned address.
        applyValue(readValue());
    }
    void applyValue(const T&);
    // INFERRED: name. Non-virtual reader of one selected instance, called only from update
    // (0043a1e0 bool, 0043a730 float, 0043abc0 int, 0043c510 enum, 0043c0d0 Vector3): DataModel lock, then the
    // descriptor's getter on the instance.
    T getValue(RBX::Instance* instance);
    virtual T readValue();
    virtual void displayValue(const T&);
    virtual bool equalValues(const T& left, const T& right) { return left == right; }
    virtual void writeValue(RBX::Instance*, const T&);
    virtual bool emptyValue() { return GetValue().IsEmpty(); }
};

typedef XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> > BoolItemBase;
class XBoolItem : public BoolItemBase {
public:
    XBoolItem(const RBX::Reflection::TypedPropertyDescriptor<bool>* property, CPropGrid* grid); // defined in XBoolItemRecovery_0043d330.cpp
    virtual ~XBoolItem(); // INFERRED: binary evidence shows no custom cleanup required; base class handles destruction
    virtual int OnDrawItemValue(CDC& dc, CRect rect); // INFERRED: vftable slot 26 (+0x68) from vtable 0x81469c; 325 bytes; primary virtual override
};

// Native attachment algorithm; use the real descriptor map and SDK ownership.
template<class Editor>
void CPropGrid::addItem(Editor* item)
{
    CXTPPropertyGridItem* category = getCategory(item->descriptor->category);
    int index = 0;
    for (; index < category->GetChilds()->GetCount(); ++index) {
        CXTPPropertyGridItem* other = category->GetChilds()->GetAt(index);
        if (item->GetCaption().Compare(other->GetCaption()) < 0) break;
    }
    category->InsertChildItem(index, item);
    propertyItems[item->descriptor] = &static_cast<Item&>(*item);
    items.push_back(&static_cast<Item&>(*item));
}
