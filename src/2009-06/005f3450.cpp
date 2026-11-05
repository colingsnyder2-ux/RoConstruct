// from server: 100% by auto
// roc 2009-06 005f3450  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005f3450
//
// 005f3450  8b442408             mov eax, dword ptr [esp + 8]
// 005f3454  8b542404             mov edx, dword ptr [esp + 4]
// 005f3458  2bc2                 sub eax, edx
// 005f345a  c1f802               sar eax, 2
// 005f345d  56                   push esi
// 005f345e  8b742410             mov esi, dword ptr [esp + 0x10]
// 005f3462  8d0c8500000000       lea ecx, [eax*4]
// 005f3469  2bf1                 sub esi, ecx
// 005f346b  85c0                 test eax, eax
// 005f346d  7e0d                 jle 0x5f347c
// 005f346f  51                   push ecx
// 005f3470  52                   push edx
// 005f3471  51                   push ecx
// 005f3472  56                   push esi
// 005f3473  ff155ce98900         call dword ptr [0x89e95c]
// 005f3479  83c410               add esp, 0x10
// 005f347c  8bc6                 mov eax, esi
// 005f347e  5e                   pop esi
// 005f347f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
