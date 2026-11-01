// from server: 100% by auto
// roc 2009-12 0073e9d0  unit: RBX::VCollectionService::?$FactoryProduct  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073e9d0
//
// 0073e9d0  55                   push ebp
// 0073e9d1  8bec                 mov ebp, esp
// 0073e9d3  6aff                 push -1
// 0073e9d5  68c1009500           push 0x9500c1
// 0073e9da  64a100000000         mov eax, dword ptr fs:[0]
// 0073e9e0  50                   push eax
// 0073e9e1  64892500000000       mov dword ptr fs:[0], esp
// 0073e9e8  83ec0c               sub esp, 0xc
// 0073e9eb  53                   push ebx
// 0073e9ec  56                   push esi
// 0073e9ed  57                   push edi
// 0073e9ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 0073e9f1  6a34                 push 0x34
// 0073e9f3  e8684e0b00           call 0x7f3860
// 0073e9f8  8bf0                 mov esi, eax
// 0073e9fa  83c404               add esp, 4
// 0073e9fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 0073ea00  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0073ea07  8975e8               mov dword ptr [ebp - 0x18], esi
// 0073ea0a  c645fc01             mov byte ptr [ebp - 4], 1
// 0073ea0e  85f6                 test esi, esi
// 0073ea10  741b                 je 0x73ea2d
// 0073ea12  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0073ea15  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0073ea18  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0073ea1b  50                   push eax
// 0073ea1c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0073ea1f  51                   push ecx
// 0073ea20  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0073ea23  52                   push edx
// 0073ea24  50                   push eax
// 0073ea25  51                   push ecx
// 0073ea26  8bce                 mov ecx, esi
// 0073ea28  e8c321faff           call 0x6e0bf0
// 0073ea2d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0073ea30  5f                   pop edi
// 0073ea31  8bc6                 mov eax, esi
// 0073ea33  5e                   pop esi
// 0073ea34  64890d00000000       mov dword ptr fs:[0], ecx
// 0073ea3b  5b                   pop ebx
// 0073ea3c  8be5                 mov esp, ebp
// 0073ea3e  5d                   pop ebp
// 0073ea3f  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
