// from server: 100% by auto
// roc 2010-06 0040f940  unit: CChatPrompt  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040f940
//
// 0040f940  8b442404             mov eax, dword ptr [esp + 4]
// 0040f944  56                   push esi
// 0040f945  50                   push eax
// 0040f946  8bf1                 mov esi, ecx
// 0040f948  ff1510a99e00         call dword ptr [0x9ea910]
// 0040f94e  c706fc23a000         mov dword ptr [esi], 0xa023fc
// 0040f954  8bc6                 mov eax, esi
// 0040f956  5e                   pop esi
// 0040f957  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
