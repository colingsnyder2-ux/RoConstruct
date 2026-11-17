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
