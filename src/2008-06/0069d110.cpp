// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_large_methods_fe8e0ed61a73b8e9.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
struct HeaderRecovery : Ogre::SceneManager {
void recover__populateLightList(const Vector3& position, Real radius, 
									  LightList& destList);
void recover__renderScene(Camera* camera, Viewport* vp, bool includeOverlays);
void recover_setSkyPlane(
                               bool enable,
                               const Plane& plane,
                               const String& materialName,
                               Real gscale,
                               Real tiling,
                               bool drawFirst,
                               Real bow, 
                               int xsegments, int ysegments, 
                               const String& groupName);
void recover_setSkyBox(
                             bool enable,
                             const String& materialName,
                             Real distance,
                             bool drawFirst,
                             const Quaternion& orientation,
                             const String& groupName);
void recover_setSkyDome(
                              bool enable,
                              const String& materialName,
                              Real curvature,
                              Real tiling,
                              Real distance,
                              bool drawFirst,
                              const Quaternion& orientation,
                              int xsegments, int ysegments, int ySegmentsToKeep,
                              const String& groupName);
void recover_renderAdditiveStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
void recover_renderModulativeStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
void recover_renderTextureShadowCasterQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
void recover_renderModulativeTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
void recover_renderAdditiveTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
void recover_findLightsAffectingFrustum(const Camera* camera);
void recover_renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables,
                                             Pass* pass,
                                             const LightList *manualLightList,
                                             unsigned long flags,
                                             bool secondpass, bool zfail, bool twosided);
void recover_setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided);
void recover_ensureShadowTexturesCreated();
void recover_prepareShadowTextures(Camera* cam, Viewport* vp);
};
void HeaderRecovery::recover__populateLightList(const Vector3& position, Real radius, 
									  LightList& destList) {
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
void HeaderRecovery::recover__renderScene(Camera* camera, Viewport* vp, bool includeOverlays) {
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
void HeaderRecovery::recover_setSkyPlane(
                               bool enable,
                               const Plane& plane,
                               const String& materialName,
                               Real gscale,
                               Real tiling,
                               bool drawFirst,
                               Real bow, 
                               int xsegments, int ysegments, 
                               const String& groupName) {
    if (enable)
    {
        String meshName = mName + "SkyPlane";
        mSkyPlane = plane;

        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky plane material '" + materialName + "' not found.",
                "SceneManager::setSkyPlane");
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
void HeaderRecovery::recover_setSkyBox(
                             bool enable,
                             const String& materialName,
                             Real distance,
                             bool drawFirst,
                             const Quaternion& orientation,
                             const String& groupName) {
    if (enable)
    {
        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky box material '" + materialName + "' not found.",
                "SceneManager::setSkyBox");
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
void HeaderRecovery::recover_setSkyDome(
                              bool enable,
                              const String& materialName,
                              Real curvature,
                              Real tiling,
                              Real distance,
                              bool drawFirst,
                              const Quaternion& orientation,
                              int xsegments, int ysegments, int ySegmentsToKeep,
                              const String& groupName) {
    if (enable)
    {
        MaterialPtr m = MaterialManager::getSingleton().getByName(materialName);
        if (m.isNull())
        {
            OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
                "Sky dome material '" + materialName + "' not found.",
                "SceneManager::setSkyDome");
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
void HeaderRecovery::recover_renderAdditiveStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderModulativeStencilShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderTextureShadowCasterQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderModulativeTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderAdditiveTextureShadowedQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_findLightsAffectingFrustum(const Camera* camera) {
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
void HeaderRecovery::recover_renderShadowVolumeObjects(ShadowCaster::ShadowRenderableListIterator iShadowRenderables,
                                             Pass* pass,
                                             const LightList *manualLightList,
                                             unsigned long flags,
                                             bool secondpass, bool zfail, bool twosided) {
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
void HeaderRecovery::recover_setShadowVolumeStencilState(bool secondpass, bool zfail, bool twosided) {
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
void HeaderRecovery::recover_ensureShadowTexturesCreated() {
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
void HeaderRecovery::recover_prepareShadowTextures(Camera* cam, Viewport* vp) {
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
