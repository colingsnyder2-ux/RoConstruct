// from server: 100% by auto
// roc 2008-06 00402390  unit: VCWorkspace::?$CComObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402390
//
// 00402390  56                   push esi
// 00402391  8d442408             lea eax, [esp + 8]
// 00402395  50                   push eax
// 00402396  8bf1                 mov esi, ecx
// 00402398  ff15a4288000         call dword ptr [0x8028a4]
// 0040239e  c70604b18000         mov dword ptr [esi], 0x80b104
// 004023a4  8bc6                 mov eax, esi
// 004023a6  5e                   pop esi
// 004023a7  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@PBD@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
