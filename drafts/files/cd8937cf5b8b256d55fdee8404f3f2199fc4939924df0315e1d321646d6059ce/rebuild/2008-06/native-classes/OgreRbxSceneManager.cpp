// native-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Ogre::RbxSceneManager / RbxSceneManagerFactory as compiled into the June 2008 client (inactive native recovery).
//
// Roblox forked Ogre 1.4.5's OgreSceneManager.cpp into ".\RbxSceneManager.cpp" (string 0084e9e8) and overrode every
// SceneManager virtual. Declarations: native-headers/OgreRbx/RbxSceneManager2008.h. Profile: document-swap flags plus
// the Ogre 1.4.5 client include path, VS2008 RTM 21022, /fp:fast (the x87 ordering of _setPass 00694680,
// renderModulativeTextureShadowedQueueGroupObjects 00695420 and _populateLightList 0069e390 only matches with it).
//
// Most bodies are the Ogre 1.4.5 OgreSceneManager.cpp bodies unchanged (each is preceded by its line in that file).
// The fork's edits, each proven by the target bytes:
//   * exception sites: "RbxSceneManager::..." source names and the original file name / line constants (pushed with
//     the 0084e9e8 file string at every OGRE_EXCEPT site), reproduced with #line;
//   * _setPass stores pass->getLightingEnabled() at +0x8bb8; renderModulativeTextureShadowedQueueGroupObjects has no
//     isCustomProjectionMatrixEnabled() test; renderShadowVolumeObjects has no isVisible() test; the bodies after the
//     "fork bodies" marker (cameras, light list, animations, manualRender, the Ogre::Timer-instrumented basic queue
//     group and _renderScene, the findingShadowCasters guard) follow the fork's versions.
// Not built (blocked): setSkyBox 00692a10 (constructs RbxSky, new(0xd4), ctor 0067fd60) and renderSingleObject
// 0069bc50 (dynamic_cast to RbxSubEntity / RbxSceneNode and their cached transforms). findShadowCastersForLight
// 006960e0 is compiled only with NATIVE_OGRE_RBXSCENEMANAGER_PENDING (it needs a declaration of RbxEntity::collect).
// _queueSkiesForRendering 0068d7d0 calls RbxSky::update through the minimal OgreRbx/RbxSky2008.h.
#include "OgreSceneManager.h"
#include "OgreCamera.h"
#include "OgreRenderSystem.h"
#include "OgreMeshManager.h"
#include "OgreMesh.h"
#include "OgreSubMesh.h"
#include "OgreEntity.h"
#include "OgreSubEntity.h"
#include "OgreLight.h"
#include "OgreMath.h"
#include "OgreControllerManager.h"
#include "OgreMaterialManager.h"
#include "OgreAnimation.h"
#include "OgreAnimationTrack.h"
#include "OgreRenderQueueSortingGrouping.h"
#include "OgreOverlay.h"
#include "OgreOverlayManager.h"
#include "OgreStringConverter.h"
#include "OgreRenderQueueListener.h"
#include "OgreBillboardSet.h"
#include "OgrePass.h"
#include "OgreTechnique.h"
#include "OgreTextureUnitState.h"
#include "OgreException.h"
#include "OgreLogManager.h"
#include "OgreHardwareBufferManager.h"
#include "OgreRoot.h"
#include "OgreSpotShadowFadePng.h"
#include "OgreGpuProgramManager.h"
#include "OgreGpuProgram.h"
#include "OgreShadowVolumeExtrudeProgram.h"
#include "OgreDataStream.h"
#include "OgreStaticGeometry.h"
#include "OgreHardwarePixelBuffer.h"
#include "OgreManualObject.h"
#include "OgreRenderQueueInvocation.h"
#include "OgreBillboardChain.h"
#include "OgreRibbonTrail.h"
#include "OgreParticleSystemManager.h"
#include "OgreTimer.h"
#include "OgreRbx/RbxSceneManager2008.h"
#ifdef NATIVE_OGRE_RBXSCENEMANAGER_PENDING
#include "RbxSceneManagerPendingDecls.h"
#endif
#include <cstdio>

namespace Ogre {


const String RbxSceneManagerFactory::FACTORY_TYPE_NAME = "RbxSceneManager";

void RbxSceneManagerFactory::initMetaData(void) const
{
	mMetaData.typeName = FACTORY_TYPE_NAME;
	mMetaData.description = "The Roblox scene manager";
	mMetaData.sceneTypeMask = ST_GENERIC;
	mMetaData.worldGeometrySupported = false;
}

SceneManager* RbxSceneManagerFactory::createInstance(const String& instanceName)
{
	return new RbxSceneManager(instanceName);
}

void RbxSceneManagerFactory::destroyInstance(SceneManager* instance)
{
	delete instance;
}

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

	for (MovableObjectCollectionMap::iterator i = mMovableObjectCollectionMap.begin();
		i != mMovableObjectCollectionMap.end(); ++i)
	{
		delete i->second;
	}
	mMovableObjectCollectionMap.clear();

	delete mShadowCasterQueryListener;
}

const String& RbxSceneManager::getTypeName(void) const
{
	return RbxSceneManagerFactory::FACTORY_TYPE_NAME;
}

// OgreSceneManager.cpp:197
RenderQueue* RbxSceneManager::getRenderQueue(void)
{
    if (!mRenderQueue)
    {
        initRenderQueue();
    }
    return mRenderQueue;
}

// OgreSceneManager.cpp:206
void RbxSceneManager::initRenderQueue(void)
{
    mRenderQueue = new RenderQueue();
    // init render queues that do not need shadows
    mRenderQueue->getQueueGroup(RENDER_QUEUE_BACKGROUND)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_OVERLAY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_EARLY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_LATE)->setShadowsEnabled(false);
}

// OgreSceneManager.cpp:216
void RbxSceneManager::addSpecialCaseRenderQueue(uint8 qid)
{
	mSpecialCaseQueueList.insert(qid);
}

// OgreSceneManager.cpp:221
void RbxSceneManager::removeSpecialCaseRenderQueue(uint8 qid)
{
	mSpecialCaseQueueList.erase(qid);
}

// OgreSceneManager.cpp:226
void RbxSceneManager::clearSpecialCaseRenderQueues(void)
{
	mSpecialCaseQueueList.clear();
}

// OgreSceneManager.cpp:231
void RbxSceneManager::setSpecialCaseRenderQueueMode(SceneManager::SpecialCaseRenderQueueMode mode)
{
	mSpecialCaseQueueMode = mode;
}

// OgreSceneManager.cpp:236
SceneManager::SpecialCaseRenderQueueMode RbxSceneManager::getSpecialCaseRenderQueueMode(void)
{
	return mSpecialCaseQueueMode;
}

// OgreSceneManager.cpp:241
bool RbxSceneManager::isRenderQueueToBeProcessed(uint8 qid)
{
	bool inList = mSpecialCaseQueueList.find(qid) != mSpecialCaseQueueList.end();
	return (inList && mSpecialCaseQueueMode == SCRQM_INCLUDE)
		|| (!inList && mSpecialCaseQueueMode == SCRQM_EXCLUDE);
}

// OgreSceneManager.cpp:248
void RbxSceneManager::setWorldGeometryRenderQueue(uint8 qid)
{
	mWorldGeometryRenderQueue = qid;
}

// OgreSceneManager.cpp:253
uint8 RbxSceneManager::getWorldGeometryRenderQueue(void)
{
	return mWorldGeometryRenderQueue;
}

// OgreSceneManager.cpp:258
Camera* RbxSceneManager::createCamera(const String& name)
{
    // Check name not used
    if (mCameras.find(name) != mCameras.end())
    {
#line 229 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "A camera with the name " + name + " already exists",
            "RbxSceneManager::createCamera" );
    }

    Camera *c = new Camera(name, this);
    mCameras.insert(CameraList::value_type(name, c));

	// create visible bounds aab map entry
	mCamVisibleObjectsMap[c] = VisibleObjectsBoundsInfo();

    return c;
}

// OgreSceneManager.cpp:279
Camera* RbxSceneManager::getCamera(const String& name) const
{
    CameraList::const_iterator i = mCameras.find(name);
    if (i == mCameras.end())
    {
#line 250 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find Camera with name " + name,
            "RbxSceneManager::getCamera");
    }
    else
    {
        return i->second;
    }
}

// OgreSceneManager.cpp:294
bool RbxSceneManager::hasCamera(const String& name) const
{
	return (mCameras.find(name) != mCameras.end());
}

// OgreSceneManager.cpp:347
Light* RbxSceneManager::createLight(const String& name)
{
	return static_cast<Light*>(
		createMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:353
Light* RbxSceneManager::getLight(const String& name) const
{
	return static_cast<Light*>(
		getMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:359
bool RbxSceneManager::hasLight(const String& name) const
{
	return hasMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:364
void RbxSceneManager::destroyLight(Light *l)
{
	destroyMovableObject(l);
}

// OgreSceneManager.cpp:369
void RbxSceneManager::destroyLight(const String& name)
{
	destroyMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:374
void RbxSceneManager::destroyAllLights(void)
{
	destroyAllMovableObjectsByType(LightFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:379
const LightList& RbxSceneManager::_getLightsAffectingFrustum(void) const
{
    return mLightsAffectingFrustum;
}

// OgreSceneManager.cpp:449
Entity* RbxSceneManager::createEntity(const String& entityName, PrefabType ptype)
{
    switch (ptype)
    {
    case PT_PLANE:
        return createEntity(entityName, "Prefab_Plane");
	case PT_CUBE:
		return createEntity(entityName, "Prefab_Cube");
	case PT_SPHERE:
		return createEntity(entityName, "Prefab_Sphere");

        break;
    }

#line 435 ".\\RbxSceneManager.cpp"
    OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
        "Unknown prefab type for entity " + entityName,
        "RbxSceneManager::createEntity");
}

// OgreSceneManager.cpp:469
Entity* RbxSceneManager::createEntity(
                                   const String& entityName,
                                   const String& meshName )
{
	// delegate to factory implementation
	NameValuePairList params;
	params["mesh"] = meshName;
	return static_cast<Entity*>(
		createMovableObject(entityName, EntityFactory::FACTORY_TYPE_NAME, 
			&params));

}

// OgreSceneManager.cpp:483
Entity* RbxSceneManager::getEntity(const String& name) const
{
	return static_cast<Entity*>(
		getMovableObject(name, EntityFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:489
bool RbxSceneManager::hasEntity(const String& name) const
{
	return hasMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:495
void RbxSceneManager::destroyEntity(Entity *e)
{
	destroyMovableObject(e);
}

// OgreSceneManager.cpp:501
void RbxSceneManager::destroyEntity(const String& name)
{
	destroyMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);

}

// OgreSceneManager.cpp:508
void RbxSceneManager::destroyAllEntities(void)
{

	destroyAllMovableObjectsByType(EntityFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:515
void RbxSceneManager::destroyAllBillboardSets(void)
{
	destroyAllMovableObjectsByType(BillboardSetFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:520
ManualObject* RbxSceneManager::createManualObject(const String& name)
{
	return static_cast<ManualObject*>(
		createMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:526
ManualObject* RbxSceneManager::getManualObject(const String& name) const
{
	return static_cast<ManualObject*>(
		getMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));

}

// OgreSceneManager.cpp:533
bool RbxSceneManager::hasManualObject(const String& name) const
{
	return hasMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);

}

// OgreSceneManager.cpp:539
void RbxSceneManager::destroyManualObject(ManualObject* obj)
{
	destroyMovableObject(obj);
}

// OgreSceneManager.cpp:544
void RbxSceneManager::destroyManualObject(const String& name)
{
	destroyMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:549
void RbxSceneManager::destroyAllManualObjects(void)
{
	destroyAllMovableObjectsByType(ManualObjectFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:554
BillboardChain* RbxSceneManager::createBillboardChain(const String& name)
{
	return static_cast<BillboardChain*>(
		createMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:560
BillboardChain* RbxSceneManager::getBillboardChain(const String& name) const
{
	return static_cast<BillboardChain*>(
		getMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));

}

// OgreSceneManager.cpp:567
bool RbxSceneManager::hasBillboardChain(const String& name) const
{
	return hasMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:573
void RbxSceneManager::destroyBillboardChain(BillboardChain* obj)
{
	destroyMovableObject(obj);
}

// OgreSceneManager.cpp:578
void RbxSceneManager::destroyBillboardChain(const String& name)
{
	destroyMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:583
void RbxSceneManager::destroyAllBillboardChains(void)
{
	destroyAllMovableObjectsByType(BillboardChainFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:588
RibbonTrail* RbxSceneManager::createRibbonTrail(const String& name)
{
	return static_cast<RibbonTrail*>(
		createMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:594
RibbonTrail* RbxSceneManager::getRibbonTrail(const String& name) const
{
	return static_cast<RibbonTrail*>(
		getMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));

}

// OgreSceneManager.cpp:601
bool RbxSceneManager::hasRibbonTrail(const String& name) const
{
	return hasMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:607
void RbxSceneManager::destroyRibbonTrail(RibbonTrail* obj)
{
	destroyMovableObject(obj);
}

// OgreSceneManager.cpp:612
void RbxSceneManager::destroyRibbonTrail(const String& name)
{
	destroyMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:617
void RbxSceneManager::destroyAllRibbonTrails(void)
{
	destroyAllMovableObjectsByType(RibbonTrailFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:622
ParticleSystem* RbxSceneManager::createParticleSystem(const String& name,
	const String& templateName)
{
	NameValuePairList params;
	params["templateName"] = templateName;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}

// OgreSceneManager.cpp:633
ParticleSystem* RbxSceneManager::createParticleSystem(const String& name,
	size_t quota, const String& group)
{
	NameValuePairList params;
	params["quota"] = StringConverter::toString(quota);
	params["resourceGroup"] = group;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}

// OgreSceneManager.cpp:645
ParticleSystem* RbxSceneManager::getParticleSystem(const String& name) const
{
	return static_cast<ParticleSystem*>(
		getMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME));

}

// OgreSceneManager.cpp:652
bool RbxSceneManager::hasParticleSystem(const String& name) const
{
	return hasMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:658
void RbxSceneManager::destroyParticleSystem(ParticleSystem* obj)
{
	destroyMovableObject(obj);
}

// OgreSceneManager.cpp:663
void RbxSceneManager::destroyParticleSystem(const String& name)
{
	destroyMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:668
void RbxSceneManager::destroyAllParticleSystems(void)
{
	destroyAllMovableObjectsByType(ParticleSystemFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:673
void RbxSceneManager::clearScene(void)
{
	destroyAllStaticGeometry();
	destroyAllMovableObjects();

	// Clear root node of all children
	mSceneRoot->removeAllChildren();
	mSceneRoot->detachAllObjects();

	// Delete all SceneNodes, except root that is
	for (SceneNodeList::iterator i = mSceneNodes.begin();
		i != mSceneNodes.end(); ++i)
	{
		delete i->second;
	}
	mSceneNodes.clear();
	mAutoTrackingSceneNodes.clear();


	
	// Clear animations
    destroyAllAnimations();

    // Remove sky nodes since they've been deleted
    mSkyBoxNode = mSkyPlaneNode = mSkyDomeNode = 0;
    mSkyBoxEnabled = mSkyPlaneEnabled = mSkyDomeEnabled = false; 

	// Clear render queue, empty completely
	if (mRenderQueue)
		mRenderQueue->clear(true);

}

// OgreSceneManager.cpp:706
SceneNode* RbxSceneManager::createSceneNode(void)
{
    SceneNode* sn = new SceneNode(this);
    assert(mSceneNodes.find(sn->getName()) == mSceneNodes.end());
    mSceneNodes[sn->getName()] = sn;
    return sn;
}

// OgreSceneManager.cpp:714
SceneNode* RbxSceneManager::createSceneNode(const String& name)
{
    // Check name not used
    if (mSceneNodes.find(name) != mSceneNodes.end())
    {
#line 691 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "A scene node with the name " + name + " already exists",
            "RbxSceneManager::createSceneNode" );
    }

    SceneNode* sn = new SceneNode(this, name);
    mSceneNodes[sn->getName()] = sn;
    return sn;
}

// OgreSceneManager.cpp:730
void RbxSceneManager::destroySceneNode(const String& name)
{
    SceneNodeList::iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
#line 708 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "SceneNode '" + name + "' not found.",
            "RbxSceneManager::destroySceneNode");
    }

    // Find any scene nodes which are tracking this node, and turn them off
    AutoTrackingSceneNodes::iterator ai, aiend;
    aiend = mAutoTrackingSceneNodes.end();
    for (ai = mAutoTrackingSceneNodes.begin(); ai != aiend; )
    {
		// Pre-increment incase we delete
		AutoTrackingSceneNodes::iterator curri = ai++;
        SceneNode* n = *curri;
        // Tracking this node
        if (n->getAutoTrackTarget() == i->second)
        {
            // turn off, this will notify SceneManager to remove
            n->setAutoTracking(false);
        }
        // node is itself a tracker
        else if (n == i->second)
        {
            mAutoTrackingSceneNodes.erase(curri);
        }
    }

	// detach from parent (don't do this in destructor since bulk destruction
	// behaves differently)
	Node* parentNode = i->second->getParent();
	if (parentNode)
	{
		parentNode->removeChild(i->second);
	}
    delete i->second;
    mSceneNodes.erase(i);
}

// OgreSceneManager.cpp:772
SceneNode* RbxSceneManager::getRootSceneNode(void) const
{
    return mSceneRoot;
}

// OgreSceneManager.cpp:777
SceneNode* RbxSceneManager::getSceneNode(const String& name) const
{
    SceneNodeList::const_iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
#line 755 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "SceneNode '" + name + "' not found.",
            "RbxSceneManager::getSceneNode");
    }

    return i->second;

}

// OgreSceneManager.cpp:791
bool RbxSceneManager::hasSceneNode(const String& name) const
{
	return (mSceneNodes.find(name) != mSceneNodes.end());
}

// OgreSceneManager.cpp:797
const Pass* RbxSceneManager::_setPass(const Pass* pass, bool evenIfSuppressed, 
								   bool shadowDerivation)
{
	if (!mSuppressRenderStateChanges || evenIfSuppressed)
	{
		// fork: remember the pass lighting state (_setPass 00694680 stores it at +0x8bb8)
		mPassLightingEnabled = !!pass->getLightingEnabled();

		if (mIlluminationStage == IRS_RENDER_TO_TEXTURE && shadowDerivation)
		{
			// Derive a special shadow caster pass from this one
			pass = deriveShadowCasterPass(pass);
		}
		else if (mIlluminationStage == IRS_RENDER_RECEIVER_PASS && shadowDerivation)
		{
			pass = deriveShadowReceiverPass(pass);
		}

        // Tell params about current pass
        mAutoParamDataSource.setCurrentPass(pass);

		// TEST
		/*
		LogManager::getSingleton().logMessage("BEGIN PASS " + StringConverter::toString(pass->getIndex()) + 
		" of " + pass->getParent()->getParent()->getName());
		*/
		bool passSurfaceAndLightParams = true;

		if (pass->hasVertexProgram())
		{
			mDestRenderSystem->bindGpuProgram(pass->getVertexProgram()->_getBindingDelegate());
			// bind parameters later since they can be per-object
			// does the vertex program want surface and light params passed to rendersystem?
			passSurfaceAndLightParams = pass->getVertexProgram()->getPassSurfaceAndLightStates();
		}
		else
		{
			// Unbind program?
			if (mDestRenderSystem->isGpuProgramBound(GPT_VERTEX_PROGRAM))
			{
				mDestRenderSystem->unbindGpuProgram(GPT_VERTEX_PROGRAM);
			}
			// Set fixed-function vertex parameters
		}

		if (passSurfaceAndLightParams)
		{
			// Set surface reflectance properties, only valid if lighting is enabled
			if (pass->getLightingEnabled())
			{
				mDestRenderSystem->_setSurfaceParams( 
					pass->getAmbient(), 
					pass->getDiffuse(), 
					pass->getSpecular(), 
					pass->getSelfIllumination(), 
					pass->getShininess(),
			pass->getVertexColourTracking() );
			}

			// Dynamic lighting enabled?
			mDestRenderSystem->setLightingEnabled(pass->getLightingEnabled());
		}

		// Using a fragment program?
		if (pass->hasFragmentProgram())
		{
			mDestRenderSystem->bindGpuProgram(
				pass->getFragmentProgram()->_getBindingDelegate());
			// bind parameters later since they can be per-object
		}
		else
		{
			// Unbind program?
			if (mDestRenderSystem->isGpuProgramBound(GPT_FRAGMENT_PROGRAM))
			{
				mDestRenderSystem->unbindGpuProgram(GPT_FRAGMENT_PROGRAM);
			}

			// Set fixed-function fragment settings
		}

        /* We need sets fog properties always. In D3D, it applies to shaders prior
        to version vs_3_0 and ps_3_0. And in OGL, it applies to "ARB_fog_XXX" in
        fragment program, and in other ways, them maybe access by gpu program via
        "state.fog.XXX".
        */
        // New fog params can either be from scene or from material
        FogMode newFogMode;
        ColourValue newFogColour;
        Real newFogStart, newFogEnd, newFogDensity;
        if (pass->getFogOverride())
        {
            // New fog params from material
            newFogMode = pass->getFogMode();
            newFogColour = pass->getFogColour();
            newFogStart = pass->getFogStart();
            newFogEnd = pass->getFogEnd();
            newFogDensity = pass->getFogDensity();
        }
        else
        {
            // New fog params from scene
            newFogMode = mFogMode;
            newFogColour = mFogColour;
            newFogStart = mFogStart;
            newFogEnd = mFogEnd;
            newFogDensity = mFogDensity;
        }
        mDestRenderSystem->_setFog(
            newFogMode, newFogColour, newFogDensity, newFogStart, newFogEnd);
        // Tell params about ORIGINAL fog
		// Need to be able to override fixed function fog, but still have
		// original fog parameters available to a shader than chooses to use
        mAutoParamDataSource.setFog(
            mFogMode, mFogColour, mFogDensity, mFogStart, mFogEnd);

		// The rest of the settings are the same no matter whether we use programs or not

		// Set scene blending
		mDestRenderSystem->_setSceneBlending(
			pass->getSourceBlendFactor(), pass->getDestBlendFactor());

		// Set point parameters
		mDestRenderSystem->_setPointParameters(
			pass->getPointSize(),
			pass->isPointAttenuationEnabled(), 
			pass->getPointAttenuationConstant(), 
			pass->getPointAttenuationLinear(), 
			pass->getPointAttenuationQuadratic(), 
			pass->getPointMinSize(), 
			pass->getPointMaxSize());

		mDestRenderSystem->_setPointSpritesEnabled(pass->getPointSpritesEnabled());

		// Texture unit settings

		Pass::ConstTextureUnitStateIterator texIter =  pass->getTextureUnitStateIterator();
		size_t unit = 0;
		// Reset the shadow texture index for each pass
		size_t shadowTexIndex = pass->getStartLight(); // all shadow casters are at the start
		while(texIter.hasMoreElements())
		{
			TextureUnitState* pTex = texIter.getNext();
			if (!pass->getIteratePerLight() && 
				isShadowTechniqueTextureBased() && 
				pTex->getContentType() == TextureUnitState::CONTENT_SHADOW)
			{
				// Need to bind the correct shadow texture, based on the start light
				// Even though the light list can change per object, our restrictions
				// say that when texture shadows are enabled, the lights up to the
				// number of texture shadows will be fixed for all objects
				// to match the shadow textures that have been generated
				// see ShadowListener::sortLightsAffectingFrustum and
				// MovableObject::Listener::objectQueryLights
				// Note that light iteration throws the indexes out so we don't bind here
				// if that's the case, we have to bind when lights are iterated
				// in renderSingleObject

				TexturePtr shadowTex;
				if (shadowTexIndex < mShadowTextures.size())
				{
					shadowTex = getShadowTexture(shadowTexIndex);
					// Hook up projection frustum
					Camera *cam = shadowTex->getBuffer()->getRenderTarget()->getViewport(0)->getCamera();
					// Enable projective texturing if fixed-function, but also need to
					// disable it explicitly for program pipeline.
					pTex->setProjectiveTexturing(!pass->hasVertexProgram(), cam);
					mAutoParamDataSource.setTextureProjector(cam, shadowTexIndex);
				}
				else
				{
					// Use fallback 'null' shadow texture
					// no projection since all uniform colour anyway
					shadowTex = mNullShadowTexture;
					pTex->setProjectiveTexturing(false);
					mAutoParamDataSource.setTextureProjector(0, shadowTexIndex);

				}
				pTex->_setTexturePtr(shadowTex);

				++shadowTexIndex;
			}
			else if (mIlluminationStage == IRS_NONE && pass->hasVertexProgram())
			{
				// Manually set texture projector for shaders if present
				// This won't get set any other way if using manual projection
				TextureUnitState::EffectMap::const_iterator effi = 
					pTex->getEffects().find(TextureUnitState::ET_PROJECTIVE_TEXTURE);
				if (effi != pTex->getEffects().end())
				{
					mAutoParamDataSource.setTextureProjector(effi->second.frustum, unit);
				}
			}
			mDestRenderSystem->_setTextureUnitSettings(unit, *pTex);
			++unit;
		}
		// Disable remaining texture units
		mDestRenderSystem->_disableTextureUnitsFrom(pass->getNumTextureUnitStates());

		// Set up non-texture related material settings
		// Depth buffer settings
		mDestRenderSystem->_setDepthBufferFunction(pass->getDepthFunction());
		mDestRenderSystem->_setDepthBufferCheckEnabled(pass->getDepthCheckEnabled());
		mDestRenderSystem->_setDepthBufferWriteEnabled(pass->getDepthWriteEnabled());
		mDestRenderSystem->_setDepthBias(pass->getDepthBiasConstant(), 
			pass->getDepthBiasSlopeScale());
		// Alpha-reject settings
		mDestRenderSystem->_setAlphaRejectSettings(
			pass->getAlphaRejectFunction(), pass->getAlphaRejectValue());
		// Set colour write mode
		// Right now we only use on/off, not per-channel
		bool colWrite = pass->getColourWriteEnabled();
		mDestRenderSystem->_setColourBufferWriteEnabled(colWrite, colWrite, colWrite, colWrite);
		// Culling mode
		if (isShadowTechniqueTextureBased() 
			&& mIlluminationStage == IRS_RENDER_TO_TEXTURE
			&& mShadowCasterRenderBackFaces
			&& pass->getCullingMode() == CULL_CLOCKWISE)
		{
			// render back faces into shadow caster, can help with depth comparison
			mDestRenderSystem->_setCullingMode(CULL_ANTICLOCKWISE);
		}
		else
		{
			mDestRenderSystem->_setCullingMode(pass->getCullingMode());
		}
		
		// Shading
		mDestRenderSystem->setShadingType(pass->getShadingMode());
		// Polygon mode
		mDestRenderSystem->_setPolygonMode(pass->getPolygonMode());

		// set pass number
    	mAutoParamDataSource.setPassNumber( pass->getIndex() );
	}

    return pass;
}

// OgreSceneManager.cpp:1033
void RbxSceneManager::prepareRenderQueue(void)
{
	RenderQueue* q = getRenderQueue();
	// Clear the render queue
	q->clear();

	// Prep the ordering options

	// If we're using a custom render squence, define based on that
	RenderQueueInvocationSequence* seq = 
		mCurrentViewport->_getRenderQueueInvocationSequence();
	if (seq)
	{
		// Iterate once to crate / reset all
		RenderQueueInvocationIterator invokeIt = seq->iterator();
		while (invokeIt.hasMoreElements())
		{
			RenderQueueInvocation* invocation = invokeIt.getNext();
			RenderQueueGroup* group = 
				q->getQueueGroup(invocation->getRenderQueueGroupID());
			group->resetOrganisationModes();
		}
		// Iterate again to build up options (may be more than one)
		invokeIt = seq->iterator();
		while (invokeIt.hasMoreElements())
		{
			RenderQueueInvocation* invocation = invokeIt.getNext();
			RenderQueueGroup* group = 
				q->getQueueGroup(invocation->getRenderQueueGroupID());
			group->addOrganisationMode(invocation->getSolidsOrganisation());
			// also set splitting options
			updateRenderQueueGroupSplitOptions(group, invocation->getSuppressShadows(), 
				invocation->getSuppressRenderStateChanges());
		}
	}
	else
	{
		// Default all the queue groups that are there, new ones will be created
		// with defaults too
		RenderQueue::QueueGroupIterator groupIter = q->_getQueueGroupIterator();
		while (groupIter.hasMoreElements())
		{
			RenderQueueGroup* g = groupIter.getNext();
			g->defaultOrganisationMode();
		}
		// Global split options
		updateRenderQueueSplitOptions();
	}

}

// OgreSceneManager.cpp:1293
void RbxSceneManager::_setDestinationRenderSystem(RenderSystem* sys)
{
    mDestRenderSystem = sys;

}

// OgreSceneManager.cpp:1301
void RbxSceneManager::setWorldGeometry(const String& filename)
{
    // This default implementation cannot handle world geometry
#line 1304 ".\\RbxSceneManager.cpp"
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}

// OgreSceneManager.cpp:1309
void RbxSceneManager::setWorldGeometry(DataStreamPtr& stream, 
	const String& typeName)
{
    // This default implementation cannot handle world geometry
#line 1313 ".\\RbxSceneManager.cpp"
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}

// OgreSceneManager.cpp:1341
void RbxSceneManager::setSkyPlane(
                               bool enable,
                               const Plane& plane,
                               const String& materialName,
                               Real gscale,
                               Real tiling,
                               bool drawFirst,
                               Real bow, 
                               int xsegments, int ysegments, 
                               const String& groupName)
{
    if (enable)
    {
        String meshName = mName + "SkyPlane";
        mSkyPlane = plane;

        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
#line 1338 ".\\RbxSceneManager.cpp"
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky plane material '" + materialName + "' not found.",
                "RbxSceneManager::setSkyPlane");
        }
        // Make sure the material doesn't update the depth buffer
        m->setDepthWriteEnabled(false);
        // Ensure loaded
        m->load();

        mSkyPlaneDrawFirst = drawFirst;

        // Set up the plane
        MeshPtr planeMesh = MeshManager::getSingleton().getByName(meshName);
        if (!planeMesh.isNull())
        {
            // Destroy the old one
            MeshManager::getSingleton().remove(planeMesh->getHandle());
        }

        // Create up vector
        Vector3 up = plane.normal.crossProduct(Vector3::UNIT_X);
        if (up == Vector3::ZERO)
            up = plane.normal.crossProduct(-Vector3::UNIT_Z);

        // Create skyplane
        if( bow > 0 )
        {
            // Build a curved skyplane
            planeMesh = MeshManager::getSingleton().createCurvedPlane(
                meshName, groupName, plane, gscale * 100, gscale * 100, gscale * bow * 100, 
                xsegments, ysegments, false, 1, tiling, tiling, up);
        }
        else
        {
            planeMesh = MeshManager::getSingleton().createPlane(
                meshName, groupName, plane, gscale * 100, gscale * 100, xsegments, ysegments, false, 
                1, tiling, tiling, up);
        }

        // Create entity 
        if (mSkyPlaneEntity)
        {
            // destroy old one, do it by name for speed
            destroyEntity(meshName);
        }
        // Create, use the same name for mesh and entity
        mSkyPlaneEntity = createEntity(meshName, meshName);
        mSkyPlaneEntity->setMaterialName(materialName);
        mSkyPlaneEntity->setCastShadows(false);

        // Create node and attach
        if (!mSkyPlaneNode)
        {
            mSkyPlaneNode = createSceneNode(meshName + "Node");
        }
        else
        {
            mSkyPlaneNode->detachAllObjects();
        }
        mSkyPlaneNode->attachObject(mSkyPlaneEntity);

    }
	mSkyPlaneEnabled = enable;
	mSkyPlaneGenParameters.skyPlaneBow = bow;
	mSkyPlaneGenParameters.skyPlaneScale = gscale;
	mSkyPlaneGenParameters.skyPlaneTiling = tiling;
	mSkyPlaneGenParameters.skyPlaneXSegments = xsegments;
	mSkyPlaneGenParameters.skyPlaneYSegments = ysegments;
}

// OgreSceneManager.cpp:1517
void RbxSceneManager::setSkyDome(
                              bool enable,
                              const String& materialName,
                              Real curvature,
                              Real tiling,
                              Real distance,
                              bool drawFirst,
                              const Quaternion& orientation,
                              int xsegments, int ysegments, int ySegmentsToKeep,
                              const String& groupName)
{
    if (enable)
    {
        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
#line 1534 ".\\RbxSceneManager.cpp"
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky dome material '" + materialName + "' not found.",
                "RbxSceneManager::setSkyDome");
        }
        // Make sure the material doesn't update the depth buffer
        m->setDepthWriteEnabled(false);
        // Ensure loaded
        m->load();

        mSkyDomeDrawFirst = drawFirst;

        // Create node 
        if (!mSkyDomeNode)
        {
            mSkyDomeNode = createSceneNode("SkyDomeNode");
        }
        else
        {
            mSkyDomeNode->detachAllObjects();
        }

        // Set up the dome (5 planes)
        for (int i = 0; i < 5; ++i)
        {
            MeshPtr planeMesh = createSkydomePlane((BoxPlane)i, curvature, 
                tiling, distance, orientation, xsegments, ysegments, 
                i!=BP_UP ? ySegmentsToKeep : -1, groupName);

            String entName = "SkyDomePlane" + StringConverter::toString(i);

            // Create entity 
            if (mSkyDomeEntity[i])
            {
                // destroy old one, do it by name for speed
                destroyEntity(entName);
            }
            mSkyDomeEntity[i] = createEntity(entName, planeMesh->getName());
            mSkyDomeEntity[i]->setMaterialName(m->getName());
            mSkyDomeEntity[i]->setCastShadows(false);

            // Attach to node
            mSkyDomeNode->attachObject(mSkyDomeEntity[i]);
        } // for each plane

    }
	mSkyDomeEnabled = enable;
	mSkyDomeGenParameters.skyDomeCurvature = curvature;
	mSkyDomeGenParameters.skyDomeDistance = distance;
	mSkyDomeGenParameters.skyDomeTiling = tiling;
	mSkyDomeGenParameters.skyDomeXSegments = xsegments;
	mSkyDomeGenParameters.skyDomeYSegments = ysegments;
	mSkyDomeGenParameters.skyDomeYSegments_keep = ySegmentsToKeep;
}

// OgreSceneManager.cpp:1587
MeshPtr RbxSceneManager::createSkyboxPlane(
                                      BoxPlane bp,
                                      Real distance,
                                      const Quaternion& orientation,
                                      const String& groupName)
{
    Plane plane;
    String meshName;
    Vector3 up;

    meshName = mName + "SkyBoxPlane_";
    // Set up plane equation
    plane.d = distance;
    switch(bp)
    {
    case BP_FRONT:
        plane.normal = Vector3::UNIT_Z;
        up = Vector3::UNIT_Y;
        meshName += "Front";
        break;
    case BP_BACK:
        plane.normal = -Vector3::UNIT_Z;
        up = Vector3::UNIT_Y;
        meshName += "Back";
        break;
    case BP_LEFT:
        plane.normal = Vector3::UNIT_X;
        up = Vector3::UNIT_Y;
        meshName += "Left";
        break;
    case BP_RIGHT:
        plane.normal = -Vector3::UNIT_X;
        up = Vector3::UNIT_Y;
        meshName += "Right";
        break;
    case BP_UP:
        plane.normal = -Vector3::UNIT_Y;
        up = Vector3::UNIT_Z;
        meshName += "Up";
        break;
    case BP_DOWN:
        plane.normal = Vector3::UNIT_Y;
        up = -Vector3::UNIT_Z;
        meshName += "Down";
        break;
    }
    // Modify by orientation
    plane.normal = orientation * plane.normal;
    up = orientation * up;


    // Check to see if existing plane
    MeshManager& mm = MeshManager::getSingleton();
    MeshPtr planeMesh = mm.getByName(meshName);
    if(!planeMesh.isNull())
    {
        // destroy existing
        mm.remove(planeMesh->getHandle());
    }
    // Create new
    Real planeSize = distance * 2;
    const int BOX_SEGMENTS = 1;
    planeMesh = mm.createPlane(meshName, groupName, plane, planeSize, planeSize, 
        BOX_SEGMENTS, BOX_SEGMENTS, false, 1, 1, 1, up);

    //planeMesh->_dumpContents(meshName);

    return planeMesh;

}

// OgreSceneManager.cpp:1658
MeshPtr RbxSceneManager::createSkydomePlane(
                                       BoxPlane bp,
                                       Real curvature,
                                       Real tiling,
                                       Real distance,
                                       const Quaternion& orientation,
                                       int xsegments, int ysegments, int ysegments_keep, 
                                       const String& groupName)
{

    Plane plane;
    String meshName;
    Vector3 up;

    meshName = mName + "SkyDomePlane_";
    // Set up plane equation
    plane.d = distance;
    switch(bp)
    {
    case BP_FRONT:
        plane.normal = Vector3::UNIT_Z;
        up = Vector3::UNIT_Y;
        meshName += "Front";
        break;
    case BP_BACK:
        plane.normal = -Vector3::UNIT_Z;
        up = Vector3::UNIT_Y;
        meshName += "Back";
        break;
    case BP_LEFT:
        plane.normal = Vector3::UNIT_X;
        up = Vector3::UNIT_Y;
        meshName += "Left";
        break;
    case BP_RIGHT:
        plane.normal = -Vector3::UNIT_X;
        up = Vector3::UNIT_Y;
        meshName += "Right";
        break;
    case BP_UP:
        plane.normal = -Vector3::UNIT_Y;
        up = Vector3::UNIT_Z;
        meshName += "Up";
        break;
    case BP_DOWN:
        // no down
        return MeshPtr();
    }
    // Modify by orientation
    plane.normal = orientation * plane.normal;
    up = orientation * up;

    // Check to see if existing plane
    MeshManager& mm = MeshManager::getSingleton();
    MeshPtr planeMesh = mm.getByName(meshName);
    if(!planeMesh.isNull())
    {
        // destroy existing
        mm.remove(planeMesh->getHandle());
    }
    // Create new
    Real planeSize = distance * 2;
    planeMesh = mm.createCurvedIllusionPlane(meshName, groupName, plane, 
        planeSize, planeSize, curvature, 
        xsegments, ysegments, false, 1, tiling, tiling, up, 
        orientation, HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY, HardwareBuffer::HBU_STATIC_WRITE_ONLY, 
        false, false, ysegments_keep);

    //planeMesh->_dumpContents(meshName);

    return planeMesh;

}

// OgreSceneManager.cpp:1734
void RbxSceneManager::_updateSceneGraph(Camera* cam)
{
	// Process queued needUpdate calls 
	Node::processQueuedUpdates();

    // Cascade down the graph updating transforms & world bounds
    // In this implementation, just update from the root
    // Smarter SceneManager subclasses may choose to update only
    //   certain scene graph branches
    mSceneRoot->_update(true, false);


}

// OgreSceneManager.cpp:1748
void RbxSceneManager::_findVisibleObjects(
	Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters)
{
    // Tell nodes to find, cascade down all nodes
    mSceneRoot->_findVisibleObjects(cam, getRenderQueue(), visibleBounds, true, 
        mDisplayNodes, onlyShadowCasters);

}

// OgreSceneManager.cpp:1757
void RbxSceneManager::_renderVisibleObjects(void)
{
	RenderQueueInvocationSequence* invocationSequence = 
		mCurrentViewport->_getRenderQueueInvocationSequence();
	// Use custom sequence only if we're not doing the texture shadow render
	// since texture shadow render should not be interfered with by suppressing
	// render state changes for example
	if (invocationSequence && mIlluminationStage != IRS_RENDER_TO_TEXTURE)
	{
		renderVisibleObjectsCustomSequence(invocationSequence);
	}
	else
	{
		renderVisibleObjectsDefaultSequence();
	}
}

// OgreSceneManager.cpp:1774
void RbxSceneManager::renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* seq)
{
	RenderQueueInvocationIterator invocationIt = seq->iterator();
	while (invocationIt.hasMoreElements())
	{
		RenderQueueInvocation* invocation = invocationIt.getNext();
		uint8 qId = invocation->getRenderQueueGroupID();
		// Skip this one if not to be processed
		if (!isRenderQueueToBeProcessed(qId))
			continue;


		bool repeatQueue = false;
		const String& invocationName = invocation->getInvocationName();
		RenderQueueGroup* queueGroup = getRenderQueue()->getQueueGroup(qId);
		do // for repeating queues
		{
			// Fire queue started event
			if (fireRenderQueueStarted(qId, invocationName))
			{
				// Someone requested we skip this queue
				break;
			}

			// Invoke it
			invocation->invoke(queueGroup, this);

			// Fire queue ended event
			if (fireRenderQueueEnded(qId, invocationName))
			{
				// Someone requested we repeat this queue
				repeatQueue = true;
			}
			else
			{
				repeatQueue = false;
			}
		} while (repeatQueue);


	}
}

// OgreSceneManager.cpp:1817
void RbxSceneManager::renderVisibleObjectsDefaultSequence(void)
{
    // Render each separate queue
    RenderQueue::QueueGroupIterator queueIt = getRenderQueue()->_getQueueGroupIterator();

    // NB only queues which have been created are rendered, no time is wasted
    //   parsing through non-existent queues (even though there are 10 available)

    while (queueIt.hasMoreElements())
    {
        // Get queue group id
        uint8 qId = queueIt.peekNextKey();
		RenderQueueGroup* pGroup = queueIt.getNext();
		// Skip this one if not to be processed
		if (!isRenderQueueToBeProcessed(qId))
			continue;


        bool repeatQueue = false;
        do // for repeating queues
        {
            // Fire queue started event
			if (fireRenderQueueStarted(qId, 
				mIlluminationStage == IRS_RENDER_TO_TEXTURE ? 
					RenderQueueInvocation::RENDER_QUEUE_INVOCATION_SHADOWS : 
					StringUtil::BLANK))
            {
                // Someone requested we skip this queue
                break;
            }

			_renderQueueGroupObjects(pGroup, QueuedRenderableCollection::OM_PASS_GROUP);

            // Fire queue ended event
			if (fireRenderQueueEnded(qId, 
				mIlluminationStage == IRS_RENDER_TO_TEXTURE ? 
					RenderQueueInvocation::RENDER_QUEUE_INVOCATION_SHADOWS : 
					StringUtil::BLANK))
            {
                // Someone requested we repeat this queue
                repeatQueue = true;
            }
            else
            {
                repeatQueue = false;
            }
        } while (repeatQueue);

    } // for each queue group

}

// OgreSceneManager.cpp:1869
void RbxSceneManager::renderAdditiveStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();
    LightList lightList;

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Sort the queue first
        pPriorityGrp->sort(mCameraInProgress);

        // Clear light list
        lightList.clear();

        // Render all the ambient passes first, no light iteration, no lights
        renderObjects(pPriorityGrp->getSolidsBasic(), om, false, &lightList);
        // Also render any objects which have receive shadows disabled
        renderObjects(pPriorityGrp->getSolidsNoShadowReceive(), om, true);


        // Now iterate per light
        // Iterate over lights, render all volumes to stencil
        LightList::const_iterator li, liend;
        liend = mLightsAffectingFrustum.end();

        for (li = mLightsAffectingFrustum.begin(); li != liend; ++li)
        {
            Light* l = *li;
            // Set light state

            if (l->getCastShadows())
            {
                // Clear stencil
                mDestRenderSystem->clearFrameBuffer(FBT_STENCIL);
                renderShadowVolumesToStencil(l, mCameraInProgress);
                // turn stencil check on
                mDestRenderSystem->setStencilCheckEnabled(true);
                // NB we render where the stencil is equal to zero to render lit areas
                mDestRenderSystem->setStencilBufferParams(CMPF_EQUAL, 0);
            }

            // render lighting passes for this light
            if (lightList.empty())
                lightList.push_back(l);
            else
                lightList[0] = l;
            renderObjects(pPriorityGrp->getSolidsDiffuseSpecular(), om, false, &lightList);

            // Reset stencil params
            mDestRenderSystem->setStencilBufferParams();
            mDestRenderSystem->setStencilCheckEnabled(false);
            mDestRenderSystem->_setDepthBufferParams();

        }// for each light


        // Now render decal passes, no need to set lights as lighting will be disabled
        renderObjects(pPriorityGrp->getSolidsDecal(), om, false);


    }// for each priority

    // Iterate again - variable name changed to appease gcc.
    RenderQueueGroup::PriorityMapIterator groupIt2 = pGroup->getIterator();
    while (groupIt2.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt2.getNext();

        // Do transparents (always descending sort)
        renderObjects(pPriorityGrp->getTransparents(), 
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);

    }// for each priority


}

// OgreSceneManager.cpp:1949
void RbxSceneManager::renderModulativeStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
    /* For each light, we need to render all the solids from each group, 
    then do the modulative shadows, then render the transparents from
    each group.
    Now, this means we are going to reorder things more, but that it required
    if the shadows are to look correct. The overall order is preserved anyway,
    it's just that all the transparents are at the end instead of them being
    interleaved as in the normal rendering loop. 
    */
    // Iterate through priorities
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Sort the queue first
        pPriorityGrp->sort(mCameraInProgress);

        // Do (shadowable) solids
        renderObjects(pPriorityGrp->getSolidsBasic(), om, true);
    }


    // Iterate over lights, render all volumes to stencil
    LightList::const_iterator li, liend;
    liend = mLightsAffectingFrustum.end();

    for (li = mLightsAffectingFrustum.begin(); li != liend; ++li)
    {
        Light* l = *li;
        if (l->getCastShadows())
        {
            // Clear stencil
            mDestRenderSystem->clearFrameBuffer(FBT_STENCIL);
            renderShadowVolumesToStencil(l, mCameraInProgress);
            // render full-screen shadow modulator for all lights
            _setPass(mShadowModulativePass);
            // turn stencil check on
            mDestRenderSystem->setStencilCheckEnabled(true);
            // NB we render where the stencil is not equal to zero to render shadows, not lit areas
            mDestRenderSystem->setStencilBufferParams(CMPF_NOT_EQUAL, 0);
            renderSingleObject(mFullScreenQuad, mShadowModulativePass, false);
            // Reset stencil params
            mDestRenderSystem->setStencilBufferParams();
            mDestRenderSystem->setStencilCheckEnabled(false);
            mDestRenderSystem->_setDepthBufferParams();
        }

    }// for each light

    // Iterate again - variable name changed to appease gcc.
    RenderQueueGroup::PriorityMapIterator groupIt2 = pGroup->getIterator();
    while (groupIt2.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt2.getNext();

        // Do non-shadowable solids
        renderObjects(pPriorityGrp->getSolidsNoShadowReceive(), om, true);

    }// for each priority


    // Iterate again - variable name changed to appease gcc.
    RenderQueueGroup::PriorityMapIterator groupIt3 = pGroup->getIterator();
    while (groupIt3.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt3.getNext();

        // Do transparents (always descending sort)
        renderObjects(pPriorityGrp->getTransparents(), 
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);

    }// for each priority

}

// OgreSceneManager.cpp:2029
void RbxSceneManager::renderTextureShadowCasterQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
    static LightList nullLightList;
    // This is like the basic group render, except we skip all transparents
    // and we also render any non-shadowed objects
    // Note that non-shadow casters will have already been eliminated during
    // _findVisibleObjects

    // Iterate through priorities
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();

    // Override auto param ambient to force vertex programs and fixed function to 
	if (isShadowTechniqueAdditive())
	{
		// Use simple black / white mask if additive
		mAutoParamDataSource.setAmbientLightColour(ColourValue::Black);
		mDestRenderSystem->setAmbientLight(0, 0, 0);
	}
	else
	{
		// Use shadow colour as caster colour if modulative
		mAutoParamDataSource.setAmbientLightColour(mShadowColour);
		mDestRenderSystem->setAmbientLight(mShadowColour.r, mShadowColour.g, mShadowColour.b);
	}

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Sort the queue first
        pPriorityGrp->sort(mCameraInProgress);

        // Do solids, override light list incase any vertex programs use them
        renderObjects(pPriorityGrp->getSolidsBasic(), om, false, &nullLightList);
        renderObjects(pPriorityGrp->getSolidsNoShadowReceive(), om, false, &nullLightList);
		// Do transparents that cast shadows
		renderTransparentShadowCasterObjects(
				pPriorityGrp->getTransparents(), 
				QueuedRenderableCollection::OM_SORT_DESCENDING, 
				false, &nullLightList);


    }// for each priority

    // reset ambient light
    mAutoParamDataSource.setAmbientLightColour(mAmbientLight);
    mDestRenderSystem->setAmbientLight(mAmbientLight.r, mAmbientLight.g, mAmbientLight.b);
}

// OgreSceneManager.cpp:2080
void RbxSceneManager::renderModulativeTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
    /* For each light, we need to render all the solids from each group, 
    then do the modulative shadows, then render the transparents from
    each group.
    Now, this means we are going to reorder things more, but that it required
    if the shadows are to look correct. The overall order is preserved anyway,
    it's just that all the transparents are at the end instead of them being
    interleaved as in the normal rendering loop. 
    */
    // Iterate through priorities
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Sort the queue first
        pPriorityGrp->sort(mCameraInProgress);

        // Do solids
        renderObjects(pPriorityGrp->getSolidsBasic(), om, true);
        renderObjects(pPriorityGrp->getSolidsNoShadowReceive(), om, true);
    }


    // Iterate over lights, render received shadows
    // only perform this if we're in the 'normal' render stage, to avoid
    // doing it during the render to texture
    if (mIlluminationStage == IRS_NONE)
    {
        mIlluminationStage = IRS_RENDER_RECEIVER_PASS;

        LightList::iterator i, iend;
        ShadowTextureList::iterator si, siend;
        iend = mLightsAffectingFrustum.end();
        siend = mShadowTextures.end();
        for (i = mLightsAffectingFrustum.begin(), si = mShadowTextures.begin();
            i != iend && si != siend; ++i)
        {
            Light* l = *i;

            if (!l->getCastShadows())
                continue;

			// Store current shadow texture
            mCurrentShadowTexture = si->getPointer();
			// Get camera for current shadow texture
            Camera *cam = mCurrentShadowTexture->getBuffer()->getRenderTarget()->getViewport(0)->getCamera();
            // Hook up receiver texture
			Pass* targetPass = mShadowTextureCustomReceiverPass ?
				mShadowTextureCustomReceiverPass : mShadowReceiverPass;
			targetPass->getTextureUnitState(0)->setTextureName(
				mCurrentShadowTexture->getName());
			// Hook up projection frustum if fixed-function, but also need to
			// disable it explicitly for program pipeline.
			TextureUnitState* texUnit = targetPass->getTextureUnitState(0);
			texUnit->setProjectiveTexturing(!targetPass->hasVertexProgram(), cam);
			// clamp to border colour in case this is a custom material
			texUnit->setTextureAddressingMode(TextureUnitState::TAM_BORDER);
			texUnit->setTextureBorderColour(ColourValue::White);

            mAutoParamDataSource.setTextureProjector(cam, 0);
            // if this light is a spotlight, we need to add the spot fader layer
			// BUT not if using a custom projection matrix, since then it will be
			// inappropriately shaped most likely
            if (l->getType() == Light::LT_SPOTLIGHT)
            {
				// remove all TUs except 0 & 1 
				// (only an issue if additive shadows have been used)
				while(targetPass->getNumTextureUnitStates() > 2)
					targetPass->removeTextureUnitState(2);

                // Add spot fader if not present already
                if (targetPass->getNumTextureUnitStates() == 2 && 
					targetPass->getTextureUnitState(1)->getTextureName() == 
						"spot_shadow_fade.png")
				{
					// Just set 
					TextureUnitState* t = 
						targetPass->getTextureUnitState(1);
					t->setProjectiveTexturing(!targetPass->hasVertexProgram(), cam);
				}
                else
				{
					// Remove any non-conforming spot layers
					while(targetPass->getNumTextureUnitStates() > 1)
						targetPass->removeTextureUnitState(1);

                    TextureUnitState* t = 
                        targetPass->createTextureUnitState("spot_shadow_fade.png");
                    t->setProjectiveTexturing(!targetPass->hasVertexProgram(), cam);
                    t->setColourOperation(LBO_ADD);
                    t->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
                }
            }
            else 
            {
				// remove all TUs except 0 including spot
				while(targetPass->getNumTextureUnitStates() > 1)
	                targetPass->removeTextureUnitState(1);

            }
			// Set lighting / blending modes
			targetPass->setSceneBlending(SBF_DEST_COLOUR, SBF_ZERO);
			targetPass->setLightingEnabled(false);

            targetPass->_load();

			// Fire pre-receiver event
			fireShadowTexturesPreReceiver(l, cam);

            renderTextureShadowReceiverQueueGroupObjects(pGroup, om);

            ++si;

        }// for each light

        mIlluminationStage = IRS_NONE;

    }

    // Iterate again - variable name changed to appease gcc.
    RenderQueueGroup::PriorityMapIterator groupIt3 = pGroup->getIterator();
    while (groupIt3.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt3.getNext();

        // Do transparents (always descending)
        renderObjects(pPriorityGrp->getTransparents(), 
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);

    }// for each priority

}

// OgreSceneManager.cpp:2218
void RbxSceneManager::renderAdditiveTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
	RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();
	LightList lightList;

	while (groupIt.hasMoreElements())
	{
		RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

		// Sort the queue first
		pPriorityGrp->sort(mCameraInProgress);

		// Clear light list
		lightList.clear();

		// Render all the ambient passes first, no light iteration, no lights
		renderObjects(pPriorityGrp->getSolidsBasic(), om, false, &lightList);
		// Also render any objects which have receive shadows disabled
		renderObjects(pPriorityGrp->getSolidsNoShadowReceive(), om, true);


		// only perform this next part if we're in the 'normal' render stage, to avoid
		// doing it during the render to texture
		if (mIlluminationStage == IRS_NONE)
		{
			// Iterate over lights, render masked
			LightList::const_iterator li, liend;
			ShadowTextureList::iterator si, siend;
			liend = mLightsAffectingFrustum.end();
			siend = mShadowTextures.end();
            si = mShadowTextures.begin();

			for (li = mLightsAffectingFrustum.begin(); li != liend; ++li)
			{
				Light* l = *li;

				if (l->getCastShadows() && si != siend)
				{
					// Store current shadow texture
					mCurrentShadowTexture = si->getPointer();
					// Get camera for current shadow texture
					Camera *cam = mCurrentShadowTexture->getBuffer()->getRenderTarget()->getViewport(0)->getCamera();
					// Hook up receiver texture
					Pass* targetPass = mShadowTextureCustomReceiverPass ?
						mShadowTextureCustomReceiverPass : mShadowReceiverPass;
					targetPass->getTextureUnitState(0)->setTextureName(
						mCurrentShadowTexture->getName());
					// Hook up projection frustum if fixed-function, but also need to
					// disable it explicitly for program pipeline.
					TextureUnitState* texUnit = targetPass->getTextureUnitState(0);
					texUnit->setProjectiveTexturing(!targetPass->hasVertexProgram(), cam);
					// clamp to border colour in case this is a custom material
					texUnit->setTextureAddressingMode(TextureUnitState::TAM_BORDER);
					texUnit->setTextureBorderColour(ColourValue::White);
					mAutoParamDataSource.setTextureProjector(cam, 0);
					// Remove any spot fader layer
					if (targetPass->getNumTextureUnitStates() > 1 && 
						targetPass->getTextureUnitState(1)->getTextureName() 
							== "spot_shadow_fade.png")
					{
						// remove spot fader layer (should only be there if
						// we previously used modulative shadows)
						targetPass->removeTextureUnitState(1);
					}
					// Set lighting / blending modes
					targetPass->setSceneBlending(SBF_ONE, SBF_ONE);
					targetPass->setLightingEnabled(true);
					targetPass->_load();

					// increment shadow texture since used
					++si;

					mIlluminationStage = IRS_RENDER_RECEIVER_PASS;

				}
				else
				{
					mIlluminationStage = IRS_NONE;

				}

                // render lighting passes for this light
                if (lightList.empty())
                    lightList.push_back(l);
                else
                    lightList[0] = l;
				renderObjects(pPriorityGrp->getSolidsDiffuseSpecular(), om, false, &lightList);

			}// for each light

			mIlluminationStage = IRS_NONE;

			// Now render decal passes, no need to set lights as lighting will be disabled
			renderObjects(pPriorityGrp->getSolidsDecal(), om, false);

		}


	}// for each priority

	// Iterate again - variable name changed to appease gcc.
	RenderQueueGroup::PriorityMapIterator groupIt2 = pGroup->getIterator();
	while (groupIt2.hasMoreElements())
	{
		RenderPriorityGroup* pPriorityGrp = groupIt2.getNext();

		// Do transparents (always descending sort)
		renderObjects(pPriorityGrp->getTransparents(), 
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);

	}// for each priority

}

// OgreSceneManager.cpp:2334
void RbxSceneManager::renderTextureShadowReceiverQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om)
{
    static LightList nullLightList;

    // Iterate through priorities
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();

    // Override auto param ambient to force vertex programs to go full-bright
    mAutoParamDataSource.setAmbientLightColour(ColourValue::White);
    mDestRenderSystem->setAmbientLight(1, 1, 1);

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Do solids, override light list incase any vertex programs use them
        renderObjects(pPriorityGrp->getSolidsBasic(), om, false, &nullLightList);

        // Don't render transparents or passes which have shadow receipt disabled

    }// for each priority

    // reset ambient
    mAutoParamDataSource.setAmbientLightColour(mAmbientLight);
    mDestRenderSystem->setAmbientLight(mAmbientLight.r, mAmbientLight.g, mAmbientLight.b);

}

// OgreSceneManager.cpp:2364
void RbxSceneManager::SceneMgrQueuedRenderableVisitor::visit(const Renderable* r)
{
	// Give SM a chance to eliminate
	if (targetSceneMgr->validateRenderableForRendering(mUsedPass, r))
	{
		// Render a single object, this will set up auto params if required
		targetSceneMgr->renderSingleObject(r, mUsedPass, autoLights, manualLightList);
	}
}

// OgreSceneManager.cpp:2374
bool RbxSceneManager::SceneMgrQueuedRenderableVisitor::visit(const Pass* p)
{
	// Give SM a chance to eliminate this pass
	if (!targetSceneMgr->validatePassForRendering(p))
		return false;

	// Set pass, store the actual one used
	mUsedPass = targetSceneMgr->_setPass(p);


	return true;
}

// OgreSceneManager.cpp:2387
void RbxSceneManager::SceneMgrQueuedRenderableVisitor::visit(const RenderablePass* rp)
{
	// Skip this one if we're in transparency cast shadows mode & it doesn't
	// Don't need to implement this one in the other visit methods since
	// transparents are never grouped, always sorted
	if (transparentShadowCastersMode && 
		!rp->pass->getParent()->getParent()->getTransparencyCastsShadows())
		return;

	// Give SM a chance to eliminate
	if (targetSceneMgr->validateRenderableForRendering(rp->pass, rp->renderable))
	{
		mUsedPass = targetSceneMgr->_setPass(rp->pass);
		targetSceneMgr->renderSingleObject(rp->renderable, mUsedPass, autoLights, 
			manualLightList);
	}
}

// OgreSceneManager.cpp:2405
bool RbxSceneManager::validatePassForRendering(const Pass* pass)
{
    // Bypass if we're doing a texture shadow render and 
    // this pass is after the first (only 1 pass needed for shadow texture render, and 
	// one pass for shadow texture receive for modulative technique)
	// Also bypass if passes above the first if render state changes are
	// suppressed since we're not actually using this pass data anyway
    if (!mSuppressShadows && mCurrentViewport->getShadowsEnabled() &&
		((isShadowTechniqueModulative() && mIlluminationStage == IRS_RENDER_RECEIVER_PASS)
		 || mIlluminationStage == IRS_RENDER_TO_TEXTURE || mSuppressRenderStateChanges) && 
        pass->getIndex() > 0)
    {
        return false;
    }

    return true;
}

// OgreSceneManager.cpp:2423
bool RbxSceneManager::validateRenderableForRendering(const Pass* pass, const Renderable* rend)
{
    // Skip this renderable if we're doing modulative texture shadows, it casts shadows
    // and we're doing the render receivers pass and we're not self-shadowing
	// also if pass number > 0
    if (!mSuppressShadows && mCurrentViewport->getShadowsEnabled() &&
		isShadowTechniqueTextureBased())
	{
		if (mIlluminationStage == IRS_RENDER_RECEIVER_PASS && 
			rend->getCastsShadows() && !mShadowTextureSelfShadow)
		{
			return false;
		}
		// Some duplication here with validatePassForRendering, for transparents
		if (((isShadowTechniqueModulative() && mIlluminationStage == IRS_RENDER_RECEIVER_PASS)
			|| mIlluminationStage == IRS_RENDER_TO_TEXTURE || mSuppressRenderStateChanges) && 
			pass->getIndex() > 0)
		{
			return false;
		}
    }

    return true;

}

// OgreSceneManager.cpp:2449
void RbxSceneManager::renderObjects(const QueuedRenderableCollection& objs, 
								 QueuedRenderableCollection::OrganisationMode om, 
								 bool doLightIteration, 
                                 const LightList* manualLightList)
{
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
	// Use visitor
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, om);
}

// OgreSceneManager.cpp:2461
void RbxSceneManager::_renderQueueGroupObjects(RenderQueueGroup* pGroup, 
										   QueuedRenderableCollection::OrganisationMode om)
{
	bool doShadows = 
		pGroup->getShadowsEnabled() && 
		mCurrentViewport->getShadowsEnabled() && 
		!mSuppressShadows && !mSuppressRenderStateChanges;
	
    if (doShadows && mShadowTechnique == SHADOWTYPE_STENCIL_ADDITIVE)
    {
        // Additive stencil shadows in use
        renderAdditiveStencilShadowedQueueGroupObjects(pGroup, om);
    }
    else if (doShadows && mShadowTechnique == SHADOWTYPE_STENCIL_MODULATIVE)
    {
        // Modulative stencil shadows in use
        renderModulativeStencilShadowedQueueGroupObjects(pGroup, om);
    }
    else if (isShadowTechniqueTextureBased())
    {
        // Modulative texture shadows in use
        if (mIlluminationStage == IRS_RENDER_TO_TEXTURE)
        {
            // Shadow caster pass
            if (mCurrentViewport->getShadowsEnabled() &&
                !mSuppressShadows && !mSuppressRenderStateChanges)
            {
                renderTextureShadowCasterQueueGroupObjects(pGroup, om);
            }
        }
        else
        {
            // Ordinary + receiver pass
            if (doShadows && !isShadowTechniqueIntegrated())
			{
				// Receiver pass(es)
				if (isShadowTechniqueAdditive())
				{
					// Auto-additive
					renderAdditiveTextureShadowedQueueGroupObjects(pGroup, om);
				}
				else
				{
					// Modulative
            		renderModulativeTextureShadowedQueueGroupObjects(pGroup, om);
				}
			}
			else
				renderBasicQueueGroupObjects(pGroup, om);
        }
    }
    else
    {
        // No shadows, ordinary pass
        renderBasicQueueGroupObjects(pGroup, om);
    }


}

// OgreSceneManager.cpp:2545
void RbxSceneManager::renderTransparentShadowCasterObjects(
	const QueuedRenderableCollection& objs, 
	QueuedRenderableCollection::OrganisationMode om, bool doLightIteration,
	const LightList* manualLightList)
{
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = true;
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	
	// Sort descending (transparency)
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, 
		QueuedRenderableCollection::OM_SORT_DESCENDING);

	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
}

// OgreSceneManager.cpp:2873
ViewPoint RbxSceneManager::getSuggestedViewpoint(bool random)
{
    // By default return the origin
    ViewPoint vp;
    vp.position = Vector3::ZERO;
    vp.orientation = Quaternion::IDENTITY;
    return vp;
}

// OgreSceneManager.cpp:2891
FogMode RbxSceneManager::getFogMode(void) const
{
    return mFogMode;
}

// OgreSceneManager.cpp:2896
const ColourValue& RbxSceneManager::getFogColour(void) const
{
    return mFogColour;
}

// OgreSceneManager.cpp:2901
Real RbxSceneManager::getFogStart(void) const
{
    return mFogStart;
}

// OgreSceneManager.cpp:2906
Real RbxSceneManager::getFogEnd(void) const
{
    return mFogEnd;
}

// OgreSceneManager.cpp:2911
Real RbxSceneManager::getFogDensity(void) const
{
    return mFogDensity;
}

// OgreSceneManager.cpp:2916
BillboardSet* RbxSceneManager::createBillboardSet(const String& name, unsigned int poolSize)
{
	NameValuePairList params;
	params["poolSize"] = StringConverter::toString(poolSize);
	return static_cast<BillboardSet*>(
		createMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME, &params));
}

// OgreSceneManager.cpp:2924
BillboardSet* RbxSceneManager::getBillboardSet(const String& name) const
{
	return static_cast<BillboardSet*>(
		getMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME));
}

// OgreSceneManager.cpp:2930
bool RbxSceneManager::hasBillboardSet(const String& name) const
{
	return hasMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:2936
void RbxSceneManager::destroyBillboardSet(BillboardSet* set)
{
	destroyMovableObject(set);
}

// OgreSceneManager.cpp:2941
void RbxSceneManager::destroyBillboardSet(const String& name)
{
	destroyMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}

// OgreSceneManager.cpp:2946
void RbxSceneManager::setDisplaySceneNodes(bool display)
{
    mDisplayNodes = display;
}

// OgreSceneManager.cpp:2951
Animation* RbxSceneManager::createAnimation(const String& name, Real length)
{
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

    // Check name not used
    if (mAnimationsList.find(name) != mAnimationsList.end())
    {
#line 2988 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "An animation with the name " + name + " already exists",
            "RbxSceneManager::createAnimation" );
    }

    Animation* pAnim = new Animation(name, length);
    mAnimationsList[name] = pAnim;
    return pAnim;
}

// OgreSceneManager.cpp:2969
Animation* RbxSceneManager::getAnimation(const String& name) const
{
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	AnimationList::const_iterator i = mAnimationsList.find(name);
    if (i == mAnimationsList.end())
    {
#line 3006 ".\\RbxSceneManager.cpp"
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find animation with name " + name, 
            "RbxSceneManager::getAnimation");
    }
    return i->second;
}

// OgreSceneManager.cpp:2983
bool RbxSceneManager::hasAnimation(const String& name) const
{
	OGRE_LOCK_MUTEX(mAnimationsListMutex)
	return (mAnimationsList.find(name) != mAnimationsList.end());
}

// OgreSceneManager.cpp:2989
void RbxSceneManager::destroyAnimation(const String& name)
{
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	// Also destroy any animation states referencing this animation
	mAnimationStates.removeAnimationState(name);

	AnimationList::iterator i = mAnimationsList.find(name);
	if (i == mAnimationsList.end())
	{
#line 3029 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"Cannot find animation with name " + name, 
			"RbxSceneManager::getAnimation");
	}

	// Free memory
	delete i->second;

	mAnimationsList.erase(i);

}

// OgreSceneManager.cpp:3011
void RbxSceneManager::destroyAllAnimations(void)
{
	OGRE_LOCK_MUTEX(mAnimationsListMutex)
    // Destroy all states too, since they cannot reference destroyed animations
    destroyAllAnimationStates();

	AnimationList::iterator i;
	for (i = mAnimationsList.begin(); i != mAnimationsList.end(); ++i)
	{
		// destroy
		delete i->second;
	}
	mAnimationsList.clear();
}

// OgreSceneManager.cpp:3026
AnimationState* RbxSceneManager::createAnimationState(const String& animName)
{
    // Get animation, this will throw an exception if not found
    Animation* anim = getAnimation(animName);

    // Create new state
	return mAnimationStates.createAnimationState(animName, 0, anim->getLength());

}

// OgreSceneManager.cpp:3036
AnimationState* RbxSceneManager::getAnimationState(const String& animName) const
{
	return mAnimationStates.getAnimationState(animName);

}

// OgreSceneManager.cpp:3042
bool RbxSceneManager::hasAnimationState(const String& name) const
{
	return mAnimationStates.hasAnimationState(name);
}

// OgreSceneManager.cpp:3047
void RbxSceneManager::destroyAnimationState(const String& name)
{
	mAnimationStates.removeAnimationState(name);
}

// OgreSceneManager.cpp:3052
void RbxSceneManager::destroyAllAnimationStates(void)
{
    mAnimationStates.removeAllAnimationStates();
}

// OgreSceneManager.cpp:3138
void RbxSceneManager::useRenderableViewProjMode(const Renderable* pRend)
{
    // Check view matrix
    bool useIdentityView = pRend->getUseIdentityView();
    if (useIdentityView)
    {
        // Using identity view now, change it
        mDestRenderSystem->_setViewMatrix(Matrix4::IDENTITY);
        mResetIdentityView = true;
    }

    bool useIdentityProj = pRend->getUseIdentityProjection();
    if (useIdentityProj)
    {
        // Use identity projection matrix, still need to take RS depth into account.
        Matrix4 mat;
        mDestRenderSystem->_convertProjectionMatrix(Matrix4::IDENTITY, mat);
        mDestRenderSystem->_setProjectionMatrix(mat);

        mResetIdentityProj = true;
    }

    
}

// OgreSceneManager.cpp:3163
void RbxSceneManager::resetViewProjMode(void)
{
    if (mResetIdentityView)
    {
        // Coming back to normal from identity view
        mDestRenderSystem->_setViewMatrix(mCameraInProgress->getViewMatrix(true));
        mResetIdentityView = false;
    }
    
    if (mResetIdentityProj)
    {
        // Coming back from flat projection
        mDestRenderSystem->_setProjectionMatrix(mCameraInProgress->getProjectionMatrixRS());
        mResetIdentityProj = false;
    }
    

}

// OgreSceneManager.cpp:3236
void RbxSceneManager::addRenderQueueListener(RenderQueueListener* newListener)
{
    mRenderQueueListeners.push_back(newListener);
}

// OgreSceneManager.cpp:3241
void RbxSceneManager::removeRenderQueueListener(RenderQueueListener* delListener)
{
    RenderQueueListenerList::iterator i, iend;
    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        if (*i == delListener)
        {
            mRenderQueueListeners.erase(i);
            break;
        }
    }

}

// OgreSceneManager.cpp:3256
void RbxSceneManager::addShadowListener(ShadowListener* newListener)
{
    mShadowListeners.push_back(newListener);
}

// OgreSceneManager.cpp:3261
void RbxSceneManager::removeShadowListener(ShadowListener* delListener)
{
    ShadowListenerList::iterator i, iend;
    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        if (*i == delListener)
        {
            mShadowListeners.erase(i);
            break;
        }
    }

}

// OgreSceneManager.cpp:3276
bool RbxSceneManager::fireRenderQueueStarted(uint8 id, const String& invocation)
{
    RenderQueueListenerList::iterator i, iend;
    bool skip = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueStarted(id, invocation, skip);
    }
    return skip;
}

// OgreSceneManager.cpp:3289
bool RbxSceneManager::fireRenderQueueEnded(uint8 id, const String& invocation)
{
    RenderQueueListenerList::iterator i, iend;
    bool repeat = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueEnded(id, invocation, repeat);
    }
    return repeat;
}

// OgreSceneManager.cpp:3302
void RbxSceneManager::fireShadowTexturesUpdated(size_t numberOfShadowTextures)
{
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTexturesUpdated(numberOfShadowTextures);
    }
}

// OgreSceneManager.cpp:3313
void RbxSceneManager::fireShadowTexturesPreCaster(Light* light, Camera* camera)
{
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureCasterPreViewProj(light, camera);
    }
}

// OgreSceneManager.cpp:3324
void RbxSceneManager::fireShadowTexturesPreReceiver(Light* light, Frustum* f)
{
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureReceiverPreViewProj(light, f);
    }
}

// OgreSceneManager.cpp:3335
void RbxSceneManager::setViewport(Viewport* vp)
{
    mCurrentViewport = vp;
    // Set viewport in render system
    mDestRenderSystem->_setViewport(vp);
	// Set the active material scheme for this viewport
	MaterialManager::getSingleton().setActiveScheme(vp->getMaterialScheme());
}

// OgreSceneManager.cpp:3344
void RbxSceneManager::showBoundingBoxes(bool bShow) 
{
    mShowBoundingBoxes = bShow;
}

// OgreSceneManager.cpp:3349
bool RbxSceneManager::getShowBoundingBoxes() const
{
    return mShowBoundingBoxes;
}

// OgreSceneManager.cpp:3354
void RbxSceneManager::_notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack)
{
    if (autoTrack)
    {
        mAutoTrackingSceneNodes.insert(node);
    }
    else
    {
        mAutoTrackingSceneNodes.erase(node);
    }
}

// OgreSceneManager.cpp:3366
void RbxSceneManager::setShadowTechnique(ShadowTechnique technique)
{
    mShadowTechnique = technique;
    if (isShadowTechniqueStencilBased())
    {
        // Firstly check that we  have a stencil
        // Otherwise forget it
        if (!mDestRenderSystem->getCapabilities()->hasCapability(RSC_HWSTENCIL))
        {
            LogManager::getSingleton().logMessage(
                "WARNING: Stencil shadows were requested, but this device does not "
                "have a hardware stencil. Shadows disabled.");
            mShadowTechnique = SHADOWTYPE_NONE;
        }
        else if (mShadowIndexBuffer.isNull())
        {
            // Create an estimated sized shadow index buffer
            mShadowIndexBuffer = HardwareBufferManager::getSingleton().
                createIndexBuffer(HardwareIndexBuffer::IT_16BIT, 
                mShadowIndexBufferSize, 
                HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE, 
                false);
            // tell all meshes to prepare shadow volumes
            MeshManager::getSingleton().setPrepareAllMeshesForShadowVolumes(true);
        }
	}

    if (!isShadowTechniqueTextureBased())
    {
        // Destroy shadow textures to optimise resource usage
        destroyShadowTextures();
    }
	else
	{
		// assure no custom shadow matrix is used accidentally in case we switch
		// from a custom shadow mapping type to a non-custom (uniform shadow mapping)
		for ( size_t i = 0; i < mShadowTextureCameras.size(); ++i )
		{
			Camera* texCam = mShadowTextureCameras[i];

			texCam->setCustomViewMatrix(false);
			texCam->setCustomProjectionMatrix(false);
		}
	}

}

// OgreSceneManager.cpp:3413
void RbxSceneManager::_suppressShadows(bool suppress)
{
	mSuppressShadows = suppress;
}

// OgreSceneManager.cpp:3418
void RbxSceneManager::_suppressRenderStateChanges(bool suppress)
{
	mSuppressRenderStateChanges = suppress;
}

// OgreSceneManager.cpp:3423
void RbxSceneManager::updateRenderQueueSplitOptions(void)
{
	if (isShadowTechniqueStencilBased())
	{
		// Casters can always be receivers
		getRenderQueue()->setShadowCastersCannotBeReceivers(false);
	}
	else // texture based
	{
		getRenderQueue()->setShadowCastersCannotBeReceivers(!mShadowTextureSelfShadow);
	}

	if (isShadowTechniqueAdditive() && !isShadowTechniqueIntegrated()
		&& mCurrentViewport->getShadowsEnabled())
	{
		// Additive lighting, we need to split everything by illumination stage
		getRenderQueue()->setSplitPassesByLightingType(true);
	}
	else
	{
		getRenderQueue()->setSplitPassesByLightingType(false);
	}

	if (isShadowTechniqueInUse() && mCurrentViewport->getShadowsEnabled()
		&& !isShadowTechniqueIntegrated())
	{
		// Tell render queue to split off non-shadowable materials
		getRenderQueue()->setSplitNoShadowPasses(true);
	}
	else
	{
		getRenderQueue()->setSplitNoShadowPasses(false);
	}


}

// OgreSceneManager.cpp:3460
void RbxSceneManager::updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, 
	bool suppressShadows, bool suppressRenderState)
{
	if (isShadowTechniqueStencilBased())
	{
		// Casters can always be receivers
		group->setShadowCastersCannotBeReceivers(false);
	}
	else if (isShadowTechniqueTextureBased()) 
	{
		group->setShadowCastersCannotBeReceivers(!mShadowTextureSelfShadow);
	}

	if (!suppressShadows && mCurrentViewport->getShadowsEnabled() &&
		isShadowTechniqueAdditive() && !isShadowTechniqueIntegrated())
	{
		// Additive lighting, we need to split everything by illumination stage
		group->setSplitPassesByLightingType(true);
	}
	else
	{
		group->setSplitPassesByLightingType(false);
	}

	if (!suppressShadows && mCurrentViewport->getShadowsEnabled() 
		&& isShadowTechniqueInUse())
	{
		// Tell render queue to split off non-shadowable materials
		group->setSplitNoShadowPasses(true);
	}
	else
	{
		group->setSplitNoShadowPasses(false);
	}


}

// OgreSceneManager.cpp:3498
void RbxSceneManager::_notifyLightsDirty(void)
{
    ++mLightsDirtyCounter;
}

// OgreSceneManager.cpp:3520
void RbxSceneManager::findLightsAffectingFrustum(const Camera* camera)
{
    // Basic iteration for this SM

    MovableObjectCollection* lights =
        getMovableObjectCollection(LightFactory::FACTORY_TYPE_NAME);


	{
		OGRE_LOCK_MUTEX(lights->mutex)

		// Pre-allocate memory
		mTestLightInfos.clear();
		mTestLightInfos.reserve(lights->map.size());

		MovableObjectIterator it(lights->map.begin(), lights->map.end());

		while(it.hasMoreElements())
		{
			Light* l = static_cast<Light*>(it.getNext());
			if (l->isVisible())
			{
				LightInfo lightInfo;
				lightInfo.light = l;
				lightInfo.type = l->getType();
				if (lightInfo.type == Light::LT_DIRECTIONAL)
				{
					// Always visible
					lightInfo.position = Vector3::ZERO;
					lightInfo.range = 0;
					mTestLightInfos.push_back(lightInfo);
				}
				else
				{
					// NB treating spotlight as point for simplicity
					// Just see if the lights attenuation range is within the frustum
					lightInfo.range = l->getAttenuationRange();
					lightInfo.position = l->getDerivedPosition();
					Sphere sphere(lightInfo.position, lightInfo.range);
					if (camera->isVisible(sphere))
					{
						mTestLightInfos.push_back(lightInfo);
					}
				}
			}
		}
	} // release lock on lights collection

    // Update lights affecting frustum if changed
    if (mCachedLightInfos != mTestLightInfos)
    {
        mLightsAffectingFrustum.resize(mTestLightInfos.size());
        LightInfoList::const_iterator i;
        LightList::iterator j = mLightsAffectingFrustum.begin();
        for (i = mTestLightInfos.begin(); i != mTestLightInfos.end(); ++i, ++j)
        {
            *j = i->light;
			// add cam distance for sorting if texture shadows
			if (isShadowTechniqueTextureBased())
			{
				(*j)->tempSquareDist = 
					(camera->getDerivedPosition() - (*j)->getDerivedPosition()).squaredLength();
			}
        }

		// Sort the lights if using texture shadows, since the first 'n' will be
		// used to generate shadow textures and we should pick the most appropriate
		if (isShadowTechniqueTextureBased())
		{
			// Allow a ShadowListener to override light sorting
			// Reverse iterate so last takes precedence
			bool overridden = false;
			for (ShadowListenerList::reverse_iterator ri = mShadowListeners.rbegin();
				ri != mShadowListeners.rend(); ++ri)
			{
				overridden = (*ri)->sortLightsAffectingFrustum(mLightsAffectingFrustum);
				if (overridden)
					break;
			}
			if (!overridden)
			{
				// default sort (stable to preserve directional light ordering
				std::stable_sort(
					mLightsAffectingFrustum.begin(), mLightsAffectingFrustum.end(), 
					lightsForShadowTextureLess());
			}
			
		}

        // Use swap instead of copy operator for efficiently
        mCachedLightInfos.swap(mTestLightInfos);

        // notify light dirty, so all movable objects will re-populate
        // their light list next time
        _notifyLightsDirty();
    }

}

// OgreSceneManager.cpp:3619
bool RbxSceneManager::ShadowCasterSceneQueryListener::queryResult(
    MovableObject* object)
{
    if (object->getCastShadows() && object->isVisible() && 
		mSceneMgr->isRenderQueueToBeProcessed(object->getRenderQueueGroup()) &&
		// objects need an edge list to cast shadows (shadow volumes only)
		((mSceneMgr->getShadowTechnique() & SHADOWDETAILTYPE_TEXTURE) ||
		 (mSceneMgr->getShadowTechnique() & SHADOWDETAILTYPE_STENCIL) && object->hasEdgeList()
		)
	   )
    {
        if (mFarDistSquared)
        {
            // Check object is within the shadow far distance
            Vector3 toObj = object->getParentNode()->_getDerivedPosition() 
                - mCamera->getDerivedPosition();
            Real radius = object->getWorldBoundingSphere().getRadius();
            Real dist =  toObj.squaredLength();               
            if (dist - (radius * radius) > mFarDistSquared)
            {
                // skip, beyond max range
                return true;
            }
        }

        // If the object is in the frustum, we can always see the shadow
        if (mCamera->isVisible(object->getWorldBoundingBox()))
        {
            mCasterList->push_back(object);
            return true;
        }

        // Otherwise, object can only be casting a shadow into our view if
        // the light is outside the frustum (or it's a directional light, 
        // which are always outside), and the object is intersecting
        // on of the volumes formed between the edges of the frustum and the
        // light
        if (!mIsLightInFrustum || mLight->getType() == Light::LT_DIRECTIONAL)
        {
            // Iterate over volumes
            PlaneBoundedVolumeList::const_iterator i, iend;
            iend = mLightClipVolumeList->end();
            for (i = mLightClipVolumeList->begin(); i != iend; ++i)
            {
                if (i->intersects(object->getWorldBoundingBox()))
                {
                    mCasterList->push_back(object);
                    return true;
                }

            }

        }
    }
    return true;
}

// OgreSceneManager.cpp:3676
bool RbxSceneManager::ShadowCasterSceneQueryListener::queryResult(
    SceneQuery::WorldFragment* fragment)
{
    // don't deal with world geometry
    return true;
}

// OgreSceneManager.cpp:3754
void RbxSceneManager::initShadowVolumeMaterials(void)
{
    /* This should have been set in the SceneManager constructor, but if you
       created the SceneManager BEFORE the Root object, you will need to call
       SceneManager::_setDestinationRenderSystem manually.
     */
    assert( mDestRenderSystem );

    if (mShadowMaterialInitDone)
        return;

    if (!mShadowDebugPass)
    {
        MaterialPtr matDebug = 
            MaterialManager::getSingleton().getByName("Ogre/Debug/ShadowVolumes");
        if (matDebug.isNull())
        {
            // Create
            matDebug = MaterialManager::getSingleton().create(
                "Ogre/Debug/ShadowVolumes", 
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowDebugPass = matDebug->getTechnique(0)->getPass(0);
            mShadowDebugPass->setSceneBlending(SBT_ADD); 
            mShadowDebugPass->setLightingEnabled(false);
            mShadowDebugPass->setDepthWriteEnabled(false);
            TextureUnitState* t = mShadowDebugPass->createTextureUnitState();
            t->setColourOperationEx(LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, 
                ColourValue(0.7, 0.0, 0.2));
            mShadowDebugPass->setCullingMode(CULL_NONE);

            if (mDestRenderSystem->getCapabilities()->hasCapability(
                RSC_VERTEX_PROGRAM))
            {
                ShadowVolumeExtrudeProgram::initialise();

                // Enable the (infinite) point light extruder for now, just to get some params
                mShadowDebugPass->setVertexProgram(
                    ShadowVolumeExtrudeProgram::programNames[ShadowVolumeExtrudeProgram::POINT_LIGHT]);
                mInfiniteExtrusionParams = 
                    mShadowDebugPass->getVertexProgramParameters();
                mInfiniteExtrusionParams->setAutoConstant(0, 
                    GpuProgramParameters::ACT_WORLDVIEWPROJ_MATRIX);
                mInfiniteExtrusionParams->setAutoConstant(4, 
                    GpuProgramParameters::ACT_LIGHT_POSITION_OBJECT_SPACE);
            }	
            matDebug->compile();

        }
        else
        {
            mShadowDebugPass = matDebug->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM))
            {
                mInfiniteExtrusionParams = mShadowDebugPass->getVertexProgramParameters();
            }
        }
    }

    if (!mShadowStencilPass)
    {

        MaterialPtr matStencil = MaterialManager::getSingleton().getByName(
            "Ogre/StencilShadowVolumes");
        if (matStencil.isNull())
        {
            // Init
            matStencil = MaterialManager::getSingleton().create(
                "Ogre/StencilShadowVolumes",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowStencilPass = matStencil->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(
                RSC_VERTEX_PROGRAM))
            {

                // Enable the finite point light extruder for now, just to get some params
                mShadowStencilPass->setVertexProgram(
                    ShadowVolumeExtrudeProgram::programNames[ShadowVolumeExtrudeProgram::POINT_LIGHT_FINITE]);
                mFiniteExtrusionParams = 
                    mShadowStencilPass->getVertexProgramParameters();
                mFiniteExtrusionParams->setAutoConstant(0, 
                    GpuProgramParameters::ACT_WORLDVIEWPROJ_MATRIX);
                mFiniteExtrusionParams->setAutoConstant(4, 
                    GpuProgramParameters::ACT_LIGHT_POSITION_OBJECT_SPACE);
                // Note extra parameter
                mFiniteExtrusionParams->setAutoConstant(5, 
                    GpuProgramParameters::ACT_SHADOW_EXTRUSION_DISTANCE);
            }
            matStencil->compile();
            // Nothing else, we don't use this like a 'real' pass anyway,
            // it's more of a placeholder
        }
        else
        {
            mShadowStencilPass = matStencil->getTechnique(0)->getPass(0);

            if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM))
            {
                mFiniteExtrusionParams = mShadowStencilPass->getVertexProgramParameters();
            }
        }
    }




    if (!mShadowModulativePass)
    {

        MaterialPtr matModStencil = MaterialManager::getSingleton().getByName(
            "Ogre/StencilShadowModulationPass");
        if (matModStencil.isNull())
        {
            // Init
            matModStencil = MaterialManager::getSingleton().create(
                "Ogre/StencilShadowModulationPass",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowModulativePass = matModStencil->getTechnique(0)->getPass(0);
            mShadowModulativePass->setSceneBlending(SBF_DEST_COLOUR, SBF_ZERO); 
            mShadowModulativePass->setLightingEnabled(false);
            mShadowModulativePass->setDepthWriteEnabled(false);
            mShadowModulativePass->setDepthCheckEnabled(false);
            TextureUnitState* t = mShadowModulativePass->createTextureUnitState();
            t->setColourOperationEx(LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, 
                mShadowColour);
            mShadowModulativePass->setCullingMode(CULL_NONE);
        }
        else
        {
            mShadowModulativePass = matModStencil->getTechnique(0)->getPass(0);
        }
    }

    // Also init full screen quad while we're at it
    if (!mFullScreenQuad)
    {
        mFullScreenQuad = new Rectangle2D();
        mFullScreenQuad->setCorners(-1,1,1,-1);
    }

    // Also init shadow caster material for texture shadows
    if (!mShadowCasterPlainBlackPass)
    {
        MaterialPtr matPlainBlack = MaterialManager::getSingleton().getByName(
            "Ogre/TextureShadowCaster");
        if (matPlainBlack.isNull())
        {
            matPlainBlack = MaterialManager::getSingleton().create(
                "Ogre/TextureShadowCaster",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowCasterPlainBlackPass = matPlainBlack->getTechnique(0)->getPass(0);
            // Lighting has to be on, because we need shadow coloured objects
            // Note that because we can't predict vertex programs, we'll have to
            // bind light values to those, and so we bind White to ambient
            // reflectance, and we'll set the ambient colour to the shadow colour
            mShadowCasterPlainBlackPass->setAmbient(ColourValue::White);
            mShadowCasterPlainBlackPass->setDiffuse(ColourValue::Black);
            mShadowCasterPlainBlackPass->setSelfIllumination(ColourValue::Black);
            mShadowCasterPlainBlackPass->setSpecular(ColourValue::Black);
			// Override fog
			mShadowCasterPlainBlackPass->setFog(true, FOG_NONE);
            // no textures or anything else, we will bind vertex programs
            // every so often though
        }
        else
        {
            mShadowCasterPlainBlackPass = matPlainBlack->getTechnique(0)->getPass(0);
        }
    }

    if (!mShadowReceiverPass)
    {
        MaterialPtr matShadRec = MaterialManager::getSingleton().getByName(
            "Ogre/TextureShadowReceiver");
        if (matShadRec.isNull())			
        {
            matShadRec = MaterialManager::getSingleton().create(
                "Ogre/TextureShadowReceiver",
                ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
            mShadowReceiverPass = matShadRec->getTechnique(0)->getPass(0);
			// Don't set lighting and blending modes here, depends on additive / modulative
            TextureUnitState* t = mShadowReceiverPass->createTextureUnitState();
            t->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);
        }
        else
        {
            mShadowReceiverPass = matShadRec->getTechnique(0)->getPass(0);
        }
    }

    // Set up spot shadow fade texture (loaded from code data block)
    TexturePtr spotShadowFadeTex = 
        TextureManager::getSingleton().getByName("spot_shadow_fade.png");
    if (spotShadowFadeTex.isNull())
    {
        // Load the manual buffer into an image (don't destroy memory!
        DataStreamPtr stream(
			new MemoryDataStream(SPOT_SHADOW_FADE_PNG, SPOT_SHADOW_FADE_PNG_SIZE, false));
        Image img;
        img.load(stream, "png");
        spotShadowFadeTex = 
            TextureManager::getSingleton().loadImage(
			"spot_shadow_fade.png", ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME, 
			img, TEX_TYPE_2D);
    }

    mShadowMaterialInitDone = true;
}

// OgreSceneManager.cpp:3964
const Pass* RbxSceneManager::deriveShadowCasterPass(const Pass* pass)
{
	if (isShadowTechniqueTextureBased())
    {
		Pass* retPass = mShadowTextureCustomCasterPass ? 
			mShadowTextureCustomCasterPass : mShadowCasterPlainBlackPass;

		
		// Special case alpha-blended passes
		if ((pass->getSourceBlendFactor() == SBF_SOURCE_ALPHA && 
			pass->getDestBlendFactor() == SBF_ONE_MINUS_SOURCE_ALPHA) 
			|| pass->getAlphaRejectFunction() != CMPF_ALWAYS_PASS)
		{
			// Alpha blended passes must retain their transparency
			retPass->setAlphaRejectSettings(pass->getAlphaRejectFunction(), 
				pass->getAlphaRejectValue());
			retPass->setSceneBlending(pass->getSourceBlendFactor(), pass->getDestBlendFactor());
			retPass->getParent()->getParent()->setTransparencyCastsShadows(true);

			// So we allow the texture units, but override the colour functions
			// Copy texture state, shift up one since 0 is shadow texture
			unsigned short origPassTUCount = pass->getNumTextureUnitStates();
			for (unsigned short t = 0; t < origPassTUCount; ++t)
			{
				TextureUnitState* tex;
				if (retPass->getNumTextureUnitStates() <= t)
				{
					tex = retPass->createTextureUnitState();
				}
				else
				{
					tex = retPass->getTextureUnitState(t);
				}
				// copy base state
				(*tex) = *(pass->getTextureUnitState(t));
				// override colour function
				tex->setColourOperationEx(LBX_SOURCE1, LBS_MANUAL, LBS_CURRENT,
					isShadowTechniqueAdditive()? ColourValue::Black : mShadowColour);

			}
			// Remove any extras
			while (retPass->getNumTextureUnitStates() > origPassTUCount)
			{
				retPass->removeTextureUnitState(origPassTUCount);
			}

		}
		else
		{
			// reset
			retPass->setSceneBlending(SBT_REPLACE);
			retPass->setAlphaRejectFunction(CMPF_ALWAYS_PASS);
			while (retPass->getNumTextureUnitStates() > 0)
			{
				retPass->removeTextureUnitState(0);
			}
		}

		// Propagate culling modes
		retPass->setCullingMode(pass->getCullingMode());
		retPass->setManualCullingMode(pass->getManualCullingMode());
		

		// Does incoming pass have a custom shadow caster program?
		if (!pass->getShadowCasterVertexProgramName().empty())
		{
			// Have to merge the shadow caster vertex program in
			retPass->setVertexProgram(
				pass->getShadowCasterVertexProgramName(), false);
			const GpuProgramPtr& prg = retPass->getVertexProgram();
			// Load this program if not done already
			if (!prg->isLoaded())
				prg->load();
			// Copy params
			retPass->setVertexProgramParameters(
				pass->getShadowCasterVertexProgramParameters());
			// Also have to hack the light autoparams, that is done later
		}
		else 
		{
			if (retPass == mShadowTextureCustomCasterPass)
			{
				// reset vp?
				if (mShadowTextureCustomCasterPass->getVertexProgramName() !=
					mShadowTextureCustomCasterVertexProgram)
				{
					mShadowTextureCustomCasterPass->setVertexProgram(
						mShadowTextureCustomCasterVertexProgram, false);
					if(mShadowTextureCustomCasterPass->hasVertexProgram())
					{
						mShadowTextureCustomCasterPass->setVertexProgramParameters(
							mShadowTextureCustomCasterVPParams);

					}

				}

			}
			else
			{
				// Standard shadow caster pass, reset to no vp
				retPass->setVertexProgram(StringUtil::BLANK);
			}
		}
		return retPass;
	}
	else
	{
        return pass;
    }

}

// OgreSceneManager.cpp:4077
const Pass* RbxSceneManager::deriveShadowReceiverPass(const Pass* pass)
{

    if (isShadowTechniqueTextureBased())
    {
		Pass* retPass = mShadowTextureCustomReceiverPass ? 
			mShadowTextureCustomReceiverPass : mShadowReceiverPass;

		// Does incoming pass have a custom shadow receiver program?
		if (!pass->getShadowReceiverVertexProgramName().empty())
		{
			// Have to merge the shadow receiver vertex program in
			retPass->setVertexProgram(
				pass->getShadowReceiverVertexProgramName(), false);
			const GpuProgramPtr& prg = retPass->getVertexProgram();
			// Load this program if not done already
			if (!prg->isLoaded())
				prg->load();
			// Copy params
			retPass->setVertexProgramParameters(
				pass->getShadowReceiverVertexProgramParameters());
			// Also have to hack the light autoparams, that is done later
		}
		else 
		{
			if (retPass == mShadowTextureCustomReceiverPass)
			{
				// reset vp?
				if (mShadowTextureCustomReceiverPass->getVertexProgramName() !=
					mShadowTextureCustomReceiverVertexProgram)
				{
					mShadowTextureCustomReceiverPass->setVertexProgram(
						mShadowTextureCustomReceiverVertexProgram, false);
					if(mShadowTextureCustomReceiverPass->hasVertexProgram())
					{
						mShadowTextureCustomReceiverPass->setVertexProgramParameters(
							mShadowTextureCustomReceiverVPParams);

					}

				}

			}
			else
			{
				// Standard shadow receiver pass, reset to no vp
				retPass->setVertexProgram(StringUtil::BLANK);
			}
		}

        unsigned short keepTUCount;
		// If additive, need lighting parameters & standard programs
		if (isShadowTechniqueAdditive())
		{
			retPass->setLightingEnabled(true);
			retPass->setAmbient(pass->getAmbient());
			retPass->setSelfIllumination(pass->getSelfIllumination());
			retPass->setDiffuse(pass->getDiffuse());
			retPass->setSpecular(pass->getSpecular());
			retPass->setShininess(pass->getShininess());
			retPass->setIteratePerLight(pass->getIteratePerLight(), 
				pass->getRunOnlyForOneLightType(), pass->getOnlyLightType());

            // We need to keep alpha rejection settings
            retPass->setAlphaRejectSettings(pass->getAlphaRejectFunction(),
                pass->getAlphaRejectValue());
            // Copy texture state, shift up one since 0 is shadow texture
            unsigned short origPassTUCount = pass->getNumTextureUnitStates();
            for (unsigned short t = 0; t < origPassTUCount; ++t)
            {
                unsigned short targetIndex = t+1;
                TextureUnitState* tex;
                if (retPass->getNumTextureUnitStates() <= targetIndex)
                {
                    tex = retPass->createTextureUnitState();
                }
                else
                {
                    tex = retPass->getTextureUnitState(targetIndex);
                }
                (*tex) = *(pass->getTextureUnitState(t));
				// If programmable, have to adjust the texcoord sets too
				// D3D insists that texcoordsets match tex unit in programmable mode
				if (retPass->hasVertexProgram())
					tex->setTextureCoordSet(targetIndex);
            }
            keepTUCount = origPassTUCount + 1;
		}// additive lighting
		else
		{
			// need to keep spotlight fade etc
			keepTUCount = retPass->getNumTextureUnitStates();
		}


		// Will also need fragment programs since this is a complex light setup
		if (!pass->getShadowReceiverFragmentProgramName().empty())
		{
			// Have to merge the shadow receiver vertex program in
			retPass->setFragmentProgram(
				pass->getShadowReceiverFragmentProgramName(), false);
			const GpuProgramPtr& prg = retPass->getFragmentProgram();
			// Load this program if not done already
			if (!prg->isLoaded())
				prg->load();
			// Copy params
			retPass->setFragmentProgramParameters(
				pass->getShadowReceiverFragmentProgramParameters());

			// Did we bind a shadow vertex program?
			if (pass->hasVertexProgram() && !retPass->hasVertexProgram())
			{
				// We didn't bind a receiver-specific program, so bind the original
				retPass->setVertexProgram(pass->getVertexProgramName(), false);
				const GpuProgramPtr& prg = retPass->getVertexProgram();
				// Load this program if required
				if (!prg->isLoaded())
					prg->load();
				// Copy params
				retPass->setVertexProgramParameters(
					pass->getVertexProgramParameters());

			}
		}
		else 
		{
			// Reset any merged fragment programs from last time
			if (retPass == mShadowTextureCustomReceiverPass)
			{
				// reset fp?
				if (mShadowTextureCustomReceiverPass->getFragmentProgramName() !=
					mShadowTextureCustomReceiverFragmentProgram)
				{
					mShadowTextureCustomReceiverPass->setFragmentProgram(
						mShadowTextureCustomReceiverFragmentProgram, false);
					if(mShadowTextureCustomReceiverPass->hasFragmentProgram())
					{
						mShadowTextureCustomReceiverPass->setFragmentProgramParameters(
							mShadowTextureCustomReceiverFPParams);

					}

				}

			}
			else
			{
				// Standard shadow receiver pass, reset to no fp
				retPass->setFragmentProgram(StringUtil::BLANK);
			}

		}

        // Remove any extra texture units
        while (retPass->getNumTextureUnitStates() > keepTUCount)
        {
            retPass->removeTextureUnitState(keepTUCount);
        }

		retPass->_load();

		return retPass;
	}
	else
	{
        return pass;
    }

}

// OgreSceneManager.cpp:4247
void RbxSceneManager::renderShadowVolumesToStencil(const Light* light, const Camera* camera)
{
    // Get the shadow caster list
    const ShadowCasterList& casters = findShadowCastersForLight(light, camera);
    // Check there are some shadow casters to render
    if (casters.empty())
    {
        // No casters, just do nothing
        return;
    }

    // Set up scissor test (point & spot lights only)
    bool scissored = false;
    if (light->getType() != Light::LT_DIRECTIONAL && 
        mDestRenderSystem->getCapabilities()->hasCapability(RSC_SCISSOR_TEST))
    {
        // Project the sphere onto the camera
        Real left, right, top, bottom;
        Sphere sphere(light->getDerivedPosition(), light->getAttenuationRange());
        if (camera->projectSphere(sphere, &left, &top, &right, &bottom))
        {
            scissored = true;
            // Turn normalised device coordinates into pixels
            int iLeft, iTop, iWidth, iHeight;
            mCurrentViewport->getActualDimensions(iLeft, iTop, iWidth, iHeight);
            size_t szLeft, szRight, szTop, szBottom;

            szLeft = (size_t)(iLeft + ((left + 1) * 0.5 * iWidth));
            szRight = (size_t)(iLeft + ((right + 1) * 0.5 * iWidth));
            szTop = (size_t)(iTop + ((-top + 1) * 0.5 * iHeight));
            szBottom = (size_t)(iTop + ((-bottom + 1) * 0.5 * iHeight));

            mDestRenderSystem->setScissorTest(true, szLeft, szTop, szRight, szBottom);
        }
    }

    mDestRenderSystem->unbindGpuProgram(GPT_FRAGMENT_PROGRAM);

    // Can we do a 2-sided stencil?
    bool stencil2sided = false;
    if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_TWO_SIDED_STENCIL) && 
        mDestRenderSystem->getCapabilities()->hasCapability(RSC_STENCIL_WRAP))
    {
        // enable
        stencil2sided = true;
    }

    // Do we have access to vertex programs?
    bool extrudeInSoftware = true;
    bool finiteExtrude = !mShadowUseInfiniteFarPlane || 
        !mDestRenderSystem->getCapabilities()->hasCapability(RSC_INFINITE_FAR_PLANE);
    if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_VERTEX_PROGRAM))
    {
        extrudeInSoftware = false;
        // attach the appropriate extrusion vertex program
        // Note we never unset it because support for vertex programs is constant
        mShadowStencilPass->setVertexProgram(
            ShadowVolumeExtrudeProgram::getProgramName(light->getType(), finiteExtrude, false)
            , false);
        // Set params
        if (finiteExtrude)
        {
            mShadowStencilPass->setVertexProgramParameters(mFiniteExtrusionParams);
        }
        else
        {
            mShadowStencilPass->setVertexProgramParameters(mInfiniteExtrusionParams);
        }
        if (mDebugShadows)
        {
            mShadowDebugPass->setVertexProgram(
                ShadowVolumeExtrudeProgram::getProgramName(light->getType(), finiteExtrude, true)
                , false);
            // Set params
            if (finiteExtrude)
            {
                mShadowDebugPass->setVertexProgramParameters(mFiniteExtrusionParams);
            }
            else
            {
                mShadowDebugPass->setVertexProgramParameters(mInfiniteExtrusionParams);
            }
        }

        mDestRenderSystem->bindGpuProgram(mShadowStencilPass->getVertexProgram()->_getBindingDelegate());

    }
    else
    {
        mDestRenderSystem->unbindGpuProgram(GPT_VERTEX_PROGRAM);
    }

    // Add light to internal list for use in render call
    LightList lightList;
    // const_cast is forgiveable here since we pass this const
    lightList.push_back(const_cast<Light*>(light));

    // Turn off colour writing and depth writing
    mDestRenderSystem->_setColourBufferWriteEnabled(false, false, false, false);
	mDestRenderSystem->_disableTextureUnitsFrom(0);
    mDestRenderSystem->_setDepthBufferParams(true, false, CMPF_LESS);
    mDestRenderSystem->setStencilCheckEnabled(true);

    // Calculate extrusion distance
    // Use direction light extrusion distance now, just form optimize code
    // generate a little, point/spot light will up to date later
    Real extrudeDist = mShadowDirLightExtrudeDist;

    // Figure out the near clip volume
    const PlaneBoundedVolume& nearClipVol = 
        light->_getNearClipVolume(camera);

    // Now iterate over the casters and render
    ShadowCasterList::const_iterator si, siend;
    siend = casters.end();


	// Now iterate over the casters and render
	for (si = casters.begin(); si != siend; ++si)
	{
        ShadowCaster* caster = *si;
		bool zfailAlgo = camera->isCustomNearClipPlaneEnabled();
		unsigned long flags = 0;

        if (light->getType() != Light::LT_DIRECTIONAL)
        {
            extrudeDist = caster->getPointExtrusionDistance(light); 
        }

        if (!extrudeInSoftware && !finiteExtrude)
        {
            // hardware extrusion, to infinity (and beyond!)
            flags |= SRF_EXTRUDE_TO_INFINITY;
        }

		// Determine whether zfail is required
        if (zfailAlgo || nearClipVol.intersects(caster->getWorldBoundingBox()))
        {
            // We use zfail for this object only because zfail
	        // compatible with zpass algorithm
			zfailAlgo = true;
            // We need to include the light and / or dark cap
            // But only if they will be visible
            if(camera->isVisible(caster->getLightCapBounds()))
            {
                flags |= SRF_INCLUDE_LIGHT_CAP;
            }
			// zfail needs dark cap 
			// UNLESS directional lights using hardware extrusion to infinity
			// since that extrudes to a single point
			if(!((flags & SRF_EXTRUDE_TO_INFINITY) && 
				light->getType() == Light::LT_DIRECTIONAL) &&
				camera->isVisible(caster->getDarkCapBounds(*light, extrudeDist)))
			{
				flags |= SRF_INCLUDE_DARK_CAP;
			}
        }
		else
		{
			// In zpass we need a dark cap if
			// 1: infinite extrusion on point/spotlight sources in modulative shadows
			//    mode, since otherwise in areas where there is no depth (skybox)
			//    the infinitely projected volume will leave a dark band
			// 2: finite extrusion on any light source since glancing angles
			//    can peek through the end and shadow objects behind incorrectly
			if ((flags & SRF_EXTRUDE_TO_INFINITY) && 
				light->getType() != Light::LT_DIRECTIONAL && 
				isShadowTechniqueModulative() && 
				camera->isVisible(caster->getDarkCapBounds(*light, extrudeDist)))
			{
				flags |= SRF_INCLUDE_DARK_CAP;
			}
			else if (!(flags & SRF_EXTRUDE_TO_INFINITY) && 
				camera->isVisible(caster->getDarkCapBounds(*light, extrudeDist)))
			{
				flags |= SRF_INCLUDE_DARK_CAP;
			}

		}

        // Get shadow renderables			
        ShadowCaster::ShadowRenderableListIterator iShadowRenderables =
            caster->getShadowVolumeRenderableIterator(mShadowTechnique,
            light, &mShadowIndexBuffer, extrudeInSoftware, 
            extrudeDist, flags);

        // Render a shadow volume here
        //  - if we have 2-sided stencil, one render with no culling
        //  - otherwise, 2 renders, one with each culling method and invert the ops
        setShadowVolumeStencilState(false, zfailAlgo, stencil2sided);
        renderShadowVolumeObjects(iShadowRenderables, mShadowStencilPass, &lightList, flags,
            false, zfailAlgo, stencil2sided);
        if (!stencil2sided)
        {
            // Second pass
            setShadowVolumeStencilState(true, zfailAlgo, false);
            renderShadowVolumeObjects(iShadowRenderables, mShadowStencilPass, &lightList, flags,
                true, zfailAlgo, false);
        }

        // Do we need to render a debug shadow marker?
        if (mDebugShadows)
        {
            // reset stencil & colour ops
            mDestRenderSystem->setStencilBufferParams();
            mShadowDebugPass->getTextureUnitState(0)->
                setColourOperationEx(LBX_MODULATE, LBS_MANUAL, LBS_CURRENT,
                zfailAlgo ? ColourValue(0.7, 0.0, 0.2) : ColourValue(0.0, 0.7, 0.2));
            _setPass(mShadowDebugPass);
            renderShadowVolumeObjects(iShadowRenderables, mShadowDebugPass, &lightList, flags,
                true, false, false);
            mDestRenderSystem->_setColourBufferWriteEnabled(false, false, false, false);
            mDestRenderSystem->_setDepthBufferFunction(CMPF_LESS);
        }
    }

    // revert colour write state
    mDestRenderSystem->_setColourBufferWriteEnabled(true, true, true, true);
    // revert depth state
    mDestRenderSystem->_setDepthBufferParams();

    mDestRenderSystem->setStencilCheckEnabled(false);

    mDestRenderSystem->unbindGpuProgram(GPT_VERTEX_PROGRAM);

    if (scissored)
    {
        // disable scissor test
        mDestRenderSystem->setScissorTest(false);
    }

}

// OgreSceneManager.cpp:4480
void RbxSceneManager::renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables,
                                             Pass* pass,
                                             const LightList *manualLightList,
                                             unsigned long flags,
                                             bool secondpass, bool zfail, bool twosided)
{
    // ----- SHADOW VOLUME LOOP -----
    // Render all shadow renderables with same stencil operations
    while (iShadowRenderables.hasMoreElements())
    {
        ShadowRenderable* sr = iShadowRenderables.getNext();

        // fork: no isVisible() test here (renderShadowVolumeObjects 00693420)
        {
            // render volume, including dark and (maybe) light caps
            renderSingleObject(sr, pass, false, manualLightList);

            // optionally render separate light cap
            if (sr->isLightCapSeparate() && (flags & SRF_INCLUDE_LIGHT_CAP))
            {
                ShadowRenderable* lightCap = sr->getLightCapRenderable();
                assert(lightCap && "Shadow renderable is missing a separate light cap renderable!");

                // We must take care with light caps when we could 'see' the back facing
                // triangles directly:
                //   1. The front facing light caps must render as always fail depth
                //      check to avoid 'depth fighting'.
                //   2. The back facing light caps must use normal depth function to
                //      avoid break the standard depth check
                //
                // TODO:
                //   1. Separate light caps rendering doesn't need for the 'closed'
                //      mesh that never touch the near plane, because in this instance,
                //      we couldn't 'see' any back facing triangles directly. The
                //      'closed' mesh must determinate by edge list builder.
                //   2. There still exists 'depth fighting' bug with coplane triangles
                //      that has opposite facing. This usually occur when use two side
                //      material in the modeling tools and the model exporting tools
                //      exporting double triangles to represent this model. This bug
                //      can't fixed in GPU only, there must has extra work on edge list
                //      builder and shadow volume generater to fix it.
                //
                if (twosided)
                {
                    // select back facing light caps to render
                    mDestRenderSystem->_setCullingMode(CULL_ANTICLOCKWISE);
                    // use normal depth function for back facing light caps
                    renderSingleObject(lightCap, pass, false, manualLightList);

                    // select front facing light caps to render
                    mDestRenderSystem->_setCullingMode(CULL_CLOCKWISE);
                    // must always fail depth check for front facing light caps
                    mDestRenderSystem->_setDepthBufferFunction(CMPF_ALWAYS_FAIL);
                    renderSingleObject(lightCap, pass, false, manualLightList);

                    // reset depth function
                    mDestRenderSystem->_setDepthBufferFunction(CMPF_LESS);
                    // reset culling mode
                    mDestRenderSystem->_setCullingMode(CULL_NONE);
                }
                else if ((secondpass || zfail) && !(secondpass && zfail))
                {
                    // use normal depth function for back facing light caps
                    renderSingleObject(lightCap, pass, false, manualLightList);
                }
                else
                {
                    // must always fail depth check for front facing light caps
                    mDestRenderSystem->_setDepthBufferFunction(CMPF_ALWAYS_FAIL);
                    renderSingleObject(lightCap, pass, false, manualLightList);

                    // reset depth function
                    mDestRenderSystem->_setDepthBufferFunction(CMPF_LESS);
                }
            }
        }
    }
}

// OgreSceneManager.cpp:4560
void RbxSceneManager::setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided)
{
    // Determinate the best stencil operation
    StencilOperation incrOp, decrOp;
    if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_STENCIL_WRAP))
    {
        incrOp = SOP_INCREMENT_WRAP;
        decrOp = SOP_DECREMENT_WRAP;
    }
    else
    {
        incrOp = SOP_INCREMENT;
        decrOp = SOP_DECREMENT;
    }

    // First pass, do front faces if zpass
    // Second pass, do back faces if zpass
    // Invert if zfail
    // this is to ensure we always increment before decrement
    // When two-sided stencil, always pass front face stencil
    // operation parameters and the inverse of them will happen
    // for back faces
    if ( !twosided && ((secondpass || zfail) && !(secondpass && zfail)) )
    {
        mDestRenderSystem->_setCullingMode(
            twosided? CULL_NONE : CULL_ANTICLOCKWISE);
        mDestRenderSystem->setStencilBufferParams(
            CMPF_ALWAYS_PASS, // always pass stencil check
            0, // no ref value (no compare)
            0xFFFFFFFF, // no mask
            SOP_KEEP, // stencil test will never fail
            zfail ? incrOp : SOP_KEEP, // back face depth fail
            zfail ? SOP_KEEP : decrOp, // back face pass
            twosided
            );
    }
    else
    {
        mDestRenderSystem->_setCullingMode(
            twosided? CULL_NONE : CULL_CLOCKWISE);
        mDestRenderSystem->setStencilBufferParams(
            CMPF_ALWAYS_PASS, // always pass stencil check
            0, // no ref value (no compare)
            0xFFFFFFFF, // no mask
            SOP_KEEP, // stencil test will never fail
            zfail ? decrOp : SOP_KEEP, // front face depth fail
            zfail ? SOP_KEEP : incrOp, // front face pass
            twosided
            );
    }
}

// OgreSceneManager.cpp:4612
void RbxSceneManager::setShadowColour(const ColourValue& colour)
{
    mShadowColour = colour;

    // Change shadow material setting only when it's prepared,
    // otherwise, it'll set up while preparing shadow materials.
    if (mShadowModulativePass)
    {
        mShadowModulativePass->getTextureUnitState(0)->setColourOperationEx(
            LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, colour);
    }
}

// OgreSceneManager.cpp:4625
const ColourValue& RbxSceneManager::getShadowColour(void) const
{
    return mShadowColour;
}

// OgreSceneManager.cpp:4630
void RbxSceneManager::setShadowFarDistance(Real distance)
{
    mShadowFarDist = distance;
    mShadowFarDistSquared = distance * distance;
}

// OgreSceneManager.cpp:4636
void RbxSceneManager::setShadowDirectionalLightExtrusionDistance(Real dist)
{
    mShadowDirLightExtrudeDist = dist;
}

// OgreSceneManager.cpp:4641
Real RbxSceneManager::getShadowDirectionalLightExtrusionDistance(void) const
{
    return mShadowDirLightExtrudeDist;
}

// OgreSceneManager.cpp:4646
void RbxSceneManager::setShadowIndexBufferSize(size_t size)
{
    if (!mShadowIndexBuffer.isNull() && size != mShadowIndexBufferSize)
    {
        // re-create shadow buffer with new size
        mShadowIndexBuffer = HardwareBufferManager::getSingleton().
            createIndexBuffer(HardwareIndexBuffer::IT_16BIT, 
            size, 
            HardwareBuffer::HBU_DYNAMIC_WRITE_ONLY_DISCARDABLE, 
            false);
    }
    mShadowIndexBufferSize = size;
}

// OgreSceneManager.cpp:4660
void RbxSceneManager::setShadowTextureConfig(size_t shadowIndex, unsigned short width, 
	unsigned short height, PixelFormat format)
{
	ShadowTextureConfig conf;
	conf.width = width;
	conf.height = height;
	conf.format = format;

	setShadowTextureConfig(shadowIndex, conf);


}

// OgreSceneManager.cpp:4673
void RbxSceneManager::setShadowTextureConfig(size_t shadowIndex, 
	const ShadowTextureConfig& config)
{
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
#line 4717 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"RbxSceneManager::setShadowTextureConfig");
	}
	mShadowTextureConfigList[shadowIndex] = config;

	mShadowTextureConfigDirty = true;
}

// OgreSceneManager.cpp:4694
void RbxSceneManager::setShadowTextureSize(unsigned short size)
{
	// default all current
	for (ShadowTextureConfigList::iterator i = mShadowTextureConfigList.begin();
		i != mShadowTextureConfigList.end(); ++i)
	{
		if (i->width != size || i->height != size)
		{
			i->width = i->height = size;
			mShadowTextureConfigDirty = true;
		}
	}

}

// OgreSceneManager.cpp:4709
void RbxSceneManager::setShadowTextureCount(size_t count)
{
    // Change size, any new items will take default
	if (count != mShadowTextureConfigList.size())
	{
		mShadowTextureConfigList.resize(count);
		mShadowTextureConfigDirty = true;
	}
}

// OgreSceneManager.cpp:4719
void RbxSceneManager::setShadowTexturePixelFormat(PixelFormat fmt)
{
	for (ShadowTextureConfigList::iterator i = mShadowTextureConfigList.begin();
		i != mShadowTextureConfigList.end(); ++i)
	{
		if (i->format != fmt)
		{
			i->format = fmt;
			mShadowTextureConfigDirty = true;
		}
	}
}

// OgreSceneManager.cpp:4732
void RbxSceneManager::setShadowTextureSettings(unsigned short size, 
	unsigned short count, PixelFormat fmt)
{
	setShadowTextureCount(count);
	for (ShadowTextureConfigList::iterator i = mShadowTextureConfigList.begin();
		i != mShadowTextureConfigList.end(); ++i)
	{
		if (i->width != size || i->height != size || i->format != fmt)
		{
			i->width = i->height = size;
			i->format = fmt;
			mShadowTextureConfigDirty = true;
		}
	}
}

// OgreSceneManager.cpp:4748
const TexturePtr& RbxSceneManager::getShadowTexture(size_t shadowIndex)
{
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
#line 4791 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"RbxSceneManager::getShadowTexture");
	}
	ensureShadowTexturesCreated();

	return mShadowTextures[shadowIndex];


}

// OgreSceneManager.cpp:4763
void RbxSceneManager::setShadowTextureSelfShadow(bool selfShadow) 
{ 
	mShadowTextureSelfShadow = selfShadow;
	if (isShadowTechniqueTextureBased())
		getRenderQueue()->setShadowCastersCannotBeReceivers(!selfShadow);
}

// OgreSceneManager.cpp:4770
void RbxSceneManager::setShadowTextureCasterMaterial(const String& name)
{
	if (name.empty())
	{
		mShadowTextureCustomCasterPass = 0;
	}
	else
	{
		MaterialPtr mat = MaterialManager::getSingleton().getByName(name);
		if (mat.isNull())
		{
#line 4820 ".\\RbxSceneManager.cpp"
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
				"Cannot locate material called '" + name + "'", 
				"RbxSceneManager::setShadowTextureCasterMaterial");
		}
		mat->load();
		mShadowTextureCustomCasterPass = mat->getBestTechnique()->getPass(0);
		if (mShadowTextureCustomCasterPass->hasVertexProgram())
		{
			// Save vertex program and params in case we have to swap them out
			mShadowTextureCustomCasterVertexProgram = 
				mShadowTextureCustomCasterPass->getVertexProgramName();
			mShadowTextureCustomCasterVPParams = 
				mShadowTextureCustomCasterPass->getVertexProgramParameters();

		}
	}
}

// OgreSceneManager.cpp:4799
void RbxSceneManager::setShadowTextureReceiverMaterial(const String& name)
{
	if (name.empty())
	{
		mShadowTextureCustomReceiverPass = 0;
	}
	else
	{
		MaterialPtr mat = MaterialManager::getSingleton().getByName(name);
		if (mat.isNull())
		{
#line 4849 ".\\RbxSceneManager.cpp"
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
				"Cannot locate material called '" + name + "'", 
				"RbxSceneManager::setShadowTextureReceiverMaterial");
		}
		mat->load();
		mShadowTextureCustomReceiverPass = mat->getBestTechnique()->getPass(0);
		if (mShadowTextureCustomReceiverPass->hasVertexProgram())
		{
			// Save vertex program and params in case we have to swap them out
			mShadowTextureCustomReceiverVertexProgram = 
				mShadowTextureCustomReceiverPass->getVertexProgramName();
			mShadowTextureCustomReceiverVPParams = 
				mShadowTextureCustomReceiverPass->getVertexProgramParameters();

		}
		else
		{
			mShadowTextureCustomReceiverVertexProgram = StringUtil::BLANK;

		}
		if (mShadowTextureCustomReceiverPass->hasFragmentProgram())
		{
			// Save fragment program and params in case we have to swap them out
			mShadowTextureCustomReceiverFragmentProgram = 
				mShadowTextureCustomReceiverPass->getFragmentProgramName();
			mShadowTextureCustomReceiverFPParams = 
				mShadowTextureCustomReceiverPass->getFragmentProgramParameters();

		}
		else
		{
			mShadowTextureCustomReceiverFragmentProgram = StringUtil::BLANK;

		}
	}
}

// OgreSceneManager.cpp:4847
void RbxSceneManager::setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup)
{
	mDefaultShadowCameraSetup = shadowSetup;

}

// OgreSceneManager.cpp:4853
const ShadowCameraSetupPtr& RbxSceneManager::getShadowCameraSetup() const
{
	return mDefaultShadowCameraSetup;
}

// OgreSceneManager.cpp:4858
void RbxSceneManager::ensureShadowTexturesCreated()
{
	if (mShadowTextureConfigDirty)
	{
		destroyShadowTextures();
		ShadowTextureManager::getSingleton().getShadowTextures(
			mShadowTextureConfigList, mShadowTextures);

		// clear shadow cam - light mapping
		mShadowCamLightMapping.clear();


		// Recreate shadow textures
		for (ShadowTextureList::iterator i = mShadowTextures.begin(); 
			i != mShadowTextures.end(); ++i) 
		{
			const TexturePtr& shadowTex = *i;

			// Camera names are local to SM 
			String camName = shadowTex->getName() + "Cam";
			// Material names are global to SM, make specific
			String matName = shadowTex->getName() + "Mat" + getName();

			RenderTexture *shadowRTT = shadowTex->getBuffer()->getRenderTarget();

			// Create camera for this texture, but note that we have to rebind
			// in prepareShadowTextures to coexist with multiple SMs
			Camera* cam = createCamera(camName);
			cam->setAspectRatio(shadowTex->getWidth() / shadowTex->getHeight());
			// Don't use rendering distance for light cameras; we don't want shadows
			// for visible objects disappearing, especially for directional lights
			cam->setUseRenderingDistance(false);
			mShadowTextureCameras.push_back(cam);

			// Create a viewport, if not there already
			if (shadowRTT->getNumViewports() == 0)
			{
				// Note camera assignment is transient when multiple SMs
				Viewport *v = shadowRTT->addViewport(cam);
				v->setClearEveryFrame(true);
				// remove overlays
				v->setOverlaysEnabled(false);
			}

			// Don't update automatically - we'll do it when required
			shadowRTT->setAutoUpdated(false);

			// Also create corresponding Material used for rendering this shadow
			MaterialPtr mat = MaterialManager::getSingleton().getByName(matName);
			if (mat.isNull())
			{
				mat = MaterialManager::getSingleton().create(
					matName, ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME);
			}
			Pass* p = mat->getTechnique(0)->getPass(0);
			if (p->getNumTextureUnitStates() != 1 ||
				p->getTextureUnitState(0)->_getTexturePtr(0) != shadowTex)
			{
				mat->getTechnique(0)->getPass(0)->removeAllTextureUnitStates();
				// create texture unit referring to render target texture
				TextureUnitState* texUnit = 
					p->createTextureUnitState(shadowTex->getName());
				// set projective based on camera
				texUnit->setProjectiveTexturing(!p->hasVertexProgram(), cam);
				// clamp to border colour
				texUnit->setTextureAddressingMode(TextureUnitState::TAM_BORDER);
				texUnit->setTextureBorderColour(ColourValue::White);
				mat->touch();

			}

			// insert dummy camera-light combination
			mShadowCamLightMapping[cam] = 0;

			// Get null shadow texture
			if (mShadowTextureConfigList.empty())
			{
				mNullShadowTexture.setNull();
			}
			else
			{
				mNullShadowTexture = 
					ShadowTextureManager::getSingleton().getNullShadowTexture(
						mShadowTextureConfigList[0].format);
			}


		}
		mShadowTextureConfigDirty = false;
	}

}

// OgreSceneManager.cpp:4951
void RbxSceneManager::destroyShadowTextures(void)
{
	
    ShadowTextureList::iterator i, iend;
    ShadowTextureCameraList::iterator ci;
    iend = mShadowTextures.end();
    ci = mShadowTextureCameras.begin();
    for (i = mShadowTextures.begin(); i != iend; ++i, ++ci)
    {
        TexturePtr &shadowTex = *i;

		// Cleanup material that references this texture
		String matName = shadowTex->getName() + "Mat" + getName();
		MaterialPtr mat = MaterialManager::getSingleton().getByName(matName);
		if (!mat.isNull())
		{
			// manually clear TUS to ensure texture ref released
			mat->getTechnique(0)->getPass(0)->removeAllTextureUnitStates();
			MaterialManager::getSingleton().remove(mat->getHandle());
		}

		// Always destroy camera since they are local to this SM
   		destroyCamera(*ci);
    }
    mShadowTextures.clear();
	mShadowTextureCameras.clear();

	// Will destroy if no other scene managers referencing
	ShadowTextureManager::getSingleton().clearUnused();

	mShadowTextureConfigDirty = true;
        
}

// OgreSceneManager.cpp:4985
void RbxSceneManager::prepareShadowTextures(Camera* cam, Viewport* vp)
{
	// create shadow textures if needed
	ensureShadowTexturesCreated();

    // Set the illumination stage, prevents recursive calls
    IlluminationRenderStage savedStage = mIlluminationStage;
    mIlluminationStage = IRS_RENDER_TO_TEXTURE;

    // Determine far shadow distance
    Real shadowDist = mShadowFarDist;
    if (!shadowDist)
    {
        // need a shadow distance, make one up
        shadowDist = cam->getNearClipDistance() * 300;
    }
	Real shadowOffset = shadowDist * mShadowTextureOffset;
    // Precalculate fading info
	Real shadowEnd = shadowDist + shadowOffset;
	Real fadeStart = shadowEnd * mShadowTextureFadeStart;
	Real fadeEnd = shadowEnd * mShadowTextureFadeEnd;
	// Additive lighting should not use fogging, since it will overbrighten; use border clamp
	if (!isShadowTechniqueAdditive())
	{
		// set fogging to hide the shadow edge 
		mShadowReceiverPass->setFog(true, FOG_LINEAR, ColourValue::White, 
			0, fadeStart, fadeEnd);
	}
    else
    {
        // disable fogging explicitly
        mShadowReceiverPass->setFog(true, FOG_NONE);
    }

    // Iterate over the lights we've found, max out at the limit of light textures
	// Note that the light sorting must now place shadow casting lights at the
	// start of the light list, therefore we do not need to deal with potential
	// mismatches in the light<->shadow texture list any more

    LightList::iterator i, iend;
    ShadowTextureList::iterator si, siend;
	ShadowTextureCameraList::iterator ci;
    iend = mLightsAffectingFrustum.end();
    siend = mShadowTextures.end();
	ci = mShadowTextureCameras.begin();
    for (i = mLightsAffectingFrustum.begin(), si = mShadowTextures.begin();
        i != iend && si != siend; ++i)
    {
        Light* light = *i;

		// skip light if shadows are disabled
		if (!light->getCastShadows())
			continue;

		TexturePtr &shadowTex = *si;
        RenderTarget *shadowRTT = shadowTex->getBuffer()->getRenderTarget();
        Viewport *shadowView = shadowRTT->getViewport(0);
        Camera *texCam = *ci;
		// rebind camera, incase another SM in use which has switched to its cam
		shadowView->setCamera(texCam);
        
		// update shadow cam - light mapping
		ShadowCamLightMapping::iterator camLightIt = mShadowCamLightMapping.find( texCam );
		assert(camLightIt != mShadowCamLightMapping.end());
		camLightIt->second = light;

		if (light->getCustomShadowCameraSetup().isNull())
			mDefaultShadowCameraSetup->getShadowCamera(this, cam, vp, light, texCam);
		else
			light->getCustomShadowCameraSetup()->getShadowCamera(this, cam, vp, light, texCam);

        // Setup background colour
        shadowView->setBackgroundColour(ColourValue::White);

		// Fire shadow caster update, callee can alter camera settings
		fireShadowTexturesPreCaster(light, texCam);

        // Update target
        shadowRTT->update();

        ++si; // next shadow texture
		++ci; // next camera
    }
    // Set the illumination stage, prevents recursive calls
    mIlluminationStage = savedStage;

	fireShadowTexturesUpdated(
		std::min(mLightsAffectingFrustum.size(), mShadowTextures.size()));

	ShadowTextureManager::getSingleton().clearUnused();

}

// OgreSceneManager.cpp:5078
StaticGeometry* RbxSceneManager::createStaticGeometry(const String& name)
{
	// Check not existing
	if (mStaticGeometryList.find(name) != mStaticGeometryList.end())
	{
#line 5122 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"StaticGeometry with name '" + name + "' already exists!", 
			"RbxSceneManager::createStaticGeometry");
	}
	StaticGeometry* ret = new StaticGeometry(this, name);
	mStaticGeometryList[name] = ret;
	return ret;
}

// OgreSceneManager.cpp:5092
StaticGeometry* RbxSceneManager::getStaticGeometry(const String& name) const
{
	StaticGeometryList::const_iterator i = mStaticGeometryList.find(name);
	if (i == mStaticGeometryList.end())
	{
#line 5136 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"StaticGeometry with name '" + name + "' not found", 
			"RbxSceneManager::createStaticGeometry");
	}
	return i->second;
}

// OgreSceneManager.cpp:5104
bool RbxSceneManager::hasStaticGeometry(const String& name) const
{
	return (mStaticGeometryList.find(name) != mStaticGeometryList.end());
}

// OgreSceneManager.cpp:5110
void RbxSceneManager::destroyStaticGeometry(StaticGeometry* geom)
{
	destroyStaticGeometry(geom->getName());
}

// OgreSceneManager.cpp:5115
void RbxSceneManager::destroyStaticGeometry(const String& name)
{
	StaticGeometryList::iterator i = mStaticGeometryList.find(name);
	if (i != mStaticGeometryList.end())
	{
		delete i->second;
		mStaticGeometryList.erase(i);
	}

}

// OgreSceneManager.cpp:5126
void RbxSceneManager::destroyAllStaticGeometry(void)
{
	StaticGeometryList::iterator i, iend;
	iend = mStaticGeometryList.end();
	for (i = mStaticGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mStaticGeometryList.clear();
}

// OgreSceneManager.cpp:5137
InstancedGeometry* RbxSceneManager::createInstancedGeometry(const String& name)
{
	// Check not existing
	if (mInstancedGeometryList.find(name) != mInstancedGeometryList.end())
	{
#line 5181 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"InstancedGeometry with name '" + name + "' already exists!", 
			"RbxSceneManager::createInstancedGeometry");
	}
	InstancedGeometry* ret = new InstancedGeometry(this, name);
	mInstancedGeometryList[name] = ret;
	return ret;
}

// OgreSceneManager.cpp:5151
InstancedGeometry* RbxSceneManager::getInstancedGeometry(const String& name) const
{
	InstancedGeometryList::const_iterator i = mInstancedGeometryList.find(name);
	if (i == mInstancedGeometryList.end())
	{
#line 5195 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"InstancedGeometry with name '" + name + "' not found", 
			"RbxSceneManager::createInstancedGeometry");
	}
	return i->second;
}

// OgreSceneManager.cpp:5163
void RbxSceneManager::destroyInstancedGeometry(InstancedGeometry* geom)
{
	destroyInstancedGeometry(geom->getName());
}

// OgreSceneManager.cpp:5168
void RbxSceneManager::destroyInstancedGeometry(const String& name)
{
	InstancedGeometryList::iterator i = mInstancedGeometryList.find(name);
	if (i != mInstancedGeometryList.end())
	{
		delete i->second;
		mInstancedGeometryList.erase(i);
	}

}

// OgreSceneManager.cpp:5179
void RbxSceneManager::destroyAllInstancedGeometry(void)
{
	InstancedGeometryList::iterator i, iend;
	iend = mInstancedGeometryList.end();
	for (i = mInstancedGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mInstancedGeometryList.clear();
}

// OgreSceneManager.cpp:5191
AxisAlignedBoxSceneQuery* 
RbxSceneManager::createAABBQuery(const AxisAlignedBox& box, unsigned long mask)
{
    DefaultAxisAlignedBoxSceneQuery* q = new DefaultAxisAlignedBoxSceneQuery(this);
    q->setBox(box);
    q->setQueryMask(mask);
    return q;
}

// OgreSceneManager.cpp:5200
SphereSceneQuery* 
RbxSceneManager::createSphereQuery(const Sphere& sphere, unsigned long mask)
{
    DefaultSphereSceneQuery* q = new DefaultSphereSceneQuery(this);
    q->setSphere(sphere);
    q->setQueryMask(mask);
    return q;
}

// OgreSceneManager.cpp:5209
PlaneBoundedVolumeListSceneQuery* 
RbxSceneManager::createPlaneBoundedVolumeQuery(const PlaneBoundedVolumeList& volumes, 
                                            unsigned long mask)
{
    DefaultPlaneBoundedVolumeListSceneQuery* q = new DefaultPlaneBoundedVolumeListSceneQuery(this);
    q->setVolumes(volumes);
    q->setQueryMask(mask);
    return q;
}

// OgreSceneManager.cpp:5220
RaySceneQuery* 
RbxSceneManager::createRayQuery(const Ray& ray, unsigned long mask)
{
    DefaultRaySceneQuery* q = new DefaultRaySceneQuery(this);
    q->setRay(ray);
    q->setQueryMask(mask);
    return q;
}

// OgreSceneManager.cpp:5229
IntersectionSceneQuery* 
RbxSceneManager::createIntersectionQuery(unsigned long mask)
{

    DefaultIntersectionSceneQuery* q = new DefaultIntersectionSceneQuery(this);
    q->setQueryMask(mask);
    return q;
}

// OgreSceneManager.cpp:5237
void RbxSceneManager::destroyQuery(SceneQuery* query)
{
    delete query;
}

// OgreSceneManager.cpp:5243
SceneManager::MovableObjectCollection* 
RbxSceneManager::getMovableObjectCollection(const String& typeName)
{
	// lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::iterator i = 
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
	{
		// create
		MovableObjectCollection* newCollection = new MovableObjectCollection();
		mMovableObjectCollectionMap[typeName] = newCollection;
		return newCollection;
	}
	else
	{
		return i->second;
	}
}

// OgreSceneManager.cpp:5264
const SceneManager::MovableObjectCollection* 
RbxSceneManager::getMovableObjectCollection(const String& typeName) const
{
	// lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::const_iterator i = 
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
	{
#line 5312 ".\\RbxSceneManager.cpp"
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"Object collection named '" + typeName + "' does not exist.", 
			"RbxSceneManager::getMovableObjectCollection");
	}
	else
	{
		return i->second;
	}
}

// OgreSceneManager.cpp:5283
MovableObject* RbxSceneManager::createMovableObject(const String& name, 
	const String& typeName, const NameValuePairList* params)
{
	MovableObjectFactory* factory = 
		Root::getSingleton().getMovableObjectFactory(typeName);
	// Check for duplicate names
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		if (objectMap->map.find(name) != objectMap->map.end())
		{
#line 5335 ".\\RbxSceneManager.cpp"
			OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
				"An object of type '" + typeName + "' with name '" + name
				+ "' already exists.", 
				"RbxSceneManager::createMovableObject");
		}

		MovableObject* newObj = factory->createInstance(name, this, params);
		objectMap->map[name] = newObj;
		return newObj;
	}

}

// OgreSceneManager.cpp:5309
void RbxSceneManager::destroyMovableObject(const String& name, const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	MovableObjectFactory* factory = 
		Root::getSingleton().getMovableObjectFactory(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		MovableObjectMap::iterator mi = objectMap->map.find(name);
		if (mi != objectMap->map.end())
		{
			factory->destroyInstance(mi->second);
			objectMap->map.erase(mi);
		}
	}
}

// OgreSceneManager.cpp:5327
void RbxSceneManager::destroyAllMovableObjectsByType(const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	MovableObjectFactory* factory = 
		Root::getSingleton().getMovableObjectFactory(typeName);
	
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::iterator i = objectMap->map.begin();
		for (; i != objectMap->map.end(); ++i)
		{
			// Only destroy our own
			if (i->second->_getManager() == this)
			{
				factory->destroyInstance(i->second);
			}
		}
		objectMap->map.clear();
	}
}

// OgreSceneManager.cpp:5348
void RbxSceneManager::destroyAllMovableObjects(void)
{
	// Lock collection mutex
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::iterator ci = mMovableObjectCollectionMap.begin();

	for(;ci != mMovableObjectCollectionMap.end(); ++ci)
	{
		MovableObjectCollection* coll = ci->second;

		// lock map mutex
		OGRE_LOCK_MUTEX(coll->mutex)

		if (Root::getSingleton().hasMovableObjectFactory(ci->first))
		{
			// Only destroy if we have a factory instance; otherwise must be injected
			MovableObjectFactory* factory = 
				Root::getSingleton().getMovableObjectFactory(ci->first);
			MovableObjectMap::iterator i = coll->map.begin();
			for (; i != coll->map.end(); ++i)
			{
				if (i->second->_getManager() == this)
				{
					factory->destroyInstance(i->second);
				}
			}
		}
		coll->map.clear();
	}

}

// OgreSceneManager.cpp:5381
MovableObject* RbxSceneManager::getMovableObject(const String& name, const String& typeName) const
{
	const MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::const_iterator mi = objectMap->map.find(name);
		if (mi == objectMap->map.end())
		{
#line 5429 ".\\RbxSceneManager.cpp"
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
				"Object named '" + name + "' does not exist.", 
				"RbxSceneManager::getMovableObject");
		}
		return mi->second;
	}
	
}

// OgreSceneManager.cpp:5399
bool RbxSceneManager::hasMovableObject(const String& name, const String& typeName) const
{
	OGRE_LOCK_MUTEX(mMovableObjectCollectionMapMutex)

	MovableObjectCollectionMap::const_iterator i = 
		mMovableObjectCollectionMap.find(typeName);
	if (i == mMovableObjectCollectionMap.end())
		return false;
	
	{
		OGRE_LOCK_MUTEX(i->second->mutex)
		return (i->second->map.find(name) != i->second->map.end());
	}
}

// OgreSceneManager.cpp:5416
SceneManager::MovableObjectIterator 
RbxSceneManager::getMovableObjectIterator(const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	// Iterator not thread safe! Warned in header.
	return MovableObjectIterator(objectMap->map.begin(), objectMap->map.end());
}

// OgreSceneManager.cpp:5423
void RbxSceneManager::destroyMovableObject(MovableObject* m)
{
	destroyMovableObject(m->getName(), m->getMovableType());
}

// OgreSceneManager.cpp:5428
void RbxSceneManager::injectMovableObject(MovableObject* m)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(m->getMovableType());
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		objectMap->map[m->getName()] = m;
	}
}

// OgreSceneManager.cpp:5438
void RbxSceneManager::extractMovableObject(const String& name, const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::iterator mi = objectMap->map.find(name);
		if (mi != objectMap->map.end())
		{
			// no delete
			objectMap->map.erase(mi);
		}
	}

}

// OgreSceneManager.cpp:5453
void RbxSceneManager::extractMovableObject(MovableObject* m)
{
	extractMovableObject(m->getName(), m->getMovableType());
}

// OgreSceneManager.cpp:5458
void RbxSceneManager::extractAllMovableObjectsByType(const String& typeName)
{
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		// no deletion
		objectMap->map.clear();
	}
}

// OgreSceneManager.cpp:5468
void RbxSceneManager::_injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation )
{
	// render something as if it came from the current queue
    const Pass *usedPass = _setPass(pass, false, shadowDerivation);
    renderSingleObject(rend, usedPass, false);
}
// ---- fork bodies (differ from the Ogre 1.4.5 SceneManager bodies) ----

// Guard of findShadowCastersForLight; _renderScene 00698cc0 clears it (byte 0097dc38).
bool findingShadowCasters = false;

void RbxSceneManager::destroyCamera(Camera* cam)
{
	CamVisibleObjectsMap::iterator camVisObjIt = mCamVisibleObjectsMap.find(cam);
	if (camVisObjIt != mCamVisibleObjectsMap.end())
		mCamVisibleObjectsMap.erase(camVisObjIt);

	ShadowCamLightMapping::iterator camLightIt = mShadowCamLightMapping.find(cam);
	if (camLightIt != mShadowCamLightMapping.end())
		mShadowCamLightMapping.erase(camLightIt);

	for (CameraList::iterator i = mCameras.begin(); i != mCameras.end(); ++i)
	{
		if (i->second == cam)
		{
			mCameras.erase(i);
			mDestRenderSystem->_notifyCameraRemoved(cam);
			delete cam;
			return;
		}
	}
}

void RbxSceneManager::destroyCamera(const String& name)
{
	CameraList::iterator i = mCameras.find(name);
	if (i != mCameras.end())
	{
		mDestRenderSystem->_notifyCameraRemoved(i->second);
		delete i->second;
		mCameras.erase(i);
	}
}

void RbxSceneManager::destroyAllCameras(void)
{
	CameraList::iterator i = mCameras.begin();
	for (; i != mCameras.end(); ++i)
	{
		mDestRenderSystem->_notifyCameraRemoved(i->second);
		delete i->second;
	}
	mCameras.clear();
}

void RbxSceneManager::_populateLightList(const Vector3& position, Real radius,
	LightList& destList)
{
	const LightList& candidateLights = _getLightsAffectingFrustum();

	destList.clear();
	destList.reserve(candidateLights.size());

	LightList::const_iterator it;
	for (it = candidateLights.begin(); it != candidateLights.end(); ++it)
	{
		Light* lt = *it;
		if (lt->getType() == Light::LT_DIRECTIONAL)
		{
			lt->tempSquareDist = 0.0f;
			destList.push_back(lt);
		}
		else
		{
			lt->tempSquareDist = (lt->getDerivedPosition() - position).squaredLength();
			Real range = lt->getAttenuationRange();
			Real maxDist = range + radius;
			if (lt->tempSquareDist <= Math::Sqr(maxDist))
			{
				destList.push_back(lt);
			}
		}
	}

	if (isShadowTechniqueTextureBased())
	{
		if (destList.size() > mShadowTextureConfigList.size())
		{
			LightList::iterator start = destList.begin();
			std::advance(start, mShadowTextureConfigList.size());
			std::stable_sort(start, destList.end(), lightLess());
		}
	}
	else
	{
		std::stable_sort(destList.begin(), destList.end(), lightLess());
	}
}

void RbxSceneManager::_applySceneAnimations(void)
{
	OGRE_LOCK_MUTEX(mAnimationStates.OGRE_AUTO_MUTEX_NAME)

	ConstEnabledAnimationStateIterator stateIt = mAnimationStates.getEnabledAnimationStateIterator();

	while (stateIt.hasMoreElements())
	{
		const AnimationState* state = stateIt.getNext();
		Animation* anim = getAnimation(state->getAnimationName());

		Animation::NodeTrackIterator nodeTrackIt = anim->getNodeTrackIterator();
		while(nodeTrackIt.hasMoreElements())
		{
			Node* nd = nodeTrackIt.getNext()->getAssociatedNode();
			nd->resetToInitialState();
		}

		Animation::NumericTrackIterator numTrackIt = anim->getNumericTrackIterator();
		while(numTrackIt.hasMoreElements())
		{
			const AnimableValuePtr& animPtr = numTrackIt.getNext()->getAssociatedAnimable();
			animPtr->resetToBaseValue();
		}

		anim->apply(state->getTimePosition(), state->getWeight());
	}
}

void RbxSceneManager::manualRender(RenderOperation* rend,
	Pass* pass, Viewport* vp, const Matrix4& worldMatrix,
	const Matrix4& viewMatrix, const Matrix4& projMatrix,
	bool doBeginEndFrame)
{
	mDestRenderSystem->_setViewport(vp);
	mDestRenderSystem->_setWorldMatrix(worldMatrix);
	mDestRenderSystem->_setViewMatrix(viewMatrix);
	mDestRenderSystem->_setProjectionMatrix(projMatrix);

	if (doBeginEndFrame)
		mDestRenderSystem->_beginFrame();

	_setPass(pass);
	mDestRenderSystem->_render(*rend);

	if (doBeginEndFrame)
		mDestRenderSystem->_endFrame();
}

void RbxSceneManager::renderBasicQueueGroupObjects(RenderQueueGroup* pGroup,
	QueuedRenderableCollection::OrganisationMode om)
{
	RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();
	Timer timer;

	while (groupIt.hasMoreElements())
	{
		RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

		timer.reset();
		pPriorityGrp->sort(mCameraInProgress);
		timer.getMicroseconds();

		timer.reset();
		renderObjects(pPriorityGrp->getSolidsBasic(), om, true);
		timer.getMicroseconds();

		timer.reset();
		renderObjects(pPriorityGrp->getTransparents(),
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);
		timer.getMicroseconds();
	}
}

void RbxSceneManager::_renderScene(Camera* camera, Viewport* vp, bool includeOverlays)
{
    findingShadowCasters = false;   // fork: reset the guard of findShadowCastersForLight (0097dc38)
    mPassLightingEnabled = true;
    mLightsLightingEnabled = false;

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

    Timer renderTimer;

    {
        OGRE_LOCK_MUTEX(sceneGraphMutex)

        renderTimer.reset();
        _updateSceneGraph(camera);
        renderTimer.getMicroseconds();

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

        renderTimer.reset();
        prepareRenderQueue();
        renderTimer.getMicroseconds();

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

    renderTimer.reset();
    _renderVisibleObjects();
    renderTimer.getMicroseconds();

    mDestRenderSystem->_endFrame();

    camera->_notifyRenderedFaces(mDestRenderSystem->_getFaceCount());
    camera->_notifyRenderedBatches(mDestRenderSystem->_getBatchCount());
}

// RbxSky::update 0067f850 is declared in OgreRbx/RbxSky2008.h (minimal interface, no layout claimed).
void RbxSceneManager::_queueSkiesForRendering(Camera* cam)
{
	if (mSkyPlaneNode)
	{
		mSkyPlaneNode->setPosition(cam->getDerivedPosition());
	}

	if (mSkyBoxNode)
	{
		mSkyBoxNode->setPosition(cam->getDerivedPosition());
		mRbxSkyNode->setPosition(cam->getDerivedPosition());
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
		if (RbxSky* sky = mRbxSky.getPointer())
			sky->update(cam, getRenderQueue(), qid);
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

#ifdef NATIVE_OGRE_RBXSCENEMANAGER_PENDING
// Pending-build-only body: it needs a declaration of the exe-local Ogre::RbxEntity (collect) that no native header
// provides yet (see the recorder's proposal header).

const SceneManager::ShadowCasterList& RbxSceneManager::findShadowCastersForLight(
	const Light* light, const Camera* camera)
{
	if (findingShadowCasters == true)
		throw std::exception("findShadowCastersForLight call repeated");
	findingShadowCasters = true;

	mShadowCasterList.clear();

	SceneNode* root = dynamic_cast<SceneNode*>(mSceneRoot->getChild("rbxroot"));
	if (!root)
	{
		LogManager::getSingleton().logMessage("RBX Missing or duplicate world node", LML_NORMAL);
	}
	else
	{
		if (root->getAttachedObjectIterator().hasMoreElements())
		{
			RbxEntity* entity = dynamic_cast<RbxEntity*>(root->getAttachedObject(0));
			entity->collect(camera, light, mShadowCasterList);
		}
	}
	return mShadowCasterList;
}
#endif

}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class Ogre::ConstMapIterator<std::map<unsigned short,Ogre::NodeAnimationTrack *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::NodeAnimationTrack *> > > >;
template class Ogre::ConstMapIterator<std::map<unsigned short,Ogre::NumericAnimationTrack *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::NumericAnimationTrack *> > > >;
template class Ogre::ConstVectorIterator<std::list<Ogre::AnimationState *,std::allocator<Ogre::AnimationState *> > >;
template class Ogre::ConstVectorIterator<std::vector<Ogre::TextureUnitState *,std::allocator<Ogre::TextureUnitState *> > >;
template class Ogre::MapIterator<std::map<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MovableObject *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> > > >;
template class Ogre::MapIterator<std::map<unsigned char,Ogre::RenderQueueGroup *,std::less<unsigned char>,std::allocator<std::pair<unsigned char const ,Ogre::RenderQueueGroup *> > > >;
template class Ogre::MapIterator<std::map<unsigned short,Ogre::RenderPriorityGroup *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::RenderPriorityGroup *> > > >;
template class Ogre::SharedPtr<Ogre::AnimableValue>;
template class Ogre::SharedPtr<Ogre::DataStream>;
template class Ogre::SharedPtr<Ogre::GpuProgramParameters>;
template class Ogre::SharedPtr<Ogre::RbxSky>;
template class Ogre::SharedPtr<Ogre::Resource>;
template class Ogre::SharedPtr<Ogre::ShadowCameraSetup>;
template class Ogre::VectorIterator<std::vector<Ogre::RenderQueueInvocation *,std::allocator<Ogre::RenderQueueInvocation *> > >;
template class Ogre::VectorIterator<std::vector<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::Light *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::SceneManager::LightInfo> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> > >;
template class std::_Revranit<std::_Vector_iterator<Ogre::ShadowListener *,std::allocator<Ogre::ShadowListener *> >,std::iterator<std::random_access_iterator_tag,Ogre::ShadowListener *,int,Ogre::ShadowListener * *,Ogre::ShadowListener * &> >;
template class std::_Tmap_traits<Ogre::Camera const *,Ogre::Light const *,std::less<Ogre::Camera const *>,std::allocator<std::pair<Ogre::Camera const * const,Ogre::Light const *> >,0>;
template class std::_Tmap_traits<Ogre::Camera const *,Ogre::VisibleObjectsBoundsInfo,std::less<Ogre::Camera const *>,std::allocator<std::pair<Ogre::Camera const * const,Ogre::VisibleObjectsBoundsInfo> >,0>;
template class std::_Tree<std::_Tmap_traits<Ogre::Camera const *,Ogre::Light const *,std::less<Ogre::Camera const *>,std::allocator<std::pair<Ogre::Camera const * const,Ogre::Light const *> >,0> >;
template class std::_Tree<std::_Tmap_traits<Ogre::Camera const *,Ogre::VisibleObjectsBoundsInfo,std::less<Ogre::Camera const *>,std::allocator<std::pair<Ogre::Camera const * const,Ogre::VisibleObjectsBoundsInfo> >,0> >;
template class std::_Tree<std::_Tmap_traits<enum Ogre::TextureUnitState::TextureEffectType,Ogre::TextureUnitState::TextureEffect,std::less<enum Ogre::TextureUnitState::TextureEffectType>,std::allocator<std::pair<enum Ogre::TextureUnitState::TextureEffectType const ,Ogre::TextureUnitState::TextureEffect> >,1> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::Animation *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Animation *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::Camera *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Camera *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::InstancedGeometry *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::InstancedGeometry *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MovableObject *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneManager::MovableObjectCollection *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneManager::MovableObjectCollection *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::SceneNode *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >,0> >;
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::StaticGeometry *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::StaticGeometry *> >,0> >;
template class std::_Tree<std::_Tmap_traits<unsigned char,Ogre::RenderQueueGroup *,std::less<unsigned char>,std::allocator<std::pair<unsigned char const ,Ogre::RenderQueueGroup *> >,0> >;
template class std::_Tree<std::_Tmap_traits<unsigned short,Ogre::NodeAnimationTrack *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::NodeAnimationTrack *> >,0> >;
template class std::_Tree<std::_Tmap_traits<unsigned short,Ogre::NumericAnimationTrack *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::NumericAnimationTrack *> >,0> >;
template class std::_Tree<std::_Tmap_traits<unsigned short,Ogre::RenderPriorityGroup *,std::less<unsigned short>,std::allocator<std::pair<unsigned short const ,Ogre::RenderPriorityGroup *> >,0> >;
template class std::_Tree<std::_Tset_traits<Ogre::SceneNode *,std::less<Ogre::SceneNode *>,std::allocator<Ogre::SceneNode *>,0> >;
template class std::_Tree<std::_Tset_traits<unsigned char,std::less<unsigned char>,std::allocator<unsigned char>,0> >;
template class std::_Vector_const_iterator<Ogre::Camera *,std::allocator<Ogre::Camera *> >;
template class std::_Vector_const_iterator<Ogre::Light *,std::allocator<Ogre::Light *> >;
template class std::_Vector_const_iterator<Ogre::PlaneBoundedVolume,std::allocator<Ogre::PlaneBoundedVolume> >;
template class std::_Vector_const_iterator<Ogre::RenderQueueInvocation *,std::allocator<Ogre::RenderQueueInvocation *> >;
template class std::_Vector_const_iterator<Ogre::RenderQueueListener *,std::allocator<Ogre::RenderQueueListener *> >;
template class std::_Vector_const_iterator<Ogre::SceneManager::LightInfo,std::allocator<Ogre::SceneManager::LightInfo> >;
template class std::_Vector_const_iterator<Ogre::ShadowCaster *,std::allocator<Ogre::ShadowCaster *> >;
template class std::_Vector_const_iterator<Ogre::ShadowListener *,std::allocator<Ogre::ShadowListener *> >;
template class std::_Vector_const_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >;
template class std::_Vector_const_iterator<Ogre::ShadowTextureConfig,std::allocator<Ogre::ShadowTextureConfig> >;
template class std::_Vector_const_iterator<Ogre::TexturePtr,std::allocator<Ogre::TexturePtr> >;
template class std::_Vector_const_iterator<Ogre::TextureUnitState *,std::allocator<Ogre::TextureUnitState *> >;
template class std::_Vector_iterator<Ogre::Camera *,std::allocator<Ogre::Camera *> >;
template class std::_Vector_iterator<Ogre::Light *,std::allocator<Ogre::Light *> >;
template class std::_Vector_iterator<Ogre::RenderQueueInvocation *,std::allocator<Ogre::RenderQueueInvocation *> >;
template class std::_Vector_iterator<Ogre::RenderQueueListener *,std::allocator<Ogre::RenderQueueListener *> >;
template class std::_Vector_iterator<Ogre::SceneManager::LightInfo,std::allocator<Ogre::SceneManager::LightInfo> >;
template class std::_Vector_iterator<Ogre::ShadowCaster *,std::allocator<Ogre::ShadowCaster *> >;
template class std::_Vector_iterator<Ogre::ShadowListener *,std::allocator<Ogre::ShadowListener *> >;
template class std::_Vector_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >;
template class std::_Vector_iterator<Ogre::ShadowTextureConfig,std::allocator<Ogre::ShadowTextureConfig> >;
template class std::_Vector_iterator<Ogre::TexturePtr,std::allocator<Ogre::TexturePtr> >;
template class std::allocator<Ogre::SceneNode *>;
template class std::allocator<Ogre::TexturePtr>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,Ogre::MovableObject *,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> >,0> >::_Node *>;
template class std::allocator<std::pair<Ogre::Camera const * const,Ogre::Light const *> >;
template class std::allocator<std::pair<Ogre::Camera const * const,Ogre::VisibleObjectsBoundsInfo> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Animation *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::Camera *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::InstancedGeometry *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::MovableObject *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneManager::MovableObjectCollection *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::SceneNode *> >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,Ogre::StaticGeometry *> >;
template class std::allocator<unsigned char>;
template class std::deque<unsigned long,std::allocator<unsigned long> >;
template class std::list<Ogre::AnimationState *,std::allocator<Ogre::AnimationState *> >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::ShadowListener *,std::allocator<Ogre::ShadowListener *> > >;
template class std::vector<Ogre::Camera *,std::allocator<Ogre::Camera *> >;
template class std::vector<Ogre::Light *,std::allocator<Ogre::Light *> >;
template class std::vector<Ogre::Plane,std::allocator<Ogre::Plane> >;
template class std::vector<Ogre::PlaneBoundedVolume,std::allocator<Ogre::PlaneBoundedVolume> >;
template class std::vector<Ogre::RenderQueueListener *,std::allocator<Ogre::RenderQueueListener *> >;
template class std::vector<Ogre::SceneManager::LightInfo,std::allocator<Ogre::SceneManager::LightInfo> >;
template class std::vector<Ogre::ShadowCaster *,std::allocator<Ogre::ShadowCaster *> >;
template class std::vector<Ogre::ShadowListener *,std::allocator<Ogre::ShadowListener *> >;
template class std::vector<Ogre::ShadowTextureConfig,std::allocator<Ogre::ShadowTextureConfig> >;
template class std::vector<Ogre::TexturePtr,std::allocator<Ogre::TexturePtr> >;
