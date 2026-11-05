// from server: 100% by auto
// roc 2007-08 00413a70  unit: DHTMLWindowService  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413a70
//
// 00413a70  8b442404             mov eax, dword ptr [esp + 4]
// 00413a74  56                   push esi
// 00413a75  50                   push eax
// 00413a76  8bf1                 mov esi, ecx
// 00413a78  e833fcffff           call 0x4136b0
// 00413a7d  c7068c717800         mov dword ptr [esi], 0x78718c
// 00413a83  8bc6                 mov eax, esi
// 00413a85  5e                   pop esi
// 00413a86  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
