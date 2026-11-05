// from server: 100% by auto
// roc 2009-06 004c7360  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c7360
//
// 004c7360  6aff                 push -1
// 004c7362  6878ef8600           push 0x86ef78
// 004c7367  64a100000000         mov eax, dword ptr fs:[0]
// 004c736d  50                   push eax
// 004c736e  64892500000000       mov dword ptr fs:[0], esp
// 004c7375  51                   push ecx
// 004c7376  56                   push esi
// 004c7377  8bf1                 mov esi, ecx
// 004c7379  6a04                 push 4
// 004c737b  89742408             mov dword ptr [esp + 8], esi
// 004c737f  e8b4162500           call 0x718a38
// 004c7384  83c404               add esp, 4
// 004c7387  85c0                 test eax, eax
// 004c7389  7404                 je 0x4c738f
// 004c738b  8930                 mov dword ptr [eax], esi
// 004c738d  eb02                 jmp 0x4c7391
// 004c738f  33c0                 xor eax, eax
// 004c7391  8906                 mov dword ptr [esi], eax
// 004c7393  8bce                 mov ecx, esi
// 004c7395  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004c739d  e84edaffff           call 0x4c4df0
// 004c73a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004c73a6  894614               mov dword ptr [esi + 0x14], eax
// 004c73a9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004c73b0  8bc6                 mov eax, esi
// 004c73b2  5e                   pop esi
// 004c73b3  64890d00000000       mov dword ptr fs:[0], ecx
// 004c73ba  83c410               add esp, 0x10
// 004c73bd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
