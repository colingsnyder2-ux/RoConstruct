// from server: 100% by auto
// roc 2009-12 00528ff0  unit: RBX::Reflection::N::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00528ff0
//
// 00528ff0  6aff                 push -1
// 00528ff2  68d8c59300           push 0x93c5d8
// 00528ff7  64a100000000         mov eax, dword ptr fs:[0]
// 00528ffd  50                   push eax
// 00528ffe  64892500000000       mov dword ptr fs:[0], esp
// 00529005  51                   push ecx
// 00529006  56                   push esi
// 00529007  8bf1                 mov esi, ecx
// 00529009  6a04                 push 4
// 0052900b  89742408             mov dword ptr [esp + 8], esi
// 0052900f  e84ca82c00           call 0x7f3860
// 00529014  83c404               add esp, 4
// 00529017  85c0                 test eax, eax
// 00529019  7404                 je 0x52901f
// 0052901b  8930                 mov dword ptr [eax], esi
// 0052901d  eb02                 jmp 0x529021
// 0052901f  33c0                 xor eax, eax
// 00529021  8906                 mov dword ptr [esi], eax
// 00529023  8bce                 mov ecx, esi
// 00529025  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0052902d  e8beb6f1ff           call 0x4446f0
// 00529032  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00529036  894618               mov dword ptr [esi + 0x18], eax
// 00529039  c6401501             mov byte ptr [eax + 0x15], 1
// 0052903d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00529040  894004               mov dword ptr [eax + 4], eax
// 00529043  8b4618               mov eax, dword ptr [esi + 0x18]
// 00529046  8900                 mov dword ptr [eax], eax
// 00529048  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052904b  894008               mov dword ptr [eax + 8], eax
// 0052904e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00529055  8bc6                 mov eax, esi
// 00529057  5e                   pop esi
// 00529058  64890d00000000       mov dword ptr fs:[0], ecx
// 0052905f  83c410               add esp, 0x10
// 00529062  c20800               ret 8
// standard library set<pod8> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
