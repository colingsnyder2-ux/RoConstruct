// from server: 100% by auto
// roc 2009-12 0040f500  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0040f500
//
// 0040f500  8b442404             mov eax, dword ptr [esp + 4]
// 0040f504  56                   push esi
// 0040f505  50                   push eax
// 0040f506  8bf1                 mov esi, ecx
// 0040f508  ff155cb79800         call dword ptr [0x98b75c]
// 0040f50e  c70688179a00         mov dword ptr [esi], 0x9a1788
// 0040f514  8bc6                 mov eax, esi
// 0040f516  5e                   pop esi
// 0040f517  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
