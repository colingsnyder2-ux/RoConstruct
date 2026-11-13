// >>> native-status (generated) -- do not edit >>>
// DecalBases | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 82eb0bb9 | roc native-status --write
#include "v8datamodel/Decal.h"

namespace RBX {
char sDecal[] = "Decal";
template<> const Name& Name::doDeclare<sDecal>() {
    static const Name& name = declare("Decal", -1);
    return name;
}
template<> const Name& Name::doDeclare<sTexture>() {
    static const Name& name = declare("Texture", -1);
    return name;
}
template<class C, class D, const char* N>
FactoryProduct<C, D, N>::FactoryProduct() : D() {}

template<class C, class D, const char* N>
const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

template<> const Name& FactoryProduct<Decal, FaceInstance, sDecal>::getClassName() const {
    return className();
}
template<> const Name& FactoryProduct<Texture, Decal, sTexture>::getClassName() const {
    return className();
}

template<class C, class D, const char* N>
DescribedCreatable<C, D, N>::DescribedCreatable()
    : Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

template DescribedCreatable<Decal, FaceInstance, sDecal>::DescribedCreatable();
template DescribedCreatable<Texture, Decal, sTexture>::DescribedCreatable();
}
