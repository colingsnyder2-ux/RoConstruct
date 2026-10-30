#include <vector>
#include <OgreShadowTextureManager.h>
#include <OgreSceneQuery.h>
template class std::vector<Ogre::ShadowTextureConfig>;
template class std::vector<Ogre::RaySceneQueryResultEntry>;

template class std::vector<Ogre::TexturePtr>;
template class Ogre::SharedPtr<Ogre::Texture>;

#include <OgrePlane.h>
template class std::vector<Ogre::Plane>;

#include <map>
#include <OgreConfigOptionMap.h>
#include <OgreGpuProgram.h>
#include <OgreResourceManager.h>
template class std::map<Ogre::String,Ogre::ConfigOption>;
template class std::map<Ogre::String,Ogre::GpuConstantDefinition>;
template class std::map<Ogre::ResourceHandle,Ogre::ResourcePtr>;
template class Ogre::SharedPtr<Ogre::Resource>;

#include <OgreShadowCameraSetup.h>
#include <OgreGpuProgram.h>
template class Ogre::SharedPtr<Ogre::ShadowCameraSetup>;
template class Ogre::SharedPtr<Ogre::GpuProgramParameters>;
