// from server: 100% by EspClaude
// roc 2007-08 005f1700  boost::function1<void, G3D::Vector3>::operator()(Vector3) const (boost 1.33: {manager, functor, invoker})
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdexcept>
namespace G3D { class Vector3 { public: float x, y, z; Vector3(const Vector3& V) : x(V.x), y(V.y), z(V.z) {} }; }
namespace boost {
class bad_function_call : public std::runtime_error {
public:
    bad_function_call();
};
template<class E> __declspec(noreturn) void throw_exception(const E& e);
namespace detail { namespace function {
union any_pointer { void* obj_ptr; const void* const_obj_ptr; void (*func_ptr)(); };
}}
template<typename R, typename T0, typename Allocator = std::allocator<void> >
class function1 {
    void* manager;
    detail::function::any_pointer functor;
    typedef R (*invoker_type)(detail::function::any_pointer, T0);
    invoker_type invoker;
public:
    bool empty() const { return !manager; }
    R operator()(T0 a0) const
    {
        if (this->empty())
            boost::throw_exception(bad_function_call());
        return invoker(this->functor, a0);
    }
};
}
template class boost::function1<void, G3D::Vector3>;
