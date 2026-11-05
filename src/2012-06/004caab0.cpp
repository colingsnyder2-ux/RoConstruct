// from server: 100% by auto
// roc 2012-06 004caab0  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004caab0
//
// 004caab0  55                   push ebp
// 004caab1  8bec                 mov ebp, esp
// 004caab3  6aff                 push -1
// 004caab5  683165aa00           push 0xaa6531
// 004caaba  64a100000000         mov eax, dword ptr fs:[0]
// 004caac0  50                   push eax
// 004caac1  64892500000000       mov dword ptr fs:[0], esp
// 004caac8  83ec0c               sub esp, 0xc
// 004caacb  53                   push ebx
// 004caacc  56                   push esi
// 004caacd  57                   push edi
// 004caace  8965f0               mov dword ptr [ebp - 0x10], esp
// 004caad1  6a40                 push 0x40
// 004caad3  e842764b00           call 0x98211a
// 004caad8  8bf0                 mov esi, eax
// 004caada  83c404               add esp, 4
// 004caadd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004caae0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004caae7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004caaea  c645fc01             mov byte ptr [ebp - 4], 1
// 004caaee  85f6                 test esi, esi
// 004caaf0  7436                 je 0x4cab28
// 004caaf2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004caaf5  8b4508               mov eax, dword ptr [ebp + 8]
// 004caaf8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004caafb  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004caafe  894e04               mov dword ptr [esi + 4], ecx
// 004cab01  8d7e10               lea edi, [esi + 0x10]
// 004cab04  53                   push ebx
// 004cab05  8bcf                 mov ecx, edi
// 004cab07  8906                 mov dword ptr [esi], eax
// 004cab09  895608               mov dword ptr [esi + 8], edx
// 004cab0c  ff154426b200         call dword ptr [0xb22644]
// 004cab12  8b4320               mov eax, dword ptr [ebx + 0x20]
// 004cab15  8a5518               mov dl, byte ptr [ebp + 0x18]
// 004cab18  894720               mov dword ptr [edi + 0x20], eax
// 004cab1b  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 004cab1e  894f24               mov dword ptr [edi + 0x24], ecx
// 004cab21  885638               mov byte ptr [esi + 0x38], dl
// 004cab24  c6463900             mov byte ptr [esi + 0x39], 0
// 004cab28  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004cab2b  5f                   pop edi
// 004cab2c  8bc6                 mov eax, esi
// 004cab2e  5e                   pop esi
// 004cab2f  64890d00000000       mov dword ptr fs:[0], ecx
// 004cab36  5b                   pop ebx
// 004cab37  8be5                 mov esp, ebp
// 004cab39  5d                   pop ebp
// 004cab3a  c21400               ret 0x14
// standard library map_str<i64> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_JU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_JU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_J@2@D@Z)

// stl: map_str<i64>
typedef __int64 E;
#include <map>
#include <string>
template class std::map<std::string, E>;
