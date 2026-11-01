// from server: 100% by auto
// roc 2009-12 00517200  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00517200
//
// 00517200  6aff                 push -1
// 00517202  68d8c59300           push 0x93c5d8
// 00517207  64a100000000         mov eax, dword ptr fs:[0]
// 0051720d  50                   push eax
// 0051720e  64892500000000       mov dword ptr fs:[0], esp
// 00517215  51                   push ecx
// 00517216  56                   push esi
// 00517217  8bf1                 mov esi, ecx
// 00517219  6a04                 push 4
// 0051721b  89742408             mov dword ptr [esp + 8], esi
// 0051721f  e83cc62d00           call 0x7f3860
// 00517224  83c404               add esp, 4
// 00517227  85c0                 test eax, eax
// 00517229  7404                 je 0x51722f
// 0051722b  8930                 mov dword ptr [eax], esi
// 0051722d  eb02                 jmp 0x517231
// 0051722f  33c0                 xor eax, eax
// 00517231  8906                 mov dword ptr [esi], eax
// 00517233  8bce                 mov ecx, esi
// 00517235  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0051723d  e8fecdffff           call 0x514040
// 00517242  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00517246  894614               mov dword ptr [esi + 0x14], eax
// 00517249  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00517250  8bc6                 mov eax, esi
// 00517252  5e                   pop esi
// 00517253  64890d00000000       mov dword ptr fs:[0], ecx
// 0051725a  83c410               add esp, 0x10
// 0051725d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
