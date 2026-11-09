// from server: 100% by auto
// roc 2009-12 00418600  unit: RBX::VTool::?$FactoryProduct::Creator  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00418600
//
// 00418600  53                   push ebx
// 00418601  8bd9                 mov ebx, ecx
// 00418603  56                   push esi
// 00418604  8b730c               mov esi, dword ptr [ebx + 0xc]
// 00418607  85f6                 test esi, esi
// 00418609  7424                 je 0x41862f
// 0041860b  57                   push edi
// 0041860c  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0041860f  3bf7                 cmp esi, edi
// 00418611  740f                 je 0x418622
// 00418613  8bce                 mov ecx, esi
// 00418615  ff15e4b69800         call dword ptr [0x98b6e4]
// 0041861b  83c61c               add esi, 0x1c
// 0041861e  3bf7                 cmp esi, edi
// 00418620  75f1                 jne 0x418613
// 00418622  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00418625  50                   push eax
// 00418626  e82fb23d00           call 0x7f385a
// 0041862b  83c404               add esp, 4
// 0041862e  5f                   pop edi
// 0041862f  5e                   pop esi
// 00418630  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 00418637  c7431000000000       mov dword ptr [ebx + 0x10], 0
// 0041863e  c7431400000000       mov dword ptr [ebx + 0x14], 0
// 00418645  5b                   pop ebx
// 00418646  c3                   ret 
// standard library vector<string> (function ?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
