// from server: 100% by auto
// roc 2010-06 006400d0  unit: RBX::VVisit::?$BoundFuncDesc  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006400d0
//
// 006400d0  55                   push ebp
// 006400d1  8bec                 mov ebp, esp
// 006400d3  6aff                 push -1
// 006400d5  68f1ca9900           push 0x99caf1
// 006400da  64a100000000         mov eax, dword ptr fs:[0]
// 006400e0  50                   push eax
// 006400e1  64892500000000       mov dword ptr fs:[0], esp
// 006400e8  83ec0c               sub esp, 0xc
// 006400eb  53                   push ebx
// 006400ec  56                   push esi
// 006400ed  57                   push edi
// 006400ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 006400f1  6a38                 push 0x38
// 006400f3  e8a8781600           call 0x7a79a0
// 006400f8  8bf0                 mov esi, eax
// 006400fa  83c404               add esp, 4
// 006400fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 00640100  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00640107  8975e8               mov dword ptr [ebp - 0x18], esi
// 0064010a  c645fc01             mov byte ptr [ebp - 4], 1
// 0064010e  85f6                 test esi, esi
// 00640110  741b                 je 0x64012d
// 00640112  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00640115  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00640118  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0064011b  50                   push eax
// 0064011c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0064011f  51                   push ecx
// 00640120  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00640123  52                   push edx
// 00640124  50                   push eax
// 00640125  51                   push ecx
// 00640126  8bce                 mov ecx, esi
// 00640128  e833fcffff           call 0x63fd60
// 0064012d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00640130  5f                   pop edi
// 00640131  8bc6                 mov eax, esi
// 00640133  5e                   pop esi
// 00640134  64890d00000000       mov dword ptr fs:[0], ecx
// 0064013b  5b                   pop ebx
// 0064013c  8be5                 mov esp, ebp
// 0064013e  5d                   pop ebp
// 0064013f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
