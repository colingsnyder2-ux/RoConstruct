// from server: 100% by auto
// roc 2012-06 00401650  unit: CAboutRobloxDialog  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401650
//
// 00401650  8b442404             mov eax, dword ptr [esp + 4]
// 00401654  56                   push esi
// 00401655  50                   push eax
// 00401656  8bf1                 mov esi, ecx
// 00401658  ff15e429b200         call dword ptr [0xb229e4]
// 0040165e  c706942eb400         mov dword ptr [esi], 0xb42e94
// 00401664  8bc6                 mov eax, esi
// 00401666  5e                   pop esi
// 00401667  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
