// from server: 100% by auto
// roc 2009-12 0045a940  unit: CRobloxDoc  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0045a940
//
// 0045a940  6aff                 push -1
// 0045a942  683a7c9200           push 0x927c3a
// 0045a947  64a100000000         mov eax, dword ptr fs:[0]
// 0045a94d  50                   push eax
// 0045a94e  64892500000000       mov dword ptr fs:[0], esp
// 0045a955  51                   push ecx
// 0045a956  68a0000000           push 0xa0
// 0045a95b  e8008f3900           call 0x7f3860
// 0045a960  83c404               add esp, 4
// 0045a963  890424               mov dword ptr [esp], eax
// 0045a966  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0045a96e  85c0                 test eax, eax
// 0045a970  7416                 je 0x45a988
// 0045a972  8bc8                 mov ecx, eax
// 0045a974  e807e7ffff           call 0x459080
// 0045a979  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045a97d  64890d00000000       mov dword ptr fs:[0], ecx
// 0045a984  83c410               add esp, 0x10
// 0045a987  c3                   ret 
// 0045a988  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045a98c  33c0                 xor eax, eax
// 0045a98e  64890d00000000       mov dword ptr fs:[0], ecx
// 0045a995  83c410               add esp, 0x10
// 0045a998  c3                   ret 
// library raknet-4.081/LogCommandParser.cpp (function ??$OP_NEW@VLogCommandParser@RakNet@@@RakNet@@YAPAVLogCommandParser@0@PBDI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 LogCommandParser.cpp
