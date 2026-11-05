// from server: 100% by auto
// roc 2012-06 00858ff0  unit: seg_00850000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00858ff0
//
// 00858ff0  8b442404             mov eax, dword ptr [esp + 4]
// 00858ff4  56                   push esi
// 00858ff5  50                   push eax
// 00858ff6  8bf1                 mov esi, ecx
// 00858ff8  e8a330bbff           call 0x40c0a0
// 00858ffd  c7065444bd00         mov dword ptr [esi], 0xbd4454
// 00859003  8bc6                 mov eax, esi
// 00859005  5e                   pop esi
// 00859006  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
