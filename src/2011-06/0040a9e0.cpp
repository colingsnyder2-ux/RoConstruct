// from server: 100% by auto
// roc 2011-06 0040a9e0  unit: std::runtime_error  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a9e0
//
// 0040a9e0  6aff                 push -1
// 0040a9e2  6879cf9c00           push 0x9ccf79
// 0040a9e7  64a100000000         mov eax, dword ptr fs:[0]
// 0040a9ed  50                   push eax
// 0040a9ee  64892500000000       mov dword ptr fs:[0], esp
// 0040a9f5  51                   push ecx
// 0040a9f6  56                   push esi
// 0040a9f7  57                   push edi
// 0040a9f8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0040a9fc  8bf1                 mov esi, ecx
// 0040a9fe  57                   push edi
// 0040a9ff  8974240c             mov dword ptr [esp + 0xc], esi
// 0040aa03  ff15580aa400         call dword ptr [0xa40a58]
// 0040aa09  83c70c               add edi, 0xc
// 0040aa0c  57                   push edi
// 0040aa0d  8d4e0c               lea ecx, [esi + 0xc]
// 0040aa10  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040aa18  c70600bfa500         mov dword ptr [esi], 0xa5bf00
// 0040aa1e  ff15c804a400         call dword ptr [0xa404c8]
// 0040aa24  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040aa28  5f                   pop edi
// 0040aa29  8bc6                 mov eax, esi
// 0040aa2b  5e                   pop esi
// 0040aa2c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040aa33  83c410               add esp, 0x10
// 0040aa36  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
