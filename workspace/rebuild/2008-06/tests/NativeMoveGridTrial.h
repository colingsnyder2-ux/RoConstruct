#pragma once
#include <G3D/Vector3.h>
namespace RBX {
inline const G3D::Vector3& nativeMoveGrid() { static G3D::Vector3 grid(1.0f, 0.1f, 1.0f); return grid; }
}
