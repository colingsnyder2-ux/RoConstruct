// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Full004957a0 character loader. Genuine used Boost1.34.1 declarations;
// original out-of-line native template boundaries remain declarations.
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <memory>
#include <typeinfo>
#include <cstddef>
#include <intrin.h>
namespace boost {
namespace noncopyable_ {class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);const noncopyable&operator=(const noncopyable&);};}typedef noncopyable_::noncopyable noncopyable;
namespace detail {
// Actual Boost1.34.1 Windows counted base; only unused methods are omitted.
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class shared_count {sp_counted_base*pi_;
public:shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {T*px;detail::shared_count pn;
template<class Y>friend class shared_ptr;
public:shared_ptr():px(0),pn(){}
 template<class Y>shared_ptr(const shared_ptr<Y>&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}T&operator*()const{return *px;}T*operator->()const{return px;}
 typedef T*shared_ptr::*unspecified_bool_type;
 operator unspecified_bool_type()const{return px==0?0:&shared_ptr::px;}
};
}


namespace boost {
template<int I>class arg{};
namespace _bi {
template<class T>class value {T t_;public:value(const T&);};
// Genuine bind optimized storage; only unused APIs and specializations omitted.
template<class A1>struct storage1 {explicit storage1(A1);A1 a1_;};
template<class A1,class A2>struct storage2:public storage1<A1>{storage2(A1,A2);A2 a2_;};
template<class A1,int I>struct storage2<A1,arg<I> >:public storage1<A1>{storage2(A1,arg<I>);};
template<class A1,class A2,class A3>struct storage3:public storage2<A1,A2>{storage3(A1,A2,A3);A3 a3_;};
template<class A1,class A2,int I>struct storage3<A1,A2,arg<I> >:public storage2<A1,A2>{storage3(A1,A2,arg<I>);};
template<class A1,class A2,class A3,class A4>struct storage4:public storage3<A1,A2,A3>{storage4(A1,A2,A3,A4);A4 a4_;};
template<class A1,class A2,class A3,int I>struct storage4<A1,A2,A3,arg<I> >:public storage3<A1,A2,A3>{storage4(A1,A2,A3,arg<I>);};
template<class A1,class A2>class list2:private storage2<A1,A2>{public:list2(A1,A2);};
template<class A1,class A2,class A3,class A4>class list4:private storage4<A1,A2,A3,A4>{public:list4(A1,A2,A3,A4);};
template<class R,class F,class L>class bind_t {F f_;L l_;public:bind_t(F,const L&);};
template<class T>struct add_value{typedef value<T>type;};
template<int I>struct add_value<arg<I> >{typedef arg<I>type;};
template<class A1,class A2>struct list_av_2{typedef list2<typename add_value<A1>::type,typename add_value<A2>::type>type;};
template<class A1,class A2,class A3,class A4>struct list_av_4{typedef list4<typename add_value<A1>::type,typename add_value<A2>::type,typename add_value<A3>::type,typename add_value<A4>::type>type;};
}
template<class R,class B1,class B2,class A1,class A2>
_bi::bind_t<R,R(*)(B1,B2),typename _bi::list_av_2<A1,A2>::type>bind(R(*)(B1,B2),A1,A2);
template<class R,class B1,class B2,class B3,class B4,class A1,class A2,class A3,class A4>
_bi::bind_t<R,R(*)(B1,B2,B3,B4),typename _bi::list_av_4<A1,A2,A3,A4>::type>bind(R(*)(B1,B2,B3,B4),A1,A2,A3,A4);
namespace detail {namespace function {
class X;
union function_buffer {void*obj_ptr;const void*const_obj_ptr;mutable void(*func_ptr)();struct bound_memfunc_ptr_t {void(X::*memfunc_ptr)(int);void*obj_ptr;}bound_memfunc_ptr;mutable char data;};
enum functor_manager_operation_type{clone_functor_tag,destroy_functor_tag,check_functor_type_tag,get_functor_type_tag};
struct vtable_base {vtable_base():manager(0){}void(*manager)(const function_buffer&,function_buffer&,functor_manager_operation_type);};
template<class R,class T0,class T1,class Allocator>struct basic_vtable2:public vtable_base {
 void clear(function_buffer&functor){if(manager)manager(functor,functor,destroy_functor_tag);}
 typedef R(*invoker_type)(function_buffer&,T0,T1);invoker_type invoker;
};
}}
class function_base {public:function_base():vtable(0){}detail::function::vtable_base*vtable;mutable detail::function::function_buffer functor;};
template<class R,class T0,class T1,class Allocator=std::allocator<void> >class function2:public function_base {
 typedef detail::function::basic_vtable2<R,T0,T1,Allocator>vtable_type;
public:function2();function2(const function2&);~function2(){clear();}
 void clear(){if(vtable){static_cast<vtable_type*>(vtable)->clear(this->functor);vtable=0;}}
};
template<class Signature,class Allocator=std::allocator<void> >class function;
template<class R,class T0,class T1,class Allocator>class function<R(T0,T1),Allocator>:public function2<R,T0,T1,Allocator> {
 typedef function2<R,T0,T1,Allocator>base_type;typedef function self_type;
public:template<class Functor>function(Functor,int=0);function(const self_type&);function(const base_type&);
};
namespace algorithm {
template<class Derived>struct predicate_facade{};
enum token_compress_mode_type{token_compress_on,token_compress_off};
namespace detail {
template<class CharT>struct is_any_ofF:public predicate_facade<is_any_ofF<CharT> >{
 template<class Args>struct sig{typedef bool type;};template<class RangeT>is_any_ofF(const RangeT&);
private:std::set<CharT>m_Set;
};
}
// Exact used native char-array instantiation and split boundary signatures.
detail::is_any_ofF<char>is_any_of(const char(&)[2]);
template<class SequenceSequenceT,class RangeT,class PredicateT>SequenceSequenceT&split(SequenceSequenceT&,RangeT&,PredicateT,token_compress_mode_type=token_compress_off);
}using algorithm::is_any_of;using algorithm::split;}
namespace {static boost::arg<1>_1;static boost::arg<2>_2;}
namespace std {template<class InputIterator,class Function>Function for_each(InputIterator,InputIterator,Function);}

namespace boost {template<class T,class U>shared_ptr<T>shared_dynamic_cast(const shared_ptr<U>&);}
namespace RBX {
class Instance {public:virtual ~Instance();virtual void setName(const std::string&);void setParent(Instance*);};
class PVInstance:public Instance{};class ModelInstance:public PVInstance{};class RunService;class ContentId;
class ContentProvider {public:enum RequestResult;
 typedef std::vector<boost::shared_ptr<Instance> >Instances;
 typedef boost::function<void(RequestResult,boost::shared_ptr<Instances>)>Callback;
 void load(ContentId,Instances&);void load(const ContentId&,Callback);
};
}
typedef RBX::ContentProvider::Instances AppearanceInstances;
namespace RBX {
class Name;
class ContentId {std::string id;const Name*mimeTypePtr;public:ContentId(const std::string&);static ContentId fromAssets(const char*);};
template<class T>boost::shared_ptr<T>shared_from(T*);
RunService*findAppearanceRunService(const Instance*); //004651c0
ContentProvider*findAppearanceContentProvider(const Instance*); //00465210
namespace Network {
class Player:public Instance {public:
 char observed04[0x10c];std::string nativeName;char observed12c[0x44];boost::shared_ptr<ModelInstance>character;char observed178[0x1c];std::string characterAppearance;
 void removeCharacterAppearance(); //0048c3e0
 void loadCharacterAppearance(bool);
 void loadCharacter(bool);void setCharacter(ModelInstance*);const std::string&getName()const{return nativeName;}
};
class Players {public:static bool backendProcessing(const Instance*,bool);}; //00495eb0
}
}
// Genuine recovered native helper signatures: bind type matches exact PE RTTI935658.
void setAppearanceParent(boost::shared_ptr<RBX::Instance>,boost::shared_ptr<RBX::Instance>); //0048a690
void onAppearanceLoaded(boost::shared_ptr<RBX::Instance>,boost::shared_ptr<RBX::RunService>,RBX::ContentProvider::RequestResult,boost::shared_ptr<AppearanceInstances>); //00492360
void RBX::Network::Player::loadCharacterAppearance(bool blocking){
 if(!Players::backendProcessing(this,true))throw std::runtime_error("LoadCharacterAppearance can only be called by the backend server");
 removeCharacterAppearance();
 if(character&&!characterAppearance.empty()){
  std::vector<std::string>strings;
  boost::algorithm::split(strings,characterAppearance,boost::algorithm::is_any_of(";"),boost::algorithm::token_compress_off);
  if(blocking){
   std::vector<boost::shared_ptr<RBX::Instance> >instances;
   {std::vector<std::string>strings;
    boost::algorithm::split(strings,characterAppearance,boost::algorithm::is_any_of(";"),boost::algorithm::token_compress_off);
    for(size_t i=0;i<strings.size();++i)findAppearanceContentProvider(this)->load(ContentId(strings[i]),instances);
   }
   std::for_each(instances.begin(),instances.end(),boost::bind(setAppearanceParent,character,_1));
  }else{
   for(size_t i=0;i<strings.size();++i)findAppearanceContentProvider(this)->load(ContentId(strings[i]),boost::bind(onAppearanceLoaded,character,shared_from(findAppearanceRunService(this)),_1,_2));
  }
 }
}
namespace G3D {class Vector3 {public:float x,y,z;Vector3(float x,float y,float z):x(x),y(y),z(z){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}};}
namespace RBX {
class RootInstance:public ModelInstance {public:void moveToPoint(PVInstance*,G3D::Vector3);};
class Workspace:public RootInstance{};
class Humanoid:public Instance {public:static Humanoid*modelIsCharacter(const Instance*);void buildJoints();};
class SpawnerService:public Instance {public:void SpawnPlayer(boost::shared_ptr<ModelInstance>,Network::Player*);};
Workspace*findCharacterWorkspace(const Instance*); //00491e50
SpawnerService*findCharacterSpawner(const Instance*); //00491ea0
namespace Reflection {class DescribedBase;}
// Actual four-method native GetSet interface, independently RTTI-linked to
// the bool BoundProp instance and earlier getter-only/read-write property proof.
namespace Reflection {
// Native RTTI-linked GetSet has two real boolean predicates then get8/setc,
// with no virtual destructor. The second predicate's isWriteOnly label is
// inferred from read/write behavior,not a claim about original source spelling.
template<class T>class TypedPropertyDescriptor {public:class GetSet {public:
virtual bool isReadOnly()const=0;virtual bool isWriteOnly()const=0;
virtual T getValue(const DescribedBase*)const=0;virtual void setValue(DescribedBase*,const T&)const=0;
};};}
typedef Reflection::TypedPropertyDescriptor<bool>::GetSet NativeArchivableSetter;
extern NativeArchivableSetter*characterArchivableSetter; // static descriptor getset field973e8c
}
void addCharacterChild(const boost::shared_ptr<RBX::ModelInstance>&parent,const boost::shared_ptr<RBX::Instance>&child); //0048a670
void RBX::Network::Player::loadCharacter(bool flag){
 Workspace*workspace=findCharacterWorkspace(this);
 if(!workspace)throw std::runtime_error("LoadCharacter can only be called when Player is in the world");
 if(!Players::backendProcessing(this,true))throw std::runtime_error("LoadCharacter can only be called by the backend server");
 std::vector<boost::shared_ptr<Instance> >instances;
 findAppearanceContentProvider(this)->load(ContentId::fromAssets("fonts\\character.rbxm"),instances);
 if(instances.size()!=1)throw std::runtime_error("character.rbxm should contain a Character model");
 boost::shared_ptr<ModelInstance>model=boost::shared_dynamic_cast<ModelInstance>(instances.front());
 if(!model)throw std::runtime_error("character.rbxm should contain a Character model");
 Humanoid*humanoid=Humanoid::modelIsCharacter(model.get());
 if(!humanoid)throw std::runtime_error("character.rbxm should contain a humanoid");
 {std::vector<boost::shared_ptr<Instance> >extra;
  findAppearanceContentProvider(this)->load(ContentId::fromAssets("fonts\\humanoidSound.rbxm"),extra);
  std::for_each(extra.begin(),extra.end(),boost::bind(addCharacterChild,model,_1));
 }
 {std::vector<boost::shared_ptr<Instance> >extra;
  findAppearanceContentProvider(this)->load(ContentId::fromAssets("fonts\\humanoidHealth.rbxm"),extra);
  std::for_each(extra.begin(),extra.end(),boost::bind(addCharacterChild,model,_1));
 }
 {std::vector<boost::shared_ptr<Instance> >extra;
  findAppearanceContentProvider(this)->load(ContentId::fromAssets("fonts\\humanoidAnimate.rbxm"),extra);
  std::for_each(extra.begin(),extra.end(),boost::bind(addCharacterChild,model,_1));
 }
 model->setName(getName());
 if(flag)humanoid->buildJoints();
 characterArchivableSetter->setValue(model?reinterpret_cast<Reflection::DescribedBase*>(reinterpret_cast<char*>(model.get())+0x14):0,false);
 setCharacter(model.get());model->setParent(workspace);
 loadCharacterAppearance(!flag);
 SpawnerService*spawner=findCharacterSpawner(this);
 if(spawner)spawner->SpawnPlayer(model,this);else workspace->moveToPoint(model.get(),G3D::Vector3(0.0f,20.0f,25.0f));
}

typedef boost::shared_ptr<RBX::ModelInstance>CharacterModel;
typedef boost::shared_ptr<RBX::Instance>CharacterInstance;
typedef std::vector<CharacterInstance>CharacterInstances;
typedef boost::_bi::bind_t<void,void(*)(const CharacterModel&,const CharacterInstance&),boost::_bi::list2<boost::_bi::value<CharacterModel>,boost::arg<1> > >CharacterBind;

typedef char character_string_size[sizeof(std::string)==28?1:-1];
typedef char character_model_shared_size[sizeof(CharacterModel)==8?1:-1];
typedef char character_instance_shared_size[sizeof(CharacterInstance)==8?1:-1];
typedef char character_vector_size[sizeof(CharacterInstances)==24?1:-1];
typedef char character_content_size[sizeof(RBX::ContentId)==32?1:-1];
typedef char character_vector3_size[sizeof(G3D::Vector3)==12?1:-1];
typedef char character_getset_size[sizeof(RBX::NativeArchivableSetter)==4?1:-1];
typedef char character_bind_size[sizeof(CharacterBind)==12?1:-1];
typedef char character_count_size[sizeof(boost::detail::shared_count)==4?1:-1];
typedef char character_name_offset[offsetof(RBX::Network::Player,nativeName)==0x110?1:-1];
typedef char character_model_offset[offsetof(RBX::Network::Player,character)==0x170?1:-1];
typedef char character_url_offset[offsetof(RBX::Network::Player,characterAppearance)==0x194?1:-1];
