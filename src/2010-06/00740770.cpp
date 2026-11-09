// from server: 100% by auto
// roc 2010-06 00740770  unit: seg_00740000  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00740770
//
// 00740770  56                   push esi
// 00740771  33c0                 xor eax, eax
// 00740773  57                   push edi
// 00740774  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00740778  8bf1                 mov esi, ecx
// 0074077a  89460c               mov dword ptr [esi + 0xc], eax
// 0074077d  894610               mov dword ptr [esi + 0x10], eax
// 00740780  894614               mov dword ptr [esi + 0x14], eax
// 00740783  3bf8                 cmp edi, eax
// 00740785  7507                 jne 0x74078e
// 00740787  5f                   pop edi
// 00740788  32c0                 xor al, al
// 0074078a  5e                   pop esi
// 0074078b  c20400               ret 4
// 0074078e  81ff66666606         cmp edi, 0x6666666
// 00740794  7605                 jbe 0x74079b
// 00740796  e85536ceff           call 0x423df0
// 0074079b  50                   push eax
// 0074079c  57                   push edi
// 0074079d  e81e9bf6ff           call 0x6aa2c0
// 007407a2  8d0cbf               lea ecx, [edi + edi*4]
// 007407a5  83c408               add esp, 8
// 007407a8  8d14c8               lea edx, [eax + ecx*8]
// 007407ab  89460c               mov dword ptr [esi + 0xc], eax
// 007407ae  894610               mov dword ptr [esi + 0x10], eax
// 007407b1  5f                   pop edi
// 007407b2  895614               mov dword ptr [esi + 0x14], edx
// 007407b5  b001                 mov al, 1
// 007407b7  5e                   pop esi
// 007407b8  c20400               ret 4
// standard library vector<pod40> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod40>
struct E { int v[10]; };
#include <vector>
template class std::vector<E>;
