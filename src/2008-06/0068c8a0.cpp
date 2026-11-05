// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_client_medium_methods_9dcc4c18d140c047.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
using namespace Ogre;
struct HeaderRecovery : Ogre::SceneManager {
void recover_initRenderQueue(void);
void recover_destroyCamera(const String& name);
void recover_destroyAllCameras(void);
Entity* recover_createEntity(const String& entityName, PrefabType ptype);
void recover_clearScene(void);
SceneNode* recover_createSceneNode(const String& name);
void recover_destroySceneNode(const String& name);
SceneNode* recover_getSceneNode(const String& name) const;
void recover_prepareRenderQueue(void);
void recover__updateSceneGraph(Camera* cam);
void recover__renderVisibleObjects(void);
void recover_renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* seq);
void recover_renderVisibleObjectsDefaultSequence(void);
void recover_renderTextureShadowReceiverQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om);
bool recover_validatePassForRendering(const Pass* pass);
bool recover_validateRenderableForRendering(const Pass* pass, const Renderable* rend);
void recover_renderObjects(const QueuedRenderableCollection& objs, 
								 QueuedRenderableCollection::OrganisationMode om, 
								 bool doLightIteration, 
                                 const LightList* manualLightList);
void recover__renderQueueGroupObjects(RenderQueueGroup* pGroup, 
										   QueuedRenderableCollection::OrganisationMode om);
void recover_renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, 
												QueuedRenderableCollection::OrganisationMode om);
void recover_renderTransparentShadowCasterObjects(
	const QueuedRenderableCollection& objs, 
	QueuedRenderableCollection::OrganisationMode om, bool doLightIteration,
	const LightList* manualLightList);
void recover_destroyAnimation(const String& name);
void recover_destroyAllAnimations(void);
void recover__applySceneAnimations(void);
void recover_manualRender(RenderOperation* rend, 
                                Pass* pass, Viewport* vp, const Matrix4& worldMatrix, 
                                const Matrix4& viewMatrix, const Matrix4& projMatrix, 
                                bool doBeginEndFrame);
void recover_useRenderableViewProjMode(const Renderable* pRend);
void recover_resetViewProjMode(void);
void recover__queueSkiesForRendering(Camera* cam);
void recover_removeRenderQueueListener(RenderQueueListener* delListener);
void recover_removeShadowListener(ShadowListener* delListener);
bool recover_fireRenderQueueStarted(uint8 id, const String& invocation);
bool recover_fireRenderQueueEnded(uint8 id, const String& invocation);
void recover_setShadowTechnique(ShadowTechnique technique);
void recover_updateRenderQueueSplitOptions(void);
void recover_updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, 
	bool suppressShadows, bool suppressRenderState);
void recover_setShadowColour(const ColourValue& colour);
void recover_setShadowIndexBufferSize(size_t size);
void recover_setShadowTextureConfig(size_t shadowIndex, 
	const ShadowTextureConfig& config);
void recover_setShadowTextureSize(unsigned short size);
void recover_setShadowTextureSettings(unsigned short size, 
	unsigned short count, PixelFormat fmt);
void recover_setShadowTextureCasterMaterial(const String& name);
void recover_setShadowTextureReceiverMaterial(const String& name);
void recover_destroyShadowTextures(void);
void recover_destroyMovableObject(const String& name, const String& typeName);
void recover_destroyAllMovableObjectsByType(const String& typeName);
void recover_destroyAllMovableObjects(void);
bool recover_hasMovableObject(const String& name, const String& typeName) const;
void recover_extractMovableObject(const String& name, const String& typeName);
};
void HeaderRecovery::recover_initRenderQueue(void) {
    mRenderQueue = new RenderQueue();
    // init render queues that do not need shadows
    mRenderQueue->getQueueGroup(RENDER_QUEUE_BACKGROUND)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_OVERLAY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_EARLY)->setShadowsEnabled(false);
    mRenderQueue->getQueueGroup(RENDER_QUEUE_SKIES_LATE)->setShadowsEnabled(false);
}
void HeaderRecovery::recover_destroyCamera(const String& name) {
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
void HeaderRecovery::recover_destroyAllCameras(void) {

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
Entity* HeaderRecovery::recover_createEntity(const String& entityName, PrefabType ptype) {
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
        "SceneManager::createEntity");
}
void HeaderRecovery::recover_clearScene(void) {
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
SceneNode* HeaderRecovery::recover_createSceneNode(const String& name) {
    // Check name not used
    if (mSceneNodes.find(name) != mSceneNodes.end())
    {
        OGRE_EXCEPT(
            Exception::ERR_DUPLICATE_ITEM,
            "A scene node with the name " + name + " already exists",
            "SceneManager::createSceneNode" );
    }

    SceneNode* sn = new SceneNode(this, name);
    mSceneNodes[sn->getName()] = sn;
    return sn;
}
void HeaderRecovery::recover_destroySceneNode(const String& name) {
    SceneNodeList::iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "SceneNode '" + name + "' not found.",
            "SceneManager::destroySceneNode");
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
SceneNode* HeaderRecovery::recover_getSceneNode(const String& name) const {
    SceneNodeList::const_iterator i = mSceneNodes.find(name);

    if (i == mSceneNodes.end())
    {
        OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "SceneNode '" + name + "' not found.",
            "SceneManager::getSceneNode");
    }

    return i->second;

}
void HeaderRecovery::recover_prepareRenderQueue(void) {
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
void HeaderRecovery::recover__updateSceneGraph(Camera* cam) {
	// Process queued needUpdate calls 
	Node::processQueuedUpdates();

    // Cascade down the graph updating transforms & world bounds
    // In this implementation, just update from the root
    // Smarter SceneManager subclasses may choose to update only
    //   certain scene graph branches
    mSceneRoot->_update(true, false);


}
void HeaderRecovery::recover__renderVisibleObjects(void) {
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
void HeaderRecovery::recover_renderVisibleObjectsCustomSequence(RenderQueueInvocationSequence* seq) {
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
void HeaderRecovery::recover_renderVisibleObjectsDefaultSequence(void) {
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
void HeaderRecovery::recover_renderTextureShadowReceiverQueueGroupObjects(
	RenderQueueGroup* pGroup, 
	QueuedRenderableCollection::OrganisationMode om) {
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
bool HeaderRecovery::recover_validatePassForRendering(const Pass* pass) {
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
bool HeaderRecovery::recover_validateRenderableForRendering(const Pass* pass, const Renderable* rend) {
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
void HeaderRecovery::recover_renderObjects(const QueuedRenderableCollection& objs, 
								 QueuedRenderableCollection::OrganisationMode om, 
								 bool doLightIteration, 
                                 const LightList* manualLightList) {
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
	// Use visitor
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, om);
}
void HeaderRecovery::recover__renderQueueGroupObjects(RenderQueueGroup* pGroup, 
										   QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderBasicQueueGroupObjects(RenderQueueGroup* pGroup, 
												QueuedRenderableCollection::OrganisationMode om) {
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
void HeaderRecovery::recover_renderTransparentShadowCasterObjects(
	const QueuedRenderableCollection& objs, 
	QueuedRenderableCollection::OrganisationMode om, bool doLightIteration,
	const LightList* manualLightList) {
	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = true;
	mActiveQueuedRenderableVisitor->autoLights = doLightIteration;
	mActiveQueuedRenderableVisitor->manualLightList = manualLightList;
	
	// Sort descending (transparency)
	objs.acceptVisitor(mActiveQueuedRenderableVisitor, 
		QueuedRenderableCollection::OM_SORT_DESCENDING);

	mActiveQueuedRenderableVisitor->transparentShadowCastersMode = false;
}
void HeaderRecovery::recover_destroyAnimation(const String& name) {
	OGRE_LOCK_MUTEX(mAnimationsListMutex)

	// Also destroy any animation states referencing this animation
	mAnimationStates.removeAnimationState(name);

	AnimationList::iterator i = mAnimationsList.find(name);
	if (i == mAnimationsList.end())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"Cannot find animation with name " + name, 
			"SceneManager::getAnimation");
	}

	// Free memory
	delete i->second;

	mAnimationsList.erase(i);

}
void HeaderRecovery::recover_destroyAllAnimations(void) {
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
void HeaderRecovery::recover__applySceneAnimations(void) {
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
void HeaderRecovery::recover_manualRender(RenderOperation* rend, 
                                Pass* pass, Viewport* vp, const Matrix4& worldMatrix, 
                                const Matrix4& viewMatrix, const Matrix4& projMatrix, 
                                bool doBeginEndFrame) {
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
void HeaderRecovery::recover_useRenderableViewProjMode(const Renderable* pRend) {
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
void HeaderRecovery::recover_resetViewProjMode(void) {
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
void HeaderRecovery::recover__queueSkiesForRendering(Camera* cam) {
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
void HeaderRecovery::recover_removeRenderQueueListener(RenderQueueListener* delListener) {
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
void HeaderRecovery::recover_removeShadowListener(ShadowListener* delListener) {
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
bool HeaderRecovery::recover_fireRenderQueueStarted(uint8 id, const String& invocation) {
    RenderQueueListenerList::iterator i, iend;
    bool skip = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueStarted(id, invocation, skip);
    }
    return skip;
}
bool HeaderRecovery::recover_fireRenderQueueEnded(uint8 id, const String& invocation) {
    RenderQueueListenerList::iterator i, iend;
    bool repeat = false;

    iend = mRenderQueueListeners.end();
    for (i = mRenderQueueListeners.begin(); i != iend; ++i)
    {
        (*i)->renderQueueEnded(id, invocation, repeat);
    }
    return repeat;
}
void HeaderRecovery::recover_setShadowTechnique(ShadowTechnique technique) {
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
void HeaderRecovery::recover_updateRenderQueueSplitOptions(void) {
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
void HeaderRecovery::recover_updateRenderQueueGroupSplitOptions(RenderQueueGroup* group, 
	bool suppressShadows, bool suppressRenderState) {
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
void HeaderRecovery::recover_setShadowColour(const ColourValue& colour) {
    mShadowColour = colour;

    // Change shadow material setting only when it's prepared,
    // otherwise, it'll set up while preparing shadow materials.
    if (mShadowModulativePass)
    {
        mShadowModulativePass->getTextureUnitState(0)->setColourOperationEx(
            LBX_MODULATE, LBS_MANUAL, LBS_CURRENT, colour);
    }
}
void HeaderRecovery::recover_setShadowIndexBufferSize(size_t size) {
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
void HeaderRecovery::recover_setShadowTextureConfig(size_t shadowIndex, 
	const ShadowTextureConfig& config) {
	if (shadowIndex >= mShadowTextureConfigList.size())
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, 
			"shadowIndex out of bounds",
			"SceneManager::setShadowTextureConfig");
	}
	mShadowTextureConfigList[shadowIndex] = config;

	mShadowTextureConfigDirty = true;
}
void HeaderRecovery::recover_setShadowTextureSize(unsigned short size) {
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
void HeaderRecovery::recover_setShadowTextureSettings(unsigned short size, 
	unsigned short count, PixelFormat fmt) {
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
void HeaderRecovery::recover_setShadowTextureCasterMaterial(const String& name) {
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
				"SceneManager::setShadowTextureCasterMaterial");
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
void HeaderRecovery::recover_setShadowTextureReceiverMaterial(const String& name) {
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
				"SceneManager::setShadowTextureReceiverMaterial");
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
void HeaderRecovery::recover_destroyShadowTextures(void) {
	
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
void HeaderRecovery::recover_destroyMovableObject(const String& name, const String& typeName) {
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
void HeaderRecovery::recover_destroyAllMovableObjectsByType(const String& typeName) {
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
void HeaderRecovery::recover_destroyAllMovableObjects(void) {
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
bool HeaderRecovery::recover_hasMovableObject(const String& name, const String& typeName) const {
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
void HeaderRecovery::recover_extractMovableObject(const String& name, const String& typeName) {
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
