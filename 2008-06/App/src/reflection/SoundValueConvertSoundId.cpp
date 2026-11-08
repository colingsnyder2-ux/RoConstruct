// >>> native-status (generated) -- do not edit >>>
// SoundValueConvertSoundId | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 2664c563 | roc native-status --write
#include "util/Sound.h"
#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<> Soundscape::SoundId& Value::convert<Soundscape::SoundId>() {
 if (isType<std::string>()) { value = Soundscape::SoundId(boost::any_cast<std::string>(value)); _type = &Type::singleton<Soundscape::SoundId>(); }
 return genericConvert<Soundscape::SoundId>();
}
}}
