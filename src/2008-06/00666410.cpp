// from server: 100% by king_originala
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
 Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 float magnitude()const{return sqrtf(x*x+y*y+z*z);}
 bool isZero()const;
};
}
namespace RBX {
struct Velocity {G3D::Vector3 rotational,linear;};
struct Owner {float heading();};
struct Controller;
namespace Math {float getHeading(const G3D::Vector3&);}
float __cdecl wrapAngle(float);
struct Landed {
 char prefix[0x20];bool turning;char unused[0xa8-0x21];
 G3D::Vector3 rotational;
 float up;
 G3D::Vector3 desired;
 float turn;
 float friction;
 float frictionValue();
 Velocity velocity(float);
 G3D::Vector3 direction();
 Owner* owner();
 void step(float,Controller&);
};
void Landed::step(float dt,Controller&){
 friction=frictionValue();
 Velocity v=velocity(dt);
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
