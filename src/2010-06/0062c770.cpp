// from server: 100% by auto
// roc 2010-06 0062c770  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0062c770
//
// 0062c770  6aff                 push -1
// 0062c772  6858a29900           push 0x99a258
// 0062c777  64a100000000         mov eax, dword ptr fs:[0]
// 0062c77d  50                   push eax
// 0062c77e  64892500000000       mov dword ptr fs:[0], esp
// 0062c785  51                   push ecx
// 0062c786  56                   push esi
// 0062c787  8bf1                 mov esi, ecx
// 0062c789  6a04                 push 4
// 0062c78b  89742408             mov dword ptr [esp + 8], esi
// 0062c78f  e80cb21700           call 0x7a79a0
// 0062c794  83c404               add esp, 4
// 0062c797  85c0                 test eax, eax
// 0062c799  7404                 je 0x62c79f
// 0062c79b  8930                 mov dword ptr [eax], esi
// 0062c79d  eb02                 jmp 0x62c7a1
// 0062c79f  33c0                 xor eax, eax
// 0062c7a1  8906                 mov dword ptr [esi], eax
// 0062c7a3  8bce                 mov ecx, esi
// 0062c7a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062c7ad  e83ef5ffff           call 0x62bcf0
// 0062c7b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0062c7b6  894614               mov dword ptr [esi + 0x14], eax
// 0062c7b9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0062c7c0  8bc6                 mov eax, esi
// 0062c7c2  5e                   pop esi
// 0062c7c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0062c7ca  83c410               add esp, 0x10
// 0062c7cd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
