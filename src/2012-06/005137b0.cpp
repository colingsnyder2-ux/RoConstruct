// from server: 100% by auto
// roc 2012-06 005137b0  unit: Ogre::RbxSpatialHashedSceneNode  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005137b0
//
// 005137b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005137b4  85c9                 test ecx, ecx
// 005137b6  7632                 jbe 0x5137ea
// 005137b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005137bc  8b442404             mov eax, dword ptr [esp + 4]
// 005137c0  56                   push esi
// 005137c1  85c0                 test eax, eax
// 005137c3  741c                 je 0x5137e1
// 005137c5  8b32                 mov esi, dword ptr [edx]
// 005137c7  8930                 mov dword ptr [eax], esi
// 005137c9  8b7204               mov esi, dword ptr [edx + 4]
// 005137cc  897004               mov dword ptr [eax + 4], esi
// 005137cf  8b7208               mov esi, dword ptr [edx + 8]
// 005137d2  897008               mov dword ptr [eax + 8], esi
// 005137d5  8b720c               mov esi, dword ptr [edx + 0xc]
// 005137d8  89700c               mov dword ptr [eax + 0xc], esi
// 005137db  8b7210               mov esi, dword ptr [edx + 0x10]
// 005137de  897010               mov dword ptr [eax + 0x10], esi
// 005137e1  49                   dec ecx
// 005137e2  83c014               add eax, 0x14
// 005137e5  85c9                 test ecx, ecx
// 005137e7  77d8                 ja 0x5137c1
// 005137e9  5e                   pop esi
// 005137ea  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
