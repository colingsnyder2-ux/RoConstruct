// from server: 100% by Xemicl
// roc 2012-06 004562c0  unit: CPropGrid::UpdateItemsJob  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004562c0
//
// 004562c0  6aff                 push -1
// 004562c2  68e852ad00           push 0xad52e8
// 004562c7  64a100000000         mov eax, dword ptr fs:[0]
// 004562cd  50                   push eax
// 004562ce  64892500000000       mov dword ptr fs:[0], esp
// 004562d5  51                   push ecx
// 004562d6  56                   push esi
// 004562d7  8bd1                 mov edx, ecx
// 004562d9  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004562dd  83ec08               sub esp, 8
// 004562e0  8bc4                 mov eax, esp
// 004562e2  8908                 mov dword ptr [eax], ecx
// 004562e4  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004562e8  894804               mov dword ptr [eax + 4], ecx
// 004562eb  8b442428             mov eax, dword ptr [esp + 0x28]
// 004562ef  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004562f7  8964240c             mov dword ptr [esp + 0xc], esp
// 004562fb  85c0                 test eax, eax
// 004562fd  740c                 je 0x45630b
// 004562ff  83c004               add eax, 4
// 00456302  b901000000           mov ecx, 1
// 00456307  f00fc108             lock xadd dword ptr [eax], ecx
// 0045630b  8b442420             mov eax, dword ptr [esp + 0x20]
// 0045630f  8b08                 mov ecx, dword ptr [eax]
// 00456311  8b12                 mov edx, dword ptr [edx]
// 00456313  ffd2                 call edx
// 00456315  8b742420             mov esi, dword ptr [esp + 0x20]
// 00456319  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00456321  85f6                 test esi, esi
// 00456323  742a                 je 0x45634f
// 00456325  8d4604               lea eax, [esi + 4]
// 00456328  83c9ff               or ecx, 0xffffffff
// 0045632b  f00fc108             lock xadd dword ptr [eax], ecx
// 0045632f  751e                 jne 0x45634f
// 00456331  8b16                 mov edx, dword ptr [esi]
// 00456333  8b4204               mov eax, dword ptr [edx + 4]
// 00456336  8bce                 mov ecx, esi
// 00456338  ffd0                 call eax
// 0045633a  8d4e08               lea ecx, [esi + 8]
// 0045633d  83caff               or edx, 0xffffffff
// 00456340  f00fc111             lock xadd dword ptr [ecx], edx
// 00456344  7509                 jne 0x45634f
// 00456346  8b06                 mov eax, dword ptr [esi]
// 00456348  8b5008               mov edx, dword ptr [eax + 8]
// 0045634b  8bce                 mov ecx, esi
// 0045634d  ffd2                 call edx
// 0045634f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00456353  64890d00000000       mov dword ptr fs:[0], ecx
// 0045635a  5e                   pop esi
// 0045635b  83c410               add esp, 0x10
// 0045635e  c20c00               ret 0xc
// copied from an identical function in another client (function ??$?RV?$shared_ptr@Voptions_description@program_options@boost@@@boost@@@?$mf1@XVoptions_description@program_options@boost@@V?$shared_ptr@Voption_description@program_options@boost@@@3@@_mfi@boost@@QBEXAAV?$shared_ptr@Voptions_description@program_options@boost@@@2@V?$shared_ptr@Voption_description@program_options@boost@@@2@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
	virtual ~sp_counted_base();
	virtual void dispose() = 0;
	virtual void destroy();
	void add_ref_copy() { _InterlockedIncrement(&use_count_); }
	void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
	void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
	long use_count_;
	long weak_count_;
};
class shared_count {
public:
	sp_counted_base* pi_;
	shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
	~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
	T* px;
	detail::shared_count pn;
	T* get() const { return px; }
};
template<class T> T* get_pointer(const shared_ptr<T>& p) { return p.get(); }
namespace _mfi {
template<class R, class T, class A1> class mf1 {
	typedef R (T::*F)(A1);
	F f_;
	template<class U, class B1> R call(U& u, const void*, B1& b1) const { return (get_pointer(u)->*f_)(b1); }
public:
	template<class U> R operator()(U& u, A1 a1) const { return call(u, &u, a1); }
};
}
namespace program_options {
class option_description;
class options_description { public: void add(shared_ptr<option_description> d); };
}
template void _mfi::mf1<void, program_options::options_description, shared_ptr<program_options::option_description> >::operator()(shared_ptr<program_options::options_description>&, shared_ptr<program_options::option_description>) const;
}