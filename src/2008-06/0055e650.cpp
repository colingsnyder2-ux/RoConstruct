// from server: 100% by auto
// roc 2008-06 0055e650  unit: RBX::MD5HasherImpl  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e650
//
// 0055e650  53                   push ebx
// 0055e651  56                   push esi
// 0055e652  8bf1                 mov esi, ecx
// 0055e654  8b4614               mov eax, dword ptr [esi + 0x14]
// 0055e657  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055e65b  57                   push edi
// 0055e65c  8b38                 mov edi, dword ptr [eax]
// 0055e65e  8b5704               mov edx, dword ptr [edi + 4]
// 0055e661  51                   push ecx
// 0055e662  52                   push edx
// 0055e663  57                   push edi
// 0055e664  8bce                 mov ecx, esi
// 0055e666  e855f2ffff           call 0x55d8c0
// 0055e66b  6a01                 push 1
// 0055e66d  8bce                 mov ecx, esi
// 0055e66f  8bd8                 mov ebx, eax
// 0055e671  e84a840700           call 0x5d6ac0
// 0055e676  895f04               mov dword ptr [edi + 4], ebx
// 0055e679  8b4304               mov eax, dword ptr [ebx + 4]
// 0055e67c  5f                   pop edi
// 0055e67d  5e                   pop esi
// 0055e67e  8918                 mov dword ptr [eax], ebx
// 0055e680  5b                   pop ebx
// 0055e681  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
