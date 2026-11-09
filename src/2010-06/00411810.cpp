// from server: 100% by auto
// roc 2010-06 00411810  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411810
//
// 00411810  8b442404             mov eax, dword ptr [esp + 4]
// 00411814  56                   push esi
// 00411815  50                   push eax
// 00411816  8bf1                 mov esi, ecx
// 00411818  e8f3fffeff           call 0x401810
// 0041181d  c7067c2aa000         mov dword ptr [esi], 0xa02a7c
// 00411823  8bc6                 mov eax, esi
// 00411825  5e                   pop esi
// 00411826  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
