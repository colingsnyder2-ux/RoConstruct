// from server: 100% by auto
// roc 2012-06 0040c0a0  unit: boost::exception_detail::clone_base  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040c0a0
//
// 0040c0a0  6aff                 push -1
// 0040c0a2  68299fa900           push 0xa99f29
// 0040c0a7  64a100000000         mov eax, dword ptr fs:[0]
// 0040c0ad  50                   push eax
// 0040c0ae  64892500000000       mov dword ptr fs:[0], esp
// 0040c0b5  51                   push ecx
// 0040c0b6  56                   push esi
// 0040c0b7  8bf1                 mov esi, ecx
// 0040c0b9  89742404             mov dword ptr [esp + 4], esi
// 0040c0bd  ff15dc29b200         call dword ptr [0xb229dc]
// 0040c0c3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0040c0c7  50                   push eax
// 0040c0c8  8d4e0c               lea ecx, [esi + 0xc]
// 0040c0cb  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040c0d3  c7064c3cb400         mov dword ptr [esi], 0xb43c4c
// 0040c0d9  ff154426b200         call dword ptr [0xb22644]
// 0040c0df  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040c0e3  8bc6                 mov eax, esi
// 0040c0e5  5e                   pop esi
// 0040c0e6  64890d00000000       mov dword ptr fs:[0], ecx
// 0040c0ed  83c410               add esp, 0x10
// 0040c0f0  c20400               ret 4
// standard library vector<ptr> (function ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
