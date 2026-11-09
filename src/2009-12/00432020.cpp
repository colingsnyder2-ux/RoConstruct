// from server: 100% by auto
// roc 2009-12 00432020  unit: CStandardOutputView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00432020
//
// 00432020  6aff                 push -1
// 00432022  683a7c9200           push 0x927c3a
// 00432027  64a100000000         mov eax, dword ptr fs:[0]
// 0043202d  50                   push eax
// 0043202e  64892500000000       mov dword ptr fs:[0], esp
// 00432035  51                   push ecx
// 00432036  6850010000           push 0x150
// 0043203b  e820183c00           call 0x7f3860
// 00432040  83c404               add esp, 4
// 00432043  890424               mov dword ptr [esp], eax
// 00432046  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0043204e  85c0                 test eax, eax
// 00432050  7416                 je 0x432068
// 00432052  8bc8                 mov ecx, eax
// 00432054  e8e7fcffff           call 0x431d40
// 00432059  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043205d  64890d00000000       mov dword ptr fs:[0], ecx
// 00432064  83c410               add esp, 0x10
// 00432067  c3                   ret 
// 00432068  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043206c  33c0                 xor eax, eax
// 0043206e  64890d00000000       mov dword ptr fs:[0], ecx
// 00432075  83c410               add esp, 0x10
// 00432078  c3                   ret 
// library raknet-4.081/RPC4Plugin.cpp (function ??$OP_NEW@VRPC4@RakNet@@@RakNet@@YAPAVRPC4@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RPC4Plugin.cpp
