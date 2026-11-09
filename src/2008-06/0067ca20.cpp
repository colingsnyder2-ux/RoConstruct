// from server: 100% by auto
// roc 2008-06 0067ca20  unit: Ogre::RbxEntity  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067ca20
//
// 0067ca20  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067ca24  85c9                 test ecx, ecx
// 0067ca26  7620                 jbe 0x67ca48
// 0067ca28  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0067ca2c  8b442404             mov eax, dword ptr [esp + 4]
// 0067ca30  56                   push esi
// 0067ca31  85c0                 test eax, eax
// 0067ca33  740a                 je 0x67ca3f
// 0067ca35  8b32                 mov esi, dword ptr [edx]
// 0067ca37  8930                 mov dword ptr [eax], esi
// 0067ca39  8b7204               mov esi, dword ptr [edx + 4]
// 0067ca3c  897004               mov dword ptr [eax + 4], esi
// 0067ca3f  49                   dec ecx
// 0067ca40  83c008               add eax, 8
// 0067ca43  85c9                 test ecx, ecx
// 0067ca45  77ea                 ja 0x67ca31
// 0067ca47  5e                   pop esi
// 0067ca48  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
