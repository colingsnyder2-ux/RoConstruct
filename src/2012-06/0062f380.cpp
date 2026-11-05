// from server: 100% by auto
// roc 2012-06 0062f380  unit: G3D::BinaryInput  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062f380
//
// 0062f380  8b442408             mov eax, dword ptr [esp + 8]
// 0062f384  8b542404             mov edx, dword ptr [esp + 4]
// 0062f388  2bc2                 sub eax, edx
// 0062f38a  56                   push esi
// 0062f38b  c1f802               sar eax, 2
// 0062f38e  57                   push edi
// 0062f38f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0062f393  8d0c8500000000       lea ecx, [eax*4]
// 0062f39a  8d3439               lea esi, [ecx + edi]
// 0062f39d  85c0                 test eax, eax
// 0062f39f  7e0d                 jle 0x62f3ae
// 0062f3a1  51                   push ecx
// 0062f3a2  52                   push edx
// 0062f3a3  51                   push ecx
// 0062f3a4  57                   push edi
// 0062f3a5  ff15c02ab200         call dword ptr [0xb22ac0]
// 0062f3ab  83c410               add esp, 0x10
// 0062f3ae  5f                   pop edi
// 0062f3af  8bc6                 mov eax, esi
// 0062f3b1  5e                   pop esi
// 0062f3b2  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
