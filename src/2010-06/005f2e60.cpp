// from server: 100% by auto
// roc 2010-06 005f2e60  unit: ArchiveBinder  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f2e60
//
// 005f2e60  55                   push ebp
// 005f2e61  8bec                 mov ebp, esp
// 005f2e63  6aff                 push -1
// 005f2e65  68c1879900           push 0x9987c1
// 005f2e6a  64a100000000         mov eax, dword ptr fs:[0]
// 005f2e70  50                   push eax
// 005f2e71  64892500000000       mov dword ptr fs:[0], esp
// 005f2e78  83ec0c               sub esp, 0xc
// 005f2e7b  53                   push ebx
// 005f2e7c  56                   push esi
// 005f2e7d  57                   push edi
// 005f2e7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f2e81  6a34                 push 0x34
// 005f2e83  e8184b1b00           call 0x7a79a0
// 005f2e88  8bf0                 mov esi, eax
// 005f2e8a  83c404               add esp, 4
// 005f2e8d  8975ec               mov dword ptr [ebp - 0x14], esi
// 005f2e90  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f2e97  8975e8               mov dword ptr [ebp - 0x18], esi
// 005f2e9a  c645fc01             mov byte ptr [ebp - 4], 1
// 005f2e9e  85f6                 test esi, esi
// 005f2ea0  741b                 je 0x5f2ebd
// 005f2ea2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005f2ea5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005f2ea8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005f2eab  50                   push eax
// 005f2eac  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005f2eaf  51                   push ecx
// 005f2eb0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005f2eb3  52                   push edx
// 005f2eb4  50                   push eax
// 005f2eb5  51                   push ecx
// 005f2eb6  8bce                 mov ecx, esi
// 005f2eb8  e843ffffff           call 0x5f2e00
// 005f2ebd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005f2ec0  5f                   pop edi
// 005f2ec1  8bc6                 mov eax, esi
// 005f2ec3  5e                   pop esi
// 005f2ec4  64890d00000000       mov dword ptr fs:[0], ecx
// 005f2ecb  5b                   pop ebx
// 005f2ecc  8be5                 mov esp, ebp
// 005f2ece  5d                   pop ebp
// 005f2ecf  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
