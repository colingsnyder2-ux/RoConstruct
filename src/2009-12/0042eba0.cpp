// from server: 100% by auto
// roc 2009-12 0042eba0  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042eba0
//
// 0042eba0  6aff                 push -1
// 0042eba2  683a7c9200           push 0x927c3a
// 0042eba7  64a100000000         mov eax, dword ptr fs:[0]
// 0042ebad  50                   push eax
// 0042ebae  64892500000000       mov dword ptr fs:[0], esp
// 0042ebb5  51                   push ecx
// 0042ebb6  6814010000           push 0x114
// 0042ebbb  e8a04c3c00           call 0x7f3860
// 0042ebc0  83c404               add esp, 4
// 0042ebc3  890424               mov dword ptr [esp], eax
// 0042ebc6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042ebce  85c0                 test eax, eax
// 0042ebd0  7416                 je 0x42ebe8
// 0042ebd2  8bc8                 mov ecx, eax
// 0042ebd4  e887feffff           call 0x42ea60
// 0042ebd9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ebdd  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ebe4  83c410               add esp, 0x10
// 0042ebe7  c3                   ret 
// 0042ebe8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042ebec  33c0                 xor eax, eax
// 0042ebee  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ebf5  83c410               add esp, 0x10
// 0042ebf8  c3                   ret 
// library raknet-4.081/FullyConnectedMesh2.cpp (function ??$OP_NEW@VBitStream@RakNet@@@RakNet@@YAPAVBitStream@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp
