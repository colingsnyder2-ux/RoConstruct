// from server: 100% by auto
// roc 2007-08 004aa9d0  unit: RBX::Network::Peer  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aa9d0
//
// 004aa9d0  53                   push ebx
// 004aa9d1  56                   push esi
// 004aa9d2  8bf1                 mov esi, ecx
// 004aa9d4  8b4604               mov eax, dword ptr [esi + 4]
// 004aa9d7  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004aa9db  57                   push edi
// 004aa9dc  8b38                 mov edi, dword ptr [eax]
// 004aa9de  8b5704               mov edx, dword ptr [edi + 4]
// 004aa9e1  51                   push ecx
// 004aa9e2  52                   push edx
// 004aa9e3  57                   push edi
// 004aa9e4  8bce                 mov ecx, esi
// 004aa9e6  e8b506f8ff           call 0x42b0a0
// 004aa9eb  6a01                 push 1
// 004aa9ed  8bce                 mov ecx, esi
// 004aa9ef  8bd8                 mov ebx, eax
// 004aa9f1  e82a01f8ff           call 0x42ab20
// 004aa9f6  895f04               mov dword ptr [edi + 4], ebx
// 004aa9f9  8b4304               mov eax, dword ptr [ebx + 4]
// 004aa9fc  5f                   pop edi
// 004aa9fd  5e                   pop esi
// 004aa9fe  8918                 mov dword ptr [eax], ebx
// 004aaa00  5b                   pop ebx
// 004aaa01  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
