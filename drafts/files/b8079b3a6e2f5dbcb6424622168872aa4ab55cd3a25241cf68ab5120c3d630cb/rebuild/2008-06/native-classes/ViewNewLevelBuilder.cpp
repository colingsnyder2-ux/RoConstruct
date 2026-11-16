// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/partsurface-profile
#include "ViewNew/QuadVolume.h"
namespace RBX { namespace ViewNew {
// Native declarations and vtable identity: WindowsClient/include/ViewNew/QuadVolume.h.
// 00500d80
LevelBuilder::LevelBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& value, G3D::Vector3 size, RenderSurfaceTypes types)
 : halfSize(size * 0.5f), surfaceTypes(types), level(value), textureScale(2,2) {}
// 00500d30
void LevelBuilder::build(Purpose purpose) {
 buildTop(purpose); buildBottom(purpose); buildLeft(purpose);
 buildRight(purpose); buildFront(purpose); buildBack(purpose);
}
// 00500fd0
void LevelBuilder::appendQuadFromIndexArray(int a,int b,int c) {
 appendQuadFromVertexIndices(level->indexArray[a],level->indexArray[b],level->indexArray[c]);
}
// 00501000
void LevelBuilder::appendQuadFromIndexArray(int a,int b,int c,int d) {
 appendQuadFromVertexIndices(level->indexArray[a],level->indexArray[b],level->indexArray[c],level->indexArray[d]);
}
} }
