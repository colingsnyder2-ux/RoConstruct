// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <list>
namespace boost { namespace detail { namespace function {
union function_buffer { void* obj_ptr; char data[16]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    int pad;
    mutable detail::function::function_buffer functor;
};
struct vtable0 { detail::function::vtable_base base; void* invoker;
    void clear(detail::function::function_buffer& functor) const { if (base.manager) base.manager(functor, functor, detail::function::destroy_functor_tag); } };
class function0 : public function_base {
public:
    vtable0* get_vtable() const { return reinterpret_cast<vtable0*>(vtable); }
    ~function0() { clear(); }
    void clear() {
        if (vtable) {
            get_vtable()->clear(functor);
            vtable = 0;
        }
    }
};
}
namespace RBX { class TimerService { public:
    class Item { public: double time; boost::function0 func; };
    std::list<Item> items;
    void f();
}; 
void TimerService::f() { items.clear(); }
}

