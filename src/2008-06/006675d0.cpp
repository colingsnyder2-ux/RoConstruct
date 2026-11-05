// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_codex_june_7ce3ac7e38f6702c.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Velocity.h"
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
namespace RBX {
using G3D::Vector3;using G3D::Matrix3;

struct Cofm {const Matrix3& getMoment()const;float getMass()const;};
struct SimBody {char prefix[0x3c];Velocity velocity;char reserved[0x90-0x54];Vector3 torque;};
struct Body {
 char prefix[0x10];Body* root;char reserved14[0x28-0x14];Cofm* cofm;SimBody* simBody;char reserved30[0x68-0x30];Matrix3 moment;float mass;char reserved90[0xc4-0x90];Velocity velocity;
 Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}
 float getBranchMass()const{return cofm?cofm->getMass():mass;}
 void updatePV()const;
 const Velocity& getVelocity()const{updatePV();return velocity;}
 const Velocity& getBranchVelocity()const{return root->simBody?root->simBody->velocity:Velocity::zero();}
 const Vector3& getBranchTorque()const{return root->simBody?root->simBody->torque:Vector3::zero();}
 void accumulateTorque(const Vector3&);
 void accumulateForceAtBranchCofm(const Vector3&);
};
struct Humanoid {Body* getTorsoBody()const;};
Vector3 __cdecl toDiagonal(const Matrix3&);
Vector3 __cdecl lowerAcceleration();Vector3 __cdecl upperAcceleration();
extern float maxYawAcceleration;
float clampValue(float v,float lo,float hi){return v<=lo?lo:(v>=hi?hi:v);}
struct Freefall {char prefix[0xa8];float desiredYaw;char reserved[8];Vector3 desiredVelocity;void baseComputeForce(float);Humanoid* getHumanoid()const;void onComputeForce(float);};
__forceinline Vector3 clampAcceleration(const Vector3& low,const Vector3& high,const Vector3& value){return value.clamp(low,high);}
void Freefall::onComputeForce(float dt){
 baseComputeForce(dt);
 Body* body=getHumanoid()->getTorsoBody();
 if(body){
  float requested;{Vector3 inertia=toDiagonal(body->getBranchIBody());
  requested=(desiredYaw-body->getVelocity().rotational.y)*inertia.y*7500.0f;}
  float torque=requested-body->getBranchTorque().y;
  float limit;{Vector3 limitInertia=toDiagonal(body->getBranchIBody());
  limit=limitInertia.y*120000.0f;}
  torque=clampValue(torque,-limit,limit);
  body->accumulateTorque(Vector3(0,torque,0));
  Vector3 accel=(desiredVelocity-body->getBranchVelocity().linear)*1250.0f;
  Vector3 bounded=clampAcceleration(lowerAcceleration(),upperAcceleration(),accel);
  {Vector3 force=bounded*body->getBranchMass();
  force.y=0;
  body->accumulateForceAtBranchCofm(force);}
 }
}
}
