// from server: 100% by auto
// roc 2010-06 00401870  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401870
//
// 00401870  8b442404             mov eax, dword ptr [esp + 4]
// 00401874  56                   push esi
// 00401875  50                   push eax
// 00401876  8bf1                 mov esi, ecx
// 00401878  e893ffffff           call 0x401810
// 0040187d  c7064400a000         mov dword ptr [esi], 0xa00044
// 00401883  8bc6                 mov eax, esi
// 00401885  5e                   pop esi
// 00401886  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
