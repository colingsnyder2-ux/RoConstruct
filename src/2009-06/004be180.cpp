// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <typeinfo>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
 long use_count_,weak_count_;
public:
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class shared_count {sp_counted_base*pi_;
public:
 shared_count(const shared_count&r);
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {T*px;detail::shared_count pn;
public:
 shared_ptr(const shared_ptr&r);
};
template<class T> struct type {};
template<int I> struct arg {};
namespace _bi {
template<class T> struct value { T t_; };
template<class A1,class A2> struct list2 { A1 a1_; A2 a2_; list2(A1 x, A2 y):a1_(x),a2_(y){} };
template<class A1,class A2,class A3> struct list3 {
 A1 a1_;
 template<class F, class A> void operator()(type<void>, F& f, A& a, int);
};
template<class R, class F, class L> struct bind_t {
 F f_; L l_;
 template<class A1,class A2> R operator()(A1& a1, A2& a2) { list2<A1&,A2&> a(a1,a2); l_(type<R>(), f_, a, 0); }
};
}
namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[16]; };
template<typename FunctionObj, typename R, typename T0, typename T1>
struct void_function_obj_invoker2 {
 static void invoke(function_buffer& function_obj_ptr, T0 a0, T1 a1)
 {
  FunctionObj* f = reinterpret_cast<FunctionObj*>(&function_obj_ptr.data);
  (*f)(a0, a1);
 }
};
}}
}
namespace RBX { class Instance; class RunStateOwner; }
struct MF { void* p; int adj; };
typedef boost::_bi::bind_t<void, MF, boost::_bi::list3<boost::_bi::value<RBX::RunStateOwner*>, boost::arg<1>, boost::arg<2> > > BindT;
template struct boost::detail::function::void_function_obj_invoker2<BindT, void, std::string, boost::shared_ptr<RBX::Instance> >;
