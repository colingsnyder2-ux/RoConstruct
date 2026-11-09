// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5 roc_rbxscene_fpfast_63a615e0f16e56ce.cpp

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
    bool mRbxRenderFlag;
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
    virtual const Pass* _setPass(const Pass* pass, bool evenIfSuppressed = false,
                                 bool shadowDerivation = true);
    const Pass* deriveShadowCasterPass(const Pass* pass);
    const Pass* deriveShadowReceiverPass(const Pass* pass);
    const TexturePtr& getShadowTexture(size_t shadowIndex);
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

const Pass* RbxSceneManager::_setPass(const Pass* pass, bool evenIfSuppressed,
                                      bool shadowDerivation)
{
    if (!mSuppressRenderStateChanges || evenIfSuppressed)
    {
        mRbxVisibilityFlag = !!pass->getLightingEnabled();

        if (mIlluminationStage == IRS_RENDER_TO_TEXTURE && shadowDerivation)
        {
            pass = deriveShadowCasterPass(pass);
        }
        else if (mIlluminationStage == IRS_RENDER_RECEIVER_PASS && shadowDerivation)
        {
            pass = deriveShadowReceiverPass(pass);
        }

        mAutoParamDataSource.setCurrentPass(pass);
        bool passSurfaceAndLightParams = true;

        if (pass->hasVertexProgram())
        {
            mDestRenderSystem->bindGpuProgram(
                pass->getVertexProgram()->_getBindingDelegate());
            passSurfaceAndLightParams =
                pass->getVertexProgram()->getPassSurfaceAndLightStates();
        }
        else
        {
            if (mDestRenderSystem->isGpuProgramBound(GPT_VERTEX_PROGRAM))
            {
                mDestRenderSystem->unbindGpuProgram(GPT_VERTEX_PROGRAM);
            }
        }

        if (passSurfaceAndLightParams)
        {
            if (pass->getLightingEnabled())
            {
                mDestRenderSystem->_setSurfaceParams(
                    pass->getAmbient(),
                    pass->getDiffuse(),
                    pass->getSpecular(),
                    pass->getSelfIllumination(),
                    pass->getShininess(),
                    pass->getVertexColourTracking());
            }

            mDestRenderSystem->setLightingEnabled(pass->getLightingEnabled());
        }

        if (pass->hasFragmentProgram())
        {
            mDestRenderSystem->bindGpuProgram(
                pass->getFragmentProgram()->_getBindingDelegate());
        }
        else
        {
            if (mDestRenderSystem->isGpuProgramBound(GPT_FRAGMENT_PROGRAM))
            {
                mDestRenderSystem->unbindGpuProgram(GPT_FRAGMENT_PROGRAM);
            }
        }

        FogMode newFogMode;
        ColourValue newFogColour;
        Real newFogStart;
        Real newFogEnd;
        Real newFogDensity;
        if (pass->getFogOverride())
        {
            newFogMode = pass->getFogMode();
            newFogColour = pass->getFogColour();
            newFogStart = pass->getFogStart();
            newFogEnd = pass->getFogEnd();
            newFogDensity = pass->getFogDensity();
        }
        else
        {
            newFogMode = mFogMode;
            newFogColour = mFogColour;
            newFogStart = mFogStart;
            newFogEnd = mFogEnd;
            newFogDensity = mFogDensity;
        }
        mDestRenderSystem->_setFog(
            newFogMode, newFogColour, newFogDensity, newFogStart, newFogEnd);
        mAutoParamDataSource.setFog(
            mFogMode, mFogColour, mFogDensity, mFogStart, mFogEnd);

        mDestRenderSystem->_setSceneBlending(
            pass->getSourceBlendFactor(), pass->getDestBlendFactor());

        mDestRenderSystem->_setPointParameters(
            pass->getPointSize(),
            pass->isPointAttenuationEnabled(),
            pass->getPointAttenuationConstant(),
            pass->getPointAttenuationLinear(),
            pass->getPointAttenuationQuadratic(),
            pass->getPointMinSize(),
            pass->getPointMaxSize());

        mDestRenderSystem->_setPointSpritesEnabled(pass->getPointSpritesEnabled());

        Pass::ConstTextureUnitStateIterator texIter =
            pass->getTextureUnitStateIterator();
        size_t unit = 0;
        size_t shadowTexIndex = pass->getStartLight();
        while (texIter.hasMoreElements())
        {
            TextureUnitState* texture = texIter.getNext();
            if (!pass->getIteratePerLight() &&
                isShadowTechniqueTextureBased() &&
                texture->getContentType() == TextureUnitState::CONTENT_SHADOW)
            {
                TexturePtr shadowTexture;
                if (shadowTexIndex < mShadowTextures.size())
                {
                    shadowTexture = getShadowTexture(shadowTexIndex);
                    Camera* camera = shadowTexture->getBuffer()
                                         ->getRenderTarget()
                                         ->getViewport(0)
                                         ->getCamera();
                    texture->setProjectiveTexturing(
                        !pass->hasVertexProgram(), camera);
                    mAutoParamDataSource.setTextureProjector(camera, shadowTexIndex);
                }
                else
                {
                    shadowTexture = mNullShadowTexture;
                    texture->setProjectiveTexturing(false);
                    mAutoParamDataSource.setTextureProjector(0, shadowTexIndex);
                }
                texture->_setTexturePtr(shadowTexture);
                ++shadowTexIndex;
            }
            else if (mIlluminationStage == IRS_NONE && pass->hasVertexProgram())
            {
                TextureUnitState::EffectMap::const_iterator effect =
                    texture->getEffects().find(
                        TextureUnitState::ET_PROJECTIVE_TEXTURE);
                if (effect != texture->getEffects().end())
                {
                    mAutoParamDataSource.setTextureProjector(
                        effect->second.frustum, unit);
                }
            }
            mDestRenderSystem->_setTextureUnitSettings(unit, *texture);
            ++unit;
        }

        mDestRenderSystem->_disableTextureUnitsFrom(
            pass->getNumTextureUnitStates());
        mDestRenderSystem->_setDepthBufferFunction(pass->getDepthFunction());
        mDestRenderSystem->_setDepthBufferCheckEnabled(
            pass->getDepthCheckEnabled());
        mDestRenderSystem->_setDepthBufferWriteEnabled(
            pass->getDepthWriteEnabled());
        mDestRenderSystem->_setDepthBias(
            pass->getDepthBiasConstant(), pass->getDepthBiasSlopeScale());
        mDestRenderSystem->_setAlphaRejectSettings(
            pass->getAlphaRejectFunction(), pass->getAlphaRejectValue());

        bool colourWrite = pass->getColourWriteEnabled();
        mDestRenderSystem->_setColourBufferWriteEnabled(
            colourWrite, colourWrite, colourWrite, colourWrite);

        if (isShadowTechniqueTextureBased() &&
            mIlluminationStage == IRS_RENDER_TO_TEXTURE &&
            mShadowCasterRenderBackFaces &&
            pass->getCullingMode() == CULL_CLOCKWISE)
        {
            mDestRenderSystem->_setCullingMode(CULL_ANTICLOCKWISE);
        }
        else
        {
            mDestRenderSystem->_setCullingMode(pass->getCullingMode());
        }

        mDestRenderSystem->setShadingType(pass->getShadingMode());
        mDestRenderSystem->_setPolygonMode(pass->getPolygonMode());
        mAutoParamDataSource.setPassNumber(pass->getIndex());
    }

    return pass;
}

}
