// from server: 100% by auto
// roc 2010-06 00741390  unit: RBX::VHttp::?$sp_counted_impl_p  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00741390
//
// 00741390  6aff                 push -1
// 00741392  6858a29900           push 0x99a258
// 00741397  64a100000000         mov eax, dword ptr fs:[0]
// 0074139d  50                   push eax
// 0074139e  64892500000000       mov dword ptr fs:[0], esp
// 007413a5  51                   push ecx
// 007413a6  56                   push esi
// 007413a7  8bf1                 mov esi, ecx
// 007413a9  6a04                 push 4
// 007413ab  89742408             mov dword ptr [esp + 8], esi
// 007413af  e8ec650600           call 0x7a79a0
// 007413b4  83c404               add esp, 4
// 007413b7  85c0                 test eax, eax
// 007413b9  7404                 je 0x7413bf
// 007413bb  8930                 mov dword ptr [eax], esi
// 007413bd  eb02                 jmp 0x7413c1
// 007413bf  33c0                 xor eax, eax
// 007413c1  8906                 mov dword ptr [esi], eax
// 007413c3  8bce                 mov ecx, esi
// 007413c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007413cd  e8eef3ffff           call 0x7407c0
// 007413d2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007413d6  894614               mov dword ptr [esi + 0x14], eax
// 007413d9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007413e0  8bc6                 mov eax, esi
// 007413e2  5e                   pop esi
// 007413e3  64890d00000000       mov dword ptr fs:[0], ecx
// 007413ea  83c410               add esp, 0x10
// 007413ed  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
