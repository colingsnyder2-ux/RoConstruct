#include "v8datamodel/ClickDetector.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
namespace RBX {
char sClickDetector[] = "ClickDetector";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
// 007f7d90: member offset 0x144, flags 5, storage 0097bfb4.
Reflection::BoundProp<float, 1> ClickDetector::prop_MaxActivationDistance("MaxActivationDistance", "Data", &ClickDetector::maxActivationDistance, Reflection::PropertyDescriptor::STANDARD);
ClickDetector::ClickDetector():field_140(0),maxActivationDistance(32.0f) { setName("ClickDetector"); }
ClickDetector::~ClickDetector() {}
// 006298d0: RTTI targets 0092dd50 PartInstance, 00932a40 ModelInstance.
bool ClickDetector::askSetParent(const Instance* parent) const {
 return dynamic_cast<const PartInstance*>(parent) || dynamic_cast<const ModelInstance*>(parent);
}
// IRenderable vtable 00845a68 slots 0/1.
bool ClickDetector::shouldRender2d() const { return false; }
bool ClickDetector::shouldRender3dAdorn() const { return true; }
}
