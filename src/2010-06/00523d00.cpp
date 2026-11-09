// from server: 100% by auto
// roc 2010-06 00523d00  unit: RBX::MeshGen  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00523d00
//
// 00523d00  56                   push esi
// 00523d01  33c0                 xor eax, eax
// 00523d03  57                   push edi
// 00523d04  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00523d08  8bf1                 mov esi, ecx
// 00523d0a  89460c               mov dword ptr [esi + 0xc], eax
// 00523d0d  894610               mov dword ptr [esi + 0x10], eax
// 00523d10  894614               mov dword ptr [esi + 0x14], eax
// 00523d13  3bf8                 cmp edi, eax
// 00523d15  7507                 jne 0x523d1e
// 00523d17  5f                   pop edi
// 00523d18  32c0                 xor al, al
// 00523d1a  5e                   pop esi
// 00523d1b  c20400               ret 4
// 00523d1e  81ff55555515         cmp edi, 0x15555555
// 00523d24  7605                 jbe 0x523d2b
// 00523d26  e8c500f0ff           call 0x423df0
// 00523d2b  50                   push eax
// 00523d2c  57                   push edi
// 00523d2d  e85ead3c00           call 0x8eea90
// 00523d32  8d0c7f               lea ecx, [edi + edi*2]
// 00523d35  83c408               add esp, 8
// 00523d38  8d1488               lea edx, [eax + ecx*4]
// 00523d3b  89460c               mov dword ptr [esi + 0xc], eax
// 00523d3e  894610               mov dword ptr [esi + 0x10], eax
// 00523d41  5f                   pop edi
// 00523d42  895614               mov dword ptr [esi + 0x14], edx
// 00523d45  b001                 mov al, 1
// 00523d47  5e                   pop esi
// 00523d48  c20400               ret 4
// standard library vector<pod12> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
