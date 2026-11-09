// from server: 100% by auto
// roc 2009-06 00787f90  unit: CXTPToolTipContext  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00787f90
//
// 00787f90  8b442404             mov eax, dword ptr [esp + 4]
// 00787f94  56                   push esi
// 00787f95  50                   push eax
// 00787f96  8bf1                 mov esi, ecx
// 00787f98  e843eeffff           call 0x786de0
// 00787f9d  c7064cdd8f00         mov dword ptr [esi], 0x8fdd4c
// 00787fa3  8bc6                 mov eax, esi
// 00787fa5  5e                   pop esi
// 00787fa6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
