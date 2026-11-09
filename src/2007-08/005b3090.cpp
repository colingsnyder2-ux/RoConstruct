// from server: 100% by auto
// roc 2007-08 005b3090  unit: RBX::Assembly  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005b3090
//
// 005b3090  8b5104               mov edx, dword ptr [ecx + 4]
// 005b3093  85d2                 test edx, edx
// 005b3095  750c                 jne 0x5b30a3
// 005b3097  33c0                 xor eax, eax
// 005b3099  33c9                 xor ecx, ecx
// 005b309b  85c0                 test eax, eax
// 005b309d  0f94c1               sete cl
// 005b30a0  8ac1                 mov al, cl
// 005b30a2  c3                   ret 
// 005b30a3  8b4108               mov eax, dword ptr [ecx + 8]
// 005b30a6  2bc2                 sub eax, edx
// 005b30a8  c1f802               sar eax, 2
// 005b30ab  33c9                 xor ecx, ecx
// 005b30ad  85c0                 test eax, eax
// 005b30af  0f94c1               sete cl
// 005b30b2  8ac1                 mov al, cl
// 005b30b4  c3                   ret 
// standard library vector<ptr> (function ?empty@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBE_NXZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
