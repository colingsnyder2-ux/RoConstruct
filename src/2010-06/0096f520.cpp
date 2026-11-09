// from server: 100% by auto
// roc 2010-06 0096f520  unit: seg_00960000  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f520
//
// 0096f520  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0096f524  56                   push esi
// 0096f525  8b742408             mov esi, dword ptr [esp + 8]
// 0096f529  8bd1                 mov edx, ecx
// 0096f52b  2bd6                 sub edx, esi
// 0096f52d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0096f532  f7ea                 imul edx
// 0096f534  d1fa                 sar edx, 1
// 0096f536  8bc2                 mov eax, edx
// 0096f538  c1e81f               shr eax, 0x1f
// 0096f53b  03c2                 add eax, edx
// 0096f53d  8b542410             mov edx, dword ptr [esp + 0x10]
// 0096f541  8d0440               lea eax, [eax + eax*2]
// 0096f544  03c0                 add eax, eax
// 0096f546  03c0                 add eax, eax
// 0096f548  57                   push edi
// 0096f549  8bf8                 mov edi, eax
// 0096f54b  8bc2                 mov eax, edx
// 0096f54d  2bc7                 sub eax, edi
// 0096f54f  3bf1                 cmp esi, ecx
// 0096f551  741d                 je 0x96f570
// 0096f553  2bd1                 sub edx, ecx
// 0096f555  8b79f4               mov edi, dword ptr [ecx - 0xc]
// 0096f558  83e90c               sub ecx, 0xc
// 0096f55b  893c0a               mov dword ptr [edx + ecx], edi
// 0096f55e  8b7904               mov edi, dword ptr [ecx + 4]
// 0096f561  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 0096f565  8b7908               mov edi, dword ptr [ecx + 8]
// 0096f568  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 0096f56c  3bce                 cmp ecx, esi
// 0096f56e  75e5                 jne 0x96f555
// 0096f570  5f                   pop edi
// 0096f571  5e                   pop esi
// 0096f572  c3                   ret 
// standard library vector<pod12> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
