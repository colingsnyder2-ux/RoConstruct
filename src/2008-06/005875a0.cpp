// from server: 100% by auto
// roc 2008-06 005875a0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005875a0
//
// 005875a0  56                   push esi
// 005875a1  8bf1                 mov esi, ecx
// 005875a3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005875a6  8b01                 mov eax, dword ptr [ecx]
// 005875a8  8909                 mov dword ptr [ecx], ecx
// 005875aa  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 005875ad  894904               mov dword ptr [ecx + 4], ecx
// 005875b0  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005875b7  3b4614               cmp eax, dword ptr [esi + 0x14]
// 005875ba  7417                 je 0x5875d3
// 005875bc  57                   push edi
// 005875bd  8d4900               lea ecx, [ecx]
// 005875c0  8b38                 mov edi, dword ptr [eax]
// 005875c2  50                   push eax
// 005875c3  e8b2901100           call 0x6a067a
// 005875c8  83c404               add esp, 4
// 005875cb  8bc7                 mov eax, edi
// 005875cd  3b7e14               cmp edi, dword ptr [esi + 0x14]
// 005875d0  75ee                 jne 0x5875c0
// 005875d2  5f                   pop edi
// 005875d3  5e                   pop esi
// 005875d4  c3                   ret 
// standard library list<ptr> (function ?clear@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXXZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
