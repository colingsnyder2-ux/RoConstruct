// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
#include <string>
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
namespace gregorian {
struct bad_year : public std::out_of_range {
    bad_year() : std::out_of_range(std::string("Year is out of valid range: 1400..10000")) {}
};
}
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
    virtual ~clone_base() throw() {}
};
template<class T>
class clone_impl : public T, public clone_base {
public:
    explicit clone_impl(T const& x) : T(x) {}
    ~clone_impl() throw() {}
private:
    clone_base const* clone() const;
    void rethrow() const { throw *this; }
};
template class clone_impl<error_info_injector<gregorian::bad_year> >;
}
}
