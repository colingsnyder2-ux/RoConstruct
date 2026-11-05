// from server: 100% by auto
// roc 2012-06 0050d600  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050d600
//
// 0050d600  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050d604  85c9                 test ecx, ecx
// 0050d606  762c                 jbe 0x50d634
// 0050d608  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0050d60c  8b442404             mov eax, dword ptr [esp + 4]
// 0050d610  56                   push esi
// 0050d611  85c0                 test eax, eax
// 0050d613  7416                 je 0x50d62b
// 0050d615  8b32                 mov esi, dword ptr [edx]
// 0050d617  8930                 mov dword ptr [eax], esi
// 0050d619  8b7204               mov esi, dword ptr [edx + 4]
// 0050d61c  897004               mov dword ptr [eax + 4], esi
// 0050d61f  8b7208               mov esi, dword ptr [edx + 8]
// 0050d622  897008               mov dword ptr [eax + 8], esi
// 0050d625  8b720c               mov esi, dword ptr [edx + 0xc]
// 0050d628  89700c               mov dword ptr [eax + 0xc], esi
// 0050d62b  49                   dec ecx
// 0050d62c  83c010               add eax, 0x10
// 0050d62f  85c9                 test ecx, ecx
// 0050d631  77de                 ja 0x50d611
// 0050d633  5e                   pop esi
// 0050d634  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
