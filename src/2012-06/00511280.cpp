// from server: 100% by auto
// roc 2012-06 00511280  unit: Ogre::RbxSpatialHashedSceneNode  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00511280
//
// 00511280  8b542404             mov edx, dword ptr [esp + 4]
// 00511284  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00511288  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0051128c  3bd1                 cmp edx, ecx
// 0051128e  7429                 je 0x5112b9
// 00511290  56                   push esi
// 00511291  8b71ec               mov esi, dword ptr [ecx - 0x14]
// 00511294  83e914               sub ecx, 0x14
// 00511297  83e814               sub eax, 0x14
// 0051129a  8930                 mov dword ptr [eax], esi
// 0051129c  8b7104               mov esi, dword ptr [ecx + 4]
// 0051129f  897004               mov dword ptr [eax + 4], esi
// 005112a2  8b7108               mov esi, dword ptr [ecx + 8]
// 005112a5  897008               mov dword ptr [eax + 8], esi
// 005112a8  8b710c               mov esi, dword ptr [ecx + 0xc]
// 005112ab  89700c               mov dword ptr [eax + 0xc], esi
// 005112ae  8b7110               mov esi, dword ptr [ecx + 0x10]
// 005112b1  897010               mov dword ptr [eax + 0x10], esi
// 005112b4  3bca                 cmp ecx, edx
// 005112b6  75d9                 jne 0x511291
// 005112b8  5e                   pop esi
// 005112b9  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
