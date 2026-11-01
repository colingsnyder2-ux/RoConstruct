// from server: 100% by auto
// roc 2009-06 00793d00  unit: CXTPKeyboardManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793d00
//
// 00793d00  83ec18               sub esp, 0x18
// 00793d03  56                   push esi
// 00793d04  8b742420             mov esi, dword ptr [esp + 0x20]
// 00793d08  56                   push esi
// 00793d09  ff15e0ed8900         call dword ptr [0x89ede0]
// 00793d0f  85c0                 test eax, eax
// 00793d11  7532                 jne 0x793d45
// 00793d13  8b442428             mov eax, dword ptr [esp + 0x28]
// 00793d17  50                   push eax
// 00793d18  56                   push esi
// 00793d19  ff1584ee8900         call dword ptr [0x89ee84]
// 00793d1f  68f0b87100           push 0x71b8f0
// 00793d24  b99426a500           mov ecx, 0xa52694
// 00793d29  e8d2810b00           call 0x84bf00
// 00793d2e  85c0                 test eax, eax
// 00793d30  7505                 jne 0x793d37
// 00793d32  e8ad4ff8ff           call 0x718ce4
// 00793d37  c7402400000000       mov dword ptr [eax + 0x24], 0
// 00793d3e  5e                   pop esi
// 00793d3f  83c418               add esp, 0x18
// 00793d42  c21000               ret 0x10
// 00793d45  57                   push edi
// 00793d46  8d4c2410             lea ecx, [esp + 0x10]
// 00793d4a  51                   push ecx
// 00793d4b  56                   push esi
// 00793d4c  ff15f4ed8900         call dword ptr [0x89edf4]
// 00793d52  8d542408             lea edx, [esp + 8]
// 00793d56  52                   push edx
// 00793d57  ff152cee8900         call dword ptr [0x89ee2c]
// 00793d5d  56                   push esi
// 00793d5e  ff1598ee8900         call dword ptr [0x89ee98]
// 00793d64  85c0                 test eax, eax
// 00793d66  741e                 je 0x793d86
// 00793d68  6af0                 push -0x10
// 00793d6a  56                   push esi
// 00793d6b  ff1558ed8900         call dword ptr [0x89ed58]
// 00793d71  85c0                 test eax, eax
// 00793d73  7811                 js 0x793d86
// 00793d75  56                   push esi
// 00793d76  e845ffffff           call 0x793cc0
// 00793d7b  83c404               add esp, 4
// 00793d7e  85c0                 test eax, eax
// 00793d80  7504                 jne 0x793d86
// 00793d82  33ff                 xor edi, edi
// 00793d84  eb05                 jmp 0x793d8b
// 00793d86  bf01000000           mov edi, 1
// 00793d8b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00793d8f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00793d93  50                   push eax
// 00793d94  51                   push ecx
// 00793d95  8d542418             lea edx, [esp + 0x18]
// 00793d99  52                   push edx
// 00793d9a  ff15c0ed8900         call dword ptr [0x89edc0]
// 00793da0  85c0                 test eax, eax
// 00793da2  7404                 je 0x793da8
// 00793da4  85ff                 test edi, edi
// 00793da6  753b                 jne 0x793de3
// 00793da8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00793dac  50                   push eax
// 00793dad  56                   push esi
// 00793dae  ff1584ee8900         call dword ptr [0x89ee84]
// 00793db4  68f0b87100           push 0x71b8f0
// 00793db9  b99426a500           mov ecx, 0xa52694
// 00793dbe  e83d810b00           call 0x84bf00
// 00793dc3  85c0                 test eax, eax
// 00793dc5  7505                 jne 0x793dcc
// 00793dc7  e8184ff8ff           call 0x718ce4
// 00793dcc  6a00                 push 0
// 00793dce  6a00                 push 0
// 00793dd0  68a3020000           push 0x2a3
// 00793dd5  56                   push esi
// 00793dd6  c7402400000000       mov dword ptr [eax + 0x24], 0
// 00793ddd  ff159cee8900         call dword ptr [0x89ee9c]
// 00793de3  5f                   pop edi
// 00793de4  5e                   pop esi
// 00793de5  83c418               add esp, 0x18
// 00793de8  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseTimerProc@CXTPMouseManager@@CGXPAUHWND__@@IIK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
