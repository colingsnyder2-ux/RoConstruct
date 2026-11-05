// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_fork_ea71c50b47f88007.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <OgreSpotShadowFadePng.h>
#include <OgreShadowVolumeExtrudeProgram.h>

namespace Ogre {
class RbxSceneManager : public SceneManager {
public:
    RenderQueue* getRenderQueue(void) ;
    void initRenderQueue(void) ;
    void addSpecialCaseRenderQueue(uint8 qid) ;
    void removeSpecialCaseRenderQueue(uint8 qid) ;
    void clearSpecialCaseRenderQueues(void) ;
    void setSpecialCaseRenderQueueMode(SceneManager::SpecialCaseRenderQueueMode mode) ;
    SceneManager::SpecialCaseRenderQueueMode getSpecialCaseRenderQueueMode(void) ;
    bool isRenderQueueToBeProcessed(uint8 qid) ;
    void setWorldGeometryRenderQueue(uint8 qid) ;
    uint8 getWorldGeometryRenderQueue(void) ;
    Camera* createCamera(const String& name) ;
    Camera* getCamera(const String& name) const;
    bool hasCamera(const String& name) const;
    void destroyCamera(Camera *cam) ;
    void destroyCamera(const String& name) ;
    void destroyAllCameras(void) ;
    Light* createLight(const String& name) ;
    Light* getLight(const String& name) const;
    bool hasLight(const String& name) const;
    void destroyLight(Light *l) ;
    void destroyLight(const String& name) ;
    void destroyAllLights(void) ;
    const LightList& _getLightsAffectingFrustum(void) const;
    void _populateLightList(const Vector3& position, Real radius, LightList& destList) ;
    Entity* createEntity(const String& entityName, PrefabType ptype) ;
    Entity* createEntity( const String& entityName, const String& meshName ) ;
    Entity* getEntity(const String& name) const;
    bool hasEntity(const String& name) const;
    void destroyEntity(Entity *e) ;
    void destroyEntity(const String& name) ;
    void destroyAllEntities(void) ;
    void destroyAllBillboardSets(void) ;
    ManualObject* createManualObject(const String& name) ;
    ManualObject* getManualObject(const String& name) const;
    bool hasManualObject(const String& name) const;
    void destroyManualObject(ManualObject* obj) ;
    void destroyManualObject(const String& name) ;
    void destroyAllManualObjects(void) ;
    BillboardChain* createBillboardChain(const String& name) ;
    BillboardChain* getBillboardChain(const String& name) const;
    bool hasBillboardChain(const String& name) const;
    void destroyBillboardChain(BillboardChain* obj) ;
    void destroyBillboardChain(const String& name) ;
    void destroyAllBillboardChains(void) ;
    RibbonTrail* createRibbonTrail(const String& name) ;
    RibbonTrail* getRibbonTrail(const String& name) const;
    bool hasRibbonTrail(const String& name) const;
    void destroyRibbonTrail(RibbonTrail* obj) ;
    void destroyRibbonTrail(const String& name) ;
    void destroyAllRibbonTrails(void) ;
    ParticleSystem* createParticleSystem(const String& name, const String& templateName) ;
    ParticleSystem* createParticleSystem(const String& name, size_t quota = 500, const String& resourceGroup = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME) ;
    ParticleSystem* getParticleSystem(const String& name) const;
    bool hasParticleSystem(const String& name) const;
    void destroyParticleSystem(ParticleSystem* obj) ;
    void destroyParticleSystem(const String& name) ;
    void destroyAllParticleSystems(void) ;
    void clearScene(void) ;
    SceneNode* createSceneNode(void) ;
    SceneNode* createSceneNode(const String& name) ;
    void destroySceneNode(const String& name) ;
    SceneNode* getRootSceneNode(void) const;
    SceneNode* getSceneNode(const String& name) const;
    bool hasSceneNode(const String& name) const;
    const Pass* _setPass(const Pass* pass, bool evenIfSuppressed = false, bool shadowDerivation = true) ;
    void prepareRenderQueue(void) ;
    void _renderScene(Camera* camera, Viewport* vp, bool includeOverlays) ;
    void _setDestinationRenderSystem(RenderSystem* sys) ;
    void setWorldGeometry(const String& filename) ;
    void setWorldGeometry(DataStreamPtr& stream, const String& typeName = StringUtil::BLANK) ;
    void setSkyPlane( bool enable, const Plane& plane, const String& materialName, Real scale = 1000, Real tiling = 10, bool drawFirst = true, Real bow = 0, int xsegments = 1, int ysegments = 1, const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME) ;
    void setSkyBox( bool enable, const String& materialName, Real distance = 5000, bool drawFirst = true, const Quaternion& orientation = Quaternion::IDENTITY, const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME) ;
    void setSkyDome( bool enable, const String& materialName, Real curvature = 10, Real tiling = 8, Real distance = 4000, bool drawFirst = true, const Quaternion& orientation = Quaternion::IDENTITY, int xsegments = 16, int ysegments = 16, int ysegments_keep = -1, const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME) ;
    MeshPtr createSkyboxPlane( BoxPlane bp, Real distance, const Quaternion& orientation, const String& groupName) ;
    MeshPtr createSkydomePlane( BoxPlane bp, Real curvature, Real tiling, Real distance, const Quaternion& orientation, int xsegments, int ysegments, int ysegments_keep, const String& groupName) ;
    void _updateSceneGraph(Camera* cam) ;
    void _findVisibleObjects( Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters) ;
    void _renderVisibleObjects(void) ;
    void renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* seq) ;
    void renderVisibleObjectsDefaultSequence(void) ;
    void renderAdditiveStencilShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderModulativeStencilShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderTextureShadowCasterQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderModulativeTextureShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderAdditiveTextureShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderTextureShadowReceiverQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    bool validatePassForRendering(const Pass* pass) ;
    bool validateRenderableForRendering(const Pass* pass, const Renderable* rend) ;
    void renderObjects(const QueuedRenderableCollection& objs, QueuedRenderableCollection::OrganisationMode om, bool doLightIteration, const LightList* manualLightList = 0) ;
    void _renderQueueGroupObjects(RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om) ;
    void renderTransparentShadowCasterObjects(const QueuedRenderableCollection& objs, QueuedRenderableCollection::OrganisationMode om, bool doLightIteration, const LightList* manualLightList = 0) ;
    void renderSingleObject(const Renderable* rend, const Pass* pass, bool doLightIteration, const LightList* manualLightList = 0) ;
    void setAmbientLight(const ColourValue& colour) ;
    const ColourValue& getAmbientLight(void) const;
    ViewPoint getSuggestedViewpoint(bool random = false) ;
    void setFog( FogMode mode = FOG_NONE, const ColourValue& colour = ColourValue::White, Real expDensity = 0.001, Real linearStart = 0.0, Real linearEnd = 1.0) ;
    FogMode getFogMode(void) const;
    const ColourValue& getFogColour(void) const;
    Real getFogStart(void) const;
    Real getFogEnd(void) const;
    Real getFogDensity(void) const;
    BillboardSet* createBillboardSet(const String& name, unsigned int poolSize = 20) ;
    BillboardSet* getBillboardSet(const String& name) const;
    bool hasBillboardSet(const String& name) const;
    void destroyBillboardSet(BillboardSet* set) ;
    void destroyBillboardSet(const String& name) ;
    void setDisplaySceneNodes(bool display) ;
    Animation* createAnimation(const String& name, Real length) ;
    Animation* getAnimation(const String& name) const;
    bool hasAnimation(const String& name) const;
    void destroyAnimation(const String& name) ;
    void destroyAllAnimations(void) ;
    AnimationState* createAnimationState(const String& animName) ;
    AnimationState* getAnimationState(const String& animName) const;
    bool hasAnimationState(const String& name) const;
    void destroyAnimationState(const String& name) ;
    void destroyAllAnimationStates(void) ;
    void _applySceneAnimations(void) ;
    void manualRender(RenderOperation* rend, Pass* pass, Viewport* vp, const Matrix4& worldMatrix, const Matrix4& viewMatrix, const Matrix4& projMatrix, bool doBeginEndFrame = false) ;
    void useRenderableViewProjMode(const Renderable* pRend) ;
    void resetViewProjMode(void) ;
    void _queueSkiesForRendering(Camera* cam) ;
    void addRenderQueueListener(RenderQueueListener* newListener) ;
    void removeRenderQueueListener(RenderQueueListener* delListener) ;
    void addShadowListener(ShadowListener* newListener) ;
    void removeShadowListener(ShadowListener* delListener) ;
    bool fireRenderQueueStarted(uint8 id, const String& invocation) ;
    bool fireRenderQueueEnded(uint8 id, const String& invocation) ;
    void fireShadowTexturesUpdated(size_t numberOfShadowTextures) ;
    void fireShadowTexturesPreCaster(Light* light, Camera* camera) ;
    void fireShadowTexturesPreReceiver(Light* light, Frustum* f) ;
    void setViewport(Viewport* vp) ;
    void showBoundingBoxes(bool bShow) ;
    bool getShowBoundingBoxes() const;
    void _notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack) ;
    void setShadowTechnique(ShadowTechnique technique) ;
    void _suppressShadows(bool suppress) ;
    void _suppressRenderStateChanges(bool suppress) ;
    void updateRenderQueueSplitOptions(void) ;
    void updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, bool suppressShadows, bool suppressRenderState) ;
    void _notifyLightsDirty(void) ;
    void findLightsAffectingFrustum(const Camera* camera) ;
    const SceneManager::ShadowCasterList& findShadowCastersForLight( const Light* light, const Camera* camera) ;
    void initShadowVolumeMaterials(void) ;
    const Pass* deriveShadowCasterPass(const Pass* pass) ;
    const Pass* deriveShadowReceiverPass(const Pass* pass) ;
    void renderShadowVolumesToStencil(const Light* light, const Camera* camera) ;
    void renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables, Pass* pass, const LightList *manualLightList, unsigned long flags, bool secondpass, bool zfail, bool twosided) ;
    void setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided) ;
    void setShadowColour(const ColourValue& colour) ;
    const ColourValue& getShadowColour(void) const;
    void setShadowFarDistance(Real distance) ;
    void setShadowDirectionalLightExtrusionDistance(Real dist) ;
    Real getShadowDirectionalLightExtrusionDistance(void) const;
    void setShadowIndexBufferSize(size_t size) ;
    void setShadowTextureConfig(size_t shadowIndex, unsigned short width, unsigned short height, PixelFormat format) ;
    void setShadowTextureConfig(size_t shadowIndex, const ShadowTextureConfig& config) ;
    ConstShadowTextureConfigIterator getShadowTextureConfigIterator() const;
    void setShadowTextureSize(unsigned short size) ;
    void setShadowTextureCount(size_t count) ;
    void setShadowTexturePixelFormat(PixelFormat fmt) ;
    void setShadowTextureSettings(unsigned short size, unsigned short count, PixelFormat fmt = PF_X8R8G8B8) ;
    const TexturePtr& getShadowTexture(size_t shadowIndex) ;
    void setShadowTextureSelfShadow(bool selfShadow) ;
    void setShadowTextureCasterMaterial(const String& name) ;
    void setShadowTextureReceiverMaterial(const String& name) ;
    void setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup) ;
    const ShadowCameraSetupPtr& getShadowCameraSetup() const;
    void ensureShadowTexturesCreated() ;
    void destroyShadowTextures(void) ;
    void prepareShadowTextures(Camera* cam, Viewport* vp) ;
    StaticGeometry* createStaticGeometry(const String& name) ;
    StaticGeometry* getStaticGeometry(const String& name) const;
    bool hasStaticGeometry(const String& name) const;
    void destroyStaticGeometry(StaticGeometry* geom) ;
    void destroyStaticGeometry(const String& name) ;
    void destroyAllStaticGeometry(void) ;
    InstancedGeometry* createInstancedGeometry(const String& name) ;
    InstancedGeometry* getInstancedGeometry(const String& name) const;
    void destroyInstancedGeometry(InstancedGeometry* geom) ;
    void destroyInstancedGeometry(const String& name) ;
    void destroyAllInstancedGeometry(void) ;
    void destroyQuery(SceneQuery* query) ;
    MovableObject* createMovableObject(const String& name, const String& typeName, const NameValuePairList* params = 0) ;
    void destroyMovableObject(const String& name, const String& typeName) ;
    void destroyAllMovableObjectsByType(const String& typeName) ;
    void destroyAllMovableObjects(void) ;
    MovableObject* getMovableObject(const String& name, const String& typeName) const;
    bool hasMovableObject(const String& name, const String& typeName) const;
    void destroyMovableObject(MovableObject* m) ;
    void injectMovableObject(MovableObject* m) ;
    void extractMovableObject(const String& name, const String& typeName) ;
    void extractMovableObject(MovableObject* m) ;
    void extractAllMovableObjectsByType(const String& typeName) ;
    void _injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation = true) ;
    uint32 _getCombinedVisibilityMask(void) const;
    void setQueuedRenderableVisitor(SceneManager::SceneMgrQueuedRenderableVisitor* visitor) ;
    SceneManager::SceneMgrQueuedRenderableVisitor* getQueuedRenderableVisitor(void) const;
};
#line 171 ".\\RbxSceneManager.cpp"
RenderQueue* RbxSceneManager::getRenderQueue(void)  {
    if (!mRenderQueue)
    {
        initRenderQueue();
    }
    return mRenderQueue;
}
#line 180 ".\\RbxSceneManager.cpp"
void RbxSceneManager::initRenderQueue(void)  {
    mRenderQueue = new RenderQueue();
    // init render queues that do not need shadows
    mRenderQueue->getQueueGroup(RENDER_QUEUE_BACKGROUND)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_OVERLAY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_EARLY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_LATE)->setShadowsEnabled(false);
}
#line 190 ".\\RbxSceneManager.cpp"
void RbxSceneManager::addSpecialCaseRenderQueue(uint8 qid)  {
	mSpecialCaseQueueList.insert(qid);
}
#line 195 ".\\RbxSceneManager.cpp"
void RbxSceneManager::removeSpecialCaseRenderQueue(uint8 qid)  {
	mSpecialCaseQueueList.erase(qid);
}
#line 200 ".\\RbxSceneManager.cpp"
void RbxSceneManager::clearSpecialCaseRenderQueues(void)  {
	mSpecialCaseQueueList.clear();
}
#line 205 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setSpecialCaseRenderQueueMode(SceneManager::SpecialCaseRenderQueueMode mode)  {
	mSpecialCaseQueueMode = mode;
}
#line 210 ".\\RbxSceneManager.cpp"
SceneManager::SpecialCaseRenderQueueMode RbxSceneManager::getSpecialCaseRenderQueueMode(void)  {
	return mSpecialCaseQueueMode;
}
#line 215 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::isRenderQueueToBeProcessed(uint8 qid)  {
	bool inList = mSpecialCaseQueueList.find(qid) != mSpecialCaseQueueList.end();
	return (inList && mSpecialCaseQueueMode == SCRQM_INCLUDE)
		|| (!inList && mSpecialCaseQueueMode == SCRQM_EXCLUDE);
}
#line 222 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setWorldGeometryRenderQueue(uint8 qid)  {
	mWorldGeometryRenderQueue = qid;
}
#line 227 ".\\RbxSceneManager.cpp"
uint8 RbxSceneManager::getWorldGeometryRenderQueue(void)  {
	return mWorldGeometryRenderQueue;
}
#line 225 ".\\RbxSceneManager.cpp"
Camera* RbxSceneManager::createCamera(const String& name)  {
    // Check name not used
    if (mCameras.find(name) != mCameras.end())
    {
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
#line 246 ".\\RbxSceneManager.cpp"
Camera* RbxSceneManager::getCamera(const String& name) const {
    CameraList::const_iterator i = mCameras.find(name);
    if (i == mCameras.end())
    {
        OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find Camera with name " + name,
            "RbxSceneManager::getCamera");
    }
    else
    {
        return i->second;
    }
}
#line 268 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasCamera(const String& name) const {
	return (mCameras.find(name) != mCameras.end());
}
#line 274 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyCamera(Camera *cam)  {
	destroyCamera(cam->getName());

}
#line 281 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyCamera(const String& name)  {
    // Find in list
    CameraList::iterator i = mCameras.find(name);
    if (i != mCameras.end())
    {
		// Remove visible boundary AAB entry
		CamVisibleObjectsMap::iterator camVisObjIt = mCamVisibleObjectsMap.find( i->second );
		if ( camVisObjIt != mCamVisibleObjectsMap.end() )
			mCamVisibleObjectsMap.erase( camVisObjIt );

		// Remove light-shadow cam mapping entry
		ShadowCamLightMapping::iterator camLightIt = mShadowCamLightMapping.find( i->second );
		if ( camLightIt != mShadowCamLightMapping.end() )
			mShadowCamLightMapping.erase( camLightIt );

		// Notify render system
        mDestRenderSystem->_notifyCameraRemoved(i->second);
        delete i->second;
        mCameras.erase(i);
    }

}
#line 306 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllCameras(void)  {

    CameraList::iterator i = mCameras.begin();
    for (; i != mCameras.end(); ++i)
    {
        // Notify render system
        mDestRenderSystem->_notifyCameraRemoved(i->second);
        delete i->second;
    }
    mCameras.clear();
	mCamVisibleObjectsMap.clear();
	mShadowCamLightMapping.clear();
}
#line 321 ".\\RbxSceneManager.cpp"
Light* RbxSceneManager::createLight(const String& name)  {
	return static_cast<Light*>(
		createMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}
#line 327 ".\\RbxSceneManager.cpp"
Light* RbxSceneManager::getLight(const String& name) const {
	return static_cast<Light*>(
		getMovableObject(name, LightFactory::FACTORY_TYPE_NAME));
}
#line 333 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasLight(const String& name) const {
	return hasMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}
#line 338 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyLight(Light *l)  {
	destroyMovableObject(l);
}
#line 343 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyLight(const String& name)  {
	destroyMovableObject(name, LightFactory::FACTORY_TYPE_NAME);
}
#line 348 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllLights(void)  {
	destroyAllMovableObjectsByType(LightFactory::FACTORY_TYPE_NAME);
}
#line 353 ".\\RbxSceneManager.cpp"
const LightList& RbxSceneManager::_getLightsAffectingFrustum(void) const {
    return mLightsAffectingFrustum;
}
#line 363 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_populateLightList(const Vector3& position, Real radius, LightList& destList)  {
    // Really basic trawl of the lights, then sort
    // Subclasses could do something smarter

    // Pick up the lights that affecting frustum only, which should has been
    // cached, so better than take all lights in the scene into account.
    const LightList& candidateLights = _getLightsAffectingFrustum();

    // Pre-allocate memory
    destList.clear();
    destList.reserve(candidateLights.size());

    LightList::const_iterator it;
    for (it = candidateLights.begin(); it != candidateLights.end(); ++it)
    {
        Light* lt = *it;
        if (lt->getType() == Light::LT_DIRECTIONAL)
        {
            // No distance
            lt->tempSquareDist = 0.0f;
            destList.push_back(lt);
        }
        else
        {
            // Calc squared distance
            lt->tempSquareDist = (lt->getDerivedPosition() - position).squaredLength();
            // only add in-range lights
            Real range = lt->getAttenuationRange();
            Real maxDist = range + radius;
            if (lt->tempSquareDist <= Math::Sqr(maxDist))
            {
                destList.push_back(lt);
            }
        }
    }

    // Sort (stable to guarantee ordering on directional lights)
	if (isShadowTechniqueTextureBased())
	{
		// Note that if we're using texture shadows, we actually want to use
		// the first few lights unchanged from the frustum list, matching the
		// texture shadows that were generated
		// Thus we only allow object-relative sorting on the remainder of the list
		if (destList.size() > getShadowTextureCount())
		{
			LightList::iterator start = destList.begin();
			std::advance(start, getShadowTextureCount());
			std::stable_sort(start, destList.end(), lightLess());
		}
	}
	else
	{
		std::stable_sort(destList.begin(), destList.end(), lightLess());
	}


}
#line 422 ".\\RbxSceneManager.cpp"
Entity* RbxSceneManager::createEntity(const String& entityName, PrefabType ptype)  {
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

    OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
        "Unknown prefab type for entity " + entityName,
        "RbxSceneManager::createEntity");
}
#line 442 ".\\RbxSceneManager.cpp"
Entity* RbxSceneManager::createEntity( const String& entityName, const String& meshName )  {
	// delegate to factory implementation
	NameValuePairList params;
	params["mesh"] = meshName;
	return static_cast<Entity*>(
		createMovableObject(entityName, EntityFactory::FACTORY_TYPE_NAME, 
			&params));

}
#line 457 ".\\RbxSceneManager.cpp"
Entity* RbxSceneManager::getEntity(const String& name) const {
	return static_cast<Entity*>(
		getMovableObject(name, EntityFactory::FACTORY_TYPE_NAME));
}
#line 463 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasEntity(const String& name) const {
	return hasMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);
}
#line 469 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyEntity(Entity *e)  {
	destroyMovableObject(e);
}
#line 475 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyEntity(const String& name)  {
	destroyMovableObject(name, EntityFactory::FACTORY_TYPE_NAME);

}
#line 482 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllEntities(void)  {

	destroyAllMovableObjectsByType(EntityFactory::FACTORY_TYPE_NAME);
}
#line 489 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllBillboardSets(void)  {
	destroyAllMovableObjectsByType(BillboardSetFactory::FACTORY_TYPE_NAME);
}
#line 494 ".\\RbxSceneManager.cpp"
ManualObject* RbxSceneManager::createManualObject(const String& name)  {
	return static_cast<ManualObject*>(
		createMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));
}
#line 500 ".\\RbxSceneManager.cpp"
ManualObject* RbxSceneManager::getManualObject(const String& name) const {
	return static_cast<ManualObject*>(
		getMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME));

}
#line 507 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasManualObject(const String& name) const {
	return hasMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);

}
#line 513 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyManualObject(ManualObject* obj)  {
	destroyMovableObject(obj);
}
#line 518 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyManualObject(const String& name)  {
	destroyMovableObject(name, ManualObjectFactory::FACTORY_TYPE_NAME);
}
#line 523 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllManualObjects(void)  {
	destroyAllMovableObjectsByType(ManualObjectFactory::FACTORY_TYPE_NAME);
}
#line 528 ".\\RbxSceneManager.cpp"
BillboardChain* RbxSceneManager::createBillboardChain(const String& name)  {
	return static_cast<BillboardChain*>(
		createMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));
}
#line 534 ".\\RbxSceneManager.cpp"
BillboardChain* RbxSceneManager::getBillboardChain(const String& name) const {
	return static_cast<BillboardChain*>(
		getMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME));

}
#line 541 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasBillboardChain(const String& name) const {
	return hasMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}
#line 547 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyBillboardChain(BillboardChain* obj)  {
	destroyMovableObject(obj);
}
#line 552 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyBillboardChain(const String& name)  {
	destroyMovableObject(name, BillboardChainFactory::FACTORY_TYPE_NAME);
}
#line 557 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllBillboardChains(void)  {
	destroyAllMovableObjectsByType(BillboardChainFactory::FACTORY_TYPE_NAME);
}
#line 562 ".\\RbxSceneManager.cpp"
RibbonTrail* RbxSceneManager::createRibbonTrail(const String& name)  {
	return static_cast<RibbonTrail*>(
		createMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));
}
#line 568 ".\\RbxSceneManager.cpp"
RibbonTrail* RbxSceneManager::getRibbonTrail(const String& name) const {
	return static_cast<RibbonTrail*>(
		getMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME));

}
#line 575 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasRibbonTrail(const String& name) const {
	return hasMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}
#line 581 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyRibbonTrail(RibbonTrail* obj)  {
	destroyMovableObject(obj);
}
#line 586 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyRibbonTrail(const String& name)  {
	destroyMovableObject(name, RibbonTrailFactory::FACTORY_TYPE_NAME);
}
#line 591 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllRibbonTrails(void)  {
	destroyAllMovableObjectsByType(RibbonTrailFactory::FACTORY_TYPE_NAME);
}
#line 596 ".\\RbxSceneManager.cpp"
ParticleSystem* RbxSceneManager::createParticleSystem(const String& name, const String& templateName)  {
	NameValuePairList params;
	params["templateName"] = templateName;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}
#line 607 ".\\RbxSceneManager.cpp"
ParticleSystem* RbxSceneManager::createParticleSystem(const String& name, size_t quota, const String& group)  {
	NameValuePairList params;
	params["quota"] = StringConverter::toString(quota);
	params["resourceGroup"] = group;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}
#line 619 ".\\RbxSceneManager.cpp"
ParticleSystem* RbxSceneManager::getParticleSystem(const String& name) const {
	return static_cast<ParticleSystem*>(
		getMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME));

}
#line 626 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasParticleSystem(const String& name) const {
	return hasMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}
#line 632 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyParticleSystem(ParticleSystem* obj)  {
	destroyMovableObject(obj);
}
#line 637 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyParticleSystem(const String& name)  {
	destroyMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME);
}
#line 642 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllParticleSystems(void)  {
	destroyAllMovableObjectsByType(ParticleSystemFactory::FACTORY_TYPE_NAME);
}
#line 647 ".\\RbxSceneManager.cpp"
void RbxSceneManager::clearScene(void)  {
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
#line 679 ".\\RbxSceneManager.cpp"
SceneNode* RbxSceneManager::createSceneNode(void)  {
    SceneNode* sn = new SceneNode(this);
    assert(mSceneNodes.find(sn->getName()) == mSceneNodes.end());
    mSceneNodes[sn->getName()] = sn;
    return sn;
}
#line 687 ".\\RbxSceneManager.cpp"
SceneNode* RbxSceneManager::createSceneNode(const String& name)  {
    // Check name not used
    if (mSceneNodes.find(name) != mSceneNodes.end())
    {
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "A scene node with the name " + name + " already exists",
            "RbxSceneManager::createSceneNode" );
    }

    SceneNode* sn = new SceneNode(this, name);
    mSceneNodes[sn->getName()] = sn;
    return sn;
}
#line 703 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroySceneNode(const String& name)  {
    SceneNodeList::iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
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
#line 746 ".\\RbxSceneManager.cpp"
SceneNode* RbxSceneManager::getRootSceneNode(void) const {
    return mSceneRoot;
}
#line 750 ".\\RbxSceneManager.cpp"
SceneNode* RbxSceneManager::getSceneNode(const String& name) const {
    SceneNodeList::const_iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "SceneNode '" + name + "' not found.",
            "RbxSceneManager::getSceneNode");
    }

    return i->second;

}
#line 765 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasSceneNode(const String& name) const {
	return (mSceneNodes.find(name) != mSceneNodes.end());
}
#line 771 ".\\RbxSceneManager.cpp"
const Pass* RbxSceneManager::_setPass(const Pass* pass, bool evenIfSuppressed, bool shadowDerivation)  {
	if (!mSuppressRenderStateChanges || evenIfSuppressed)
	{
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
#line 1007 ".\\RbxSceneManager.cpp"
void RbxSceneManager::prepareRenderQueue(void)  {
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
#line 1058 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_renderScene(Camera* camera, Viewport* vp, bool includeOverlays)  {
    Root::getSingleton()._setCurrentSceneManager(this);
	mActiveQueuedRenderableVisitor->targetSceneMgr = this;
	mAutoParamDataSource.setCurrentSceneManager(this);

	// Also set the internal viewport pointer at this point, for calls that need it
	// However don't call setViewport just yet (see below)
	mCurrentViewport = vp;

    if (isShadowTechniqueInUse())
    {
        // Prepare shadow materials
        initShadowVolumeMaterials();
    }

    // Perform a quick pre-check to see whether we should override far distance
    // When using stencil volumes we have to use infinite far distance
    // to prevent dark caps getting clipped
    if (isShadowTechniqueStencilBased() && 
        camera->getProjectionType() == PT_PERSPECTIVE &&
        camera->getFarClipDistance() != 0 && 
        mDestRenderSystem->getCapabilities()->hasCapability(RSC_INFINITE_FAR_PLANE) && 
        mShadowUseInfiniteFarPlane)
    {
        // infinite far distance
        camera->setFarClipDistance(0);
    }

    mCameraInProgress = camera;


    // Update controllers 
    ControllerManager::getSingleton().updateAllControllers();

    // Update the scene, only do this once per frame
    unsigned long thisFrameNumber = Root::getSingleton().getCurrentFrameNumber();
    if (thisFrameNumber != mLastFrameNumber)
    {
        // Update animations
        _applySceneAnimations();
        mLastFrameNumber = thisFrameNumber;
    }

	{
		// Lock scene graph mutex, no more changes until we're ready to render
		OGRE_LOCK_MUTEX(sceneGraphMutex)

		// Update scene graph for this camera (can happen multiple times per frame)
		_updateSceneGraph(camera);

		// Auto-track nodes
		AutoTrackingSceneNodes::iterator atsni, atsniend;
		atsniend = mAutoTrackingSceneNodes.end();
		for (atsni = mAutoTrackingSceneNodes.begin(); atsni != atsniend; ++atsni)
		{
			(*atsni)->_autoTrack();
		}
		// Auto-track camera if required
		camera->_autoTrack();


		if (mIlluminationStage != IRS_RENDER_TO_TEXTURE && mFindVisibleObjects)
		{
			// Locate any lights which could be affecting the frustum
			findLightsAffectingFrustum(camera);

			// Are we using any shadows at all?
			if (isShadowTechniqueInUse() && vp->getShadowsEnabled())
			{
				// Prepare shadow textures if texture shadow based shadowing
				// technique in use
				if (isShadowTechniqueTextureBased())
				{
					// *******
					// WARNING
					// *******
					// This call will result in re-entrant calls to this method
					// therefore anything which comes before this is NOT 
					// guaranteed persistent. Make sure that anything which 
					// MUST be specific to this camera / target is done 
					// AFTER THIS POINT
					prepareShadowTextures(camera, vp);
					// reset the cameras because of the re-entrant call
					mCameraInProgress = camera;
				}
			}
		}

		// Invert vertex winding?
		if (camera->isReflected())
		{
			mDestRenderSystem->setInvertVertexWinding(true);
		}
		else
		{
			mDestRenderSystem->setInvertVertexWinding(false);
		}

		// Tell params about viewport
		mAutoParamDataSource.setCurrentViewport(vp);
		// Set the viewport - this is deliberately after the shadow texture update
		setViewport(vp);

		// Tell params about camera
		mAutoParamDataSource.setCurrentCamera(camera);
		// Set autoparams for finite dir light extrusion
		mAutoParamDataSource.setShadowDirLightExtrusionDistance(mShadowDirLightExtrudeDist);

		// Tell params about current ambient light
		mAutoParamDataSource.setAmbientLightColour(mAmbientLight);
		// Tell rendersystem
		mDestRenderSystem->setAmbientLight(mAmbientLight.r, mAmbientLight.g, mAmbientLight.b);

		// Tell params about render target
		mAutoParamDataSource.setCurrentRenderTarget(vp->getTarget());


		// Set camera window clipping planes (if any)
		if (mDestRenderSystem->getCapabilities()->hasCapability(RSC_USER_CLIP_PLANES))
		{
			if (camera->isWindowSet())  
			{
				const std::vector<Plane>& planeList = 
					camera->getWindowPlanes();
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

		// Prepare render queue for receiving new objects
		prepareRenderQueue();

		if (mFindVisibleObjects)
		{
			// Assemble an AAB on the fly which contains the scene elements visible
			// by the camera.
			CamVisibleObjectsMap::iterator camVisObjIt = mCamVisibleObjectsMap.find( camera );

			assert (camVisObjIt != mCamVisibleObjectsMap.end() &&
				"Should never fail to find a visible object bound for a camera, "
				"did you override SceneManager::createCamera or something?");

			// reset the bounds
			camVisObjIt->second.reset();

			// Parse the scene and tag visibles
			_findVisibleObjects(camera, &(camVisObjIt->second),
				mIlluminationStage == IRS_RENDER_TO_TEXTURE? true : false);

			mAutoParamDataSource.setMainCamBoundsInfo(&(camVisObjIt->second));
		}
		// Add overlays, if viewport deems it
		if (vp->getOverlaysEnabled() && mIlluminationStage != IRS_RENDER_TO_TEXTURE)
		{
			OverlayManager::getSingleton()._queueOverlaysForRendering(camera, getRenderQueue(), vp);
		}
		// Queue skies, if viewport seems it
		if (vp->getSkiesEnabled() && mFindVisibleObjects && mIlluminationStage != IRS_RENDER_TO_TEXTURE)
		{
			_queueSkiesForRendering(camera);
		}
	} // end lock on scene graph mutex

    mDestRenderSystem->_beginGeometryCount();
	// Clear the viewport if required
	if (mCurrentViewport->getClearEveryFrame())
	{
		mDestRenderSystem->clearFrameBuffer(
			mCurrentViewport->getClearBuffers(), 
			mCurrentViewport->getBackgroundColour());
	}        
    // Begin the frame
    mDestRenderSystem->_beginFrame();

    // Set rasterisation mode
    mDestRenderSystem->_setPolygonMode(camera->getPolygonMode());

	// Set initial camera state
	mDestRenderSystem->_setProjectionMatrix(mCameraInProgress->getProjectionMatrixRS());
	mDestRenderSystem->_setViewMatrix(mCameraInProgress->getViewMatrix(true));

    // Render scene content
    _renderVisibleObjects();

    // End frame
    mDestRenderSystem->_endFrame();

    // Notify camera of vis faces
    camera->_notifyRenderedFaces(mDestRenderSystem->_getFaceCount());

    // Notify camera of vis batches
    camera->_notifyRenderedBatches(mDestRenderSystem->_getBatchCount());


}
#line 1267 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_setDestinationRenderSystem(RenderSystem* sys)  {
    mDestRenderSystem = sys;

}
#line 1294 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setWorldGeometry(const String& filename)  {
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}
#line 1302 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setWorldGeometry(DataStreamPtr& stream, const String& typeName)  {
    // This default implementation cannot handle world geometry
    OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS,
        "World geometry is not supported by the generic SceneManager.",
        "RbxSceneManager::setWorldGeometry");
}
#line 1315 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setSkyPlane( bool enable, const Plane& plane, const String& materialName, Real gscale, Real tiling, bool drawFirst, Real bow, int xsegments, int ysegments, const String& groupName)  {
    if (enable)
    {
        String meshName = mName + "SkyPlane";
        mSkyPlane = plane;

        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
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
#line 1404 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setSkyBox( bool enable, const String& materialName, Real distance, bool drawFirst, const Quaternion& orientation, const String& groupName)  {
    if (enable)
    {
        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky box material '" + materialName + "' not found.",
                "RbxSceneManager::setSkyBox");
        }
        // Make sure the material doesn't update the depth buffer
        m->setDepthWriteEnabled(false);
        // Ensure loaded
        m->load();
        // Also clamp texture, don't wrap (otherwise edges can get filtered)
        m->getBestTechnique()->getPass(0)->getTextureUnitState(0)->setTextureAddressingMode(TextureUnitState::TAM_CLAMP);


        mSkyBoxDrawFirst = drawFirst;

        // Create node 
        if (!mSkyBoxNode)
        {
            mSkyBoxNode = createSceneNode("SkyBoxNode");
        }
        else
        {
            mSkyBoxNode->detachAllObjects();
        }

        MaterialManager& matMgr = MaterialManager::getSingleton();
        // Set up the box (6 planes)
        for (int i = 0; i < 6; ++i)
        {
            MeshPtr planeMesh = createSkyboxPlane((BoxPlane)i, distance, orientation, groupName);
            String entName = mName + "SkyBoxPlane" + StringConverter::toString(i);

            // Create entity 
            if (mSkyBoxEntity[i])
            {
                // destroy old one, do it by name for speed
                destroyEntity(entName);
            }
            mSkyBoxEntity[i] = createEntity(entName, planeMesh->getName());
            mSkyBoxEntity[i]->setCastShadows(false);
            // Have to create 6 materials, one for each frame
            // Used to use combined material but now we're using queue we can't split to change frame
            // This doesn't use much memory because textures aren't duplicated
            MaterialPtr boxMat = matMgr.getByName(entName);
            if (boxMat.isNull())
            {
                // Create new by clone
                boxMat = m->clone(entName);
                boxMat->load();
            }
            else
            {
                // Copy over existing
                m->copyDetailsTo(boxMat);
                boxMat->load();
            }
            // Set active frame
			Material::TechniqueIterator ti = boxMat->getSupportedTechniqueIterator();
			while (ti.hasMoreElements())
			{
				Technique* tech = ti.getNext();
				tech->getPass(0)->getTextureUnitState(0)->setCurrentFrame(i);
			}

            mSkyBoxEntity[i]->setMaterialName(boxMat->getName());

            // Attach to node
            mSkyBoxNode->attachObject(mSkyBoxEntity[i]);
        } // for each plane

    }
	mSkyBoxEnabled = enable;
	mSkyBoxGenParameters.skyBoxDistance = distance;
}
#line 1528 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setSkyDome( bool enable, const String& materialName, Real curvature, Real tiling, Real distance, bool drawFirst, const Quaternion& orientation, int xsegments, int ysegments, int ySegmentsToKeep, const String& groupName)  {
    if (enable)
    {
        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
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
#line 1561 ".\\RbxSceneManager.cpp"
MeshPtr RbxSceneManager::createSkyboxPlane( BoxPlane bp, Real distance, const Quaternion& orientation, const String& groupName)  {
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
#line 1632 ".\\RbxSceneManager.cpp"
MeshPtr RbxSceneManager::createSkydomePlane( BoxPlane bp, Real curvature, Real tiling, Real distance, const Quaternion& orientation, int xsegments, int ysegments, int ysegments_keep, const String& groupName)  {

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
#line 1708 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_updateSceneGraph(Camera* cam)  {
	// Process queued needUpdate calls 
	Node::processQueuedUpdates();

    // Cascade down the graph updating transforms & world bounds
    // In this implementation, just update from the root
    // Smarter SceneManager subclasses may choose to update only
    //   certain scene graph branches
    mSceneRoot->_update(true, false);


}
#line 1722 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_findVisibleObjects( Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters)  {
    // Tell nodes to find, cascade down all nodes
    mSceneRoot->_findVisibleObjects(cam, getRenderQueue(), visibleBounds, true, 
        mDisplayNodes, onlyShadowCasters);

}
#line 1731 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_renderVisibleObjects(void)  {
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
#line 1748 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* seq)  {
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
#line 1791 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderVisibleObjectsDefaultSequence(void)  {
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
#line 1843 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderAdditiveStencilShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 1923 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderModulativeStencilShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 2003 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderTextureShadowCasterQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 2054 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderModulativeTextureShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
            if (l->getType() == Light::LT_SPOTLIGHT && !cam->isCustomProjectionMatrixEnabled())
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
#line 2192 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderAdditiveTextureShadowedQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 2308 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderTextureShadowReceiverQueueGroupObjects( RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 2379 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::validatePassForRendering(const Pass* pass)  {
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
#line 2397 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::validateRenderableForRendering(const Pass* pass, const Renderable* rend)  {
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
#line 2423 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderObjects(const QueuedRenderableCollection& objs, QueuedRenderableCollection::OrganisationMode om, bool doLightIteration, const LightList* manualLightList)  {
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
	// Use visitor
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, om);
}
#line 2435 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_renderQueueGroupObjects(RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
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
#line 2495 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, QueuedRenderableCollection::OrganisationMode om)  {
    // Basic render loop
    // Iterate through priorities
    RenderQueueGroup::PriorityMapIterator groupIt = pGroup->getIterator();

    while (groupIt.hasMoreElements())
    {
        RenderPriorityGroup* pPriorityGrp = groupIt.getNext();

        // Sort the queue first
        pPriorityGrp->sort(mCameraInProgress);

        // Do solids
        renderObjects(pPriorityGrp->getSolidsBasic(), om, true);
        // Do transparents (always descending)
        renderObjects(pPriorityGrp->getTransparents(), 
			QueuedRenderableCollection::OM_SORT_DESCENDING, true);


    }// for each priority
}
#line 2519 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderTransparentShadowCasterObjects( const QueuedRenderableCollection& objs, QueuedRenderableCollection::OrganisationMode om, bool doLightIteration, const LightList* manualLightList)  {
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = true;
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	
	// Sort descending (transparency)
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, 
		QueuedRenderableCollection::OM_SORT_DESCENDING);

	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
}
#line 2535 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderSingleObject(const Renderable* rend, const Pass* pass, bool doLightIteration, const LightList* manualLightList)  {
    unsigned short numMatrices;
    static RenderOperation ro;

    // Set up rendering operation
    // I know, I know, const_cast is nasty but otherwise it requires all internal
    // state of the Renderable assigned to the rop to be mutable
    const_cast<Renderable*>(rend)->getRenderOperation(ro);
    ro.srcRenderable = rend;

    // Set world transformation
    rend->getWorldTransforms(mTempXform);
    numMatrices = rend->getNumWorldTransforms();
    if (numMatrices > 1)
    {
        mDestRenderSystem->_setWorldMatrices(mTempXform, numMatrices);
    }
    else
    {
        mDestRenderSystem->_setWorldMatrix(*mTempXform);
    }

    // Issue view / projection changes if any
    useRenderableViewProjMode(rend);

    if (!mSuppressRenderStateChanges)
    {
        bool passSurfaceAndLightParams = true;

        if (pass->isProgrammable())
        {
            // Tell auto params object about the renderable change
            mAutoParamDataSource.setCurrentRenderable(rend);
            // Tell auto params object about the world matrices, eliminated query from renderable again
            mAutoParamDataSource.setWorldMatrices(mTempXform, numMatrices);
            pass->_updateAutoParamsNoLights(mAutoParamDataSource);
            if (pass->hasVertexProgram())
            {
                passSurfaceAndLightParams = pass->getVertexProgram()->getPassSurfaceAndLightStates();
            }
        }

        // Reissue any texture gen settings which are dependent on view matrix
        Pass::ConstTextureUnitStateIterator texIter =  pass->getTextureUnitStateIterator();
        size_t unit = 0;
        while(texIter.hasMoreElements())
        {
            TextureUnitState* pTex = texIter.getNext();
            if (pTex->hasViewRelativeTextureCoordinateGeneration())
            {
                mDestRenderSystem->_setTextureUnitSettings(unit, *pTex);
            }
            ++unit;
        }

        // Sort out normalisation
        mDestRenderSystem->setNormaliseNormals(rend->getNormaliseNormals());

        // Set up the solid / wireframe override
		// Precedence is Camera, Object, Material
		// Camera might not override object if not overrideable
		PolygonMode reqMode = pass->getPolygonMode();
		if (rend->getPolygonModeOverrideable())
		{
            PolygonMode camPolyMode = mCameraInProgress->getPolygonMode();
			// check camera detial only when render detail is overridable
			if (reqMode > camPolyMode)
			{
				// only downgrade detail; if cam says wireframe we don't go up to solid
				reqMode = camPolyMode;
			}
		}
		mDestRenderSystem->_setPolygonMode(reqMode);

		mDestRenderSystem->setClipPlanes(rend->getClipPlanes());

		if (doLightIteration)
		{
            // Create local light list for faster light iteration setup
            static LightList localLightList;


			// Here's where we issue the rendering operation to the render system
			// Note that we may do this once per light, therefore it's in a loop
			// and the light parameters are updated once per traversal through the
			// loop
			const LightList& rendLightList = rend->getLights();

			bool iteratePerLight = pass->getIteratePerLight();

			// deliberately unsigned in case start light exceeds number of lights
			// in which case this pass would be skipped
			int lightsLeft = 1;
			if (iteratePerLight)
			{
				lightsLeft = static_cast<int>(rendLightList.size()) - pass->getStartLight();
				// Don't allow total light count for all iterations to exceed max per pass
				if (lightsLeft > static_cast<int>(pass->getMaxSimultaneousLights()))
				{
					lightsLeft = static_cast<int>(pass->getMaxSimultaneousLights());
				}

			}

			const LightList* pLightListToUse;
			// Start counting from the start light
			size_t lightIndex = pass->getStartLight();

			while (lightsLeft > 0)
			{
				// Determine light list to use
				if (iteratePerLight)
				{
					localLightList.resize(pass->getLightCountPerIteration());

					LightList::iterator destit = localLightList.begin();
					unsigned short numShadowTextureLights = 0;
					for (; destit != localLightList.end() 
							&& lightIndex < rendLightList.size(); 
						++lightIndex, --lightsLeft)
					{
						// Check whether we need to filter this one out
						if (pass->getRunOnlyForOneLightType() && 
							pass->getOnlyLightType() != rendLightList[lightIndex]->getType())
						{
							// Skip
							continue;
						}

						*destit++ = rendLightList[lightIndex];
						// potentially need to update content_type shadow texunit
						// corresponding to this light
						if (isShadowTechniqueTextureBased() && lightIndex < mShadowTextures.size())
						{
							// link the numShadowTextureLights'th shadow texture unit
							unsigned short tuindex = 
								pass->_getTextureUnitWithContentTypeIndex(
								TextureUnitState::CONTENT_SHADOW, numShadowTextureLights);
							if (tuindex < pass->getNumTextureUnitStates())
							{
								// I know, nasty const_cast
								TextureUnitState* tu = 
									const_cast<TextureUnitState*>(
										pass->getTextureUnitState(tuindex));
								const TexturePtr& shadowTex = mShadowTextures[lightIndex];
								tu->_setTexturePtr(shadowTex);
								Camera *cam = shadowTex->getBuffer()->getRenderTarget()->getViewport(0)->getCamera();
								tu->setProjectiveTexturing(!pass->hasVertexProgram(), cam);
								mAutoParamDataSource.setTextureProjector(cam, numShadowTextureLights);
								++numShadowTextureLights;
								// Have to set TU on rendersystem right now, although
								// autoparams will be set later
								mDestRenderSystem->_setTextureUnitSettings(tuindex, *tu);
							}

						}



					}
					// Did we run out of lights before slots? e.g. 5 lights, 2 per iteration
					if (destit != localLightList.end())
					{
						localLightList.erase(destit, localLightList.end());
						lightsLeft = 0;
					}
					pLightListToUse = &localLightList;
				}
				else
				{
					// Use complete light list potentially adjusted by start light
					if (pass->getStartLight() || pass->getMaxSimultaneousLights() != OGRE_MAX_SIMULTANEOUS_LIGHTS)
					{
						// out of lights?
						if (pass->getStartLight() >= rendLightList.size())
						{
							lightsLeft = 0;
							break;
						}
						else
						{
							localLightList.clear();
							LightList::const_iterator copyStart = rendLightList.begin();
							std::advance(copyStart, pass->getStartLight());
							LightList::const_iterator copyEnd = copyStart;
							// Clamp lights to copy to avoid overrunning the end of the list
							size_t lightsToCopy = std::min(
								static_cast<size_t>(pass->getMaxSimultaneousLights()), 
								rendLightList.size() - pass->getStartLight());
							std::advance(copyEnd, lightsToCopy);
							localLightList.insert(localLightList.begin(), 
								copyStart, copyEnd);
							pLightListToUse = &localLightList;
						}
					}
					else
					{
						pLightListToUse = &rendLightList;
					}
					lightsLeft = 0;
				}


				// Do we need to update GPU program parameters?
				if (pass->isProgrammable())
				{
					// Update any automatic gpu params for lights
					// Other bits of information will have to be looked up
					mAutoParamDataSource.setCurrentLightList(pLightListToUse);
					pass->_updateAutoParamsLightsOnly(mAutoParamDataSource);
					// NOTE: We MUST bind parameters AFTER updating the autos

					if (pass->hasVertexProgram())
					{
						mDestRenderSystem->bindGpuProgramParameters(GPT_VERTEX_PROGRAM, 
							pass->getVertexProgramParameters());
					}
					if (pass->hasFragmentProgram())
					{
						mDestRenderSystem->bindGpuProgramParameters(GPT_FRAGMENT_PROGRAM, 
							pass->getFragmentProgramParameters());
					}
				}
				// Do we need to update light states? 
				// Only do this if fixed-function vertex lighting applies
				if (pass->getLightingEnabled() && passSurfaceAndLightParams)
				{
					mDestRenderSystem->_useLights(*pLightListToUse, pass->getMaxSimultaneousLights());
				}
				// issue the render op		
				// nfz: check for gpu_multipass
				mDestRenderSystem->setCurrentPassIterationCount(pass->getPassIterationCount());
				mDestRenderSystem->_render(ro);
			} // possibly iterate per light
		}
		else // no automatic light processing
		{
			// Even if manually driving lights, check light type passes
			bool skipBecauseOfLightType = false;
			if (pass->getRunOnlyForOneLightType())
			{
				if (!manualLightList ||
					(manualLightList->size() == 1 && 
					manualLightList->at(0)->getType() != pass->getOnlyLightType())) 
				{
					skipBecauseOfLightType = true;
				}
			}

			if (!skipBecauseOfLightType)
			{
				// Do we need to update GPU program parameters?
				if (pass->isProgrammable())
				{
					// Do we have a manual light list?
					if (manualLightList)
					{
						// Update any automatic gpu params for lights
						mAutoParamDataSource.setCurrentLightList(manualLightList);
						pass->_updateAutoParamsLightsOnly(mAutoParamDataSource);
					}

					if (pass->hasVertexProgram())
					{
						mDestRenderSystem->bindGpuProgramParameters(GPT_VERTEX_PROGRAM, 
							pass->getVertexProgramParameters());
					}
					if (pass->hasFragmentProgram())
					{
						mDestRenderSystem->bindGpuProgramParameters(GPT_FRAGMENT_PROGRAM, 
							pass->getFragmentProgramParameters());
					}
				}

				// Use manual lights if present, and not using vertex programs that don't use fixed pipeline
				if (manualLightList && 
					pass->getLightingEnabled() && passSurfaceAndLightParams)
				{
					mDestRenderSystem->_useLights(*manualLightList, pass->getMaxSimultaneousLights());
				}
				// issue the render op		
				// nfz: set up multipass rendering
				mDestRenderSystem->setCurrentPassIterationCount(pass->getPassIterationCount());
				mDestRenderSystem->_render(ro);
			} // !skipBecauseOfLightType
		}

	}
	else // mSuppressRenderStateChanges
	{
		// Just render
		mDestRenderSystem->setCurrentPassIterationCount(1);
		mDestRenderSystem->_render(ro);
	}
	
    // Reset view / projection changes if any
    resetViewProjMode();

}
#line 2837 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setAmbientLight(const ColourValue& colour)  {
    mAmbientLight = colour;
}
#line 2842 ".\\RbxSceneManager.cpp"
const ColourValue& RbxSceneManager::getAmbientLight(void) const {
    return mAmbientLight;
}
#line 2847 ".\\RbxSceneManager.cpp"
ViewPoint RbxSceneManager::getSuggestedViewpoint(bool random)  {
    // By default return the origin
    ViewPoint vp;
    vp.position = Vector3::ZERO;
    vp.orientation = Quaternion::IDENTITY;
    return vp;
}
#line 2856 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setFog(FogMode mode, const ColourValue& colour, Real density, Real start, Real end)  {
    mFogMode = mode;
    mFogColour = colour;
    mFogStart = start;
    mFogEnd = end;
    mFogDensity = density;
}
#line 2865 ".\\RbxSceneManager.cpp"
FogMode RbxSceneManager::getFogMode(void) const {
    return mFogMode;
}
#line 2870 ".\\RbxSceneManager.cpp"
const ColourValue& RbxSceneManager::getFogColour(void) const {
    return mFogColour;
}
#line 2875 ".\\RbxSceneManager.cpp"
Real RbxSceneManager::getFogStart(void) const {
    return mFogStart;
}
#line 2880 ".\\RbxSceneManager.cpp"
Real RbxSceneManager::getFogEnd(void) const {
    return mFogEnd;
}
#line 2885 ".\\RbxSceneManager.cpp"
Real RbxSceneManager::getFogDensity(void) const {
    return mFogDensity;
}
#line 2890 ".\\RbxSceneManager.cpp"
BillboardSet* RbxSceneManager::createBillboardSet(const String& name, unsigned int poolSize)  {
	NameValuePairList params;
	params["poolSize"] = StringConverter::toString(poolSize);
	return static_cast<BillboardSet*>(
		createMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME, &params));
}
#line 2898 ".\\RbxSceneManager.cpp"
BillboardSet* RbxSceneManager::getBillboardSet(const String& name) const {
	return static_cast<BillboardSet*>(
		getMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME));
}
#line 2904 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasBillboardSet(const String& name) const {
	return hasMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}
#line 2910 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyBillboardSet(BillboardSet* set)  {
	destroyMovableObject(set);
}
#line 2915 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyBillboardSet(const String& name)  {
	destroyMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME);
}
#line 2920 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setDisplaySceneNodes(bool display)  {
    mDisplayNodes = display;
}
#line 2982 ".\\RbxSceneManager.cpp"
Animation* RbxSceneManager::createAnimation(const String& name, Real length)  {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

    // Check name not used
    if (mAnimationsList.find(name) != mAnimationsList.end())
    {
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "An animation with the name " + name + " already exists",
            "RbxSceneManager::createAnimation" );
    }

    Animation* pAnim = new Animation(name, length);
    mAnimationsList[name] = pAnim;
    return pAnim;
}
#line 3000 ".\\RbxSceneManager.cpp"
Animation* RbxSceneManager::getAnimation(const String& name) const {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	AnimationList::const_iterator i = mAnimationsList.find(name);
    if (i == mAnimationsList.end())
    {
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find animation with name " + name, 
            "RbxSceneManager::getAnimation");
    }
    return i->second;
}
#line 2957 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasAnimation(const String& name) const {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)
	return (mAnimationsList.find(name) != mAnimationsList.end());
}
#line 3020 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAnimation(const String& name)  {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	// Also destroy any animation states referencing this animation
	mAnimationStates.removeAnimationState(name);

	AnimationList::iterator i = mAnimationsList.find(name);
	if (i == mAnimationsList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"Cannot find animation with name " + name, 
			"RbxSceneManager::getAnimation");
	}

	// Free memory
	delete i->second;

	mAnimationsList.erase(i);

}
#line 2985 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllAnimations(void)  {
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
#line 3000 ".\\RbxSceneManager.cpp"
AnimationState* RbxSceneManager::createAnimationState(const String& animName)  {
    // Get animation, this will throw an exception if not found
    Animation* anim = getAnimation(animName);

    // Create new state
	return mAnimationStates.createAnimationState(animName, 0, anim->getLength());

}
#line 3010 ".\\RbxSceneManager.cpp"
AnimationState* RbxSceneManager::getAnimationState(const String& animName) const {
	return mAnimationStates.getAnimationState(animName);

}
#line 3016 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasAnimationState(const String& name) const {
	return mAnimationStates.hasAnimationState(name);
}
#line 3021 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAnimationState(const String& name)  {
	mAnimationStates.removeAnimationState(name);
}
#line 3026 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllAnimationStates(void)  {
    mAnimationStates.removeAllAnimationStates();
}
#line 3031 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_applySceneAnimations(void)  {
	// manual lock over states (extended duration required)
	OGRE_LOCK_MUTEX(mAnimationStates.OGRE_AUTO_MUTEX_NAME)

    ConstEnabledAnimationStateIterator stateIt = mAnimationStates.getEnabledAnimationStateIterator();

    while (stateIt.hasMoreElements())
    {
        const AnimationState* state = stateIt.getNext();
        Animation* anim = getAnimation(state->getAnimationName());

        // Reset any nodes involved
        // NB this excludes blended animations
        Animation::NodeTrackIterator nodeTrackIt = anim->getNodeTrackIterator();
        while(nodeTrackIt.hasMoreElements())
        {
            Node* nd = nodeTrackIt.getNext()->getAssociatedNode();
			if (nd)
				nd->resetToInitialState();
        }

        Animation::NumericTrackIterator numTrackIt = anim->getNumericTrackIterator();
        while(numTrackIt.hasMoreElements())
        {
            const AnimableValuePtr& anim = numTrackIt.getNext()->getAssociatedAnimable();
			if (!anim.isNull())
				anim->resetToBaseValue();
        }

        // Apply the animation
        anim->apply(state->getTimePosition(), state->getWeight());
    }


}
#line 3068 ".\\RbxSceneManager.cpp"
void RbxSceneManager::manualRender(RenderOperation* rend, Pass* pass, Viewport* vp, const Matrix4& worldMatrix, const Matrix4& viewMatrix, const Matrix4& projMatrix, bool doBeginEndFrame)  {
    mDestRenderSystem->_setViewport(vp);
    mDestRenderSystem->_setWorldMatrix(worldMatrix);
    mDestRenderSystem->_setViewMatrix(viewMatrix);
    mDestRenderSystem->_setProjectionMatrix(projMatrix);

    if (doBeginEndFrame)
        mDestRenderSystem->_beginFrame();

    _setPass(pass);
	// Do we need to update GPU program parameters?
	if (pass->isProgrammable())
	{
		mAutoParamDataSource.setCurrentViewport(vp);
		mAutoParamDataSource.setCurrentRenderTarget(vp->getTarget());
		mAutoParamDataSource.setCurrentSceneManager(this);
		mAutoParamDataSource.setWorldMatrices(&worldMatrix, 1);
		Camera dummyCam(StringUtil::BLANK, 0);
		dummyCam.setCustomViewMatrix(true, viewMatrix);
		dummyCam.setCustomProjectionMatrix(true, projMatrix);
		pass->_updateAutoParamsNoLights(mAutoParamDataSource);
		// NOTE: We MUST bind parameters AFTER updating the autos
		if (pass->hasVertexProgram())
		{
			mDestRenderSystem->bindGpuProgramParameters(GPT_VERTEX_PROGRAM, 
				pass->getVertexProgramParameters());
		}
		if (pass->hasFragmentProgram())
		{
			mDestRenderSystem->bindGpuProgramParameters(GPT_FRAGMENT_PROGRAM, 
				pass->getFragmentProgramParameters());
		}
	}
    mDestRenderSystem->_render(*rend);

    if (doBeginEndFrame)
        mDestRenderSystem->_endFrame();

}
#line 3112 ".\\RbxSceneManager.cpp"
void RbxSceneManager::useRenderableViewProjMode(const Renderable* pRend)  {
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
#line 3137 ".\\RbxSceneManager.cpp"
void RbxSceneManager::resetViewProjMode(void)  {
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
#line 3156 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_queueSkiesForRendering(Camera* cam)  {
    // Update nodes
    // Translate the box by the camera position (constant distance)
    if (mSkyPlaneNode)
    {
        // The plane position relative to the camera has already been set up
        mSkyPlaneNode->setPosition(cam->getDerivedPosition());
    }

    if (mSkyBoxNode)
    {
        mSkyBoxNode->setPosition(cam->getDerivedPosition());
    }

    if (mSkyDomeNode)
    {
        mSkyDomeNode->setPosition(cam->getDerivedPosition());
    }

    uint8 qid;
    if (mSkyPlaneEnabled)
    {
        qid = mSkyPlaneDrawFirst? 
RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;
        getRenderQueue()->addRenderable(mSkyPlaneEntity->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
    }

    uint plane;
    if (mSkyBoxEnabled)
    {
        qid = mSkyBoxDrawFirst? 
RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;

        for (plane = 0; plane < 6; ++plane)
        {
            getRenderQueue()->addRenderable(
                mSkyBoxEntity[plane]->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
        }
    }

    if (mSkyDomeEnabled)
    {
        qid = mSkyDomeDrawFirst? 
RENDER_QUEUE_SKIES_EARLY : RENDER_QUEUE_SKIES_LATE;

        for (plane = 0; plane < 5; ++plane)
        {
            getRenderQueue()->addRenderable(
                mSkyDomeEntity[plane]->getSubEntity(0), qid, OGRE_RENDERABLE_DEFAULT_PRIORITY);
        }
    }
}
#line 3210 ".\\RbxSceneManager.cpp"
void RbxSceneManager::addRenderQueueListener(RenderQueueListener* newListener)  {
    mRenderQueueListeners.push_back(newListener);
}
#line 3215 ".\\RbxSceneManager.cpp"
void RbxSceneManager::removeRenderQueueListener(RenderQueueListener* delListener)  {
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
#line 3230 ".\\RbxSceneManager.cpp"
void RbxSceneManager::addShadowListener(ShadowListener* newListener)  {
    mShadowListeners.push_back(newListener);
}
#line 3235 ".\\RbxSceneManager.cpp"
void RbxSceneManager::removeShadowListener(ShadowListener* delListener)  {
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
#line 3250 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::fireRenderQueueStarted(uint8 id, const String& invocation)  {
    RenderQueueListenerList::iterator i, iend;
    bool skip = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueStarted(id, invocation, skip);
    }
    return skip;
}
#line 3263 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::fireRenderQueueEnded(uint8 id, const String& invocation)  {
    RenderQueueListenerList::iterator i, iend;
    bool repeat = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueEnded(id, invocation, repeat);
    }
    return repeat;
}
#line 3276 ".\\RbxSceneManager.cpp"
void RbxSceneManager::fireShadowTexturesUpdated(size_t numberOfShadowTextures)  {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTexturesUpdated(numberOfShadowTextures);
    }
}
#line 3287 ".\\RbxSceneManager.cpp"
void RbxSceneManager::fireShadowTexturesPreCaster(Light* light, Camera* camera)  {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureCasterPreViewProj(light, camera);
    }
}
#line 3298 ".\\RbxSceneManager.cpp"
void RbxSceneManager::fireShadowTexturesPreReceiver(Light* light, Frustum* f)  {
    ShadowListenerList::iterator i, iend;

    iend = mShadowListeners.end();
    for (i = mShadowListeners.begin(); i != iend; ++i)
    {
        (*i)->shadowTextureReceiverPreViewProj(light, f);
    }
}
#line 3309 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setViewport(Viewport* vp)  {
    mCurrentViewport = vp;
    // Set viewport in render system
    mDestRenderSystem->_setViewport(vp);
	// Set the active material scheme for this viewport
	MaterialManager::getSingleton().setActiveScheme(vp->getMaterialScheme());
}
#line 3318 ".\\RbxSceneManager.cpp"
void RbxSceneManager::showBoundingBoxes(bool bShow)  {
    mShowBoundingBoxes = bShow;
}
#line 3323 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::getShowBoundingBoxes() const {
    return mShowBoundingBoxes;
}
#line 3328 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack)  {
    if (autoTrack)
    {
        mAutoTrackingSceneNodes.insert(node);
    }
    else
    {
        mAutoTrackingSceneNodes.erase(node);
    }
}
#line 3340 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTechnique(ShadowTechnique technique)  {
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
#line 3387 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_suppressShadows(bool suppress)  {
	mSuppressShadows = suppress;
}
#line 3392 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_suppressRenderStateChanges(bool suppress)  {
	mSuppressRenderStateChanges = suppress;
}
#line 3397 ".\\RbxSceneManager.cpp"
void RbxSceneManager::updateRenderQueueSplitOptions(void)  {
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
#line 3434 ".\\RbxSceneManager.cpp"
void RbxSceneManager::updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, bool suppressShadows, bool suppressRenderState)  {
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
#line 3472 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_notifyLightsDirty(void)  {
    ++mLightsDirtyCounter;
}
#line 3494 ".\\RbxSceneManager.cpp"
void RbxSceneManager::findLightsAffectingFrustum(const Camera* camera)  {
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
#line 3657 ".\\RbxSceneManager.cpp"
const SceneManager::ShadowCasterList& RbxSceneManager::findShadowCastersForLight( const Light* light, const Camera* camera)  {
    mShadowCasterList.clear();

    if (light->getType() == Light::LT_DIRECTIONAL)
    {
        // Basic AABB query encompassing the frustum and the extrusion of it
        AxisAlignedBox aabb;
        const Vector3* corners = camera->getWorldSpaceCorners();
        Vector3 min, max;
        Vector3 extrude = light->getDerivedDirection() * -mShadowDirLightExtrudeDist;
        // do first corner
        min = max = corners[0];
        min.makeFloor(corners[0] + extrude);
        max.makeCeil(corners[0] + extrude);
        for (size_t c = 1; c < 8; ++c)
        {
            min.makeFloor(corners[c]);
            max.makeCeil(corners[c]);
            min.makeFloor(corners[c] + extrude);
            max.makeCeil(corners[c] + extrude);
        }
        aabb.setExtents(min, max);

        if (!mShadowCasterAABBQuery)
            mShadowCasterAABBQuery = createAABBQuery(aabb);
        else
            mShadowCasterAABBQuery->setBox(aabb);
        // Execute, use callback
        mShadowCasterQueryListener->prepare(false, 
            &(light->_getFrustumClipVolumes(camera)), 
            light, camera, &mShadowCasterList, mShadowFarDistSquared);
        mShadowCasterAABBQuery->execute(mShadowCasterQueryListener);


    }
    else
    {
        Sphere s(light->getDerivedPosition(), light->getAttenuationRange());
        // eliminate early if camera cannot see light sphere
        if (camera->isVisible(s))
        {
            if (!mShadowCasterSphereQuery)
                mShadowCasterSphereQuery = createSphereQuery(s);
            else
                mShadowCasterSphereQuery->setSphere(s);

            // Determine if light is inside or outside the frustum
            bool lightInFrustum = camera->isVisible(light->getDerivedPosition());
            const PlaneBoundedVolumeList* volList = 0;
            if (!lightInFrustum)
            {
                // Only worth building an external volume list if
                // light is outside the frustum
                volList = &(light->_getFrustumClipVolumes(camera));
            }

            // Execute, use callback
            mShadowCasterQueryListener->prepare(lightInFrustum, 
                volList, light, camera, &mShadowCasterList, mShadowFarDistSquared);
            mShadowCasterSphereQuery->execute(mShadowCasterQueryListener);

        }

    }


    return mShadowCasterList;
}
#line 3728 ".\\RbxSceneManager.cpp"
void RbxSceneManager::initShadowVolumeMaterials(void)  {
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
#line 3938 ".\\RbxSceneManager.cpp"
const Pass* RbxSceneManager::deriveShadowCasterPass(const Pass* pass)  {
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
#line 4051 ".\\RbxSceneManager.cpp"
const Pass* RbxSceneManager::deriveShadowReceiverPass(const Pass* pass)  {

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
#line 4221 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderShadowVolumesToStencil(const Light* light, const Camera* camera)  {
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
#line 4454 ".\\RbxSceneManager.cpp"
void RbxSceneManager::renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables, Pass* pass, const LightList *manualLightList, unsigned long flags, bool secondpass, bool zfail, bool twosided)  {
    // ----- SHADOW VOLUME LOOP -----
    // Render all shadow renderables with same stencil operations
    while (iShadowRenderables.hasMoreElements())
    {
        ShadowRenderable* sr = iShadowRenderables.getNext();

        // omit hidden renderables
        if (sr->isVisible())
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
#line 4534 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided)  {
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
#line 4586 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowColour(const ColourValue& colour)  {
    mShadowColour = colour;

    // Change shadow material setting only when it's prepared,
    // otherwise, it'll set up while preparing shadow materials.
    if (mShadowModulativePass)
    {
        mShadowModulativePass->getTextureUnitState(0)->setColourOperationEx(
            LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, colour);
    }
}
#line 4599 ".\\RbxSceneManager.cpp"
const ColourValue& RbxSceneManager::getShadowColour(void) const {
    return mShadowColour;
}
#line 4604 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowFarDistance(Real distance)  {
    mShadowFarDist = distance;
    mShadowFarDistSquared = distance * distance;
}
#line 4610 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowDirectionalLightExtrusionDistance(Real dist)  {
    mShadowDirLightExtrudeDist = dist;
}
#line 4615 ".\\RbxSceneManager.cpp"
Real RbxSceneManager::getShadowDirectionalLightExtrusionDistance(void) const {
    return mShadowDirLightExtrudeDist;
}
#line 4620 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowIndexBufferSize(size_t size)  {
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
#line 4701 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureConfig(size_t shadowIndex, unsigned short width, unsigned short height, PixelFormat format)  {
	ShadowTextureConfig conf;
	conf.width = width;
	conf.height = height;
	conf.format = format;

	setShadowTextureConfig(shadowIndex, conf);


}
#line 4714 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureConfig(size_t shadowIndex, const ShadowTextureConfig& config)  {
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"RbxSceneManager::setShadowTextureConfig");
	}
	mShadowTextureConfigList[shadowIndex] = config;

	mShadowTextureConfigDirty = true;
}
#line 4661 ".\\RbxSceneManager.cpp"
ConstShadowTextureConfigIterator RbxSceneManager::getShadowTextureConfigIterator() const {
	return ConstShadowTextureConfigIterator(
		mShadowTextureConfigList.begin(), mShadowTextureConfigList.end());

}
#line 4668 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureSize(unsigned short size)  {
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
#line 4683 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureCount(size_t count)  {
    // Change size, any new items will take default
	if (count != mShadowTextureConfigList.size())
	{
		mShadowTextureConfigList.resize(count);
		mShadowTextureConfigDirty = true;
	}
}
#line 4693 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTexturePixelFormat(PixelFormat fmt)  {
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
#line 4706 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureSettings(unsigned short size, unsigned short count, PixelFormat fmt)  {
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
#line 4722 ".\\RbxSceneManager.cpp"
const TexturePtr& RbxSceneManager::getShadowTexture(size_t shadowIndex)  {
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"RbxSceneManager::getShadowTexture");
	}
	ensureShadowTexturesCreated();

	return mShadowTextures[shadowIndex];


}
#line 4737 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureSelfShadow(bool selfShadow)  { 
	mShadowTextureSelfShadow = selfShadow;
	if (isShadowTechniqueTextureBased())
		getRenderQueue()->setShadowCastersCannotBeReceivers(!selfShadow);
}
#line 4810 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureCasterMaterial(const String& name)  {
	if (name.empty())
	{
		mShadowTextureCustomCasterPass = 0;
	}
	else
	{
		MaterialPtr mat = MaterialManager::getSingleton().getByName(name);
		if (mat.isNull())
		{
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
#line 4839 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowTextureReceiverMaterial(const String& name)  {
	if (name.empty())
	{
		mShadowTextureCustomReceiverPass = 0;
	}
	else
	{
		MaterialPtr mat = MaterialManager::getSingleton().getByName(name);
		if (mat.isNull())
		{
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
#line 4821 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup)  {
	mDefaultShadowCameraSetup = shadowSetup;

}
#line 4827 ".\\RbxSceneManager.cpp"
const ShadowCameraSetupPtr& RbxSceneManager::getShadowCameraSetup() const {
	return mDefaultShadowCameraSetup;
}
#line 4832 ".\\RbxSceneManager.cpp"
void RbxSceneManager::ensureShadowTexturesCreated()  {
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
#line 4925 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyShadowTextures(void)  {
	
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
#line 4959 ".\\RbxSceneManager.cpp"
void RbxSceneManager::prepareShadowTextures(Camera* cam, Viewport* vp)  {
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
#line 5118 ".\\RbxSceneManager.cpp"
StaticGeometry* RbxSceneManager::createStaticGeometry(const String& name)  {
	// Check not existing
	if (mStaticGeometryList.find(name) != mStaticGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"StaticGeometry with name '" + name + "' already exists!", 
			"RbxSceneManager::createStaticGeometry");
	}
	StaticGeometry* ret = new StaticGeometry(this, name);
	mStaticGeometryList[name] = ret;
	return ret;
}
#line 5132 ".\\RbxSceneManager.cpp"
StaticGeometry* RbxSceneManager::getStaticGeometry(const String& name) const {
	StaticGeometryList::const_iterator i = mStaticGeometryList.find(name);
	if (i == mStaticGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"StaticGeometry with name '" + name + "' not found", 
			"RbxSceneManager::createStaticGeometry");
	}
	return i->second;
}
#line 5078 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasStaticGeometry(const String& name) const {
	return (mStaticGeometryList.find(name) != mStaticGeometryList.end());
}
#line 5084 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyStaticGeometry(StaticGeometry* geom)  {
	destroyStaticGeometry(geom->getName());
}
#line 5089 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyStaticGeometry(const String& name)  {
	StaticGeometryList::iterator i = mStaticGeometryList.find(name);
	if (i != mStaticGeometryList.end())
	{
		delete i->second;
		mStaticGeometryList.erase(i);
	}

}
#line 5100 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllStaticGeometry(void)  {
	StaticGeometryList::iterator i, iend;
	iend = mStaticGeometryList.end();
	for (i = mStaticGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mStaticGeometryList.clear();
}
#line 5177 ".\\RbxSceneManager.cpp"
InstancedGeometry* RbxSceneManager::createInstancedGeometry(const String& name)  {
	// Check not existing
	if (mInstancedGeometryList.find(name) != mInstancedGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"InstancedGeometry with name '" + name + "' already exists!", 
			"RbxSceneManager::createInstancedGeometry");
	}
	InstancedGeometry* ret = new InstancedGeometry(this, name);
	mInstancedGeometryList[name] = ret;
	return ret;
}
#line 5191 ".\\RbxSceneManager.cpp"
InstancedGeometry* RbxSceneManager::getInstancedGeometry(const String& name) const {
	InstancedGeometryList::const_iterator i = mInstancedGeometryList.find(name);
	if (i == mInstancedGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"InstancedGeometry with name '" + name + "' not found", 
			"RbxSceneManager::createInstancedGeometry");
	}
	return i->second;
}
#line 5137 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyInstancedGeometry(InstancedGeometry* geom)  {
	destroyInstancedGeometry(geom->getName());
}
#line 5142 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyInstancedGeometry(const String& name)  {
	InstancedGeometryList::iterator i = mInstancedGeometryList.find(name);
	if (i != mInstancedGeometryList.end())
	{
		delete i->second;
		mInstancedGeometryList.erase(i);
	}

}
#line 5153 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllInstancedGeometry(void)  {
	InstancedGeometryList::iterator i, iend;
	iend = mInstancedGeometryList.end();
	for (i = mInstancedGeometryList.begin(); i != iend; ++i)
	{
		delete i->second;
	}
	mInstancedGeometryList.clear();
}
#line 5211 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyQuery(SceneQuery* query)  {
    delete query;
}
#line 5324 ".\\RbxSceneManager.cpp"
MovableObject* RbxSceneManager::createMovableObject(const String& name, const String& typeName, const NameValuePairList* params)  {
	MovableObjectFactory* factory = 
		Root::getSingleton().getMovableObjectFactory(typeName);
	// Check for duplicate names
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);

	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		if (objectMap->map.find(name) != objectMap->map.end())
		{
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
#line 5283 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyMovableObject(const String& name, const String& typeName)  {
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
#line 5301 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllMovableObjectsByType(const String& typeName)  {
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
#line 5322 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyAllMovableObjects(void)  {
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
#line 5421 ".\\RbxSceneManager.cpp"
MovableObject* RbxSceneManager::getMovableObject(const String& name, const String& typeName) const {
	const MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::const_iterator mi = objectMap->map.find(name);
		if (mi == objectMap->map.end())
		{
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
				"Object named '" + name + "' does not exist.", 
				"RbxSceneManager::getMovableObject");
		}
		return mi->second;
	}
	
}
#line 5373 ".\\RbxSceneManager.cpp"
bool RbxSceneManager::hasMovableObject(const String& name, const String& typeName) const {
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
#line 5397 ".\\RbxSceneManager.cpp"
void RbxSceneManager::destroyMovableObject(MovableObject* m)  {
	destroyMovableObject(m->getName(), m->getMovableType());
}
#line 5402 ".\\RbxSceneManager.cpp"
void RbxSceneManager::injectMovableObject(MovableObject* m)  {
	MovableObjectCollection* objectMap = getMovableObjectCollection(m->getMovableType());
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)

		objectMap->map[m->getName()] = m;
	}
}
#line 5412 ".\\RbxSceneManager.cpp"
void RbxSceneManager::extractMovableObject(const String& name, const String& typeName)  {
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
#line 5427 ".\\RbxSceneManager.cpp"
void RbxSceneManager::extractMovableObject(MovableObject* m)  {
	extractMovableObject(m->getName(), m->getMovableType());
}
#line 5432 ".\\RbxSceneManager.cpp"
void RbxSceneManager::extractAllMovableObjectsByType(const String& typeName)  {
	MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		// no deletion
		objectMap->map.clear();
	}
}
#line 5442 ".\\RbxSceneManager.cpp"
void RbxSceneManager::_injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation )  {
	// render something as if it came from the current queue
    const Pass *usedPass = _setPass(pass, false, shadowDerivation);
    renderSingleObject(rend, usedPass, false);
}
#line 5454 ".\\RbxSceneManager.cpp"
uint32 RbxSceneManager::_getCombinedVisibilityMask(void) const {
	return mCurrentViewport ?
		mCurrentViewport->getVisibilityMask() & mVisibilityMask : mVisibilityMask;

}
#line 5503 ".\\RbxSceneManager.cpp"
void RbxSceneManager::setQueuedRenderableVisitor(SceneManager::SceneMgrQueuedRenderableVisitor* visitor)  {
	if (visitor)
		mActiveQueuedRenderableVisitor = visitor;
	else
		mActiveQueuedRenderableVisitor = &mDefaultQueuedRenderableVisitor;
}
#line 5511 ".\\RbxSceneManager.cpp"
SceneManager::SceneMgrQueuedRenderableVisitor* RbxSceneManager::getQueuedRenderableVisitor(void) const {
	return mActiveQueuedRenderableVisitor;
}
}
