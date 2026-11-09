// from server: 100% by auto
// roc 2011-06 00969210  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00969210
//
// 00969210  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00969214  8b542408             mov edx, dword ptr [esp + 8]
// 00969218  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0096921c  3bca                 cmp ecx, edx
// 0096921e  741a                 je 0x96923a
// 00969220  56                   push esi
// 00969221  85c0                 test eax, eax
// 00969223  740a                 je 0x96922f
// 00969225  8b31                 mov esi, dword ptr [ecx]
// 00969227  8930                 mov dword ptr [eax], esi
// 00969229  8b7104               mov esi, dword ptr [ecx + 4]
// 0096922c  897004               mov dword ptr [eax + 4], esi
// 0096922f  83c108               add ecx, 8
// 00969232  83c008               add eax, 8
// 00969235  3bca                 cmp ecx, edx
// 00969237  75e8                 jne 0x969221
// 00969239  5e                   pop esi
// 0096923a  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
