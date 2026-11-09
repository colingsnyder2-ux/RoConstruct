// from server: 100% by auto
// roc 2008-06 00671ae0  unit: RBX::AdornRbxGfx  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00671ae0
//
// 00671ae0  6aff                 push -1
// 00671ae2  68e8727d00           push 0x7d72e8
// 00671ae7  64a100000000         mov eax, dword ptr fs:[0]
// 00671aed  50                   push eax
// 00671aee  64892500000000       mov dword ptr fs:[0], esp
// 00671af5  51                   push ecx
// 00671af6  56                   push esi
// 00671af7  8bf1                 mov esi, ecx
// 00671af9  6a04                 push 4
// 00671afb  89742408             mov dword ptr [esp + 8], esi
// 00671aff  e81cee0200           call 0x6a0920
// 00671b04  83c404               add esp, 4
// 00671b07  85c0                 test eax, eax
// 00671b09  7404                 je 0x671b0f
// 00671b0b  8930                 mov dword ptr [eax], esi
// 00671b0d  eb02                 jmp 0x671b11
// 00671b0f  33c0                 xor eax, eax
// 00671b11  8906                 mov dword ptr [esi], eax
// 00671b13  8bce                 mov ecx, esi
// 00671b15  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00671b1d  e87e5df4ff           call 0x5b78a0
// 00671b22  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00671b26  894618               mov dword ptr [esi + 0x18], eax
// 00671b29  c6403501             mov byte ptr [eax + 0x35], 1
// 00671b2d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671b30  894004               mov dword ptr [eax + 4], eax
// 00671b33  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671b36  8900                 mov dword ptr [eax], eax
// 00671b38  8b4618               mov eax, dword ptr [esi + 0x18]
// 00671b3b  894008               mov dword ptr [eax + 8], eax
// 00671b3e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00671b45  8bc6                 mov eax, esi
// 00671b47  5e                   pop esi
// 00671b48  64890d00000000       mov dword ptr fs:[0], ecx
// 00671b4f  83c410               add esp, 0x10
// 00671b52  c20800               ret 8
// standard library set<pod40> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
