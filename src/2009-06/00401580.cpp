// from server: 100% by auto
// roc 2009-06 00401580  unit: std::bad_alloc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401580
//
// 00401580  8b442404             mov eax, dword ptr [esp + 4]
// 00401584  56                   push esi
// 00401585  50                   push eax
// 00401586  8bf1                 mov esi, ecx
// 00401588  e853ffffff           call 0x4014e0
// 0040158d  c7065cc98a00         mov dword ptr [esi], 0x8ac95c
// 00401593  8bc6                 mov eax, esi
// 00401595  5e                   pop esi
// 00401596  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
