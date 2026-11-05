// from server: 100% by auto
// roc 2011-06 0040b5e0  unit: boost::bad_any_cast  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b5e0
//
// 0040b5e0  8b442404             mov eax, dword ptr [esp + 4]
// 0040b5e4  56                   push esi
// 0040b5e5  50                   push eax
// 0040b5e6  8bf1                 mov esi, ecx
// 0040b5e8  ff15080aa400         call dword ptr [0xa40a08]
// 0040b5ee  c70604c1a500         mov dword ptr [esi], 0xa5c104
// 0040b5f4  8bc6                 mov eax, esi
// 0040b5f6  5e                   pop esi
// 0040b5f7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
