// from server: 100% by auto
// roc 2011-06 0072a2f0  unit: RBX::HandlesBase  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0072a2f0
//
// 0072a2f0  8b442404             mov eax, dword ptr [esp + 4]
// 0072a2f4  8b542408             mov edx, dword ptr [esp + 8]
// 0072a2f8  3bc2                 cmp eax, edx
// 0072a2fa  741c                 je 0x72a318
// 0072a2fc  53                   push ebx
// 0072a2fd  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0072a301  56                   push esi
// 0072a302  57                   push edi
// 0072a303  8bf8                 mov edi, eax
// 0072a305  83c024               add eax, 0x24
// 0072a308  b909000000           mov ecx, 9
// 0072a30d  8bf3                 mov esi, ebx
// 0072a30f  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0072a311  3bc2                 cmp eax, edx
// 0072a313  75ee                 jne 0x72a303
// 0072a315  5f                   pop edi
// 0072a316  5e                   pop esi
// 0072a317  5b                   pop ebx
// 0072a318  c3                   ret 
// standard library vector<pod36> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
