// from server: 100% by auto
// roc 2011-06 00401a70  unit: CAboutRobloxDialog  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00401a70
//
// 00401a70  8b442404             mov eax, dword ptr [esp + 4]
// 00401a74  56                   push esi
// 00401a75  50                   push eax
// 00401a76  8bf1                 mov esi, ecx
// 00401a78  e893ffffff           call 0x401a10
// 00401a7d  c706d8b5a500         mov dword ptr [esi], 0xa5b5d8
// 00401a83  8bc6                 mov eax, esi
// 00401a85  5e                   pop esi
// 00401a86  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
