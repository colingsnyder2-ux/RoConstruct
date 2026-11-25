// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 005863e0: RBX::Reflection::Value::get<RBX::ContentId>() const (registry placeholder func_005863e0).
// Identity: thiscall ret 4 with a hidden ContentId result (std::string copy + the +0x1c word); type_info compare
// against 0092bf44 (??_R0?AVContentId@RBX@@@8), any_cast<ContentId> 00586140 on the held any (+4); otherwise a Value
// copy (any clone, slot 2) and convert<ContentId> 0056eff0 (AppUnit564_2008ValueConvert.cpp). Same template body as
// ValueGetTextureId_00597e40.cpp / ValueGetMeshId.cpp.
#include "reflection/type.h"
#include "util/ContentProvider.h"
#include <boost/any.hpp>

namespace RBX { namespace Reflection {
// 005863e0
template<class T> T Value::get() const
{
	if (isType<T>()) return boost::any_cast<const T&>(value);
	Value copy(*this);
	return copy.convert<T>();
}
template ContentId Value::get<ContentId>() const;
}}
