#pragma once
#include <Ogre.h>
#include <G3D/GImage.h>
#include <G3D/Color3uint8.h>
namespace PlayerTextureAtlas {
void shadePixel(const G3D::Color3uint8& base,G3D::Color3uint8& lighting);
void build(const G3D::GImage& strip,G3D::GImage& atlas);
Ogre::TexturePtr load(const std::string& filename);
}
