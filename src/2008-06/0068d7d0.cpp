// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_espclaude_be1af347978f4727.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "OgreSceneManager.h"
#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreEntity.h"
#include "OgreSubEntity.h"
#include "OgreRenderQueue.h"
namespace Ogre {
struct Queue:RenderQueue {__declspec(dllimport) void enqueue(Renderable*,unsigned,unsigned short);};
struct Special {void update(Camera*,RenderQueue*,unsigned);};
struct RbxSceneManager:SceneManager {
 char tail[0x8bdc-sizeof(SceneManager)];Special* special;unsigned reserved;SceneNode* extra;
 void f(Camera*);
};
void RbxSceneManager::f(Camera* cam)
{
    if (mSkyPlaneNode)
    {
        mSkyPlaneNode->setPosition(cam->getDerivedPosition());
    }

    if (mSkyBoxNode)
    {
        mSkyBoxNode->setPosition(cam->getDerivedPosition());
        extra->setPosition(cam->getDerivedPosition());
    }

    if (mSkyDomeNode)
    {
        mSkyDomeNode->setPosition(cam->getDerivedPosition());
    }

    RenderQueueGroupID qid;
    if (mSkyPlaneEnabled)
    {
        qid = mSkyPlaneDrawFirst? RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;
        getRenderQueue()->addRenderable(mSkyPlaneEntity->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
    }

    uint plane;
    if (mSkyBoxEnabled)
    {
        qid = mSkyBoxDrawFirst? RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;

        for (plane = 0; plane < 6; ++plane)
        {
            getRenderQueue()->addRenderable(
                mSkyBoxEntity[plane]->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
        }
        if (Special* object = special)
            object->update(cam, getRenderQueue(), qid);
    }

    if (mSkyDomeEnabled)
    {
        qid = mSkyDomeDrawFirst? RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;

        for (plane = 0; plane < 5; ++plane)
        {
            getRenderQueue()->addRenderable(
                mSkyDomeEntity[plane]->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
        }
    }
}
}
