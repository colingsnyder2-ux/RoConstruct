// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_snapinfonative8176958b308ca092.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/CoordinateFrame.h"
#include "G3D/Ray.h"
#include "G3D/Plane.h"
#include "util/Extents.h"
struct Dimensions{unsigned tag;G3D::Vector3 size;};
struct Primitive{char padding[0x9c];Dimensions*dimensions;const G3D::CoordinateFrame&getFrame();};
extern bool intersect(const G3D::Ray&,const G3D::Plane&,G3D::Vector3&);
struct SnapInfo{Primitive*snap;RBX::NormalId surface;G3D::Vector3 hitWorld;void update(const G3D::Ray&);};
void SnapInfo::update(const G3D::Ray&mouseRay){
 G3D::Vector3 half=snap->dimensions->size*0.5f;
 RBX::Extents extents(-half,half);
 const G3D::CoordinateFrame&frame=snap->getFrame();
 G3D::Ray ray=frame.toObjectSpace(mouseRay);
 G3D::Plane plane=extents.getPlane(surface);
 G3D::Vector3 hit;
 if(intersect(ray,plane,hit))hitWorld=frame.pointToWorldSpace(hit);else intersect(ray,plane,hit);
 static G3D::Ray savedRay=ray;
 static G3D::Plane savedPlane=plane;
}
