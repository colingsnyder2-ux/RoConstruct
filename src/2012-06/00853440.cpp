// from server: 100% by auto
// roc 2012-06 00853440  unit: RBX::LuaStatsItem  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00853440
//
// 00853440  55                   push ebp
// 00853441  8bec                 mov ebp, esp
// 00853443  6aff                 push -1
// 00853445  6841dfac00           push 0xacdf41
// 0085344a  64a100000000         mov eax, dword ptr fs:[0]
// 00853450  50                   push eax
// 00853451  64892500000000       mov dword ptr fs:[0], esp
// 00853458  83ec0c               sub esp, 0xc
// 0085345b  53                   push ebx
// 0085345c  56                   push esi
// 0085345d  57                   push edi
// 0085345e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00853461  6a3c                 push 0x3c
// 00853463  e8b2ec1200           call 0x98211a
// 00853468  8bf0                 mov esi, eax
// 0085346a  83c404               add esp, 4
// 0085346d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00853470  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00853477  8975e8               mov dword ptr [ebp - 0x18], esi
// 0085347a  c645fc01             mov byte ptr [ebp - 4], 1
// 0085347e  85f6                 test esi, esi
// 00853480  741b                 je 0x85349d
// 00853482  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00853485  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00853488  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0085348b  50                   push eax
// 0085348c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0085348f  51                   push ecx
// 00853490  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00853493  52                   push edx
// 00853494  50                   push eax
// 00853495  51                   push ecx
// 00853496  8bce                 mov ecx, esi
// 00853498  e8f3feffff           call 0x853390
// 0085349d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008534a0  5f                   pop edi
// 008534a1  8bc6                 mov eax, esi
// 008534a3  5e                   pop esi
// 008534a4  64890d00000000       mov dword ptr fs:[0], ecx
// 008534ab  5b                   pop ebx
// 008534ac  8be5                 mov esp, ebp
// 008534ae  5d                   pop ebp
// 008534af  c21400               ret 0x14
// standard library map_str<pod16> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
