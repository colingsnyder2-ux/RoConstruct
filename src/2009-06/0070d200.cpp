// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
namespace exception_detail { class error_info_container; }
class exception {
protected:
    exception() throw();
    exception(exception const&) throw();
    virtual ~exception() throw() = 0;
private:
    exception_detail::error_info_container* data_;
    char const* throw_function_;
    char const* throw_file_;
    int throw_line_;
};
namespace exception_detail {
template<class T>
struct error_info_injector : public T, public exception {
    explicit error_info_injector(T const& x);
    error_info_injector(error_info_injector const& x);
    ~error_info_injector() throw();
};
class clone_base {
public:
    virtual clone_base const* clone() const = 0;
    virtual void rethrow() const = 0;
    virtual ~clone_base() throw();
};
template<class T>
class clone_impl : public T, public clone_base {
public:
    explicit clone_impl(T const& x);
    clone_impl(clone_impl const& x);
    ~clone_impl() throw();
private:
    clone_base const* clone() const;
    void rethrow() const;
};
template<class T> error_info_injector<T> enable_error_info(T const& x);
template<class T> clone_impl<T> enable_current_exception(T const& x);
}
using exception_detail::enable_error_info;
using exception_detail::enable_current_exception;
template<class E> __declspec(noreturn) void throw_exception(E const& e)
{
    throw enable_current_exception(enable_error_info(e));
}
}
void throwLengthError(std::length_error const& e) { boost::throw_exception(e); }
namespace boost {
}
