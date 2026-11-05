// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_36f3876ce376584e.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/type.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include <stdexcept>
namespace RBX { namespace Reflection {
template<class T> T& Value::genericConvert() {
    T* id = boost::any_cast<T>(&value);
    if (id) return *id;
    if (isType<std::string>()) {
        T v;
        if (StringConverter<T>::convertToValue(*boost::any_cast<std::string>(&value),v)) {
            value = v;
            _type = &Type::singleton<T>();
            return *boost::any_cast<T>(&value);
        }
    }
    throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), Type::singleton<T>().tag.c_str()));
}
template int& Value::genericConvert<int>();
template bool& Value::genericConvert<bool>();
template float& Value::genericConvert<float>();
template double& Value::genericConvert<double>();
template G3D::Vector3& Value::genericConvert<G3D::Vector3>();
template G3D::Color3& Value::genericConvert<G3D::Color3>();
template G3D::CoordinateFrame& Value::genericConvert<G3D::CoordinateFrame>();
template RBX::BrickColor& Value::genericConvert<RBX::BrickColor>();
}}
