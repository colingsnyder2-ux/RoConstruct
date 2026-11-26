// from server: 100% by Xemicl
// roc 2012-06 00481040  unit: CRobloxDoc  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00481040
//
// 00481040  6aff                 push -1
// 00481042  68280cad00           push 0xad0c28
// 00481047  64a100000000         mov eax, dword ptr fs:[0]
// 0048104d  50                   push eax
// 0048104e  64892500000000       mov dword ptr fs:[0], esp
// 00481055  51                   push ecx
// 00481056  56                   push esi
// 00481057  8bf1                 mov esi, ecx
// 00481059  89742404             mov dword ptr [esp + 4], esi
// 0048105d  8d4e20               lea ecx, [esi + 0x20]
// 00481060  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00481068  ff153c26b200         call dword ptr [0xb2263c]
// 0048106e  8b06                 mov eax, dword ptr [esi]
// 00481070  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00481078  85c0                 test eax, eax
// 0048107a  7418                 je 0x481094
// 0048107c  8b00                 mov eax, dword ptr [eax]
// 0048107e  8d4e08               lea ecx, [esi + 8]
// 00481081  85c0                 test eax, eax
// 00481083  7409                 je 0x48108e
// 00481085  6a02                 push 2
// 00481087  51                   push ecx
// 00481088  51                   push ecx
// 00481089  ffd0                 call eax
// 0048108b  83c40c               add esp, 0xc
// 0048108e  c70600000000         mov dword ptr [esi], 0
// 00481094  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481098  5e                   pop esi
// 00481099  64890d00000000       mov dword ptr fs:[0], ecx
// 004810a0  83c410               add esp, 0x10
// 004810a3  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost { namespace detail { namespace function {
union function_buffer { void* obj_ptr; struct { void* a; void* b; void* c; } bound; __declspec(align(8)) char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
	void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
	void clear(function_buffer& functor) { if (manager) manager(functor, functor, destroy_functor_tag); }
};
} }
class function_base {
public:
	detail::function::vtable_base* vtable;
	mutable detail::function::function_buffer functor;
};
class function0 : public function_base {
public:
	~function0() { clear(); }
	void clear() { if (vtable) { vtable->clear(this->functor); vtable = 0; } }
};
}
struct S {
	boost::function0 f;
	std::string s;
	~S();
};
S::~S() {}