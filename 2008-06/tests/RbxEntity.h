#pragma once

#include <Ogre.h>
#include <vector>

class RbxEntity : public Ogre::Entity
{
public:
    RbxEntity();
    virtual ~RbxEntity();

    class RbxSubEntity* addSubEntity(Ogre::SubMesh* subMesh, void* chunk);
};

class RbxSubEntity : public Ogre::SubEntity, public Ogre::ShadowCaster
{
public:
    RbxSubEntity(Ogre::Entity* parent, Ogre::SubMesh* subMesh, void* chunk);
    virtual ~RbxSubEntity();

    void* chunk;
    float lodBias;
};
EOF