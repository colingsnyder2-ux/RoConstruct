// Ogre::RbxSubEntity and RbxSubEntity::RbxSubEntityShadowRenderable method bodies (inactive native recovery, June 2008
// client; the Ogre::RbxSubEntity block 00684fa0..00685a40 of the application range 0067c000..00688000). Declarations:
// native-headers/AppUnit67C_2008/RbxSubEntity2008.h. Built with the Ogre 1.4.5 client headers (/fp:fast);
// tests/record_native_app_unit67c_2008.py verifies them. getWorldBoundingBox 00685490 remains parked for a
// codegen-shape mismatch (see the header); getShadowVolumeRenderableIterator 00685a40 is recovered.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// AppUnit67C_2008SubEntity | 2008-06 | draft (no current byte proof)
// 0/27 mapped addresses byte-exact | 27 unproved | no mapped strings | by colin (+4) (mixed 4)
// <<< native-status | src 6e856eb8 | roc native-status --write
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

	// 00685a40
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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

namespace Ogre {
const AxisAlignedBox& RbxSubEntity::getWorldBoundingBox(bool derive) const {
    static AxisAlignedBox box;
    RbxSubMesh* mesh = static_cast<RbxSubMesh*>(mShadowSubMesh ? mShadowSubMesh : getCurrentSubMesh());
    Vector3 position = mTransform.getTrans();
    Real radius = mesh->radius * 1.7f;
    box.setExtents(position + Vector3(-radius, -radius, -radius), position + Vector3(radius, radius, radius));
    return box;
}
}
