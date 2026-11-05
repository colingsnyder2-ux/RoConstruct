// from server: 100% by auto
// roc 2008-06 004024a0  unit: std::bad_alloc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004024a0
//
// 004024a0  8b442404             mov eax, dword ptr [esp + 4]
// 004024a4  56                   push esi
// 004024a5  50                   push eax
// 004024a6  8bf1                 mov esi, ecx
// 004024a8  e873ffffff           call 0x402420
// 004024ad  c70628b18000         mov dword ptr [esi], 0x80b128
// 004024b3  8bc6                 mov eax, esi
// 004024b5  5e                   pop esi
// 004024b6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
