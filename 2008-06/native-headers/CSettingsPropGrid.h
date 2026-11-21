#pragma once
#include "CSelectionPropGrid.h"

// RTTI vtables 0081c174/0081c168/0081c15c: no own CRuntimeClass; every slot equals CSelectionPropGrid's except
// primary slot 90 (+0x168, data word 0081c2dc), the CPropGrid::addProperty 00440e30 slot, which holds the override
// 00467000 (CSettingsPropGridProperties.cpp). Its scalar deleting destructor folds into 004307c0. Constructed
// inline in 00466e10 (CPropGrid ctor 00442b20, shared_ptr at +0x23c/+0x240 zeroed, own vtables),
// destroyed through ~CSelectionPropGrid 00430700: no members beyond CSelectionPropGrid (0x244).
class CSettingsPropGrid : public CSelectionPropGrid {
public:
    virtual void addProperty(const RBX::Reflection::ClassDescriptor*,
                             const RBX::Reflection::PropertyDescriptor*); // 00467000, primary slot 90
};
