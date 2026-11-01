// from server: 100% by auto
// roc 2009-12 00409390  unit: boost::exception_detail::clone_base  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00409390
//
// 00409390  6aff                 push -1
// 00409392  68d9749200           push 0x9274d9
// 00409397  64a100000000         mov eax, dword ptr fs:[0]
// 0040939d  50                   push eax
// 0040939e  64892500000000       mov dword ptr fs:[0], esp
// 004093a5  51                   push ecx
// 004093a6  56                   push esi
// 004093a7  8bf1                 mov esi, ecx
// 004093a9  89742404             mov dword ptr [esp + 4], esi
// 004093ad  ff1554b79800         call dword ptr [0x98b754]
// 004093b3  8b442418             mov eax, dword ptr [esp + 0x18]
// 004093b7  50                   push eax
// 004093b8  8d4e0c               lea ecx, [esi + 0xc]
// 004093bb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004093c3  c706a0fd9900         mov dword ptr [esi], 0x99fda0
// 004093c9  ff15f0b69800         call dword ptr [0x98b6f0]
// 004093cf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004093d3  8bc6                 mov eax, esi
// 004093d5  5e                   pop esi
// 004093d6  64890d00000000       mov dword ptr fs:[0], ecx
// 004093dd  83c410               add esp, 0x10
// 004093e0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
