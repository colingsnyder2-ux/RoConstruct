// from server: 100% by auto
// roc 2010-06 0096f870  unit: seg_00960000  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f870
//
// 0096f870  6aff                 push -1
// 0096f872  6858a29900           push 0x99a258
// 0096f877  64a100000000         mov eax, dword ptr fs:[0]
// 0096f87d  50                   push eax
// 0096f87e  64892500000000       mov dword ptr fs:[0], esp
// 0096f885  51                   push ecx
// 0096f886  56                   push esi
// 0096f887  8bf1                 mov esi, ecx
// 0096f889  6a04                 push 4
// 0096f88b  89742408             mov dword ptr [esp + 8], esi
// 0096f88f  e80c81e3ff           call 0x7a79a0
// 0096f894  83c404               add esp, 4
// 0096f897  85c0                 test eax, eax
// 0096f899  7404                 je 0x96f89f
// 0096f89b  8930                 mov dword ptr [eax], esi
// 0096f89d  eb02                 jmp 0x96f8a1
// 0096f89f  33c0                 xor eax, eax
// 0096f8a1  8906                 mov dword ptr [esi], eax
// 0096f8a3  8bce                 mov ecx, esi
// 0096f8a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0096f8ad  e8cefcffff           call 0x96f580
// 0096f8b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0096f8b6  894614               mov dword ptr [esi + 0x14], eax
// 0096f8b9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0096f8c0  8bc6                 mov eax, esi
// 0096f8c2  5e                   pop esi
// 0096f8c3  64890d00000000       mov dword ptr fs:[0], ecx
// 0096f8ca  83c410               add esp, 0x10
// 0096f8cd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
