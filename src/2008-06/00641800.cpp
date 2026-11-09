// from server: 100% by coldek
// claude-opus-5-5 opusC: codegen analog; 7 unused float locals set the /fp:fast x87 frame-local count (not original declarations)
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <vector>
namespace G3D {
struct Vector2 {float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2 operator-(const Vector2&v)const{return Vector2(x-v.x,y-v.y);}float length()const{return sqrtf(x*x+y*y);}Vector2 direction()const;};
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}
 Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}Vector3 operator-(const Vector3&v)const{return Vector3(x-v.x,y-v.y,z-v.z);}Vector3 operator+(const Vector3&v)const{return Vector3(x+v.x,y+v.y,z+v.z);}Vector3 operator*(float f)const{return Vector3(x*f,y*f,z*f);}
 Vector3&operator+=(const Vector3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}Vector3&operator/=(float);float squaredMagnitude()const{return x*x+y*y+z*z;}float magnitude()const{return(float)sqrt(squaredMagnitude());}Vector2 xz()const;
};
struct Matrix3 {float elt[3][3];Matrix3(){}Matrix3(const Matrix3&);Matrix3&operator=(const Matrix3&m){memcpy(elt,m.elt,9*sizeof(float));return *this;}Vector3 getColumn(int)const;};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;CoordinateFrame(const CoordinateFrame&f):rotation(f.rotation),translation(f.translation){}~CoordinateFrame(){}Vector3 pointToObjectSpace(const Vector3&)const;};
}
namespace RBX {
struct Primitive;struct ContactManager;
struct ILocation {virtual const G3D::CoordinateFrame getLocation()const=0;};
struct ICameraSubject:virtual ILocation {
 virtual ~ICameraSubject();virtual void onCameraNear(float);virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>&);virtual float getLerp()const;virtual bool zoom(float,G3D::CoordinateFrame&,G3D::CoordinateFrame&);virtual void stepGoalAndFocus(G3D::CoordinateFrame&,G3D::CoordinateFrame&,bool);
};
struct Vector3ERA {float weight,x,y,z;G3D::Vector3 pushAndGetAverage(G3D::Vector3);G3D::Vector3 getAverage();};
struct floatERA {float weight,avg;float pushAndGetAverage(float);float getAverage();};
struct Math {static G3D::CoordinateFrame getFocusSpace(const G3D::CoordinateFrame&);};
struct ICharacterSubject:ICameraSubject {
 Vector3ERA focusERA,focusOffsetERA;G3D::Vector3 lastOffset;floatERA rotationERA;bool cursorLocked,wasOccluded;float unoccludedDistance;bool hasGoalInFocus;G3D::Vector3 goalInFocus;
 G3D::CoordinateFrame goalFromDistance(const G3D::CoordinateFrame&,const G3D::CoordinateFrame&,float);bool testOcclusion(const G3D::CoordinateFrame&,const G3D::CoordinateFrame&,float&);
 virtual bool zoom(float,G3D::CoordinateFrame&,G3D::CoordinateFrame&);virtual void stepGoalAndFocus(G3D::CoordinateFrame&,G3D::CoordinateFrame&,bool);
 virtual ContactManager*getContactManager()=0;virtual void getIgnorePrims(std::vector<const Primitive*>&);virtual void tellCameraNear(float);virtual G3D::Vector3 getIntendedMovementVector()=0;virtual float getIntendedRotationAboutYAxis()=0;virtual void cameraSetWalkOrientation(float,bool)=0;
};
static __forceinline G3D::Vector3 placeXZ(const G3D::Vector3&focus,const G3D::Vector2&direction,float radius,float dy){return focus-G3D::Vector3(direction.x*radius,dy,direction.y*radius);}
void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame&cameraGoal,G3D::CoordinateFrame&cameraFocus,bool){ float roc_dd0 = 0; float roc_dd1 = 0; float roc_dd2 = 0; float roc_dd3 = 0; float roc_dd4 = 0; float roc_dd5 = 0; float roc_dd6 = 0;
 G3D::Vector3 focusToGoal=cameraFocus.translation-cameraGoal.translation;
 if((cameraGoal.translation-cameraFocus.translation).magnitude()<2.75f){
  G3D::Vector3 oldFocus=cameraFocus.translation;
  cameraFocus=getLocation();
  cameraGoal.translation+=cameraFocus.translation-oldFocus;
 }else{
  cameraFocus=getLocation();
  G3D::Vector3 intended=getIntendedMovementVector()*16.0f;intended/=30.0f;
  G3D::Vector3 filterInput=cameraFocus.translation-focusERA.getAverage()-intended;
  filterInput.y=0;
  G3D::Vector3 offset;
  offset=focusOffsetERA.pushAndGetAverage(filterInput);
  (void)focusERA.pushAndGetAverage(cameraFocus.translation);
  (void)getIntendedRotationAboutYAxis();
  G3D::CoordinateFrame subjectFrame=getLocation();
  {G3D::Vector3 back=subjectFrame.rotation.getColumn(2);
  (void)rotationERA.getAverage();
  (void)rotationERA.pushAndGetAverage((float)-atan2(-back.x,back.z));}
  G3D::CoordinateFrame focusSpace=Math::getFocusSpace(cameraFocus);
  cameraGoal.translation+=offset;
  float radius=focusToGoal.xz().length();
  cameraGoal.translation=placeXZ(cameraFocus.translation,(cameraFocus.translation.xz()-cameraGoal.translation.xz()).direction(),radius,focusToGoal.y);
  goalInFocus=focusSpace.pointToObjectSpace(cameraGoal.translation);hasGoalInFocus=true;
 }
 G3D::CoordinateFrame testGoal=wasOccluded?goalFromDistance(cameraFocus,cameraGoal,unoccludedDistance):cameraGoal;
 {float distance;
 bool occluded=testOcclusion(cameraFocus,testGoal,distance);
 if(occluded){if(!wasOccluded)unoccludedDistance=focusToGoal.magnitude();cameraGoal=goalFromDistance(cameraFocus,cameraGoal,distance);}
 else if(wasOccluded)cameraGoal=testGoal;
 wasOccluded=occluded;tellCameraNear(distance);}
}
}
typedef char vector_size[sizeof(G3D::Vector3)==12?1:-1];
typedef char vector2_size[sizeof(G3D::Vector2)==8?1:-1];
typedef char frame_size[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char focus_era_offset[offsetof(RBX::ICharacterSubject,focusERA)==8?1:-1];
typedef char offset_era_offset[offsetof(RBX::ICharacterSubject,focusOffsetERA)==0x18?1:-1];
typedef char rotation_era_offset[offsetof(RBX::ICharacterSubject,rotationERA)==0x34?1:-1];
typedef char occluded_offset[offsetof(RBX::ICharacterSubject,wasOccluded)==0x3d?1:-1];
typedef char distance_offset[offsetof(RBX::ICharacterSubject,unoccludedDistance)==0x40?1:-1];
typedef char goal_flag_offset[offsetof(RBX::ICharacterSubject,hasGoalInFocus)==0x44?1:-1];
typedef char goal_offset[offsetof(RBX::ICharacterSubject,goalInFocus)==0x48?1:-1];