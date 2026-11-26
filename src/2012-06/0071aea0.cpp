// from server: 100% by Xemicl
// roc 2012-06 0071aea0  unit: RBX::VProtectedString::?$TypedPropertyDescriptor  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071aea0
//
// 0071aea0  6aff                 push -1
// 0071aea2  68f8f1ab00           push 0xabf1f8
// 0071aea7  64a100000000         mov eax, dword ptr fs:[0]
// 0071aead  50                   push eax
// 0071aeae  64892500000000       mov dword ptr fs:[0], esp
// 0071aeb5  51                   push ecx
// 0071aeb6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0071aeba  56                   push esi
// 0071aebb  8bf1                 mov esi, ecx
// 0071aebd  8b08                 mov ecx, dword ptr [eax]
// 0071aebf  890e                 mov dword ptr [esi], ecx
// 0071aec1  8b4804               mov ecx, dword ptr [eax + 4]
// 0071aec4  89742404             mov dword ptr [esp + 4], esi
// 0071aec8  894e04               mov dword ptr [esi + 4], ecx
// 0071aecb  85c9                 test ecx, ecx
// 0071aecd  740c                 je 0x71aedb
// 0071aecf  83c108               add ecx, 8
// 0071aed2  ba01000000           mov edx, 1
// 0071aed7  f00fc111             lock xadd dword ptr [ecx], edx
// 0071aedb  8b4808               mov ecx, dword ptr [eax + 8]
// 0071aede  894e08               mov dword ptr [esi + 8], ecx
// 0071aee1  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0071aee4  894e0c               mov dword ptr [esi + 0xc], ecx
// 0071aee7  85c9                 test ecx, ecx
// 0071aee9  740c                 je 0x71aef7
// 0071aeeb  83c108               add ecx, 8
// 0071aeee  ba01000000           mov edx, 1
// 0071aef3  f00fc111             lock xadd dword ptr [ecx], edx
// 0071aef7  83c010               add eax, 0x10
// 0071aefa  50                   push eax
// 0071aefb  8d4e10               lea ecx, [esi + 0x10]
// 0071aefe  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0071af06  ff154426b200         call dword ptr [0xb22644]
// 0071af0c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071af10  8bc6                 mov eax, esi
// 0071af12  5e                   pop esi
// 0071af13  64890d00000000       mov dword ptr fs:[0], ecx
// 0071af1a  83c410               add esp, 0x10
// 0071af1d  c20400               ret 4
// copied from an identical function in another client (function ??0?$storage3@U?$value@V?$weak_ptr@VPlayer@Network@RBX@@@boost@@@_bi@boost@@U?$value@V?$weak_ptr@VInstance@RBX@@@boost@@@23@U?$value@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@23@@_bi@boost@@QAE@ABU012@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class weak_count {
public:
	sp_counted_base* pi_;
	weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
namespace _bi {
template<class T> struct value { T t_; };
template<class A1, class A2> struct storage2 { A1 a1_; A2 a2_; };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> {
	A3 a3_;
	storage3(const storage3& o);
};
template<class A1, class A2, class A3> storage3<A1,A2,A3>::storage3(const storage3& o) : storage2<A1, A2>(o), a3_(o.a3_) {}
}
}
namespace RBX { class Instance; namespace Network { class Player; } }
template struct boost::_bi::storage3<boost::_bi::value<boost::weak_ptr<RBX::Network::Player> >, boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<std::string> >;