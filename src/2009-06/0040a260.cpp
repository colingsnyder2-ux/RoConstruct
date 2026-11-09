// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
class exception {
protected:
    exception();
    exception(const exception&);
    virtual ~exception();
private:
    void* data_; const char* fn_; const char* file_; int line_;
};
class bad_function_call : public std::runtime_error {
public:
    bad_function_call();
};
namespace exception_detail {
template<class T> struct error_info_injector : public T, public exception {
    explicit error_info_injector(const T& x);
    ~error_info_injector() throw();
};
class clone_base { public: virtual ~clone_base() throw(); };
template<class T> class clone_impl : public T, public clone_base {
public:
    explicit clone_impl(const T& x);
    ~clone_impl() throw();
};
template<class T> error_info_injector<T> enable_error_info(const T& x);
template<class T> clone_impl<T> enable_current_exception(const T& x);
}
__declspec(noreturn) void throw_bfc(const bad_function_call& e)
{
    throw exception_detail::enable_current_exception(exception_detail::enable_error_info(e));
}
}
