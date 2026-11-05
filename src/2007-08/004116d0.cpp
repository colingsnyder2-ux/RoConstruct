// from server: 100% by auto
// roc 2007-08 004116d0  unit: boost::bad_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004116d0
//
// 004116d0  8b442404             mov eax, dword ptr [esp + 4]
// 004116d4  56                   push esi
// 004116d5  50                   push eax
// 004116d6  8bf1                 mov esi, ecx
// 004116d8  ff1518e77700         call dword ptr [0x77e718]
// 004116de  c706fc6d7800         mov dword ptr [esi], 0x786dfc
// 004116e4  8bc6                 mov eax, esi
// 004116e6  5e                   pop esi
// 004116e7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
