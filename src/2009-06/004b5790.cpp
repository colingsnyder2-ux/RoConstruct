// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
 void weak_add_ref(){_InterlockedIncrement(&weak_count_);}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
class weak_count {sp_counted_base*pi_;
public:
 weak_count(const weak_count&r):pi_(r.pi_){if(pi_!=0)pi_->weak_add_ref();}
 ~weak_count(){if(pi_!=0)pi_->weak_release();}
};
}
template<class T>class weak_ptr {T*px;detail::weak_count pn;
public:
 weak_ptr(const weak_ptr&r):px(r.px),pn(r.pn){}
};
}
namespace RBX {
class Instance;
class Base {
public:
	Base(boost::weak_ptr<Instance> a, boost::weak_ptr<Instance> b);
};
class D : public Base {
public:
	D(boost::weak_ptr<Instance> a, boost::weak_ptr<Instance> b, int c);
};
D::D(boost::weak_ptr<Instance> a, boost::weak_ptr<Instance> b, int c) : Base(a, b) {}
}
