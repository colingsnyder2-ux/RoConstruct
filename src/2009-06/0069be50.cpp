// from server: 100% by auto
// roc 2009-06 0069be50  unit: RBX::VFlagStandService::?$FactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0069be50
//
// 0069be50  6aff                 push -1
// 0069be52  6878ef8600           push 0x86ef78
// 0069be57  64a100000000         mov eax, dword ptr fs:[0]
// 0069be5d  50                   push eax
// 0069be5e  64892500000000       mov dword ptr fs:[0], esp
// 0069be65  51                   push ecx
// 0069be66  56                   push esi
// 0069be67  8bf1                 mov esi, ecx
// 0069be69  6a04                 push 4
// 0069be6b  89742408             mov dword ptr [esp + 8], esi
// 0069be6f  e8c4cb0700           call 0x718a38
// 0069be74  83c404               add esp, 4
// 0069be77  85c0                 test eax, eax
// 0069be79  7404                 je 0x69be7f
// 0069be7b  8930                 mov dword ptr [eax], esi
// 0069be7d  eb02                 jmp 0x69be81
// 0069be7f  33c0                 xor eax, eax
// 0069be81  8906                 mov dword ptr [esi], eax
// 0069be83  8bce                 mov ecx, esi
// 0069be85  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0069be8d  e88eaadfff           call 0x496920
// 0069be92  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0069be96  894614               mov dword ptr [esi + 0x14], eax
// 0069be99  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0069bea0  8bc6                 mov eax, esi
// 0069bea2  5e                   pop esi
// 0069bea3  64890d00000000       mov dword ptr fs:[0], ecx
// 0069beaa  83c410               add esp, 0x10
// 0069bead  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
