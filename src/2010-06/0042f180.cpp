// from server: 100% by auto
// roc 2010-06 0042f180  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042f180
//
// 0042f180  6aff                 push -1
// 0042f182  68da209800           push 0x9820da
// 0042f187  64a100000000         mov eax, dword ptr fs:[0]
// 0042f18d  50                   push eax
// 0042f18e  64892500000000       mov dword ptr fs:[0], esp
// 0042f195  51                   push ecx
// 0042f196  6814010000           push 0x114
// 0042f19b  e800883700           call 0x7a79a0
// 0042f1a0  83c404               add esp, 4
// 0042f1a3  890424               mov dword ptr [esp], eax
// 0042f1a6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042f1ae  85c0                 test eax, eax
// 0042f1b0  7416                 je 0x42f1c8
// 0042f1b2  8bc8                 mov ecx, eax
// 0042f1b4  e887feffff           call 0x42f040
// 0042f1b9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042f1bd  64890d00000000       mov dword ptr fs:[0], ecx
// 0042f1c4  83c410               add esp, 0x10
// 0042f1c7  c3                   ret 
// 0042f1c8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042f1cc  33c0                 xor eax, eax
// 0042f1ce  64890d00000000       mov dword ptr fs:[0], ecx
// 0042f1d5  83c410               add esp, 0x10
// 0042f1d8  c3                   ret 
// library raknet-4.081/FullyConnectedMesh2.cpp (function ??$OP_NEW@VBitStream@RakNet@@@RakNet@@YAPAVBitStream@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp
