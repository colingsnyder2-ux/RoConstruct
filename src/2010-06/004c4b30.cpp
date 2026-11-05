// from server: 100% by auto
// roc 2010-06 004c4b30  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c4b30
//
// 004c4b30  6aff                 push -1
// 004c4b32  6858a29900           push 0x99a258
// 004c4b37  64a100000000         mov eax, dword ptr fs:[0]
// 004c4b3d  50                   push eax
// 004c4b3e  64892500000000       mov dword ptr fs:[0], esp
// 004c4b45  51                   push ecx
// 004c4b46  56                   push esi
// 004c4b47  8bf1                 mov esi, ecx
// 004c4b49  6a04                 push 4
// 004c4b4b  89742408             mov dword ptr [esp + 8], esi
// 004c4b4f  e84c2e2e00           call 0x7a79a0
// 004c4b54  83c404               add esp, 4
// 004c4b57  85c0                 test eax, eax
// 004c4b59  7404                 je 0x4c4b5f
// 004c4b5b  8930                 mov dword ptr [eax], esi
// 004c4b5d  eb02                 jmp 0x4c4b61
// 004c4b5f  33c0                 xor eax, eax
// 004c4b61  8906                 mov dword ptr [esi], eax
// 004c4b63  8bce                 mov ecx, esi
// 004c4b65  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c4b6d  e86ec9ffff           call 0x4c14e0
// 004c4b72  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c4b76  894614               mov dword ptr [esi + 0x14], eax
// 004c4b79  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c4b80  8bc6                 mov eax, esi
// 004c4b82  5e                   pop esi
// 004c4b83  64890d00000000       mov dword ptr fs:[0], ecx
// 004c4b8a  83c410               add esp, 0x10
// 004c4b8d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
