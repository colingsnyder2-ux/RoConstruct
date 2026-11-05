// from server: 100% by auto
// roc 2007-08 00588cf0  unit: RBX::SoundChannel  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00588cf0
//
// 00588cf0  55                   push ebp
// 00588cf1  8bec                 mov ebp, esp
// 00588cf3  6aff                 push -1
// 00588cf5  68c1607500           push 0x7560c1
// 00588cfa  64a100000000         mov eax, dword ptr fs:[0]
// 00588d00  50                   push eax
// 00588d01  64892500000000       mov dword ptr fs:[0], esp
// 00588d08  83ec0c               sub esp, 0xc
// 00588d0b  53                   push ebx
// 00588d0c  56                   push esi
// 00588d0d  57                   push edi
// 00588d0e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00588d11  6a38                 push 0x38
// 00588d13  e8de710a00           call 0x62fef6
// 00588d18  8bf0                 mov esi, eax
// 00588d1a  83c404               add esp, 4
// 00588d1d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00588d20  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00588d27  8975e8               mov dword ptr [ebp - 0x18], esi
// 00588d2a  85f6                 test esi, esi
// 00588d2c  c645fc01             mov byte ptr [ebp - 4], 1
// 00588d30  741b                 je 0x588d4d
// 00588d32  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00588d35  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00588d38  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00588d3b  50                   push eax
// 00588d3c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00588d3f  51                   push ecx
// 00588d40  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00588d43  52                   push edx
// 00588d44  50                   push eax
// 00588d45  51                   push ecx
// 00588d46  8bce                 mov ecx, esi
// 00588d48  e8c3f8ffff           call 0x588610
// 00588d4d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00588d50  5f                   pop edi
// 00588d51  8bc6                 mov eax, esi
// 00588d53  5e                   pop esi
// 00588d54  64890d00000000       mov dword ptr fs:[0], ecx
// 00588d5b  5b                   pop ebx
// 00588d5c  8be5                 mov esp, ebp
// 00588d5e  5d                   pop ebp
// 00588d5f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
