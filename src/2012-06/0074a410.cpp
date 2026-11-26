// from server: 100% by Xemicl
// roc 2012-06 0074a410  unit: RBX::ContentProvider  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0074a410
//
// 0074a410  6aff                 push -1
// 0074a412  6828acab00           push 0xabac28
// 0074a417  64a100000000         mov eax, dword ptr fs:[0]
// 0074a41d  50                   push eax
// 0074a41e  64892500000000       mov dword ptr fs:[0], esp
// 0074a425  51                   push ecx
// 0074a426  56                   push esi
// 0074a427  8bf1                 mov esi, ecx
// 0074a429  89742404             mov dword ptr [esp + 4], esi
// 0074a42d  8b4620               mov eax, dword ptr [esi + 0x20]
// 0074a430  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0074a438  85c0                 test eax, eax
// 0074a43a  7419                 je 0x74a455
// 0074a43c  8b00                 mov eax, dword ptr [eax]
// 0074a43e  8d4e28               lea ecx, [esi + 0x28]
// 0074a441  85c0                 test eax, eax
// 0074a443  7409                 je 0x74a44e
// 0074a445  6a02                 push 2
// 0074a447  51                   push ecx
// 0074a448  51                   push ecx
// 0074a449  ffd0                 call eax
// 0074a44b  83c40c               add esp, 0xc
// 0074a44e  c7462000000000       mov dword ptr [esi + 0x20], 0
// 0074a455  8bce                 mov ecx, esi
// 0074a457  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0074a45f  ff153c26b200         call dword ptr [0xb2263c]
// 0074a465  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0074a469  5e                   pop esi
// 0074a46a  64890d00000000       mov dword ptr fs:[0], ecx
// 0074a471  83c410               add esp, 0x10
// 0074a474  c3                   ret 
// copied from an identical function in another client (function ??1Item@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
union function_buffer { void* obj; __declspec(align(8)) char data[0x18]; };
typedef void (*manager_type)(const function_buffer&, function_buffer&, int);
struct vtable_base {
	manager_type manager;
	void clear(function_buffer& functor) { if (manager) manager(functor, functor, 2); }
};
struct function_base {
	vtable_base* vtable;
	function_buffer functor;
	~function_base() { if (vtable) { vtable->clear(functor); vtable = 0; } }
};
struct Item {
	std::string name;
	function_base func;
	~Item();
};
Item::~Item() {}