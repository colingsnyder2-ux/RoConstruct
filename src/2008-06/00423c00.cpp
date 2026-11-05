// from server: 100% by auto
// roc 2008-06 00423c00  unit: CSelectionTreeCtrl  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00423c00
//
// 00423c00  8b442408             mov eax, dword ptr [esp + 8]
// 00423c04  8b542404             mov edx, dword ptr [esp + 4]
// 00423c08  2bc2                 sub eax, edx
// 00423c0a  56                   push esi
// 00423c0b  c1f802               sar eax, 2
// 00423c0e  57                   push edi
// 00423c0f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00423c13  8d0c8500000000       lea ecx, [eax*4]
// 00423c1a  8d3439               lea esi, [ecx + edi]
// 00423c1d  85c0                 test eax, eax
// 00423c1f  760d                 jbe 0x423c2e
// 00423c21  51                   push ecx
// 00423c22  52                   push edx
// 00423c23  51                   push ecx
// 00423c24  57                   push edi
// 00423c25  ff1550288000         call dword ptr [0x802850]
// 00423c2b  83c410               add esp, 0x10
// 00423c2e  5f                   pop edi
// 00423c2f  8bc6                 mov eax, esi
// 00423c31  5e                   pop esi
// 00423c32  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
