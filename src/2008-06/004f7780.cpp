// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_wedgesurfacenative4041b68dcf17bdaf.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
struct SurfaceTypes{unsigned value;SurfaceTypes():value(0){}};
struct Mesh:G3D::ReferenceCountedObject{char storage[28];Mesh(int);};
typedef G3D::ReferenceCountedPointer<Mesh> Ref;
struct Base{virtual ~Base();char padding[8];G3D::Array<Ref> mesh;Base();};
struct __declspec(novtable) FaceBase{virtual void unused();char padding[16];Ref reference;char tail[8];FaceBase(const Ref&,G3D::Vector3,SurfaceTypes);void build(int);};
struct Face:FaceBase{float bevel;Face(const Ref&r,G3D::Vector3 size,SurfaceTypes types):FaceBase(r,size,types),bevel(0.0f){}virtual void unused();};
struct WedgeMesh:Base{WedgeMesh(const G3D::Vector3&,SurfaceTypes);virtual ~WedgeMesh();};
WedgeMesh::WedgeMesh(const G3D::Vector3& size,SurfaceTypes types){mesh.push_back(new Mesh(5));Face builder(mesh.last(),size,types);builder.build(0);}
