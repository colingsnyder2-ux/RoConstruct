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
