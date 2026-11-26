// from server: 100% by Xemicl
// roc 2012-06 00576460  unit: RBX::Network::Replicator::RockyItem  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00576460
//
// 00576460  6aff                 push -1
// 00576462  687bf4aa00           push 0xaaf47b
// 00576467  64a100000000         mov eax, dword ptr fs:[0]
// 0057646d  50                   push eax
// 0057646e  64892500000000       mov dword ptr fs:[0], esp
// 00576475  51                   push ecx
// 00576476  56                   push esi
// 00576477  8bf1                 mov esi, ecx
// 00576479  89742404             mov dword ptr [esp + 4], esi
// 0057647d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00576485  e816ffffff           call 0x5763a0
// 0057648a  8b760c               mov esi, dword ptr [esi + 0xc]
// 0057648d  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00576495  85f6                 test esi, esi
// 00576497  742a                 je 0x5764c3
// 00576499  8d4604               lea eax, [esi + 4]
// 0057649c  83c9ff               or ecx, 0xffffffff
// 0057649f  f00fc108             lock xadd dword ptr [eax], ecx
// 005764a3  751e                 jne 0x5764c3
// 005764a5  8b16                 mov edx, dword ptr [esi]
// 005764a7  8b4204               mov eax, dword ptr [edx + 4]
// 005764aa  8bce                 mov ecx, esi
// 005764ac  ffd0                 call eax
// 005764ae  8d4e08               lea ecx, [esi + 8]
// 005764b1  83caff               or edx, 0xffffffff
// 005764b4  f00fc111             lock xadd dword ptr [ecx], edx
// 005764b8  7509                 jne 0x5764c3
// 005764ba  8b06                 mov eax, dword ptr [esi]
// 005764bc  8b5008               mov edx, dword ptr [eax + 8]
// 005764bf  8bce                 mov ecx, esi
// 005764c1  ffd2                 call edx
// 005764c3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005764c7  5e                   pop esi
// 005764c8  64890d00000000       mov dword ptr fs:[0], ecx
// 005764cf  83c410               add esp, 0x10
// 005764d2  c3                   ret 
// copied from an identical function in another client (function ??1Writer2009@RBX@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base() {}
	virtual void dispose() = 0;
	virtual void destroy() { delete this; }
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	sp_counted_base* pi_;
	~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
namespace RBX {
class Stream;
class Writer2009 {
public:
	void* a;
	void* b;
	boost::shared_ptr<Stream> stream;
	~Writer2009();
	void flush();
};
Writer2009::~Writer2009() { flush(); }
}