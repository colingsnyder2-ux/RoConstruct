// from server: 100% by Xemicl
// roc 2012-06 0051c8e0  unit: Ogre::istreamDataStream  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0051c8e0
//
// 0051c8e0  6aff                 push -1
// 0051c8e2  6828acab00           push 0xabac28
// 0051c8e7  64a100000000         mov eax, dword ptr fs:[0]
// 0051c8ed  50                   push eax
// 0051c8ee  64892500000000       mov dword ptr fs:[0], esp
// 0051c8f5  51                   push ecx
// 0051c8f6  56                   push esi
// 0051c8f7  8bf1                 mov esi, ecx
// 0051c8f9  89742404             mov dword ptr [esp + 4], esi
// 0051c8fd  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0051c900  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051c908  85c9                 test ecx, ecx
// 0051c90a  7413                 je 0x51c91f
// 0051c90c  8d4108               lea eax, [ecx + 8]
// 0051c90f  83caff               or edx, 0xffffffff
// 0051c912  f00fc110             lock xadd dword ptr [eax], edx
// 0051c916  7507                 jne 0x51c91f
// 0051c918  8b01                 mov eax, dword ptr [ecx]
// 0051c91a  8b5008               mov edx, dword ptr [eax + 8]
// 0051c91d  ffd2                 call edx
// 0051c91f  8bce                 mov ecx, esi
// 0051c921  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0051c929  ff153c26b200         call dword ptr [0xb2263c]
// 0051c92f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0051c933  5e                   pop esi
// 0051c934  64890d00000000       mov dword ptr fs:[0], ecx
// 0051c93b  83c410               add esp, 0x10
// 0051c93e  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

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
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class weak_count {
	sp_counted_base* pi_;
public:
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { T* px; detail::weak_count pn; };
}
class Player;
struct S {
	std::string name;
	boost::weak_ptr<Player> player;
	~S();
};
S::~S() {}