// from server: 100% by auto
// roc 2009-06 005db660  unit: RBX::VInstance::?$NonFactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005db660
//
// 005db660  53                   push ebx
// 005db661  56                   push esi
// 005db662  8bf1                 mov esi, ecx
// 005db664  8b4614               mov eax, dword ptr [esi + 0x14]
// 005db667  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005db66b  57                   push edi
// 005db66c  8b38                 mov edi, dword ptr [eax]
// 005db66e  8b5704               mov edx, dword ptr [edi + 4]
// 005db671  51                   push ecx
// 005db672  52                   push edx
// 005db673  57                   push edi
// 005db674  8bce                 mov ecx, esi
// 005db676  e885f2ffff           call 0x5da900
// 005db67b  6a01                 push 1
// 005db67d  8bce                 mov ecx, esi
// 005db67f  8bd8                 mov ebx, eax
// 005db681  e8eaebffff           call 0x5da270
// 005db686  895f04               mov dword ptr [edi + 4], ebx
// 005db689  8b4304               mov eax, dword ptr [ebx + 4]
// 005db68c  5f                   pop edi
// 005db68d  5e                   pop esi
// 005db68e  8918                 mov dword ptr [eax], ebx
// 005db690  5b                   pop ebx
// 005db691  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
