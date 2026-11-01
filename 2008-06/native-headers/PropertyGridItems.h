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
