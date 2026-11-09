// from server: 100% by auto
// roc 2012-06 00416ee0  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00416ee0
//
// 00416ee0  8b442404             mov eax, dword ptr [esp + 4]
// 00416ee4  56                   push esi
// 00416ee5  50                   push eax
// 00416ee6  8bf1                 mov esi, ecx
// 00416ee8  ff15e429b200         call dword ptr [0xb229e4]
// 00416eee  c706e45eb400         mov dword ptr [esi], 0xb45ee4
// 00416ef4  8bc6                 mov eax, esi
// 00416ef6  5e                   pop esi
// 00416ef7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
