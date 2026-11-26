// from server: 100% by Xemicl
// roc 2012-06 0043bb60  unit: VCProcessPerfCounter::?$sp_counted_impl_p  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0043bb60
//
// 0043bb60  8b542408             mov edx, dword ptr [esp + 8]
// 0043bb64  56                   push esi
// 0043bb65  8bf1                 mov esi, ecx
// 0043bb67  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043bb6b  8d4608               lea eax, [esi + 8]
// 0043bb6e  50                   push eax
// 0043bb6f  83ec18               sub esp, 0x18
// 0043bb72  8bc4                 mov eax, esp
// 0043bb74  8908                 mov dword ptr [eax], ecx
// 0043bb76  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0043bb7a  895004               mov dword ptr [eax + 4], edx
// 0043bb7d  8b542430             mov edx, dword ptr [esp + 0x30]
// 0043bb81  894808               mov dword ptr [eax + 8], ecx
// 0043bb84  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0043bb88  89500c               mov dword ptr [eax + 0xc], edx
// 0043bb8b  8b542438             mov edx, dword ptr [esp + 0x38]
// 0043bb8f  894810               mov dword ptr [eax + 0x10], ecx
// 0043bb92  b9706dd600           mov ecx, 0xd66d70
// 0043bb97  895014               mov dword ptr [eax + 0x14], edx
// 0043bb9a  e821082f00           call 0x72c3c0
// 0043bb9f  0fb6c0               movzx eax, al
// 0043bba2  f7d8                 neg eax
// 0043bba4  1bc0                 sbb eax, eax
// 0043bba6  25706dd600           and eax, 0xd66d70
// 0043bbab  8906                 mov dword ptr [esi], eax
// 0043bbad  5e                   pop esi
// 0043bbae  c21800               ret 0x18
// copied from an identical function in another client (function ??$assign_to@UFunctor@@@?$function1@XH@boost@@QAEXUFunctor@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
struct Functor { int a[6]; };
template void boost::function1<void, int>::assign_to<Functor>(Functor);