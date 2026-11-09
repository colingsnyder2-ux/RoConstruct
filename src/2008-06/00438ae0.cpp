// from server: 100% by auto
// roc 2008-06 00438ae0  unit: IIHAAH::?$CMap  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438ae0
//
// 00438ae0  56                   push esi
// 00438ae1  33c0                 xor eax, eax
// 00438ae3  57                   push edi
// 00438ae4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00438ae8  8bf1                 mov esi, ecx
// 00438aea  89460c               mov dword ptr [esi + 0xc], eax
// 00438aed  894610               mov dword ptr [esi + 0x10], eax
// 00438af0  894614               mov dword ptr [esi + 0x14], eax
// 00438af3  3bf8                 cmp edi, eax
// 00438af5  7507                 jne 0x438afe
// 00438af7  5f                   pop edi
// 00438af8  32c0                 xor al, al
// 00438afa  5e                   pop esi
// 00438afb  c20400               ret 4
// 00438afe  81ffffffff3f         cmp edi, 0x3fffffff
// 00438b04  7605                 jbe 0x438b0b
// 00438b06  e835e20800           call 0x4c6d40
// 00438b0b  50                   push eax
// 00438b0c  57                   push edi
// 00438b0d  e83e80feff           call 0x420b50
// 00438b12  89460c               mov dword ptr [esi + 0xc], eax
// 00438b15  894610               mov dword ptr [esi + 0x10], eax
// 00438b18  83c408               add esp, 8
// 00438b1b  8d04b8               lea eax, [eax + edi*4]
// 00438b1e  894614               mov dword ptr [esi + 0x14], eax
// 00438b21  5f                   pop edi
// 00438b22  b001                 mov al, 1
// 00438b24  5e                   pop esi
// 00438b25  c20400               ret 4
// standard library vector<ptr> (function ?_Buy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAE_NI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
