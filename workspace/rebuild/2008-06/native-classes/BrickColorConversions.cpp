// >>> native-status (generated) -- do not edit >>>
// BrickColorConversions | 2008-06 | draft (no current byte proof)
// 0/5 mapped addresses byte-exact | 5 unproved | no mapped strings | by auto (+2) (mixed 2)
// <<< native-status | src 607a84fa | roc native-status --write
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
