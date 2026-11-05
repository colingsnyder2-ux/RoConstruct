// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_ogre_resume_b2126d94dfadd044.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <OgreEdgeListBuilder.h>
namespace Ogre {
class RbxSubMesh : public SubMesh {
public:
    bool prepared;
    EdgeData* edges;
    AxisAlignedBox bounds;
    ~RbxSubMesh();
    void prepareEdges();
};
RbxSubMesh::~RbxSubMesh() { delete edges; }
void RbxSubMesh::prepareEdges() {
    if (prepared) return;
    vertexData->prepareForShadowVolume();
    prepared = true;
    EdgeListBuilder builder;
    builder.addVertexData(vertexData);
    builder.addIndexData(indexData, 0, operationType);
    edges = builder.build();
}
}
