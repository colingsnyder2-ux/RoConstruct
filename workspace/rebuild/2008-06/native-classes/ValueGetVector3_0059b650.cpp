// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0059b650: Value::get<G3D::Color3>() const (registry placeholder func_0059b650). The file name is historical: the
// body was first attributed to get<Vector3>, but 0059b650 compares the held type against typeid 009463a4
// '??_R0?AVColor3@G3D@@@8' and calls any_cast<const Color3&> 0059a880 (typeid 009463a4) and convert<Color3> 0056efd0
// (jmp genericConvert<Color3> 0056dc00). The exact Value::get<Vector3> 0059b730 (typeid 00946364) lives in
// Inferred_0056f0b0.cpp, which holds the generic Value::get<T> template (type.h declares it only).
// Caller: TypedPropertyDescriptor<Color3>::setVariant (call at 0059b8e6; Vector3 twin calls 0059b730 at 0059b916).
#include "util/Utilities.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "reflection/type.h"

namespace RBX {
namespace Reflection {

// 0059b650 ??$get@VColor3@G3D@@@Value@Reflection@RBX@@QBE?AVColor3@G3D@@XZ
// Same shape as the generic get<T> in Inferred_0056f0b0.cpp (which no longer instantiates Color3, so the body is
// defined once): the stored value when the type matches, else convert<Color3>() on a copy.
template<>
G3D::Color3 Value::get<G3D::Color3>() const
{
	if (isType<G3D::Color3>())
		return boost::any_cast<const G3D::Color3&>(value);

	Value copy(*this);
	return copy.convert<G3D::Color3>();
}

}
}

// Reflection-unit instances of boost::any_cast<Vector3> that this file proved before it became the Color3 instance:
// 0056dfe0 any_cast<Vector3>(const any&) by value (called from Value::convert<std::string> at 0056f2d5; that unit
// declares the specialization out of line, so it never emits the body) and 0056c6d0 any_cast<Vector3>(any*)
// (called from genericConvert<Vector3> at 0056d930).
template G3D::Vector3 boost::any_cast<G3D::Vector3>(const boost::any&);
template G3D::Vector3* boost::any_cast<G3D::Vector3>(boost::any*);
