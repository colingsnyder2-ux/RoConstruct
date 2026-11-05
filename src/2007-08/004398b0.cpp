// from server: 100% by auto
// roc 2007-08 004398b0  unit: RBX::VSoundId::?$XItem  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004398b0
//
// 004398b0  8b442408             mov eax, dword ptr [esp + 8]
// 004398b4  8b542404             mov edx, dword ptr [esp + 4]
// 004398b8  2bc2                 sub eax, edx
// 004398ba  56                   push esi
// 004398bb  c1f802               sar eax, 2
// 004398be  85c0                 test eax, eax
// 004398c0  57                   push edi
// 004398c1  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004398c5  8d0c8500000000       lea ecx, [eax*4]
// 004398cc  8d3439               lea esi, [ecx + edi]
// 004398cf  7e0d                 jle 0x4398de
// 004398d1  51                   push ecx
// 004398d2  52                   push edx
// 004398d3  51                   push ecx
// 004398d4  57                   push edi
// 004398d5  ff1548e77700         call dword ptr [0x77e748]
// 004398db  83c410               add esp, 0x10
// 004398de  5f                   pop edi
// 004398df  8bc6                 mov eax, esi
// 004398e1  5e                   pop esi
// 004398e2  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
