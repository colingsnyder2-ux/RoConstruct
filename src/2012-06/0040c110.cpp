// from server: 100% by auto
// roc 2012-06 0040c110  unit: std::logic_error  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c110
//
// 0040c110  6aff                 push -1
// 0040c112  68299fa900           push 0xa99f29
// 0040c117  64a100000000         mov eax, dword ptr fs:[0]
// 0040c11d  50                   push eax
// 0040c11e  64892500000000       mov dword ptr fs:[0], esp
// 0040c125  51                   push ecx
// 0040c126  56                   push esi
// 0040c127  57                   push edi
// 0040c128  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0040c12c  8bf1                 mov esi, ecx
// 0040c12e  57                   push edi
// 0040c12f  8974240c             mov dword ptr [esp + 0xc], esi
// 0040c133  ff15e429b200         call dword ptr [0xb229e4]
// 0040c139  83c70c               add edi, 0xc
// 0040c13c  57                   push edi
// 0040c13d  8d4e0c               lea ecx, [esi + 0xc]
// 0040c140  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040c148  c7064c3cb400         mov dword ptr [esi], 0xb43c4c
// 0040c14e  ff154426b200         call dword ptr [0xb22644]
// 0040c154  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040c158  5f                   pop edi
// 0040c159  8bc6                 mov eax, esi
// 0040c15b  5e                   pop esi
// 0040c15c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040c163  83c410               add esp, 0x10
// 0040c166  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
