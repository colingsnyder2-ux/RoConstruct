// from server: 100% by auto
// roc 2008-06 00404f90  unit: VCWorkspace::?$CComObject  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00404f90
//
// 00404f90  8b442404             mov eax, dword ptr [esp + 4]
// 00404f94  56                   push esi
// 00404f95  50                   push eax
// 00404f96  8bf1                 mov esi, ecx
// 00404f98  e893ffffff           call 0x404f30
// 00404f9d  c70628b18000         mov dword ptr [esi], 0x80b128
// 00404fa3  8bc6                 mov eax, esi
// 00404fa5  5e                   pop esi
// 00404fa6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
