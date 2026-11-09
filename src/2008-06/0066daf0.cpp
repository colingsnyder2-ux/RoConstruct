// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_draggersafeyreferences57e38a7405d2cb8e.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/CoordinateFrame.h"
#include "G3D/Array.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
struct Primitive{const G3D::CoordinateFrame&getFrame();};
struct Part{char pad[0x228];Primitive primitive;Primitive*getPrimitive(){return &primitive;}void setFrame(const G3D::CoordinateFrame&);};
extern Part*fromPrimitive(Primitive*);
struct ContactManager{bool intersectingOthers(Primitive*,float);};
struct World{char pad[0x84];ContactManager*contacts;ContactManager&getContactManager(){return *contacts;}};
struct Workspace{char pad[0x2e4];World*world;World*getWorld()const{return world;}};
extern G3D::Vector3 safeMove(const G3D::Array<Primitive*>&,const G3D::Vector3&,ContactManager&);
struct Dragger{boost::weak_ptr<Part> dragPart,snapPart;Workspace*workspace;Primitive*drag;void findSafeY();};
void Dragger::findSafeY(){
 if(workspace->getWorld()->getContactManager().intersectingOthers(drag,0.01f)){
 Part*part=fromPrimitive(drag);
 G3D::Array<Primitive*>temp;temp.push_back(part->getPrimitive());
 G3D::Vector3 moved=safeMove(temp,G3D::Vector3::zero(),workspace->getWorld()->getContactManager());
 G3D::CoordinateFrame newC=drag->getFrame();newC.translation+=moved;
 dragPart.lock()->setFrame(newC);
 }
}
