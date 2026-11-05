// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5 roc_shadow_query_mix_4e65ef0ea0a4a2ee.cpp

// Candidate translation unit (score above; library headers required).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
#undef OGRE_NONCLIENT_BUILD
#include <OgreMovableObject.h>
#include <OgreSceneNode.h>
#include <OgreCamera.h>
#include <OgreLight.h>
#define OGRE_NONCLIENT_BUILD
#include <OgreSceneManager.h>
using namespace Ogre;
bool SceneManager::ShadowCasterSceneQueryListener::queryResult(MovableObject* object)
{
    if (object->getCastShadows() && object->isVisible() &&
        mSceneMgr->isRenderQueueToBeProcessed(object->getRenderQueueGroup()) &&
        ((mSceneMgr->getShadowTechnique() & SHADOWDETAILTYPE_TEXTURE) ||
         (mSceneMgr->getShadowTechnique() & SHADOWDETAILTYPE_STENCIL) && object->hasEdgeList()))
    {
        if (mFarDistSquared)
        {
            Vector3 toObj = object->getParentNode()->_getDerivedPosition() - mCamera->getDerivedPosition();
            Real radius = object->getWorldBoundingSphere().getRadius();
            Real dist = toObj.squaredLength();
            if (dist - (radius * radius) > mFarDistSquared)
                return true;
        }
        if (mCamera->isVisible(object->getWorldBoundingBox()))
        {
            mCasterList->push_back(object);
            return true;
        }
        if (!mIsLightInFrustum || mLight->getType() == Light::LT_DIRECTIONAL)
        {
            PlaneBoundedVolumeList::const_iterator i, iend;
            iend = mLightClipVolumeList->end();
            for (i = mLightClipVolumeList->begin(); i != iend; ++i)
                if (i->intersects(object->getWorldBoundingBox()))
                {
                    mCasterList->push_back(object);
                    return true;
                }
        }
    }
    return true;
}


