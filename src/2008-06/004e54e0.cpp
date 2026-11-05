// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-view roc_espeon_nativemeshfactory2364c1e6ea7ebc65.cpp

// Candidate translation unit (score above; library headers required).
#include "QuadVolume.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/AABox.h>
namespace RBX { namespace RenderBase {
class Mesh: public G3D::ReferenceCountedObject {
public:
 char storage[0x50-sizeof(G3D::ReferenceCountedObject)];
 G3D::AABox boxA,boxB;
 int first,second;
 Mesh(); virtual ~Mesh();
}; }
namespace ViewNew {
class BrickMesh: public RenderBase::Mesh {
public:
 BrickMesh(const G3D::Vector3&, View::RenderSurfaceTypes, BrickColor,int,int,int,float);
 void configure(const G3D::Vector3&,View::RenderSurfaceTypes,BrickColor,int,int,int,float);
};
typedef char mesh_size_check[sizeof(BrickMesh)==136?1:-1];
extern bool enabled,building;
extern float meshValue;
extern const float initialValue;
G3D::ReferenceCountedPointer<RenderBase::Mesh> create(const G3D::Vector3& a, View::RenderSurfaceTypes b, BrickColor c,int d,int e,int f,float scale){
 G3D::ReferenceCountedPointer<RenderBase::Mesh> result;
 building=false;
 if(enabled){
  meshValue=initialValue;
  result=new BrickMesh(a,b,c,d,e,f,scale);
  meshValue=0; building=true;
  dynamic_cast<BrickMesh*>(result.pointer())->configure(a,b,c,d,e,f,scale);
  building=false;
 }else{meshValue=0;result=new BrickMesh(a,b,c,d,e,f,scale);}
 return result;
}
}}
