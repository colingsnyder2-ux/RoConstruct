// from server: 100% by auto
// roc 2010-06 005efd10  unit: RBX::ChangeHistoryService  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005efd10
//
// 005efd10  55                   push ebp
// 005efd11  8bec                 mov ebp, esp
// 005efd13  6aff                 push -1
// 005efd15  68f1849900           push 0x9984f1
// 005efd1a  64a100000000         mov eax, dword ptr fs:[0]
// 005efd20  50                   push eax
// 005efd21  64892500000000       mov dword ptr fs:[0], esp
// 005efd28  83ec0c               sub esp, 0xc
// 005efd2b  53                   push ebx
// 005efd2c  56                   push esi
// 005efd2d  57                   push edi
// 005efd2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005efd31  6a48                 push 0x48
// 005efd33  e8687c1b00           call 0x7a79a0
// 005efd38  8bf0                 mov esi, eax
// 005efd3a  83c404               add esp, 4
// 005efd3d  8975ec               mov dword ptr [ebp - 0x14], esi
// 005efd40  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005efd47  8975e8               mov dword ptr [ebp - 0x18], esi
// 005efd4a  c645fc01             mov byte ptr [ebp - 4], 1
// 005efd4e  85f6                 test esi, esi
// 005efd50  7427                 je 0x5efd79
// 005efd52  8b4508               mov eax, dword ptr [ebp + 8]
// 005efd55  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 005efd58  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005efd5b  8906                 mov dword ptr [esi], eax
// 005efd5d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005efd60  894e04               mov dword ptr [esi + 4], ecx
// 005efd63  50                   push eax
// 005efd64  8d4e0c               lea ecx, [esi + 0xc]
// 005efd67  895608               mov dword ptr [esi + 8], edx
// 005efd6a  e891fbffff           call 0x5ef900
// 005efd6f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 005efd72  884e44               mov byte ptr [esi + 0x44], cl
// 005efd75  c6464500             mov byte ptr [esi + 0x45], 0
// 005efd79  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005efd7c  5f                   pop edi
// 005efd7d  8bc6                 mov eax, esi
// 005efd7f  5e                   pop esi
// 005efd80  64890d00000000       mov dword ptr fs:[0], ecx
// 005efd87  5b                   pop ebx
// 005efd88  8be5                 mov esp, ebp
// 005efd8a  5d                   pop ebp
// 005efd8b  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
