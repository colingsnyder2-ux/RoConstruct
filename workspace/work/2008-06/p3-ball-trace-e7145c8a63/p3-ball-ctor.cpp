// Implementation: C:\Users\colin\RoConstruct\tools\rbxgs\Client\App\roc_espeon_spheresurfacenative72a4ae64b6ab9c3d.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\004fcfb0.cpp
#pragma float_control(precise,off)
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
struct SurfaceTypes{unsigned value;SurfaceTypes():value(0){}};
struct Mesh:G3D::ReferenceCountedObject{char storage[28];Mesh(int);};
typedef G3D::ReferenceCountedPointer<Mesh> Ref;
struct Base{virtual ~Base();char padding[8];G3D::Array<Ref> mesh;char remaining[108];Base();};
struct __declspec(novtable) FaceBase{virtual void unused();char padding[16];Ref reference;char tail[8];FaceBase(const Ref&,G3D::Vector3,SurfaceTypes);void build(int);};
struct Face:FaceBase{int elements;Face(const Ref&r,G3D::Vector3 size,SurfaceTypes types):FaceBase(r,size,types),elements(6){}virtual void unused();};
struct SphereMesh:Base{int mode;SphereMesh(const G3D::Vector3&,SurfaceTypes);virtual ~SphereMesh();};
SphereMesh::SphereMesh(const G3D::Vector3& size,SurfaceTypes types):mode(2){mesh.push_back(new Mesh(5));Face builder(mesh.last(),size,types);builder.build(0);}
