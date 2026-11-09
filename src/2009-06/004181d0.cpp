// from server: 100% by auto
// roc 2009-06 004181d0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004181d0
//
// 004181d0  53                   push ebx
// 004181d1  8bd9                 mov ebx, ecx
// 004181d3  56                   push esi
// 004181d4  8b730c               mov esi, dword ptr [ebx + 0xc]
// 004181d7  85f6                 test esi, esi
// 004181d9  7424                 je 0x4181ff
// 004181db  57                   push edi
// 004181dc  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004181df  3bf7                 cmp esi, edi
// 004181e1  740f                 je 0x4181f2
// 004181e3  8bce                 mov ecx, esi
// 004181e5  ff15c4e48900         call dword ptr [0x89e4c4]
// 004181eb  83c61c               add esi, 0x1c
// 004181ee  3bf7                 cmp esi, edi
// 004181f0  75f1                 jne 0x4181e3
// 004181f2  8b430c               mov eax, dword ptr [ebx + 0xc]
// 004181f5  50                   push eax
// 004181f6  e837083000           call 0x718a32
// 004181fb  83c404               add esp, 4
// 004181fe  5f                   pop edi
// 004181ff  5e                   pop esi
// 00418200  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 00418207  c7431000000000       mov dword ptr [ebx + 0x10], 0
// 0041820e  c7431400000000       mov dword ptr [ebx + 0x14], 0
// 00418215  5b                   pop ebx
// 00418216  c3                   ret 
// standard library vector<string> (function ?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
