// from server: 100% by auto
// roc 2010-06 004185b0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004185b0
//
// 004185b0  53                   push ebx
// 004185b1  8bd9                 mov ebx, ecx
// 004185b3  56                   push esi
// 004185b4  8b730c               mov esi, dword ptr [ebx + 0xc]
// 004185b7  85f6                 test esi, esi
// 004185b9  7424                 je 0x4185df
// 004185bb  57                   push edi
// 004185bc  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004185bf  3bf7                 cmp esi, edi
// 004185c1  740f                 je 0x4185d2
// 004185c3  8bce                 mov ecx, esi
// 004185c5  ff1500a49e00         call dword ptr [0x9ea400]
// 004185cb  83c61c               add esi, 0x1c
// 004185ce  3bf7                 cmp esi, edi
// 004185d0  75f1                 jne 0x4185c3
// 004185d2  8b430c               mov eax, dword ptr [ebx + 0xc]
// 004185d5  50                   push eax
// 004185d6  e8bff33800           call 0x7a799a
// 004185db  83c404               add esp, 4
// 004185de  5f                   pop edi
// 004185df  5e                   pop esi
// 004185e0  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 004185e7  c7431000000000       mov dword ptr [ebx + 0x10], 0
// 004185ee  c7431400000000       mov dword ptr [ebx + 0x14], 0
// 004185f5  5b                   pop ebx
// 004185f6  c3                   ret 
// standard library vector<string> (function ?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
