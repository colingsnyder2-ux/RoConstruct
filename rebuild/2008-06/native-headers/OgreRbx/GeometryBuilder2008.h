#pragma once
#include <OgreVertexIndexData.h>
#include <OgreVector3.h>
#include <G3D/Color4.h>
// INFERRED: analog 00679ae0 names receiver OgreUtil; target consumes position/normal triples and four-float colors.
namespace RBX {
class OgreUtil {
public:
    Ogre::VertexData* createVertexData(const Ogre::Vector3*, unsigned, const Ogre::Vector3*, const G3D::Color4*, const float*);
};
}
