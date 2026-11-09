// from server: 100% by auto
// roc 2009-06 00409410  unit: boost::exception_detail::clone_base  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409410
//
// 00409410  6aff                 push -1
// 00409412  6809ca8400           push 0x84ca09
// 00409417  64a100000000         mov eax, dword ptr fs:[0]
// 0040941d  50                   push eax
// 0040941e  64892500000000       mov dword ptr fs:[0], esp
// 00409425  51                   push ecx
// 00409426  56                   push esi
// 00409427  8bf1                 mov esi, ecx
// 00409429  89742404             mov dword ptr [esp + 4], esi
// 0040942d  ff15b8e98900         call dword ptr [0x89e9b8]
// 00409433  8b442418             mov eax, dword ptr [esp + 0x18]
// 00409437  50                   push eax
// 00409438  8d4e0c               lea ecx, [esi + 0xc]
// 0040943b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00409443  c7065cd28a00         mov dword ptr [esi], 0x8ad25c
// 00409449  ff15b8e48900         call dword ptr [0x89e4b8]
// 0040944f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00409453  8bc6                 mov eax, esi
// 00409455  5e                   pop esi
// 00409456  64890d00000000       mov dword ptr fs:[0], ecx
// 0040945d  83c410               add esp, 0x10
// 00409460  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
