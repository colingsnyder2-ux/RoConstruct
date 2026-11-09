// from server: 100% by auto
// roc 2010-06 00401890  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00401890
//
// 00401890  8b442404             mov eax, dword ptr [esp + 4]
// 00401894  56                   push esi
// 00401895  50                   push eax
// 00401896  8bf1                 mov esi, ecx
// 00401898  e873ffffff           call 0x401810
// 0040189d  c7063800a000         mov dword ptr [esi], 0xa00038
// 004018a3  8bc6                 mov eax, esi
// 004018a5  5e                   pop esi
// 004018a6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
