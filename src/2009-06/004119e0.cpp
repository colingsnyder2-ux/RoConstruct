// from server: 100% by auto
// roc 2009-06 004119e0  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004119e0
//
// 004119e0  8b442404             mov eax, dword ptr [esp + 4]
// 004119e4  56                   push esi
// 004119e5  50                   push eax
// 004119e6  8bf1                 mov esi, ecx
// 004119e8  e89301ffff           call 0x401b80
// 004119ed  c70664f28a00         mov dword ptr [esi], 0x8af264
// 004119f3  8bc6                 mov eax, esi
// 004119f5  5e                   pop esi
// 004119f6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
