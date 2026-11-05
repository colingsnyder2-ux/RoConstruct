// from server: 100% by auto
// roc 2010-06 008d3170  unit: Ogre::VisualEngine  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3170
//
// 008d3170  6aff                 push -1
// 008d3172  6858a29900           push 0x99a258
// 008d3177  64a100000000         mov eax, dword ptr fs:[0]
// 008d317d  50                   push eax
// 008d317e  64892500000000       mov dword ptr fs:[0], esp
// 008d3185  51                   push ecx
// 008d3186  56                   push esi
// 008d3187  8bf1                 mov esi, ecx
// 008d3189  6a04                 push 4
// 008d318b  89742408             mov dword ptr [esp + 8], esi
// 008d318f  e80c48edff           call 0x7a79a0
// 008d3194  83c404               add esp, 4
// 008d3197  85c0                 test eax, eax
// 008d3199  7404                 je 0x8d319f
// 008d319b  8930                 mov dword ptr [eax], esi
// 008d319d  eb02                 jmp 0x8d31a1
// 008d319f  33c0                 xor eax, eax
// 008d31a1  8906                 mov dword ptr [esi], eax
// 008d31a3  8bce                 mov ecx, esi
// 008d31a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d31ad  e80ef9ffff           call 0x8d2ac0
// 008d31b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008d31b6  894614               mov dword ptr [esi + 0x14], eax
// 008d31b9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008d31c0  8bc6                 mov eax, esi
// 008d31c2  5e                   pop esi
// 008d31c3  64890d00000000       mov dword ptr fs:[0], ecx
// 008d31ca  83c410               add esp, 0x10
// 008d31cd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
