// from server: 100% by auto
// roc 2012-06 00605b60  unit: RBX::BrickBuilder  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00605b60
//
// 00605b60  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00605b64  85c9                 test ecx, ecx
// 00605b66  7626                 jbe 0x605b8e
// 00605b68  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00605b6c  8b442404             mov eax, dword ptr [esp + 4]
// 00605b70  56                   push esi
// 00605b71  85c0                 test eax, eax
// 00605b73  7410                 je 0x605b85
// 00605b75  8b32                 mov esi, dword ptr [edx]
// 00605b77  8930                 mov dword ptr [eax], esi
// 00605b79  8b7204               mov esi, dword ptr [edx + 4]
// 00605b7c  897004               mov dword ptr [eax + 4], esi
// 00605b7f  8b7208               mov esi, dword ptr [edx + 8]
// 00605b82  897008               mov dword ptr [eax + 8], esi
// 00605b85  49                   dec ecx
// 00605b86  83c00c               add eax, 0xc
// 00605b89  85c9                 test ecx, ecx
// 00605b8b  77e4                 ja 0x605b71
// 00605b8d  5e                   pop esi
// 00605b8e  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
