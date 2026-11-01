// from server: 100% by auto
// roc 2009-12 006aa740  unit: RBX::ScriptContext  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006aa740
//
// 006aa740  6aff                 push -1
// 006aa742  68d8c59300           push 0x93c5d8
// 006aa747  64a100000000         mov eax, dword ptr fs:[0]
// 006aa74d  50                   push eax
// 006aa74e  64892500000000       mov dword ptr fs:[0], esp
// 006aa755  51                   push ecx
// 006aa756  56                   push esi
// 006aa757  8bf1                 mov esi, ecx
// 006aa759  6a04                 push 4
// 006aa75b  89742408             mov dword ptr [esp + 8], esi
// 006aa75f  e8fc901400           call 0x7f3860
// 006aa764  83c404               add esp, 4
// 006aa767  85c0                 test eax, eax
// 006aa769  7404                 je 0x6aa76f
// 006aa76b  8930                 mov dword ptr [eax], esi
// 006aa76d  eb02                 jmp 0x6aa771
// 006aa76f  33c0                 xor eax, eax
// 006aa771  8906                 mov dword ptr [esi], eax
// 006aa773  8bce                 mov ecx, esi
// 006aa775  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006aa77d  e87effffff           call 0x6aa700
// 006aa782  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006aa786  894614               mov dword ptr [esi + 0x14], eax
// 006aa789  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006aa790  8bc6                 mov eax, esi
// 006aa792  5e                   pop esi
// 006aa793  64890d00000000       mov dword ptr fs:[0], ecx
// 006aa79a  83c410               add esp, 0x10
// 006aa79d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
