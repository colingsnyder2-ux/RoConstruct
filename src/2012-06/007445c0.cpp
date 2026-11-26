// from server: 100% by Xemicl
// roc 2012-06 007445c0  unit: boost::Vbad_lexical_cast::?$error_info_injector  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007445c0
//
// 007445c0  56                   push esi
// 007445c1  8bf1                 mov esi, ecx
// 007445c3  c74628343cb400       mov dword ptr [esi + 0x28], 0xb43c34
// 007445ca  c70654a9ba00         mov dword ptr [esi], 0xbaa954
// 007445d0  c746144ca9ba00       mov dword ptr [esi + 0x14], 0xbaa94c
// 007445d7  c74614603eb400       mov dword ptr [esi + 0x14], 0xb43e60
// 007445de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007445e1  85c9                 test ecx, ecx
// 007445e3  7407                 je 0x7445ec
// 007445e5  8b01                 mov eax, dword ptr [ecx]
// 007445e7  8b5010               mov edx, dword ptr [eax + 0x10]
// 007445ea  ffd2                 call edx
// 007445ec  c7067ca8ba00         mov dword ptr [esi], 0xbaa87c
// 007445f2  8bce                 mov ecx, esi
// 007445f4  5e                   pop esi
// 007445f5  ff25242ab200         jmp dword ptr [0xb22a24]
// copied from an identical function in another client (function ??1?$clone_impl@U?$error_info_injector@Vbad_lexical_cast@boost@@@exception_detail@boost@@@exception_detail@boost@@UAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _DLL
#include <typeinfo>
namespace boost {
class bad_lexical_cast : public std::bad_cast {
public:
    virtual ~bad_lexical_cast() throw() {}
private:
    const std::type_info* source;
    const std::type_info* target;
};
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
template class boost::exception_detail::clone_impl<boost::exception_detail::error_info_injector<boost::bad_lexical_cast> >;