// from server: 100% by auto
// roc 2009-12 005b15c0  unit: RBX::BrickBuilder  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b15c0
//
// 005b15c0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005b15c4  85c9                 test ecx, ecx
// 005b15c6  7626                 jbe 0x5b15ee
// 005b15c8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 005b15cc  8b442404             mov eax, dword ptr [esp + 4]
// 005b15d0  56                   push esi
// 005b15d1  85c0                 test eax, eax
// 005b15d3  7410                 je 0x5b15e5
// 005b15d5  8b32                 mov esi, dword ptr [edx]
// 005b15d7  8930                 mov dword ptr [eax], esi
// 005b15d9  8b7204               mov esi, dword ptr [edx + 4]
// 005b15dc  897004               mov dword ptr [eax + 4], esi
// 005b15df  8b7208               mov esi, dword ptr [edx + 8]
// 005b15e2  897008               mov dword ptr [eax + 8], esi
// 005b15e5  49                   dec ecx
// 005b15e6  83c00c               add eax, 0xc
// 005b15e9  85c9                 test ecx, ecx
// 005b15eb  77e4                 ja 0x5b15d1
// 005b15ed  5e                   pop esi
// 005b15ee  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
