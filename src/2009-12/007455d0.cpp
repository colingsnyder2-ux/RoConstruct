// from server: 100% by auto
// roc 2009-12 007455d0  unit: RBX::VFlagStandService::?$FactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007455d0
//
// 007455d0  6aff                 push -1
// 007455d2  68d8c59300           push 0x93c5d8
// 007455d7  64a100000000         mov eax, dword ptr fs:[0]
// 007455dd  50                   push eax
// 007455de  64892500000000       mov dword ptr fs:[0], esp
// 007455e5  51                   push ecx
// 007455e6  56                   push esi
// 007455e7  8bf1                 mov esi, ecx
// 007455e9  6a04                 push 4
// 007455eb  89742408             mov dword ptr [esp + 8], esi
// 007455ef  e86ce20a00           call 0x7f3860
// 007455f4  83c404               add esp, 4
// 007455f7  85c0                 test eax, eax
// 007455f9  7404                 je 0x7455ff
// 007455fb  8930                 mov dword ptr [eax], esi
// 007455fd  eb02                 jmp 0x745601
// 007455ff  33c0                 xor eax, eax
// 00745601  8906                 mov dword ptr [esi], eax
// 00745603  8bce                 mov ecx, esi
// 00745605  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0074560d  e8fecbfdff           call 0x722210
// 00745612  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00745616  894614               mov dword ptr [esi + 0x14], eax
// 00745619  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00745620  8bc6                 mov eax, esi
// 00745622  5e                   pop esi
// 00745623  64890d00000000       mov dword ptr fs:[0], ecx
// 0074562a  83c410               add esp, 0x10
// 0074562d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
