// from server: 100% by auto
// roc 2009-12 004017b0  unit: CAboutRobloxDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004017b0
//
// 004017b0  6aff                 push -1
// 004017b2  68d9749200           push 0x9274d9
// 004017b7  64a100000000         mov eax, dword ptr fs:[0]
// 004017bd  50                   push eax
// 004017be  64892500000000       mov dword ptr fs:[0], esp
// 004017c5  51                   push ecx
// 004017c6  56                   push esi
// 004017c7  57                   push edi
// 004017c8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004017cc  8bf1                 mov esi, ecx
// 004017ce  57                   push edi
// 004017cf  8974240c             mov dword ptr [esp + 0xc], esi
// 004017d3  ff155cb79800         call dword ptr [0x98b75c]
// 004017d9  83c70c               add edi, 0xc
// 004017dc  57                   push edi
// 004017dd  8d4e0c               lea ecx, [esi + 0xc]
// 004017e0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004017e8  c70684f49900         mov dword ptr [esi], 0x99f484
// 004017ee  ff15f0b69800         call dword ptr [0x98b6f0]
// 004017f4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004017f8  5f                   pop edi
// 004017f9  8bc6                 mov eax, esi
// 004017fb  5e                   pop esi
// 004017fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00401803  83c410               add esp, 0x10
// 00401806  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
