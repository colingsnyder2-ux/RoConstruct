// from server: 100% by auto
// roc 2010-06 00434f60  unit: CPropGrid::UpdateItemsJob  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00434f60
//
// 00434f60  8b442408             mov eax, dword ptr [esp + 8]
// 00434f64  8b542404             mov edx, dword ptr [esp + 4]
// 00434f68  2bc2                 sub eax, edx
// 00434f6a  c1f802               sar eax, 2
// 00434f6d  56                   push esi
// 00434f6e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00434f72  8d0c8500000000       lea ecx, [eax*4]
// 00434f79  2bf1                 sub esi, ecx
// 00434f7b  85c0                 test eax, eax
// 00434f7d  7e0d                 jle 0x434f8c
// 00434f7f  51                   push ecx
// 00434f80  52                   push edx
// 00434f81  51                   push ecx
// 00434f82  56                   push esi
// 00434f83  ff1580a89e00         call dword ptr [0x9ea880]
// 00434f89  83c410               add esp, 0x10
// 00434f8c  8bc6                 mov eax, esi
// 00434f8e  5e                   pop esi
// 00434f8f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
