// from server: 100% by auto
// roc 2012-06 004016d0  unit: CAboutRobloxDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004016d0
//
// 004016d0  6aff                 push -1
// 004016d2  68299fa900           push 0xa99f29
// 004016d7  64a100000000         mov eax, dword ptr fs:[0]
// 004016dd  50                   push eax
// 004016de  64892500000000       mov dword ptr fs:[0], esp
// 004016e5  51                   push ecx
// 004016e6  56                   push esi
// 004016e7  57                   push edi
// 004016e8  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004016ec  8bf1                 mov esi, ecx
// 004016ee  57                   push edi
// 004016ef  8974240c             mov dword ptr [esp + 0xc], esi
// 004016f3  ff15e429b200         call dword ptr [0xb229e4]
// 004016f9  83c70c               add edi, 0xc
// 004016fc  57                   push edi
// 004016fd  8d4e0c               lea ecx, [esi + 0xc]
// 00401700  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00401708  c706a02eb400         mov dword ptr [esi], 0xb42ea0
// 0040170e  ff154426b200         call dword ptr [0xb22644]
// 00401714  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401718  5f                   pop edi
// 00401719  8bc6                 mov eax, esi
// 0040171b  5e                   pop esi
// 0040171c  64890d00000000       mov dword ptr fs:[0], ecx
// 00401723  83c410               add esp, 0x10
// 00401726  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
