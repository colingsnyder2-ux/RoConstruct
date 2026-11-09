// from server: 100% by auto
// roc 2011-06 004013f0  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004013f0
//
// 004013f0  6aff                 push -1
// 004013f2  6879cf9c00           push 0x9ccf79
// 004013f7  64a100000000         mov eax, dword ptr fs:[0]
// 004013fd  50                   push eax
// 004013fe  64892500000000       mov dword ptr fs:[0], esp
// 00401405  51                   push ecx
// 00401406  56                   push esi
// 00401407  8bf1                 mov esi, ecx
// 00401409  89742404             mov dword ptr [esp + 4], esi
// 0040140d  ff15600aa400         call dword ptr [0xa40a60]
// 00401413  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401417  50                   push eax
// 00401418  8d4e0c               lea ecx, [esi + 0xc]
// 0040141b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00401423  c706c0b5a500         mov dword ptr [esi], 0xa5b5c0
// 00401429  ff15c804a400         call dword ptr [0xa404c8]
// 0040142f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401433  8bc6                 mov eax, esi
// 00401435  5e                   pop esi
// 00401436  64890d00000000       mov dword ptr fs:[0], ecx
// 0040143d  83c410               add esp, 0x10
// 00401440  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
