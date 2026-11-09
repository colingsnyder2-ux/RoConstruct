// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 0058d860  unit: RBX::ChangeHistoryService  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058d860
//
// 0058d860  55                   push ebp
// 0058d861  8bec                 mov ebp, esp
// 0058d863  6aff                 push -1
// 0058d865  6821197d00           push 0x7d1921
// 0058d86a  64a100000000         mov eax, dword ptr fs:[0]
// 0058d870  50                   push eax
// 0058d871  64892500000000       mov dword ptr fs:[0], esp
// 0058d878  83ec0c               sub esp, 0xc
// 0058d87b  53                   push ebx
// 0058d87c  56                   push esi
// 0058d87d  57                   push edi
// 0058d87e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0058d881  6a48                 push 0x48
// 0058d883  e898301100           call 0x6a0920
// 0058d888  8bf0                 mov esi, eax
// 0058d88a  83c404               add esp, 4
// 0058d88d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0058d890  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0058d897  8975e8               mov dword ptr [ebp - 0x18], esi
// 0058d89a  c645fc01             mov byte ptr [ebp - 4], 1
// 0058d89e  85f6                 test esi, esi
// 0058d8a0  7427                 je 0x58d8c9
// 0058d8a2  8b4508               mov eax, dword ptr [ebp + 8]
// 0058d8a5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0058d8a8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0058d8ab  8906                 mov dword ptr [esi], eax
// 0058d8ad  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0058d8b0  894e04               mov dword ptr [esi + 4], ecx
// 0058d8b3  50                   push eax
// 0058d8b4  8d4e0c               lea ecx, [esi + 0xc]
// 0058d8b7  895608               mov dword ptr [esi + 8], edx
// 0058d8ba  e891fbffff           call 0x58d450
// 0058d8bf  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0058d8c2  884e44               mov byte ptr [esi + 0x44], cl
// 0058d8c5  c6464500             mov byte ptr [esi + 0x45], 0
// 0058d8c9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0058d8cc  5f                   pop edi
// 0058d8cd  8bc6                 mov eax, esi
// 0058d8cf  5e                   pop esi
// 0058d8d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0058d8d7  5b                   pop ebx
// 0058d8d8  8be5                 mov esp, ebp
// 0058d8da  5d                   pop ebp
// 0058d8db  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
