// Recovered climb sensing (00644a30/00644c80) and movement (00666410/00666550).
// This adapts the native algorithms to the donor state ABI; parity remains open.
#include "humanoid/Humanoid.h"
#include "humanoid/Balancing.h"
#include "humanoid/Running.h"
#include "humanoid/Freefall.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8kernel/Body.h"
#include "util/Math.h"
#include <G3D/Ray.h>
#include <cmath>
namespace RBX { bool DetectClimb(Humanoid*); }
// 00644a30 / 00644c80: candidate box and vertical obstruction ray sweep.
class ClimbRayFilter : public RBX::HitTestFilter {
    const RBX::Humanoid* humanoid;
public:
    explicit ClimbRayFilter(const RBX::Humanoid* value):humanoid(value){}
    Result filterResult(const RBX::Primitive* primitive) const {
        RBX::Primitive* torso=humanoid->getTorsoPrimitive();
        return primitive->getDragging() || !primitive->getCanCollide() ||
            (torso && torso->getAssembly()==primitive->getAssembly()) ? IGNORE_PRIM : INCLUDE_PRIM;
    }
};
bool RBX::DetectClimb(RBX::Humanoid* humanoid)
{
    RBX::Body* torso=humanoid->getTorsoBody();
    if(!torso || !humanoid->getWorld())return false;
    const G3D::CoordinateFrame& frame=torso->getCoordinateFrame();
    RBX::ContactManager& contact=humanoid->getWorld()->getContactManager();
    G3D::Vector3 center=frame.translation+frame.lookVector();
    G3D::Array<RBX::Primitive*> candidates;
    contact.getPrimitivesTouchingExtents(RBX::Extents(center-G3D::Vector3(1,2.7f,1),center+G3D::Vector3(1,0,1)),NULL,candidates);
    const RBX::Instance* character=humanoid->getParent();
    bool nearby=false;
    for(int i=0;i<candidates.size();++i){
        RBX::PartInstance* part=RBX::PartInstance::fromPrimitive(candidates[i]);
        if(part && !part->isDescendentOf(character)){nearby=true;break;}
    }
    if(!nearby)return false;
    ClimbRayFilter filter(humanoid);float firstHeight=0,span=0;bool first=true,inContact=false;
    for(int i=1;i<18;++i){
        float height=float(i)*.1428571492433548f;
        G3D::Vector3 origin=frame.translation+G3D::Vector3(0,height-2.7f,0),hit;
        float distance=0;
        G3D::Ray ray=G3D::Ray::fromOriginAndDirection(origin,frame.lookVector());
        bool close=contact.getHitLegacy(ray,NULL,&filter,hit,distance,2.0f) && (hit-origin).magnitude()<.7f;
        if(close){if(first){first=false;firstHeight=height;inContact=true;}}
        else if(inContact){inContact=false;span=height-firstHeight;}
    }
    return firstHeight<2.45f && span>0 && span<2.45f;
}

namespace RBX {
Reflection::SignalDesc<Humanoid, void(float)> Humanoid::event_Climbing("Climbing", "speed");
class RecoveredClimbing : public Balancing {
    G3D::Vector3 desiredVelocity;
    float desiredRotation;
public:
    explicit RecoveredClimbing(Humanoid* humanoid):Balancing(humanoid,300.0f,50.0f),desiredVelocity(G3D::Vector3::zero()),desiredRotation(0){}
    virtual const Name& getName() const { return Name::declare("Climbing",-1); }
    virtual bool canSleep() const { return false; }
    virtual State* onStep(float dt,Controller& controller) {
        State* next=Balancing::onStep(dt,controller);
        if(next!=this)return next;
        if(!DetectClimb(humanoid))return floorPart?static_cast<State*>(new Running(humanoid)):static_cast<State*>(new Freefall(humanoid));
        desiredVelocity=humanoid->updateWalkDirection()*16.0f;
        float speed=desiredVelocity.magnitude();
        desiredRotation=speed>0?Math::radWrap(Math::getHeading(desiredVelocity)-humanoid->getTorsoHeading())*8.0f:0;
        desiredVelocity.x*=.7f;desiredVelocity.y=speed*.7f;desiredVelocity.z*=.7f;
        Humanoid::event_Climbing.fire(humanoid,desiredVelocity.magnitude());
        return this;
    }
    virtual void onComputeForce(float dt) {
        Balancing::onComputeForce(dt);
        Body* root=humanoid->getRootBody();
        if(!root || !humanoid->getTorsoBody())return;
        float mass=root->getBranchMass();if(mass<=0)return;
        const Velocity& velocity=root->getVelocity();
        float inertia=root->getBranchIBodyV3().y;
        float torque=((humanoid->getWalkRotationalVelocity()*4.0f+desiredRotation)-velocity.rotational.y)*inertia*7500.0f-root->getBranchTorque().y;
        root->accumulateTorque(G3D::Vector3(0,G3D::clamp(torque,-inertia*160000.0f,inertia*160000.0f),0));
        G3D::Vector3 current=root->getBranchForce()/mass;
        G3D::Vector3 acceleration((desiredVelocity.x-velocity.linear.x)*1250.0f,
            desiredVelocity.y>0?(desiredVelocity.y-velocity.linear.y)*1250.0f:current.y,
            (desiredVelocity.z-velocity.linear.z)*1250.0f);
        acceleration-=current;
        acceleration.x=G3D::clamp(acceleration.x,-1000.0f,1000.0f);
        acceleration.y=G3D::clamp(acceleration.y,0.0f,10000.0f);
        acceleration.z=G3D::clamp(acceleration.z,-1000.0f,1000.0f);
        root->accumulateForceAtBranchCofm(acceleration*mass);
    }
};
// 006451c0 / 00643bc0 / 00643c20: limb flags for climb and running.
void ApplyRecoveredClimbCollision(Humanoid* humanoid,bool climbing,bool running)
{
    PartInstance* left=humanoid->getLeftArm();PartInstance* right=humanoid->getRightArm();
    Primitive* arms[]={left?left->getPrimitive():NULL,right?right->getPrimitive():NULL};
    Primitive* legs[]={humanoid->getLeftLegPrimitive(),humanoid->getRightLegPrimitive()};
    for(int i=0;i<2;++i){
        if(arms[i])arms[i]->setCanCollide(!climbing);
        if(legs[i])legs[i]->setCanCollide(!climbing && !running);
    }
}
Humanoid::State* CreateRecoveredClimbing(Humanoid* humanoid) { return new RecoveredClimbing(humanoid); }
}
