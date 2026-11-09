// from server: 100% by auto
// roc 2010-06 009045a0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009045a0
//
// 009045a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009045a4  85c9                 test ecx, ecx
// 009045a6  762c                 jbe 0x9045d4
// 009045a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 009045ac  8b442404             mov eax, dword ptr [esp + 4]
// 009045b0  56                   push esi
// 009045b1  85c0                 test eax, eax
// 009045b3  7416                 je 0x9045cb
// 009045b5  8b32                 mov esi, dword ptr [edx]
// 009045b7  8930                 mov dword ptr [eax], esi
// 009045b9  8b7204               mov esi, dword ptr [edx + 4]
// 009045bc  897004               mov dword ptr [eax + 4], esi
// 009045bf  8b7208               mov esi, dword ptr [edx + 8]
// 009045c2  897008               mov dword ptr [eax + 8], esi
// 009045c5  8b720c               mov esi, dword ptr [edx + 0xc]
// 009045c8  89700c               mov dword ptr [eax + 0xc], esi
// 009045cb  49                   dec ecx
// 009045cc  83c010               add eax, 0x10
// 009045cf  85c9                 test ecx, ecx
// 009045d1  77de                 ja 0x9045b1
// 009045d3  5e                   pop esi
// 009045d4  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
