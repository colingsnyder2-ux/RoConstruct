// from server: 100% by auto
// roc 2009-12 00425660  unit: MainLogManager  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425660
//
// 00425660  6aff                 push -1
// 00425662  68d8c59300           push 0x93c5d8
// 00425667  64a100000000         mov eax, dword ptr fs:[0]
// 0042566d  50                   push eax
// 0042566e  64892500000000       mov dword ptr fs:[0], esp
// 00425675  51                   push ecx
// 00425676  56                   push esi
// 00425677  8bf1                 mov esi, ecx
// 00425679  6a04                 push 4
// 0042567b  89742408             mov dword ptr [esp + 8], esi
// 0042567f  e8dce13c00           call 0x7f3860
// 00425684  83c404               add esp, 4
// 00425687  85c0                 test eax, eax
// 00425689  7404                 je 0x42568f
// 0042568b  8930                 mov dword ptr [eax], esi
// 0042568d  eb02                 jmp 0x425691
// 0042568f  33c0                 xor eax, eax
// 00425691  8906                 mov dword ptr [esi], eax
// 00425693  8bce                 mov ecx, esi
// 00425695  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042569d  e88ef5ffff           call 0x424c30
// 004256a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004256a6  894614               mov dword ptr [esi + 0x14], eax
// 004256a9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004256b0  8bc6                 mov eax, esi
// 004256b2  5e                   pop esi
// 004256b3  64890d00000000       mov dword ptr fs:[0], ecx
// 004256ba  83c410               add esp, 0x10
// 004256bd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
