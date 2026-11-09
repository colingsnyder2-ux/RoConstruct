// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
namespace exception_detail {
class error_info_container {
public:
    virtual char const* diagnostic_information(char const*) const = 0;
    virtual void get() const = 0;
    virtual void set() = 0;
    virtual void add_ref() const = 0;
    virtual void release() const = 0;
protected:
    virtual ~error_info_container() throw() {}
};
template<class T> class refcount_ptr {
public:
    refcount_ptr() : px_(0) {}
    ~refcount_ptr() { release(); }
private:
    T* px_;
    void release() { if (px_) px_->release(); }
};
}
class exception {
protected:
    exception() throw();
    exception(exception const&) throw();
    virtual ~exception() throw() = 0;
private:
    mutable exception_detail::refcount_ptr<exception_detail::error_info_container> data_;
    char const* throw_function_;
    char const* throw_file_;
    int throw_line_;
};
inline exception::~exception() throw() {}
namespace exception_detail {
template<class T>
struct error_info_injector : public T, public exception {
    explicit error_info_injector(T const& x);
    error_info_injector(error_info_injector const& x);
    ~error_info_injector() throw() {}
};
class clone_base {
public:
    virtual clone_base const* clone() const = 0;
    virtual void rethrow() const = 0;
    virtual ~clone_base() throw() {}
};
template<class T>
class clone_impl : public T, public clone_base {
public:
    explicit clone_impl(T const& x);
    ~clone_impl() throw() {}
private:
    clone_base const* clone() const;
    void rethrow() const;
};
template<class T> void clone_impl<T>::rethrow() const { throw *this; }
template void clone_impl<error_info_injector<std::out_of_range> >::rethrow() const;
}
}
