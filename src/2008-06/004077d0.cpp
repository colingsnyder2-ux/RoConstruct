// from server: 100% by auto
// roc 2008-06 004077d0  unit: VCApp::?$IObjectSafetyRobloxImpl  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004077d0
//
// 004077d0  53                   push ebx
// 004077d1  8bd9                 mov ebx, ecx
// 004077d3  56                   push esi
// 004077d4  8b730c               mov esi, dword ptr [ebx + 0xc]
// 004077d7  85f6                 test esi, esi
// 004077d9  7424                 je 0x4077ff
// 004077db  57                   push edi
// 004077dc  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 004077df  3bf7                 cmp esi, edi
// 004077e1  740f                 je 0x4077f2
// 004077e3  8bce                 mov ecx, esi
// 004077e5  ff1568248000         call dword ptr [0x802468]
// 004077eb  83c61c               add esi, 0x1c
// 004077ee  3bf7                 cmp esi, edi
// 004077f0  75f1                 jne 0x4077e3
// 004077f2  8b430c               mov eax, dword ptr [ebx + 0xc]
// 004077f5  50                   push eax
// 004077f6  e87f8e2900           call 0x6a067a
// 004077fb  83c404               add esp, 4
// 004077fe  5f                   pop edi
// 004077ff  5e                   pop esi
// 00407800  c7430c00000000       mov dword ptr [ebx + 0xc], 0
// 00407807  c7431000000000       mov dword ptr [ebx + 0x10], 0
// 0040780e  c7431400000000       mov dword ptr [ebx + 0x14], 0
// 00407815  5b                   pop ebx
// 00407816  c3                   ret 
// standard library vector<string> (function ?_Tidy@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXXZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
