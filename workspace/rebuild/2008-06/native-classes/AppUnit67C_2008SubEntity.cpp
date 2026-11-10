// Ogre::RbxSubEntity and RbxSubEntity::RbxSubEntityShadowRenderable method bodies (inactive native recovery, June 2008
// client; the Ogre::RbxSubEntity block 00684fa0..00685a40 of the application range 0067c000..00688000). Declarations:
// native-headers/AppUnit67C_2008/RbxSubEntity2008.h. Built with the Ogre 1.4.5 client headers (/fp:fast);
// tests/record_native_app_unit67c_2008.py verifies them. getWorldBoundingBox 00685490 and
// getShadowVolumeRenderableIterator 00685a40 are not built (exe-local SubMesh subclass members, see the header).
#include "AppUnit67C_2008/RbxSubEntity2008.h"
#include "OgreRbxNode/RbxSceneNode2008.h"
#include <OgreEntity.h>
#include <OgreSubMesh.h>
#include <OgreCamera.h>
#include <OgreLight.h>
#include <OgreLogManager.h>
#include <OgreHardwareBufferManager.h>
#include <exception>

namespace Ogre
{
	// 006851d0
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

	// 006853a0
	RbxSubEntity::RbxSubEntityShadowRenderable::~RbxSubEntityShadowRenderable()
	{
		delete mRenderOp.indexData;
		delete mRenderOp.vertexData;
		mRenderOp.indexData = 0;
		mRenderOp.vertexData = 0;
	}

	// 00685450
	void RbxSubEntity::RbxSubEntityShadowRenderable::getWorldTransforms(Matrix4* xform) const
	{
		mSubEntity->getWorldTransforms(xform);
	}

	// 00685460
	const Quaternion& RbxSubEntity::RbxSubEntityShadowRenderable::getWorldOrientation(void) const
	{
		return mSubEntity->getWorldOrientation();
	}

	// 00685470
	const Vector3& RbxSubEntity::RbxSubEntityShadowRenderable::getWorldPosition(void) const
	{
		return mSubEntity->getWorldPosition();
	}

	// 00684fa0
	HardwareVertexBufferSharedPtr RbxSubEntity::RbxSubEntityShadowRenderable::getPositionBuffer(void)
	{
		return mPositionBuffer;
	}

	// 00685480
	bool RbxSubEntity::RbxSubEntityShadowRenderable::isVisible(void) const
	{
		return mSubEntity->isVisible();
	}

	// 00685660
	RbxSubEntity::RbxSubEntity(Entity* parent)
		: SubEntity(parent, 0), mLod(0), mCastShadows(true)
	{
		mShadowSubMesh = 0;
		mLodSubMeshes[0] = 0;
	}

	// 00685850
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

	// 00685910
	RbxSubEntity::~RbxSubEntity()
	{
		for (int i = 0; i < (int)mShadowRenderables.size(); ++i)
		{
			delete mShadowRenderables[i];
		}
		mShadowRenderables.clear();
	}

	// 00684fd0
	void RbxSubEntity::getRenderOperation(RenderOperation& op)
	{
		if (mLod == 0)
			mSubMesh->_getRenderOperation(op, 0);
		else
			mLodSubMeshes[mLod - 1]->_getRenderOperation(op, 0);
	}

	// 00685710
	void RbxSubEntity::getWorldTransforms(Matrix4* xform) const
	{
		*xform = mTransform;
	}

	// 00685730
	const Quaternion& RbxSubEntity::getWorldOrientation(void) const
	{
		LogManager::getSingleton().logMessage("RBX perf warning!");
		static Quaternion orientation = mTransform.extractQuaternion();
		return orientation;
	}

	// 006857e0
	const Vector3& RbxSubEntity::getWorldPosition(void) const
	{
		static Vector3 position = mTransform.getTrans();
		return position;
	}

	// 00685010
	Real RbxSubEntity::getSquaredViewDepth(const Camera* cam) const
	{
		if (mCachedCamera == cam)
			return mCachedCameraDist;
		dynamic_cast<RbxSceneNode*>(mParentEntity->getParentNode());
		Vector3 diff = mTransform.getTrans() - cam->getDerivedPosition();
		return diff.squaredLength();
	}

	// 00685820
	void RbxSubEntity::setCustomValue(Real value)
	{
		mCustomValue = value;
	}

	// 00685830
	Real RbxSubEntity::getCustomValue(void) const
	{
		return mCustomValue;
	}

	// 00685700
	bool RbxSubEntity::getCastShadows(void) const
	{
		return mCastShadows;
	}

	// 00685170
	EdgeData* RbxSubEntity::getEdgeList(void)
	{
		throw std::exception("RBX RbxSubEntity::getEdgeList(): should not be called");
	}

	// 006851a0
	bool RbxSubEntity::hasEdgeList(void)
	{
		throw std::exception("RBX RbxSubEntity::hasEdgeList(): should not be called");
	}

	// 00685100
	const AxisAlignedBox& RbxSubEntity::getLightCapBounds(void) const
	{
		return getWorldBoundingBox();
	}

	// 00685590
	const AxisAlignedBox& RbxSubEntity::getDarkCapBounds(const Light& light, Real dirLightExtrusionDist) const
	{
		static AxisAlignedBox darkCapBounds;
		darkCapBounds = getLightCapBounds();
		extrudeBounds(darkCapBounds, light.getAs4DVector(), dirLightExtrusionDist);
		return darkCapBounds;
	}

	// 00685110
	Real RbxSubEntity::getPointExtrusionDistance(const Light* l) const
	{
		return getExtrusionDistance(mTransform.getTrans(), l);
	}

	// 006850a0
	void RbxSubEntity::setMaterial(const MaterialPtr& material)
	{
		mpMaterial = material;
	}

	// 006850b0
	void RbxSubEntity::setSubMesh(int lod, SubMesh* subMesh)
	{
		if (lod == 0)
			mSubMesh = subMesh;
		else
			mLodSubMeshes[lod - 1] = subMesh;
	}

	// 006850d0
	SubMesh* RbxSubEntity::getSubMesh(int lod)
	{
		if (lod == 0)
			return mSubMesh;
		return mLodSubMeshes[lod - 1];
	}

	// 006850f0
	void RbxSubEntity::setLod(int lod)
	{
		mLod = lod;
	}

	// 00685140
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
}
