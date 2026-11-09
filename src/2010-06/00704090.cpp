// from server: 100% by auto
// roc 2010-06 00704090  unit: RBX::Animator  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00704090
//
// 00704090  56                   push esi
// 00704091  33c0                 xor eax, eax
// 00704093  57                   push edi
// 00704094  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00704098  8bf1                 mov esi, ecx
// 0070409a  89460c               mov dword ptr [esi + 0xc], eax
// 0070409d  894610               mov dword ptr [esi + 0x10], eax
// 007040a0  894614               mov dword ptr [esi + 0x14], eax
// 007040a3  3bf8                 cmp edi, eax
// 007040a5  7507                 jne 0x7040ae
// 007040a7  5f                   pop edi
// 007040a8  32c0                 xor al, al
// 007040aa  5e                   pop esi
// 007040ab  c20400               ret 4
// 007040ae  81ffc7711c07         cmp edi, 0x71c71c7
// 007040b4  7605                 jbe 0x7040bb
// 007040b6  e835fdd1ff           call 0x423df0
// 007040bb  50                   push eax
// 007040bc  57                   push edi
// 007040bd  e89efaffff           call 0x703b60
// 007040c2  8d0cff               lea ecx, [edi + edi*8]
// 007040c5  83c408               add esp, 8
// 007040c8  8d1488               lea edx, [eax + ecx*4]
// 007040cb  89460c               mov dword ptr [esi + 0xc], eax
// 007040ce  894610               mov dword ptr [esi + 0x10], eax
// 007040d1  5f                   pop edi
// 007040d2  895614               mov dword ptr [esi + 0x14], edx
// 007040d5  b001                 mov al, 1
// 007040d7  5e                   pop esi
// 007040d8  c20400               ret 4
// standard library vector<pod36> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
