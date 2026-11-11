// >>> native-status (generated) -- do not edit >>>
// Explosion | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | 1 referenced strings (not rechecked) | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 6a9327b9 | roc native-status --write
#include "v8datamodel/Explosion.h"
namespace RBX {
char sExplosion[] = "Explosion";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
Explosion::Explosion():blastRadius(4.0f),blastPressure(500000.0f),age(0.0f) { setName("Explosion"); }
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sExplosion>();
