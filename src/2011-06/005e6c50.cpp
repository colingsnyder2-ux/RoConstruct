// from server: 100% by auto
// roc 2011-06 005e6c50  unit: RBX::DataModel  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005e6c50
//
// 005e6c50  8b442404             mov eax, dword ptr [esp + 4]
// 005e6c54  56                   push esi
// 005e6c55  50                   push eax
// 005e6c56  8bf1                 mov esi, ecx
// 005e6c58  ff15580aa400         call dword ptr [0xa40a58]
// 005e6c5e  c706380da900         mov dword ptr [esi], 0xa90d38
// 005e6c64  8bc6                 mov eax, esi
// 005e6c66  5e                   pop esi
// 005e6c67  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
