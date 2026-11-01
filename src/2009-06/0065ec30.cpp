// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
class bad_function_call : public std::runtime_error {
public:
    bad_function_call();
};
template<class E> __declspec(noreturn) void throw_exception(const E& e);
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[16]; };
} }
template<class R, class T0>
class function1 {
public:
    struct vtable_type {
        void* manager;
        R (*invoker)(detail::function::function_buffer&, T0);
    };
    vtable_type* vtable;
    mutable detail::function::function_buffer functor;
    bool empty() const { return !vtable; }
    R operator()(T0 a0) const;
};
template<class R, class T0>
R function1<R, T0>::operator()(T0 a0) const
{
    if (this->empty())
        boost::throw_exception(bad_function_call());
    return vtable->invoker(this->functor, a0);
}
}
template class boost::function1<void, float>;
