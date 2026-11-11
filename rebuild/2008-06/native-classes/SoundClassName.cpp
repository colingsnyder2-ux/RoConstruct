// >>> native-status (generated) -- do not edit >>>
// SoundClassName | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src c390dbf8 | roc native-status --write
#include "util/Sound.h"
namespace RBX {
template<class C,class B,const char* N> const Name& FactoryProduct<C,B,N>::className() { return Name::declare<N>(); }
template<> const Name& FactoryProduct<Soundscape::SoundService,Instance,Soundscape::sSoundService>::getClassName() const { return className(); }
template<> const Name& FactoryProduct<Soundscape::SoundChannel,Instance,Soundscape::sSoundChannel>::getClassName() const { return className(); }
template<> const Name& FactoryProduct<StockSound,Soundscape::SoundChannel,sStockSound>::getClassName() const { return className(); }
}
