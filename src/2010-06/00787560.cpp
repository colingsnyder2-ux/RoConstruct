// from server: 100% by auto
// roc 2010-06 00787560  unit: RBX::HUMAN::GettingUp  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787560
//
// 00787560  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00787564  85c9                 test ecx, ecx
// 00787566  7632                 jbe 0x78759a
// 00787568  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0078756c  8b442404             mov eax, dword ptr [esp + 4]
// 00787570  56                   push esi
// 00787571  85c0                 test eax, eax
// 00787573  741c                 je 0x787591
// 00787575  8b32                 mov esi, dword ptr [edx]
// 00787577  8930                 mov dword ptr [eax], esi
// 00787579  8b7204               mov esi, dword ptr [edx + 4]
// 0078757c  897004               mov dword ptr [eax + 4], esi
// 0078757f  8b7208               mov esi, dword ptr [edx + 8]
// 00787582  897008               mov dword ptr [eax + 8], esi
// 00787585  8b720c               mov esi, dword ptr [edx + 0xc]
// 00787588  89700c               mov dword ptr [eax + 0xc], esi
// 0078758b  8b7210               mov esi, dword ptr [edx + 0x10]
// 0078758e  897010               mov dword ptr [eax + 0x10], esi
// 00787591  49                   dec ecx
// 00787592  83c014               add eax, 0x14
// 00787595  85c9                 test ecx, ecx
// 00787597  77d8                 ja 0x787571
// 00787599  5e                   pop esi
// 0078759a  c3                   ret 
// standard library vector<pod20> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
