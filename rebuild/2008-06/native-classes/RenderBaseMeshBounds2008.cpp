// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Donor Mesh bounds method; target 00547440. Inactive.
#include "RenderLib/AggregateChunk2008.h"
#include "RenderLib/Material2008.h"
namespace RBX { namespace RenderBase {
void Mesh::computeAABounds(
	const std::vector<G3D::ReferenceCountedPointer<Chunk> >& chunkArray, G3D::Vector3& lo, G3D::Vector3& hi
)
{
	lo = G3D::Vector3::inf();
	hi = -G3D::Vector3::inf();

	std::vector<G3D::ReferenceCountedPointer<Chunk> >::const_iterator end = chunkArray.end();

	for (std::vector<G3D::ReferenceCountedPointer<Chunk> >::const_iterator iter = chunkArray.begin(); iter != end;
		 ++iter) {
		const G3D::ReferenceCountedPointer<Chunk>& chunk = *iter;
		const G3D::ReferenceCountedPointer<Mesh>& srcMesh = chunk->getMesh();

		if (srcMesh.isNull()) {
			continue;
		}

		const G3D::CoordinateFrame& cframe = chunk->cframe();
		LevelRef srcLevel = srcMesh->detailLevel(0.0f);
		const G3D::Array<unsigned int>& indexArray = srcLevel->indexArray;

		for (int i = 0; i < indexArray.size(); i++) {
			unsigned int index = indexArray[i];

			G3D::Vector3 v = cframe.pointToWorldSpace(visibleGeometry.vertexArray[index]);

			hi = hi.max(v);
			lo = lo.min(v);
		}
	}
}

using namespace G3D;
ReferenceCountedPointer<Mesh> Mesh::aggregate(const std::vector<ReferenceCountedPointer<Chunk> >& chunks,CoordinateFrame& frame,float& radius) {
 ReferenceCountedPointer<Mesh> mesh=new Mesh;
 std::vector<ReferenceCountedPointer<Chunk> >::const_iterator end=chunks.end();
 Vector3 v334,maximum;
 computeAABounds(chunks,v334,maximum);
 frame.translation=(maximum+v334)/2.0f;
 frame.rotation=Matrix3::identity();
 radius=(maximum-v334).magnitude()/2.0;
 for(int detail=0;detail<1;detail++) {
  float quality=0.3f;
  mesh->levels.append(new Level(RenderDevice::QUADS));
  ReferenceCountedPointer<Level> output=mesh->levels.last();
  for(std::vector<ReferenceCountedPointer<Chunk> >::const_iterator item=chunks.begin();item!=end;++item) {
   const ReferenceCountedPointer<Chunk>& v369=*item;
   const ReferenceCountedPointer<Mesh>& v323=v369->getMesh();
   if(v323.isNull())continue;
   const CoordinateFrame& v368=v369->cframe();
   ReferenceCountedPointer<Level> v335=v323->detailLevel(quality);
   Array<unsigned>& v352=v335->indexArray;
   CoordinateFrame v338=frame.inverse()*v368;
   do{}while(0);
   bool v328=detail!=0;
   for(int i=0;i<v352.size();i++) {
    unsigned v289=v352[i];
    Vector3 v332=v338.pointToWorldSpace(visibleGeometry.vertexArray[v289]);
    Vector3 v362=v338.vectorToWorldSpace(visibleGeometry.normalArray[v289]);
    Vector2 v353=texCoordArray[v289];
    output->indexArray.append(allocVertex(v332,v362,v353,v328));
   }
  }
 }
 {
 ShadowSurface& shadow=mesh->shadowSurface;
 shadow.dropShadowGeometry=mesh->levels[0];
 int vertexOffset=0,edgeOffset=0,faceOffset=0;
 for(std::vector<ReferenceCountedPointer<Chunk> >::const_iterator item=chunks.begin();item!=end;++item) {
  const ReferenceCountedPointer<Chunk>& v369=*item;
  const ReferenceCountedPointer<Mesh>& v323=v369->getMesh();
  if(v323.isNull())continue;
  ShadowSurface& v306=v323->shadowSurface;
  const CoordinateFrame& v368=v369->cframe();
  CoordinateFrame v338=frame.inverse()*v368;
  for(int i=0;i<v306.faceNormalArray.size();i++)
   shadow.faceNormalArray.append(v338.vectorToWorldSpace(v306.faceNormalArray[i]));
  for(int i=0;i<v306.geometry.size();i++)
   shadow.geometry.append(v338.pointToWorldSpace(v306.geometry[i]));
  for(int i=0;i<v306.edgeArray.size();i++) {
   const MeshAlg::Edge& edge=v306.edgeArray[i];
   MeshAlg::Edge& added=shadow.edgeArray.next();
   for(int j=0;j<2;j++) {
    added.vertexIndex[j]=edge.vertexIndex[j]+vertexOffset;
    added.faceIndex[j]=edge.faceIndex[j]+faceOffset;
   }
  }
  for(int i=0;i<v306.faceArray.size();i++) {
   const MeshAlg::Face& face=v306.faceArray[i];
   MeshAlg::Face& added=shadow.faceArray.next();
   // Native loop copies exactly two edge slots, including its original behavior.
   for(int j=0;j<2;j++)added.edgeIndex[j]=face.edgeIndex[j]+edgeOffset;
   for(int j=0;j<3;j++)added.vertexIndex[j]=face.vertexIndex[j]+vertexOffset;
  }
  edgeOffset+=v306.edgeArray.size();
  vertexOffset+=v306.geometry.size();
  faceOffset+=v306.faceArray.size();
 }
 }
 mesh->debugBoundingRadius=radius;
 return mesh;
}
} }
