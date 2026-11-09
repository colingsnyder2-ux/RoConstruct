// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_value_string_const_boundary_81d88175af0c3fe9.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"
#include "util/Utilities.h"
#include <G3D/Vector3.h>
#include <stdexcept>
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
} }
