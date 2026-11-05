// from server: 100% by auto
// roc 2010-06 007414f0  unit: RBX::VHttp::?$sp_counted_impl_p  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007414f0
//
// 007414f0  6aff                 push -1
// 007414f2  6858a29900           push 0x99a258
// 007414f7  64a100000000         mov eax, dword ptr fs:[0]
// 007414fd  50                   push eax
// 007414fe  64892500000000       mov dword ptr fs:[0], esp
// 00741505  51                   push ecx
// 00741506  56                   push esi
// 00741507  8bf1                 mov esi, ecx
// 00741509  6a04                 push 4
// 0074150b  89742408             mov dword ptr [esp + 8], esi
// 0074150f  e88c640600           call 0x7a79a0
// 00741514  83c404               add esp, 4
// 00741517  85c0                 test eax, eax
// 00741519  7404                 je 0x74151f
// 0074151b  8930                 mov dword ptr [eax], esi
// 0074151d  eb02                 jmp 0x741521
// 0074151f  33c0                 xor eax, eax
// 00741521  8906                 mov dword ptr [esi], eax
// 00741523  8bce                 mov ecx, esi
// 00741525  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0074152d  e85e65faff           call 0x6e7a90
// 00741532  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00741536  894614               mov dword ptr [esi + 0x14], eax
// 00741539  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00741540  8bc6                 mov eax, esi
// 00741542  5e                   pop esi
// 00741543  64890d00000000       mov dword ptr fs:[0], ecx
// 0074154a  83c410               add esp, 0x10
// 0074154d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
