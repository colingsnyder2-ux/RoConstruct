// from server: 100% by auto
// roc 2009-06 00432430  unit: IIHAAH::?$CMap  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00432430
//
// 00432430  8b442408             mov eax, dword ptr [esp + 8]
// 00432434  8b542404             mov edx, dword ptr [esp + 4]
// 00432438  2bc2                 sub eax, edx
// 0043243a  56                   push esi
// 0043243b  c1f802               sar eax, 2
// 0043243e  57                   push edi
// 0043243f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00432443  8d0c8500000000       lea ecx, [eax*4]
// 0043244a  8d3439               lea esi, [ecx + edi]
// 0043244d  85c0                 test eax, eax
// 0043244f  7e0d                 jle 0x43245e
// 00432451  51                   push ecx
// 00432452  52                   push edx
// 00432453  51                   push ecx
// 00432454  57                   push edi
// 00432455  ff155ce98900         call dword ptr [0x89e95c]
// 0043245b  83c410               add esp, 0x10
// 0043245e  5f                   pop edi
// 0043245f  8bc6                 mov eax, esi
// 00432461  5e                   pop esi
// 00432462  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
