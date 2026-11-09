// from server: 100% by auto
// roc 2008-06 0068e250  unit: Ogre::VRbxSky::?$SharedPtr  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068e250
//
// 0068e250  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068e254  56                   push esi
// 0068e255  8b742408             mov esi, dword ptr [esp + 8]
// 0068e259  8bd1                 mov edx, ecx
// 0068e25b  2bd6                 sub edx, esi
// 0068e25d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0068e262  f7ea                 imul edx
// 0068e264  d1fa                 sar edx, 1
// 0068e266  8bc2                 mov eax, edx
// 0068e268  c1e81f               shr eax, 0x1f
// 0068e26b  03c2                 add eax, edx
// 0068e26d  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068e271  8d0440               lea eax, [eax + eax*2]
// 0068e274  03c0                 add eax, eax
// 0068e276  03c0                 add eax, eax
// 0068e278  57                   push edi
// 0068e279  8bf8                 mov edi, eax
// 0068e27b  8bc2                 mov eax, edx
// 0068e27d  2bc7                 sub eax, edi
// 0068e27f  3bf1                 cmp esi, ecx
// 0068e281  741d                 je 0x68e2a0
// 0068e283  2bd1                 sub edx, ecx
// 0068e285  8b79f4               mov edi, dword ptr [ecx - 0xc]
// 0068e288  83e90c               sub ecx, 0xc
// 0068e28b  893c0a               mov dword ptr [edx + ecx], edi
// 0068e28e  8b7904               mov edi, dword ptr [ecx + 4]
// 0068e291  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 0068e295  8b7908               mov edi, dword ptr [ecx + 8]
// 0068e298  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 0068e29c  3bce                 cmp ecx, esi
// 0068e29e  75e5                 jne 0x68e285
// 0068e2a0  5f                   pop edi
// 0068e2a1  5e                   pop esi
// 0068e2a2  c3                   ret 
// standard library vector<pod12> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
