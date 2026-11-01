// from server: 100% by auto
// roc 2009-12 0047f600  unit: RBX::AdornRbxGfx  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047f600
//
// 0047f600  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047f604  85c9                 test ecx, ecx
// 0047f606  7620                 jbe 0x47f628
// 0047f608  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0047f60c  8b442404             mov eax, dword ptr [esp + 4]
// 0047f610  56                   push esi
// 0047f611  85c0                 test eax, eax
// 0047f613  740a                 je 0x47f61f
// 0047f615  8b32                 mov esi, dword ptr [edx]
// 0047f617  8930                 mov dword ptr [eax], esi
// 0047f619  8b7204               mov esi, dword ptr [edx + 4]
// 0047f61c  897004               mov dword ptr [eax + 4], esi
// 0047f61f  49                   dec ecx
// 0047f620  83c008               add eax, 8
// 0047f623  85c9                 test ecx, ecx
// 0047f625  77ea                 ja 0x47f611
// 0047f627  5e                   pop esi
// 0047f628  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
