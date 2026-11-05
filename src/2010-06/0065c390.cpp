// from server: 100% by auto
// roc 2010-06 0065c390  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065c390
//
// 0065c390  6aff                 push -1
// 0065c392  6858a29900           push 0x99a258
// 0065c397  64a100000000         mov eax, dword ptr fs:[0]
// 0065c39d  50                   push eax
// 0065c39e  64892500000000       mov dword ptr fs:[0], esp
// 0065c3a5  51                   push ecx
// 0065c3a6  56                   push esi
// 0065c3a7  8bf1                 mov esi, ecx
// 0065c3a9  6a04                 push 4
// 0065c3ab  89742408             mov dword ptr [esp + 8], esi
// 0065c3af  e8ecb51400           call 0x7a79a0
// 0065c3b4  83c404               add esp, 4
// 0065c3b7  85c0                 test eax, eax
// 0065c3b9  7404                 je 0x65c3bf
// 0065c3bb  8930                 mov dword ptr [eax], esi
// 0065c3bd  eb02                 jmp 0x65c3c1
// 0065c3bf  33c0                 xor eax, eax
// 0065c3c1  8906                 mov dword ptr [esi], eax
// 0065c3c3  8bce                 mov ecx, esi
// 0065c3c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0065c3cd  e8fef1ffff           call 0x65b5d0
// 0065c3d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0065c3d6  894614               mov dword ptr [esi + 0x14], eax
// 0065c3d9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0065c3e0  8bc6                 mov eax, esi
// 0065c3e2  5e                   pop esi
// 0065c3e3  64890d00000000       mov dword ptr fs:[0], ecx
// 0065c3ea  83c410               add esp, 0x10
// 0065c3ed  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
