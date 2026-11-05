// from server: 100% by auto
// roc 2009-06 00401540  unit: std::bad_alloc  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401540
//
// 00401540  8b442404             mov eax, dword ptr [esp + 4]
// 00401544  56                   push esi
// 00401545  50                   push eax
// 00401546  8bf1                 mov esi, ecx
// 00401548  e893ffffff           call 0x4014e0
// 0040154d  c70650c98a00         mov dword ptr [esi], 0x8ac950
// 00401553  8bc6                 mov eax, esi
// 00401555  5e                   pop esi
// 00401556  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
