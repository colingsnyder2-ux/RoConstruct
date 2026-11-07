// >>> native-status (generated) -- do not edit >>>
// Explosion | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 14a2e0f7 | roc native-status --write
#include "v8datamodel/Explosion.h"
namespace RBX {
char sExplosion[] = "Explosion";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
Explosion::Explosion():blastRadius(4.0f),blastPressure(500000.0f),age(0.0f) { setName("Explosion"); }
}
