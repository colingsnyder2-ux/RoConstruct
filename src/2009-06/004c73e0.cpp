// from server: 100% by auto
// roc 2009-06 004c73e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c73e0
//
// 004c73e0  6aff                 push -1
// 004c73e2  6878ef8600           push 0x86ef78
// 004c73e7  64a100000000         mov eax, dword ptr fs:[0]
// 004c73ed  50                   push eax
// 004c73ee  64892500000000       mov dword ptr fs:[0], esp
// 004c73f5  51                   push ecx
// 004c73f6  56                   push esi
// 004c73f7  8bf1                 mov esi, ecx
// 004c73f9  6a04                 push 4
// 004c73fb  89742408             mov dword ptr [esp + 8], esi
// 004c73ff  e834162500           call 0x718a38
// 004c7404  83c404               add esp, 4
// 004c7407  85c0                 test eax, eax
// 004c7409  7404                 je 0x4c740f
// 004c740b  8930                 mov dword ptr [eax], esi
// 004c740d  eb02                 jmp 0x4c7411
// 004c740f  33c0                 xor eax, eax
// 004c7411  8906                 mov dword ptr [esi], eax
// 004c7413  8bce                 mov ecx, esi
// 004c7415  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c741d  e8eed9ffff           call 0x4c4e10
// 004c7422  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c7426  894614               mov dword ptr [esi + 0x14], eax
// 004c7429  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c7430  8bc6                 mov eax, esi
// 004c7432  5e                   pop esi
// 004c7433  64890d00000000       mov dword ptr fs:[0], ecx
// 004c743a  83c410               add esp, 0x10
// 004c743d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
