// >>> native-status (generated) -- do not edit >>>
// SoundValueGenericSoundId | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 69795b28 | roc native-status --write
#include "util/Sound.h"
#include "reflection/type.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include <stdexcept>
namespace RBX { namespace Reflection {
template<> Soundscape::SoundId& Value::genericConvert<Soundscape::SoundId>() {
    Soundscape::SoundId* id = boost::any_cast<Soundscape::SoundId>(&value);
    if (id) return *id;
    if (isType<std::string>()) {
        Soundscape::SoundId v;
        if (StringConverter<Soundscape::SoundId>::convertToValue(*boost::any_cast<std::string>(&value),v)) {
            value = v;
            _type = &Type::singleton<Soundscape::SoundId>();
            return *boost::any_cast<Soundscape::SoundId>(&value);
        }
    }
    const Type& dst = Type::singleton<Soundscape::SoundId>(); throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), dst.tag.c_str()));
}

}}
