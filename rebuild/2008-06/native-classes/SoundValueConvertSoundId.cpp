#include "util/Sound.h"
#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<> Soundscape::SoundId& Value::convert<Soundscape::SoundId>() {
 if (isType<std::string>()) { value = Soundscape::SoundId(boost::any_cast<std::string>(value)); _type = &Type::singleton<Soundscape::SoundId>(); }
 return genericConvert<Soundscape::SoundId>();
}
}}
