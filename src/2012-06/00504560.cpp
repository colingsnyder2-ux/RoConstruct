// from server: 100% by auto
// roc 2012-06 00504560  unit: Ogre::RbxMeshPartAdapter  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00504560
//
// 00504560  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00504564  85c9                 test ecx, ecx
// 00504566  7620                 jbe 0x504588
// 00504568  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050456c  8b442404             mov eax, dword ptr [esp + 4]
// 00504570  56                   push esi
// 00504571  85c0                 test eax, eax
// 00504573  740a                 je 0x50457f
// 00504575  8b32                 mov esi, dword ptr [edx]
// 00504577  8930                 mov dword ptr [eax], esi
// 00504579  8b7204               mov esi, dword ptr [edx + 4]
// 0050457c  897004               mov dword ptr [eax + 4], esi
// 0050457f  49                   dec ecx
// 00504580  83c008               add eax, 8
// 00504583  85c9                 test ecx, ecx
// 00504585  77ea                 ja 0x504571
// 00504587  5e                   pop esi
// 00504588  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
