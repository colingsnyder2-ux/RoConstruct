// from server: 100% by auto
// roc 2012-06 0040cc90  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040cc90
//
// 0040cc90  8b442404             mov eax, dword ptr [esp + 4]
// 0040cc94  56                   push esi
// 0040cc95  50                   push eax
// 0040cc96  8bf1                 mov esi, ecx
// 0040cc98  e8334affff           call 0x4016d0
// 0040cc9d  c706583cb400         mov dword ptr [esi], 0xb43c58
// 0040cca3  8bc6                 mov eax, esi
// 0040cca5  5e                   pop esi
// 0040cca6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
