// from server: 100% by Xemicl
// roc 2012-06 0040c8d0  unit: VAuthoringSettings::?$FactoryProduct  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c8d0
//
// 0040c8d0  56                   push esi
// 0040c8d1  8bf1                 mov esi, ecx
// 0040c8d3  57                   push edi
// 0040c8d4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0040c8d8  c706603eb400         mov dword ptr [esi], 0xb43e60
// 0040c8de  8b4f04               mov ecx, dword ptr [edi + 4]
// 0040c8e1  894e04               mov dword ptr [esi + 4], ecx
// 0040c8e4  85c9                 test ecx, ecx
// 0040c8e6  7407                 je 0x40c8ef
// 0040c8e8  8b01                 mov eax, dword ptr [ecx]
// 0040c8ea  8b500c               mov edx, dword ptr [eax + 0xc]
// 0040c8ed  ffd2                 call edx
// 0040c8ef  8b4708               mov eax, dword ptr [edi + 8]
// 0040c8f2  894608               mov dword ptr [esi + 8], eax
// 0040c8f5  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0040c8f8  894e0c               mov dword ptr [esi + 0xc], ecx
// 0040c8fb  8b5710               mov edx, dword ptr [edi + 0x10]
// 0040c8fe  5f                   pop edi
// 0040c8ff  895610               mov dword ptr [esi + 0x10], edx
// 0040c902  8bc6                 mov eax, esi
// 0040c904  5e                   pop esi
// 0040c905  c20400               ret 4
// copied from an identical function in another client (function ??0exception@boost@@QAE@ABV01@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdexcept>
namespace boost {
class bad_weak_ptr : public std::exception {
public:
    virtual char const* what() const throw();
};
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
void throwBadWeak2009() { throw boost::exception_detail::error_info_injector<boost::bad_weak_ptr>(boost::bad_weak_ptr()); }