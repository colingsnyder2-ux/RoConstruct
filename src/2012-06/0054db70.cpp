// from server: 100% by Xemicl
// roc 2012-06 0054db70  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0054db70
//
// 0054db70  6aff                 push -1
// 0054db72  6888d1aa00           push 0xaad188
// 0054db77  64a100000000         mov eax, dword ptr fs:[0]
// 0054db7d  50                   push eax
// 0054db7e  64892500000000       mov dword ptr fs:[0], esp
// 0054db85  51                   push ecx
// 0054db86  56                   push esi
// 0054db87  57                   push edi
// 0054db88  8bf1                 mov esi, ecx
// 0054db8a  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0054db8e  8d4608               lea eax, [esi + 8]
// 0054db91  50                   push eax
// 0054db92  83ec58               sub esp, 0x58
// 0054db95  8bc4                 mov eax, esp
// 0054db97  8908                 mov dword ptr [eax], ecx
// 0054db99  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 0054db9d  8d7808               lea edi, [eax + 8]
// 0054dba0  895004               mov dword ptr [eax + 4], edx
// 0054dba3  8d842480000000       lea eax, [esp + 0x80]
// 0054dbaa  89642464             mov dword ptr [esp + 0x64], esp
// 0054dbae  50                   push eax
// 0054dbaf  8bcf                 mov ecx, edi
// 0054dbb1  c744247400000000     mov dword ptr [esp + 0x74], 0
// 0054dbb9  e85287ffff           call 0x546310
// 0054dbbe  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 0054dbc5  894f48               mov dword ptr [edi + 0x48], ecx
// 0054dbc8  b91052d800           mov ecx, 0xd85210
// 0054dbcd  e88ed5ffff           call 0x54b160
// 0054dbd2  0fb6d0               movzx edx, al
// 0054dbd5  f7da                 neg edx
// 0054dbd7  1bd2                 sbb edx, edx
// 0054dbd9  81e21052d800         and edx, 0xd85210
// 0054dbdf  8d4c2424             lea ecx, [esp + 0x24]
// 0054dbe3  8916                 mov dword ptr [esi], edx
// 0054dbe5  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0054dbed  e83e82ffff           call 0x545e30
// 0054dbf2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054dbf6  5f                   pop edi
// 0054dbf7  64890d00000000       mov dword ptr fs:[0], ecx
// 0054dbfe  5e                   pop esi
// 0054dbff  83c410               add esp, 0x10
// 0054dc02  c25800               ret 0x58
// copied from an identical function in another client (function ??$assign_to@UF@@@?$function0@X@boost@@QAEXUF@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align_; char data[16]; };
template<class R> struct basic_vtable0 {
	void* manager;
	void* invoker;
	template<class F> bool assign_to(F f, function_buffer& functor);
};
}}
class function_base {
public:
	void* vtable;
	mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
	typedef detail::function::basic_vtable0<R> vtable_type;
	template<class F> void assign_to(F f)
	{
		static vtable_type stored_vtable = { 0, 0 };
		if (stored_vtable.assign_to(f, this->functor))
			this->vtable = &stored_vtable;
		else
			this->vtable = 0;
	}
};
}
struct X { double d; char pad[0x40]; X(const X&); ~X(); };
struct Y { X c; int d; };
struct F { int a; int b; Y y; };
template void boost::function0<void>::assign_to<F>(F);