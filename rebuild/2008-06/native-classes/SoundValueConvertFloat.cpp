// >>> native-status (generated) -- do not edit >>>
// SoundValueConvertFloat | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src ce8c4162 | roc native-status --write
#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<> float& Value::convert<float>() {
 if (isType<int>()) { value = (float)boost::any_cast<int>(value); _type = &Type::singleton<float>(); }
 if (isType<double>()) { value = (float)boost::any_cast<double>(value); _type = &Type::singleton<float>(); }
 if (isType<bool>()) { value = (float)(int)(boost::any_cast<bool>(value) != 0); _type = &Type::singleton<float>(); }
 return genericConvert<float>();
}
}}

