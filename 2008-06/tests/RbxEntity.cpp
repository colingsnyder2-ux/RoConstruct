#include "RbxEntity.h"

#include <cstdio>

RbxEntity::RbxEntity() : Ogre::Entity()
{
    // Original 0x0067D1F0: Ogre::Entity base ctor, vtable 0x84E45C, then
    // +0x1D4=1, +0x278=1, +0x27A=1, +0x274=0, +0x29C=float(0x8222F0),
    // +0x2A0=0x378.  The compiler supplies the vtable; the remaining flags
    // are left to the base class defaults in this adaptation.
    std::printf("RbxEntity ctor 0x0067D1F0 ran\n");
}

RbxEntity::~RbxEntity()
{
}

RbxEntity::RbxSubEntity* RbxEntity::addSubEntity(Ogre::SubMesh* subMesh, void* chunk)
{
    // Original 0x0067D9B0: alloc 0x15C, construct RbxSubEntity, optionally
    // copy the SubMesh material name, then push it onto mSubEntityList.
    RbxSubEntity* sub = new RbxSubEntity(this, subMesh, chunk);
    if (subMesh && subMesh->isMatInitialised())
        sub->setMaterialName(subMesh->getMaterialName());
    mSubEntityList.push_back(sub);
    std::printf("RbxEntity::addSubEntity 0x0067D9B0 ran\n");
    return sub;
}

RbxSubEntity::RbxSubEntity(Ogre::Entity* parent, Ogre::SubMesh* subMesh, void* chunkValue)
    : Ogre::SubEntity(parent, subMesh),
      chunk(chunkValue),
      lodBias(1.0f)
{
    // Original 0x00685850 calls Ogre::SubEntity(parent, subMesh) then stores
    // chunk-dependent state.  The chunk is retained for traceability.
    std::printf("RbxSubEntity ctor 0x00685850 ran\n");
}

RbxSubEntity::~RbxSubEntity()
{
}
EOF