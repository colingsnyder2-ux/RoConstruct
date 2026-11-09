// from server: 100% by auto
// roc 2010-06 005f27b0  unit: TextXmlParser  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f27b0
//
// 005f27b0  6aff                 push -1
// 005f27b2  6858a29900           push 0x99a258
// 005f27b7  64a100000000         mov eax, dword ptr fs:[0]
// 005f27bd  50                   push eax
// 005f27be  64892500000000       mov dword ptr fs:[0], esp
// 005f27c5  51                   push ecx
// 005f27c6  56                   push esi
// 005f27c7  8bf1                 mov esi, ecx
// 005f27c9  6a04                 push 4
// 005f27cb  89742408             mov dword ptr [esp + 8], esi
// 005f27cf  e8cc511b00           call 0x7a79a0
// 005f27d4  83c404               add esp, 4
// 005f27d7  85c0                 test eax, eax
// 005f27d9  7404                 je 0x5f27df
// 005f27db  8930                 mov dword ptr [eax], esi
// 005f27dd  eb02                 jmp 0x5f27e1
// 005f27df  33c0                 xor eax, eax
// 005f27e1  8906                 mov dword ptr [esi], eax
// 005f27e3  8bce                 mov ecx, esi
// 005f27e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005f27ed  e83efeffff           call 0x5f2630
// 005f27f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005f27f6  894614               mov dword ptr [esi + 0x14], eax
// 005f27f9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 005f2800  8bc6                 mov eax, esi
// 005f2802  5e                   pop esi
// 005f2803  64890d00000000       mov dword ptr fs:[0], ecx
// 005f280a  83c410               add esp, 0x10
// 005f280d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
