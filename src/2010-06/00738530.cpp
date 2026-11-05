// from server: 100% by auto
// roc 2010-06 00738530  unit: seg_00730000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00738530
//
// 00738530  55                   push ebp
// 00738531  8bec                 mov ebp, esp
// 00738533  6aff                 push -1
// 00738535  6801919a00           push 0x9a9101
// 0073853a  64a100000000         mov eax, dword ptr fs:[0]
// 00738540  50                   push eax
// 00738541  64892500000000       mov dword ptr fs:[0], esp
// 00738548  83ec0c               sub esp, 0xc
// 0073854b  53                   push ebx
// 0073854c  56                   push esi
// 0073854d  57                   push edi
// 0073854e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00738551  6a3c                 push 0x3c
// 00738553  e848f40600           call 0x7a79a0
// 00738558  8bf0                 mov esi, eax
// 0073855a  83c404               add esp, 4
// 0073855d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00738560  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00738567  8975e8               mov dword ptr [ebp - 0x18], esi
// 0073856a  c645fc01             mov byte ptr [ebp - 4], 1
// 0073856e  85f6                 test esi, esi
// 00738570  741b                 je 0x73858d
// 00738572  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00738575  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00738578  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0073857b  50                   push eax
// 0073857c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0073857f  51                   push ecx
// 00738580  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00738583  52                   push edx
// 00738584  50                   push eax
// 00738585  51                   push ecx
// 00738586  8bce                 mov ecx, esi
// 00738588  e823ffffff           call 0x7384b0
// 0073858d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00738590  5f                   pop edi
// 00738591  8bc6                 mov eax, esi
// 00738593  5e                   pop esi
// 00738594  64890d00000000       mov dword ptr fs:[0], ecx
// 0073859b  5b                   pop ebx
// 0073859c  8be5                 mov esp, ebp
// 0073859e  5d                   pop ebp
// 0073859f  c21400               ret 0x14
// standard library map_str<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
