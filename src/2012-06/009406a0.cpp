// from server: 100% by auto
// roc 2012-06 009406a0  unit: RBX::PlayerChatLine  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009406a0
//
// 009406a0  55                   push ebp
// 009406a1  8bec                 mov ebp, esp
// 009406a3  6aff                 push -1
// 009406a5  68b191ad00           push 0xad91b1
// 009406aa  64a100000000         mov eax, dword ptr fs:[0]
// 009406b0  50                   push eax
// 009406b1  64892500000000       mov dword ptr fs:[0], esp
// 009406b8  83ec0c               sub esp, 0xc
// 009406bb  53                   push ebx
// 009406bc  56                   push esi
// 009406bd  57                   push edi
// 009406be  8965f0               mov dword ptr [ebp - 0x10], esp
// 009406c1  6a40                 push 0x40
// 009406c3  e8521a0400           call 0x98211a
// 009406c8  8bf0                 mov esi, eax
// 009406ca  83c404               add esp, 4
// 009406cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 009406d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 009406d7  8975e8               mov dword ptr [ebp - 0x18], esi
// 009406da  c645fc01             mov byte ptr [ebp - 4], 1
// 009406de  85f6                 test esi, esi
// 009406e0  741b                 je 0x9406fd
// 009406e2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 009406e5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 009406e8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 009406eb  50                   push eax
// 009406ec  8b450c               mov eax, dword ptr [ebp + 0xc]
// 009406ef  51                   push ecx
// 009406f0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 009406f3  52                   push edx
// 009406f4  50                   push eax
// 009406f5  51                   push ecx
// 009406f6  8bce                 mov ecx, esi
// 009406f8  e8a3fbffff           call 0x9402a0
// 009406fd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00940700  5f                   pop edi
// 00940701  8bc6                 mov eax, esi
// 00940703  5e                   pop esi
// 00940704  64890d00000000       mov dword ptr fs:[0], ecx
// 0094070b  5b                   pop ebx
// 0094070c  8be5                 mov esp, ebp
// 0094070e  5d                   pop ebp
// 0094070f  c21400               ret 0x14
// standard library map_str<pod20> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
