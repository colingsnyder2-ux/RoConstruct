// from server: 100% by auto
// roc 2012-06 007b2500  unit: RBX::VCacheableContentProvider::?$NonFactoryProduct  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007b2500
//
// 007b2500  8b442404             mov eax, dword ptr [esp + 4]
// 007b2504  8b542408             mov edx, dword ptr [esp + 8]
// 007b2508  3bc2                 cmp eax, edx
// 007b250a  741c                 je 0x7b2528
// 007b250c  53                   push ebx
// 007b250d  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007b2511  56                   push esi
// 007b2512  57                   push edi
// 007b2513  8bf8                 mov edi, eax
// 007b2515  83c024               add eax, 0x24
// 007b2518  b909000000           mov ecx, 9
// 007b251d  8bf3                 mov esi, ebx
// 007b251f  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 007b2521  3bc2                 cmp eax, edx
// 007b2523  75ee                 jne 0x7b2513
// 007b2525  5f                   pop edi
// 007b2526  5e                   pop esi
// 007b2527  5b                   pop ebx
// 007b2528  c3                   ret 
// standard library vector<pod36> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
