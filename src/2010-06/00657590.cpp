// from server: 100% by auto
// roc 2010-06 00657590  unit: RBX::Network::P8Player::?$GetSetImpl  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00657590
//
// 00657590  56                   push esi
// 00657591  33c0                 xor eax, eax
// 00657593  57                   push edi
// 00657594  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00657598  8bf1                 mov esi, ecx
// 0065759a  89460c               mov dword ptr [esi + 0xc], eax
// 0065759d  894610               mov dword ptr [esi + 0x10], eax
// 006575a0  894614               mov dword ptr [esi + 0x14], eax
// 006575a3  3bf8                 cmp edi, eax
// 006575a5  7507                 jne 0x6575ae
// 006575a7  5f                   pop edi
// 006575a8  32c0                 xor al, al
// 006575aa  5e                   pop esi
// 006575ab  c20400               ret 4
// 006575ae  81ffffffff3f         cmp edi, 0x3fffffff
// 006575b4  7605                 jbe 0x6575bb
// 006575b6  e835c8dcff           call 0x423df0
// 006575bb  50                   push eax
// 006575bc  57                   push edi
// 006575bd  e84edd2700           call 0x8d5310
// 006575c2  89460c               mov dword ptr [esi + 0xc], eax
// 006575c5  894610               mov dword ptr [esi + 0x10], eax
// 006575c8  83c408               add esp, 8
// 006575cb  8d04b8               lea eax, [eax + edi*4]
// 006575ce  894614               mov dword ptr [esi + 0x14], eax
// 006575d1  5f                   pop edi
// 006575d2  b001                 mov al, 1
// 006575d4  5e                   pop esi
// 006575d5  c20400               ret 4
// standard library vector<ptr> (function ?_Buy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAE_NI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
