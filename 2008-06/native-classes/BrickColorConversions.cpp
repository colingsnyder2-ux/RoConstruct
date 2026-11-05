#include "v8datamodel/BrickColor.h"

G3D::Color3uint8 RBX::BrickColor::color3uint8() const
{
    G3D::Color4uint8 color = color4uint8();
    return G3D::Color3uint8(color.r, color.g, color.b);
}

RBX::BrickColor RBX::BrickColor::closest(G3D::Color3uint8 color)
{
    return closest(G3D::Color4uint8(color, 0));
}
