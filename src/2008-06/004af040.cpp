// from server: 100% by auto
// roc 2008-06 004af040  unit: RBX::Network::Replicator::MarkerItem  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004af040
//
// 004af040  53                   push ebx
// 004af041  56                   push esi
// 004af042  8bf1                 mov esi, ecx
// 004af044  8b4614               mov eax, dword ptr [esi + 0x14]
// 004af047  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004af04b  57                   push edi
// 004af04c  8b38                 mov edi, dword ptr [eax]
// 004af04e  8b5704               mov edx, dword ptr [edi + 4]
// 004af051  51                   push ecx
// 004af052  52                   push edx
// 004af053  57                   push edi
// 004af054  8bce                 mov ecx, esi
// 004af056  e805e8ffff           call 0x4ad860
// 004af05b  6a01                 push 1
// 004af05d  8bce                 mov ecx, esi
// 004af05f  8bd8                 mov ebx, eax
// 004af061  e8eadaffff           call 0x4acb50
// 004af066  895f04               mov dword ptr [edi + 4], ebx
// 004af069  8b4304               mov eax, dword ptr [ebx + 4]
// 004af06c  5f                   pop edi
// 004af06d  5e                   pop esi
// 004af06e  8918                 mov dword ptr [eax], ebx
// 004af070  5b                   pop ebx
// 004af071  c20400               ret 4
// standard library list<ptr> (function ?push_front@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
