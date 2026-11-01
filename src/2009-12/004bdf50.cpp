// from server: 100% by auto
// roc 2009-12 004bdf50  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bdf50
//
// 004bdf50  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004bdf54  85c9                 test ecx, ecx
// 004bdf56  762c                 jbe 0x4bdf84
// 004bdf58  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004bdf5c  8b442404             mov eax, dword ptr [esp + 4]
// 004bdf60  56                   push esi
// 004bdf61  85c0                 test eax, eax
// 004bdf63  7416                 je 0x4bdf7b
// 004bdf65  8b32                 mov esi, dword ptr [edx]
// 004bdf67  8930                 mov dword ptr [eax], esi
// 004bdf69  8b7204               mov esi, dword ptr [edx + 4]
// 004bdf6c  897004               mov dword ptr [eax + 4], esi
// 004bdf6f  8b7208               mov esi, dword ptr [edx + 8]
// 004bdf72  897008               mov dword ptr [eax + 8], esi
// 004bdf75  8b720c               mov esi, dword ptr [edx + 0xc]
// 004bdf78  89700c               mov dword ptr [eax + 0xc], esi
// 004bdf7b  49                   dec ecx
// 004bdf7c  83c010               add eax, 0x10
// 004bdf7f  85c9                 test ecx, ecx
// 004bdf81  77de                 ja 0x4bdf61
// 004bdf83  5e                   pop esi
// 004bdf84  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
