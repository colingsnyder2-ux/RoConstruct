// from server: 100% by auto
// roc 2010-06 007870d0  unit: RBX::HUMAN::GettingUp  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007870d0
//
// 007870d0  8b442408             mov eax, dword ptr [esp + 8]
// 007870d4  8b542404             mov edx, dword ptr [esp + 4]
// 007870d8  2bc2                 sub eax, edx
// 007870da  56                   push esi
// 007870db  c1f802               sar eax, 2
// 007870de  57                   push edi
// 007870df  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007870e3  8d0c8500000000       lea ecx, [eax*4]
// 007870ea  8d3439               lea esi, [ecx + edi]
// 007870ed  85c0                 test eax, eax
// 007870ef  7e0d                 jle 0x7870fe
// 007870f1  51                   push ecx
// 007870f2  52                   push edx
// 007870f3  51                   push ecx
// 007870f4  57                   push edi
// 007870f5  ff1580a89e00         call dword ptr [0x9ea880]
// 007870fb  83c410               add esp, 0x10
// 007870fe  5f                   pop edi
// 007870ff  8bc6                 mov eax, esi
// 00787101  5e                   pop esi
// 00787102  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
