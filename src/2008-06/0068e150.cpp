// from server: 100% by auto
// roc 2008-06 0068e150  unit: Ogre::VRbxSky::?$SharedPtr  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068e150
//
// 0068e150  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068e154  56                   push esi
// 0068e155  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068e159  8bd6                 mov edx, esi
// 0068e15b  2bd1                 sub edx, ecx
// 0068e15d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068e162  f7ea                 imul edx
// 0068e164  d1fa                 sar edx, 1
// 0068e166  8bc2                 mov eax, edx
// 0068e168  c1e81f               shr eax, 0x1f
// 0068e16b  03c2                 add eax, edx
// 0068e16d  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068e171  8d0440               lea eax, [eax + eax*2]
// 0068e174  8d0482               lea eax, [edx + eax*4]
// 0068e177  3bce                 cmp ecx, esi
// 0068e179  7420                 je 0x68e19b
// 0068e17b  2bd1                 sub edx, ecx
// 0068e17d  57                   push edi
// 0068e17e  8bff                 mov edi, edi
// 0068e180  8b39                 mov edi, dword ptr [ecx]
// 0068e182  893c0a               mov dword ptr [edx + ecx], edi
// 0068e185  8b7904               mov edi, dword ptr [ecx + 4]
// 0068e188  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 0068e18c  8b7908               mov edi, dword ptr [ecx + 8]
// 0068e18f  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 0068e193  83c10c               add ecx, 0xc
// 0068e196  3bce                 cmp ecx, esi
// 0068e198  75e6                 jne 0x68e180
// 0068e19a  5f                   pop edi
// 0068e19b  5e                   pop esi
// 0068e19c  c3                   ret 
// standard library vector<pod12> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
