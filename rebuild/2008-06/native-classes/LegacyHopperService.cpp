#include "v8datamodel/Hopper.h"
namespace RBX {
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
// 005d10a0 (allocated 0x168 by 0048ec70): vtables 0x83acfc.. carry RTTI .?AVLegacyHopperService@RBX@@; calls
// DescribedCreatable ctor 005d0a80, then setName with literal 0x83a758 == "Hopper" (donor Hopper.cpp:217).
LegacyHopperService::LegacyHopperService() { setName("Hopper"); }
}
