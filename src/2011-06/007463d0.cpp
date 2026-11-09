// from server: 100% by auto
// roc 2011-06 007463d0  unit: RBX::Animator  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007463d0
//
// 007463d0  8b542408             mov edx, dword ptr [esp + 8]
// 007463d4  85d2                 test edx, edx
// 007463d6  7625                 jbe 0x7463fd
// 007463d8  8b442404             mov eax, dword ptr [esp + 4]
// 007463dc  53                   push ebx
// 007463dd  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007463e1  56                   push esi
// 007463e2  57                   push edi
// 007463e3  85c0                 test eax, eax
// 007463e5  740b                 je 0x7463f2
// 007463e7  b909000000           mov ecx, 9
// 007463ec  8bf3                 mov esi, ebx
// 007463ee  8bf8                 mov edi, eax
// 007463f0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007463f2  4a                   dec edx
// 007463f3  83c024               add eax, 0x24
// 007463f6  85d2                 test edx, edx
// 007463f8  77e9                 ja 0x7463e3
// 007463fa  5f                   pop edi
// 007463fb  5e                   pop esi
// 007463fc  5b                   pop ebx
// 007463fd  c3                   ret 
// standard library vector<pod36> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
