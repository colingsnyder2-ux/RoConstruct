// from server: 100% by auto
// roc 2011-06 006d3600  unit: RBX::VMotor::?$FactoryProduct  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006d3600
//
// 006d3600  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d3604  85c9                 test ecx, ecx
// 006d3606  7626                 jbe 0x6d362e
// 006d3608  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006d360c  8b442404             mov eax, dword ptr [esp + 4]
// 006d3610  56                   push esi
// 006d3611  85c0                 test eax, eax
// 006d3613  7410                 je 0x6d3625
// 006d3615  8b32                 mov esi, dword ptr [edx]
// 006d3617  8930                 mov dword ptr [eax], esi
// 006d3619  8b7204               mov esi, dword ptr [edx + 4]
// 006d361c  897004               mov dword ptr [eax + 4], esi
// 006d361f  8b7208               mov esi, dword ptr [edx + 8]
// 006d3622  897008               mov dword ptr [eax + 8], esi
// 006d3625  49                   dec ecx
// 006d3626  83c00c               add eax, 0xc
// 006d3629  85c9                 test ecx, ecx
// 006d362b  77e4                 ja 0x6d3611
// 006d362d  5e                   pop esi
// 006d362e  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
