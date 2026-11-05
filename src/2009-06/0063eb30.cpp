// from server: 100% by auto
// roc 2009-06 0063eb30  unit: RBX::Accoutrement  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063eb30
//
// 0063eb30  55                   push ebp
// 0063eb31  8bec                 mov ebp, esp
// 0063eb33  6aff                 push -1
// 0063eb35  6881a58600           push 0x86a581
// 0063eb3a  64a100000000         mov eax, dword ptr fs:[0]
// 0063eb40  50                   push eax
// 0063eb41  64892500000000       mov dword ptr fs:[0], esp
// 0063eb48  83ec0c               sub esp, 0xc
// 0063eb4b  53                   push ebx
// 0063eb4c  56                   push esi
// 0063eb4d  57                   push edi
// 0063eb4e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0063eb51  6a30                 push 0x30
// 0063eb53  e8e09e0d00           call 0x718a38
// 0063eb58  8bf0                 mov esi, eax
// 0063eb5a  83c404               add esp, 4
// 0063eb5d  8975ec               mov dword ptr [ebp - 0x14], esi
// 0063eb60  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0063eb67  8975e8               mov dword ptr [ebp - 0x18], esi
// 0063eb6a  c645fc01             mov byte ptr [ebp - 4], 1
// 0063eb6e  85f6                 test esi, esi
// 0063eb70  7430                 je 0x63eba2
// 0063eb72  8b4508               mov eax, dword ptr [ebp + 8]
// 0063eb75  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0063eb78  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0063eb7b  8906                 mov dword ptr [esi], eax
// 0063eb7d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0063eb80  894e04               mov dword ptr [esi + 4], ecx
// 0063eb83  895608               mov dword ptr [esi + 8], edx
// 0063eb86  8b08                 mov ecx, dword ptr [eax]
// 0063eb88  83c004               add eax, 4
// 0063eb8b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0063eb8e  50                   push eax
// 0063eb8f  8d4e10               lea ecx, [esi + 0x10]
// 0063eb92  ff15b8e48900         call dword ptr [0x89e4b8]
// 0063eb98  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0063eb9b  88562c               mov byte ptr [esi + 0x2c], dl
// 0063eb9e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 0063eba2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0063eba5  5f                   pop edi
// 0063eba6  8bc6                 mov eax, esi
// 0063eba8  5e                   pop esi
// 0063eba9  64890d00000000       mov dword ptr fs:[0], ecx
// 0063ebb0  5b                   pop ebx
// 0063ebb1  8be5                 mov esp, ebp
// 0063ebb3  5d                   pop ebp
// 0063ebb4  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
