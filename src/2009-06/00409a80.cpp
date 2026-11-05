// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <typeinfo>
namespace boost {
class bad_any_cast : public std::bad_cast {
public:
    virtual const char* what() const throw() { return "boost::bad_any_cast: failed conversion using boost::any_cast"; }
};
namespace exception_detail {
struct error_info_container {
    virtual char const* diagnostic_information() const = 0;
    virtual void get() const = 0;
    virtual void set() = 0;
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
    mutable exception_detail::refcount_ptr<exception_detail::error_info_container> data_;
    mutable char const* throw_function_;
    mutable char const* throw_file_;
    mutable int throw_line_;
};
inline exception::~exception() throw() {}
namespace exception_detail {
template <class T> struct error_info_injector : public T, public exception {
    explicit error_info_injector(T const& x) : T(x) {}
    ~error_info_injector() throw();
};
template <class T> error_info_injector<T>::~error_info_injector() throw() {}
template struct error_info_injector<bad_any_cast>;
}
}
