// from server: 100% by Xemicl
// roc 2012-06 0067a320  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0067a320
//
// 0067a320  6aff                 push -1
// 0067a322  6808c8ac00           push 0xacc808
// 0067a327  64a100000000         mov eax, dword ptr fs:[0]
// 0067a32d  50                   push eax
// 0067a32e  64892500000000       mov dword ptr fs:[0], esp
// 0067a335  83ec0c               sub esp, 0xc
// 0067a338  8d442404             lea eax, [esp + 4]
// 0067a33c  56                   push esi
// 0067a33d  50                   push eax
// 0067a33e  e89d1bdcff           call 0x43bee0
// 0067a343  8b00                 mov eax, dword ptr [eax]
// 0067a345  8b503c               mov edx, dword ptr [eax + 0x3c]
// 0067a348  8d4c2408             lea ecx, [esp + 8]
// 0067a34c  51                   push ecx
// 0067a34d  52                   push edx
// 0067a34e  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0067a356  e845a32f00           call 0x9746a0
// 0067a35b  8b742418             mov esi, dword ptr [esp + 0x18]
// 0067a35f  83c40c               add esp, 0xc
// 0067a362  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0067a36a  85f6                 test esi, esi
// 0067a36c  742a                 je 0x67a398
// 0067a36e  8d4604               lea eax, [esi + 4]
// 0067a371  83c9ff               or ecx, 0xffffffff
// 0067a374  f00fc108             lock xadd dword ptr [eax], ecx
// 0067a378  751e                 jne 0x67a398
// 0067a37a  8b16                 mov edx, dword ptr [esi]
// 0067a37c  8b4204               mov eax, dword ptr [edx + 4]
// 0067a37f  8bce                 mov ecx, esi
// 0067a381  ffd0                 call eax
// 0067a383  8d4e08               lea ecx, [esi + 8]
// 0067a386  83caff               or edx, 0xffffffff
// 0067a389  f00fc111             lock xadd dword ptr [ecx], edx
// 0067a38d  7509                 jne 0x67a398
// 0067a38f  8b06                 mov eax, dword ptr [esi]
// 0067a391  8b5008               mov edx, dword ptr [eax + 8]
// 0067a394  8bce                 mov ecx, esi
// 0067a396  ffd2                 call edx
// 0067a398  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067a39c  8b442404             mov eax, dword ptr [esp + 4]
// 0067a3a0  5e                   pop esi
// 0067a3a1  64890d00000000       mov dword ptr fs:[0], ecx
// 0067a3a8  83c418               add esp, 0x18
// 0067a3ab  c3                   ret 
// copied from an identical function in another client (function ?getB2009@@YAHXZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
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
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; T* operator->() const { return px; } };
}
struct Info2009 { char pad[0x38]; void* a; void* b; };
boost::shared_ptr<Info2009> getInfo2009();
void query2009(void* h, int* out);
int getB2009()
{
	int v;
	query2009(getInfo2009()->b, &v);
	return v;
}