// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// RBX::AdornRbxGfx 2D drawing and render-pass members as compiled into the June 2008 client (inactive native recovery).
// Same original unit as native-classes/AdornRbxGfx.cpp (image block 0066f900..006743eb); kept in a separate file
// because that file is read-only for this batch. Declarations: native-headers/RbxGraphics/AdornRbxGfx2008.h.
// The VisualEngine (+0x4) members used here come from OgreRbx/VisualEngine2008.h: viewport +0x10, twoD +0x14,
// sceneManager +0x4. The 2D primitives go through Ogre::TwoDManager (OgreRbxNode/TwoDManager2008.h).
#include "RbxGraphics/AdornRbxGfx2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbxNode/TwoDManager2008.h"
#include "OgreRbx/RbxEntity2008.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>

namespace RBX
{
    // 0097da58: the uniqueName counter. The same object is the file-local `nameCounter` of AdornRbxGfx.cpp (one
    // original unit); integration merges these bodies into that file and drops this duplicate declaration.
    static int nameCounter;

    // 0066f920 (slot 11): addQuad 00682d60 with a copy of texture2d (+0x8), full texture coordinates (0, 0, 1, 1).
    // y is flipped against the viewport height (slot 6 getHeight 0066f910).
    void AdornRbxGfx::rect2d(const G3D::Rect2D& rect, const G3D::Color4& color) const
    {
        visualEngine->twoD->addQuad(texture2d, color,
                                    rect.x0(), (getHeight() - 1) - rect.y0(),
                                    rect.x1(), (getHeight() - 1) - rect.y1(),
                                    0, 0, 1, 1);
    }

    // 0066f9c0 (slot 10): primitive 00683000 with operation type 2 (OT_LINE_LIST); thick is unused.
    void AdornRbxGfx::outlineRect2d(const G3D::Rect2D& rect, float thick, const G3D::Color4& color) const
    {
        G3D::Rect2D r = rect;
        Ogre::TwoDManager* twoD = visualEngine->twoD;
        twoD->primitive(Ogre::RenderOperation::OT_LINE_LIST,
                        r.x0(), (getHeight() - 1) - r.y0(),
                        r.x1(), (getHeight() - 1) - r.y1(),
                        color);
    }

    // 0066fa50 (slot 9): 006830b0 with the two end points.
    void AdornRbxGfx::line2d(const G3D::Vector2& p0, const G3D::Vector2& p1, const G3D::Color4& color) const
    {
        Ogre::TwoDManager* twoD = visualEngine->twoD;
        twoD->outlineRectangle(p0.x, (getHeight() - 1) - p0.y,
                               p1.x, (getHeight() - 1) - p1.y,
                               color);
    }

    // 00670020 (slot 4): Rect2D::xyxy is out of line at 0045b950.
    G3D::Rect2D AdornRbxGfx::getViewport() const
    {
        Ogre::Viewport* viewport = visualEngine->viewport;
        return G3D::Rect2D::xywh(viewport->getActualLeft(), viewport->getActualTop(),
                                 viewport->getActualWidth(), viewport->getActualHeight());
    }

    // 00671f90 (slot 3)
    void AdornRbxGfx::finishRenderPass()
    {
        rootNode->removeAndDestroyAllChildren();
        visualEngine->sceneManager->destroyAllManualObjects();
        nameCounter = 0;
        entity->func_0067d3d0();
        releaseSubEntities();
    }
}

