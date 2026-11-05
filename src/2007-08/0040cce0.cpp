// from server: 100% by auto
// roc 2007-08 0040cce0  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040cce0
//
// 0040cce0  8b442404             mov eax, dword ptr [esp + 4]
// 0040cce4  56                   push esi
// 0040cce5  50                   push eax
// 0040cce6  8bf1                 mov esi, ecx
// 0040cce8  ff1500e77700         call dword ptr [0x77e700]
// 0040ccee  c706a8647800         mov dword ptr [esi], 0x7864a8
// 0040ccf4  8bc6                 mov eax, esi
// 0040ccf6  5e                   pop esi
// 0040ccf7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
