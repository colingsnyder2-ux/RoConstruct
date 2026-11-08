#include <G3D/Vector3.h>

typedef G3D::Vector3 (G3D::Vector3::*VectorSubtract)(const G3D::Vector3&) const;
VectorSubtract keepVectorSubtract = &G3D::Vector3::operator-;
