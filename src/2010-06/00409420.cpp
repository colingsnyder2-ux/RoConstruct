// from server: 100% by auto
// roc 2010-06 00409420  unit: std::logic_error  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00409420
//
// 00409420  6aff                 push -1
// 00409422  68198f9a00           push 0x9a8f19
// 00409427  64a100000000         mov eax, dword ptr fs:[0]
// 0040942d  50                   push eax
// 0040942e  64892500000000       mov dword ptr fs:[0], esp
// 00409435  51                   push ecx
// 00409436  56                   push esi
// 00409437  57                   push edi
// 00409438  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0040943c  8bf1                 mov esi, ecx
// 0040943e  57                   push edi
// 0040943f  8974240c             mov dword ptr [esp + 0xc], esi
// 00409443  ff1510a99e00         call dword ptr [0x9ea910]
// 00409449  83c70c               add edi, 0xc
// 0040944c  57                   push edi
// 0040944d  8d4e0c               lea ecx, [esi + 0xc]
// 00409450  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00409458  c7063009a000         mov dword ptr [esi], 0xa00930
// 0040945e  ff150ca49e00         call dword ptr [0x9ea40c]
// 00409464  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00409468  5f                   pop edi
// 00409469  8bc6                 mov eax, esi
// 0040946b  5e                   pop esi
// 0040946c  64890d00000000       mov dword ptr fs:[0], ecx
// 00409473  83c410               add esp, 0x10
// 00409476  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
