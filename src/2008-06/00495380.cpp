// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Full00495380 appearance loader. Genuine used Boost1.34.1 declarations;
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
namespace RBX {
// Existing primary pointer views only. No native owner objects/RTTI/size claims.
class Instance{};class ModelInstance:public Instance{};class RunService;class ContentId;
class ContentProvider {public:enum RequestResult;
 typedef std::vector<boost::shared_ptr<Instance> >Instances;
 typedef boost::function<void(RequestResult,boost::shared_ptr<Instances>)>Callback;
 void load(ContentId,Instances&);void load(const ContentId&,Callback);
};
}
typedef RBX::ContentProvider::Instances AppearanceInstances;
namespace RBX {
class Name;
class ContentId {std::string id;const Name*mimeTypePtr;public:ContentId(const std::string&);};
template<class T>boost::shared_ptr<T>shared_from(T*);
RunService*findAppearanceRunService(const Instance*); //004651c0
ContentProvider*findAppearanceContentProvider(const Instance*); //00465210
namespace Network {
class Player:public Instance {public:
 char observed00[0x170];boost::shared_ptr<ModelInstance>character;char observed178[0x1c];std::string characterAppearance;
 void removeCharacterAppearance(); //0048c3e0
 void loadCharacterAppearance(bool);
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

#include <cstddef>

typedef char appearance_string_size[sizeof(std::string)==28?1:-1];
typedef char appearance_shared_size[sizeof(boost::shared_ptr<RBX::Instance>)==8?1:-1];
typedef char appearance_content_size[sizeof(RBX::ContentId)==32?1:-1];
typedef char appearance_predicate_size[sizeof(boost::algorithm::detail::is_any_ofF<char>)==32?1:-1];

typedef char appearance_callback_size[sizeof(RBX::ContentProvider::Callback)==32?1:-1];
typedef char appearance_callback_align[__alignof(RBX::ContentProvider::Callback)==8?1:-1];
typedef char appearance_result_size[sizeof(RBX::ContentProvider::RequestResult)==4?1:-1];
typedef char appearance_character_offset[offsetof(RBX::Network::Player,character)==0x170?1:-1];
typedef char appearance_url_offset[offsetof(RBX::Network::Player,characterAppearance)==0x194?1:-1];

typedef boost::_bi::bind_t<void,void(*)(boost::shared_ptr<RBX::Instance>,boost::shared_ptr<RBX::Instance>),boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::ModelInstance> >,boost::arg<1> > >AppearanceSyncBind;
typedef boost::_bi::bind_t<void,void(*)(boost::shared_ptr<RBX::Instance>,boost::shared_ptr<RBX::RunService>,RBX::ContentProvider::RequestResult,boost::shared_ptr<AppearanceInstances>),boost::_bi::list4<boost::_bi::value<boost::shared_ptr<RBX::ModelInstance> >,boost::_bi::value<boost::shared_ptr<RBX::RunService> >,boost::arg<1>,boost::arg<2> > >AppearanceAsyncBind;

typedef char appearance_buffer_size[sizeof(boost::detail::function::function_buffer)==24?1:-1];
typedef char appearance_buffer_align[__alignof(boost::detail::function::function_buffer)==8?1:-1];
typedef char appearance_tablebase_size[sizeof(boost::detail::function::vtable_base)==4?1:-1];
typedef char appearance_table2_size[sizeof(boost::detail::function::basic_vtable2<void,RBX::ContentProvider::RequestResult,boost::shared_ptr<AppearanceInstances>,std::allocator<void> >)==8?1:-1];
typedef char appearance_functionbase_size[sizeof(boost::function_base)==32?1:-1];
typedef char appearance_syncbind_size[sizeof(AppearanceSyncBind)==12?1:-1];
typedef char appearance_asyncbind_size[sizeof(AppearanceAsyncBind)==20?1:-1];
typedef char appearance_arg_size[sizeof(boost::arg<1>)==1&&sizeof(boost::arg<2>)==1?1:-1];
typedef char appearance_count_size[sizeof(boost::detail::shared_count)==4?1:-1];
typedef char appearance_countbase_size[sizeof(boost::detail::sp_counted_base)==12?1:-1];
