// from server: 100% by auto
// roc 2007-08 00402a00  unit: VCWorkspace::?$CComObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00402a00
//
// 00402a00  8b442404             mov eax, dword ptr [esp + 4]
// 00402a04  56                   push esi
// 00402a05  50                   push eax
// 00402a06  8bf1                 mov esi, ecx
// 00402a08  ff1500e77700         call dword ptr [0x77e700]
// 00402a0e  c706544e7800         mov dword ptr [esi], 0x784e54
// 00402a14  8bc6                 mov eax, esi
// 00402a16  5e                   pop esi
// 00402a17  c20400               ret 4
// standard library vector<ptr> (function ??0bad_alloc@std@@QAE@ABV01@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
