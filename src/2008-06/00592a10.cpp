// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00592a10  unit: ArchiveBinder  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00592a10
//
// 00592a10  55                   push ebp
// 00592a11  8bec                 mov ebp, esp
// 00592a13  6aff                 push -1
// 00592a15  68211d7d00           push 0x7d1d21
// 00592a1a  64a100000000         mov eax, dword ptr fs:[0]
// 00592a20  50                   push eax
// 00592a21  64892500000000       mov dword ptr fs:[0], esp
// 00592a28  83ec0c               sub esp, 0xc
// 00592a2b  53                   push ebx
// 00592a2c  56                   push esi
// 00592a2d  57                   push edi
// 00592a2e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00592a31  6a34                 push 0x34
// 00592a33  e8e8de1000           call 0x6a0920
// 00592a38  8bf0                 mov esi, eax
// 00592a3a  83c404               add esp, 4
// 00592a3d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00592a40  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00592a47  8975e8               mov dword ptr [ebp - 0x18], esi
// 00592a4a  c645fc01             mov byte ptr [ebp - 4], 1
// 00592a4e  85f6                 test esi, esi
// 00592a50  741b                 je 0x592a6d
// 00592a52  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00592a55  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00592a58  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00592a5b  50                   push eax
// 00592a5c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00592a5f  51                   push ecx
// 00592a60  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00592a63  52                   push edx
// 00592a64  50                   push eax
// 00592a65  51                   push ecx
// 00592a66  8bce                 mov ecx, esi
// 00592a68  e843ffffff           call 0x5929b0
// 00592a6d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00592a70  5f                   pop edi
// 00592a71  8bc6                 mov eax, esi
// 00592a73  5e                   pop esi
// 00592a74  64890d00000000       mov dword ptr fs:[0], ecx
// 00592a7b  5b                   pop ebx
// 00592a7c  8be5                 mov esp, ebp
// 00592a7e  5d                   pop ebp
// 00592a7f  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
