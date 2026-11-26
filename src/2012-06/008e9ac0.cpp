// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <new>
#include <typeinfo>
#include <string>
#include <exception>
namespace RBX { class Animation; }
namespace boost {
namespace detail {
class counted_base {
public:
    virtual ~counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void add_ref() { _InterlockedIncrement(&use_count_); }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::counted_base* pn;
    shared_ptr(const shared_ptr& r) : px(r.px), pn(r.pn) {
        if (pn) pn->add_ref();
    }
    ~shared_ptr() {
        if (pn) pn->release();
    }
};
template<int I> struct arg { };
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1, class A2, class A3> class list3 {
public:
    A3 a3_;
};
template<class R, class F, class L> class bind_t {
public:
    F f_;
    L l_;
    bind_t(const bind_t& o) : f_(o.f_), l_(o.l_) {}
};
}
}
typedef boost::_bi::bind_t<void,
    void (*)(std::string*, std::exception*, boost::shared_ptr<RBX::Animation>),
    boost::_bi::list3<boost::arg<1>, boost::arg<2>, boost::_bi::value<boost::shared_ptr<RBX::Animation> > > > Functor;
namespace RBX { namespace Reflection { struct Tuple {}; } }
namespace boost { template<class T0> class function {}; }
namespace boost { namespace _bi { template<class T0,class T1> class list2 {}; } }
union function_buffer {
    void* obj_ptr;
    struct {
        const std::type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
    char data[12];
};
void manage(const function_buffer& in, function_buffer& out, int op)
{
    if (op == 0 || op == 1) {
        const Functor* f = reinterpret_cast<const Functor*>(in.data);
        new (reinterpret_cast<void*>(out.data)) Functor(*f);
        if (op == 1)
            reinterpret_cast<Functor*>(const_cast<char*>(in.data))->~Functor();
    } else if (op == 2) {
        reinterpret_cast<Functor*>(out.data)->~Functor();
    } else if (op == 3) {
        if (*out.type.type == typeid(class boost::_bi::bind_t<class boost::shared_ptr<struct RBX::Reflection::Tuple const >,class boost::shared_ptr<struct RBX::Reflection::Tuple const > (__cdecl*)(class boost::shared_ptr<class boost::function<class boost::shared_ptr<struct RBX::Reflection::Tuple> __cdecl(class boost::shared_ptr<struct RBX::Reflection::Tuple const >)> >,class boost::shared_ptr<struct RBX::Reflection::Tuple const >),class boost::_bi::list2<class boost::_bi::value<class boost::shared_ptr<class boost::function<class boost::shared_ptr<struct RBX::Reflection::Tuple> __cdecl(class boost::shared_ptr<struct RBX::Reflection::Tuple const >)> > >,struct boost::arg<1> > >))
            out.obj_ptr = const_cast<char*>(in.data);
        else
            out.obj_ptr = 0;
    } else {
        out.type.type = &typeid(class boost::_bi::bind_t<class boost::shared_ptr<struct RBX::Reflection::Tuple const >,class boost::shared_ptr<struct RBX::Reflection::Tuple const > (__cdecl*)(class boost::shared_ptr<class boost::function<class boost::shared_ptr<struct RBX::Reflection::Tuple> __cdecl(class boost::shared_ptr<struct RBX::Reflection::Tuple const >)> >,class boost::shared_ptr<struct RBX::Reflection::Tuple const >),class boost::_bi::list2<class boost::_bi::value<class boost::shared_ptr<class boost::function<class boost::shared_ptr<struct RBX::Reflection::Tuple> __cdecl(class boost::shared_ptr<struct RBX::Reflection::Tuple const >)> > >,struct boost::arg<1> > >);
        out.type.const_qualified = false;
        out.type.volatile_qualified = false;
    }
}
