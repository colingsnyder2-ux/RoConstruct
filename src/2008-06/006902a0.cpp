// from server: 100% by auto
// roc 2008-06 006902a0  unit: Ogre::RbxSceneManagerFactory  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006902a0
//
// 006902a0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006902a4  85c9                 test ecx, ecx
// 006902a6  7626                 jbe 0x6902ce
// 006902a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006902ac  8b442404             mov eax, dword ptr [esp + 4]
// 006902b0  56                   push esi
// 006902b1  85c0                 test eax, eax
// 006902b3  7410                 je 0x6902c5
// 006902b5  8b32                 mov esi, dword ptr [edx]
// 006902b7  8930                 mov dword ptr [eax], esi
// 006902b9  8b7204               mov esi, dword ptr [edx + 4]
// 006902bc  897004               mov dword ptr [eax + 4], esi
// 006902bf  8b7208               mov esi, dword ptr [edx + 8]
// 006902c2  897008               mov dword ptr [eax + 8], esi
// 006902c5  49                   dec ecx
// 006902c6  83c00c               add eax, 0xc
// 006902c9  85c9                 test ecx, ecx
// 006902cb  77e4                 ja 0x6902b1
// 006902cd  5e                   pop esi
// 006902ce  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
