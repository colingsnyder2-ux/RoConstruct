// Existing NormalId.cpp template body; explicit instances needed by 004e2c80.
#include "util/NormalId.h"
namespace RBX {
template<NormalId faceId>
G3D::Vector3 uvwToObject(const G3D::Vector3& v) { return uvwToObject(v, faceId); }
template G3D::Vector3 uvwToObject<NORM_X>(const G3D::Vector3&);
template G3D::Vector3 uvwToObject<NORM_Y>(const G3D::Vector3&);
template G3D::Vector3 uvwToObject<NORM_Z>(const G3D::Vector3&);
template G3D::Vector3 uvwToObject<NORM_X_NEG>(const G3D::Vector3&);
template G3D::Vector3 uvwToObject<NORM_Y_NEG>(const G3D::Vector3&);
template G3D::Vector3 uvwToObject<NORM_Z_NEG>(const G3D::Vector3&);
}
