// from server: 100% by auto
// roc 2008-06 0065a830  unit: RBX::BallBallContact  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065a830
//
// 0065a830  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065a834  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0065a838  56                   push esi
// 0065a839  8b742408             mov esi, dword ptr [esp + 8]
// 0065a83d  8bc1                 mov eax, ecx
// 0065a83f  2bc6                 sub eax, esi
// 0065a841  c1f803               sar eax, 3
// 0065a844  03c0                 add eax, eax
// 0065a846  03c0                 add eax, eax
// 0065a848  03c0                 add eax, eax
// 0065a84a  57                   push edi
// 0065a84b  8bf8                 mov edi, eax
// 0065a84d  8bc2                 mov eax, edx
// 0065a84f  2bc7                 sub eax, edi
// 0065a851  3bf1                 cmp esi, ecx
// 0065a853  7416                 je 0x65a86b
// 0065a855  2bd1                 sub edx, ecx
// 0065a857  8b79f8               mov edi, dword ptr [ecx - 8]
// 0065a85a  83e908               sub ecx, 8
// 0065a85d  893c0a               mov dword ptr [edx + ecx], edi
// 0065a860  8b7904               mov edi, dword ptr [ecx + 4]
// 0065a863  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 0065a867  3bce                 cmp ecx, esi
// 0065a869  75ec                 jne 0x65a857
// 0065a86b  5f                   pop edi
// 0065a86c  5e                   pop esi
// 0065a86d  c3                   ret 
// standard library vector<pod8> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
