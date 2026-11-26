// from server: 100% by Xemicl
// roc 2012-06 007447b0  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007447b0
//
// 007447b0  56                   push esi
// 007447b1  8bf1                 mov esi, ecx
// 007447b3  c74628343cb400       mov dword ptr [esi + 0x28], 0xb43c34
// 007447ba  c70654a9ba00         mov dword ptr [esi], 0xbaa954
// 007447c0  c746144ca9ba00       mov dword ptr [esi + 0x14], 0xbaa94c
// 007447c7  c74614603eb400       mov dword ptr [esi + 0x14], 0xb43e60
// 007447ce  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007447d1  85c9                 test ecx, ecx
// 007447d3  7407                 je 0x7447dc
// 007447d5  8b01                 mov eax, dword ptr [ecx]
// 007447d7  8b5010               mov edx, dword ptr [eax + 0x10]
// 007447da  ffd2                 call edx
// 007447dc  8bce                 mov ecx, esi
// 007447de  c7067ca8ba00         mov dword ptr [esi], 0xbaa87c
// 007447e4  ff15242ab200         call dword ptr [0xb22a24]
// 007447ea  f644240801           test byte ptr [esp + 8], 1
// 007447ef  7409                 je 0x7447fa
// 007447f1  56                   push esi
// 007447f2  e81dd92300           call 0x982114
// 007447f7  83c404               add esp, 4
// 007447fa  8bc6                 mov eax, esi
// 007447fc  5e                   pop esi
// 007447fd  c20400               ret 4
// copied from an identical function in another client (function ??_G?$clone_impl@U?$error_info_injector@Vbad_lexical_cast@boost@@@exception_detail@boost@@@exception_detail@boost@@UAEPAXI@Z)

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