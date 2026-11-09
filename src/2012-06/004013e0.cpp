// from server: 100% by auto
// roc 2012-06 004013e0  unit: std::bad_alloc  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004013e0
//
// 004013e0  6aff                 push -1
// 004013e2  68299fa900           push 0xa99f29
// 004013e7  64a100000000         mov eax, dword ptr fs:[0]
// 004013ed  50                   push eax
// 004013ee  64892500000000       mov dword ptr fs:[0], esp
// 004013f5  51                   push ecx
// 004013f6  56                   push esi
// 004013f7  8bf1                 mov esi, ecx
// 004013f9  89742404             mov dword ptr [esp + 4], esi
// 004013fd  ff15dc29b200         call dword ptr [0xb229dc]
// 00401403  8b442418             mov eax, dword ptr [esp + 0x18]
// 00401407  50                   push eax
// 00401408  8d4e0c               lea ecx, [esi + 0xc]
// 0040140b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00401413  c706a02eb400         mov dword ptr [esi], 0xb42ea0
// 00401419  ff154426b200         call dword ptr [0xb22644]
// 0040141f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401423  8bc6                 mov eax, esi
// 00401425  5e                   pop esi
// 00401426  64890d00000000       mov dword ptr fs:[0], ecx
// 0040142d  83c410               add esp, 0x10
// 00401430  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
