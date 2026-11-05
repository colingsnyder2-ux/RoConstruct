// from server: 100% by auto
// roc 2007-08 0040a260  unit: VCApp::?$CComObject  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a260
//
// 0040a260  53                   push ebx
// 0040a261  8bd9                 mov ebx, ecx
// 0040a263  56                   push esi
// 0040a264  8b7304               mov esi, dword ptr [ebx + 4]
// 0040a267  85f6                 test esi, esi
// 0040a269  7424                 je 0x40a28f
// 0040a26b  57                   push edi
// 0040a26c  8b7b08               mov edi, dword ptr [ebx + 8]
// 0040a26f  3bf7                 cmp esi, edi
// 0040a271  740f                 je 0x40a282
// 0040a273  8bce                 mov ecx, esi
// 0040a275  ff15ace67700         call dword ptr [0x77e6ac]
// 0040a27b  83c61c               add esi, 0x1c
// 0040a27e  3bf7                 cmp esi, edi
// 0040a280  75f1                 jne 0x40a273
// 0040a282  8b4304               mov eax, dword ptr [ebx + 4]
// 0040a285  50                   push eax
// 0040a286  e8d7592200           call 0x62fc62
// 0040a28b  83c404               add esp, 4
// 0040a28e  5f                   pop edi
// 0040a28f  5e                   pop esi
// 0040a290  c7430400000000       mov dword ptr [ebx + 4], 0
// 0040a297  c7430800000000       mov dword ptr [ebx + 8], 0
// 0040a29e  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 0040a2a5  5b                   pop ebx
// 0040a2a6  c3                   ret 
// standard library vector<string> (function ?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
