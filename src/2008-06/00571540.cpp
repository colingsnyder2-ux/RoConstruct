// from server: 100% by auto
// roc 2008-06 00571540  unit: RBX::Reflection::ClassDescriptor  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00571540
//
// 00571540  6aff                 push -1
// 00571542  68e8727d00           push 0x7d72e8
// 00571547  64a100000000         mov eax, dword ptr fs:[0]
// 0057154d  50                   push eax
// 0057154e  64892500000000       mov dword ptr fs:[0], esp
// 00571555  51                   push ecx
// 00571556  56                   push esi
// 00571557  8bf1                 mov esi, ecx
// 00571559  6a04                 push 4
// 0057155b  89742408             mov dword ptr [esp + 8], esi
// 0057155f  e8bcf31200           call 0x6a0920
// 00571564  83c404               add esp, 4
// 00571567  85c0                 test eax, eax
// 00571569  7404                 je 0x57156f
// 0057156b  8930                 mov dword ptr [eax], esi
// 0057156d  eb02                 jmp 0x571571
// 0057156f  33c0                 xor eax, eax
// 00571571  8906                 mov dword ptr [esi], eax
// 00571573  8bce                 mov ecx, esi
// 00571575  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0057157d  e8bef7ffff           call 0x570d40
// 00571582  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00571586  894614               mov dword ptr [esi + 0x14], eax
// 00571589  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00571590  8bc6                 mov eax, esi
// 00571592  5e                   pop esi
// 00571593  64890d00000000       mov dword ptr fs:[0], ecx
// 0057159a  83c410               add esp, 0x10
// 0057159d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
