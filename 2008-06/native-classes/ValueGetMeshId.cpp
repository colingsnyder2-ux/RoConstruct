// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Reflection::Value::get<RBX::MeshId>() const 0059f310 (inactive), the MeshId twin of
// Value::get<TextureId> 00597e40 (ValueGetTextureId_00597e40.cpp). Identity: ret 4 with a hidden MeshId result;
// isType<MeshId> (Type +8 type_info against 0094b368), any_cast<MeshId> 0059f1d0 and the std::string copy plus the
// +0x1c word; otherwise a Value copy (any clone, slot 2) and convert<MeshId> 006156c0 (MeshIdValueConvert.cpp).
// Caller 0059f400 (the SpecialShape unit's TypedPropertyDescriptor<MeshId> helpers 0059eec0..0059f400). Flags and
// includes from MeshIdValueConvert.cpp.
#include "reflection/type.h"
#include "util/MeshId.h"
#include "util/MeshIdType.h"
#include <boost/any.hpp>

namespace RBX { namespace Reflection {
// 0059f310 (template body as in ValueGetTextureId_00597e40.cpp)
template<class T> T Value::get() const
{
	if (isType<T>()) return boost::any_cast<const T&>(value);
	Value copy(*this);
	return copy.convert<T>();
}
template MeshId Value::get<MeshId>() const;
}}
