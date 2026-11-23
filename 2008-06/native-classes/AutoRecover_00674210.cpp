// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Best effort: the disassembly given was truncated after the 'rbxdummymesh' push (0067459x), so the tail
// (mesh lookup, setMesh, "loff%d" material) is INFERRED from the 2007 donor and the rbxgs snapshot.
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreMeshManager.h>
#include <OgreMaterialManager.h>
#include <stdio.h>

extern "C" int fn_006a0920(int a1);
extern "C" int fn_00684eb0(int a1, int a2);
extern "C" int __fastcall fn_00674160(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0067c510(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0067c520(void* self, int unusedEdx, int a1, int a2, int a3);

namespace RBX
{
    extern int nameCounter;
    // 00962da8 / 0097db28: font SharedPtr and per-process a3dr counter.
    extern Ogre::SharedPtr<Ogre::HardwareVertexBuffer> nativeAdornFont;   // INFERRED: 0x962da8 type per disassembly
    extern int nativeAdornCount;                                          // 0x97db28

    AdornRbxGfx::AdornRbxGfx(Ogre::VisualEngine* context)
        : texture2d(""), meshes(), explosionRoot(0), explosions(), sparkleRoot(0), sparkles()
    {
        visualEngine = context;
        if (nativeAdornFont.isNull())
        {
            try
            {
                nativeAdornFont = Ogre::loadRbxFont(LDraw2Lua::resolveMapPath("Fonts\\comics.fnt"));
            }
            catch (...)
            {
            }
        }

        char name[8];
        _snprintf(name, 8, "a3dr%d", nativeAdornCount++);
        rootNode = visualEngine->getSceneManager()->createSceneNode(name);
        visualEngine->getSceneManager()->getRootSceneNode()->addChild(rootNode);

        renderNode = new Ogre::RbxSceneNode(context->getSceneManager(), std::string(name) + "opt");
        visualEngine->getSceneManager()->getRootSceneNode()->addChild(renderNode);

        entity = new Ogre::RbxEntity();
        *(bool*)((char*)entity + 0x278) = false;
        *(bool*)((char*)entity + 0x27a) = false;
        fn_0067c510(entity, 0, (int)((char*)visualEngine + 0x18));
        renderNode->attachObject(entity);

        // INFERRED: tail from the donor.
        Ogre::MeshPtr mesh = Ogre::MeshManager::getSingleton().getByName("rbxdummymesh");
        if (mesh.isNull())
            mesh = Ogre::MeshManager::getSingleton().createOrRetrieve("rbxdummymesh", "General").first;
        entity->setMesh(mesh);

        _snprintf(name, 8, "loff%d", nativeAdornCount - 1);
        solidMaterial = Ogre::MaterialManager::getSingleton().create(name, "General");
        solidMaterial->setLightingEnabled(false);
    }
}
