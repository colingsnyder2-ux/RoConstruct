// from server: 100% by tester
// roc 2008-06 00434640  unit: CDeclarationView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00434640
//
// 00434640  6aff                 push -1
// 00434642  681afa7b00           push 0x7bfa1a
// 00434647  64a100000000         mov eax, dword ptr fs:[0]
// 0043464d  50                   push eax
// 0043464e  64892500000000       mov dword ptr fs:[0], esp
// 00434655  51                   push ecx
// 00434656  6814010000           push 0x114
// 0043465b  e8c0c22600           call 0x6a0920
// 00434660  83c404               add esp, 4
// 00434663  890424               mov dword ptr [esp], eax
// 00434666  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0043466e  85c0                 test eax, eax
// 00434670  7416                 je 0x434688
// 00434672  8bc8                 mov ecx, eax
// 00434674  e887feffff           call 0x434500
// 00434679  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043467d  64890d00000000       mov dword ptr fs:[0], ecx
// 00434684  83c410               add esp, 0x10
// 00434687  c3                   ret 
// 00434688  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043468c  33c0                 xor eax, eax
// 0043468e  64890d00000000       mov dword ptr fs:[0], ecx
// 00434695  83c410               add esp, 0x10
// 00434698  c3                   ret 
// library raknet-4.081/FullyConnectedMesh2.cpp (function ??$OP_NEW@VBitStream@RakNet@@@RakNet@@YAPAVBitStream@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp
