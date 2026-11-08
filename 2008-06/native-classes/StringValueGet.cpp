// >>> native-status (generated) -- do not edit >>>
// StringValueGet | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 672433de | roc native-status --write
#include "reflection/type.h"
#include <string>

namespace RBX { namespace Reflection {
template<class T> T Value::get() const
{
    if (isType<T>()) return boost::any_cast<const T&>(value);
    Value copy(*this);
    return copy.convert<T>();
}
template std::string Value::get<std::string>() const;
}}
