// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5 roc_rbxscene_ctor_252e30df9e8b13f7.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {

class RbxSky;

class RbxSceneManager : public SceneManager {
    class ShadowCasterSceneQueryListener : public SceneQueryListener {
        SceneManager* mSceneMgr;
        ShadowCasterList* mCasterList;
        bool mIsLightInFrustum;
        const PlaneBoundedVolumeList* mLightClipVolumeList;
        const Camera* mCamera;
        const Light* mLight;
        Real mFarDistSquared;

    public:
        explicit ShadowCasterSceneQueryListener(SceneManager* sceneManager)
            : mSceneMgr(sceneManager),
              mCasterList(0),
              mIsLightInFrustum(false),
              mLightClipVolumeList(0),
              mCamera(0)
        {
        }

        bool queryResult(MovableObject* object);
        bool queryResult(SceneQuery::WorldFragment* fragment);
    };

    class SceneMgrQueuedRenderableVisitor : public QueuedRenderableVisitor {
        const Pass* mUsedPass;

    public:
        SceneMgrQueuedRenderableVisitor()
            : transparentShadowCastersMode(false)
        {
        }

        ~SceneMgrQueuedRenderableVisitor()
        {
        }

        void visit(const Renderable* renderable);
        bool visit(const Pass* pass);
        void visit(const RenderablePass* renderablePass);

        SceneManager* targetSceneMgr;
        bool transparentShadowCastersMode;
        bool autoLights;
        const LightList* manualLightList;
    };

    bool mRbxVisibilityFlag;
    String mRbxSkyName;
    SharedPtr<RbxSky> mRbxSky;
    SceneNode* mRbxSkyNode;
    ShadowCasterSceneQueryListener* mShadowCasterQueryListener;
    SceneMgrQueuedRenderableVisitor* mActiveQueuedRenderableVisitor;
    SceneMgrQueuedRenderableVisitor mDefaultQueuedRenderableVisitor;

public:
    explicit RbxSceneManager(const String& name);
    virtual ~RbxSceneManager();
    virtual void destroyAllCameras(void);
    virtual void clearScene(void);
};

RbxSceneManager::RbxSceneManager(const String& name)
    : SceneManager(name)
{
    mShadowCasterQueryListener = new ShadowCasterSceneQueryListener(this);
    mActiveQueuedRenderableVisitor = &mDefaultQueuedRenderableVisitor;
}

RbxSceneManager::~RbxSceneManager()
{
    clearScene();
    destroyAllCameras();

    for (MovableObjectCollectionMap::iterator item = mMovableObjectCollectionMap.begin();
         item != mMovableObjectCollectionMap.end(); ++item)
    {
        delete item->second;
    }
    mMovableObjectCollectionMap.clear();

    delete mShadowCasterQueryListener;
}

}
