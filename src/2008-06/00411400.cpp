// from server: 100% by auto
// roc 2008-06 00411400  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00411400
//
// 00411400  8b442404             mov eax, dword ptr [esp + 4]
// 00411404  56                   push esi
// 00411405  50                   push eax
// 00411406  8bf1                 mov esi, ecx
// 00411408  ff1588288000         call dword ptr [0x802888]
// 0041140e  c706a8df8000         mov dword ptr [esi], 0x80dfa8
// 00411414  8bc6                 mov eax, esi
// 00411416  5e                   pop esi
// 00411417  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
