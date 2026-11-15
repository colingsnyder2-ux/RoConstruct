#include "util/Sound.h"
#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<class T> T Value::get() const {
    if (isType<T>()) return boost::any_cast<const T&>(value);
    Value copy(*this);
    return copy.convert<T>();
}
template bool Value::get<bool>() const;
template float Value::get<float>() const;
template int Value::get<int>() const;
template Soundscape::SoundId Value::get<Soundscape::SoundId>() const;
}}

