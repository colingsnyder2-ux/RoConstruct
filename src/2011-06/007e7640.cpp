// from server: 100% by auto
// roc 2011-06 007e7640  unit: RBX::AdvRotateTool  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e7640
//
// 007e7640  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e7644  85c9                 test ecx, ecx
// 007e7646  7632                 jbe 0x7e767a
// 007e7648  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007e764c  8b442404             mov eax, dword ptr [esp + 4]
// 007e7650  56                   push esi
// 007e7651  85c0                 test eax, eax
// 007e7653  741c                 je 0x7e7671
// 007e7655  8b32                 mov esi, dword ptr [edx]
// 007e7657  8930                 mov dword ptr [eax], esi
// 007e7659  8b7204               mov esi, dword ptr [edx + 4]
// 007e765c  897004               mov dword ptr [eax + 4], esi
// 007e765f  8b7208               mov esi, dword ptr [edx + 8]
// 007e7662  897008               mov dword ptr [eax + 8], esi
// 007e7665  8b720c               mov esi, dword ptr [edx + 0xc]
// 007e7668  89700c               mov dword ptr [eax + 0xc], esi
// 007e766b  8b7210               mov esi, dword ptr [edx + 0x10]
// 007e766e  897010               mov dword ptr [eax + 0x10], esi
// 007e7671  49                   dec ecx
// 007e7672  83c014               add eax, 0x14
// 007e7675  85c9                 test ecx, ecx
// 007e7677  77d8                 ja 0x7e7651
// 007e7679  5e                   pop esi
// 007e767a  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
