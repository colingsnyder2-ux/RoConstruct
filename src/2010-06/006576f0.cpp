// from server: 100% by auto
// roc 2010-06 006576f0  unit: RBX::Network::P8Player::?$GetSetImpl  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006576f0
//
// 006576f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006576f4  85c9                 test ecx, ecx
// 006576f6  7620                 jbe 0x657718
// 006576f8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006576fc  8b442404             mov eax, dword ptr [esp + 4]
// 00657700  56                   push esi
// 00657701  85c0                 test eax, eax
// 00657703  740a                 je 0x65770f
// 00657705  8b32                 mov esi, dword ptr [edx]
// 00657707  8930                 mov dword ptr [eax], esi
// 00657709  8b7204               mov esi, dword ptr [edx + 4]
// 0065770c  897004               mov dword ptr [eax + 4], esi
// 0065770f  49                   dec ecx
// 00657710  83c008               add eax, 8
// 00657713  85c9                 test ecx, ecx
// 00657715  77ea                 ja 0x657701
// 00657717  5e                   pop esi
// 00657718  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
