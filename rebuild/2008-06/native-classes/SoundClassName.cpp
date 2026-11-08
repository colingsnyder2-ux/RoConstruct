#include "util/Sound.h"
namespace RBX {
template<class C,class B,const char* N> const Name& FactoryProduct<C,B,N>::className() { return Name::declare<N>(); }
template<> const Name& FactoryProduct<Soundscape::SoundService,Instance,Soundscape::sSoundService>::getClassName() const { return className(); }
template<> const Name& FactoryProduct<Soundscape::SoundChannel,Instance,Soundscape::sSoundChannel>::getClassName() const { return className(); }
template<> const Name& FactoryProduct<StockSound,Soundscape::SoundChannel,sStockSound>::getClassName() const { return className(); }
}
