// from server: 100% by auto
// roc 2009-06 0040f7a0  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040f7a0
//
// 0040f7a0  8b442404             mov eax, dword ptr [esp + 4]
// 0040f7a4  56                   push esi
// 0040f7a5  50                   push eax
// 0040f7a6  8bf1                 mov esi, ecx
// 0040f7a8  ff15b0e98900         call dword ptr [0x89e9b0]
// 0040f7ae  c706b8eb8a00         mov dword ptr [esi], 0x8aebb8
// 0040f7b4  8bc6                 mov eax, esi
// 0040f7b6  5e                   pop esi
// 0040f7b7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
