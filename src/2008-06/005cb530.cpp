// from server: 100% by EspClaude
// from server: 78% by coldek
// roc 2008-06 005cb530  unit: RBX::PlayerController  size: 748 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cb530
//

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <intrin.h>
namespace boost {namespace detail {
struct sp_counted_base {
 virtual ~sp_counted_base(){}virtual void dispose()=0;virtual void destroy(){delete this;}
 long use_count_,weak_count_;
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
struct shared_count {sp_counted_base*pi_;shared_count(const shared_count&r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}~shared_count(){if(pi_)pi_->release();}};
}
template<class T>struct shared_ptr {T*px;detail::shared_count pn;T*get()const{return px;}};
template<class T>struct weak_ptr {T*px;void*control;shared_ptr<T>lock()const;};
}
namespace G3D {
struct Vector3 {
 float x,y,z;
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3(const Vector3&r):x(r.x),y(r.y),z(r.z){}
 Vector3 operator*(float s)const{return Vector3(x*s,y*s,z*s);}
 Vector3 operator+(const Vector3&r)const{return Vector3(x+r.x,y+r.y,z+r.z);}
 Vector3& operator+=(const Vector3&r){x+=r.x;y+=r.y;z+=r.z;return *this;}
 float squaredLength()const{return x*x+y*y+z*z;}
 float unitize(float);
 static const Vector3& zero();
};
struct CoordinateFrame {char opaque[48];CoordinateFrame(const CoordinateFrame&);~CoordinateFrame(){}Vector3 lookVector()const;};
struct ReferenceCountedObject {virtual ~ReferenceCountedObject();long count;void*weakPointers;};
}
namespace RBX {
struct Instance {virtual ~Instance();};
struct PVInstance:Instance {};
struct ModelInstance:PVInstance {};
struct Humanoid {
 static Humanoid* fromInstance(Instance*);
 void setWalkDirection(const G3D::Vector3&);
 void setMovementFlag(bool);
 void setSit(bool);void setJump(bool);
};
namespace Network {struct Players {static ModelInstance*findLocalCharacter(const Instance*);};}
struct Camera {
 G3D::CoordinateFrame getCameraCoordinateFrame() const;
 void panRadians(float);
 bool getMovementFlag() const;
};
struct ICameraOwner {virtual ~ICameraOwner();virtual Camera*getCamera()const=0;};
struct WorkspacePrimary {virtual ~WorkspacePrimary();char reserved[0x288-4];};
struct Workspace:WorkspacePrimary,ICameraOwner {static Workspace*findWorkspace(const Instance*);};
struct NavKeys {
 bool forward_arrow,backward_arrow,left_arrow,right_arrow,forward_asdw,backward_asdw,left_asdw,right_asdw,space;
 NavKeys():forward_arrow(false),backward_arrow(false),left_arrow(false),right_arrow(false),forward_asdw(false),backward_asdw(false),left_asdw(false),right_asdw(false),space(false){}
 bool hasASDW() const;
 bool arrowKeyDown()const{return (forward_arrow || backward_arrow || left_arrow || right_arrow);}
 float forwardBackwardASDW()const;float leftRightASDW()const;float leftRightArrow()const;
};
struct UserInputBase {void getNavKeys(NavKeys&)const;bool ctrlKeyDown()const;};
struct Controller:G3D::ReferenceCountedObject {};
struct RunService;struct ControllerService;
struct Heartbeat {const float time,step;};
template<class C,class E>struct Listener {virtual void onEvent(const C*,E)=0;virtual ~Listener(){}};
struct SteppingController:Controller,Listener<RunService,Heartbeat> {boost::shared_ptr<RunService>runService;boost::weak_ptr<const PVInstance>controlledInstance;};
struct PlayerController:SteppingController {
 boost::weak_ptr<ControllerService>controllerService;int stepsRotating;
 const UserInputBase* getHardwareDevice() const;
 virtual void onEvent(const RunService*,Heartbeat);
};
void PlayerController::onEvent(const RunService*,Heartbeat event){
 const UserInputBase*hardware=getHardwareDevice();
 Humanoid*humanoid=0;
 const PVInstance*controlled=controlledInstance.lock().get();
 ModelInstance*character=Network::Players::findLocalCharacter(controlled);
 if(controlled==character)humanoid=Humanoid::fromInstance(character);
 Workspace*workspace=Workspace::findWorkspace(character);
 if(hardware && humanoid && workspace){
  Camera*camera=workspace->getCamera();
  NavKeys keys;hardware->getNavKeys(keys);
  if(keys.arrowKeyDown()){
   if(keys.left_arrow || keys.right_arrow){camera->panRadians(keys.leftRightArrow()*event.step*1.8f);++stepsRotating;}
   else stepsRotating=0;
   float amount=keys.forward_arrow?1.f:(keys.backward_arrow?-1.f:0.f);
   G3D::Vector3 forward=camera->getCameraCoordinateFrame().lookVector();
   forward.y=0.f;forward.unitize(.000001f);
   G3D::Vector3 walk=G3D::Vector3(forward.x,0.f,forward.z)*amount;
   humanoid->setWalkDirection(walk);
  }else if(keys.hasASDW()){
   float forwardAmount=keys.forwardBackwardASDW();
   float leftAmount=keys.leftRightASDW();
   G3D::Vector3 forward=camera->getCameraCoordinateFrame().lookVector();
   forward.y=0.f;forward.unitize(.000001f);
   G3D::Vector3 walk=G3D::Vector3(forward.x,0.f,forward.z)*forwardAmount;
   walk+=G3D::Vector3(forward.z,0.f,-forward.x)*leftAmount;
   if(walk.squaredLength()>1.f)walk.unitize(.000001f);
   humanoid->setWalkDirection(walk);
   if(camera->getMovementFlag())humanoid->setMovementFlag(true);
   else humanoid->setMovementFlag(false);
  }else humanoid->setWalkDirection(G3D::Vector3::zero());
  if(keys.space){humanoid->setSit(false);humanoid->setJump(true);}
  hardware->ctrlKeyDown();
 }
}
}

