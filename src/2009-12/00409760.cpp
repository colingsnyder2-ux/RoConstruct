// from server: 100% by auto
// roc 2009-12 00409760  unit: boost::bad_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00409760
//
// 00409760  8b442404             mov eax, dword ptr [esp + 4]
// 00409764  56                   push esi
// 00409765  50                   push eax
// 00409766  8bf1                 mov esi, ecx
// 00409768  ff15acb79800         call dword ptr [0x98b7ac]
// 0040976e  c70694fe9900         mov dword ptr [esi], 0x99fe94
// 00409774  8bc6                 mov eax, esi
// 00409776  5e                   pop esi
// 00409777  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
