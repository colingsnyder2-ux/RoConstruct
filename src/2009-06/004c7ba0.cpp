// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
namespace function {
struct X;
union function_buffer {
    void* obj_ptr;
    struct type_t { const void* type; bool c; bool v; } type;
    void (*func_ptr)();
    struct bound_memfunc_ptr_t { void (X::*memfunc_ptr)(int); void* obj_ptr; } bound_memfunc_ptr;
    char data;
    double align;
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}
}
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f)
    {
        this->vtable = 0;
        this->assign_to_own(f);
    }
    ~function0() { if (this->vtable) this->vtable->clear(this->functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
struct Y { virtual ~Y(); long refcount; };
inline void intrusive_ptr_add_ref(Y* p) { _InterlockedIncrement(&p->refcount); }
inline void intrusive_ptr_release(Y* p);
namespace boost {
template<class T> class intrusive_ptr {
public:
    intrusive_ptr(T* p, bool add_ref = true) : px(p) { if (px != 0 && add_ref) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
    T* px;
};
}
Y* newY(const boost::function0<void>& f);
boost::intrusive_ptr<Y> createY(boost::function0<void> f)
{
    return boost::intrusive_ptr<Y>(newY(f));
}
