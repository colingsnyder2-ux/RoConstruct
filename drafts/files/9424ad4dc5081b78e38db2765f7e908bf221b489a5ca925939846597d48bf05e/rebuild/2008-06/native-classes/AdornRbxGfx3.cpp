// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// RBX::AdornRbxGfx viewport size / 2D text members as compiled into the June 2008 client (inactive native recovery).
// Same original unit as AdornRbxGfx.cpp (image block 0066f900..006743eb). Declarations: RbxGraphics/AdornRbxGfx2008.h.
#include "RbxGraphics/AdornRbxGfx2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbx/VRbxFont2008.h"
#include <OgreViewport.h>

namespace RBX
{
    // 00962da8: the 2D text font, an Ogre::SharedPtr<RbxFont> (vptr 0084d1d4, pRep at 00962dac) assigned from
    // RbxFont::fromFile by the AdornRbxGfx constructor 00674210 (guard `[00962dac] == 0`, call 00670670 on 00962da8).
    extern Ogre::SharedPtr<Ogre::RbxFont> font2d;

    // 0066f900 (slot 5): tail-jumps to Viewport::getActualWidth (rgmain import).
    int AdornRbxGfx::getWidth() const
    {
        return visualEngine->viewport->getActualWidth();
    }

    // 0066f910 (slot 6)
    int AdornRbxGfx::getHeight() const
    {
        return visualEngine->viewport->getActualHeight();
    }

    // 0066fda0 (slot 13): RbxFont::draw2D 00684730 with the y position flipped against the viewport height; the
    // result is written back as (x, y) of the returned Vector2.
    G3D::Vector2 AdornRbxGfx::drawFont2D(const std::string& s, const G3D::Vector2& pos2d, double size,
                                         const G3D::Color4& color, const G3D::Color4& outline, XAlign xalign,
                                         YAlign yalign, Spacing spacing) const
    {
        G3D::Vector2 pos(pos2d.x, (getHeight() - 1) - pos2d.y);
        G3D::Vector2 bounds = font2d->draw2D(visualEngine, s, pos, size, color, outline,
                                             (Ogre::RbxFont::XAlign)xalign, (Ogre::RbxFont::YAlign)yalign,
                                             (Ogre::RbxFont::Spacing)spacing);
        return G3D::Vector2(bounds.x, bounds.y);
    }
}

#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreParticleSystem.h>

namespace RBX
{
    // 00673a90 (slot 0). NEAR MISS: 1613 B like the target, identical instruction stream; only the stack spill slot
    // numbering (esp+0x10/0x14/0x1c vs the target's 0x14/0x10) and frame size (0x14 vs 0x18) differ. The
    // explosion / sparkle nodes hold ParticleSystems (getAttachedObject(0) at -0x20, destroyParticleSystem slot
    // 0x134, removeAndDestroyChild slot 0x170). Tried: single-expression sm loads, sm locals per call, sm
    // local per if-block; none reproduced the extra temp.
    AdornRbxGfx::~AdornRbxGfx()
    {
        meshes.clear();
        Ogre::SceneNode* root = visualEngine->sceneManager->getRootSceneNode();
        root->removeAndDestroyChild(rootNode->getName());
        visualEngine->sceneManager->getRootSceneNode()->removeChild(renderNode);
        delete renderNode;
        delete entity;
        for (int i = 0; i < (int)freeSubEntities.size(); ++i)
            delete freeSubEntities[i];
        for (int i = 0; i < (int)usedSubEntities.size(); ++i)
            delete usedSubEntities[i];
        for (int i = 0; i < (int)explosionNodes.size(); ++i)
        {
            Ogre::ParticleSystem* e = static_cast<Ogre::ParticleSystem*>(explosionNodes[i]->getAttachedObject(0));
            Ogre::SceneManager* sm = visualEngine->sceneManager;
            sm->destroyParticleSystem(e->getName());
            sm = visualEngine->sceneManager;
            sm->destroySceneNode(explosionNodes[i]->getName());
        }
        if (explosionRoot)
        {
            Ogre::SceneManager* sm = visualEngine->sceneManager;
            sm->destroySceneNode(explosionRoot->getName());
        }
        for (int i = 0; i < (int)sparkleNodes.size(); ++i)
        {
            Ogre::ParticleSystem* e = static_cast<Ogre::ParticleSystem*>(sparkleNodes[i]->getAttachedObject(0));
            Ogre::SceneManager* sm = visualEngine->sceneManager;
            sm->destroyParticleSystem(e->getName());
            sm = visualEngine->sceneManager;
            sm->destroySceneNode(sparkleNodes[i]->getName());
        }
        if (sparkleRoot)
        {
            Ogre::SceneManager* sm = visualEngine->sceneManager;
            sm->destroySceneNode(sparkleRoot->getName());
        }
        explosionNodes.clear();
        explosions.clear();
        sparkleNodes.clear();
        sparkles.clear();
    }
}

#include <GLG3D/Texture.h>
#include <OgreTextureManager.h>
#include <OgreTexture.h>

namespace RBX
{
    // 00670210 (vtable slot 8, ret 8 = hidden Rect2D + TextureProxyBaseRef by value): resolve (TextureProxyBase slot 6,
    // the visual engine pointer passed as in setTexture 006700e0) with its RCP discarded, then
    // TextureManager::getSingleton().getByName(filename +0x0c) (ResourceManager vtable +0x4c) into a TexturePtr;
    // getHeight (+0x64) is read before getWidth (+0x60) (right-to-left arguments), both size_t (unsigned fild fix-up).
    G3D::Rect2D AdornRbxGfx::getTextureSize(TextureProxyBaseRef _texture) const
    {
        _texture->resolve(reinterpret_cast<G3D::RenderDevice*>(visualEngine));
        Ogre::TexturePtr texture = Ogre::TextureManager::getSingleton().getByName(_texture->filename);
        size_t width = texture->getWidth();
        size_t height = texture->getHeight();
        return G3D::Rect2D(G3D::Vector2(width, height));
    }
}

#ifdef ADORNRBXGFX_HEADER_DECLARES_SET_COLOR_MATERIAL
#include <OgreMaterialManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <stdio.h>

namespace RBX
{
    // 00670400 (thiscall, ret 8; callers cylinderAlongX 006726a0, sphere 00672ba0, quad 00672f50, ray 006735a0).
    // Guarded: RbxGraphics/AdornRbxGfx2008.h does not declare this private helper (header proposal).
    // INFERRED: name and the int parameter's meaning (registry placeholder func_00670400; the openrbx 2007 analog
    // AppDraw/AdornRbxGfx.cpp calls it FUN_0066aae0). Body: _snprintf format 0084d214 (64-byte buffer), MaterialManager
    // getByName (vtable +0x4c) into textureMaterial +0x24, create (vtable +0x10, group 008163c4) when null, then pass 0
    // of technique 0: setAmbient / setDiffuse / setSpecular / setShininess (0x827490) and setLightingEnabled(true).
    void AdornRbxGfx::setColorMaterial(const G3D::Color4& color, int variant)
    {
        char name[64];
        _snprintf(name, sizeof(name), "setColor%.3f%.3f%.3f%.3f%d", color.r, color.g, color.b, color.a, variant);
        textureMaterial = Ogre::MaterialManager::getSingleton().getByName(name);
        if (textureMaterial.isNull())
        {
            textureMaterial = Ogre::MaterialManager::getSingleton().create(name, "adorn3d");
            Ogre::Pass* pass = textureMaterial->getTechnique(0)->getPass(0);
            pass->setAmbient(color.r, color.g, color.b);
            pass->setDiffuse(color.r, color.g, color.b, color.a);
            pass->setSpecular(color.r, color.g, color.b, color.a);
            pass->setShininess(10.0f);
            textureMaterial->setLightingEnabled(true);
        }
    }
}
#endif
