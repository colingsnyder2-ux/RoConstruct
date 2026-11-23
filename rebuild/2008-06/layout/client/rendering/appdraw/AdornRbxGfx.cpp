// =============================================================================
// AdornRbxGfx.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/AdornRbxGfx.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "RbxGraphics/AdornRbxGfx2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>

namespace RBX
{
    extern int nameCounter;

    void AdornRbxGfx::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
    {
        visualEngine->twoD->addQuad(texture2d, color,
                                    rect.x0(), (getHeight() - 1) - rect.y0(),
                                    rect.x1(), (getHeight() - 1) - rect.y1(),
                                    0, 0, 1, 1);
    }

    static inline void outlineRectangle2d(const AdornRbxGfx* adorn, Ogre::TwoDManager* twoD,
                                          float x0, float y0, float x1, float y1, const G3D::Color4& color)
    {
        twoD->primitive(Ogre::RenderOperation::OT_LINE_LIST,
                        x0, (adorn->getHeight() - 1) - y0,
                        x1, (adorn->getHeight() - 1) - y1,
                        color);
    }

    void AdornRbxGfx::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
    {
        outlineRectangle2d(this, visualEngine->twoD, rect.x0(), rect.y0(), rect.x1(), rect.y1(), color);
    }

    void AdornRbxGfx::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const
    {
        Ogre::TwoDManager* twoD = visualEngine->twoD;
        twoD->outlineRectangle(p0.x, (getHeight() - 1) - p0.y,
                               p1.x, (getHeight() - 1) - p1.y,
                               color);
    }

    G3D::Rect2D AdornRbxGfx::getViewport() const
    {
        Ogre::Viewport* viewport = visualEngine->viewport;
        return G3D::Rect2D::xywh(viewport->getActualLeft(), viewport->getActualTop(),
                                 viewport->getActualWidth(), viewport->getActualHeight());
    }

    void AdornRbxGfx::finishRenderPass()
    {
        rootNode->removeAndDestroyAllChildren();
        visualEngine->sceneManager->destroyAllManualObjects();
        nameCounter = 0;
        entity->func_0067d3d0();
        releaseSubEntities();
    }
}

#include <OgreMatrix3.h>
#include <OgreMatrix4.h>
#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include "util/Utilities.h"
#include "RenderLib/TextureProxy2008.h"

template class std::map<std::string, Ogre::MeshPtr>;
template class std::_Tree<std::_Tmap_traits<std::string, Ogre::MeshPtr, std::less<std::string>,
                                            std::allocator<std::pair<const std::string, Ogre::MeshPtr> >, false> >;
template class std::map<std::string, Ogre::SceneNode*>;
template class std::_Tree<std::_Tmap_traits<std::string, Ogre::SceneNode*, std::less<std::string>,
                                            std::allocator<std::pair<const std::string, Ogre::SceneNode*> >, false> >;
template class std::vector<Ogre::RbxSubEntity*>;
template class std::vector<Ogre::SceneNode*>;

namespace RBX
{
    int nameCounter;   // global 0097da58: external linkage (AdornRbxGfx2d.cpp finishRenderPass is exact only so)

    void AdornRbxGfx::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
    {
        objectToWorld = c;
    }

    void AdornRbxGfx::setColor(const G3D::Color4& color)
    {
    }

    void AdornRbxGfx::lineSegment(const G3D::LineSegment& lineSegment, const G3D::Color4& color, float scale)
    {
    }

    void AdornRbxGfx::axes(const G3D::Color4& xColor, const G3D::Color4& yColor, const G3D::Color4& zColor, float scale)
    {
    }

    // G3D::Matrix3 / Vector3 and Ogre::Matrix3 / Vector3 share their float layout; the original passes the addresses of
    // objectToWorld.rotation (+0x114) and .translation (+0x138) straight to the Ogre calls.
    void AdornRbxGfx::getObjectToWorld(Ogre::Matrix4& transform, const Ogre::Vector3& offset, const Ogre::Vector3& scale,
                                       const Ogre::Quaternion& rotation)
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        q = q * rotation;
        transform.makeTransform(offset + reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation), scale, q);
    }

    void AdornRbxGfx::getObjectToWorld(Ogre::Matrix4& transform)
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        transform.makeTransform(reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation),
                                Ogre::Vector3(1, 1, 1), q);
    }

    std::string AdornRbxGfx::uniqueName()
    {
        int id = nameCounter++;
        return StringConverter<int>::convertToString(id);
    }

    void AdornRbxGfx::releaseSubEntities()
    {
        for (int i = 0; i < (int)usedSubEntities.size(); ++i)
            freeSubEntities.push_back(usedSubEntities[i]);
        usedSubEntities.clear();
    }

    TextureProxyBaseRef AdornRbxGfx::createTextureProxy(const std::string& filename)
    {
        return new RenderNew::TextureProxy(filename);
    }
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::SceneNode *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> > >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >,std::iterator<std::random_access_iterator_tag,Ogre::RbxSubEntity *,int,Ogre::RbxSubEntity * const *,Ogre::RbxSubEntity * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >,std::iterator<std::random_access_iterator_tag,Ogre::SceneNode *,int,Ogre::SceneNode * const *,Ogre::SceneNode * const &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >,std::iterator<std::random_access_iterator_tag,Ogre::RbxSubEntity *,int,Ogre::RbxSubEntity * *,Ogre::RbxSubEntity * &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >,std::iterator<std::random_access_iterator_tag,Ogre::SceneNode *,int,Ogre::SceneNode * *,Ogre::SceneNode * &> >;
template class std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >;
template class std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> >;
template class std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::_Node *>;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MeshPtr,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MeshPtr> >,0> >::iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >::iterator>;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::RbxSubEntity *,std::allocator<Ogre::RbxSubEntity *> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::SceneNode *,std::allocator<Ogre::SceneNode *> > >;

#include "OgreRbx/VRbxFont2008.h"

namespace RBX
{
    extern Ogre::SharedPtr<Ogre::RbxFont> font2d;

    int AdornRbxGfx::getWidth() const
    {
        return visualEngine->viewport->getActualWidth();
    }

    int AdornRbxGfx::getHeight() const
    {
        return visualEngine->viewport->getActualHeight();
    }

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
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include <OgreParticleSystem.h>

namespace RBX
{
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
