// from server: 100% by auto
// roc 2011-06 0059f970  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0059f970
//
// 0059f970  55                   push ebp
// 0059f971  8bec                 mov ebp, esp
// 0059f973  6aff                 push -1
// 0059f975  6861109e00           push 0x9e1061
// 0059f97a  64a100000000         mov eax, dword ptr fs:[0]
// 0059f980  50                   push eax
// 0059f981  64892500000000       mov dword ptr fs:[0], esp
// 0059f988  83ec0c               sub esp, 0xc
// 0059f98b  53                   push ebx
// 0059f98c  56                   push esi
// 0059f98d  57                   push edi
// 0059f98e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0059f991  6a38                 push 0x38
// 0059f993  e8c6a62600           call 0x80a05e
// 0059f998  8bf0                 mov esi, eax
// 0059f99a  83c404               add esp, 4
// 0059f99d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0059f9a0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0059f9a7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0059f9aa  c645fc01             mov byte ptr [ebp - 4], 1
// 0059f9ae  85f6                 test esi, esi
// 0059f9b0  741b                 je 0x59f9cd
// 0059f9b2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 0059f9b5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0059f9b8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0059f9bb  50                   push eax
// 0059f9bc  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0059f9bf  51                   push ecx
// 0059f9c0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0059f9c3  52                   push edx
// 0059f9c4  50                   push eax
// 0059f9c5  51                   push ecx
// 0059f9c6  8bce                 mov ecx, esi
// 0059f9c8  e863f8ffff           call 0x59f230
// 0059f9cd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0059f9d0  5f                   pop edi
// 0059f9d1  8bc6                 mov eax, esi
// 0059f9d3  5e                   pop esi
// 0059f9d4  64890d00000000       mov dword ptr fs:[0], ecx
// 0059f9db  5b                   pop ebx
// 0059f9dc  8be5                 mov esp, ebp
// 0059f9de  5d                   pop ebp
// 0059f9df  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
