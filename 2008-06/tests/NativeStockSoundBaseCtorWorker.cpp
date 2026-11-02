#include "util/Sound.h"
namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable()
    : Reflection::Described<Class, ClassName, FactoryProduct<Class, DerivedClass, ClassName> >() {}
template DescribedCreatable<StockSound, Soundscape::SoundChannel, sStockSound>::DescribedCreatable();
}
