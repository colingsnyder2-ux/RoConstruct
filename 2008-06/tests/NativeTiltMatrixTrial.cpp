#include "util/Math.h"
namespace RBX {
const G3D::Matrix3& Math::matrixTiltZ() { static G3D::Matrix3 value(0,1,0,-1,0,0,0,0,1); return value; }
const G3D::Matrix3& Math::matrixTiltNegativeZ() { static G3D::Matrix3 value(0,-1,0,1,0,0,0,0,1); return value; }
const G3D::Matrix3 Math::matrixTiltQuadrant(int n) {
    switch (n) {
    case 0: return G3D::Matrix3(1,0,0,0,0,-1,0,1,0);
    case 1: return matrixTiltZ();
    case 2: return G3D::Matrix3(1,0,0,0,0,1,0,-1,0);
    case 3: return matrixTiltNegativeZ();
    default: return G3D::Matrix3::identity();
    }
}
}
