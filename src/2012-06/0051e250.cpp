// from server: 100% by Xemicl
// roc 2012-06 0051e250  unit: RBX::Network::P8Player::?$GetSetImpl  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051e250
//
// 0051e250  6aff                 push -1
// 0051e252  6840b1aa00           push 0xaab140
// 0051e257  64a100000000         mov eax, dword ptr fs:[0]
// 0051e25d  50                   push eax
// 0051e25e  64892500000000       mov dword ptr fs:[0], esp
// 0051e265  83ec08               sub esp, 8
// 0051e268  56                   push esi
// 0051e269  8bf1                 mov esi, ecx
// 0051e26b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0051e273  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0051e277  83ec08               sub esp, 8
// 0051e27a  8bc4                 mov eax, esp
// 0051e27c  8908                 mov dword ptr [eax], ecx
// 0051e27e  8b542444             mov edx, dword ptr [esp + 0x44]
// 0051e282  895004               mov dword ptr [eax + 4], edx
// 0051e285  8b442444             mov eax, dword ptr [esp + 0x44]
// 0051e289  8964240c             mov dword ptr [esp + 0xc], esp
// 0051e28d  85c0                 test eax, eax
// 0051e28f  740c                 je 0x51e29d
// 0051e291  83c008               add eax, 8
// 0051e294  b901000000           mov ecx, 1
// 0051e299  f00fc108             lock xadd dword ptr [eax], ecx
// 0051e29d  83ec1c               sub esp, 0x1c
// 0051e2a0  8d542440             lea edx, [esp + 0x40]
// 0051e2a4  8964242c             mov dword ptr [esp + 0x2c], esp
// 0051e2a8  8bcc                 mov ecx, esp
// 0051e2aa  52                   push edx
// 0051e2ab  c644243c03           mov byte ptr [esp + 0x3c], 3
// 0051e2b0  ff154426b200         call dword ptr [0xb22644]
// 0051e2b6  8bce                 mov ecx, esi
// 0051e2b8  c644243802           mov byte ptr [esp + 0x38], 2
// 0051e2bd  e83eedffff           call 0x51d000
// 0051e2c2  8b442440             mov eax, dword ptr [esp + 0x40]
// 0051e2c6  894624               mov dword ptr [esi + 0x24], eax
// 0051e2c9  8b442444             mov eax, dword ptr [esp + 0x44]
// 0051e2cd  894628               mov dword ptr [esi + 0x28], eax
// 0051e2d0  85c0                 test eax, eax
// 0051e2d2  740c                 je 0x51e2e0
// 0051e2d4  83c008               add eax, 8
// 0051e2d7  b901000000           mov ecx, 1
// 0051e2dc  f00fc108             lock xadd dword ptr [eax], ecx
// 0051e2e0  8d4c241c             lea ecx, [esp + 0x1c]
// 0051e2e4  c644241401           mov byte ptr [esp + 0x14], 1
// 0051e2e9  ff153c26b200         call dword ptr [0xb2263c]
// 0051e2ef  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0051e2f3  c644241400           mov byte ptr [esp + 0x14], 0
// 0051e2f8  85c0                 test eax, eax
// 0051e2fa  7415                 je 0x51e311
// 0051e2fc  8bc8                 mov ecx, eax
// 0051e2fe  83c008               add eax, 8
// 0051e301  83caff               or edx, 0xffffffff
// 0051e304  f00fc110             lock xadd dword ptr [eax], edx
// 0051e308  7507                 jne 0x51e311
// 0051e30a  8b01                 mov eax, dword ptr [ecx]
// 0051e30c  8b5008               mov edx, dword ptr [eax + 8]
// 0051e30f  ffd2                 call edx
// 0051e311  8b442444             mov eax, dword ptr [esp + 0x44]
// 0051e315  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0051e31d  85c0                 test eax, eax
// 0051e31f  7415                 je 0x51e336
// 0051e321  8bc8                 mov ecx, eax
// 0051e323  83c008               add eax, 8
// 0051e326  83caff               or edx, 0xffffffff
// 0051e329  f00fc110             lock xadd dword ptr [eax], edx
// 0051e32d  7507                 jne 0x51e336
// 0051e32f  8b01                 mov eax, dword ptr [ecx]
// 0051e331  8b5008               mov edx, dword ptr [eax + 8]
// 0051e334  ffd2                 call edx
// 0051e336  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0051e33a  8bc6                 mov eax, esi
// 0051e33c  64890d00000000       mov dword ptr fs:[0], ecx
// 0051e343  5e                   pop esi
// 0051e344  83c414               add esp, 0x14
// 0051e347  c22c00               ret 0x2c
// copied from an identical function in another client (function ??0?$storage3@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@_bi@boost@@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@23@V?$value@V?$weak_ptr@VPlayer@RBX@@@boost@@@23@@_bi@boost@@QAE@V?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@12@V?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@12@V?$value@V?$weak_ptr@VPlayer@RBX@@@boost@@@12@@Z)

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
    storage3(A1 a1, A2 a2, A3 a3) : storage2<A1, A2>(a1, a2), a3_(a3) {}
    A3 a3_;
};
}
}
namespace RBX { class Instance; class Player; }
template struct boost::_bi::storage3<boost::_bi::value<std::string>, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<boost::weak_ptr<RBX::Player> > >;