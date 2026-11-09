// from server: 100% by auto
// roc 2008-06 00446110  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00446110
//
// 00446110  6aff                 push -1
// 00446112  68e8727d00           push 0x7d72e8
// 00446117  64a100000000         mov eax, dword ptr fs:[0]
// 0044611d  50                   push eax
// 0044611e  64892500000000       mov dword ptr fs:[0], esp
// 00446125  51                   push ecx
// 00446126  56                   push esi
// 00446127  8bf1                 mov esi, ecx
// 00446129  6a04                 push 4
// 0044612b  89742408             mov dword ptr [esp + 8], esi
// 0044612f  e8eca72500           call 0x6a0920
// 00446134  83c404               add esp, 4
// 00446137  85c0                 test eax, eax
// 00446139  7404                 je 0x44613f
// 0044613b  8930                 mov dword ptr [eax], esi
// 0044613d  eb02                 jmp 0x446141
// 0044613f  33c0                 xor eax, eax
// 00446141  8906                 mov dword ptr [esi], eax
// 00446143  8bce                 mov ecx, esi
// 00446145  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044614d  e87e721200           call 0x56d3d0
// 00446152  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00446156  894618               mov dword ptr [esi + 0x18], eax
// 00446159  c6401501             mov byte ptr [eax + 0x15], 1
// 0044615d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00446160  894004               mov dword ptr [eax + 4], eax
// 00446163  8b4618               mov eax, dword ptr [esi + 0x18]
// 00446166  8900                 mov dword ptr [eax], eax
// 00446168  8b4618               mov eax, dword ptr [esi + 0x18]
// 0044616b  894008               mov dword ptr [eax + 8], eax
// 0044616e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00446175  8bc6                 mov eax, esi
// 00446177  5e                   pop esi
// 00446178  64890d00000000       mov dword ptr fs:[0], ecx
// 0044617f  83c410               add esp, 0x10
// 00446182  c20800               ret 8
// standard library set<pod8> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
