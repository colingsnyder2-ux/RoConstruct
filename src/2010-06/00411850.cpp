// from server: 100% by auto
// roc 2010-06 00411850  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411850
//
// 00411850  8b442404             mov eax, dword ptr [esp + 4]
// 00411854  56                   push esi
// 00411855  50                   push eax
// 00411856  8bf1                 mov esi, ecx
// 00411858  e8b3fffeff           call 0x401810
// 0041185d  c706e82aa000         mov dword ptr [esi], 0xa02ae8
// 00411863  8bc6                 mov eax, esi
// 00411865  5e                   pop esi
// 00411866  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
