// from server: 100% by auto
// roc 2009-12 0068afb0  unit: TextXmlParser  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0068afb0
//
// 0068afb0  6aff                 push -1
// 0068afb2  68d8c59300           push 0x93c5d8
// 0068afb7  64a100000000         mov eax, dword ptr fs:[0]
// 0068afbd  50                   push eax
// 0068afbe  64892500000000       mov dword ptr fs:[0], esp
// 0068afc5  51                   push ecx
// 0068afc6  56                   push esi
// 0068afc7  8bf1                 mov esi, ecx
// 0068afc9  6a04                 push 4
// 0068afcb  89742408             mov dword ptr [esp + 8], esi
// 0068afcf  e88c881600           call 0x7f3860
// 0068afd4  83c404               add esp, 4
// 0068afd7  85c0                 test eax, eax
// 0068afd9  7404                 je 0x68afdf
// 0068afdb  8930                 mov dword ptr [eax], esi
// 0068afdd  eb02                 jmp 0x68afe1
// 0068afdf  33c0                 xor eax, eax
// 0068afe1  8906                 mov dword ptr [esi], eax
// 0068afe3  8bce                 mov ecx, esi
// 0068afe5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0068afed  e83efeffff           call 0x68ae30
// 0068aff2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068aff6  894614               mov dword ptr [esi + 0x14], eax
// 0068aff9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0068b000  8bc6                 mov eax, esi
// 0068b002  5e                   pop esi
// 0068b003  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b00a  83c410               add esp, 0x10
// 0068b00d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
