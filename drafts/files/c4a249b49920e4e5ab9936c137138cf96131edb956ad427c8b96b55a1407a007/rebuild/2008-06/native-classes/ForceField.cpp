#include "v8datamodel/ForceField.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
char sForceField[] = "ForceField";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
ForceField::ForceField():field_140(false),field_144(0) { setName("ForceField"); }
ForceField::~ForceField() {}
bool ForceField::askSetParent(const Instance* instance) const { return dynamic_cast<const Workspace*>(instance) == 0; }
}

