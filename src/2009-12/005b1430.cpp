// from server: 100% by auto
// roc 2009-12 005b1430  unit: RBX::BrickBuilder  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b1430
//
// 005b1430  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b1434  56                   push esi
// 005b1435  8b742408             mov esi, dword ptr [esp + 8]
// 005b1439  8bd1                 mov edx, ecx
// 005b143b  2bd6                 sub edx, esi
// 005b143d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005b1442  f7ea                 imul edx
// 005b1444  d1fa                 sar edx, 1
// 005b1446  8bc2                 mov eax, edx
// 005b1448  c1e81f               shr eax, 0x1f
// 005b144b  03c2                 add eax, edx
// 005b144d  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b1451  8d0440               lea eax, [eax + eax*2]
// 005b1454  03c0                 add eax, eax
// 005b1456  03c0                 add eax, eax
// 005b1458  57                   push edi
// 005b1459  8bf8                 mov edi, eax
// 005b145b  8bc2                 mov eax, edx
// 005b145d  2bc7                 sub eax, edi
// 005b145f  3bf1                 cmp esi, ecx
// 005b1461  741d                 je 0x5b1480
// 005b1463  2bd1                 sub edx, ecx
// 005b1465  8b79f4               mov edi, dword ptr [ecx - 0xc]
// 005b1468  83e90c               sub ecx, 0xc
// 005b146b  893c0a               mov dword ptr [edx + ecx], edi
// 005b146e  8b7904               mov edi, dword ptr [ecx + 4]
// 005b1471  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 005b1475  8b7908               mov edi, dword ptr [ecx + 8]
// 005b1478  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 005b147c  3bce                 cmp ecx, esi
// 005b147e  75e5                 jne 0x5b1465
// 005b1480  5f                   pop edi
// 005b1481  5e                   pop esi
// 005b1482  c3                   ret 
// standard library vector<pod12> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
