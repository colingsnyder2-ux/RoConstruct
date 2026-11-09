// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Native Gyro.cpp Rocket::turn, with target-observed Body/SimBody/Rocket offsets.
#include <math.h>
#include <stddef.h>
#include <intrin.h>
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 float&operator[](int i){return ((float*)this)[i];}
 const float&operator[](int i)const{return ((const float*)this)[i];}
 Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3&operator+=(const Vector3&v){float oldX=x;_ReadWriteBarrier();x=oldX+v.x;y+=v.y;z+=v.z;return *this;}
 static const Vector3&zero(){static Vector3 v(0,0,0);return v;}
};
struct Matrix3 {
 float elt[3][3];
 Matrix3(){}Matrix3(const Matrix3&);
 Matrix3 transpose()const;
 Vector3 operator*(const Vector3&v)const{
  Vector3 kProd;
  for(int r=0;r<3;++r){double p0=elt[r][0]*v[0];double p1=elt[r][1]*v[1];double p2=elt[r][2]*v[2];kProd[r]=static_cast<float>((p2+p1)+p0);}
  return kProd;
 }
};
struct CoordinateFrame {
 Matrix3 rotation;Vector3 translation;
 Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}
 Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}
};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct PV {G3D::CoordinateFrame position;Velocity velocity;};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);};
struct Cofm {const G3D::Matrix3&getMoment()const;};
struct Body;
struct SimBody {
 Body*body;float dt;bool dirty;char unused[0x90-9];G3D::Vector3 torque;
 void update();
 void accumulateTorque(const G3D::Vector3&v){if(dirty)update();torque+=v;}
};
struct Body {
 char prefix[0x10];Body*root;
 char unused[0x28-0x14];Cofm*cofm;SimBody*simBody;
 char unused2[0x68-0x30];G3D::Matrix3 moment;float mass;int stateIndex;PV pv;
 void updatePV()const;
 Body*getRoot(){return root;}
 const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return pv.position;}
 const Velocity&getVelocity()const{updatePV();return pv.velocity;}
 const G3D::Vector3&getBranchTorque()const{return root->simBody?root->simBody->torque:G3D::Vector3::zero();}
 G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}
 G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&v){if(root->simBody)root->simBody->accumulateTorque(v);}
};
struct Rocket {
 char unused[0x178];float kTurnP,kTurnD;G3D::Vector3 maxTorque;
 G3D::Vector3 turn(Body*,const G3D::Vector3&);
};
G3D::Vector3 Rocket::turn(Body*body,const G3D::Vector3&targetDir){
 G3D::Vector3 targetObjectSpace=body->getCoordinateFrame().vectorToObjectSpace(targetDir);
 Body*root=body->getRoot();
 G3D::Vector3 oldTorqueWorld=root->getBranchTorque();
 float desiredTorqueX=targetObjectSpace.y*root->getBranchIBodyV3().x*kTurnP;
 float desiredTorqueY=-(targetObjectSpace.x*root->getBranchIBodyV3().y*kTurnP);
 G3D::Vector3 torqueBody=body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);
 if(fabs(desiredTorqueX-torqueBody.x)<root->getBranchIBodyV3().x*maxTorque.x)torqueBody.x=desiredTorqueX;
 else torqueBody.x+=desiredTorqueX;
 if(fabs(desiredTorqueY-torqueBody.y)<root->getBranchIBodyV3().y*maxTorque.y)torqueBody.y=desiredTorqueY;
 else torqueBody.y+=desiredTorqueY;
 G3D::Vector3 angVelBody=body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
 torqueBody.x-=(root->getBranchIBodyV3().x*angVelBody.x)*kTurnD;
 torqueBody.y-=(root->getBranchIBodyV3().y*angVelBody.y)*kTurnD;
 G3D::Vector3 addedTorque=body->getCoordinateFrame().vectorToWorldSpace(torqueBody)-oldTorqueWorld;
 root->accumulateTorque(addedTorque);
 return targetObjectSpace;
}
}
typedef char body_pv_offset[offsetof(RBX::Body,pv)==0x94?1:-1];
typedef char simbody_torque_offset[offsetof(RBX::SimBody,torque)==0x90?1:-1];
typedef char rocket_gain_offset[offsetof(RBX::Rocket,kTurnP)==0x178?1:-1];
