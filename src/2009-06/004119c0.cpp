// from server: 100% by auto
// roc 2009-06 004119c0  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004119c0
//
// 004119c0  8b442404             mov eax, dword ptr [esp + 4]
// 004119c4  56                   push esi
// 004119c5  50                   push eax
// 004119c6  8bf1                 mov esi, ecx
// 004119c8  e8b301ffff           call 0x401b80
// 004119cd  c7062cf28a00         mov dword ptr [esi], 0x8af22c
// 004119d3  8bc6                 mov eax, esi
// 004119d5  5e                   pop esi
// 004119d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
