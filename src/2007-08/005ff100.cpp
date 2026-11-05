// from server: 100% by auto
// roc 2007-08 005ff100  unit: RBX::RedoVerb  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005ff100
//
// 005ff100  8b442408             mov eax, dword ptr [esp + 8]
// 005ff104  8b542404             mov edx, dword ptr [esp + 4]
// 005ff108  2bc2                 sub eax, edx
// 005ff10a  c1f802               sar eax, 2
// 005ff10d  56                   push esi
// 005ff10e  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ff112  8d0c8500000000       lea ecx, [eax*4]
// 005ff119  2bf1                 sub esi, ecx
// 005ff11b  85c0                 test eax, eax
// 005ff11d  7e0d                 jle 0x5ff12c
// 005ff11f  51                   push ecx
// 005ff120  52                   push edx
// 005ff121  51                   push ecx
// 005ff122  56                   push esi
// 005ff123  ff1548e77700         call dword ptr [0x77e748]
// 005ff129  83c410               add esp, 0x10
// 005ff12c  8bc6                 mov eax, esi
// 005ff12e  5e                   pop esi
// 005ff12f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
