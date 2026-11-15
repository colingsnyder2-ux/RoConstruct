// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Selection.h"
namespace RBX {
template<class C, class D, const char* N>
FactoryProduct<C,D,N>::FactoryProduct() : D() {}
template<class C, class D, const char* N>
DescribedCreatable<C,D,N>::DescribedCreatable() : Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
template<class C, class D, const char* N>
const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C, class D, const char* N>
const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template const Name& FactoryProduct<Selection,Instance,sSelection>::getClassName() const;
template FactoryProduct<Selection,Instance,sSelection>::FactoryProduct();
template DescribedCreatable<Selection,Instance,sSelection>::DescribedCreatable();
}
