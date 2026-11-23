// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// INFERRED: the tail of the disassembly was truncated. The dummy-mesh and loff-material steps follow the 2007 analog. This has not been compiled or diffed.
// INFERRED: the /I flag is added because the class header includes OgreMaterial.h, which fails to compile without it.
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <stdio.h>

extern "C" int __fastcall fn_00674160(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0067c510(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0067c520(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_0067d1f0(void* self, int unusedEdx);   // RbxEntity ctor
extern "C" int fn_00684eb0(int a1, int a2);
extern "C" int fn_0055d0b0(void* out, const char* path);            // LDraw2Lua::resolveMapPath
extern "C" int fn_006a0920(int a1);                                 // operator new

namespace RBX
{
    extern int nativeAdornFontPtr;   // 00962dac
    extern int nameCounter97db28;    // 0097db28

    AdornRbxGfx::AdornRbxGfx(Ogre::VisualEngine* context)
        : texture2d(""), meshes(), explosionRoot(0), explosions(), sparkleRoot(0), sparkles()
    {
        visualEngine = reinterpret_cast<Ogre::VisualEngine*>(context);
        if (nativeAdornFontPtr == 0)
        {
            try
            {
                std::string path;
                std::string font;
                fn_0055d0b0(&path, "Fonts\\comics.fnt");
                fn_00684eb0(reinterpret_cast<int>(&font), reinterpret_cast<int>(&path));
            }
            catch (...)
            {
            }
        }

        char name[8];
        _snprintf(name, 8, "a3dr%d", nameCounter97db28++);
        Ogre::SceneManager* sm = *reinterpret_cast<Ogre::SceneManager**>(reinterpret_cast<char*>(visualEngine) + 4);
        rootNode = sm->createSceneNode(std::string(name));
        sm->getRootSceneNode()->addChild(rootNode);

        Ogre::RbxSceneNode* node = reinterpret_cast<Ogre::RbxSceneNode*>(fn_006a0920(0x248));
        if (node)
        {
            std::string optName = std::string(name) + "opt";
            fn_00674160(node, 0, reinterpret_cast<int>(sm), reinterpret_cast<int>(&optName));
        }
        renderNode = node;
        sm->getRootSceneNode()->addChild(reinterpret_cast<Ogre::SceneNode*>(renderNode));

        Ogre::RbxEntity* e = reinterpret_cast<Ogre::RbxEntity*>(fn_006a0920(0x2bc));
        if (e)
            fn_0067d1f0(e, 0);
        entity = e;
        *(bool*)((char*)entity + 0x278) = false;
        *(bool*)((char*)entity + 0x27a) = false;
        fn_0067c510(entity, 0, reinterpret_cast<int>(reinterpret_cast<char*>(visualEngine) + 0x18));
        reinterpret_cast<Ogre::SceneNode*>(renderNode)->attachObject(reinterpret_cast<Ogre::MovableObject*>(entity));
        fn_0067c520(entity, 0, 0, 0, 0);
    }
}
