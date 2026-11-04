#include "v8datamodel/ForceField.h"
namespace RBX {
const char sForceField[] = "ForceField";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
ForceField::ForceField():field_140(false),field_144(0) { setName("ForceField"); }
ForceField::~ForceField() {}
}

