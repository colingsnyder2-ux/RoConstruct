// from server: 100% by auto
// roc 2009-12 006bdce0  unit: CPropGrid::UpdateItemsJob  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bdce0
//
// 006bdce0  55                   push ebp
// 006bdce1  8bec                 mov ebp, esp
// 006bdce3  6aff                 push -1
// 006bdce5  68218c9400           push 0x948c21
// 006bdcea  64a100000000         mov eax, dword ptr fs:[0]
// 006bdcf0  50                   push eax
// 006bdcf1  64892500000000       mov dword ptr fs:[0], esp
// 006bdcf8  83ec0c               sub esp, 0xc
// 006bdcfb  53                   push ebx
// 006bdcfc  56                   push esi
// 006bdcfd  57                   push edi
// 006bdcfe  8965f0               mov dword ptr [ebp - 0x10], esp
// 006bdd01  6a38                 push 0x38
// 006bdd03  e8585b1300           call 0x7f3860
// 006bdd08  8bf0                 mov esi, eax
// 006bdd0a  83c404               add esp, 4
// 006bdd0d  8975ec               mov dword ptr [ebp - 0x14], esi
// 006bdd10  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006bdd17  8975e8               mov dword ptr [ebp - 0x18], esi
// 006bdd1a  c645fc01             mov byte ptr [ebp - 4], 1
// 006bdd1e  85f6                 test esi, esi
// 006bdd20  741b                 je 0x6bdd3d
// 006bdd22  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006bdd25  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 006bdd28  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006bdd2b  50                   push eax
// 006bdd2c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006bdd2f  51                   push ecx
// 006bdd30  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006bdd33  52                   push edx
// 006bdd34  50                   push eax
// 006bdd35  51                   push ecx
// 006bdd36  8bce                 mov ecx, esi
// 006bdd38  e833f7ffff           call 0x6bd470
// 006bdd3d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006bdd40  5f                   pop edi
// 006bdd41  8bc6                 mov eax, esi
// 006bdd43  5e                   pop esi
// 006bdd44  64890d00000000       mov dword ptr fs:[0], ecx
// 006bdd4b  5b                   pop ebx
// 006bdd4c  8be5                 mov esp, ebp
// 006bdd4e  5d                   pop ebp
// 006bdd4f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
