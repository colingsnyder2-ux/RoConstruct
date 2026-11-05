// from server: 100% by auto
// roc 2011-06 0074cfa0  unit: RBX::BallBallContact  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0074cfa0
//
// 0074cfa0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0074cfa4  85c9                 test ecx, ecx
// 0074cfa6  7620                 jbe 0x74cfc8
// 0074cfa8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0074cfac  8b442404             mov eax, dword ptr [esp + 4]
// 0074cfb0  56                   push esi
// 0074cfb1  85c0                 test eax, eax
// 0074cfb3  740a                 je 0x74cfbf
// 0074cfb5  8b32                 mov esi, dword ptr [edx]
// 0074cfb7  8930                 mov dword ptr [eax], esi
// 0074cfb9  8b7204               mov esi, dword ptr [edx + 4]
// 0074cfbc  897004               mov dword ptr [eax + 4], esi
// 0074cfbf  49                   dec ecx
// 0074cfc0  83c008               add eax, 8
// 0074cfc3  85c9                 test ecx, ecx
// 0074cfc5  77ea                 ja 0x74cfb1
// 0074cfc7  5e                   pop esi
// 0074cfc8  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
