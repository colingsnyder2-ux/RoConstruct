#pragma once
#include <G3D/Color3.h>
namespace RBX {
class Color {
public:
    static const G3D::Color3& red();
    static const G3D::Color3& blue();
    static const G3D::Color3& green();
    static const G3D::Color3& purple();
    static const G3D::Color3& orange();
    static const G3D::Color3& yellow();
    static const G3D::Color3& pink();
    static const G3D::Color3& colorFromIndex8 (int index);
};
}
