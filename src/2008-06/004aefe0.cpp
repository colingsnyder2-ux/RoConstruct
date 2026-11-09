// from server: 100% by auto
// roc 2008-06 004aefe0  unit: RBX::Network::Replicator::MarkerItem  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004aefe0
//
// 004aefe0  6aff                 push -1
// 004aefe2  68e8727d00           push 0x7d72e8
// 004aefe7  64a100000000         mov eax, dword ptr fs:[0]
// 004aefed  50                   push eax
// 004aefee  64892500000000       mov dword ptr fs:[0], esp
// 004aeff5  51                   push ecx
// 004aeff6  56                   push esi
// 004aeff7  8bf1                 mov esi, ecx
// 004aeff9  6a04                 push 4
// 004aeffb  89742408             mov dword ptr [esp + 8], esi
// 004aefff  e81c191f00           call 0x6a0920
// 004af004  83c404               add esp, 4
// 004af007  85c0                 test eax, eax
// 004af009  7404                 je 0x4af00f
// 004af00b  8930                 mov dword ptr [eax], esi
// 004af00d  eb02                 jmp 0x4af011
// 004af00f  33c0                 xor eax, eax
// 004af011  8906                 mov dword ptr [esi], eax
// 004af013  8bce                 mov ecx, esi
// 004af015  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af01d  e8eedaffff           call 0x4acb10
// 004af022  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004af026  894614               mov dword ptr [esi + 0x14], eax
// 004af029  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004af030  8bc6                 mov eax, esi
// 004af032  5e                   pop esi
// 004af033  64890d00000000       mov dword ptr fs:[0], ecx
// 004af03a  83c410               add esp, 0x10
// 004af03d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
