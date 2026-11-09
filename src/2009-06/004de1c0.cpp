// from server: 100% by auto
// roc 2009-06 004de1c0  unit: RBX::Network::IdSerializer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004de1c0
//
// 004de1c0  55                   push ebp
// 004de1c1  8bec                 mov ebp, esp
// 004de1c3  6aff                 push -1
// 004de1c5  6801b98500           push 0x85b901
// 004de1ca  64a100000000         mov eax, dword ptr fs:[0]
// 004de1d0  50                   push eax
// 004de1d1  64892500000000       mov dword ptr fs:[0], esp
// 004de1d8  83ec0c               sub esp, 0xc
// 004de1db  53                   push ebx
// 004de1dc  56                   push esi
// 004de1dd  57                   push edi
// 004de1de  8965f0               mov dword ptr [ebp - 0x10], esp
// 004de1e1  6a30                 push 0x30
// 004de1e3  e850a82300           call 0x718a38
// 004de1e8  8bf0                 mov esi, eax
// 004de1ea  83c404               add esp, 4
// 004de1ed  8975ec               mov dword ptr [ebp - 0x14], esi
// 004de1f0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004de1f7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004de1fa  c645fc01             mov byte ptr [ebp - 4], 1
// 004de1fe  85f6                 test esi, esi
// 004de200  7430                 je 0x4de232
// 004de202  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004de205  8b4508               mov eax, dword ptr [ebp + 8]
// 004de208  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004de20b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004de20e  894e04               mov dword ptr [esi + 4], ecx
// 004de211  8d7e0c               lea edi, [esi + 0xc]
// 004de214  53                   push ebx
// 004de215  8bcf                 mov ecx, edi
// 004de217  8906                 mov dword ptr [esi], eax
// 004de219  895608               mov dword ptr [esi + 8], edx
// 004de21c  ff15b8e48900         call dword ptr [0x89e4b8]
// 004de222  8a431c               mov al, byte ptr [ebx + 0x1c]
// 004de225  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004de228  88471c               mov byte ptr [edi + 0x1c], al
// 004de22b  884e2c               mov byte ptr [esi + 0x2c], cl
// 004de22e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004de232  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004de235  5f                   pop edi
// 004de236  8bc6                 mov eax, esi
// 004de238  5e                   pop esi
// 004de239  64890d00000000       mov dword ptr fs:[0], ecx
// 004de240  5b                   pop ebx
// 004de241  8be5                 mov esp, ebp
// 004de243  5d                   pop ebp
// 004de244  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
