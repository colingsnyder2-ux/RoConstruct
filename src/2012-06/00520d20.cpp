// from server: 100% by Xemicl
// roc 2012-06 00520d20  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00520d20
//
// 00520d20  8bc1                 mov eax, ecx
// 00520d22  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00520d26  8b11                 mov edx, dword ptr [ecx]
// 00520d28  8910                 mov dword ptr [eax], edx
// 00520d2a  8b5104               mov edx, dword ptr [ecx + 4]
// 00520d2d  895004               mov dword ptr [eax + 4], edx
// 00520d30  8b5108               mov edx, dword ptr [ecx + 8]
// 00520d33  895008               mov dword ptr [eax + 8], edx
// 00520d36  85d2                 test edx, edx
// 00520d38  740e                 je 0x520d48
// 00520d3a  56                   push esi
// 00520d3b  83c208               add edx, 8
// 00520d3e  be01000000           mov esi, 1
// 00520d43  f00fc132             lock xadd dword ptr [edx], esi
// 00520d47  5e                   pop esi
// 00520d48  8b510c               mov edx, dword ptr [ecx + 0xc]
// 00520d4b  89500c               mov dword ptr [eax + 0xc], edx
// 00520d4e  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 00520d51  894810               mov dword ptr [eax + 0x10], ecx
// 00520d54  85c9                 test ecx, ecx
// 00520d56  740c                 je 0x520d64
// 00520d58  83c108               add ecx, 8
// 00520d5b  ba01000000           mov edx, 1
// 00520d60  f00fc111             lock xadd dword ptr [ecx], edx
// 00520d64  c20400               ret 4
// copied from an identical function in another client (function ??0Functor@@QAE@ABU0@@Z)

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
	void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
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
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
}
namespace boost {
namespace detail { namespace function {
union function_buffer {
	void* obj_ptr;
	void (*func_ptr)();
	double align_;
	char data[16];
};
struct vtable_base { void (*manager)(); };
template<class R, class T0> struct basic_vtable1 {
	vtable_base base;
	void (*invoker)();
	template<class F> bool assign_to(F f, function_buffer& functor);
};
}}
class function_base {
public:
	detail::function::vtable_base* vtable;
	mutable detail::function::function_buffer functor;
};
template<class R, class T0> class function1 : public function_base {
	typedef detail::function::basic_vtable1<R, T0> vtable_type;
public:
	template<class Functor> void assign_to(Functor f);
};
template<class R, class T0> template<class Functor> void function1<R, T0>::assign_to(Functor f)
{
	static vtable_type stored_vtable;
	if (stored_vtable.assign_to(f, functor))
		vtable = &stored_vtable.base;
	else
		vtable = 0;
}
}
namespace boost { namespace detail {
class weak_count {
public:
	sp_counted_base* pi_;
	weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
}
namespace RBX { class Player; class Instance; }
struct L2 { boost::weak_ptr<RBX::Player> a; boost::weak_ptr<RBX::Instance> b; ~L2(); };
struct Functor { void (*f)(); L2 l; };
template void boost::function1<void, int>::assign_to<Functor>(Functor);