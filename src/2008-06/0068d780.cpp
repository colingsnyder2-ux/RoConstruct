// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_remaining_methods_04658f2fb3f66782.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <OgreSpotShadowFadePng.h>
#include <OgreShadowVolumeExtrudeProgram.h>
using namespace Ogre;
struct HeaderRecovery : Ogre::SceneManager {
SceneManager::SpecialCaseRenderQueueMode recover_getSpecialCaseRenderQueueMode(void);
Camera* recover_createCamera(const String& name);
Camera* recover_getCamera(const String& name) const;
ParticleSystem* recover_createParticleSystem(const String& name,
	const String& templateName);
ParticleSystem* recover_createParticleSystem(const String& name,
	size_t quota, const String& group);
ParticleSystem* recover_getParticleSystem(const String& name) const;
const Pass* recover__setPass(const Pass* pass, bool evenIfSuppressed, 
								   bool shadowDerivation);
MeshPtr recover_createSkyboxPlane(
                                      BoxPlane bp,
                                      Real distance,
                                      const Quaternion& orientation,
                                      const String& groupName);
MeshPtr recover_createSkydomePlane(
                                       BoxPlane bp,
                                       Real curvature,
                                       Real tiling,
                                       Real distance,
                                       const Quaternion& orientation,
                                       int xsegments, int ysegments, int ysegments_keep, 
                                       const String& groupName);
void recover_renderSingleObject(const Renderable* rend, const Pass* pass, 
                                      bool doLightIteration, const LightList* manualLightList);
ViewPoint recover_getSuggestedViewpoint(bool random);
FogMode recover_getFogMode(void) const;
BillboardSet* recover_createBillboardSet(const String& name, unsigned int poolSize);
BillboardSet* recover_getBillboardSet(const String& name) const;
Animation* recover_createAnimation(const String& name, Real length);
Animation* recover_getAnimation(const String& name) const;
AnimationState* recover_createAnimationState(const String& animName);
AnimationState* recover_getAnimationState(const String& animName) const;
const SceneManager::ShadowCasterList& recover_findShadowCastersForLight(
    const Light* light, const Camera* camera);
void recover_initShadowVolumeMaterials(void);
const Pass* recover_deriveShadowCasterPass(const Pass* pass);
const Pass* recover_deriveShadowReceiverPass(const Pass* pass);
void recover_renderShadowVolumesToStencil(const Light* light, const Camera* camera);
ConstShadowTextureConfigIterator recover_getShadowTextureConfigIterator() const;
StaticGeometry* recover_createStaticGeometry(const String& name);
StaticGeometry* recover_getStaticGeometry(const String& name) const;
InstancedGeometry* recover_createInstancedGeometry(const String& name);
InstancedGeometry* recover_getInstancedGeometry(const String& name) const;
MovableObject* recover_createMovableObject(const String& name, 
	const String& typeName, const NameValuePairList* params);
MovableObject* recover_getMovableObject(const String& name, const String& typeName) const;
SceneManager::SceneMgrQueuedRenderableVisitor* recover_getQueuedRenderableVisitor(void) const;
};
SceneManager::SpecialCaseRenderQueueMode HeaderRecovery::recover_getSpecialCaseRenderQueueMode(void) {
	return mSpecialCaseQueueMode;
}
Camera* HeaderRecovery::recover_createCamera(const String& name) {
    // Check name not used
    if (mCameras.find(name) != mCameras.end())
    {
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "A camera with the name " + name + " already exists",
            "SceneManager::createCamera" );
    }

    Camera *c = new Camera(name, this);
    mCameras.insert(CameraList::value_type(name, c));

	// create visible bounds aab map entry
	mCamVisibleObjectsMap[c] = VisibleObjectsBoundsInfo();

    return c;
}
Camera* HeaderRecovery::recover_getCamera(const String& name) const {
    CameraList::const_iterator i = mCameras.find(name);
    if (i == mCameras.end())
    {
        OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find Camera with name " + name,
            "SceneManager::getCamera");
    }
    else
    {
        return i->second;
    }
}
ParticleSystem* HeaderRecovery::recover_createParticleSystem(const String& name,
	const String& templateName) {
	NameValuePairList params;
	params["templateName"] = templateName;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}
ParticleSystem* HeaderRecovery::recover_createParticleSystem(const String& name,
	size_t quota, const String& group) {
	NameValuePairList params;
	params["quota"] = StringConverter::toString(quota);
	params["resourceGroup"] = group;
	
	return static_cast<ParticleSystem*>(
		createMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME, 
			&params));
}
ParticleSystem* HeaderRecovery::recover_getParticleSystem(const String& name) const {
	return static_cast<ParticleSystem*>(
		getMovableObject(name, ParticleSystemFactory::FACTORY_TYPE_NAME));

}
const Pass* HeaderRecovery::recover__setPass(const Pass* pass, bool evenIfSuppressed, 
								   bool shadowDerivation) {
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
MeshPtr HeaderRecovery::recover_createSkyboxPlane(
                                      BoxPlane bp,
                                      Real distance,
                                      const Quaternion& orientation,
                                      const String& groupName) {
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
MeshPtr HeaderRecovery::recover_createSkydomePlane(
                                       BoxPlane bp,
                                       Real curvature,
                                       Real tiling,
                                       Real distance,
                                       const Quaternion& orientation,
                                       int xsegments, int ysegments, int ysegments_keep, 
                                       const String& groupName) {

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
void HeaderRecovery::recover_renderSingleObject(const Renderable* rend, const Pass* pass, 
                                      bool doLightIteration, const LightList* manualLightList) {
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
ViewPoint HeaderRecovery::recover_getSuggestedViewpoint(bool random) {
    // By default return the origin
    ViewPoint vp;
    vp.position = Vector3::ZERO;
    vp.orientation = Quaternion::IDENTITY;
    return vp;
}
FogMode HeaderRecovery::recover_getFogMode(void) const {
    return mFogMode;
}
BillboardSet* HeaderRecovery::recover_createBillboardSet(const String& name, unsigned int poolSize) {
	NameValuePairList params;
	params["poolSize"] = StringConverter::toString(poolSize);
	return static_cast<BillboardSet*>(
		createMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME, &params));
}
BillboardSet* HeaderRecovery::recover_getBillboardSet(const String& name) const {
	return static_cast<BillboardSet*>(
		getMovableObject(name, BillboardSetFactory::FACTORY_TYPE_NAME));
}
Animation* HeaderRecovery::recover_createAnimation(const String& name, Real length) {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

    // Check name not used
    if (mAnimationsList.find(name) != mAnimationsList.end())
    {
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "An animation with the name " + name + " already exists",
            "SceneManager::createAnimation" );
    }

    Animation* pAnim = new Animation(name, length);
    mAnimationsList[name] = pAnim;
    return pAnim;
}
Animation* HeaderRecovery::recover_getAnimation(const String& name) const {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	AnimationList::const_iterator i = mAnimationsList.find(name);
    if (i == mAnimationsList.end())
    {
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
            "Cannot find animation with name " + name, 
            "SceneManager::getAnimation");
    }
    return i->second;
}
AnimationState* HeaderRecovery::recover_createAnimationState(const String& animName) {
    // Get animation, this will throw an exception if not found
    Animation* anim = getAnimation(animName);

    // Create new state
	return mAnimationStates.createAnimationState(animName, 0, anim->getLength());

}
AnimationState* HeaderRecovery::recover_getAnimationState(const String& animName) const {
	return mAnimationStates.getAnimationState(animName);

}
const SceneManager::ShadowCasterList& HeaderRecovery::recover_findShadowCastersForLight(
    const Light* light, const Camera* camera) {
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
void HeaderRecovery::recover_initShadowVolumeMaterials(void) {
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
const Pass* HeaderRecovery::recover_deriveShadowCasterPass(const Pass* pass) {
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
const Pass* HeaderRecovery::recover_deriveShadowReceiverPass(const Pass* pass) {

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
void HeaderRecovery::recover_renderShadowVolumesToStencil(const Light* light, const Camera* camera) {
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
ConstShadowTextureConfigIterator HeaderRecovery::recover_getShadowTextureConfigIterator() const {
	return ConstShadowTextureConfigIterator(
		mShadowTextureConfigList.begin(), mShadowTextureConfigList.end());

}
StaticGeometry* HeaderRecovery::recover_createStaticGeometry(const String& name) {
	// Check not existing
	if (mStaticGeometryList.find(name) != mStaticGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"StaticGeometry with name '" + name + "' already exists!", 
			"SceneManager::createStaticGeometry");
	}
	StaticGeometry* ret = new StaticGeometry(this, name);
	mStaticGeometryList[name] = ret;
	return ret;
}
StaticGeometry* HeaderRecovery::recover_getStaticGeometry(const String& name) const {
	StaticGeometryList::const_iterator i = mStaticGeometryList.find(name);
	if (i == mStaticGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"StaticGeometry with name '" + name + "' not found", 
			"SceneManager::createStaticGeometry");
	}
	return i->second;
}
InstancedGeometry* HeaderRecovery::recover_createInstancedGeometry(const String& name) {
	// Check not existing
	if (mInstancedGeometryList.find(name) != mInstancedGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_DUPLICATE_ITEM, 
			"InstancedGeometry with name '" + name + "' already exists!", 
			"SceneManager::createInstancedGeometry");
	}
	InstancedGeometry* ret = new InstancedGeometry(this, name);
	mInstancedGeometryList[name] = ret;
	return ret;
}
InstancedGeometry* HeaderRecovery::recover_getInstancedGeometry(const String& name) const {
	InstancedGeometryList::const_iterator i = mInstancedGeometryList.find(name);
	if (i == mInstancedGeometryList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"InstancedGeometry with name '" + name + "' not found", 
			"SceneManager::createInstancedGeometry");
	}
	return i->second;
}
MovableObject* HeaderRecovery::recover_createMovableObject(const String& name, 
	const String& typeName, const NameValuePairList* params) {
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
				"SceneManager::createMovableObject");
		}

		MovableObject* newObj = factory->createInstance(name, this, params);
		objectMap->map[name] = newObj;
		return newObj;
	}

}
MovableObject* HeaderRecovery::recover_getMovableObject(const String& name, const String& typeName) const {
	const MovableObjectCollection* objectMap = getMovableObjectCollection(typeName);
	
	{
		OGRE_LOCK_MUTEX(objectMap->mutex)
		MovableObjectMap::const_iterator mi = objectMap->map.find(name);
		if (mi == objectMap->map.end())
		{
			OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
				"Object named '" + name + "' does not exist.", 
				"SceneManager::getMovableObject");
		}
		return mi->second;
	}
	
}
SceneManager::SceneMgrQueuedRenderableVisitor* HeaderRecovery::recover_getQueuedRenderableVisitor(void) const {
	return mActiveQueuedRenderableVisitor;
}
