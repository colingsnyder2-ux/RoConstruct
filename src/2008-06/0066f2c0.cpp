// from server: 100% by coldek
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
struct Vec2 {float x,y;Vec2():x(0),y(0){}bool operator!=(const Vec2&v)const{return x!=v.x||y!=v.y;}};
struct Vec3 {float x,y,z;Vec3():x(0),y(0),z(0){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3 operator+(const Vec3&v)const{return Vec3(v.x+x,y+v.y,z+v.z);}Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}float squaredLength()const{return x*x+y*y+z*z;}Vec2 xz()const;bool isZero()const;};
struct Velocity {Vec3 linear,rotational;Velocity(const Vec3&);};
struct Frame {float rotation[9];Vec3 translation;};
struct ControlledBody {void setFrame(const Frame&);void setVelocity(const Velocity&);};
struct DescribedBase {virtual ~DescribedBase();};
struct CharacterPrefix {virtual ~CharacterPrefix();char prefix[0x10];};
struct Character:CharacterPrefix,DescribedBase {char gap[0x1b0-0x18];float turnSpeed;char gap1b4[0x34];unsigned flags;ControlledBody* getBody();float heading();};
struct Unused {};
struct Signal {Unused fire(float);};
struct SignalInstance {char prefix[0x10];Signal signal;};
struct SignalDescriptor {SignalInstance* find(DescribedBase*);};
extern SignalDescriptor runningSignal;
extern float heightOffset,threshold,turnFactor,headingFactor;
float __cdecl getHeading(const Vec3&);
float __cdecl normalizeAngle(float);
void __cdecl rotateY(Frame&,float);
inline float sign(float v){if(v>0.0f)return 1.0f;if(v<0.0f)return -1.0f;return 0.0f;}
struct Moving {char prefix[0xe4];Frame frame;Character* owner();Velocity floorVelocity(float);Vec3 desiredVelocity();double height();bool signalEnabled();void baseStep(float);void update(float,float);};
void Moving::update(float dt,float){
 ControlledBody* body=owner()->getBody();
 if(!body)return;
 Velocity floor=floorVelocity(dt);
 Vec3 desired=desiredVelocity();
 float base=height()-heightOffset;
 Vec3 velocity=floor.linear+desired;
 float difference=base-frame.translation.y;
 if(fabs(difference)>threshold)velocity.y+=sign((float)difference);
 Vec3 step(velocity.x*dt,velocity.y*dt,velocity.z*dt);frame.translation.x+=step.x;frame.translation.y+=step.y;frame.translation.z+=step.z;
 if(owner()->flags&0x10){
  float delta=owner()->turnSpeed*turnFactor*dt;rotateY(frame,delta);
 }else{
  if(desired.xz()!=Vec2()){
   Character* character=owner();
   float desiredHeading=getHeading(velocity);
   float currentHeading=character->heading();
   float delta=normalizeAngle(desiredHeading-currentHeading)*headingFactor*dt;
   rotateY(frame,delta);
  }
 }
 body->setFrame(frame);
 if(!velocity.isZero())body->setVelocity(Velocity(velocity));
 if(signalEnabled()){
  DescribedBase* character=owner();
  float squared=desired.squaredLength();
  SignalInstance* instance=runningSignal.find(character);
  if(instance)instance->signal.fire((float)sqrt(squared));
 }
 baseStep(dt);
}
