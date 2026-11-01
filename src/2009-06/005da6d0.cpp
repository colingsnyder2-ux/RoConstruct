// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer&, function_buffer&, functor_manager_operation_type);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
};
template<class R, class T0, class Allocator = std::allocator<void> >
class function1 : public function_base {
public:
    function1() {}
    ~function1() { clear(); }
    void clear() {
        if (vtable) {
            void (*m)(const detail::function::function_buffer&, detail::function::function_buffer&, detail::function::functor_manager_operation_type) = vtable->manager;
            if (m)
                m(functor, functor, detail::function::destroy_functor_tag);
        }
    }
    void swap(function1& other)
    {
        if (&other == this)
            return;
        function1 tmp;
        tmp.move_assign(*this);
        this->move_assign(other);
        other.move_assign(tmp);
    }
    void move_assign(function1& f);
};
template void function1<void, bool>::swap(function1<void, bool>&);
}
