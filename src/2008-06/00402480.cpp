// from server: 100% by auto
// roc 2008-06 00402480  unit: std::bad_alloc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402480
//
// 00402480  8b442404             mov eax, dword ptr [esp + 4]
// 00402484  56                   push esi
// 00402485  50                   push eax
// 00402486  8bf1                 mov esi, ecx
// 00402488  e893ffffff           call 0x402420
// 0040248d  c7061cb18000         mov dword ptr [esi], 0x80b11c
// 00402493  8bc6                 mov eax, esi
// 00402495  5e                   pop esi
// 00402496  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
