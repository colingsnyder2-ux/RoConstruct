// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_mesh_aggregate_715bbcbbc86bd81c.cpp

// Candidate translation unit (score above; library headers required).
#include <RenderLib/Mesh.h>
#include <RenderLib/Chunk.h>
#include <new>
using namespace G3D;
namespace RBX { namespace Render {
// Native aggregate allocates88h bytes. Only authentic inherited fields used;
// unknown backend tail remains opaque, constructor/destructor remain external.
class AggregateMesh2008:public Mesh {public:
 static void* operator new(size_t){return ::operator new(0x88);}
 AggregateMesh2008();
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
 Vector3 minimum,maximum;
 computeAABounds(chunks,minimum,maximum);
 frame.translation=(minimum+maximum)/2.0f;
 frame.rotation=Matrix3::identity();
 radius=(maximum-minimum).magnitude()/2.0;
 for(int detail=0;detail<1;detail++) {
  float quality=0.3f;
  mesh->levels.append(new AggregateLevel2008(RenderDevice::QUADS));
  ReferenceCountedPointer<Level> output=mesh->levels.last();
  for(std::vector<ReferenceCountedPointer<Chunk> >::const_iterator item=chunks.begin();item!=end;++item) {
   const ReferenceCountedPointer<Chunk>& chunk=*item;
   ReferenceCountedPointer<Mesh> source=chunk->getMesh();
   if(source.isNull())continue;
   const CoordinateFrame& cframe=chunk->cframe();
   ReferenceCountedPointer<Level> input=source->detailLevel(quality);
   Array<unsigned>& indices=input->indexArray;
   CoordinateFrame transform=frame.inverse()*cframe;
   bool share=detail!=0;
   for(int i=0;i<indices.size();i++) {
    unsigned index=indices[i];
    Vector3 vertex=transform.pointToWorldSpace(visibleGeometry.vertexArray[index]);
    Vector3 normal=transform.vectorToWorldSpace(visibleGeometry.normalArray[index]);
    Vector2 uv=texCoordArray[index];
    unsigned added=allocVertex(vertex,normal,uv,share);
    output->indexArray.append(added);
   }
  }
 }
 ShadowSurface& shadow=mesh->shadowSurface;
 shadow.dropShadowGeometry=mesh->levels[0];
 int vertexOffset=0,edgeOffset=0,faceOffset=0;
 for(std::vector<ReferenceCountedPointer<Chunk> >::const_iterator item=chunks.begin();item!=end;++item) {
  const ReferenceCountedPointer<Chunk>& chunk=*item;
  ReferenceCountedPointer<Mesh> source=chunk->getMesh();
  if(source.isNull())continue;
  ShadowSurface& input=source->shadowSurface;
  const CoordinateFrame& cframe=chunk->cframe();
  CoordinateFrame transform=frame.inverse()*cframe;
  for(int i=0;i<input.faceNormalArray.size();i++)
   shadow.faceNormalArray.append(transform.vectorToWorldSpace(input.faceNormalArray[i]));
  for(int i=0;i<input.geometry.size();i++)
   shadow.geometry.append(transform.pointToWorldSpace(input.geometry[i]));
  for(int i=0;i<input.edgeArray.size();i++) {
   const MeshAlg::Edge& edge=input.edgeArray[i];
   MeshAlg::Edge& added=shadow.edgeArray.next();
   for(int j=0;j<2;j++) {
    added.vertexIndex[j]=edge.vertexIndex[j]+vertexOffset;
    added.faceIndex[j]=edge.faceIndex[j]+faceOffset;
   }
  }
  for(int i=0;i<input.faceArray.size();i++) {
   const MeshAlg::Face& face=input.faceArray[i];
   MeshAlg::Face& added=shadow.faceArray.next();
   // Native loop copies exactly two edge slots, including its original behavior.
   for(int j=0;j<2;j++)added.edgeIndex[j]=face.edgeIndex[j]+edgeOffset;
   for(int j=0;j<3;j++)added.vertexIndex[j]=face.vertexIndex[j]+vertexOffset;
  }
  edgeOffset+=input.edgeArray.size();
  vertexOffset+=input.geometry.size();
  faceOffset+=input.faceArray.size();
 }
 mesh->debugBoundingRadius=radius;
 return mesh;
}
}}
