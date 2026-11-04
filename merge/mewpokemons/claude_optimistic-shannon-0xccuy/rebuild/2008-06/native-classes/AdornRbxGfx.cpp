// RBX::AdornRbxGfx bodies as compiled into the June 2008 client (inactive native recovery).
// Declarations: native-headers/RbxGraphics/AdornRbxGfx2008.h. Verified by tests/record_native_adorn.py (VS2008 RTM
// 21022, document-swap flags + Ogre 1.4.5 client headers + /fp:fast).
//
// Only bodies that need nothing beyond the AdornRbxGfx layout and the Ogre / std headers are built here. Everything
// that reads the Ogre::VisualEngine (+0x4: scene manager +0x4, 2D manager +0x14, viewport +0x10) or calls the exe-local
// RbxSceneNode / RbxEntity / RbxSubEntity / RbxFont methods waits for those declarations (see the recorder receipt).
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <OgreSceneNode.h>
#include <OgreMatrix3.h>
#include <OgreMatrix4.h>
#include <OgreQuaternion.h>
#include <OgreVector3.h>
#include "util/Utilities.h"
#ifdef NATIVE_ADORNRBXGFX_PENDING
#include "RenderLib/TextureProxy2008.h"
#endif

// The AdornRbxGfx image block (0066fc30..00671d5f) holds the out-of-line members of its four containers. Explicit
// instantiation emits the same COMDATs here: std::map<std::string, Ogre::MeshPtr> (+0x78), std::map<std::string,
// Ogre::SceneNode*> (+0xb8 / +0xf4), std::vector<Ogre::RbxSubEntity*> (+0x48 / +0x60), std::vector<Ogre::SceneNode*>
// (+0xa0 / +0xdc).
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
    // 0097da58: incremented by uniqueName 0066fc00, reset to 0 by finishRenderPass 00671f90.
    static int nameCounter;

    void AdornRbxGfx::setObjectToWorldMatrix(const G3D::CoordinateFrame& c)
    {
        objectToWorld = c;
    }

    // Slots 15 / 22 / 23 are empty: the image folds them onto the shared `ret 4` / `ret 0xc` / `ret 0x10` bodies
    // 0070bdf0 / 006ad2a0 / 004e83a0.
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

#ifdef NATIVE_ADORNRBXGFX_PENDING
    // Needs RenderNew::TextureProxy(const std::string&) (out of line at 0066ffb0), which RenderLib/TextureProxy2008.h
    // does not declare yet (proposal for the texture proxy owner).
    TextureProxyBaseRef AdornRbxGfx::createTextureProxy(const std::string& filename)
    {
        return new RenderNew::TextureProxy(filename);
    }
#endif
}
