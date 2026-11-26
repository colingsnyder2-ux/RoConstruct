// from server: 100% by Xemicl
// roc 2012-06 00532e00  unit: RBX::Network::VPlayer::?$FactoryProduct  size: 171 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00532e00
//
// 00532e00  6aff                 push -1
// 00532e02  68d8bbaa00           push 0xaabbd8
// 00532e07  64a100000000         mov eax, dword ptr fs:[0]
// 00532e0d  50                   push eax
// 00532e0e  64892500000000       mov dword ptr fs:[0], esp
// 00532e15  51                   push ecx
// 00532e16  53                   push ebx
// 00532e17  56                   push esi
// 00532e18  8bf1                 mov esi, ecx
// 00532e1a  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 00532e1e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00532e22  c644240800           mov byte ptr [esp + 8], 0
// 00532e27  8b442408             mov eax, dword ptr [esp + 8]
// 00532e2b  50                   push eax
// 00532e2c  51                   push ecx
// 00532e2d  83ec28               sub esp, 0x28
// 00532e30  8bc4                 mov eax, esp
// 00532e32  8910                 mov dword ptr [eax], edx
// 00532e34  c7400800000000       mov dword ptr [eax + 8], 0
// 00532e3b  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00532e3f  c744244400000000     mov dword ptr [esp + 0x44], 0
// 00532e47  89642474             mov dword ptr [esp + 0x74], esp
// 00532e4b  85c9                 test ecx, ecx
// 00532e4d  7419                 je 0x532e68
// 00532e4f  894808               mov dword ptr [eax + 8], ecx
// 00532e52  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 00532e56  8b11                 mov edx, dword ptr [ecx]
// 00532e58  83c010               add eax, 0x10
// 00532e5b  6a00                 push 0
// 00532e5d  50                   push eax
// 00532e5e  8d442464             lea eax, [esp + 0x64]
// 00532e62  50                   push eax
// 00532e63  ffd2                 call edx
// 00532e65  83c40c               add esp, 0xc
// 00532e68  8bce                 mov ecx, esi
// 00532e6a  e891feffff           call 0x532d00
// 00532e6f  8ad8                 mov bl, al
// 00532e71  8b442424             mov eax, dword ptr [esp + 0x24]
// 00532e75  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00532e7d  85c0                 test eax, eax
// 00532e7f  7415                 je 0x532e96
// 00532e81  8b00                 mov eax, dword ptr [eax]
// 00532e83  85c0                 test eax, eax
// 00532e85  740f                 je 0x532e96
// 00532e87  8d4c242c             lea ecx, [esp + 0x2c]
// 00532e8b  6a02                 push 2
// 00532e8d  51                   push ecx
// 00532e8e  8bd1                 mov edx, ecx
// 00532e90  52                   push edx
// 00532e91  ffd0                 call eax
// 00532e93  83c40c               add esp, 0xc
// 00532e96  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00532e9a  5e                   pop esi
// 00532e9b  8ac3                 mov al, bl
// 00532e9d  64890d00000000       mov dword ptr fs:[0], ecx
// 00532ea4  5b                   pop ebx
// 00532ea5  83c410               add esp, 0x10
// 00532ea8  c22c00               ret 0x2c
// copied from an identical function in another client (function ?run@Owner@@QAE_NUItem@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
union function_buffer { void* obj_ptr; double align; char buf[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
	void (*manager)(const function_buffer& in, function_buffer& out, functor_manager_operation_type op);
};
struct function_base {
	vtable_base* vtable;
	mutable function_buffer functor;
	function_base() : vtable(0) {}
};
struct function : function_base {
	~function() {
		if (vtable) {
			void (*m)(const function_buffer&, function_buffer&, functor_manager_operation_type) = vtable->manager;
			if (m) m(functor, functor, destroy_functor_tag);
		}
	}
	function(const function& f) {
		if (f.vtable) {
			vtable = f.vtable;
			vtable->manager(f.functor, functor, clone_functor_tag);
		}
	}
};
struct Item { int id; function f; };
struct Tag {};
class Owner {
public:
	bool doIt(Item item, int x, Tag t);
	bool run(Item item, int x);
};
bool Owner::run(Item item, int x)
{
	return doIt(item, x, Tag());
}