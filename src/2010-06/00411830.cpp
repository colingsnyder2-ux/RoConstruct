// from server: 100% by auto
// roc 2010-06 00411830  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00411830
//
// 00411830  8b442404             mov eax, dword ptr [esp + 4]
// 00411834  56                   push esi
// 00411835  50                   push eax
// 00411836  8bf1                 mov esi, ecx
// 00411838  e8d3fffeff           call 0x401810
// 0041183d  c706b42aa000         mov dword ptr [esi], 0xa02ab4
// 00411843  8bc6                 mov eax, esi
// 00411845  5e                   pop esi
// 00411846  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
