// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
#include <typeinfo>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
namespace detail {
namespace function {
union function_buffer {
    mutable void* obj_ptr;
    struct type_t {
        const std::type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
    mutable char data[16];
};
enum functor_manager_operation_type {
    clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag
};
template<class F> struct functor_manager {
    static void manage(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op)
    {
        if (op == clone_functor_tag || op == move_functor_tag) {
            const F* in_functor = reinterpret_cast<const F*>(&in_buffer.data);
            new ((void*)&out_buffer.data) F(*in_functor);
            if (op == move_functor_tag) {
                reinterpret_cast<F*>(&in_buffer.data)->~F();
            }
        } else if (op == destroy_functor_tag) {
            reinterpret_cast<F*>(&out_buffer.data)->~F();
        } else if (op == check_functor_type_tag) {
            const std::type_info& check_type = *out_buffer.type.type;
            if (check_type == typeid(F))
                out_buffer.obj_ptr = &in_buffer.data;
            else
                out_buffer.obj_ptr = 0;
        } else {
            out_buffer.type.type = &typeid(F);
            out_buffer.type.const_qualified = false;
            out_buffer.type.volatile_qualified = false;
        }
    }
};
}
}
}
namespace G3D { class CoordinateFrame; }
namespace RBX { namespace Reflection { class __multiple_inheritance GenericSlotWrapper; } }
namespace boost {
template<int I> struct arg {};
namespace _mfi { template<class R, class T, class A1> class mf1 { public: typedef R (T::*F)(A1); F f_; }; }
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1, class A2> class list2 { public: A1 a1_; };
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
}
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::Reflection::GenericSlotWrapper, G3D::CoordinateFrame>,
    boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::Reflection::GenericSlotWrapper> >, boost::arg<1> > > SlotFunctor;
template struct boost::detail::function::functor_manager<SlotFunctor>;
