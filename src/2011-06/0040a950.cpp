// from server: 100% by auto
// roc 2011-06 0040a950  unit: boost::exception_detail::clone_base  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a950
//
// 0040a950  6aff                 push -1
// 0040a952  6879cf9c00           push 0x9ccf79
// 0040a957  64a100000000         mov eax, dword ptr fs:[0]
// 0040a95d  50                   push eax
// 0040a95e  64892500000000       mov dword ptr fs:[0], esp
// 0040a965  51                   push ecx
// 0040a966  56                   push esi
// 0040a967  8bf1                 mov esi, ecx
// 0040a969  89742404             mov dword ptr [esp + 4], esi
// 0040a96d  ff15600aa400         call dword ptr [0xa40a60]
// 0040a973  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040a977  50                   push eax
// 0040a978  8d4e0c               lea ecx, [esi + 0xc]
// 0040a97b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040a983  c70600bfa500         mov dword ptr [esi], 0xa5bf00
// 0040a989  ff15c804a400         call dword ptr [0xa404c8]
// 0040a98f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040a993  8bc6                 mov eax, esi
// 0040a995  5e                   pop esi
// 0040a996  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a99d  83c410               add esp, 0x10
// 0040a9a0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
