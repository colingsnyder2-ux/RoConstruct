// from server: 100% by auto
// roc 2012-06 007a7670  unit: RBX::KeyframeSequence  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a7670
//
// 007a7670  8b542408             mov edx, dword ptr [esp + 8]
// 007a7674  85d2                 test edx, edx
// 007a7676  7625                 jbe 0x7a769d
// 007a7678  8b442404             mov eax, dword ptr [esp + 4]
// 007a767c  53                   push ebx
// 007a767d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007a7681  56                   push esi
// 007a7682  57                   push edi
// 007a7683  85c0                 test eax, eax
// 007a7685  740b                 je 0x7a7692
// 007a7687  b908000000           mov ecx, 8
// 007a768c  8bf3                 mov esi, ebx
// 007a768e  8bf8                 mov edi, eax
// 007a7690  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007a7692  4a                   dec edx
// 007a7693  83c020               add eax, 0x20
// 007a7696  85d2                 test edx, edx
// 007a7698  77e9                 ja 0x7a7683
// 007a769a  5f                   pop edi
// 007a769b  5e                   pop esi
// 007a769c  5b                   pop ebx
// 007a769d  c3                   ret 
// standard library vector<pod32> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
