// from server: 100% by auto
// roc 2007-08 00696520  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00696520
//
// 00696520  8b442404             mov eax, dword ptr [esp + 4]
// 00696524  56                   push esi
// 00696525  50                   push eax
// 00696526  8bf1                 mov esi, ecx
// 00696528  e8b3e9ffff           call 0x694ee0
// 0069652d  c7069c117d00         mov dword ptr [esi], 0x7d119c
// 00696533  8bc6                 mov eax, esi
// 00696535  5e                   pop esi
// 00696536  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
