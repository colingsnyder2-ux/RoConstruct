// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_torsofaceunsigned00d7a1d390b3bf4d.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/Vector2int16.h>
struct SurfaceTypes{unsigned value;SurfaceTypes():value(0){}};
struct Mesh:G3D::ReferenceCountedObject{char storage[28];Mesh(int);};
typedef G3D::ReferenceCountedPointer<Mesh> Ref;
struct Base{virtual ~Base();char padding[8];G3D::Array<Ref> mesh;Base();};
struct __declspec(novtable) FaceBase{virtual void unused();char padding[16];Ref reference;char tail[8];FaceBase(const Ref&,G3D::Vector3,SurfaceTypes);void build(int);};
struct __declspec(novtable) Bevel:FaceBase {float bevel;Bevel(const Bevel&);};
struct Torso:Bevel {float shoulder;virtual void unused();};
struct Builder {void build(Torso,G3D::Vector2int16,int);void build(Torso,unsigned,unsigned,int);};
void Builder::build(Torso deformer,unsigned x,unsigned y,int purpose){build(deformer,G3D::Vector2int16(x,y),purpose);}
