// from server: 100% by auto
// roc 2010-06 008fe6b0  unit: Ogre::RbxSceneUpdater  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe6b0
//
// 008fe6b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008fe6b4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008fe6b8  56                   push esi
// 008fe6b9  8b742408             mov esi, dword ptr [esp + 8]
// 008fe6bd  8bc1                 mov eax, ecx
// 008fe6bf  2bc6                 sub eax, esi
// 008fe6c1  c1f803               sar eax, 3
// 008fe6c4  03c0                 add eax, eax
// 008fe6c6  03c0                 add eax, eax
// 008fe6c8  03c0                 add eax, eax
// 008fe6ca  57                   push edi
// 008fe6cb  8bf8                 mov edi, eax
// 008fe6cd  8bc2                 mov eax, edx
// 008fe6cf  2bc7                 sub eax, edi
// 008fe6d1  3bf1                 cmp esi, ecx
// 008fe6d3  7416                 je 0x8fe6eb
// 008fe6d5  2bd1                 sub edx, ecx
// 008fe6d7  8b79f8               mov edi, dword ptr [ecx - 8]
// 008fe6da  83e908               sub ecx, 8
// 008fe6dd  893c0a               mov dword ptr [edx + ecx], edi
// 008fe6e0  8b7904               mov edi, dword ptr [ecx + 4]
// 008fe6e3  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 008fe6e7  3bce                 cmp ecx, esi
// 008fe6e9  75ec                 jne 0x8fe6d7
// 008fe6eb  5f                   pop edi
// 008fe6ec  5e                   pop esi
// 008fe6ed  c3                   ret 
// standard library vector<pod8> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
