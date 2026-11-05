// from server: 100% by auto
// roc 2011-06 006753a0  unit: RBX::VVisit::?$BoundFuncDesc  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006753a0
//
// 006753a0  55                   push ebp
// 006753a1  8bec                 mov ebp, esp
// 006753a3  6aff                 push -1
// 006753a5  68a1e59e00           push 0x9ee5a1
// 006753aa  64a100000000         mov eax, dword ptr fs:[0]
// 006753b0  50                   push eax
// 006753b1  64892500000000       mov dword ptr fs:[0], esp
// 006753b8  83ec0c               sub esp, 0xc
// 006753bb  53                   push ebx
// 006753bc  56                   push esi
// 006753bd  57                   push edi
// 006753be  8965f0               mov dword ptr [ebp - 0x10], esp
// 006753c1  6a34                 push 0x34
// 006753c3  e8964c1900           call 0x80a05e
// 006753c8  8bf0                 mov esi, eax
// 006753ca  83c404               add esp, 4
// 006753cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 006753d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006753d7  8975e8               mov dword ptr [ebp - 0x18], esi
// 006753da  c645fc01             mov byte ptr [ebp - 4], 1
// 006753de  85f6                 test esi, esi
// 006753e0  741b                 je 0x6753fd
// 006753e2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006753e5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 006753e8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006753eb  50                   push eax
// 006753ec  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006753ef  51                   push ecx
// 006753f0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006753f3  52                   push edx
// 006753f4  50                   push eax
// 006753f5  51                   push ecx
// 006753f6  8bce                 mov ecx, esi
// 006753f8  e853fbffff           call 0x674f50
// 006753fd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00675400  5f                   pop edi
// 00675401  8bc6                 mov eax, esi
// 00675403  5e                   pop esi
// 00675404  64890d00000000       mov dword ptr fs:[0], ecx
// 0067540b  5b                   pop ebx
// 0067540c  8be5                 mov esp, ebp
// 0067540e  5d                   pop ebp
// 0067540f  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
