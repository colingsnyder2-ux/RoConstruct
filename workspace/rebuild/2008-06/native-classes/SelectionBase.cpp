// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// SelectionBase | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src edc1f301 | roc native-status --write
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
