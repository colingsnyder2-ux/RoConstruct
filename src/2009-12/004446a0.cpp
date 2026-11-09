// from server: 100% by auto
// roc 2009-12 004446a0  unit: VCRenderSettingsItem::?$FactoryProduct  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004446a0
//
// 004446a0  56                   push esi
// 004446a1  33c0                 xor eax, eax
// 004446a3  57                   push edi
// 004446a4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004446a8  8bf1                 mov esi, ecx
// 004446aa  89460c               mov dword ptr [esi + 0xc], eax
// 004446ad  894610               mov dword ptr [esi + 0x10], eax
// 004446b0  894614               mov dword ptr [esi + 0x14], eax
// 004446b3  3bf8                 cmp edi, eax
// 004446b5  7507                 jne 0x4446be
// 004446b7  5f                   pop edi
// 004446b8  32c0                 xor al, al
// 004446ba  5e                   pop esi
// 004446bb  c20400               ret 4
// 004446be  81ffffffff3f         cmp edi, 0x3fffffff
// 004446c4  7605                 jbe 0x4446cb
// 004446c6  e895daffff           call 0x442160
// 004446cb  50                   push eax
// 004446cc  57                   push edi
// 004446cd  e86ec2feff           call 0x430940
// 004446d2  89460c               mov dword ptr [esi + 0xc], eax
// 004446d5  894610               mov dword ptr [esi + 0x10], eax
// 004446d8  83c408               add esp, 8
// 004446db  8d04b8               lea eax, [eax + edi*4]
// 004446de  894614               mov dword ptr [esi + 0x14], eax
// 004446e1  5f                   pop edi
// 004446e2  b001                 mov al, 1
// 004446e4  5e                   pop esi
// 004446e5  c20400               ret 4
// standard library vector<ptr> (function ?_Buy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAE_NI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
