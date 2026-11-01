// from server: 100% by auto
// roc 2009-12 004bdc70  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bdc70
//
// 004bdc70  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bdc74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004bdc78  56                   push esi
// 004bdc79  8b742408             mov esi, dword ptr [esp + 8]
// 004bdc7d  8bc1                 mov eax, ecx
// 004bdc7f  2bc6                 sub eax, esi
// 004bdc81  c1f804               sar eax, 4
// 004bdc84  c1e004               shl eax, 4
// 004bdc87  57                   push edi
// 004bdc88  8bf8                 mov edi, eax
// 004bdc8a  8bc2                 mov eax, edx
// 004bdc8c  2bc7                 sub eax, edi
// 004bdc8e  3bf1                 cmp esi, ecx
// 004bdc90  7424                 je 0x4bdcb6
// 004bdc92  2bd1                 sub edx, ecx
// 004bdc94  8b79f0               mov edi, dword ptr [ecx - 0x10]
// 004bdc97  83e910               sub ecx, 0x10
// 004bdc9a  893c0a               mov dword ptr [edx + ecx], edi
// 004bdc9d  8b7904               mov edi, dword ptr [ecx + 4]
// 004bdca0  897c0a04             mov dword ptr [edx + ecx + 4], edi
// 004bdca4  8b7908               mov edi, dword ptr [ecx + 8]
// 004bdca7  897c0a08             mov dword ptr [edx + ecx + 8], edi
// 004bdcab  8b790c               mov edi, dword ptr [ecx + 0xc]
// 004bdcae  897c0a0c             mov dword ptr [edx + ecx + 0xc], edi
// 004bdcb2  3bce                 cmp ecx, esi
// 004bdcb4  75de                 jne 0x4bdc94
// 004bdcb6  5f                   pop edi
// 004bdcb7  5e                   pop esi
// 004bdcb8  c3                   ret 
// standard library vector<pod16> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
