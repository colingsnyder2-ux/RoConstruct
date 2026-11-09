// from server: 100% by auto
// roc 2008-06 004389f0  unit: IIHAAH::?$CMap  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004389f0
//
// 004389f0  8b442408             mov eax, dword ptr [esp + 8]
// 004389f4  8b542404             mov edx, dword ptr [esp + 4]
// 004389f8  2bc2                 sub eax, edx
// 004389fa  56                   push esi
// 004389fb  c1f802               sar eax, 2
// 004389fe  57                   push edi
// 004389ff  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00438a03  8d0c8500000000       lea ecx, [eax*4]
// 00438a0a  8d3439               lea esi, [ecx + edi]
// 00438a0d  85c0                 test eax, eax
// 00438a0f  7e0d                 jle 0x438a1e
// 00438a11  51                   push ecx
// 00438a12  52                   push edx
// 00438a13  51                   push ecx
// 00438a14  57                   push edi
// 00438a15  ff1550288000         call dword ptr [0x802850]
// 00438a1b  83c410               add esp, 0x10
// 00438a1e  5f                   pop edi
// 00438a1f  8bc6                 mov eax, esi
// 00438a21  5e                   pop esi
// 00438a22  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
