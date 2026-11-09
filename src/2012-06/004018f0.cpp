// from server: 100% by auto
// roc 2012-06 004018f0  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004018f0
//
// 004018f0  8b442404             mov eax, dword ptr [esp + 4]
// 004018f4  56                   push esi
// 004018f5  50                   push eax
// 004018f6  8bf1                 mov esi, ecx
// 004018f8  e8d3fdffff           call 0x4016d0
// 004018fd  c706ac2eb400         mov dword ptr [esi], 0xb42eac
// 00401903  8bc6                 mov eax, esi
// 00401905  5e                   pop esi
// 00401906  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
