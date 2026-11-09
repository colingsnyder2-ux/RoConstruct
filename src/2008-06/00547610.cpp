// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_e96598433e7da2a2.cpp

// Candidate translation unit (score above; library headers required).
#include <RenderLib/Mesh.h>
#include <RenderLib/Chunk.h>
#include <new>
using namespace G3D;
namespace RBX { namespace Render {
// Native aggregate allocates88h bytes. Only authentic inherited fields used;
// unknown backend tail remains opaque, constructor/destructor remain external.
class AggregateMesh2008:public Mesh {public:
 AggregateMesh2008();
 int tail[(0x88-sizeof(Mesh))/4];
};
// Native 004dd2e0's40-byte Level extends the authentic28-byte prefix.
class AggregateLevel2008:public Mesh::Level {
 bool state;unsigned slot,count;
public:AggregateLevel2008(RenderDevice::Primitive);virtual ~AggregateLevel2008();
};
typedef char LevelSizeProof[sizeof(AggregateLevel2008)==40?1:-1];
ReferenceCountedPointer<Mesh> Mesh::aggregate(const std::vector<ReferenceCountedPointer<Chunk> >& chunks,CoordinateFrame& frame,float& radius) {
 ReferenceCountedPointer<Mesh> mesh=new AggregateMesh2008;
 std::vector<ReferenceCountedPointer<Chunk> >::const_iterator end=chunks.end();
 Vector3 v334,maximum;
 computeAABounds(chunks,v334,maximum);
 frame.translation=(maximum+v334)/2.0f;
 frame.rotation=Matrix3::identity();
 radius=(maximum-v334).magnitude()/2.0;
 for(int detail=0;detail<1;detail++) {
  float quality=0.3f;
  mesh->levels.append(new AggregateLevel2008(RenderDevice::QUADS));
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
  const ReferenceCountedPointer<Chunk>& v296=*item;
  const ReferenceCountedPointer<Mesh>& v358=v296->getMesh();
  if(v358.isNull())continue;
  ShadowSurface& v306=v358->shadowSurface;
  const CoordinateFrame& v331=v296->cframe();
  CoordinateFrame v285=frame.inverse()*v331;
  for(int i=0;i<v306.faceNormalArray.size();i++)
   shadow.faceNormalArray.append(v285.vectorToWorldSpace(v306.faceNormalArray[i]));
  for(int i=0;i<v306.geometry.size();i++)
   shadow.geometry.append(v285.pointToWorldSpace(v306.geometry[i]));
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
}}
