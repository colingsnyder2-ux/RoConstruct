// from server: 100% by auto
// roc 2007-08 004399a0  unit: RBX::VSoundId::?$XItem  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004399a0
//
// 004399a0  56                   push esi
// 004399a1  33c0                 xor eax, eax
// 004399a3  57                   push edi
// 004399a4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004399a8  3bf8                 cmp edi, eax
// 004399aa  8bf1                 mov esi, ecx
// 004399ac  894604               mov dword ptr [esi + 4], eax
// 004399af  894608               mov dword ptr [esi + 8], eax
// 004399b2  89460c               mov dword ptr [esi + 0xc], eax
// 004399b5  7507                 jne 0x4399be
// 004399b7  5f                   pop edi
// 004399b8  32c0                 xor al, al
// 004399ba  5e                   pop esi
// 004399bb  c20400               ret 4
// 004399be  81ffffffff3f         cmp edi, 0x3fffffff
// 004399c4  7605                 jbe 0x4399cb
// 004399c6  e835defdff           call 0x417800
// 004399cb  50                   push eax
// 004399cc  57                   push edi
// 004399cd  e88e631700           call 0x5afd60
// 004399d2  894604               mov dword ptr [esi + 4], eax
// 004399d5  894608               mov dword ptr [esi + 8], eax
// 004399d8  83c408               add esp, 8
// 004399db  8d04b8               lea eax, [eax + edi*4]
// 004399de  89460c               mov dword ptr [esi + 0xc], eax
// 004399e1  5f                   pop edi
// 004399e2  b001                 mov al, 1
// 004399e4  5e                   pop esi
// 004399e5  c20400               ret 4
// standard library vector<ptr> (function ?_Buy@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAE_NI@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
