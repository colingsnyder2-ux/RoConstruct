// from server: 100% by auto
// roc 2008-06 00459670  unit: CRobloxView  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459670
//
// 00459670  8b442408             mov eax, dword ptr [esp + 8]
// 00459674  8b542404             mov edx, dword ptr [esp + 4]
// 00459678  2bc2                 sub eax, edx
// 0045967a  c1f802               sar eax, 2
// 0045967d  56                   push esi
// 0045967e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00459682  8d0c8500000000       lea ecx, [eax*4]
// 00459689  2bf1                 sub esi, ecx
// 0045968b  85c0                 test eax, eax
// 0045968d  7e0d                 jle 0x45969c
// 0045968f  51                   push ecx
// 00459690  52                   push edx
// 00459691  51                   push ecx
// 00459692  56                   push esi
// 00459693  ff1550288000         call dword ptr [0x802850]
// 00459699  83c410               add esp, 0x10
// 0045969c  8bc6                 mov eax, esi
// 0045969e  5e                   pop esi
// 0045969f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
