// from server: 100% by auto
// roc 2007-03 004d0dc0  unit: seg_004d0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004d0dc0
//
// 004d0dc0  55                   push ebp
// 004d0dc1  8bec                 mov ebp, esp
// 004d0dc3  6aff                 push -1
// 004d0dc5  6871db7400           push 0x74db71
// 004d0dca  64a100000000         mov eax, dword ptr fs:[0]
// 004d0dd0  50                   push eax
// 004d0dd1  64892500000000       mov dword ptr fs:[0], esp
// 004d0dd8  83ec0c               sub esp, 0xc
// 004d0ddb  53                   push ebx
// 004d0ddc  56                   push esi
// 004d0ddd  57                   push edi
// 004d0dde  8965f0               mov dword ptr [ebp - 0x10], esp
// 004d0de1  6a38                 push 0x38
// 004d0de3  e820d31400           call 0x61e108
// 004d0de8  8bf0                 mov esi, eax
// 004d0dea  83c404               add esp, 4
// 004d0ded  8975ec               mov dword ptr [ebp - 0x14], esi
// 004d0df0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004d0df7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004d0dfa  85f6                 test esi, esi
// 004d0dfc  c645fc01             mov byte ptr [ebp - 4], 1
// 004d0e00  741b                 je 0x4d0e1d
// 004d0e02  8b4518               mov eax, dword ptr [ebp + 0x18]
// 004d0e05  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 004d0e08  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004d0e0b  50                   push eax
// 004d0e0c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004d0e0f  51                   push ecx
// 004d0e10  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004d0e13  52                   push edx
// 004d0e14  50                   push eax
// 004d0e15  51                   push ecx
// 004d0e16  8bce                 mov ecx, esi
// 004d0e18  e8a3ccffff           call 0x4cdac0
// 004d0e1d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004d0e20  5f                   pop edi
// 004d0e21  8bc6                 mov eax, esi
// 004d0e23  5e                   pop esi
// 004d0e24  64890d00000000       mov dword ptr fs:[0], ecx
// 004d0e2b  5b                   pop ebx
// 004d0e2c  8be5                 mov esp, ebp
// 004d0e2e  5d                   pop ebp
// 004d0e2f  c21400               ret 0x14
// 004d0e32  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004d0e35  52                   push edx
// 004d0e36  e8b5d21400           call 0x61e0f0
// 004d0e3b  83c404               add esp, 4
// 004d0e3e  6a00                 push 0
// 004d0e40  6a00                 push 0
// 004d0e42  e8e7e11400           call 0x61f02e
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
