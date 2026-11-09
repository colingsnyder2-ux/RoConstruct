// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Target RTTI proves Named<HumanoidState> at0 and SimJob at a0; payloads not used here stay opaque.
// SimJob constructor writes through +20, proving its36-byte extent; no guessed vector element type.
// setMotionFlag, holdPart, findControlScope and signal labels are descriptive ABI reconstruction names.
// The observed primitive setter writes flag aa, not the older header canSleep field ab.
#include <string.h>
#include <stddef.h>
#include <intrin.h>
#include <utility>
namespace boost {
namespace detail {
struct sp_counted_base {
    sp_counted_base():use_count_(1),weak_count_(1){}
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
    void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
template<class Y>struct sp_counted_impl_p:sp_counted_base {Y*pointer;explicit sp_counted_impl_p(Y*p):pointer(p){}void dispose(){delete pointer;}};
struct shared_count {
    sp_counted_base* pi_;
    shared_count():pi_(0){}
    
    shared_count& operator=(const shared_count& r){sp_counted_base* tmp=r.pi_;if(tmp!=pi_){if(tmp)_InterlockedIncrement(&tmp->use_count_);if(pi_)pi_->release();pi_=tmp;}return *this;}
    void swap(shared_count& r){sp_counted_base* tmp=r.pi_;r.pi_=pi_;pi_=tmp;}
    shared_count(const shared_count& r):pi_(r.pi_){if(pi_)_InterlockedIncrement(&pi_->use_count_);}
    ~shared_count(){if(pi_)pi_->release();}
};
}
namespace detail {inline void sp_enable_shared_from_this(const shared_count&,...) {}}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    shared_ptr():px(0),pn(){}
    
    shared_ptr& operator=(const shared_ptr& r){px=r.px;pn=r.pn;return *this;}
    void swap(shared_ptr& r){std::swap(px,r.px);pn.swap(r.pn);}
    void reset(){shared_ptr().swap(*this);}
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
    shared_ptr(const shared_ptr& r):px(r.px),pn(r.pn){}
    template<class Y> shared_ptr(const shared_ptr<Y>& r):px(r.px),pn(r.pn){}
    T* get()const{return px;}
    T* operator->()const{return px;}
};
template<class T,class U> bool operator==(const shared_ptr<T>& a,const shared_ptr<U>& b){return a.get()==b.get();}
}


namespace boost {
namespace detail {template<class T>struct empty_base{};}
template<class T,class B=detail::empty_base<T> >struct less_than_comparable1:B{};
template<class T,class B=detail::empty_base<T> >struct equality_comparable1:B{};
namespace signals {
struct basic_connection {void*signal;void*signal_data;void(*signal_disconnect)(void*,void*);};
struct connection:private less_than_comparable1<connection>,private equality_comparable1<connection> {
 shared_ptr<basic_connection>con;bool controlling_connection;
 connection():con(),controlling_connection(false){}connection(const connection&);~connection();connection&operator=(const connection&);void disconnect()const;
 bool connected()const{return con.get()&&con->signal_disconnect;}
};
struct scoped_connection:connection {bool released;scoped_connection():connection(),released(false){}~scoped_connection();scoped_connection&operator=(const connection&);};
}
}

namespace G3D {
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Matrix3 {float elt[3][3];Matrix3&operator=(const Matrix3&m){memcpy(elt,m.elt,sizeof(elt));return *this;}};
struct CoordinateFrame {Matrix3 rotation;Vector3 translation;CoordinateFrame();~CoordinateFrame(){}CoordinateFrame&operator=(const CoordinateFrame&f){rotation=f.rotation;translation=f.translation;return *this;}};
}
namespace RBX {
struct Name;struct Primitive {void setMotionFlag(bool);};
namespace Reflection {struct SignalSource {virtual ~SignalSource();void*signals;};}
struct InstancePrefix {virtual ~InstancePrefix();char opaque[0x14-4];};
struct Instance:InstancePrefix,Reflection::SignalSource {};
struct PartInstance:Instance {char opaque[0x228-sizeof(Instance)];Primitive primitive;const G3D::CoordinateFrame&getCoordinateFrame()const;};
struct SimJob {virtual ~SimJob();char opaque[32];SimJob();};
struct SimJobStage {void insert(SimJob*);};
struct World {SimJobStage&getSimJobStage();};
struct Humanoid:Instance {char opaque[0x21c-sizeof(Instance)];World*world;PartInstance*getTorso();};
struct ServiceProvider {void holdPart(PartInstance*);};
ServiceProvider* __cdecl findControlScope(Humanoid*);
template<class T>boost::shared_ptr<T> __cdecl shared_from(T*);
struct INamed {virtual const Name&getName()const=0;};
struct HitTestFilter {enum Result{STOP_TEST,IGNORE_PRIM,INCLUDE_PRIM};virtual Result filterResult(const Primitive*)const=0;};
namespace HUMAN {
struct HumanoidState:INamed,HitTestFilter {Humanoid*humanoid;char opaque[0xa0-12];HumanoidState(Humanoid*);virtual ~HumanoidState();virtual Result filterResult(const Primitive*)const;};
extern const char*const sMovingNoPhysicsBase;
template<class B,const char*const*N>struct Named:B {Named(Humanoid*h):B(h){}virtual const Name&getName()const;};
struct MovingNoPhysicsBase:Named<HumanoidState,&sMovingNoPhysicsBase>,SimJob {
 boost::shared_ptr<PartInstance>torso;ServiceProvider*scope;boost::signals::scoped_connection torsoConnection;G3D::CoordinateFrame frame;
 MovingNoPhysicsBase(Humanoid*);virtual ~MovingNoPhysicsBase();void onAncestryChanged();
};
struct BoundAncestry {typedef void(MovingNoPhysicsBase::*Method)();Method method;MovingNoPhysicsBase*owner;BoundAncestry(Method m,MovingNoPhysicsBase*p):method(m),owner(p){}};
namespace SlotDetail {
class X;union FunctionBuffer {void*obj_ptr;const void*const_obj_ptr;void(*func_ptr)();struct BoundMember {void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;char data;};
struct Function {void*vtable;FunctionBuffer functor;};struct SlotBase {boost::shared_ptr<void>data;};
}
struct AncestrySlot:SlotDetail::SlotBase {SlotDetail::Function slot_function;AncestrySlot(const BoundAncestry&);~AncestrySlot();};
struct AncestrySignal {boost::signals::connection connect(Reflection::SignalSource*,const AncestrySlot&,int);};extern AncestrySignal ancestrySignal;
struct Unused {};struct FloatSignal {Unused fire(float);};struct FloatSignalInstance {char opaque[0x10];FloatSignal signal;};
struct FloatSignalDescriptor {FloatSignalInstance*find(Reflection::SignalSource*);};extern FloatSignalDescriptor runningSignal;
MovingNoPhysicsBase::MovingNoPhysicsBase(Humanoid*h):Named<HumanoidState,&sMovingNoPhysicsBase>(h),scope(0){
 torso=shared_from(h->getTorso());
 if(torso.get()){
  frame=torso->getCoordinateFrame();torso->primitive.setMotionFlag(true);
  torsoConnection=ancestrySignal.connect(torso.get(),BoundAncestry(&MovingNoPhysicsBase::onAncestryChanged,this),10);
  scope=findControlScope(h);scope->holdPart(torso.get());h->world->getSimJobStage().insert(this);
 }
 FloatSignalInstance*signal=runningSignal.find(h);if(signal)signal->signal.fire(0.0f);
}
}
}
typedef char state_size[sizeof(RBX::HUMAN::HumanoidState)==0xa0?1:-1];
typedef char job_size[sizeof(RBX::SimJob)==36?1:-1];
typedef char torso_offset[offsetof(RBX::HUMAN::MovingNoPhysicsBase,torso)==0xc4?1:-1];
typedef char scope_offset[offsetof(RBX::HUMAN::MovingNoPhysicsBase,scope)==0xcc?1:-1];
typedef char connection_offset[offsetof(RBX::HUMAN::MovingNoPhysicsBase,torsoConnection)==0xd0?1:-1];
typedef char frame_offset[offsetof(RBX::HUMAN::MovingNoPhysicsBase,frame)==0xe4?1:-1];
typedef char scoped_size[sizeof(boost::signals::scoped_connection)==20?1:-1];
typedef char slot_size[sizeof(RBX::HUMAN::AncestrySlot)==40?1:-1];
typedef char bind_size[sizeof(RBX::HUMAN::BoundAncestry)==16?1:-1];
typedef char primitive_offset[offsetof(RBX::PartInstance,primitive)==0x228?1:-1];

