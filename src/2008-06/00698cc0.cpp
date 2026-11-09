// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_rbxscene_timed_no_viewport_8cefb7f930351b4e.cpp

// Candidate translation unit (score above; library headers required).
#define RBX_TIMED_RENDER 1
#define _DLL
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {

class RbxSky;

#ifdef RBX_TIMED_RENDER
bool gRbxSceneRenderFlag;
#endif

class RbxSceneManager : public SceneManager {
    class ShadowCasterSceneQueryListener;

    class SceneMgrQueuedRenderableVisitor : public QueuedRenderableVisitor {
        const Pass* mUsedPass;

    public:
        void visit(const Renderable* renderable);
        bool visit(const Pass* pass);
        void visit(const RenderablePass* renderablePass);

        SceneManager* targetSceneMgr;
        bool transparentShadowCastersMode;
        bool autoLights;
        const LightList* manualLightList;
    };

    bool mRbxVisibilityFlag;
    bool mRbxRenderFlag;
    String mRbxSkyName;
    SharedPtr<RbxSky> mRbxSky;
    SceneNode* mRbxSkyNode;
    ShadowCasterSceneQueryListener* mShadowCasterQueryListener;
    SceneMgrQueuedRenderableVisitor* mActiveQueuedRenderableVisitor;
    SceneMgrQueuedRenderableVisitor mDefaultQueuedRenderableVisitor;

public:
    virtual void _renderScene(Camera* camera, Viewport* vp, bool includeOverlays);
};

void RbxSceneManager::_renderScene(Camera* camera, Viewport* vp, bool includeOverlays)
{
#ifdef RBX_TIMED_RENDER
    gRbxSceneRenderFlag = false;
#endif
    mRbxVisibilityFlag = true;
    mRbxRenderFlag = false;

    Root::getSingleton()._setCurrentSceneManager(this);
    mActiveQueuedRenderableVisitor->targetSceneMgr = this;
    mAutoParamDataSource.setCurrentSceneManager(this);

    if (isShadowTechniqueInUse())
    {
        initShadowVolumeMaterials();
    }

    if (isShadowTechniqueStencilBased() &&
        camera->getProjectionType() == PT_PERSPECTIVE &&
        camera->getFarClipDistance() != 0 &&
        mDestRenderSystem->getCapabilities()->hasCapability(RSC_INFINITE_FAR_PLANE) &&
        mShadowUseInfiniteFarPlane)
    {
        camera->setFarClipDistance(0);
    }

    mCameraInProgress = camera;

    ControllerManager::getSingleton().updateAllControllers();

    unsigned long thisFrameNumber = Root::getSingleton().getCurrentFrameNumber();
    if (thisFrameNumber != mLastFrameNumber)
    {
        _applySceneAnimations();
        mLastFrameNumber = thisFrameNumber;
    }

#ifdef RBX_TIMED_RENDER
    Timer renderTimer;
#endif

    {
        OGRE_LOCK_MUTEX(sceneGraphMutex)

#ifdef RBX_TIMED_RENDER
        renderTimer.reset();
#endif
        _updateSceneGraph(camera);
#ifdef RBX_TIMED_RENDER
        renderTimer.getMicroseconds();
#endif

        AutoTrackingSceneNodes::iterator atsni, atsniend;
        atsniend = mAutoTrackingSceneNodes.end();
        for (atsni = mAutoTrackingSceneNodes.begin(); atsni != atsniend; ++atsni)
        {
            (*atsni)->_autoTrack();
        }
        camera->_autoTrack();

        if (mIlluminationStage != IRS_RENDER_TO_TEXTURE && mFindVisibleObjects)
        {
            findLightsAffectingFrustum(camera);

            if (isShadowTechniqueInUse() && vp->getShadowsEnabled())
            {
                if (isShadowTechniqueTextureBased())
                {
                    prepareShadowTextures(camera, vp);
                    mCameraInProgress = camera;
                }
            }
        }

        if (camera->isReflected())
        {
            mDestRenderSystem->setInvertVertexWinding(true);
        }
        else
        {
            mDestRenderSystem->setInvertVertexWinding(false);
        }

        mAutoParamDataSource.setCurrentViewport(vp);
        setViewport(vp);

        mAutoParamDataSource.setCurrentCamera(camera);
        mAutoParamDataSource.setShadowDirLightExtrusionDistance(mShadowDirLightExtrudeDist);

        mAutoParamDataSource.setAmbientLightColour(mAmbientLight);
        mDestRenderSystem->setAmbientLight(mAmbientLight.r, mAmbientLight.g, mAmbientLight.b);

        mAutoParamDataSource.setCurrentRenderTarget(vp->getTarget());

        if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_USER_CLIP_PLANES))
        {
            if (camera->isWindowSet())
            {
                const std::vector<Plane>& planeList = camera->getWindowPlanes();
                for (ushort i = 0; i < 4; ++i)
                {
                    mDestRenderSystem->enableClipPlane(i, true);
                    mDestRenderSystem->setClipPlane(i, planeList[i]);
                }
            }
            else
            {
                for (ushort i = 0; i < 4; ++i)
                {
                    mDestRenderSystem->enableClipPlane(i, false);
                }
            }
        }

#ifdef RBX_TIMED_RENDER
        renderTimer.reset();
#endif
        prepareRenderQueue();
#ifdef RBX_TIMED_RENDER
        renderTimer.getMicroseconds();
#endif

        if (mFindVisibleObjects)
        {
            CamVisibleObjectsMap::iterator camVisObjIt = mCamVisibleObjectsMap.find(camera);

            assert(camVisObjIt != mCamVisibleObjectsMap.end() &&
                   "Should never fail to find a visible object bound for a camera, "
                   "did you override SceneManager::createCamera or something?");

            camVisObjIt->second.reset();

            _findVisibleObjects(camera, &(camVisObjIt->second),
                                mIlluminationStage == IRS_RENDER_TO_TEXTURE ? true : false);

            mAutoParamDataSource.setMainCamBoundsInfo(&(camVisObjIt->second));
        }

        if (vp->getOverlaysEnabled() && mIlluminationStage != IRS_RENDER_TO_TEXTURE)
        {
            OverlayManager::getSingleton()._queueOverlaysForRendering(camera, getRenderQueue(), vp);
        }

        if (vp->getSkiesEnabled() && mFindVisibleObjects &&
            mIlluminationStage != IRS_RENDER_TO_TEXTURE)
        {
            _queueSkiesForRendering(camera);
        }
    }

    mDestRenderSystem->_beginGeometryCount();
    if (mCurrentViewport->getClearEveryFrame())
    {
        mDestRenderSystem->clearFrameBuffer(
            mCurrentViewport->getClearBuffers(),
            mCurrentViewport->getBackgroundColour());
    }
    mDestRenderSystem->_beginFrame();

    mDestRenderSystem->_setPolygonMode(camera->getPolygonMode());

    mDestRenderSystem->_setProjectionMatrix(mCameraInProgress->getProjectionMatrixRS());
    mDestRenderSystem->_setViewMatrix(mCameraInProgress->getViewMatrix(true));

#ifdef RBX_TIMED_RENDER
    renderTimer.reset();
#endif
    _renderVisibleObjects();
#ifdef RBX_TIMED_RENDER
    renderTimer.getMicroseconds();
#endif

    mDestRenderSystem->_endFrame();

    camera->_notifyRenderedFaces(mDestRenderSystem->_getFaceCount());
    camera->_notifyRenderedBatches(mDestRenderSystem->_getBatchCount());
}

}
