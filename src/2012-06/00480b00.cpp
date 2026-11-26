// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL

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
namespace exception_detail {
struct error_info_container {
    virtual char const* diagnostic_information(char const*) const = 0;
    virtual void* get(int const&) const = 0;
    virtual void set(void*, int const&) = 0;
    virtual void add_ref() const = 0;
    virtual void release() const = 0;
protected:
    virtual ~error_info_container() throw() {}
};
template <class T> class refcount_ptr {
public:
    refcount_ptr() : px_(0) {}
    ~refcount_ptr() { release(); }
private:
    void release() { if (px_) px_->release(); }
    T* px_;
};
}
class exception {
protected:
    exception() : throw_function_(0), throw_file_(0), throw_line_(-1) {}
    virtual ~exception() throw() = 0;
private:
    exception_detail::refcount_ptr<exception_detail::error_info_container> data_;
    char const* throw_function_;
    char const* throw_file_;
    int throw_line_;
};
inline exception::~exception() throw() {}
namespace exception_detail {
template <class T> struct error_info_injector : public T, public exception {
    error_info_injector(error_info_injector const&);
    ~error_info_injector() throw() {}
};
class clone_base {
public:
    virtual clone_base const* clone() const = 0;
    virtual void rethrow() const = 0;
    virtual ~clone_base() throw() {}
};
template <class T> class clone_impl : public T, public clone_base {
public:
    ~clone_impl() throw() {}
private:
    clone_base const* clone() const { return new clone_impl(*this); }
    void rethrow() const { throw *this; }
};
}
}
template class boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::filesystem::basic_filesystem_error<boost::filesystem::path>> >;
