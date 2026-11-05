// from server: 100% by auto
// roc 2010-06 0096a4a0  unit: Ogre::RbxSceneUpdater  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a4a0
//
// 0096a4a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0096a4a4  8b542408             mov edx, dword ptr [esp + 8]
// 0096a4a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0096a4ac  3bca                 cmp ecx, edx
// 0096a4ae  7432                 je 0x96a4e2
// 0096a4b0  56                   push esi
// 0096a4b1  85c0                 test eax, eax
// 0096a4b3  7422                 je 0x96a4d7
// 0096a4b5  8b31                 mov esi, dword ptr [ecx]
// 0096a4b7  8930                 mov dword ptr [eax], esi
// 0096a4b9  8b7104               mov esi, dword ptr [ecx + 4]
// 0096a4bc  897004               mov dword ptr [eax + 4], esi
// 0096a4bf  8b7108               mov esi, dword ptr [ecx + 8]
// 0096a4c2  897008               mov dword ptr [eax + 8], esi
// 0096a4c5  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0096a4c8  89700c               mov dword ptr [eax + 0xc], esi
// 0096a4cb  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0096a4ce  897010               mov dword ptr [eax + 0x10], esi
// 0096a4d1  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0096a4d4  897014               mov dword ptr [eax + 0x14], esi
// 0096a4d7  83c118               add ecx, 0x18
// 0096a4da  83c018               add eax, 0x18
// 0096a4dd  3bca                 cmp ecx, edx
// 0096a4df  75d0                 jne 0x96a4b1
// 0096a4e1  5e                   pop esi
// 0096a4e2  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
