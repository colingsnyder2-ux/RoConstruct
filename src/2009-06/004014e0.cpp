// from server: 100% by auto
// roc 2009-06 004014e0  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004014e0
//
// 004014e0  6aff                 push -1
// 004014e2  6809ca8400           push 0x84ca09
// 004014e7  64a100000000         mov eax, dword ptr fs:[0]
// 004014ed  50                   push eax
// 004014ee  64892500000000       mov dword ptr fs:[0], esp
// 004014f5  51                   push ecx
// 004014f6  56                   push esi
// 004014f7  8bf1                 mov esi, ecx
// 004014f9  89742404             mov dword ptr [esp + 4], esi
// 004014fd  ff15b8e98900         call dword ptr [0x89e9b8]
// 00401503  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401507  50                   push eax
// 00401508  8d4e0c               lea ecx, [esi + 0xc]
// 0040150b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00401513  c70644c98a00         mov dword ptr [esi], 0x8ac944
// 00401519  ff15b8e48900         call dword ptr [0x89e4b8]
// 0040151f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401523  8bc6                 mov eax, esi
// 00401525  5e                   pop esi
// 00401526  64890d00000000       mov dword ptr fs:[0], ecx
// 0040152d  83c410               add esp, 0x10
// 00401530  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
