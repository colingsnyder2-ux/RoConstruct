// =============================================================================
// GLight.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/GLight.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\G3Dcpp\\GLight.cpp"
/**
  @file GLight.cpp

  @maintainer Morgan McGuire, matrix@graphics3d.com

  @created 2003-11-12
  @edited  2005-01-10
*/

#include "G3D/GLight.h"

namespace G3D
{

GLight::GLight() {
    position        = Vector4(0, 0, 0, 0);
    color           = Color3::white();
    spotDirection   = Vector3(0, 0, -1);
    spotCutoff      = 180;
    enabled         = false;
    attenuation[0]  = 1.0;
    attenuation[1]  = 0.0;
    attenuation[2]  = 0.0;
    specular        = true;
    diffuse         = true;
}

GLight GLight::directional(const Vector3& toLight, const Color3& color, bool s, bool d) {
    GLight L;
    L.position = Vector4(toLight.direction(), 0);
    L.color    = color;
    L.specular = s;
    L.diffuse  = d;
    return L;
}

GLight GLight::point(const Vector3& pos, const Color3& color, double constAtt, double linAtt, double quadAtt, bool s, bool d) {
    GLight L;
    L.position = Vector4(pos, 1);
    L.color    = color;
    L.attenuation[0] = constAtt;
    L.attenuation[1] = linAtt;
    L.attenuation[2] = quadAtt;
    L.specular       = s;
    L.diffuse        = d;
    return L;
}

GLight GLight::spot(const Vector3& pos, const Vector3& pointDirection, double cutOffAngleDegrees, const Color3& color, double constAtt, double linAtt, double quadAtt, bool s, bool d) {
    GLight L;
    L.position = Vector4(pos, 1);
    L.spotDirection = pointDirection;
    L.spotCutoff = cutOffAngleDegrees;
    L.color    = color;
    L.attenuation[0] = constAtt;
    L.attenuation[1] = linAtt;
    L.attenuation[2] = quadAtt;
    L.specular       = s;
    L.diffuse        = d;
    return L;
}

bool GLight::operator==(const GLight& other) const {
    return (position == other.position) &&
        (spotDirection == other.spotDirection) &&
        (spotCutoff == other.spotCutoff) &&
        (attenuation[0] == other.attenuation[0]) &&
        (attenuation[1] == other.attenuation[1]) &&
        (attenuation[2] == other.attenuation[2]) &&
        (color == other.color) &&
        (enabled == other.enabled) &&
        (specular == other.specular) &&
        (diffuse == other.diffuse);
}

bool GLight::operator!=(const GLight& other) const {
    return !(*this == other);
}

}
