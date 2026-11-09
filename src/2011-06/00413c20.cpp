// from server: 100% by auto
// roc 2011-06 00413c20  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00413c20
//
// 00413c20  8b442404             mov eax, dword ptr [esp + 4]
// 00413c24  56                   push esi
// 00413c25  50                   push eax
// 00413c26  8bf1                 mov esi, ecx
// 00413c28  ff15580aa400         call dword ptr [0xa40a58]
// 00413c2e  c706bcdea500         mov dword ptr [esi], 0xa5debc
// 00413c34  8bc6                 mov eax, esi
// 00413c36  5e                   pop esi
// 00413c37  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
