// from server: 100% by auto
// roc 2008-06 0055e530  unit: RBX::MD5HasherImpl  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e530
//
// 0055e530  6aff                 push -1
// 0055e532  68e8727d00           push 0x7d72e8
// 0055e537  64a100000000         mov eax, dword ptr fs:[0]
// 0055e53d  50                   push eax
// 0055e53e  64892500000000       mov dword ptr fs:[0], esp
// 0055e545  51                   push ecx
// 0055e546  56                   push esi
// 0055e547  8bf1                 mov esi, ecx
// 0055e549  6a04                 push 4
// 0055e54b  89742408             mov dword ptr [esp + 8], esi
// 0055e54f  e8cc231400           call 0x6a0920
// 0055e554  83c404               add esp, 4
// 0055e557  85c0                 test eax, eax
// 0055e559  7404                 je 0x55e55f
// 0055e55b  8930                 mov dword ptr [eax], esi
// 0055e55d  eb02                 jmp 0x55e561
// 0055e55f  33c0                 xor eax, eax
// 0055e561  8906                 mov dword ptr [esi], eax
// 0055e563  8bce                 mov ecx, esi
// 0055e565  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055e56d  e87eecffff           call 0x55d1f0
// 0055e572  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055e576  894614               mov dword ptr [esi + 0x14], eax
// 0055e579  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0055e580  8bc6                 mov eax, esi
// 0055e582  5e                   pop esi
// 0055e583  64890d00000000       mov dword ptr fs:[0], ecx
// 0055e58a  83c410               add esp, 0x10
// 0055e58d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
