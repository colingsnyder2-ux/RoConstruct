// from server: 100% by auto
// roc 2011-06 005434f0  unit: G3D::BinaryInput  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005434f0
//
// 005434f0  8b442408             mov eax, dword ptr [esp + 8]
// 005434f4  8b542404             mov edx, dword ptr [esp + 4]
// 005434f8  2bc2                 sub eax, edx
// 005434fa  56                   push esi
// 005434fb  c1f802               sar eax, 2
// 005434fe  57                   push edi
// 005434ff  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00543503  8d0c8500000000       lea ecx, [eax*4]
// 0054350a  8d3439               lea esi, [ecx + edi]
// 0054350d  85c0                 test eax, eax
// 0054350f  7e0d                 jle 0x54351e
// 00543511  51                   push ecx
// 00543512  52                   push edx
// 00543513  51                   push ecx
// 00543514  57                   push edi
// 00543515  ff15fc09a400         call dword ptr [0xa409fc]
// 0054351b  83c410               add esp, 0x10
// 0054351e  5f                   pop edi
// 0054351f  8bc6                 mov eax, esi
// 00543521  5e                   pop esi
// 00543522  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
