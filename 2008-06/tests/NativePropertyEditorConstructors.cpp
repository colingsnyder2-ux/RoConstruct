#include "PropertyGridItems.h"
#include <G3D/Color3.h>

template XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> >::XItem(const RBX::Reflection::TypedPropertyDescriptor<float>*, CPropGrid*);
template XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> >::XItem(const RBX::Reflection::TypedPropertyDescriptor<int>*, CPropGrid*);
template XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> >::XItem(const RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>*, CPropGrid*);
template XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor>::XItem(const RBX::Reflection::PropertyDescriptor*, CPropGrid*);
XBoolItem* createBoolEditor(const RBX::Reflection::TypedPropertyDescriptor<bool>* property, CPropGrid* grid)
{
    return new XBoolItem(property, grid);
}

typedef XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> > FloatItem;
typedef XItem<int, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<int> > IntItem;
typedef XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> > ColorItem;
typedef XItem<std::string, CXTPPropertyGridItem, RBX::Reflection::PropertyDescriptor> StringItem;
C_ASSERT(sizeof(CXTPPropertyGridItem) == 0x10c);
C_ASSERT(sizeof(CXTPPropertyGridItemBool) == 0x120);
C_ASSERT(sizeof(CXTPPropertyGridItemColor) == 0x118);
C_ASSERT(sizeof(FloatItem) == 0x130);
C_ASSERT(sizeof(IntItem) == 0x130);
C_ASSERT(sizeof(ColorItem) == 0x13c);
C_ASSERT(sizeof(StringItem) == 0x130);
C_ASSERT(sizeof(BoolItemBase) == 0x144);
C_ASSERT(sizeof(XBoolItem) == 0x144);
C_ASSERT(offsetof(FloatItem, classes) == 0x110);
C_ASSERT(offsetof(FloatItem, grid) == 0x128);
C_ASSERT(offsetof(FloatItem, descriptor) == 0x12c);
