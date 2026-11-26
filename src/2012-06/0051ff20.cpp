// from server: 100% by Xemicl
// roc 2012-06 0051ff20  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 262 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051ff20
//
// 0051ff20  6aff                 push -1
// 0051ff22  68f8b1aa00           push 0xaab1f8
// 0051ff27  64a100000000         mov eax, dword ptr fs:[0]
// 0051ff2d  50                   push eax
// 0051ff2e  64892500000000       mov dword ptr fs:[0], esp
// 0051ff35  83ec0c               sub esp, 0xc
// 0051ff38  56                   push esi
// 0051ff39  8bf1                 mov esi, ecx
// 0051ff3b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0051ff43  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0051ff47  83ec08               sub esp, 8
// 0051ff4a  8bc4                 mov eax, esp
// 0051ff4c  8908                 mov dword ptr [eax], ecx
// 0051ff4e  8b542450             mov edx, dword ptr [esp + 0x50]
// 0051ff52  895004               mov dword ptr [eax + 4], edx
// 0051ff55  8b442450             mov eax, dword ptr [esp + 0x50]
// 0051ff59  8964240c             mov dword ptr [esp + 0xc], esp
// 0051ff5d  85c0                 test eax, eax
// 0051ff5f  740c                 je 0x51ff6d
// 0051ff61  83c008               add eax, 8
// 0051ff64  b901000000           mov ecx, 1
// 0051ff69  f00fc108             lock xadd dword ptr [eax], ecx
// 0051ff6d  8b542444             mov edx, dword ptr [esp + 0x44]
// 0051ff71  83ec08               sub esp, 8
// 0051ff74  8bc4                 mov eax, esp
// 0051ff76  8910                 mov dword ptr [eax], edx
// 0051ff78  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0051ff7c  894804               mov dword ptr [eax + 4], ecx
// 0051ff7f  8b442450             mov eax, dword ptr [esp + 0x50]
// 0051ff83  89642418             mov dword ptr [esp + 0x18], esp
// 0051ff87  85c0                 test eax, eax
// 0051ff89  740c                 je 0x51ff97
// 0051ff8b  83c008               add eax, 8
// 0051ff8e  ba01000000           mov edx, 1
// 0051ff93  f00fc110             lock xadd dword ptr [eax], edx
// 0051ff97  83ec1c               sub esp, 0x1c
// 0051ff9a  8d44244c             lea eax, [esp + 0x4c]
// 0051ff9e  89642438             mov dword ptr [esp + 0x38], esp
// 0051ffa2  8bcc                 mov ecx, esp
// 0051ffa4  50                   push eax
// 0051ffa5  c644244804           mov byte ptr [esp + 0x48], 4
// 0051ffaa  ff154426b200         call dword ptr [0xb22644]
// 0051ffb0  8bce                 mov ecx, esi
// 0051ffb2  c644244402           mov byte ptr [esp + 0x44], 2
// 0051ffb7  e894e2ffff           call 0x51e250
// 0051ffbc  8d4c2420             lea ecx, [esp + 0x20]
// 0051ffc0  c644241801           mov byte ptr [esp + 0x18], 1
// 0051ffc5  ff153c26b200         call dword ptr [0xb2263c]
// 0051ffcb  8b442440             mov eax, dword ptr [esp + 0x40]
// 0051ffcf  c644241800           mov byte ptr [esp + 0x18], 0
// 0051ffd4  85c0                 test eax, eax
// 0051ffd6  7415                 je 0x51ffed
// 0051ffd8  8bc8                 mov ecx, eax
// 0051ffda  83c008               add eax, 8
// 0051ffdd  83caff               or edx, 0xffffffff
// 0051ffe0  f00fc110             lock xadd dword ptr [eax], edx
// 0051ffe4  7507                 jne 0x51ffed
// 0051ffe6  8b01                 mov eax, dword ptr [ecx]
// 0051ffe8  8b5008               mov edx, dword ptr [eax + 8]
// 0051ffeb  ffd2                 call edx
// 0051ffed  8b442448             mov eax, dword ptr [esp + 0x48]
// 0051fff1  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0051fff9  85c0                 test eax, eax
// 0051fffb  7415                 je 0x520012
// 0051fffd  8bc8                 mov ecx, eax
// 0051ffff  83c008               add eax, 8
// 00520002  83caff               or edx, 0xffffffff
// 00520005  f00fc110             lock xadd dword ptr [eax], edx
// 00520009  7507                 jne 0x520012
// 0052000b  8b01                 mov eax, dword ptr [ecx]
// 0052000d  8b5008               mov edx, dword ptr [eax + 8]
// 00520010  ffd2                 call edx
// 00520012  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00520016  8bc6                 mov eax, esi
// 00520018  64890d00000000       mov dword ptr fs:[0], ecx
// 0052001f  5e                   pop esi
// 00520020  83c418               add esp, 0x18
// 00520023  c22c00               ret 0x2c
// copied from an identical function in another client (function ??0?$list3@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_bi@boost@@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@23@V?$value@V?$weak_ptr@VPlayer@RBX@@@boost@@@23@@_bi@boost@@QAE@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@12@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@12@V?$value@V?$weak_ptr@VPlayer@RBX@@@boost@@@12@@Z)

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
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(weak_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { explicit storage1(A1 a1); A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> {
    storage2(A1 a1, A2 a2);
    A2 a2_;
};
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
    storage3(A1 a1, A2 a2, A3 a3);
    A3 a3_;
};
template<class A1, class A2, class A3> class list3 : private storage3<A1, A2, A3> {
    typedef storage3<A1, A2, A3> base_type;
public:
    list3(A1 a1, A2 a2, A3 a3) : base_type(a1, a2, a3) {}
};
}
}
namespace RBX { class Instance; class Player; }
template class boost::_bi::list3<boost::_bi::value<std::string>, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<boost::weak_ptr<RBX::Player> > >;