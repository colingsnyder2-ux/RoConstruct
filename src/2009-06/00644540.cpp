// from server: 100% by auto
// roc 2009-06 00644540  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00644540
//
// 00644540  55                   push ebp
// 00644541  8bec                 mov ebp, esp
// 00644543  6aff                 push -1
// 00644545  6831a88600           push 0x86a831
// 0064454a  64a100000000         mov eax, dword ptr fs:[0]
// 00644550  50                   push eax
// 00644551  64892500000000       mov dword ptr fs:[0], esp
// 00644558  83ec0c               sub esp, 0xc
// 0064455b  53                   push ebx
// 0064455c  56                   push esi
// 0064455d  57                   push edi
// 0064455e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00644561  6a38                 push 0x38
// 00644563  e8d0440d00           call 0x718a38
// 00644568  8bf0                 mov esi, eax
// 0064456a  83c404               add esp, 4
// 0064456d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00644570  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00644577  8975e8               mov dword ptr [ebp - 0x18], esi
// 0064457a  c645fc01             mov byte ptr [ebp - 4], 1
// 0064457e  85f6                 test esi, esi
// 00644580  741b                 je 0x64459d
// 00644582  8b4518               mov eax, dword ptr [ebp + 0x18]
// 00644585  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00644588  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0064458b  50                   push eax
// 0064458c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0064458f  51                   push ecx
// 00644590  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00644593  52                   push edx
// 00644594  50                   push eax
// 00644595  51                   push ecx
// 00644596  8bce                 mov ecx, esi
// 00644598  e8d3f9ffff           call 0x643f70
// 0064459d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006445a0  5f                   pop edi
// 006445a1  8bc6                 mov eax, esi
// 006445a3  5e                   pop esi
// 006445a4  64890d00000000       mov dword ptr fs:[0], ecx
// 006445ab  5b                   pop ebx
// 006445ac  8be5                 mov esp, ebp
// 006445ae  5d                   pop ebp
// 006445af  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
