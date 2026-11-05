// from server: 100% by auto
// roc 2009-06 00411a00  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411a00
//
// 00411a00  8b442404             mov eax, dword ptr [esp + 4]
// 00411a04  56                   push esi
// 00411a05  50                   push eax
// 00411a06  8bf1                 mov esi, ecx
// 00411a08  e87301ffff           call 0x401b80
// 00411a0d  c70698f28a00         mov dword ptr [esi], 0x8af298
// 00411a13  8bc6                 mov eax, esi
// 00411a15  5e                   pop esi
// 00411a16  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
