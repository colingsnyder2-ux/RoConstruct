// from server: 100% by auto
// roc 2009-12 00401450  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401450
//
// 00401450  6aff                 push -1
// 00401452  68d9749200           push 0x9274d9
// 00401457  64a100000000         mov eax, dword ptr fs:[0]
// 0040145d  50                   push eax
// 0040145e  64892500000000       mov dword ptr fs:[0], esp
// 00401465  51                   push ecx
// 00401466  56                   push esi
// 00401467  8bf1                 mov esi, ecx
// 00401469  89742404             mov dword ptr [esp + 4], esi
// 0040146d  ff1554b79800         call dword ptr [0x98b754]
// 00401473  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401477  50                   push eax
// 00401478  8d4e0c               lea ecx, [esi + 0xc]
// 0040147b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00401483  c70684f49900         mov dword ptr [esi], 0x99f484
// 00401489  ff15f0b69800         call dword ptr [0x98b6f0]
// 0040148f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401493  8bc6                 mov eax, esi
// 00401495  5e                   pop esi
// 00401496  64890d00000000       mov dword ptr fs:[0], ecx
// 0040149d  83c410               add esp, 0x10
// 004014a0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
