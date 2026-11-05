// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_short_methods_5b192b39c746b09e.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
struct HeaderRecovery : Ogre::SceneManager {
RenderQueue* recover_getRenderQueue(void);
void recover_addSpecialCaseRenderQueue(uint8 qid);
void recover_removeSpecialCaseRenderQueue(uint8 qid);
void recover_clearSpecialCaseRenderQueues(void);
void recover_setSpecialCaseRenderQueueMode(SceneManager::SpecialCaseRenderQueueMode mode);
bool recover_isRenderQueueToBeProcessed(uint8 qid);
void recover_setWorldGeometryRenderQueue(uint8 qid);
uint8 recover_getWorldGeometryRenderQueue(void);
bool recover_hasCamera(const String& name) const;
void recover_destroyCamera(Camera *cam);
Light* recover_createLight(const String& name);
Light* recover_getLight(const String& name) const;
bool recover_hasLight(const String& name) const;
void recover_destroyLight(Light *l);
void recover_destroyLight(const String& name);
void recover_destroyAllLights(void);
const LightList& recover__getLightsAffectingFrustum(void) const;
Entity* recover_createEntity(
                                   const String& entityName,
                                   const String& meshName );
Entity* recover_getEntity(const String& name) const;
bool recover_hasEntity(const String& name) const;
void recover_destroyEntity(Entity *e);
void recover_destroyEntity(const String& name);
void recover_destroyAllEntities(void);
void recover_destroyAllBillboardSets(void);
ManualObject* recover_createManualObject(const String& name);
ManualObject* recover_getManualObject(const String& name) const;
bool recover_hasManualObject(const String& name) const;
void recover_destroyManualObject(ManualObject* obj);
void recover_destroyManualObject(const String& name);
void recover_destroyAllManualObjects(void);
BillboardChain* recover_createBillboardChain(const String& name);
BillboardChain* recover_getBillboardChain(const String& name) const;
bool recover_hasBillboardChain(const String& name) const;
void recover_destroyBillboardChain(BillboardChain* obj);
void recover_destroyBillboardChain(const String& name);
void recover_destroyAllBillboardChains(void);
RibbonTrail* recover_createRibbonTrail(const String& name);
RibbonTrail* recover_getRibbonTrail(const String& name) const;
bool recover_hasRibbonTrail(const String& name) const;
void recover_destroyRibbonTrail(RibbonTrail* obj);
void recover_destroyRibbonTrail(const String& name);
void recover_destroyAllRibbonTrails(void);
bool recover_hasParticleSystem(const String& name) const;
void recover_destroyParticleSystem(ParticleSystem* obj);
void recover_destroyParticleSystem(const String& name);
void recover_destroyAllParticleSystems(void);
SceneNode* recover_createSceneNode(void);
SceneNode* recover_getRootSceneNode(void) const;
bool recover_hasSceneNode(const String& name) const;
void recover__setDestinationRenderSystem(RenderSystem* sys);
void recover_setWorldGeometry(const String& filename);
void recover_setWorldGeometry(DataStreamPtr& stream, 
	const String& typeName);
void recover__findVisibleObjects(
	Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters);
void recover_setAmbientLight(const ColourValue& colour);
const ColourValue& recover_getAmbientLight(void) const;
void recover_setFog(FogMode mode, const ColourValue& colour, Real density, Real start, Real end);
const ColourValue& recover_getFogColour(void) const;
Real recover_getFogStart(void) const;
Real recover_getFogEnd(void) const;
Real recover_getFogDensity(void) const;
bool recover_hasBillboardSet(const String& name) const;
void recover_destroyBillboardSet(BillboardSet* set);
void recover_destroyBillboardSet(const String& name);
void recover_setDisplaySceneNodes(bool display);
bool recover_hasAnimation(const String& name) const;
bool recover_hasAnimationState(const String& name) const;
void recover_destroyAnimationState(const String& name);
void recover_destroyAllAnimationStates(void);
void recover_addRenderQueueListener(RenderQueueListener* newListener);
void recover_addShadowListener(ShadowListener* newListener);
void recover_fireShadowTexturesUpdated(size_t numberOfShadowTextures);
void recover_fireShadowTexturesPreCaster(Light* light, Camera* camera);
void recover_fireShadowTexturesPreReceiver(Light* light, Frustum* f);
void recover_setViewport(Viewport* vp);
void recover_showBoundingBoxes(bool bShow);
bool recover_getShowBoundingBoxes() const;
void recover__notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack);
void recover__suppressShadows(bool suppress);
void recover__suppressRenderStateChanges(bool suppress);
void recover__notifyLightsDirty(void);
const ColourValue& recover_getShadowColour(void) const;
void recover_setShadowFarDistance(Real distance);
void recover_setShadowDirectionalLightExtrusionDistance(Real dist);
Real recover_getShadowDirectionalLightExtrusionDistance(void) const;
void recover_setShadowTextureConfig(size_t shadowIndex, unsigned short width, 
	unsigned short height, PixelFormat format);
void recover_setShadowTextureCount(size_t count);
void recover_setShadowTexturePixelFormat(PixelFormat fmt);
const TexturePtr& recover_getShadowTexture(size_t shadowIndex);
void recover_setShadowTextureSelfShadow(bool selfShadow);
void recover_setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup);
const ShadowCameraSetupPtr& recover_getShadowCameraSetup() const;
bool recover_hasStaticGeometry(const String& name) const;
void recover_destroyStaticGeometry(StaticGeometry* geom);
void recover_destroyStaticGeometry(const String& name);
void recover_destroyAllStaticGeometry(void);
void recover_destroyInstancedGeometry(InstancedGeometry* geom);
void recover_destroyInstancedGeometry(const String& name);
void recover_destroyAllInstancedGeometry(void);
void recover_destroyQuery(SceneQuery* query);
void recover_destroyMovableObject(MovableObject* m);
void recover_injectMovableObject(MovableObject* m);
void recover_extractMovableObject(MovableObject* m);
void recover_extractAllMovableObjectsByType(const String& typeName);
void recover__injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation );
uint32 recover__getCombinedVisibilityMask(void) const;
void recover_setQueuedRenderableVisitor(SceneManager::SceneMgrQueuedRenderableVisitor* visitor);
};
RenderQueue* HeaderRecovery::recover_getRenderQueue(void) {
    if (!mRenderQueue)
    {
        initRenderQueue();
    }
    return mRenderQueue;
}
void HeaderRecovery::recover_addSpecialCaseRenderQueue(uint8 qid) {
	mSpecialCaseQueueList.insert(qid);
}
void HeaderRecovery::recover_removeSpecialCaseRenderQueue(uint8 qid) {
	mSpecialCaseQueueList.erase(qid);
}
void HeaderRecovery::recover_clearSpecialCaseRenderQueues(void) {
	mSpecialCaseQueueList.clear();
}
void HeaderRecovery::recover_setSpecialCaseRenderQueueMode(SceneManager::SpecialCaseRenderQueueMode mode) {
	mSpecialCaseQueueMode = mode;
}
bool HeaderRecovery::recover_isRenderQueueToBeProcessed(uint8 qid) {
	bool inList = mSpecialCaseQueueList.find(qid) != mSpecialCaseQueueList.end();
	return (inList && mSpecialCaseQueueMode == SCRQM_INCLUDE)
		|| (!inList && mSpecialCaseQueueMode == SCRQM_EXCLUDE);
}
void HeaderRecovery::recover_setWorldGeometryRenderQueue(uint8 qid) {
	mWorldGeometryRenderQueue = qid;
}
uint8 HeaderRecovery::recover_getWorldGeometryRenderQueue(void) {
	return mWorldGeometryRenderQueue;
}
bool HeaderRecovery::recover_hasCamera(const String& name) const {
	return (mCameras.find(name) != mCameras.end());
}
void HeaderRecovery::recover_destroyCamera(Camera *cam) {
	destroyCamera(cam->getName());

}
Light* HeaderRecovery::recover_createLight(const String& name) {
	return static_cast<Light*>(
		createMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}
Light* HeaderRecovery::recover_getLight(const String& name) const {
	return static_cast<Light*>(
		getMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}
bool HeaderRecovery::recover_hasLight(const String& name) const {
	return hasMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyLight(Light *l) {
	destroyMovableObject(l);
}
void HeaderRecovery::recover_destroyLight(const String& name) {
	destroyMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllLights(void) {
	destroyAllMovableObjectsByType(LightFactory::FACTORY_TYPE_NAME);
}
const LightList& HeaderRecovery::recover__getLightsAffectingFrustum(void) const {
    return mLightsAffectingFrustum;
}
Entity* HeaderRecovery::recover_createEntity(
                                   const String& entityName,
                                   const String& meshName ) {
	// delegate to factory implementation
	NameValuePairList params;
	params["mesh"] = meshName;
	return static_cast<Entity*>(
		createMovableObject(entityName, EntityFactory::FACTORY_TYPE_NAME, 
			&params));

}
Entity* HeaderRecovery::recover_getEntity(const String& name) const {
	return static_cast<Entity*>(
		getMovableObject(name, EntityFactory::FACTORY_TYPE_NAME));
}
bool HeaderRecovery::recover_hasEntity(const String& name) const {
	return hasMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyEntity(Entity *e) {
	destroyMovableObject(e);
}
void HeaderRecovery::recover_destroyEntity(const String& name) {
	destroyMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);

}
void HeaderRecovery::recover_destroyAllEntities(void) {

	destroyAllMovableObjectsByType(EntityFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllBillboardSets(void) {
	destroyAllMovableObjectsByType(BillboardSetFactory::FACTORY_TYPE_NAME);
}
ManualObject* HeaderRecovery::recover_createManualObject(const String& name) {
	return static_cast<ManualObject*>(
		createMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));
}
ManualObject* HeaderRecovery::recover_getManualObject(const String& name) const {
	return static_cast<ManualObject*>(
		getMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));

}
bool HeaderRecovery::recover_hasManualObject(const String& name) const {
	return hasMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);

}
void HeaderRecovery::recover_destroyManualObject(ManualObject* obj) {
	destroyMovableObject(obj);
}
void HeaderRecovery::recover_destroyManualObject(const String& name) {
	destroyMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllManualObjects(void) {
	destroyAllMovableObjectsByType(ManualObjectFactory::FACTORY_TYPE_NAME);
}
BillboardChain* HeaderRecovery::recover_createBillboardChain(const String& name) {
	return static_cast<BillboardChain*>(
		createMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));
}
BillboardChain* HeaderRecovery::recover_getBillboardChain(const String& name) const {
	return static_cast<BillboardChain*>(
		getMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));

}
bool HeaderRecovery::recover_hasBillboardChain(const String& name) const {
	return hasMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyBillboardChain(BillboardChain* obj) {
	destroyMovableObject(obj);
}
void HeaderRecovery::recover_destroyBillboardChain(const String& name) {
	destroyMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllBillboardChains(void) {
	destroyAllMovableObjectsByType(BillboardChainFactory::FACTORY_TYPE_NAME);
}
RibbonTrail* HeaderRecovery::recover_createRibbonTrail(const String& name) {
	return static_cast<RibbonTrail*>(
		createMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));
}
RibbonTrail* HeaderRecovery::recover_getRibbonTrail(const String& name) const {
	return static_cast<RibbonTrail*>(
		getMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));

}
bool HeaderRecovery::recover_hasRibbonTrail(const String& name) const {
	return hasMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyRibbonTrail(RibbonTrail* obj) {
	destroyMovableObject(obj);
}
void HeaderRecovery::recover_destroyRibbonTrail(const String& name) {
	destroyMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllRibbonTrails(void) {
	destroyAllMovableObjectsByType(RibbonTrailFactory::FACTORY_TYPE_NAME);
}
bool HeaderRecovery::recover_hasParticleSystem(const String& name) const {
	return hasMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyParticleSystem(ParticleSystem* obj) {
	destroyMovableObject(obj);
}
void HeaderRecovery::recover_destroyParticleSystem(const String& name) {
	destroyMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyAllParticleSystems(void) {
	destroyAllMovableObjectsByType(ParticleSystemFactory::FACTORY_TYPE_NAME);
}
SceneNode* HeaderRecovery::recover_createSceneNode(void) {
    SceneNode* sn = new SceneNode(this);
    assert(mSceneNodes.find(sn->getName()) == mSceneNodes.end());
    mSceneNodes[sn->getName()] = sn;
    return sn;
}
SceneNode* HeaderRecovery::recover_getRootSceneNode(void) const {
    return mSceneRoot;
}
bool HeaderRecovery::recover_hasSceneNode(const String& name) const {
	return (mSceneNodes.find(name) != mSceneNodes.end());
}
void HeaderRecovery::recover__setDestinationRenderSystem(RenderSystem* sys) {
    mDestRenderSystem = sys;

}
void HeaderRecovery::recover_setWorldGeometry(const String& filename) {
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "SceneManager::setWorldGeometry");
}
void HeaderRecovery::recover_setWorldGeometry(DataStreamPtr& stream, 
	const String& typeName) {
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "SceneManager::setWorldGeometry");
}
void HeaderRecovery::recover__findVisibleObjects(
	Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters) {
    // Tell nodes to find, cascade down all nodes
    mSceneRoot->_findVisibleObjects(cam, getRenderQueue(), visibleBounds, true, 
        mDisplayNodes, onlyShadowCasters);

}
void HeaderRecovery::recover_setAmbientLight(const ColourValue& colour) {
    mAmbientLight = colour;
}
const ColourValue& HeaderRecovery::recover_getAmbientLight(void) const {
    return mAmbientLight;
}
void HeaderRecovery::recover_setFog(FogMode mode, const ColourValue& colour, Real density, Real start, Real end) {
    mFogMode = mode;
    mFogColour = colour;
    mFogStart = start;
    mFogEnd = end;
    mFogDensity = density;
}
const ColourValue& HeaderRecovery::recover_getFogColour(void) const {
    return mFogColour;
}
Real HeaderRecovery::recover_getFogStart(void) const {
    return mFogStart;
}
Real HeaderRecovery::recover_getFogEnd(void) const {
    return mFogEnd;
}
Real HeaderRecovery::recover_getFogDensity(void) const {
    return mFogDensity;
}
bool HeaderRecovery::recover_hasBillboardSet(const String& name) const {
	return hasMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_destroyBillboardSet(BillboardSet* set) {
	destroyMovableObject(set);
}
void HeaderRecovery::recover_destroyBillboardSet(const String& name) {
	destroyMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}
void HeaderRecovery::recover_setDisplaySceneNodes(bool display) {
    mDisplayNodes = display;
}
bool HeaderRecovery::recover_hasAnimation(const String& name) const {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)
	return (mAnimationsList.find(name) != mAnimationsList.end());
}
bool HeaderRecovery::recover_hasAnimationState(const String& name) const {
	return mAnimationStates.hasAnimationState(name);
}
void HeaderRecovery::recover_destroyAnimationState(const String& name) {
	mAnimationStates.removeAnimationState(name);
}
void HeaderRecovery::recover_destroyAllAnimationStates(void) {
    mAnimationStates.removeAllAnimationStates();
}
void HeaderRecovery::recover_addRenderQueueListener(RenderQueueListener* newListener) {
    mRenderQueueListeners.push_back(newListener);
}
void HeaderRecovery::recover_addShadowListener(ShadowListener* newListener) {
    mShadowListeners.push_back(newListener);
}
void HeaderRecovery::recover_fireShadowTexturesUpdated(size_t numberOfShadowTextures) {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTexturesUpdated(numberOfShadowTextures);
    }
}
void HeaderRecovery::recover_fireShadowTexturesPreCaster(Light* light, Camera* camera) {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureCasterPreViewProj(light, camera);
    }
}
void HeaderRecovery::recover_fireShadowTexturesPreReceiver(Light* light, Frustum* f) {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureReceiverPreViewProj(light, f);
    }
}
void HeaderRecovery::recover_setViewport(Viewport* vp) {
    mCurrentViewport = vp;
    // Set viewport in render system
    mDestRenderSystem->_setViewport(vp);
	// Set the active material scheme for this viewport
	MaterialManager::getSingleton().setActiveScheme(vp->getMaterialScheme());
}
void HeaderRecovery::recover_showBoundingBoxes(bool bShow) {
    mShowBoundingBoxes = bShow;
}
bool HeaderRecovery::recover_getShowBoundingBoxes() const {
    return mShowBoundingBoxes;
}
void HeaderRecovery::recover__notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack) {
    if (autoTrack)
    {
        mAutoTrackingSceneNodes.insert(node);
    }
    else
    {
        mAutoTrackingSceneNodes.erase(node);
    }
}
void HeaderRecovery::recover__suppressShadows(bool suppress) {
	mSuppressShadows = suppress;
}
void HeaderRecovery::recover__suppressRenderStateChanges(bool suppress) {
	mSuppressRenderStateChanges = suppress;
}
void HeaderRecovery::recover__notifyLightsDirty(void) {
    ++mLightsDirtyCounter;
}
const ColourValue& HeaderRecovery::recover_getShadowColour(void) const {
    return mShadowColour;
}
void HeaderRecovery::recover_setShadowFarDistance(Real distance) {
    mShadowFarDist = distance;
    mShadowFarDistSquared = distance * distance;
}
void HeaderRecovery::recover_setShadowDirectionalLightExtrusionDistance(Real dist) {
    mShadowDirLightExtrudeDist = dist;
}
Real HeaderRecovery::recover_getShadowDirectionalLightExtrusionDistance(void) const {
    return mShadowDirLightExtrudeDist;
}
void HeaderRecovery::recover_setShadowTextureConfig(size_t shadowIndex, unsigned short width, 
	unsigned short height, PixelFormat format) {
	ShadowTextureConfig conf;
	conf.width = width;
	conf.height = height;
	conf.format = format;

	setShadowTextureConfig(shadowIndex, conf);


}
void HeaderRecovery::recover_setShadowTextureCount(size_t count) {
    // Change size, any new items will take default
	if (count != mShadowTextureConfigList.size())
	{
		mShadowTextureConfigList.resize(count);
		mShadowTextureConfigDirty = true;
	}
}
void HeaderRecovery::recover_setShadowTexturePixelFormat(PixelFormat fmt) {
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
const TexturePtr& HeaderRecovery::recover_getShadowTexture(size_t shadowIndex) {
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"SceneManager::getShadowTexture");
	}
	ensureShadowTexturesCreated();

	return mShadowTextures[shadowIndex];


}
void HeaderRecovery::recover_setShadowTextureSelfShadow(bool selfShadow) { 
	mShadowTextureSelfShadow = selfShadow;
	if (isShadowTechniqueTextureBased())
		getRenderQueue()->setShadowCastersCannotBeReceivers(!selfShadow);
}
void HeaderRecovery::recover_setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup) {
	mDefaultShadowCameraSetup = shadowSetup;

}
const ShadowCameraSetupPtr& HeaderRecovery::recover_getShadowCameraSetup() const {
	return mDefaultShadowCameraSetup;
}
bool HeaderRecovery::recover_hasStaticGeometry(const String& name) const {
	return (mStaticGeometryList.find(name) != mStaticGeometryList.end());
}
void HeaderRecovery::recover_destroyStaticGeometry(StaticGeometry* geom) {
	destroyStaticGeometry(geom->getName());
}
void HeaderRecovery::recover_destroyStaticGeometry(const String& name) {
	StaticGeometryList::iterator i = mStaticGeometryList.find(name);
	if (i != mStaticGeometryList.end())
	{
		delete i->second;
		mStaticGeometryList.erase(i);
	}

}
void HeaderRecovery::recover_destroyAllStaticGeometry(void) {
	StaticGeometryList::iterator i, iend;
	iend = mStaticGeometryList.end();
	for (i = mStaticGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mStaticGeometryList.clear();
}
void HeaderRecovery::recover_destroyInstancedGeometry(InstancedGeometry* geom) {
	destroyInstancedGeometry(geom->getName());
}
void HeaderRecovery::recover_destroyInstancedGeometry(const String& name) {
	InstancedGeometryList::iterator i = mInstancedGeometryList.find(name);
	if (i != mInstancedGeometryList.end())
	{
		delete i->second;
		mInstancedGeometryList.erase(i);
	}

}
void HeaderRecovery::recover_destroyAllInstancedGeometry(void) {
	InstancedGeometryList::iterator i, iend;
	iend = mInstancedGeometryList.end();
	for (i = mInstancedGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mInstancedGeometryList.clear();
}
void HeaderRecovery::recover_destroyQuery(SceneQuery* query) {
    delete query;
}
void HeaderRecovery::recover_destroyMovableObject(MovableObject* m) {
	destroyMovableObject(m->getName(), m->getMovableType());
}
void HeaderRecovery::recover_injectMovableObject(MovableObject* m) {
	MovableObjectCollection* objectMap = getMovableObjectCollection(m->getMovableType());
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		objectMap->map[m->getName()] = m;
	}
}
void HeaderRecovery::recover_extractMovableObject(MovableObject* m) {
	extractMovableObject(m->getName(), m->getMovableType());
}
void HeaderRecovery::recover_extractAllMovableObjectsByType(const String& typeName) {
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		// no deletion
		objectMap->map.clear();
	}
}
void HeaderRecovery::recover__injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation ) {
	// render something as if it came from the current queue
    const Pass *usedPass = _setPass(pass, false, shadowDerivation);
    renderSingleObject(rend, usedPass, false);
}
uint32 HeaderRecovery::recover__getCombinedVisibilityMask(void) const {
	return mCurrentViewport ?
		mCurrentViewport->getVisibilityMask() & mVisibilityMask : mVisibilityMask;

}
void HeaderRecovery::recover_setQueuedRenderableVisitor(SceneManager::SceneMgrQueuedRenderableVisitor* visitor) {
	if (visitor)
		mActiveQueuedRenderableVisitor = visitor;
	else
		mActiveQueuedRenderableVisitor = &mDefaultQueuedRenderableVisitor;
}
