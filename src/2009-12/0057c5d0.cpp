// from server: 100% by auto
// roc 2009-12 0057c5d0  unit: std::Vlength_error::?$error_info_injector  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057c5d0
//
// 0057c5d0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057c5d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0057c5d8  56                   push esi
// 0057c5d9  8b742408             mov esi, dword ptr [esp + 8]
// 0057c5dd  8bc1                 mov eax, ecx
// 0057c5df  2bc6                 sub eax, esi
// 0057c5e1  c1f803               sar eax, 3
// 0057c5e4  03c0                 add eax, eax
// 0057c5e6  03c0                 add eax, eax
// 0057c5e8  03c0                 add eax, eax
// 0057c5ea  57                   push edi
// 0057c5eb  8bf8                 mov edi, eax
// 0057c5ed  8bc2                 mov eax, edx
// 0057c5ef  2bc7                 sub eax, edi
// 0057c5f1  3bf1                 cmp esi, ecx
// 0057c5f3  7416                 je 0x57c60b
// 0057c5f5  2bd1                 sub edx, ecx
// 0057c5f7  8b79f8               mov edi, dword ptr [ecx - 8]
// 0057c5fa  83e908               sub ecx, 8
// 0057c5fd  893c0a               mov dword ptr [edx + ecx], edi
// 0057c600  8b7904               mov edi, dword ptr [ecx + 4]
// 0057c603  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 0057c607  3bce                 cmp ecx, esi
// 0057c609  75ec                 jne 0x57c5f7
// 0057c60b  5f                   pop edi
// 0057c60c  5e                   pop esi
// 0057c60d  c3                   ret 
// standard library vector<pod8> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
