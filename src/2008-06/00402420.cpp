// from server: 100% by auto
// roc 2008-06 00402420  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402420
//
// 00402420  6aff                 push -1
// 00402422  6859cd7b00           push 0x7bcd59
// 00402427  64a100000000         mov eax, dword ptr fs:[0]
// 0040242d  50                   push eax
// 0040242e  64892500000000       mov dword ptr fs:[0], esp
// 00402435  51                   push ecx
// 00402436  56                   push esi
// 00402437  8bf1                 mov esi, ecx
// 00402439  89742404             mov dword ptr [esp + 4], esi
// 0040243d  ff1598288000         call dword ptr [0x802898]
// 00402443  8b442418             mov eax, dword ptr [esp + 0x18]
// 00402447  50                   push eax
// 00402448  8d4e0c               lea ecx, [esi + 0xc]
// 0040244b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00402453  c70610b18000         mov dword ptr [esi], 0x80b110
// 00402459  ff155c248000         call dword ptr [0x80245c]
// 0040245f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00402463  8bc6                 mov eax, esi
// 00402465  5e                   pop esi
// 00402466  64890d00000000       mov dword ptr fs:[0], ecx
// 0040246d  83c410               add esp, 0x10
// 00402470  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
