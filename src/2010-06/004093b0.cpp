// from server: 100% by auto
// roc 2010-06 004093b0  unit: boost::exception_detail::clone_base  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004093b0
//
// 004093b0  6aff                 push -1
// 004093b2  68198f9a00           push 0x9a8f19
// 004093b7  64a100000000         mov eax, dword ptr fs:[0]
// 004093bd  50                   push eax
// 004093be  64892500000000       mov dword ptr fs:[0], esp
// 004093c5  51                   push ecx
// 004093c6  56                   push esi
// 004093c7  8bf1                 mov esi, ecx
// 004093c9  89742404             mov dword ptr [esp + 4], esi
// 004093cd  ff1518a99e00         call dword ptr [0x9ea918]
// 004093d3  8b442418             mov eax, dword ptr [esp + 0x18]
// 004093d7  50                   push eax
// 004093d8  8d4e0c               lea ecx, [esi + 0xc]
// 004093db  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004093e3  c7063009a000         mov dword ptr [esi], 0xa00930
// 004093e9  ff150ca49e00         call dword ptr [0x9ea40c]
// 004093ef  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004093f3  8bc6                 mov eax, esi
// 004093f5  5e                   pop esi
// 004093f6  64890d00000000       mov dword ptr fs:[0], ecx
// 004093fd  83c410               add esp, 0x10
// 00409400  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
