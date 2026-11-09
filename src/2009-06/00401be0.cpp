// from server: 100% by auto
// roc 2009-06 00401be0  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401be0
//
// 00401be0  8b442404             mov eax, dword ptr [esp + 4]
// 00401be4  56                   push esi
// 00401be5  50                   push eax
// 00401be6  8bf1                 mov esi, ecx
// 00401be8  e893ffffff           call 0x401b80
// 00401bed  c7065cc98a00         mov dword ptr [esi], 0x8ac95c
// 00401bf3  8bc6                 mov eax, esi
// 00401bf5  5e                   pop esi
// 00401bf6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
