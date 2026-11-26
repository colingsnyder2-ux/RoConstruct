// from server: 100% by Xemicl
// roc 2012-06 0051d000  unit: Ogre::istreamDataStream  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051d000
//
// 0051d000  6aff                 push -1
// 0051d002  6860b0aa00           push 0xaab060
// 0051d007  64a100000000         mov eax, dword ptr fs:[0]
// 0051d00d  50                   push eax
// 0051d00e  64892500000000       mov dword ptr fs:[0], esp
// 0051d015  51                   push ecx
// 0051d016  56                   push esi
// 0051d017  8bf1                 mov esi, ecx
// 0051d019  83ec1c               sub esp, 0x1c
// 0051d01c  8d442434             lea eax, [esp + 0x34]
// 0051d020  89642420             mov dword ptr [esp + 0x20], esp
// 0051d024  8bcc                 mov ecx, esp
// 0051d026  50                   push eax
// 0051d027  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0051d02f  ff154426b200         call dword ptr [0xb22644]
// 0051d035  8bce                 mov ecx, esi
// 0051d037  e8543bf1ff           call 0x430b90
// 0051d03c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0051d040  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0051d044  894e1c               mov dword ptr [esi + 0x1c], ecx
// 0051d047  894620               mov dword ptr [esi + 0x20], eax
// 0051d04a  85c0                 test eax, eax
// 0051d04c  740c                 je 0x51d05a
// 0051d04e  83c008               add eax, 8
// 0051d051  ba01000000           mov edx, 1
// 0051d056  f00fc110             lock xadd dword ptr [eax], edx
// 0051d05a  8d4c2418             lea ecx, [esp + 0x18]
// 0051d05e  c644241000           mov byte ptr [esp + 0x10], 0
// 0051d063  ff153c26b200         call dword ptr [0xb2263c]
// 0051d069  8b442438             mov eax, dword ptr [esp + 0x38]
// 0051d06d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0051d075  85c0                 test eax, eax
// 0051d077  7415                 je 0x51d08e
// 0051d079  8bc8                 mov ecx, eax
// 0051d07b  83c008               add eax, 8
// 0051d07e  83caff               or edx, 0xffffffff
// 0051d081  f00fc110             lock xadd dword ptr [eax], edx
// 0051d085  7507                 jne 0x51d08e
// 0051d087  8b01                 mov eax, dword ptr [ecx]
// 0051d089  8b5008               mov edx, dword ptr [eax + 8]
// 0051d08c  ffd2                 call edx
// 0051d08e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051d092  8bc6                 mov eax, esi
// 0051d094  64890d00000000       mov dword ptr fs:[0], ecx
// 0051d09b  5e                   pop esi
// 0051d09c  83c410               add esp, 0x10
// 0051d09f  c22400               ret 0x24
// copied from an identical function in another client (function ??0?$storage2@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_bi@boost@@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@23@@_bi@boost@@QAE@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@12@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@12@@Z)

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
    storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {}
    A2 a2_;
};
}
}
namespace RBX { class Instance; }
template struct boost::_bi::storage2<boost::_bi::value<std::string>, boost::_bi::value<boost::weak_ptr<RBX::Instance> > >;