// from server: 100% by auto
// roc 2010-06 00409800  unit: boost::bad_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00409800
//
// 00409800  8b442404             mov eax, dword ptr [esp + 4]
// 00409804  56                   push esi
// 00409805  50                   push eax
// 00409806  8bf1                 mov esi, ecx
// 00409808  ff1594a89e00         call dword ptr [0x9ea894]
// 0040980e  c7064c0aa000         mov dword ptr [esi], 0xa00a4c
// 00409814  8bc6                 mov eax, esi
// 00409816  5e                   pop esi
// 00409817  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
