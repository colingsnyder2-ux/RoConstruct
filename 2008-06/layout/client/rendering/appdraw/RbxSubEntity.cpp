// =============================================================================
// RbxSubEntity.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/appdraw/RbxSubEntity.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include "OgreRbxNode/RbxSceneNode2008.h"
#include "OgreRbx/RbxSubMesh2008.h"
#include <OgreEntity.h>
#include <OgreSubMesh.h>
#include <OgreCamera.h>
#include <OgreLight.h>
#include <OgreLogManager.h>
#include <OgreHardwareBufferManager.h>
#include <OgreEdgeListBuilder.h>
#include <exception>

namespace Ogre
{
	RbxSubEntity::RbxSubEntityShadowRenderable::RbxSubEntityShadowRenderable(Entity* parent,
		HardwareIndexBufferSharedPtr* indexBuffer, const VertexData* vertexData, bool createSeparateLightCap,
		RbxSubEntity* subEntity, bool isLightCap)
		: mSubEntity(subEntity)
	{
		mCurrentVertexData = vertexData;

		mRenderOp.indexData = new IndexData();
		mRenderOp.indexData->indexBuffer = *indexBuffer;
		mRenderOp.indexData->indexStart = 0;

		mRenderOp.vertexData = new VertexData();
		mRenderOp.vertexData->vertexDeclaration->addElement(0, 0, VET_FLOAT3, VES_POSITION);
		mOriginalPosBufferBinding =
			vertexData->vertexDeclaration->findElementBySemantic(VES_POSITION)->getSource();
		mPositionBuffer = vertexData->vertexBufferBinding->getBuffer(mOriginalPosBufferBinding);
		mRenderOp.vertexData->vertexBufferBinding->setBinding(0, mPositionBuffer);
		if (!vertexData->hardwareShadowVolWBuffer.isNull())
		{
			mRenderOp.vertexData->vertexDeclaration->addElement(1, 0, VET_FLOAT1, VES_TEXTURE_COORDINATES, 0);
			mWBuffer = vertexData->hardwareShadowVolWBuffer;
			mRenderOp.vertexData->vertexBufferBinding->setBinding(1, mWBuffer);
		}
		mRenderOp.vertexData->vertexStart = vertexData->vertexStart;

		if (isLightCap)
		{
			mRenderOp.vertexData->vertexCount = vertexData->vertexCount;
		}
		else
		{
			mRenderOp.vertexData->vertexCount = vertexData->vertexCount * 2;
			if (createSeparateLightCap)
			{
				mLightCap = new RbxSubEntityShadowRenderable(parent, indexBuffer, vertexData, false, subEntity, true);
			}
		}
	}

	RbxSubEntity::RbxSubEntityShadowRenderable::~RbxSubEntityShadowRenderable()
	{
		delete mRenderOp.indexData;
		delete mRenderOp.vertexData;
		mRenderOp.indexData = 0;
		mRenderOp.vertexData = 0;
	}

	void RbxSubEntity::RbxSubEntityShadowRenderable::getWorldTransforms(Matrix4* xform) const
	{
		mSubEntity->getWorldTransforms(xform);
	}

	const Quaternion& RbxSubEntity::RbxSubEntityShadowRenderable::getWorldOrientation(void) const
	{
		return mSubEntity->getWorldOrientation();
	}

	const Vector3& RbxSubEntity::RbxSubEntityShadowRenderable::getWorldPosition(void) const
	{
		return mSubEntity->getWorldPosition();
	}

	HardwareVertexBufferSharedPtr RbxSubEntity::RbxSubEntityShadowRenderable::getPositionBuffer(void)
	{
		return mPositionBuffer;
	}

	bool RbxSubEntity::RbxSubEntityShadowRenderable::isVisible(void) const
	{
		return mSubEntity->isVisible();
	}

	RbxSubEntity::RbxSubEntity(Entity* parent)
		: SubEntity(parent, 0), mLod(0), mCastShadows(true)
	{
		mShadowSubMesh = 0;
		mLodSubMeshes[0] = 0;
	}

	RbxSubEntity::RbxSubEntity(Entity* parent, SubMesh* subMesh, int lod)
		: SubEntity(parent, 0), mLod(lod), mCastShadows(true)
	{
		mLodSubMeshes[0] = 0;
		if (lod == 0)
			mSubMesh = subMesh;
		else
			mLodSubMeshes[mLod - 1] = subMesh;
		mShadowSubMesh = 0;
	}

	RbxSubEntity::~RbxSubEntity()
	{
		for (int i = 0; i < (int)mShadowRenderables.size(); ++i)
		{
			delete mShadowRenderables[i];
		}
		mShadowRenderables.clear();
	}

	void RbxSubEntity::getRenderOperation(RenderOperation& op)
	{
		if (mLod == 0)
			mSubMesh->_getRenderOperation(op, 0);
		else
			mLodSubMeshes[mLod - 1]->_getRenderOperation(op, 0);
	}

	void RbxSubEntity::getWorldTransforms(Matrix4* xform) const
	{
		*xform = mTransform;
	}

	const Quaternion& RbxSubEntity::getWorldOrientation(void) const
	{
		LogManager::getSingleton().logMessage("RBX perf warning!");
		static Quaternion orientation = mTransform.extractQuaternion();
		return orientation;
	}

	Real RbxSubEntity::getSquaredViewDepth(const Camera* cam) const
	{
		if (mCachedCamera == cam)
			return mCachedCameraDist;
		dynamic_cast<RbxSceneNode*>(mParentEntity->getParentNode());
		Vector3 diff = mTransform.getTrans() - cam->getDerivedPosition();
		return diff.squaredLength();
	}

	void RbxSubEntity::setCustomValue(Real value)
	{
		mCustomValue = value;
	}

	Real RbxSubEntity::getCustomValue(void) const
	{
		return mCustomValue;
	}

	bool RbxSubEntity::getCastShadows(void) const
	{
		return mCastShadows;
	}

	EdgeData* RbxSubEntity::getEdgeList(void)
	{
		throw std::exception("RBX RbxSubEntity::getEdgeList(): should not be called");
	}

	bool RbxSubEntity::hasEdgeList(void)
	{
		throw std::exception("RBX RbxSubEntity::hasEdgeList(): should not be called");
	}

	const AxisAlignedBox& RbxSubEntity::getLightCapBounds(void) const
	{
		return getWorldBoundingBox();
	}

	const AxisAlignedBox& RbxSubEntity::getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const
	{
		static AxisAlignedBox darkCapBounds;
		darkCapBounds = getLightCapBounds();
		extrudeBounds(darkCapBounds, light.getAs4DVector(), dirLightExtrusionDist);
		return darkCapBounds;
	}

	Real RbxSubEntity::getPointExtrusionDistance(const Light* l) const
	{
		return getExtrusionDistance(mTransform.getTrans(), l);
	}

	void RbxSubEntity::setMaterial(const MaterialPtr& material)
	{
		mpMaterial = material;
	}

	void RbxSubEntity::setSubMesh(int lod, SubMesh* subMesh)
	{
		if (lod == 0)
			mSubMesh = subMesh;
		else
			mLodSubMeshes[lod - 1] = subMesh;
	}

	SubMesh* RbxSubEntity::getSubMesh(int lod)
	{
		if (lod == 0)
			return mSubMesh;
		return mLodSubMeshes[lod - 1];
	}

	void RbxSubEntity::setLod(int lod)
	{
		mLod = lod;
	}

	SubMesh* RbxSubEntity::getCoarsestSubMesh(void)
	{
		SubMesh* subMesh = 0;
		for (int i = sizeof(mLodSubMeshes) / sizeof(mLodSubMeshes[0]) - 1; i >= 0; --i)
		{
			if (mLodSubMeshes[i])
			{
				subMesh = mLodSubMeshes[i];
				break;
			}
		}
		return subMesh ? subMesh : mSubMesh;
	}

	ShadowCaster::ShadowRenderableListIterator RbxSubEntity::getShadowVolumeRenderableIterator(
		ShadowTechnique shadowTechnique, const Light* light, HardwareIndexBufferSharedPtr* indexBuffer,
		bool extrude, Real extrusionDistance, unsigned long flags)
	{
		RbxSubMesh* mesh = static_cast<RbxSubMesh*>(mShadowSubMesh ? mShadowSubMesh : getCurrentSubMesh());
		mesh->prepareEdges();

		Vector4 lightPos = light->getAs4DVector();
		Matrix4 world2Obj = mTransform.inverseAffine();
		lightPos = world2Obj.transformAffine(lightPos);

		EdgeData* edgeList = mesh->edgeData;
		if (!edgeList)
			return ShadowRenderableListIterator(mShadowRenderables.begin(), mShadowRenderables.end());

		bool init = mShadowRenderables.empty();
		EdgeData::EdgeGroupList::iterator egi;
		ShadowRenderableList::iterator si, siend;
		RbxSubEntityShadowRenderable* esr = 0;
		if (init)
			mShadowRenderables.resize(edgeList->edgeGroups.size());

		siend = mShadowRenderables.end();
		egi = edgeList->edgeGroups.begin();
		for (si = mShadowRenderables.begin(); si != siend; ++si, ++egi)
		{
			const VertexData* vertexData = egi->vertexData;
			if (init)
				*si = new RbxSubEntityShadowRenderable(0, indexBuffer, vertexData, !extrude, this);

			esr = static_cast<RbxSubEntityShadowRenderable*>(*si);
			HardwareVertexBufferSharedPtr positionBuffer = esr->getPositionBuffer();
			if (extrude)
			{
				ShadowCaster::extrudeVertices(positionBuffer, egi->vertexData->vertexCount, lightPos, extrusionDistance);
			}
			positionBuffer->suppressHardwareUpdate(false);
		}

		updateEdgeListLightFacing(edgeList, lightPos);
		generateShadowVolume(edgeList, *indexBuffer, light, mShadowRenderables, flags);
		return ShadowRenderableListIterator(mShadowRenderables.begin(), mShadowRenderables.end());
	}

	SubMesh* RbxSubEntity::getCurrentSubMesh(void) const
	{
		SubMesh* subMesh = 0;
		for (int lod = 0; lod >= 0; --lod)
		{
			if (mLodSubMeshes[lod])
			{
				subMesh = mLodSubMeshes[lod];
				break;
			}
		}
		if (!subMesh)
			subMesh = mSubMesh;
		return subMesh;
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Container_base_aux_alloc_real<std::allocator<Ogre::ShadowRenderable *> >;
template class std::vector<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >;
template class Ogre::VectorIterator<std::vector<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> > >;
template class std::_Revranit<std::_Vector_const_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >,std::iterator<std::random_access_iterator_tag,Ogre::ShadowRenderable *,int,Ogre::ShadowRenderable * const *,Ogre::ShadowRenderable * const &> >;
template class std::_Revranit<std::_Vector_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >,std::iterator<std::random_access_iterator_tag,Ogre::ShadowRenderable *,int,Ogre::ShadowRenderable * *,Ogre::ShadowRenderable * &> >;
template class std::_Vector_const_iterator<Ogre::EdgeData::EdgeGroup,std::allocator<Ogre::EdgeData::EdgeGroup> >;
template class std::_Vector_const_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >;
template class std::_Vector_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> >;
template class std::reverse_iterator<std::_Vector_const_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> > >;
template class std::reverse_iterator<std::_Vector_iterator<Ogre::ShadowRenderable *,std::allocator<Ogre::ShadowRenderable *> > >;
template class std::vector<Ogre::EdgeData::EdgeGroup,std::allocator<Ogre::EdgeData::EdgeGroup> >;

namespace Ogre
{
const AxisAlignedBox& RbxSubEntity::getWorldBoundingBox(bool derive) const {
	static AxisAlignedBox box;
	RbxSubMesh* mesh = static_cast<RbxSubMesh*>(mShadowSubMesh ? mShadowSubMesh : getCurrentSubMesh());
	Vector3 position = mTransform.getTrans();
	Real radius = mesh->radius * 1.7f;
	box.setExtents(position + Vector3(-radius, -radius, -radius), position + Vector3(radius, radius, radius));
	return box;
}
}
