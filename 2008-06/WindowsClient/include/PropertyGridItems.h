#pragma once
// >>> native-status (generated) -- do not edit >>>
// PropertyGridItems | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 55c32e8c | roc native-status --write
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
        T converted = readValue();
        applyValue(converted);
    }
    void applyValue(const T&);
    virtual T readValue();
    virtual void displayValue(const T&);
    virtual bool equalValues(const T& left, const T& right) { return left == right; }
    virtual void writeValue(RBX::Instance*, const T&);
    virtual bool emptyValue() { return GetValue().IsEmpty(); }
};

typedef XItem<bool, CXTPPropertyGridItemBool, RBX::Reflection::TypedPropertyDescriptor<bool> > BoolItemBase;
class XBoolItem : public BoolItemBase {
public:
    XBoolItem(const RBX::Reflection::TypedPropertyDescriptor<bool>* property, CPropGrid* grid)
        : BoolItemBase(property, grid)
    {
        SetCheckBoxStyle(TRUE);
    }
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
