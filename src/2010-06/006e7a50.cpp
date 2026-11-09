// from server: 100% by auto
// roc 2010-06 006e7a50  unit: RBX::P8PVInstance::?$SetImpl  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e7a50
//
// 006e7a50  56                   push esi
// 006e7a51  8bf1                 mov esi, ecx
// 006e7a53  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006e7a56  8b01                 mov eax, dword ptr [ecx]
// 006e7a58  8909                 mov dword ptr [ecx], ecx
// 006e7a5a  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006e7a5d  894904               mov dword ptr [ecx + 4], ecx
// 006e7a60  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006e7a67  3b4614               cmp eax, dword ptr [esi + 0x14]
// 006e7a6a  7417                 je 0x6e7a83
// 006e7a6c  57                   push edi
// 006e7a6d  8d4900               lea ecx, [ecx]
// 006e7a70  8b38                 mov edi, dword ptr [eax]
// 006e7a72  50                   push eax
// 006e7a73  e822ff0b00           call 0x7a799a
// 006e7a78  83c404               add esp, 4
// 006e7a7b  8bc7                 mov eax, edi
// 006e7a7d  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 006e7a80  75ee                 jne 0x6e7a70
// 006e7a82  5f                   pop edi
// 006e7a83  5e                   pop esi
// 006e7a84  c3                   ret 
// standard library list<ptr> (function ?clear@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
