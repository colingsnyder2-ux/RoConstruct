// from server: 100% by auto
// roc 2011-06 007834f0  unit: RBX::Tasks::VExclusive::?$sp_counted_impl_p  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007834f0
//
// 007834f0  55                   push ebp
// 007834f1  8bec                 mov ebp, esp
// 007834f3  6aff                 push -1
// 007834f5  68b1b89f00           push 0x9fb8b1
// 007834fa  64a100000000         mov eax, dword ptr fs:[0]
// 00783500  50                   push eax
// 00783501  64892500000000       mov dword ptr fs:[0], esp
// 00783508  83ec0c               sub esp, 0xc
// 0078350b  53                   push ebx
// 0078350c  56                   push esi
// 0078350d  57                   push edi
// 0078350e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00783511  6a3c                 push 0x3c
// 00783513  e8466b0800           call 0x80a05e
// 00783518  8bf0                 mov esi, eax
// 0078351a  83c404               add esp, 4
// 0078351d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00783520  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00783527  8975e8               mov dword ptr [ebp - 0x18], esi
// 0078352a  c645fc01             mov byte ptr [ebp - 4], 1
// 0078352e  85f6                 test esi, esi
// 00783530  741b                 je 0x78354d
// 00783532  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00783535  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00783538  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0078353b  50                   push eax
// 0078353c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0078353f  51                   push ecx
// 00783540  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00783543  52                   push edx
// 00783544  50                   push eax
// 00783545  51                   push ecx
// 00783546  8bce                 mov ecx, esi
// 00783548  e823ffffff           call 0x783470
// 0078354d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00783550  5f                   pop edi
// 00783551  8bc6                 mov eax, esi
// 00783553  5e                   pop esi
// 00783554  64890d00000000       mov dword ptr fs:[0], ecx
// 0078355b  5b                   pop ebx
// 0078355c  8be5                 mov esp, ebp
// 0078355e  5d                   pop ebp
// 0078355f  c21400               ret 0x14
// standard library map_str<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
