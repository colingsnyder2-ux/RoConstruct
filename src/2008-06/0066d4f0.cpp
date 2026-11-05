// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_draggerinitnative8d489f113fd8feaa.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/CoordinateFrame.h"
#include "util/Velocity.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
struct Primitive {const G3D::CoordinateFrame&getFrame();void setVelocity(const RBX::Velocity&);};
struct Part{char pad[0x228];Primitive primitive;};
struct Workspace;
struct SnapInfo{Primitive*snap;int surface;G3D::Vector3 hitWorld,lastDragSnap;SnapInfo():surface(6),hitWorld(G3D::Vector3::inf()),lastDragSnap(G3D::Vector3::inf()),snap(0){}};
extern void turnUpright(Part*);
struct Dragger{boost::weak_ptr<Part>dragPart,snapPart;Workspace*workspace;Primitive*drag;G3D::Vector3 dragPointLocal;SnapInfo snapInfo;void init(Workspace*,boost::weak_ptr<Part>,const G3D::Vector3&);};
void Dragger::init(Workspace*w,boost::weak_ptr<Part>part,const G3D::Vector3&hit){
 workspace=w;dragPart=part;drag=&part.lock()->primitive;
 dragPointLocal=drag->getFrame().pointToObjectSpace(hit);
 drag->setVelocity(RBX::Velocity::zero());
 snapInfo=SnapInfo();
 turnUpright(dragPart.lock().get());
}
