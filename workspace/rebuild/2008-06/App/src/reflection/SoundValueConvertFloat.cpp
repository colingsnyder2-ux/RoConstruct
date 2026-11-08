#include "reflection/type.h"
namespace RBX { namespace Reflection {
template<> float& Value::convert<float>() {
 if (isType<int>()) { value = (float)boost::any_cast<int>(value); _type = &Type::singleton<float>(); }
 if (isType<double>()) { value = (float)boost::any_cast<double>(value); _type = &Type::singleton<float>(); }
 if (isType<bool>()) { value = (float)(int)(boost::any_cast<bool>(value) != 0); _type = &Type::singleton<float>(); }
 return genericConvert<float>();
}
}}

