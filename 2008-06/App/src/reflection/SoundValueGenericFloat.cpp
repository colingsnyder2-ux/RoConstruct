// >>> native-status (generated) -- do not edit >>>
// SoundValueGenericFloat | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 413686a3 | roc native-status --write
#include "reflection/type.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include <stdexcept>
namespace RBX { namespace Reflection {
template<class T> T& Value::genericConvert() {
    T* id = boost::any_cast<T>(&value);
    if (id) return *id;
    if (isType<std::string>()) {
        T v;
        if (StringConverter<T>::convertToValue(*boost::any_cast<std::string>(&value),v)) {
            value = v;
            _type = &Type::singleton<T>();
            return *boost::any_cast<T>(&value);
        }
    }
    throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), Type::singleton<T>().tag.c_str()));
}
template float& Value::genericConvert<float>();
}}
