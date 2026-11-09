// from server: 100% by auto
// roc 2012-06 0040ce00  unit: rbx::bad_placement_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ce00
//
// 0040ce00  8b442404             mov eax, dword ptr [esp + 4]
// 0040ce04  56                   push esi
// 0040ce05  50                   push eax
// 0040ce06  8bf1                 mov esi, ecx
// 0040ce08  ff15282ab200         call dword ptr [0xb22a28]
// 0040ce0e  c7062041b400         mov dword ptr [esi], 0xb44120
// 0040ce14  8bc6                 mov eax, esi
// 0040ce16  5e                   pop esi
// 0040ce17  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
