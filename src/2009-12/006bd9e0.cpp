// from server: 100% by auto
// roc 2009-12 006bd9e0  unit: CPropGrid::UpdateItemsJob  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bd9e0
//
// 006bd9e0  56                   push esi
// 006bd9e1  8b742408             mov esi, dword ptr [esp + 8]
// 006bd9e5  33c0                 xor eax, eax
// 006bd9e7  57                   push edi
// 006bd9e8  8bf9                 mov edi, ecx
// 006bd9ea  89470c               mov dword ptr [edi + 0xc], eax
// 006bd9ed  894710               mov dword ptr [edi + 0x10], eax
// 006bd9f0  894714               mov dword ptr [edi + 0x14], eax
// 006bd9f3  3bf0                 cmp esi, eax
// 006bd9f5  7507                 jne 0x6bd9fe
// 006bd9f7  5f                   pop edi
// 006bd9f8  32c0                 xor al, al
// 006bd9fa  5e                   pop esi
// 006bd9fb  c20400               ret 4
// 006bd9fe  81feffffff07         cmp esi, 0x7ffffff
// 006bda04  7605                 jbe 0x6bda0b
// 006bda06  e85547d8ff           call 0x442160
// 006bda0b  50                   push eax
// 006bda0c  56                   push esi
// 006bda0d  e86e76dcff           call 0x485080
// 006bda12  c1e605               shl esi, 5
// 006bda15  03f0                 add esi, eax
// 006bda17  83c408               add esp, 8
// 006bda1a  89470c               mov dword ptr [edi + 0xc], eax
// 006bda1d  894710               mov dword ptr [edi + 0x10], eax
// 006bda20  897714               mov dword ptr [edi + 0x14], esi
// 006bda23  5f                   pop edi
// 006bda24  b001                 mov al, 1
// 006bda26  5e                   pop esi
// 006bda27  c20400               ret 4
// standard library vector<pod32> (function ?_Buy@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAE_NI@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
