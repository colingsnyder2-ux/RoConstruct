// from server: 100% by auto
// roc 2011-06 007b5640  unit: RBX::TreeStage  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b5640
//
// 007b5640  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007b5644  85c9                 test ecx, ecx
// 007b5646  762c                 jbe 0x7b5674
// 007b5648  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007b564c  8b442404             mov eax, dword ptr [esp + 4]
// 007b5650  56                   push esi
// 007b5651  85c0                 test eax, eax
// 007b5653  7416                 je 0x7b566b
// 007b5655  8b32                 mov esi, dword ptr [edx]
// 007b5657  8930                 mov dword ptr [eax], esi
// 007b5659  8b7204               mov esi, dword ptr [edx + 4]
// 007b565c  897004               mov dword ptr [eax + 4], esi
// 007b565f  8b7208               mov esi, dword ptr [edx + 8]
// 007b5662  897008               mov dword ptr [eax + 8], esi
// 007b5665  8b720c               mov esi, dword ptr [edx + 0xc]
// 007b5668  89700c               mov dword ptr [eax + 0xc], esi
// 007b566b  49                   dec ecx
// 007b566c  83c010               add eax, 0x10
// 007b566f  85c9                 test ecx, ecx
// 007b5671  77de                 ja 0x7b5651
// 007b5673  5e                   pop esi
// 007b5674  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
