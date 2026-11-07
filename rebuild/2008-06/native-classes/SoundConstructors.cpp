// >>> native-status (generated) -- do not edit >>>
// SoundConstructors | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2fdea2ee | roc native-status --write
#include "util/Sound.h"

namespace RBX {

template<class C, class D, const char* N>
FactoryProduct<C, D, N>::FactoryProduct() : D() {}

template<class C, class D, const char* N>
DescribedCreatable<C, D, N>::DescribedCreatable()
    : Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

template DescribedCreatable<Soundscape::SoundService, Instance, Soundscape::sSoundService>::DescribedCreatable();
template DescribedCreatable<Soundscape::SoundChannel, Instance, Soundscape::sSoundChannel>::DescribedCreatable();
template DescribedCreatable<StockSound, Soundscape::SoundChannel, sStockSound>::DescribedCreatable();

}
