// from server: 100% by auto
// roc 2007-08 00403d00  unit: ATL::CComClassFactory  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403d00
//
// 00403d00  8b442404             mov eax, dword ptr [esp + 4]
// 00403d04  56                   push esi
// 00403d05  50                   push eax
// 00403d06  8bf1                 mov esi, ecx
// 00403d08  e883ffffff           call 0x403c90
// 00403d0d  c706784e7800         mov dword ptr [esi], 0x784e78
// 00403d13  8bc6                 mov eax, esi
// 00403d15  5e                   pop esi
// 00403d16  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
