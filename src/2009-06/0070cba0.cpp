// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
namespace exception_detail {
template <class T>
class refcount_ptr {
public:
    refcount_ptr() : px_(0) {}
    ~refcount_ptr() { release(); }
    refcount_ptr(refcount_ptr const& x) : px_(x.px_) { add_ref(); }
    refcount_ptr& operator=(refcount_ptr const& x) { adopt(x.px_); return *this; }
private:
    T* px_;
    void add_ref() { if (px_) px_->add_ref(); }
    void release() { if (px_) px_->release(); }
    void adopt(T* px) { release(); px_ = px; add_ref(); }
};
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
}
class exception {
protected:
    exception() : throw_function_(0), throw_file_(0), throw_line_(-1) {}
    virtual ~exception() throw() = 0;
private:
    exception_detail::refcount_ptr<exception_detail::error_info_container> data_;
    mutable char const* throw_function_;
    mutable char const* throw_file_;
    mutable int throw_line_;
};
inline exception::~exception() throw() {}
namespace exception_detail {
template <class T>
struct error_info_injector : public T, public exception {
    explicit error_info_injector(T const& x) : T(x) {}
    ~error_info_injector() throw() {}
};
}
}
void throwLengthError2009(const std::length_error& e) { throw boost::exception_detail::error_info_injector<std::length_error>(e); }
