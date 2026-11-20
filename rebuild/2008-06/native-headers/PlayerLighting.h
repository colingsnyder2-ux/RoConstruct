#pragma once
#include <Ogre.h>
#include <GLG3D/LightingParameters.h>

namespace PlayerLighting {
// Contiguous values copied by004dab50 from Lighting+270 to RenderScene+338.
// This is a typed value group, not a declaration of either enclosing class.
struct Settings {
    G3D::Vector3 mainTint,fillTint;
    float brightness;
    G3D::Vector3 ambient,mainDiffuse,mainSpecular,fillDiffuse,fillSpecular,fillScale;
    Settings(); // Defaults proven by native Lighting constructor005e1a40.
};
G3D::LightingRef preset(const G3D::LightingParameters&,const G3D::Color3& top,const G3D::Color3& bottom);
void apply(Ogre::SceneManager&,const G3D::LightingRef&,const Settings&,
           const Ogre::AxisAlignedBox* ownerBounds,bool shadows);
}
