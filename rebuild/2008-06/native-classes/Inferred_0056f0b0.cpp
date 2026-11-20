// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include
// 0056f0b0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "util/Utilities.h"
#include "G3D/Vector3.h"
#include "reflection/type.h"
#include "util/Name.h"
#include "G3D/Color3.h"
#include "G3D/Vector2int16.h"
#include "v8datamodel/BrickColor.h"

namespace boost { template<> G3D::Vector3 any_cast<G3D::Vector3>(const any&); }

namespace RBX { namespace Reflection {

template<> std::string& Value::convert<std::string>() {
	if (isType<bool>()) {
		value = StringConverter<bool>::convertToString(cast<bool>());
		_type = &Type::singleton<bool>();
	}
	if (isType<int>()) {
		value = StringConverter<int>::convertToString(cast<int>());
		_type = &Type::singleton<int>();
	}
	if (isType<float>()) {
		value = StringConverter<float>::convertToString(cast<float>());
		_type = &Type::singleton<float>();
	}
	if (isType<double>()) {
		value = StringConverter<double>::convertToString(cast<double>());
		_type = &Type::singleton<double>();
	}
	if (isType<G3D::Vector3>()) {
		value = StringConverter<G3D::Vector3>::convertToString(boost::any_cast<G3D::Vector3>(static_cast<const boost::any&>(value)));
		_type = &Type::singleton<G3D::Vector3>();
	}
	std::string* result = boost::any_cast<std::string>(&value);
	if (!result) throw std::runtime_error("Unable to cast value to std::string");
	return *result;
}

// Value::get<T>() const (type.h declares it only): the stored value when the type matches (out-of-line
// any_cast<const T&>), else convert<T>() on a copy. Instances used by TypedPropertyDescriptor<T>::setVariant:
//   Color3 0059b650 (typeid 009463a4, any_cast 0059a880; see ValueGetVector3_0059b650.cpp), Vector3 0059b730 (typeid 00946364, any_cast 0059a910),
//   double 005641e0 (typeid 0092bee8, any_cast 00563f60, convert<double> 0056ee50; DebugSettings unit caller 0056429a),
//   Vector2int16 00445e50 (typeid 00931034, any_cast 004459f0, caller 00445fd3), BrickColor 0048c5e0 (typeid 00935398,
//   any_cast 0048b690, caller 0048ca83)
template<class T> T Value::get() const
{
	if (isType<T>())
		return boost::any_cast<const T&>(value);
	Value copy(*this);
	return copy.convert<T>();
}
// get<G3D::Color3> 0059b650 is defined once, in ValueGetVector3_0059b650.cpp (explicit specialization).
template G3D::Vector3 Value::get<G3D::Vector3>() const;
template double Value::get<double>() const;
template G3D::Vector2int16 Value::get<G3D::Vector2int16>() const;
template BrickColor Value::get<BrickColor>() const;

} }
