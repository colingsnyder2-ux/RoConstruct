// from server: 100% by EspClaude
// roc 2007-08 00415db0  std::deque<boost::function0<void> >::pop_front (VS2005 deque, boost 1.33 function {manager, functor, invoker})
// roc-flags: /O2 /GS /EHsc /MD
#include <deque>
namespace boost {
namespace detail { namespace function {
union any_pointer { void* obj_ptr; const void* const_obj_ptr; void (*func_ptr)(); };
enum functor_manager_operation_type { clone_functor_tag, destroy_functor_tag };
} }
class function_base {
public:
    function_base() : manager(0) { functor.obj_ptr = 0; }
    bool empty() const { return !manager; }
    detail::function::any_pointer (*manager)(detail::function::any_pointer, detail::function::functor_manager_operation_type);
    detail::function::any_pointer functor;
};
template<typename R>
class function0 : public function_base {
public:
    typedef R (*invoker_type)(detail::function::any_pointer);
    function0() : function_base(), invoker(0) {}
    function0(const function0& f);
    ~function0() { clear(); }
    void clear()
    {
        if (manager)
            functor = manager(functor, detail::function::destroy_functor_tag);
        manager = 0;
        invoker = 0;
    }
private:
    invoker_type invoker;
};
}
template void std::deque<boost::function0<void> >::pop_front();
