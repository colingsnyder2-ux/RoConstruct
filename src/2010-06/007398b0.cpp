// from server: 100% by auto
// roc 2010-06 007398b0  unit: seg_00730000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007398b0
//
// 007398b0  55                   push ebp
// 007398b1  8bec                 mov ebp, esp
// 007398b3  6aff                 push -1
// 007398b5  68e1919a00           push 0x9a91e1
// 007398ba  64a100000000         mov eax, dword ptr fs:[0]
// 007398c0  50                   push eax
// 007398c1  64892500000000       mov dword ptr fs:[0], esp
// 007398c8  83ec0c               sub esp, 0xc
// 007398cb  53                   push ebx
// 007398cc  56                   push esi
// 007398cd  57                   push edi
// 007398ce  8965f0               mov dword ptr [ebp - 0x10], esp
// 007398d1  6a30                 push 0x30
// 007398d3  e8c8e00600           call 0x7a79a0
// 007398d8  8bf0                 mov esi, eax
// 007398da  83c404               add esp, 4
// 007398dd  8975ec               mov dword ptr [ebp - 0x14], esi
// 007398e0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 007398e7  8975e8               mov dword ptr [ebp - 0x18], esi
// 007398ea  c645fc01             mov byte ptr [ebp - 4], 1
// 007398ee  85f6                 test esi, esi
// 007398f0  7430                 je 0x739922
// 007398f2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 007398f5  8b4508               mov eax, dword ptr [ebp + 8]
// 007398f8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 007398fb  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 007398fe  894e04               mov dword ptr [esi + 4], ecx
// 00739901  8d7e0c               lea edi, [esi + 0xc]
// 00739904  53                   push ebx
// 00739905  8bcf                 mov ecx, edi
// 00739907  8906                 mov dword ptr [esi], eax
// 00739909  895608               mov dword ptr [esi + 8], edx
// 0073990c  ff150ca49e00         call dword ptr [0x9ea40c]
// 00739912  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 00739915  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00739918  89471c               mov dword ptr [edi + 0x1c], eax
// 0073991b  884e2c               mov byte ptr [esi + 0x2c], cl
// 0073991e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00739922  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00739925  5f                   pop edi
// 00739926  8bc6                 mov eax, esi
// 00739928  5e                   pop esi
// 00739929  64890d00000000       mov dword ptr fs:[0], ecx
// 00739930  5b                   pop ebx
// 00739931  8be5                 mov esp, ebp
// 00739933  5d                   pop ebp
// 00739934  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
