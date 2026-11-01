// from server: 100% by auto
// roc 2009-06 0042db60  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042db60
//
// 0042db60  6aff                 push -1
// 0042db62  687aef8400           push 0x84ef7a
// 0042db67  64a100000000         mov eax, dword ptr fs:[0]
// 0042db6d  50                   push eax
// 0042db6e  64892500000000       mov dword ptr fs:[0], esp
// 0042db75  51                   push ecx
// 0042db76  6814010000           push 0x114
// 0042db7b  e8b8ae2e00           call 0x718a38
// 0042db80  83c404               add esp, 4
// 0042db83  890424               mov dword ptr [esp], eax
// 0042db86  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042db8e  85c0                 test eax, eax
// 0042db90  7416                 je 0x42dba8
// 0042db92  8bc8                 mov ecx, eax
// 0042db94  e887feffff           call 0x42da20
// 0042db99  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042db9d  64890d00000000       mov dword ptr fs:[0], ecx
// 0042dba4  83c410               add esp, 0x10
// 0042dba7  c3                   ret 
// 0042dba8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042dbac  33c0                 xor eax, eax
// 0042dbae  64890d00000000       mov dword ptr fs:[0], ecx
// 0042dbb5  83c410               add esp, 0x10
// 0042dbb8  c3                   ret 
// library raknet-4.081/FullyConnectedMesh2.cpp (function ??$OP_NEW@VBitStream@RakNet@@@RakNet@@YAPAVBitStream@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp
