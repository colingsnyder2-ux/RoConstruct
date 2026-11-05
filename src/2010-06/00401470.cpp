// from server: 100% by auto
// roc 2010-06 00401470  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401470
//
// 00401470  6aff                 push -1
// 00401472  68198f9a00           push 0x9a8f19
// 00401477  64a100000000         mov eax, dword ptr fs:[0]
// 0040147d  50                   push eax
// 0040147e  64892500000000       mov dword ptr fs:[0], esp
// 00401485  51                   push ecx
// 00401486  56                   push esi
// 00401487  8bf1                 mov esi, ecx
// 00401489  89742404             mov dword ptr [esp + 4], esi
// 0040148d  ff1518a99e00         call dword ptr [0x9ea918]
// 00401493  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401497  50                   push eax
// 00401498  8d4e0c               lea ecx, [esi + 0xc]
// 0040149b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004014a3  c7062c00a000         mov dword ptr [esi], 0xa0002c
// 004014a9  ff150ca49e00         call dword ptr [0x9ea40c]
// 004014af  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004014b3  8bc6                 mov eax, esi
// 004014b5  5e                   pop esi
// 004014b6  64890d00000000       mov dword ptr fs:[0], ecx
// 004014bd  83c410               add esp, 0x10
// 004014c0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
