#include "v8datamodel/Hopper.h"
namespace RBX {
const char sStarterPackService[] = "StarterPack";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
// 005d0fc0: final vtables 0083b454 etc. have COL type descriptor 00952360
// (.?AVStarterPackService@RBX@@). Creator RTTI 00936248 -> vtable 00821784
// -> slot 0 0048ea80 -> allocator 0048ea00: malloc(0x168), ctor 005d0fc0.
// Calls DescribedCreatable 005d0980; literal 0083a74c is StarterPack.
StarterPackService::StarterPackService() { setName("StarterPack"); }
}
