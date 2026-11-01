// from server: 100% by auto
// roc 2009-12 00433bb0  unit: CPropGrid::UpdateItemsJob  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433bb0
//
// 00433bb0  8b442408             mov eax, dword ptr [esp + 8]
// 00433bb4  8b542404             mov edx, dword ptr [esp + 4]
// 00433bb8  2bc2                 sub eax, edx
// 00433bba  56                   push esi
// 00433bbb  c1f802               sar eax, 2
// 00433bbe  57                   push edi
// 00433bbf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00433bc3  8d0c8500000000       lea ecx, [eax*4]
// 00433bca  8d3439               lea esi, [ecx + edi]
// 00433bcd  85c0                 test eax, eax
// 00433bcf  7e0d                 jle 0x433bde
// 00433bd1  51                   push ecx
// 00433bd2  52                   push edx
// 00433bd3  51                   push ecx
// 00433bd4  57                   push edi
// 00433bd5  ff15c0b79800         call dword ptr [0x98b7c0]
// 00433bdb  83c410               add esp, 0x10
// 00433bde  5f                   pop edi
// 00433bdf  8bc6                 mov eax, esi
// 00433be1  5e                   pop esi
// 00433be2  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
