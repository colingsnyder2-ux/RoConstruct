// Inactive experimental layout; binary-derived offsets, not selected.
#include "v8datamodel/SpecialShape.h"
namespace RBX {
char sSpecialShape[] = "SpecialMesh";
template<class C, class D, const char* N> FactoryProduct<C,D,N>::FactoryProduct() : D() {}
template<class C, class D, const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C, class D, const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C, class D, const char* N> DescribedCreatable<C,D,N>::DescribedCreatable() : Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
SpecialShape::SpecialShape() : meshType(0), scale(1,1,1), vertColor(1,1,1) { setName("Mesh"); }
}
