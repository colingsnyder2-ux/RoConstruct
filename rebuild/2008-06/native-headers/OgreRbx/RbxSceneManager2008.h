#pragma once
// Ogre::RbxSceneManager and Ogre::RbxSceneManagerFactory as compiled into the June 2008 client (inactive native
// recovery; Roblox's fork of the Ogre 1.4.5 scene manager, source file ".\RbxSceneManager.cpp", string 0084e9e8).
//
// Non-colliding name: there is no donor RbxSceneManager header. Needs the Ogre 1.4.5 client headers on the include
// path (tools/libs/ogre-1.4.5/ogrenew/OgreMain/include, OGRE_NONCLIENT_BUILD undefined: Ogre::SceneManager and every
// library method are rgmain.dll imports).
//
// Evidence (original Roblox.exe):
//   * RTTI: vtable 0084ed34 .?AVRbxSceneManager@Ogre@@ -> .?AVSceneManager@Ogre@@ at offset 0. 229 slots: the 228
//     Ogre::SceneManager slots, all overridden by exe bodies except slot 48 (the rgmain import thunk 006a02d2 of
//     SceneManager::createEntity(const String&, SceneManager::PrefabType)), plus one new slot 228 (0068b8b0): the
//     prefab createEntity of the fork ("RbxSceneManager::createEntity" 0084ea20, "Prefab_Plane/Cube/Sphere"), which
//     calls slot 49 createEntity(name, meshName). A new slot rather than an override of slot 48 means its enum
//     parameter is a type of the fork's own, declared here as RbxSceneManager::PrefabType.
//   * slot 26 getTypeName 0068cef0 returns the static string 0097dc3c, which initMetaData 0068cf00 copies into the
//     factory's metadata: RbxSceneManagerFactory::FACTORY_TYPE_NAME (dynamic initializer 007f9100, "RbxSceneManager"
//     0084e018; atexit destructor 008015a0).
//   * size 0x8c04: RbxSceneManagerFactory::createInstance 0068fde0 pushes 0x8c04 to operator new and calls the
//     constructor 0068e7c0 with the instance name. sizeof(Ogre::SceneManager) is 0x8bb8 (layout probe).
//   * constructor 0068e7c0: SceneManager(name) import; vptr 0084ed34; std::string() at +0x8bbc; SharedPtr<RbxSky>()
//     at +0x8bd8 (vtable 0084ec3c .?AV?$SharedPtr@VRbxSky@Ogre@@@Ogre@@, +0x8bdc / +0x8be0 = 0); the nested
//     SceneMgrQueuedRenderableVisitor at +0x8bf0 (vtable 0084e9a4, +0x8bfc transparentShadowCastersMode = false);
//     +0x8be8 = new(0x20) ShadowCasterSceneQueryListener(this) (vtable 0084e994; +4 = this, +8 = 0, +0xc = false,
//     +0x10 = +0x14 = 0); +0x8bec = &+0x8bf0.
//   * destructor 0069e220 (??_G 0069eb00): clearScene 00698890 and destroyAllCameras 006987c0 called directly, the
//     MovableObjectCollectionMap at +0x4268 emptied and cleared, the listener deleted through slot 0, then the visitor,
//     SharedPtr<RbxSky>, string and ~SceneManager import.
//   * +0x8bb8 / +0x8bb9 are bools: _renderScene 00698cc0 sets them to 1 / 0, _setPass 00694680 stores
//     pass->getLightingEnabled() into +0x8bb8, renderSingleObject 0069bc50 skips the light setup while they are equal
//     and copies +0x8bb8 into +0x8bb9 after it.
//   * +0x8bbc (string, passed to new(0xd4) RbxSky ctor 0067fd60), +0x8bd8 SharedPtr<RbxSky> and +0x8be4 SceneNode*
//     are the fork's sky: setSkyBox 00692a10 / _queueSkiesForRendering 0068d7d0.
//   * ShadowCasterSceneQueryListener vtable 0084e994: ??_G 0068d670, queryResult(WorldFragment*) 00565ff0 (folded
//     `return true`), queryResult(MovableObject*) 0069c5f0. SceneMgrQueuedRenderableVisitor vtable 0084e9a4: ??_G
//     0068b6a0, visit overloads 0068d690 / 0068d6d0 / 0068d710; out-of-line destructor 0068b690.
//   * RbxSceneManagerFactory vtable 0084df14 (.?AVRbxSceneManagerFactory@Ogre@@ -> SceneManagerFactory): initMetaData
//     0068cf00, ??_G 00678440, getMetaData = import thunk 0069ff66, createInstance 0068fde0, destroyInstance 0068cf30.
// The fork re-declares the SceneManager methods (with the base's inline bodies), and the two nested helper classes and
// their members (which shadow the base's copies). Names of the fork's own members are naming choices; types and
// offsets come from the evidence above.
#include <OgreSceneManager.h>
#include <OgreSceneQuery.h>
#include <OgreRenderQueueSortingGrouping.h>
#include <OgreShadowCameraSetup.h>
#include "OgreRbx/RbxSky2008.h"   // minimal Ogre::RbxSky interface (virtual destructor, update); no layout claimed

struct NativeOgreRbxSceneManagerLayout;

namespace Ogre
{
	// RbxSky (exe-local; new(0xd4), constructor 0067fd60; SharedPtr<RbxSky> vtable 0084ec3c): OgreRbx/RbxSky2008.h

	class RbxSceneManager : public SceneManager
	{
		friend struct ::NativeOgreRbxSceneManagerLayout;

	protected:
		class ShadowCasterSceneQueryListener : public SceneQueryListener
		{
		protected:
			SceneManager* mSceneMgr;                        // +0x04
			ShadowCasterList* mCasterList;                  // +0x08
			bool mIsLightInFrustum;                         // +0x0c
			const PlaneBoundedVolumeList* mLightClipVolumeList;   // +0x10
			const Camera* mCamera;                          // +0x14
			const Light* mLight;                            // +0x18
			Real mFarDistSquared;                           // +0x1c
		public:
			ShadowCasterSceneQueryListener(SceneManager* sm) : mSceneMgr(sm),
				mCasterList(0), mIsLightInFrustum(false), mLightClipVolumeList(0),
				mCamera(0) {}
			void prepare(bool lightInFrustum,
				const PlaneBoundedVolumeList* lightClipVolumes,
				const Light* light, const Camera* cam, ShadowCasterList* casterList,
				Real farDistSquared)
			{
				mCasterList = casterList;
				mIsLightInFrustum = lightInFrustum;
				mLightClipVolumeList = lightClipVolumes;
				mCamera = cam;
				mLight = light;
				mFarDistSquared = farDistSquared;
			}
			bool queryResult(MovableObject* object);
			bool queryResult(SceneQuery::WorldFragment* fragment);
		};

		class SceneMgrQueuedRenderableVisitor : public QueuedRenderableVisitor
		{
		protected:
			const Pass* mUsedPass;                          // +0x04
		public:
			SceneMgrQueuedRenderableVisitor()
				:transparentShadowCastersMode(false) {}
			~SceneMgrQueuedRenderableVisitor() {}
			void visit(const Renderable* r);
			bool visit(const Pass* p);
			void visit(const RenderablePass* rp);
			RbxSceneManager* targetSceneMgr;                // +0x08 (visit 0068d690 / 0068d710 call the fork's
			                                                //  validate* copies 0068bfe0 / 0068bf80 through it)
			bool transparentShadowCastersMode;              // +0x0c
			bool autoLights;                                // +0x0d
			const LightList* manualLightList;               // +0x10
		};
		friend class SceneMgrQueuedRenderableVisitor;

		bool mPassLightingEnabled;                          // +0x8bb8
		bool mLightsLightingEnabled;                        // +0x8bb9
		String mRbxSkyName;                                 // +0x8bbc
		SharedPtr<RbxSky> mRbxSky;                          // +0x8bd8
		SceneNode* mRbxSkyNode;                             // +0x8be4
		ShadowCasterSceneQueryListener* mShadowCasterQueryListener;          // +0x8be8
		SceneMgrQueuedRenderableVisitor* mActiveQueuedRenderableVisitor;    // +0x8bec
		SceneMgrQueuedRenderableVisitor mDefaultQueuedRenderableVisitor;    // +0x8bf0

		// Non-virtual helpers re-declared by the fork: the fork's bodies call exe copies of them directly.
		const Pass* deriveShadowCasterPass(const Pass* pass);
		const Pass* deriveShadowReceiverPass(const Pass* pass);
		bool validatePassForRendering(const Pass* pass);
		bool validateRenderableForRendering(const Pass* pass, const Renderable* rend);
		MeshPtr createSkyboxPlane(
			BoxPlane bp,
			Real distance,
			const Quaternion& orientation,
			const String& groupName);
		MeshPtr createSkydomePlane(
			BoxPlane bp,
			Real curvature, Real tiling, Real distance,
			const Quaternion& orientation,
			int xsegments, int ysegments, int ySegmentsToKeep,
			const String& groupName);
		void useRenderableViewProjMode(const Renderable* pRend);
		void resetViewProjMode(void);
		bool fireRenderQueueStarted(uint8 id, const String& invocation);
		bool fireRenderQueueEnded(uint8 id, const String& invocation);
		void fireShadowTexturesUpdated(size_t numberOfShadowTextures);
		void fireShadowTexturesPreCaster(Light* light, Camera* camera);
		void fireShadowTexturesPreReceiver(Light* light, Frustum* f);
		void renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables,
			Pass* pass, const LightList *manualLightList, unsigned long flags,
			bool secondpass, bool zfail, bool twosided);
		MovableObjectCollection* getMovableObjectCollection(const String& typeName);
		const MovableObjectCollection* getMovableObjectCollection(const String& typeName) const;

		virtual void initRenderQueue(void);
		virtual void setViewport(Viewport *vp);
		virtual void renderVisibleObjectsDefaultSequence(void);
		virtual void renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* s);
		virtual void prepareRenderQueue(void);
		virtual void renderSingleObject(const Renderable* rend, const Pass* pass,
			bool doLightIteration, const LightList* manualLightList = 0);
		virtual void findLightsAffectingFrustum(const Camera* camera);
		virtual void initShadowVolumeMaterials(void);
		virtual void ensureShadowTexturesCreated();
		virtual void destroyShadowTextures(void);
		virtual void prepareShadowTextures(Camera* cam, Viewport* vp);
		virtual void renderShadowVolumesToStencil(const Light* light, const Camera* cam);
		virtual void setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided);
		virtual const ShadowCasterList& findShadowCastersForLight(const Light* light,
			const Camera* camera);
		virtual void renderBasicQueueGroupObjects(RenderQueueGroup* pGroup,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderAdditiveStencilShadowedQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderModulativeStencilShadowedQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderTextureShadowCasterQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderTextureShadowReceiverQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderModulativeTextureShadowedQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderAdditiveTextureShadowedQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
		virtual void renderObjects(const QueuedRenderableCollection& objs,
			QueuedRenderableCollection::OrganisationMode om,
			bool doLightIteration, const LightList* manualLightList = 0);
		virtual void renderTransparentShadowCasterObjects(const QueuedRenderableCollection& objs,
			QueuedRenderableCollection::OrganisationMode om,
			bool doLightIteration, const LightList* manualLightList = 0);
		virtual void updateRenderQueueSplitOptions(void);
		virtual void updateRenderQueueGroupSplitOptions(RenderQueueGroup* group,
			bool suppressShadows, bool suppressRenderState);

	public:
		RbxSceneManager(const String& instanceName);       // 0068e7c0
		virtual ~RbxSceneManager();                        // 0069e220 (??_G 0069eb00)

		virtual const String& getTypeName(void) const;
		virtual Camera* createCamera(const String& name);
		virtual Camera* getCamera(const String& name) const;
		virtual bool hasCamera(const String& name) const;
		virtual void destroyCamera(Camera *cam);
		virtual void destroyCamera(const String& name);
		virtual void destroyAllCameras(void);
		virtual Light* createLight(const String& name);
		virtual Light* getLight(const String& name) const;
		virtual bool hasLight(const String& name) const;
		virtual void destroyLight(const String& name);
		virtual void destroyLight(Light* light);
		virtual void destroyAllLights(void);
		virtual void _notifyLightsDirty(void);
		virtual const LightList& _getLightsAffectingFrustum(void) const;
		virtual void _populateLightList(const Vector3& position, Real radius, LightList& destList);
		virtual SceneNode* createSceneNode(void);
		virtual SceneNode* createSceneNode(const String& name);
		virtual void destroySceneNode(const String& name);
		virtual SceneNode* getRootSceneNode(void) const;
		virtual SceneNode* getSceneNode(const String& name) const;
		virtual bool hasSceneNode(const String& name) const;
		virtual Entity* createEntity(const String& entityName, const String& meshName);
		enum PrefabType {
			PT_PLANE,
			PT_CUBE,
			PT_SPHERE
		};
		virtual Entity* createEntity(const String& entityName, PrefabType ptype);   // new slot 228
		virtual Entity* getEntity(const String& name) const;
		virtual bool hasEntity(const String& name) const;
		virtual void destroyEntity(Entity* ent);
		virtual void destroyEntity(const String& name);
		virtual void destroyAllEntities(void);
		virtual ManualObject* createManualObject(const String& name);
		virtual ManualObject* getManualObject(const String& name) const;
		virtual bool hasManualObject(const String& name) const;
		virtual void destroyManualObject(ManualObject* obj);
		virtual void destroyManualObject(const String& name);
		virtual void destroyAllManualObjects(void);
		virtual BillboardChain* createBillboardChain(const String& name);
		virtual BillboardChain* getBillboardChain(const String& name) const;
		virtual bool hasBillboardChain(const String& name) const;
		virtual void destroyBillboardChain(BillboardChain* obj);
		virtual void destroyBillboardChain(const String& name);
		virtual void destroyAllBillboardChains(void);
		virtual RibbonTrail* createRibbonTrail(const String& name);
		virtual RibbonTrail* getRibbonTrail(const String& name) const;
		virtual bool hasRibbonTrail(const String& name) const;
		virtual void destroyRibbonTrail(RibbonTrail* obj);
		virtual void destroyRibbonTrail(const String& name);
		virtual void destroyAllRibbonTrails(void);
		virtual ParticleSystem* createParticleSystem(const String& name,
			const String& templateName);
		virtual ParticleSystem* createParticleSystem(const String& name,
			size_t quota = 500,
			const String& resourceGroup = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		virtual ParticleSystem* getParticleSystem(const String& name) const;
		virtual bool hasParticleSystem(const String& name) const;
		virtual void destroyParticleSystem(ParticleSystem* obj);
		virtual void destroyParticleSystem(const String& name);
		virtual void destroyAllParticleSystems(void);
		virtual void clearScene(void);
		virtual void setWorldGeometry(const String& filename);
		virtual void setWorldGeometry(DataStreamPtr& stream,
			const String& typeName = StringUtil::BLANK);
		virtual size_t estimateWorldGeometry(const String& filename) { return 0; }
		virtual size_t estimateWorldGeometry(DataStreamPtr& stream,
			const String& typeName = StringUtil::BLANK) { return 0; }
		virtual ViewPoint getSuggestedViewpoint(bool random = false);
		virtual bool setOption( const String& strKey, const void* pValue ) { return false; }
		virtual bool getOption( const String& strKey, void* pDestValue ) { return false; }
		virtual bool hasOption( const String& strKey ) const { return false; }
		virtual bool getOptionValues( const String& strKey, StringVector& refValueList ) { return false; }
		virtual bool getOptionKeys( StringVector& refKeys ) { return false; }
		virtual void _updateSceneGraph(Camera* cam);
		virtual void _findVisibleObjects(Camera* cam, VisibleObjectsBoundsInfo* visibleBounds, bool onlyShadowCasters);
		virtual void _applySceneAnimations(void);
		virtual void _renderVisibleObjects(void);
		virtual void _renderScene(Camera* camera, Viewport* vp, bool includeOverlays);
		virtual void _queueSkiesForRendering(Camera* cam);
		virtual void _setDestinationRenderSystem(RenderSystem* sys);
		virtual void setSkyPlane(
			bool enable,
			const Plane& plane, const String& materialName, Real scale = 1000,
			Real tiling = 10, bool drawFirst = true, Real bow = 0,
			int xsegments = 1, int ysegments = 1,
			const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		virtual bool isSkyPlaneEnabled(void) const { return mSkyPlaneEnabled; }
		virtual SceneNode* getSkyPlaneNode(void) const { return mSkyPlaneNode; }
		virtual const SkyPlaneGenParameters& getSkyPlaneGenParameters(void) const { return mSkyPlaneGenParameters; }
		virtual void setSkyBox(
			bool enable, const String& materialName, Real distance = 5000,
			bool drawFirst = true, const Quaternion& orientation = Quaternion::IDENTITY,
			const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		virtual bool isSkyBoxEnabled(void) const { return mSkyBoxEnabled; }
		virtual SceneNode* getSkyBoxNode(void) const { return mSkyBoxNode; }
		virtual const SkyBoxGenParameters& getSkyBoxGenParameters(void) const { return mSkyBoxGenParameters; }
		virtual void setSkyDome(
			bool enable, const String& materialName, Real curvature = 10,
			Real tiling = 8, Real distance = 4000, bool drawFirst = true,
			const Quaternion& orientation = Quaternion::IDENTITY,
			int xsegments = 16, int ysegments = 16, int ysegments_keep = -1,
			const String& groupName = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
		virtual bool isSkyDomeEnabled(void) const { return mSkyDomeEnabled; }
		virtual SceneNode* getSkyDomeNode(void) const { return mSkyDomeNode; }
		virtual const SkyDomeGenParameters& getSkyDomeGenParameters(void) const { return mSkyDomeGenParameters; }
		virtual FogMode getFogMode(void) const;
		virtual const ColourValue& getFogColour(void) const;
		virtual Real getFogStart(void) const;
		virtual Real getFogEnd(void) const;
		virtual Real getFogDensity(void) const;
		virtual BillboardSet* createBillboardSet(const String& name, unsigned int poolSize = 20);
		virtual BillboardSet* getBillboardSet(const String& name) const;
		virtual bool hasBillboardSet(const String& name) const;
		virtual void destroyBillboardSet(BillboardSet* set);
		virtual void destroyBillboardSet(const String& name);
		virtual void destroyAllBillboardSets(void);
		virtual void setDisplaySceneNodes(bool display);
		virtual bool getDisplaySceneNodes(void) const {return mDisplayNodes;}
		virtual Animation* createAnimation(const String& name, Real length);
		virtual Animation* getAnimation(const String& name) const;
		virtual bool hasAnimation(const String& name) const;
		virtual void destroyAnimation(const String& name);
		virtual void destroyAllAnimations(void);
		virtual AnimationState* createAnimationState(const String& animName);
		virtual AnimationState* getAnimationState(const String& animName) const;
		virtual bool hasAnimationState(const String& name) const;
		virtual void destroyAnimationState(const String& name);
		virtual void destroyAllAnimationStates(void);
		virtual void manualRender(RenderOperation* rend, Pass* pass, Viewport* vp,
			const Matrix4& worldMatrix, const Matrix4& viewMatrix, const Matrix4& projMatrix,
			bool doBeginEndFrame = false) ;
		virtual RenderQueue* getRenderQueue(void);
		virtual void addRenderQueueListener(RenderQueueListener* newListener);
		virtual void removeRenderQueueListener(RenderQueueListener* delListener);
		virtual void addSpecialCaseRenderQueue(uint8 qid);
		virtual void removeSpecialCaseRenderQueue(uint8 qid);
		virtual void clearSpecialCaseRenderQueues(void);
		virtual void setSpecialCaseRenderQueueMode(SpecialCaseRenderQueueMode mode);
		virtual SpecialCaseRenderQueueMode getSpecialCaseRenderQueueMode(void);
		virtual bool isRenderQueueToBeProcessed(uint8 qid);
		virtual void setWorldGeometryRenderQueue(uint8 qid);
		virtual uint8 getWorldGeometryRenderQueue(void);
		virtual void showBoundingBoxes(bool bShow);
		virtual bool getShowBoundingBoxes() const;
		virtual void _notifyAutotrackingSceneNode(SceneNode* node, bool autoTrack);
		virtual AxisAlignedBoxSceneQuery*
			createAABBQuery(const AxisAlignedBox& box, unsigned long mask = 0xFFFFFFFF);
		virtual SphereSceneQuery*
			createSphereQuery(const Sphere& sphere, unsigned long mask = 0xFFFFFFFF);
		virtual PlaneBoundedVolumeListSceneQuery*
			createPlaneBoundedVolumeQuery(const PlaneBoundedVolumeList& volumes, unsigned long mask = 0xFFFFFFFF);
		virtual RaySceneQuery*
			createRayQuery(const Ray& ray, unsigned long mask = 0xFFFFFFFF);
		virtual IntersectionSceneQuery*
			createIntersectionQuery(unsigned long mask = 0xFFFFFFFF);
		virtual void destroyQuery(SceneQuery* query);
		virtual void setShadowTechnique(ShadowTechnique technique);
		virtual ShadowTechnique getShadowTechnique(void) const { return mShadowTechnique; }
		virtual void setShowDebugShadows(bool debug) { mDebugShadows = debug; }
		virtual bool getShowDebugShadows(void ) const { return mDebugShadows; }
		virtual void setShadowColour(const ColourValue& colour);
		virtual const ColourValue& getShadowColour(void) const;
		virtual void setShadowDirectionalLightExtrusionDistance(Real dist);
		virtual Real getShadowDirectionalLightExtrusionDistance(void) const;
		virtual void setShadowFarDistance(Real distance);
		virtual Real getShadowFarDistance(void) const
		{ return mShadowFarDist; }
		virtual void setShadowIndexBufferSize(size_t size);
		virtual size_t getShadowIndexBufferSize(void) const
		{ return mShadowIndexBufferSize; }
		virtual void setShadowTextureSize(unsigned short size);
		virtual void setShadowTextureConfig(size_t shadowIndex, unsigned short width,
			unsigned short height, PixelFormat format);
		virtual void setShadowTextureConfig(size_t shadowIndex,
			const ShadowTextureConfig& config);
		virtual void setShadowTexturePixelFormat(PixelFormat fmt);
		virtual void setShadowTextureCount(size_t count);
		virtual void setShadowTextureSettings(unsigned short size, unsigned short count,
			PixelFormat fmt = PF_X8R8G8B8);
		virtual const TexturePtr& getShadowTexture(size_t shadowIndex);
		virtual void setShadowDirLightTextureOffset(Real offset) { mShadowTextureOffset = offset;}
		virtual Real getShadowDirLightTextureOffset(void)  const { return mShadowTextureOffset; }
		virtual void setShadowTextureFadeStart(Real fadeStart)
		{ mShadowTextureFadeStart = fadeStart; }
		virtual void setShadowTextureFadeEnd(Real fadeEnd)
		{ mShadowTextureFadeEnd = fadeEnd; }
		virtual void setShadowTextureSelfShadow(bool selfShadow);
		virtual bool getShadowTextureSelfShadow(void) const
		{ return mShadowTextureSelfShadow; }
		virtual void setShadowTextureCasterMaterial(const String& name);
		virtual void setShadowTextureReceiverMaterial(const String& name);
		virtual void setShadowCasterRenderBackFaces(bool bf) { mShadowCasterRenderBackFaces = bf; }
		virtual bool getShadowCasterRenderBackFaces() const { return mShadowCasterRenderBackFaces; }
		virtual void setShadowCameraSetup(const ShadowCameraSetupPtr& shadowSetup);
		virtual const ShadowCameraSetupPtr& getShadowCameraSetup() const;
		virtual void setShadowUseInfiniteFarPlane(bool enable) {
			mShadowUseInfiniteFarPlane = enable; }
		virtual bool isShadowTechniqueStencilBased(void) const
		{ return (mShadowTechnique & SHADOWDETAILTYPE_STENCIL) != 0; }
		virtual bool isShadowTechniqueTextureBased(void) const
		{ return (mShadowTechnique & SHADOWDETAILTYPE_TEXTURE) != 0; }
		virtual bool isShadowTechniqueModulative(void) const
		{ return (mShadowTechnique & SHADOWDETAILTYPE_MODULATIVE) != 0; }
		virtual bool isShadowTechniqueAdditive(void) const
		{ return (mShadowTechnique & SHADOWDETAILTYPE_ADDITIVE) != 0; }
		virtual bool isShadowTechniqueIntegrated(void) const
		{ return (mShadowTechnique & SHADOWDETAILTYPE_INTEGRATED) != 0; }
		virtual bool isShadowTechniqueInUse(void) const
		{ return mShadowTechnique != SHADOWTYPE_NONE; }
		virtual void addShadowListener(ShadowListener* s);
		virtual void removeShadowListener(ShadowListener* s);
		virtual StaticGeometry* createStaticGeometry(const String& name);
		virtual StaticGeometry* getStaticGeometry(const String& name) const;
		virtual bool hasStaticGeometry(const String& name) const;
		virtual void destroyStaticGeometry(StaticGeometry* geom);
		virtual void destroyStaticGeometry(const String& name);
		virtual void destroyAllStaticGeometry(void);
		virtual InstancedGeometry* createInstancedGeometry(const String& name);
		virtual InstancedGeometry* getInstancedGeometry(const String& name) const;
		virtual void destroyInstancedGeometry(InstancedGeometry* geom);
		virtual void destroyInstancedGeometry(const String& name);
		virtual void destroyAllInstancedGeometry(void);
		virtual MovableObject* createMovableObject(const String& name,
			const String& typeName, const NameValuePairList* params = 0);
		virtual void destroyMovableObject(const String& name, const String& typeName);
		virtual void destroyMovableObject(MovableObject* m);
		virtual void destroyAllMovableObjectsByType(const String& typeName);
		virtual void destroyAllMovableObjects(void);
		virtual MovableObject* getMovableObject(const String& name, const String& typeName) const;
		virtual bool hasMovableObject(const String& name, const String& typeName) const;
		virtual MovableObjectIterator getMovableObjectIterator(const String& typeName);
		virtual void injectMovableObject(MovableObject* m);
		virtual void extractMovableObject(const String& name, const String& typeName);
		virtual void extractMovableObject(MovableObject* m);
		virtual void extractAllMovableObjectsByType(const String& typeName);
		virtual void setVisibilityMask(uint32 vmask) { mVisibilityMask = vmask; }
		virtual uint32 getVisibilityMask(void) { return mVisibilityMask; }
		virtual void setFindVisibleObjects(bool find) { mFindVisibleObjects = find; }
		virtual bool getFindVisibleObjects(void) { return mFindVisibleObjects; }
		virtual void _injectRenderWithPass(Pass *pass, Renderable *rend, bool shadowDerivation = true);
		virtual void _suppressRenderStateChanges(bool suppress);
		virtual bool _areRenderStateChangesSuppressed(void) const
		{ return mSuppressRenderStateChanges; }
		virtual const Pass* _setPass(const Pass* pass,
			bool evenIfSuppressed = false, bool shadowDerivation = true);
		virtual void _suppressShadows(bool suppress);
		virtual bool _areShadowsSuppressed(void) const
		{ return mSuppressShadows; }
		virtual void _renderQueueGroupObjects(RenderQueueGroup* group,
			QueuedRenderableCollection::OrganisationMode om);
	};

	class RbxSceneManagerFactory : public SceneManagerFactory
	{
	protected:
		void initMetaData(void) const;                     // 0068cf00
	public:
		RbxSceneManagerFactory() {}
		~RbxSceneManagerFactory() {}                       // ??_G 00678440
		static const String FACTORY_TYPE_NAME;             // 0097dc3c
		SceneManager* createInstance(const String& instanceName);   // 0068fde0
		void destroyInstance(SceneManager* instance);      // 0068cf30
	};
}
