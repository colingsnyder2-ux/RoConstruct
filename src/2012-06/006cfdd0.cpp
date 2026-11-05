// from server: 100% by auto
// roc 2012-06 006cfdd0  unit: boost::io::too_many_args  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cfdd0
//
// 006cfdd0  8b442404             mov eax, dword ptr [esp + 4]
// 006cfdd4  56                   push esi
// 006cfdd5  50                   push eax
// 006cfdd6  8bf1                 mov esi, ecx
// 006cfdd8  ff15e429b200         call dword ptr [0xb229e4]
// 006cfdde  c7060488b900         mov dword ptr [esi], 0xb98804
// 006cfde4  8bc6                 mov eax, esi
// 006cfde6  5e                   pop esi
// 006cfde7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
