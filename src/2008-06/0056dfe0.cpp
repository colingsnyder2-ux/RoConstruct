// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_unit_926fed2d4d408281.cpp

// Candidate translation unit (score above; library headers required).
namespace boost { template<class E> __declspec(noreturn) void throw_exception(const E&); }
#include <boost/any.hpp>
#include "G3D/Vector3.h"
#include "G3D/Vector2int16.h"
#include "G3D/CoordinateFrame.h"
#include "G3D/Color3.h"
#include "util/ContentProvider.h"
#include "v8datamodel/BrickColor.h"
template bool boost::any_cast<bool>(const boost::any&);
template bool boost::any_cast<bool>(boost::any&);
template int boost::any_cast<int>(const boost::any&);
template int boost::any_cast<int>(boost::any&);
template float boost::any_cast<float>(const boost::any&);
template float boost::any_cast<float>(boost::any&);
template double boost::any_cast<double>(const boost::any&);
template double boost::any_cast<double>(boost::any&);
template std::string boost::any_cast<std::string>(const boost::any&);
template std::string boost::any_cast<std::string>(boost::any&);
template G3D::Vector3 boost::any_cast<G3D::Vector3>(const boost::any&);
template G3D::Vector3 boost::any_cast<G3D::Vector3>(boost::any&);
template G3D::Vector2int16 boost::any_cast<G3D::Vector2int16>(const boost::any&);
template G3D::Vector2int16 boost::any_cast<G3D::Vector2int16>(boost::any&);
template G3D::CoordinateFrame boost::any_cast<G3D::CoordinateFrame>(const boost::any&);
template G3D::CoordinateFrame boost::any_cast<G3D::CoordinateFrame>(boost::any&);
template G3D::Color3 boost::any_cast<G3D::Color3>(const boost::any&);
template G3D::Color3 boost::any_cast<G3D::Color3>(boost::any&);
template RBX::BrickColor boost::any_cast<RBX::BrickColor>(const boost::any&);
template RBX::BrickColor boost::any_cast<RBX::BrickColor>(boost::any&);
template RBX::ContentId boost::any_cast<RBX::ContentId>(const boost::any&);
template RBX::ContentId boost::any_cast<RBX::ContentId>(boost::any&);
