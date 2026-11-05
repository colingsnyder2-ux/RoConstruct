// from server: 100% by auto
// roc 2009-06 005df350  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005df350
//
// 005df350  8b442404             mov eax, dword ptr [esp + 4]
// 005df354  53                   push ebx
// 005df355  56                   push esi
// 005df356  57                   push edi
// 005df357  8bf1                 mov esi, ecx
// 005df359  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005df35c  8b4f04               mov ecx, dword ptr [edi + 4]
// 005df35f  50                   push eax
// 005df360  51                   push ecx
// 005df361  57                   push edi
// 005df362  8bce                 mov ecx, esi
// 005df364  e8b7fcffff           call 0x5df020
// 005df369  6a01                 push 1
// 005df36b  8bce                 mov ecx, esi
// 005df36d  8bd8                 mov ebx, eax
// 005df36f  e85caeffff           call 0x5da1d0
// 005df374  895f04               mov dword ptr [edi + 4], ebx
// 005df377  8b5304               mov edx, dword ptr [ebx + 4]
// 005df37a  5f                   pop edi
// 005df37b  5e                   pop esi
// 005df37c  891a                 mov dword ptr [edx], ebx
// 005df37e  5b                   pop ebx
// 005df37f  c20400               ret 4
// standard library list<ptr> (function ?push_back@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
