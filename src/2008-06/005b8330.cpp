// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 005b8330  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b8330
//
// 005b8330  55                   push ebp
// 005b8331  8bec                 mov ebp, esp
// 005b8333  6aff                 push -1
// 005b8335  68a13a7d00           push 0x7d3aa1
// 005b833a  64a100000000         mov eax, dword ptr fs:[0]
// 005b8340  50                   push eax
// 005b8341  64892500000000       mov dword ptr fs:[0], esp
// 005b8348  83ec0c               sub esp, 0xc
// 005b834b  53                   push ebx
// 005b834c  56                   push esi
// 005b834d  57                   push edi
// 005b834e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005b8351  6a38                 push 0x38
// 005b8353  e8c8850e00           call 0x6a0920
// 005b8358  8bf0                 mov esi, eax
// 005b835a  83c404               add esp, 4
// 005b835d  8975ec               mov dword ptr [ebp - 0x14], esi
// 005b8360  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005b8367  8975e8               mov dword ptr [ebp - 0x18], esi
// 005b836a  c645fc01             mov byte ptr [ebp - 4], 1
// 005b836e  85f6                 test esi, esi
// 005b8370  741b                 je 0x5b838d
// 005b8372  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005b8375  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005b8378  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005b837b  50                   push eax
// 005b837c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005b837f  51                   push ecx
// 005b8380  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005b8383  52                   push edx
// 005b8384  50                   push eax
// 005b8385  51                   push ecx
// 005b8386  8bce                 mov ecx, esi
// 005b8388  e853f5ffff           call 0x5b78e0
// 005b838d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005b8390  5f                   pop edi
// 005b8391  8bc6                 mov eax, esi
// 005b8393  5e                   pop esi
// 005b8394  64890d00000000       mov dword ptr fs:[0], ecx
// 005b839b  5b                   pop ebx
// 005b839c  8be5                 mov esp, ebp
// 005b839e  5d                   pop ebp
// 005b839f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
