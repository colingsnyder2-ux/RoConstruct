// from server: 100% by auto
// roc 2009-06 00485540  unit: RBX::MeshFileKey  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485540
//
// 00485540  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00485544  85c9                 test ecx, ecx
// 00485546  762c                 jbe 0x485574
// 00485548  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048554c  8b442404             mov eax, dword ptr [esp + 4]
// 00485550  56                   push esi
// 00485551  85c0                 test eax, eax
// 00485553  7416                 je 0x48556b
// 00485555  8b32                 mov esi, dword ptr [edx]
// 00485557  8930                 mov dword ptr [eax], esi
// 00485559  8b7204               mov esi, dword ptr [edx + 4]
// 0048555c  897004               mov dword ptr [eax + 4], esi
// 0048555f  8b7208               mov esi, dword ptr [edx + 8]
// 00485562  897008               mov dword ptr [eax + 8], esi
// 00485565  8b720c               mov esi, dword ptr [edx + 0xc]
// 00485568  89700c               mov dword ptr [eax + 0xc], esi
// 0048556b  49                   dec ecx
// 0048556c  83c010               add eax, 0x10
// 0048556f  85c9                 test ecx, ecx
// 00485571  77de                 ja 0x485551
// 00485573  5e                   pop esi
// 00485574  c3                   ret 
// standard library vector<pod16> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
