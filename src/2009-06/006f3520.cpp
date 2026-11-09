// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3(){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3& a):x(a.x),y(a.y),z(a.z){}
 Vector3& operator=(const Vector3& a){x=a.x;y=a.y;z=a.z;return *this;}
 float magnitude()const{return sqrtf(x*x+y*y+z*z);}
 bool isZero()const;
};
}
namespace RBX {
struct Velocity {G3D::Vector3 rotational,linear;};
struct Owner {float heading();};
struct Ground;
namespace Math {float getHeading(const G3D::Vector3&);}
float __cdecl wrapAngle(double);
struct Landed {
 char prefix[0x28];bool turning;char unused[0x4c-0x29];
 G3D::Vector3 rotational;
 float up;
 G3D::Vector3 desired;
 float turn;
 float friction;
 Ground* ground();
 float frictionValue();
 Velocity velocity();
 G3D::Vector3 direction();
 Owner* owner();
 void step(float);
};
void Landed::step(float){
 friction=ground()?frictionValue():0.0f;
 Velocity v=velocity();
 rotational=v.rotational;
 up=v.linear.y;
 desired=direction();
 turn=0;
 if(!desired.isZero()){
  Owner* p=owner();
  turn=wrapAngle(Math::getHeading(desired)-p->heading())*8;
  if(turning){float magnitude=desired.magnitude();desired.x*=0.7f;desired.y=magnitude*0.7f;desired.z*=0.7f;}
 }
}
}
