#include "PropertyGridItems.h"
#include <G3D/Color3.h>
typedef XItem<float, CXTPPropertyGridItem, RBX::Reflection::TypedPropertyDescriptor<float> > FloatEditor;
typedef XItem<G3D::Color3, CXTPPropertyGridItemColor, RBX::Reflection::TypedPropertyDescriptor<G3D::Color3> > ColorEditor;
typedef XItem<int, CXTPPropertyGridItemEnum, RBX::Reflection::EnumPropertyDescriptor> EnumEditor;
template void CPropGrid::addItem(XBoolItem*);
template void CPropGrid::addItem(FloatEditor*);
template void CPropGrid::addItem(ColorEditor*);
template void CPropGrid::addItem(EnumEditor*);

C_ASSERT(sizeof(EnumEditor) == 0x138);
C_ASSERT(offsetof(EnumEditor, descriptor) == 0x134);
