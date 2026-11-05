// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_torsotexturenativea32285e08b660e7c.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/Vector2.h>
G3D::Vector3 mapToUvw(const G3D::Vector3&,int);
struct SurfaceTypes{unsigned value;SurfaceTypes():value(0){}};
struct Mesh:G3D::ReferenceCountedObject{char storage[28];Mesh(int);};
typedef G3D::ReferenceCountedPointer<Mesh> Ref;
struct Base{virtual ~Base();char padding[8];G3D::Array<Ref> mesh;Base();};
struct __declspec(novtable) FaceBase{virtual void unused();char padding[16];Ref reference;G3D::Vector2 textureScale;FaceBase(const Ref&,G3D::Vector3,SurfaceTypes);void build(int,int);};
struct Face:FaceBase{float bevel;float shoulder;Face(const Ref&r,G3D::Vector3 size,SurfaceTypes types,float amount,float height):FaceBase(r,size,types),bevel(amount),shoulder(height){}virtual void unused();};
struct TorsoMesh:Base{TorsoMesh(const G3D::Vector3&,int,const G3D::Vector2&);virtual ~TorsoMesh();};
TorsoMesh::TorsoMesh(const G3D::Vector3& size,int face,const G3D::Vector2& dimensions){
 float height=size.z*0.3f;
 Ref level=new Mesh(5);mesh.push_back(level);
 Face builder(level,size,SurfaceTypes(),0.065f,height);
 builder.textureScale=mapToUvw(size,face).xy()*2.0f/dimensions;
 builder.build(face,1);
}
