// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 00597e40: RBX::Reflection::Value::get<RBX::TextureId>() const
#include "reflection/type.h"
#include "util/TextureId.h"
#include <boost/any.hpp>

namespace RBX { namespace Reflection {
template<class T> T Value::get() const
{
	if (isType<T>()) return boost::any_cast<const T&>(value);
	Value copy(*this);
	return copy.convert<T>();
}
template TextureId Value::get<TextureId>() const;
}}
