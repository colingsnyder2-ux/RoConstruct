// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor RenderLib methods; original 00548fe0 and 00549030 guard dirty G3D arrays.
#include "ViewNew/RenderBaseMesh.h"
namespace RBX { namespace RenderBase {
extern bool g3dVarDirty; // original 009738a1
void Mesh::sendGeometry(const Level* level, G3D::RenderDevice* rd)
{
    debugAssert(rd); // INFERRED disabled invariant in original release code.
    if (g3dVarDirty) return;
    if (!level) return;
    int size = level->indexArray.size();
    if (size > 0) rd->sendIndices(level->primitive, level->indexArray);
}
void Mesh::endRender(G3D::RenderDevice* rd)
{
    if (g3dVarDirty) return;
    rd->endIndexedPrimitives();
    debugAssert(rd); // INFERRED disabled invariant in original release code.
}
} }
