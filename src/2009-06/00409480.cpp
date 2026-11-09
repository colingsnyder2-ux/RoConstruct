// from server: 100% by auto
// roc 2009-06 00409480  unit: std::logic_error  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409480
//
// 00409480  6aff                 push -1
// 00409482  6809ca8400           push 0x84ca09
// 00409487  64a100000000         mov eax, dword ptr fs:[0]
// 0040948d  50                   push eax
// 0040948e  64892500000000       mov dword ptr fs:[0], esp
// 00409495  51                   push ecx
// 00409496  56                   push esi
// 00409497  57                   push edi
// 00409498  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0040949c  8bf1                 mov esi, ecx
// 0040949e  57                   push edi
// 0040949f  8974240c             mov dword ptr [esp + 0xc], esi
// 004094a3  ff15b0e98900         call dword ptr [0x89e9b0]
// 004094a9  83c70c               add edi, 0xc
// 004094ac  57                   push edi
// 004094ad  8d4e0c               lea ecx, [esi + 0xc]
// 004094b0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004094b8  c7065cd28a00         mov dword ptr [esi], 0x8ad25c
// 004094be  ff15b8e48900         call dword ptr [0x89e4b8]
// 004094c4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004094c8  5f                   pop edi
// 004094c9  8bc6                 mov eax, esi
// 004094cb  5e                   pop esi
// 004094cc  64890d00000000       mov dword ptr fs:[0], ecx
// 004094d3  83c410               add esp, 0x10
// 004094d6  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
