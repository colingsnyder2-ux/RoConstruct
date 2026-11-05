// from server: 100% by auto
// roc 2007-08 00583510  unit: RBX::VHat::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583510
//
// 00583510  55                   push ebp
// 00583511  8bec                 mov ebp, esp
// 00583513  6aff                 push -1
// 00583515  68015e7500           push 0x755e01
// 0058351a  64a100000000         mov eax, dword ptr fs:[0]
// 00583520  50                   push eax
// 00583521  64892500000000       mov dword ptr fs:[0], esp
// 00583528  83ec0c               sub esp, 0xc
// 0058352b  53                   push ebx
// 0058352c  56                   push esi
// 0058352d  57                   push edi
// 0058352e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00583531  6a30                 push 0x30
// 00583533  e8bec90a00           call 0x62fef6
// 00583538  8bf0                 mov esi, eax
// 0058353a  83c404               add esp, 4
// 0058353d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00583540  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00583547  8975e8               mov dword ptr [ebp - 0x18], esi
// 0058354a  85f6                 test esi, esi
// 0058354c  c645fc01             mov byte ptr [ebp - 4], 1
// 00583550  7430                 je 0x583582
// 00583552  8b4508               mov eax, dword ptr [ebp + 8]
// 00583555  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00583558  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0058355b  8906                 mov dword ptr [esi], eax
// 0058355d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00583560  894e04               mov dword ptr [esi + 4], ecx
// 00583563  895608               mov dword ptr [esi + 8], edx
// 00583566  8b08                 mov ecx, dword ptr [eax]
// 00583568  83c004               add eax, 4
// 0058356b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0058356e  50                   push eax
// 0058356f  8d4e10               lea ecx, [esi + 0x10]
// 00583572  ff159ce67700         call dword ptr [0x77e69c]
// 00583578  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0058357b  88562c               mov byte ptr [esi + 0x2c], dl
// 0058357e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00583582  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00583585  5f                   pop edi
// 00583586  8bc6                 mov eax, esi
// 00583588  5e                   pop esi
// 00583589  64890d00000000       mov dword ptr fs:[0], ecx
// 00583590  5b                   pop ebx
// 00583591  8be5                 mov esp, ebp
// 00583593  5d                   pop ebp
// 00583594  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
