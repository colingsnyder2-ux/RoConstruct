// >>> native-status (generated) -- do not edit >>>
// SoundValueGet | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 8aea620f | roc native-status --write
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

