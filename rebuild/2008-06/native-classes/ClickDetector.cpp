#include "v8datamodel/ClickDetector.h"
namespace RBX {
const char sClickDetector[] = "ClickDetector";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
ClickDetector::ClickDetector():field_140(0),field_144(32.0f) { setName("ClickDetector"); }
ClickDetector::~ClickDetector() {}
// Remaining virtuals intentionally declaration-only pending recovery.
}
