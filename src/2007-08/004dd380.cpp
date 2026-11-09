// from server: 100% by auto
// roc 2007-08 004dd380  unit: seg_004d0000  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004dd380
//
// 004dd380  55                   push ebp
// 004dd381  8bec                 mov ebp, esp
// 004dd383  6aff                 push -1
// 004dd385  6821cd7400           push 0x74cd21
// 004dd38a  64a100000000         mov eax, dword ptr fs:[0]
// 004dd390  50                   push eax
// 004dd391  64892500000000       mov dword ptr fs:[0], esp
// 004dd398  83ec0c               sub esp, 0xc
// 004dd39b  53                   push ebx
// 004dd39c  56                   push esi
// 004dd39d  57                   push edi
// 004dd39e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004dd3a1  6a38                 push 0x38
// 004dd3a3  e84e2b1500           call 0x62fef6
// 004dd3a8  8bf0                 mov esi, eax
// 004dd3aa  83c404               add esp, 4
// 004dd3ad  8975ec               mov dword ptr [ebp - 0x14], esi
// 004dd3b0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004dd3b7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004dd3ba  85f6                 test esi, esi
// 004dd3bc  c645fc01             mov byte ptr [ebp - 4], 1
// 004dd3c0  741b                 je 0x4dd3dd
// 004dd3c2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004dd3c5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004dd3c8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004dd3cb  50                   push eax
// 004dd3cc  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004dd3cf  51                   push ecx
// 004dd3d0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004dd3d3  52                   push edx
// 004dd3d4  50                   push eax
// 004dd3d5  51                   push ecx
// 004dd3d6  8bce                 mov ecx, esi
// 004dd3d8  e8c3c7ffff           call 0x4d9ba0
// 004dd3dd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004dd3e0  5f                   pop edi
// 004dd3e1  8bc6                 mov eax, esi
// 004dd3e3  5e                   pop esi
// 004dd3e4  64890d00000000       mov dword ptr fs:[0], ecx
// 004dd3eb  5b                   pop ebx
// 004dd3ec  8be5                 mov esp, ebp
// 004dd3ee  5d                   pop ebp
// 004dd3ef  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
