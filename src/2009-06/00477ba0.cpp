// from server: 100% by auto
// roc 2009-06 00477ba0  unit: Ogre::RbxMeshLoader  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00477ba0
//
// 00477ba0  6aff                 push -1
// 00477ba2  6878ef8600           push 0x86ef78
// 00477ba7  64a100000000         mov eax, dword ptr fs:[0]
// 00477bad  50                   push eax
// 00477bae  64892500000000       mov dword ptr fs:[0], esp
// 00477bb5  51                   push ecx
// 00477bb6  56                   push esi
// 00477bb7  8bf1                 mov esi, ecx
// 00477bb9  6a04                 push 4
// 00477bbb  89742408             mov dword ptr [esp + 8], esi
// 00477bbf  e8740e2a00           call 0x718a38
// 00477bc4  83c404               add esp, 4
// 00477bc7  85c0                 test eax, eax
// 00477bc9  7404                 je 0x477bcf
// 00477bcb  8930                 mov dword ptr [eax], esi
// 00477bcd  eb02                 jmp 0x477bd1
// 00477bcf  33c0                 xor eax, eax
// 00477bd1  8906                 mov dword ptr [esi], eax
// 00477bd3  8bce                 mov ecx, esi
// 00477bd5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00477bdd  e83eed0100           call 0x496920
// 00477be2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00477be6  894614               mov dword ptr [esi + 0x14], eax
// 00477be9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00477bf0  8bc6                 mov eax, esi
// 00477bf2  5e                   pop esi
// 00477bf3  64890d00000000       mov dword ptr fs:[0], ecx
// 00477bfa  83c410               add esp, 0x10
// 00477bfd  c20400               ret 4
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@ABV?$allocator@PAUT@@@1@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
