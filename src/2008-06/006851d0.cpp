// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_try_90e948f69e73921c.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
namespace Ogre {
class RbxSubEntity : public SubEntity { public:
class RbxSubEntityShadowRenderable : public ShadowRenderable
		{
		protected:
			
			// Shared link to position buffer
			HardwareVertexBufferSharedPtr mPositionBuffer;
			// Shared link to w-coord buffer (optional)
			HardwareVertexBufferSharedPtr mWBuffer;
			// Link to current vertex data used to bind (maybe changes)
			const VertexData* mCurrentVertexData;
			// Original position buffer source binding
			unsigned short mOriginalPosBufferBinding;
			/// Link to SubEntity, only present if SubEntity has it's own geometry
			SubEntity* mSubEntity;


		public:
			RbxSubEntityShadowRenderable(Entity* parent,
				HardwareIndexBufferSharedPtr* indexBuffer, const VertexData* vertexData,
				bool createSeparateLightCap, SubEntity* subent, bool isLightCap = false);
			~RbxSubEntityShadowRenderable();
			/// Overridden from ShadowRenderable
			void getWorldTransforms(Matrix4* xform) const;
			/// Overridden from ShadowRenderable
			const Quaternion& getWorldOrientation(void) const;
			/// Overridden from ShadowRenderable
			const Vector3& getWorldPosition(void) const;
			HardwareVertexBufferSharedPtr getPositionBuffer(void) { return mPositionBuffer; }
			HardwareVertexBufferSharedPtr getWBuffer(void) { return mWBuffer; }
			/// Rebind the source positions (for temp buffer users)
			void rebindPositionBuffer(const VertexData* vertexData, bool force);
			/// Overridden from ShadowRenderable
			bool isVisible(void) const;

		};
};
RbxSubEntity::RbxSubEntityShadowRenderable::RbxSubEntityShadowRenderable(Entity* parent,
        HardwareIndexBufferSharedPtr* indexBuffer, const VertexData* vertexData,
        bool createSeparateLightCap, SubEntity* subent, bool isLightCap)
        : mSubEntity(subent)
    {
        // Save link to vertex data
        mCurrentVertexData = vertexData;

        // Initialise render op
        mRenderOp.indexData = new IndexData();
        mRenderOp.indexData->indexBuffer = *indexBuffer;
        mRenderOp.indexData->indexStart = 0;
        // index start and count are sorted out later

        // Create vertex data which just references position component (and 2 component)
        mRenderOp.vertexData = new VertexData();
        // Map in position data
        mRenderOp.vertexData->vertexDeclaration->addElement(0,0,VET_FLOAT3, VES_POSITION);
        mOriginalPosBufferBinding =
            vertexData->vertexDeclaration->findElementBySemantic(VES_POSITION)->getSource();
        mPositionBuffer = vertexData->vertexBufferBinding->getBuffer(mOriginalPosBufferBinding);
        mRenderOp.vertexData->vertexBufferBinding->setBinding(0, mPositionBuffer);
        // Map in w-coord buffer (if present)
        if(!vertexData->hardwareShadowVolWBuffer.isNull())
        {
            mRenderOp.vertexData->vertexDeclaration->addElement(1,0,VET_FLOAT1, VES_TEXTURE_COORDINATES, 0);
            mWBuffer = vertexData->hardwareShadowVolWBuffer;
            mRenderOp.vertexData->vertexBufferBinding->setBinding(1, mWBuffer);
        }
        // Use same vertex start as input
        mRenderOp.vertexData->vertexStart = vertexData->vertexStart;

        if (isLightCap)
        {
            // Use original vertex count, no extrusion
            mRenderOp.vertexData->vertexCount = vertexData->vertexCount;
        }
        else
        {
            // Vertex count must take into account the doubling of the buffer,
            // because second half of the buffer is the extruded copy
            mRenderOp.vertexData->vertexCount =
                vertexData->vertexCount * 2;
            if (createSeparateLightCap)
            {
                // Create child light cap
                mLightCap = new RbxSubEntityShadowRenderable(parent,
                    indexBuffer, vertexData, false, subent, true);
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
    

    void RbxSubEntity::RbxSubEntityShadowRenderable::rebindPositionBuffer(const VertexData* vertexData, bool force)
    {
        if (force || mCurrentVertexData != vertexData)
        {
            mCurrentVertexData = vertexData;
            mPositionBuffer = mCurrentVertexData->vertexBufferBinding->getBuffer(
                mOriginalPosBufferBinding);
            mRenderOp.vertexData->vertexBufferBinding->setBinding(0, mPositionBuffer);
            if (mLightCap)
            {
                static_cast<RbxSubEntityShadowRenderable*>(mLightCap)->rebindPositionBuffer(vertexData, force);
            }
        }
    }
    

    bool RbxSubEntity::RbxSubEntityShadowRenderable::isVisible(void) const
    {
        if (mSubEntity)
        {
            return mSubEntity->isVisible();
        }
        else
        {
            return ShadowRenderable::isVisible();
        }
    }
    
}
