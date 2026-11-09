// from server: 100% by auto
// roc 2008-06 0040a3d0  unit: boost::any::_N::?$holder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040a3d0
//
// 0040a3d0  8b442404             mov eax, dword ptr [esp + 4]
// 0040a3d4  56                   push esi
// 0040a3d5  50                   push eax
// 0040a3d6  8bf1                 mov esi, ecx
// 0040a3d8  ff155c288000         call dword ptr [0x80285c]
// 0040a3de  c7062cba8000         mov dword ptr [esi], 0x80ba2c
// 0040a3e4  8bc6                 mov eax, esi
// 0040a3e6  5e                   pop esi
// 0040a3e7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
