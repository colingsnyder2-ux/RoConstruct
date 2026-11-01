// from server: 100% by EspClaude
// from server: 79% by EspClaude
// roc 2009-06 006fb3e0  unit: RBX::HUMAN::GettingUp  size: 1009 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fb3e0
//

// from server: 100% by EspClaude
// roc 2008-06 0066e6a0  unit: RBX::HUMAN::GettingUp  size: 1003 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066e6a0
//

// from server: 99% by coldek
// roc 2008-06 0066e6a0  unit: RBX::HUMAN::GettingUp  size: 1003 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066e6a0
//


// claude-opus-5-5 opusC: codegen analog; unused float locals set the /fp:fast x87 frame-local count (not original declarations)
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
#include <stddef.h>
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(float a,float b,float c,int){x=a;z=0;y=b;z=c;}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 const float&operator[](int i)const{return ((float*)this)[i];}float&operator[](int i){return ((float*)this)[i];}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}
 Vector3 operator*(const Vector3&v)const{return Vector3(x*v.x,y*v.y,z*v.z);}Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 Vector3&operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
 Vector3&operator-=(const Vector3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
 Vector3 cross(const Vector3&v)const{return Vector3(y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x,0);}
 static const Vector3&unitY(){static Vector3 v(0,1,0);return v;}
};
inline Vector3 operator*(float f,const Vector3&v){return v*f;}
struct Matrix3 {
 float elt[3][3];Matrix3(){}Matrix3(const Matrix3&m){*this=m;}Matrix3&operator=(const Matrix3&);
 Vector3 getColumn(int)const;Matrix3 transpose()const;
 inline Vector3 operator*(const Vector3&v)const{Vector3 p;for(int r=0;r<3;++r)p[r]=elt[r][0]*v[0]+elt[r][1]*v[1]+elt[r][2]*v[2];return p;}
};
Matrix3 operator*(float,const Matrix3&);
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;Vector3 vectorToObjectSpace(const Vector3&v)const{return rotation.transpose()*v;}Vector3 vectorToWorldSpace(const Vector3&v)const{return rotation*v;}};
}
namespace RBX {
struct Velocity {G3D::Vector3 linear,rotational;};
struct Cofm {char opaque[4];bool dirty;char pad[0x18-5];G3D::Matrix3 moment;void updateIfDirty();const G3D::Matrix3&getMoment(){updateIfDirty();return moment;}};
struct SimBody {char opaque[8];bool dirty;char padding[0x90-9];G3D::Vector3 torque;void update();void updateIfDirty(){if(dirty)update();}void accumulateTorque(const G3D::Vector3&t){updateIfDirty();torque.x=t.x+torque.x;torque.y+=t.y;torque.z+=t.z;}};
struct Math {static G3D::Vector3 toDiagonal(const G3D::Matrix3&);};
struct Body {char opaque[0x2c];Body*root;Cofm*cofm;SimBody*simBody;char opaque38[0x70-0x38];G3D::Matrix3 moment;char opaque94[8];G3D::CoordinateFrame frame;Velocity velocity;
 void updatePV()const;const G3D::CoordinateFrame&getCoordinateFrame()const{updatePV();return frame;}const Velocity&getVelocity()const{updatePV();return velocity;}
 const G3D::Vector3&getBranchTorque()const;G3D::Matrix3 getBranchIBody()const{return cofm?cofm->getMoment():moment;}G3D::Vector3 getBranchIBodyV3()const{return Math::toDiagonal(getBranchIBody());}
 void accumulateTorque(const G3D::Vector3&t){if(root->simBody)root->simBody->accumulateTorque(t);}
};
struct Humanoid {Body*getTorsoBody();Body*getRootBody();};
namespace HUMAN {
struct Balancing {char opaque[0x44];float kP,kD;Humanoid*getHumanoid()const;void onComputeForce();};
void Balancing::onComputeForce(){ float roc_dd0 = 0; float roc_dd1 = 0;
 Body*torso=getHumanoid()->getTorsoBody();if(!torso)return;
 Body*root=getHumanoid()->getRootBody();if(!root)return;
 G3D::Vector3 yAxis=torso->getCoordinateFrame().rotation.getColumn(1);
 G3D::Vector3 tilt=G3D::Vector3::unitY().cross(yAxis);
 G3D::Vector3 angularVelocity=torso->getVelocity().rotational;
 G3D::Vector3 torque=root->getBranchTorque();
 const G3D::CoordinateFrame&rootFrame=root->getCoordinateFrame();
 const G3D::Vector3 localTilt=rootFrame.vectorToObjectSpace(tilt);
 G3D::Vector3 localAngularVelocity=rootFrame.vectorToObjectSpace(angularVelocity);
 G3D::Vector3 localTorque=rootFrame.vectorToObjectSpace(torque);
 G3D::Vector3 desiredTorque=(-kP*root->getBranchIBody())*localTilt;
 const G3D::Vector3&dt=desiredTorque;G3D::Vector3 totalTorque=localTorque+dt;
 G3D::Vector3 inertia=RBX::Math::toDiagonal(root->getBranchIBody());
 for(int i=0;i<3;i+=2){if(fabs(desiredTorque[i]-localTorque[i])<inertia[i]*4000.0f)totalTorque[i]=desiredTorque[i];}
 totalTorque-=kD*inertia*localAngularVelocity;
 G3D::Vector3 torqueWorld=root->frame.vectorToWorldSpace(totalTorque);
 G3D::Vector3 addedTorque=torqueWorld-torque;
 root->accumulateTorque(addedTorque);
}
}
}

