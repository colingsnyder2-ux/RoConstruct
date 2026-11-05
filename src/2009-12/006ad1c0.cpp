// from server: 100% by auto
// roc 2009-12 006ad1c0  unit: RBX::Accoutrement  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad1c0
//
// 006ad1c0  55                   push ebp
// 006ad1c1  8bec                 mov ebp, esp
// 006ad1c3  6aff                 push -1
// 006ad1c5  6811829400           push 0x948211
// 006ad1ca  64a100000000         mov eax, dword ptr fs:[0]
// 006ad1d0  50                   push eax
// 006ad1d1  64892500000000       mov dword ptr fs:[0], esp
// 006ad1d8  83ec0c               sub esp, 0xc
// 006ad1db  53                   push ebx
// 006ad1dc  56                   push esi
// 006ad1dd  57                   push edi
// 006ad1de  8965f0               mov dword ptr [ebp - 0x10], esp
// 006ad1e1  6a30                 push 0x30
// 006ad1e3  e878661400           call 0x7f3860
// 006ad1e8  8bf0                 mov esi, eax
// 006ad1ea  83c404               add esp, 4
// 006ad1ed  8975ec               mov dword ptr [ebp - 0x14], esi
// 006ad1f0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006ad1f7  8975e8               mov dword ptr [ebp - 0x18], esi
// 006ad1fa  c645fc01             mov byte ptr [ebp - 4], 1
// 006ad1fe  85f6                 test esi, esi
// 006ad200  7430                 je 0x6ad232
// 006ad202  8b4508               mov eax, dword ptr [ebp + 8]
// 006ad205  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 006ad208  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006ad20b  8906                 mov dword ptr [esi], eax
// 006ad20d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 006ad210  894e04               mov dword ptr [esi + 4], ecx
// 006ad213  895608               mov dword ptr [esi + 8], edx
// 006ad216  8b08                 mov ecx, dword ptr [eax]
// 006ad218  83c004               add eax, 4
// 006ad21b  894e0c               mov dword ptr [esi + 0xc], ecx
// 006ad21e  50                   push eax
// 006ad21f  8d4e10               lea ecx, [esi + 0x10]
// 006ad222  ff15f0b69800         call dword ptr [0x98b6f0]
// 006ad228  8a5518               mov dl, byte ptr [ebp + 0x18]
// 006ad22b  88562c               mov byte ptr [esi + 0x2c], dl
// 006ad22e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 006ad232  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006ad235  5f                   pop edi
// 006ad236  8bc6                 mov eax, esi
// 006ad238  5e                   pop esi
// 006ad239  64890d00000000       mov dword ptr fs:[0], ecx
// 006ad240  5b                   pop ebx
// 006ad241  8be5                 mov esp, ebp
// 006ad243  5d                   pop ebp
// 006ad244  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
