// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5 roc_observed_53d74a95e1732a0f.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
// Target IAT calls require dynamic CRT declarations during preprocessing.
#define _DLL
#include <Ogre.h>

namespace Ogre {
// The target calls 00681250 with the stock merge arguments out of line.
// This derived declaration retains the real bounds layout and adds no fields.
struct RbxVisibleObjectsBoundsInfo : public VisibleObjectsBoundsInfo {
    void merge(const AxisAlignedBox&, const Sphere&, const Camera*);
};
class RbxSceneNode : public SceneNode {
public:
    void _findVisibleObjects(Camera*, RenderQueue*, VisibleObjectsBoundsInfo*,
                             bool, bool, bool);
};
// Authentic SceneNode body, with the target's omitted camera visibility check.
void RbxSceneNode::_findVisibleObjects(Camera* cam, RenderQueue* queue,
    VisibleObjectsBoundsInfo* visibleBounds, bool includeChildren,
    bool displayNodes, bool onlyShadowCasters) {
    ObjectMap::iterator iobj;
    ObjectMap::iterator iobjend = mObjectsByName.end();
    for (iobj = mObjectsByName.begin(); iobj != iobjend; ++iobj) {
        iobj->second->_notifyCurrentCamera(cam);
        if (iobj->second->isVisible() &&
            (!onlyShadowCasters || iobj->second->getCastShadows())) {
            iobj->second->_updateRenderQueue(queue);
            if (visibleBounds) {
                static_cast<RbxVisibleObjectsBoundsInfo*>(visibleBounds)->merge(
                    iobj->second->getWorldBoundingBox(true),
                    iobj->second->getWorldBoundingSphere(true), cam);
            }
        }
    }
    if (includeChildren) {
        ChildNodeMap::iterator child, childend;
        childend = mChildren.end();
        for (child = mChildren.begin(); child != childend; ++child) {
            SceneNode* sceneChild = static_cast<SceneNode*>(child->second);
            sceneChild->_findVisibleObjects(cam, queue, visibleBounds,
                includeChildren, displayNodes, onlyShadowCasters);
        }
    }
    if (displayNodes) queue->addRenderable(this);
    if (mShowBoundingBox || (mCreator && mCreator->getShowBoundingBoxes()))
        _addBoundingBoxToQueue(queue);
}
}
