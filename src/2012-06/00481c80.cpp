// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <string>
namespace boost {
namespace detail { class sp_counted_base; }
template<class T> class shared_ptr {
public:
    shared_ptr(shared_ptr const&);
    ~shared_ptr();
private:
    T* px;
    detail::sp_counted_base* pn;
};
namespace system {
class error_category;
class error_code {
    int m_val;
    const error_category* m_cat;
};
class system_error : public std::runtime_error {
public:
    system_error(system_error const&);
    virtual ~system_error() throw();
    virtual const char* what() const throw();
private:
    error_code m_error_code;
    mutable std::string m_what;
};
}
namespace filesystem {
struct path_traits;
template<class String, class Traits> class basic_path;
template<class Path>
class basic_filesystem_error : public system::system_error {
public:
    basic_filesystem_error(basic_filesystem_error const&);
    ~basic_filesystem_error() throw();
private:
    struct m_imp;
    boost::shared_ptr<m_imp> m_imp_ptr;
};
typedef basic_path<std::string, path_traits> path;
}
}
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
void throwFilesystemError(boost::filesystem::basic_filesystem_error<boost::filesystem::path> const& e) { boost::throw_exception(e); }
