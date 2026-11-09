// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_rbx_subentity_shadow_volume_f6cac9c91aa4e5c1.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>

namespace Ogre {

class RbxSubMesh : public SubMesh {
public:
    bool prepared;
    EdgeData* edges;
    AxisAlignedBox bounds;
    Real radius;

    void prepareEdges();
};

class RbxSubEntity : public SubEntity, public ShadowCaster {
public:
    class RbxSubEntityShadowRenderable : public ShadowRenderable {
    protected:
        HardwareVertexBufferSharedPtr mPositionBuffer;
        HardwareVertexBufferSharedPtr mWBuffer;
        const VertexData* mCurrentVertexData;
        unsigned short mOriginalPosBufferBinding;
        SubEntity* mSubEntity;

    public:
        RbxSubEntityShadowRenderable(
            Entity* parent,
            HardwareIndexBufferSharedPtr* indexBuffer,
            const VertexData* vertexData,
            bool createSeparateLightCap,
            SubEntity* subent,
            bool isLightCap = false);

        void getWorldTransforms(Matrix4* xform) const;
        const Quaternion& getWorldOrientation() const;
        const Vector3& getWorldPosition() const;

        HardwareVertexBufferSharedPtr getPositionBuffer()
        {
            return mPositionBuffer;
        }
    };

    Matrix4 transform;
    SubMesh* lodMeshes[1];
    unsigned int lodIndex;
    unsigned int unknown138;
    bool castShadows;
    SubMesh* shadow;
    std::vector<ShadowRenderable*> shadows;

    SubMesh* getCurrentSubMesh() const;

    ShadowRenderableListIterator getShadowVolumeRenderableIterator(
        ShadowTechnique shadowTechnique,
        const Light* light,
        HardwareIndexBufferSharedPtr* indexBuffer,
        bool extrude,
        Real extrusionDistance,
        unsigned long flags = 0);
};

SubMesh* RbxSubEntity::getCurrentSubMesh() const
{
    SubMesh* sm = 0;
    for (int lod = 0; lod >= 0; --lod)
    {
        if (lodMeshes[lod])
        {
            sm = lodMeshes[lod];
            break;
        }
    }
    if (!sm)
        sm = mSubMesh;
    return sm;
}

ShadowCaster::ShadowRenderableListIterator
RbxSubEntity::getShadowVolumeRenderableIterator(
    ShadowTechnique shadowTechnique,
    const Light* light,
    HardwareIndexBufferSharedPtr* indexBuffer,
    bool extrude,
    Real extrusionDistance,
    unsigned long flags)
{
    RbxSubMesh* mesh = static_cast<RbxSubMesh*>(
        shadow ? shadow : getCurrentSubMesh());
    mesh->prepareEdges();

    Vector4 lightPos = light->getAs4DVector();
    Matrix4 world2Obj = transform.inverseAffine();
    lightPos = world2Obj.transformAffine(lightPos);

    EdgeData* edgeList = mesh->edges;
    if (!edgeList)
    {
        return ShadowRenderableListIterator(shadows.begin(), shadows.end());
    }

    bool init = shadows.empty();

    EdgeData::EdgeGroupList::iterator egi;
    ShadowRenderableList::iterator si, siend;
    RbxSubEntityShadowRenderable* esr = 0;
    if (init)
        shadows.resize(edgeList->edgeGroups.size());

    siend = shadows.end();
    egi = edgeList->edgeGroups.begin();
    for (si = shadows.begin(); si != siend; ++si, ++egi)
    {
        const VertexData* vertexData = egi->vertexData;
        if (init)
        {
            *si = new RbxSubEntityShadowRenderable(
                0, indexBuffer, vertexData, !extrude, this);
        }

        esr = static_cast<RbxSubEntityShadowRenderable*>(*si);
        HardwareVertexBufferSharedPtr positionBuffer =
            esr->getPositionBuffer();

        if (extrude)
        {
            extrudeVertices(
                positionBuffer,
                egi->vertexData->vertexCount,
                lightPos,
                extrusionDistance);
        }

        positionBuffer->suppressHardwareUpdate(false);
    }

    updateEdgeListLightFacing(edgeList, lightPos);
    generateShadowVolume(edgeList, *indexBuffer, light, shadows, flags);

    return ShadowRenderableListIterator(shadows.begin(), shadows.end());
}

}
