// from server: 100% by auto
// roc 2009-06 00409630  unit: std::logic_error  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409630
//
// 00409630  8b442404             mov eax, dword ptr [esp + 4]
// 00409634  56                   push esi
// 00409635  50                   push eax
// 00409636  8bf1                 mov esi, ecx
// 00409638  e843feffff           call 0x409480
// 0040963d  c70668d28a00         mov dword ptr [esi], 0x8ad268
// 00409643  8bc6                 mov eax, esi
// 00409645  5e                   pop esi
// 00409646  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
