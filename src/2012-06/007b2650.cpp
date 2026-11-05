// from server: 100% by auto
// roc 2012-06 007b2650  unit: RBX::VCacheableContentProvider::?$NonFactoryProduct  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b2650
//
// 007b2650  8b542408             mov edx, dword ptr [esp + 8]
// 007b2654  85d2                 test edx, edx
// 007b2656  7625                 jbe 0x7b267d
// 007b2658  8b442404             mov eax, dword ptr [esp + 4]
// 007b265c  53                   push ebx
// 007b265d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007b2661  56                   push esi
// 007b2662  57                   push edi
// 007b2663  85c0                 test eax, eax
// 007b2665  740b                 je 0x7b2672
// 007b2667  b909000000           mov ecx, 9
// 007b266c  8bf3                 mov esi, ebx
// 007b266e  8bf8                 mov edi, eax
// 007b2670  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b2672  4a                   dec edx
// 007b2673  83c024               add eax, 0x24
// 007b2676  85d2                 test edx, edx
// 007b2678  77e9                 ja 0x7b2663
// 007b267a  5f                   pop edi
// 007b267b  5e                   pop esi
// 007b267c  5b                   pop ebx
// 007b267d  c3                   ret 
// standard library vector<pod36> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
