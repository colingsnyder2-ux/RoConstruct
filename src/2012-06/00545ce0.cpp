// from server: 100% by Xemicl
// roc 2012-06 00545ce0  unit: rbx::signals::Z::$$A6AX_NH::?$signal::Vslot::?$callable  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00545ce0
//
// 00545ce0  6aff                 push -1
// 00545ce2  68d9e0ac00           push 0xace0d9
// 00545ce7  64a100000000         mov eax, dword ptr fs:[0]
// 00545ced  50                   push eax
// 00545cee  64892500000000       mov dword ptr fs:[0], esp
// 00545cf5  83ec08               sub esp, 8
// 00545cf8  56                   push esi
// 00545cf9  8bf1                 mov esi, ecx
// 00545cfb  8b4648               mov eax, dword ptr [esi + 0x48]
// 00545cfe  50                   push eax
// 00545cff  83ec1c               sub esp, 0x1c
// 00545d02  8d562c               lea edx, [esi + 0x2c]
// 00545d05  8bcc                 mov ecx, esp
// 00545d07  89642424             mov dword ptr [esp + 0x24], esp
// 00545d0b  52                   push edx
// 00545d0c  ff154426b200         call dword ptr [0xb22644]
// 00545d12  83ec1c               sub esp, 0x1c
// 00545d15  8d4610               lea eax, [esi + 0x10]
// 00545d18  8bcc                 mov ecx, esp
// 00545d1a  89642444             mov dword ptr [esp + 0x44], esp
// 00545d1e  50                   push eax
// 00545d1f  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00545d27  ff154426b200         call dword ptr [0xb22644]
// 00545d2d  8b5608               mov edx, dword ptr [esi + 8]
// 00545d30  83ec08               sub esp, 8
// 00545d33  8bcc                 mov ecx, esp
// 00545d35  8911                 mov dword ptr [ecx], edx
// 00545d37  8b460c               mov eax, dword ptr [esi + 0xc]
// 00545d3a  8964244c             mov dword ptr [esp + 0x4c], esp
// 00545d3e  894104               mov dword ptr [ecx + 4], eax
// 00545d41  85c0                 test eax, eax
// 00545d43  740c                 je 0x545d51
// 00545d45  83c008               add eax, 8
// 00545d48  b901000000           mov ecx, 1
// 00545d4d  f00fc108             lock xadd dword ptr [eax], ecx
// 00545d51  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 00545d55  56                   push esi
// 00545d56  c744245cffffffff     mov dword ptr [esp + 0x5c], 0xffffffff
// 00545d5e  e85de8ffff           call 0x5445c0
// 00545d63  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00545d67  64890d00000000       mov dword ptr fs:[0], ecx
// 00545d6e  5e                   pop esi
// 00545d6f  83c414               add esp, 0x14
// 00545d72  c21000               ret 0x10
// copied from an identical function in another client (function ??$?RV?$mf4@XVObj@@V?$weak_ptr@VOther@@@boost@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V45@H@_mfi@boost@@Ulist0@_bi@2@@?$list5@V?$value@V?$shared_ptr@VObj@@@boost@@@_bi@boost@@V?$value@V?$weak_ptr@VOther@@@boost@@@23@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@V523@V?$value@H@23@@_bi@boost@@QAEXU?$type@X@2@AAV?$mf4@XVObj@@V?$weak_ptr@VOther@@@boost@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V45@H@_mfi@2@AAUlist0@12@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); if (_InterlockedDecrement(&weak_count_) == 0) destroy(); } }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(weak_count const& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->weak_count_); }
    ~weak_count() { if (pi_ != 0 && _InterlockedDecrement(&pi_->weak_count_) == 0) pi_->destroy(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> struct type {};
namespace _bi {
template<class T> class value {
public:
    T t_;
    T& get() { return t_; }
};
template<class A1, class A2, class A3, class A4, class A5> struct list5 {
    A1 a1_; A2 a2_; A3 a3_; A4 a4_; A5 a5_;
    template<class T> T& operator[](value<T>& v) const { return v.get(); }
    template<class F, class A> void operator()(type<void>, F& f, A& a, int)
    {
        f(a[a1_], a[a2_], a[a3_], a[a4_], a[a5_]);
    }
};
struct list0 {
    template<class T> T& operator[](value<T>& v) const { return v.get(); }
};
}
namespace _mfi {
template<class R, class T, class B1, class B2, class B3, class B4> class mf4 {
public:
    typedef R (T::*F)(B1, B2, B3, B4);
    F f_;
    template<class U> R operator()(U& u, B1 b1, B2 b2, B3 b3, B4 b4) const;
};
}
}
class Obj; class Other;
typedef boost::_mfi::mf4<void, Obj, boost::weak_ptr<Other>, std::string, std::string, int> MF;
typedef boost::_bi::list5<boost::_bi::value<boost::shared_ptr<Obj> >, boost::_bi::value<boost::weak_ptr<Other> >, boost::_bi::value<std::string>, boost::_bi::value<std::string>, boost::_bi::value<int> > L;
template void L::operator()<MF, boost::_bi::list0>(boost::type<void>, MF&, boost::_bi::list0&, int);