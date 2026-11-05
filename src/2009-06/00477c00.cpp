// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_visual_engine_d4ce797c6a771e8f.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderTarget.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreMeshManager.h>
#include <OgreSubMesh.h>
#include <OgreResourceGroupManager.h>
#include <OgreStringConverter.h>
#include <OgreLogManager.h>
#include <map>

// Actual boost/thread/once.hpp signature; the native executable calls it directly.
namespace boost {
typedef long once_flag;
void call_once(void (*func)(), once_flag& flag);
}

namespace Ogre {
void releaseUnusedResources(ResourceManager&, const String&, const StringVector&);
void dumpResources(ResourceManager& manager, const String& type) {
    ResourceManager::ResourceMapIterator it = manager.getResourceIterator();
    int index = 0;
    while (it.hasMoreElements()) {
        ResourcePtr resource = it.getNext();
        LogManager::getSingleton().logMessage(type + StringConverter::toString(index)
            + "(rc=" + StringConverter::toString(resource.useCount()) + ") "
            + resource->getName() + " grp=" + resource->getGroup());
        ++index;
    }
}

extern Root* visualRoot;
extern void* meshNameCache;
extern void* sphereMapCache;
extern boost::once_flag meshNameOnce;
void initializeMeshNames();

// RTTI proves Ogre::VisualEngine with one destructor slot. This is an opaque
// declaration, not a claim that the original object had no data members.
class VisualEngine {
public:
    virtual ~VisualEngine();
};

VisualEngine::~VisualEngine() {
    if (!visualRoot)
        return;
    // Native 0067a162/176/184 loads these three owned pointers.
    if (*reinterpret_cast<SceneManager**>(reinterpret_cast<char*>(this) + 4))
        visualRoot->destroySceneManager(*reinterpret_cast<SceneManager**>(reinterpret_cast<char*>(this) + 4));
    if (*reinterpret_cast<RenderTarget**>(reinterpret_cast<char*>(this) + 0xc))
        visualRoot->detachRenderTarget(*reinterpret_cast<RenderTarget**>(reinterpret_cast<char*>(this) + 0xc));
    if (void* object = *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x14)) {
        // Observed scalar deleting destructor: slot0, thiscall, flag1.
        typedef void (__thiscall *DeleteMethod)(void*, unsigned);
        reinterpret_cast<DeleteMethod>((*reinterpret_cast<void***>(object))[0])(object, 1);
    }

    StringVector textureKeep;
    StringVector materialKeep;
    StringVector meshKeep;
    releaseUnusedResources(MaterialManager::getSingleton(), "Material", materialKeep);
    releaseUnusedResources(TextureManager::getSingleton(), "Texture", textureKeep);
    releaseUnusedResources(MeshManager::getSingleton(), "Mesh", materialKeep);
    dumpResources(MaterialManager::getSingleton(), "matl");
    dumpResources(TextureManager::getSingleton(), "tex");
    dumpResources(MeshManager::getSingleton(), "mesh");

    boost::call_once(&initializeMeshNames, meshNameOnce);
    // 0067c401 inserts a newly constructed SubMesh base pointer as key, then
    // assigns its generated name. Iteration reads the String value at node+10.
    std::map<SubMesh*, String>& names = *static_cast<std::map<SubMesh*, String>*>(meshNameCache);
    LogManager::getSingleton().logMessage("RBX sms c=" + StringConverter::toString(names.size()));
    if (!names.empty()) {
        String remaining;
        for (std::map<SubMesh*, String>::iterator it = names.begin(); it != names.end(); ++it)
            remaining += " " + it->second;
        LogManager::getSingleton().logMessage("RBX sms remaining: " + remaining);
    }

    MeshPtr mesh(MeshManager::getSingleton().getByName("rbxvb"));
    if (!mesh.isNull()) {
        int total = mesh->getNumSubMeshes();
        int count = 0;
        for (int i = 0; i < total; ++i)
            if (mesh->getSubMesh(i)->indexData)
                ++count;
        LogManager::getSingleton().logMessage("RBX sm c=" + StringConverter::toString(count));
    }
    if (sphereMapCache)
        LogManager::getSingleton().logMessage("RBX sm2sph c=" + StringConverter::toString(
            *reinterpret_cast<unsigned*>(static_cast<char*>(sphereMapCache) + 0x1c)));
}
}
