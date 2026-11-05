// from server: 100% by auto
// roc 2009-06 00409850  unit: boost::bad_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409850
//
// 00409850  8b442404             mov eax, dword ptr [esp + 4]
// 00409854  56                   push esi
// 00409855  50                   push eax
// 00409856  8bf1                 mov esi, ecx
// 00409858  ff1568e98900         call dword ptr [0x89e968]
// 0040985e  c70648d38a00         mov dword ptr [esi], 0x8ad348
// 00409864  8bc6                 mov eax, esi
// 00409866  5e                   pop esi
// 00409867  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
