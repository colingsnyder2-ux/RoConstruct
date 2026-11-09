// from server: 100% by auto
// roc 2010-06 004c4ad0  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c4ad0
//
// 004c4ad0  6aff                 push -1
// 004c4ad2  6858a29900           push 0x99a258
// 004c4ad7  64a100000000         mov eax, dword ptr fs:[0]
// 004c4add  50                   push eax
// 004c4ade  64892500000000       mov dword ptr fs:[0], esp
// 004c4ae5  51                   push ecx
// 004c4ae6  56                   push esi
// 004c4ae7  8bf1                 mov esi, ecx
// 004c4ae9  6a04                 push 4
// 004c4aeb  89742408             mov dword ptr [esp + 8], esi
// 004c4aef  e8ac2e2e00           call 0x7a79a0
// 004c4af4  83c404               add esp, 4
// 004c4af7  85c0                 test eax, eax
// 004c4af9  7404                 je 0x4c4aff
// 004c4afb  8930                 mov dword ptr [eax], esi
// 004c4afd  eb02                 jmp 0x4c4b01
// 004c4aff  33c0                 xor eax, eax
// 004c4b01  8906                 mov dword ptr [esi], eax
// 004c4b03  8bce                 mov ecx, esi
// 004c4b05  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c4b0d  e8aec9ffff           call 0x4c14c0
// 004c4b12  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c4b16  894614               mov dword ptr [esi + 0x14], eax
// 004c4b19  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c4b20  8bc6                 mov eax, esi
// 004c4b22  5e                   pop esi
// 004c4b23  64890d00000000       mov dword ptr fs:[0], ecx
// 004c4b2a  83c410               add esp, 0x10
// 004c4b2d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
