// from server: 100% by auto
// roc 2008-06 00683170  unit: Ogre::RbxSceneNode  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00683170
//
// 00683170  6aff                 push -1
// 00683172  68e8727d00           push 0x7d72e8
// 00683177  64a100000000         mov eax, dword ptr fs:[0]
// 0068317d  50                   push eax
// 0068317e  64892500000000       mov dword ptr fs:[0], esp
// 00683185  51                   push ecx
// 00683186  56                   push esi
// 00683187  8bf1                 mov esi, ecx
// 00683189  6a04                 push 4
// 0068318b  89742408             mov dword ptr [esp + 8], esi
// 0068318f  e88cd70100           call 0x6a0920
// 00683194  83c404               add esp, 4
// 00683197  85c0                 test eax, eax
// 00683199  7404                 je 0x68319f
// 0068319b  8930                 mov dword ptr [eax], esi
// 0068319d  eb02                 jmp 0x6831a1
// 0068319f  33c0                 xor eax, eax
// 006831a1  8906                 mov dword ptr [esi], eax
// 006831a3  8bce                 mov ecx, esi
// 006831a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006831ad  e86ef9ffff           call 0x682b20
// 006831b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006831b6  894614               mov dword ptr [esi + 0x14], eax
// 006831b9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006831c0  8bc6                 mov eax, esi
// 006831c2  5e                   pop esi
// 006831c3  64890d00000000       mov dword ptr fs:[0], ecx
// 006831ca  83c410               add esp, 0x10
// 006831cd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
