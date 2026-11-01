// from server: 100% by auto
// roc 2007-03 005fd9f0  unit: seg_005f0000  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd9f0
//
// 005fd9f0  57                   push edi
// 005fd9f1  8b7e14               mov edi, dword ptr [esi + 0x14]
// 005fd9f4  8b07                 mov eax, dword ptr [edi]
// 005fd9f6  894614               mov dword ptr [esi + 0x14], eax
// 005fd9f9  0fb65708             movzx edx, byte ptr [edi + 8]
// 005fd9fd  8b460c               mov eax, dword ptr [esi + 0xc]
// 005fda00  e8abfcffff           call 0x5fd6b0
// 005fda05  807f0900             cmp byte ptr [edi + 9], 0
// 005fda09  7414                 je 0x5fda1f
// 005fda0b  0fb64f08             movzx ecx, byte ptr [edi + 8]
// 005fda0f  6a00                 push 0
// 005fda11  6a00                 push 0
// 005fda13  51                   push ecx
// 005fda14  6a23                 push 0x23
// 005fda16  56                   push esi
// 005fda17  e894710100           call 0x614bb0
// 005fda1c  83c414               add esp, 0x14
// 005fda1f  0fb65632             movzx edx, byte ptr [esi + 0x32]
// 005fda23  895624               mov dword ptr [esi + 0x24], edx
// 005fda26  8b4704               mov eax, dword ptr [edi + 4]
// 005fda29  50                   push eax
// 005fda2a  56                   push esi
// 005fda2b  e8e0730100           call 0x614e10
// 005fda30  83c408               add esp, 8
// 005fda33  5f                   pop edi
// 005fda34  c3                   ret 
// library lua-5.1.1/lparser.c (function _leaveblock)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
