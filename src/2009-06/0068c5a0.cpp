// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <typeinfo>
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
inline void* operator new(unsigned int, void* p) throw() { return p; }
inline void operator delete(void*, void*) throw() {}

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
namespace boost {
namespace detail {
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
template<int I> struct arg {};
namespace _mfi {
template<class R, class T, class A1> class mf1 { public: R (T::*f_)(A1); };
}
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1, class A2> class list2 { public: A1 a1_; };
template<class R, class F, class L> class bind_t { public: F f_; L l_; };
}
}
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX { namespace Reflection {
struct SB1 { virtual void f(); };
struct SB2 { virtual void g(); };
class GenericSlotWrapper : public SB1, public SB2 { public: void call(G3D::Vector3); };
} }
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, RBX::Reflection::GenericSlotWrapper, G3D::Vector3>,
    boost::_bi::list2<boost::_bi::value<boost::shared_ptr<RBX::Reflection::GenericSlotWrapper> >, boost::arg<1> > > Functor;
union function_buffer {
    mutable void* obj_ptr;
    struct type_t { const std::type_info* type; bool const_qualified; bool volatile_qualified; } type;
    mutable void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (RBX::Reflection::SB1::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    mutable char data;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };

void manage(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op)
{
    if (op == clone_functor_tag || op == move_functor_tag) {
        const Functor* in_functor = reinterpret_cast<const Functor*>(&in_buffer.data);
        new ((void*)&out_buffer.data) Functor(*in_functor);
        if (op == move_functor_tag)
            reinterpret_cast<Functor*>(&in_buffer.data)->~Functor();
    } else if (op == destroy_functor_tag) {
        reinterpret_cast<Functor*>(&out_buffer.data)->~Functor();
    } else if (op == check_functor_type_tag) {
        const std::type_info& check_type = *out_buffer.type.type;
        if (check_type == typeid(Functor))
            out_buffer.obj_ptr = &in_buffer.data;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &typeid(Functor);
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
