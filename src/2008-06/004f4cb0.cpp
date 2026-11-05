// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-view roc_espeon_pbbnativehalf295efc548d68d463.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("RenderLib/Mesh.h", "roc_espeon_meshlevel40header731ec96bd7d47417.cpp")
#include "QuadVolume.h"
#include <G3D/AABox.h>
#include <G3D/Vector3int16.h>
namespace RBX {namespace ViewNew {
class Mesh: public Render::Mesh {
public:
 G3D::AABox boxA,boxB; int first,second;
 Mesh();virtual ~Mesh();
};
class PBBBuilder:public View::LevelBuilder{
 G3D::Vector3int16 strips;
public:
 PBBBuilder(G3D::ReferenceCountedPointer<Render::Mesh::Level>&,G3D::Vector3,View::RenderSurfaceTypes);
 virtual void buildTop(Purpose);virtual void buildBottom(Purpose);virtual void buildLeft(Purpose);virtual void buildRight(Purpose);virtual void buildFront(Purpose);virtual void buildBack(Purpose);
};
class PBBMesh:public Mesh {
public:
 PBBMesh(const G3D::Vector3&,View::RenderSurfaceTypes);
 virtual ~PBBMesh();
};
typedef char size_level[sizeof(Render::Mesh::Level)==40?1:-1];
typedef char size_mesh[sizeof(Mesh)==136?1:-1];
typedef char size_builder[sizeof(PBBBuilder)==40?1:-1];
extern bool enabled;
extern const float scale;
void calculate(const G3D::Vector3&,G3D::AABox&,G3D::AABox&);
PBBMesh::PBBMesh(const G3D::Vector3& size,View::RenderSurfaceTypes surfaces){
 {
  G3D::ReferenceCountedPointer<Render::Mesh::Level> level=new Render::Mesh::Level(G3D::RenderDevice::QUADS);
  levels.append(level);
  PBBBuilder builder(level,size,surfaces);
  builder.build(View::LevelBuilder::Surface);
 }
 if(enabled){G3D::Vector3 half=size*0.5f;calculate(half,boxB,boxA);}
}
}}
