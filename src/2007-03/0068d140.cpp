// from server: 100% by auto
// roc 2007-03 0068d140  unit: seg_00680000  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068d140
//
// 0068d140  83ec18               sub esp, 0x18
// 0068d143  56                   push esi
// 0068d144  8b742420             mov esi, dword ptr [esp + 0x20]
// 0068d148  56                   push esi
// 0068d149  ff1574ed7700         call dword ptr [0x77ed74]
// 0068d14f  85c0                 test eax, eax
// 0068d151  7532                 jne 0x68d185
// 0068d153  8b442428             mov eax, dword ptr [esp + 0x28]
// 0068d157  50                   push eax
// 0068d158  56                   push esi
// 0068d159  ff155cee7700         call dword ptr [0x77ee5c]
// 0068d15f  68300c6200           push 0x620c30
// 0068d164  b910238c00           mov ecx, 0x8c2310
// 0068d169  e836d90a00           call 0x73aaa4
// 0068d16e  85c0                 test eax, eax
// 0068d170  7505                 jne 0x68d177
// 0068d172  e83712f9ff           call 0x61e3ae
// 0068d177  c7402400000000       mov dword ptr [eax + 0x24], 0
// 0068d17e  5e                   pop esi
// 0068d17f  83c418               add esp, 0x18
// 0068d182  c21000               ret 0x10
// 0068d185  57                   push edi
// 0068d186  8d4c2410             lea ecx, [esp + 0x10]
// 0068d18a  51                   push ecx
// 0068d18b  56                   push esi
// 0068d18c  ff155ced7700         call dword ptr [0x77ed5c]
// 0068d192  8d542408             lea edx, [esp + 8]
// 0068d196  52                   push edx
// 0068d197  ff1524ed7700         call dword ptr [0x77ed24]
// 0068d19d  56                   push esi
// 0068d19e  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0068d1a4  85c0                 test eax, eax
// 0068d1a6  741e                 je 0x68d1c6
// 0068d1a8  6af0                 push -0x10
// 0068d1aa  56                   push esi
// 0068d1ab  ff1504ed7700         call dword ptr [0x77ed04]
// 0068d1b1  85c0                 test eax, eax
// 0068d1b3  7811                 js 0x68d1c6
// 0068d1b5  56                   push esi
// 0068d1b6  e875ffffff           call 0x68d130
// 0068d1bb  83c404               add esp, 4
// 0068d1be  85c0                 test eax, eax
// 0068d1c0  7504                 jne 0x68d1c6
// 0068d1c2  33ff                 xor edi, edi
// 0068d1c4  eb05                 jmp 0x68d1cb
// 0068d1c6  bf01000000           mov edi, 1
// 0068d1cb  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068d1cf  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068d1d3  50                   push eax
// 0068d1d4  51                   push ecx
// 0068d1d5  8d542418             lea edx, [esp + 0x18]
// 0068d1d9  52                   push edx
// 0068d1da  ff1598ed7700         call dword ptr [0x77ed98]
// 0068d1e0  85c0                 test eax, eax
// 0068d1e2  7404                 je 0x68d1e8
// 0068d1e4  85ff                 test edi, edi
// 0068d1e6  753b                 jne 0x68d223
// 0068d1e8  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0068d1ec  50                   push eax
// 0068d1ed  56                   push esi
// 0068d1ee  ff155cee7700         call dword ptr [0x77ee5c]
// 0068d1f4  68300c6200           push 0x620c30
// 0068d1f9  b910238c00           mov ecx, 0x8c2310
// 0068d1fe  e8a1d80a00           call 0x73aaa4
// 0068d203  85c0                 test eax, eax
// 0068d205  7505                 jne 0x68d20c
// 0068d207  e8a211f9ff           call 0x61e3ae
// 0068d20c  6a00                 push 0
// 0068d20e  6a00                 push 0
// 0068d210  68a3020000           push 0x2a3
// 0068d215  56                   push esi
// 0068d216  c7402400000000       mov dword ptr [eax + 0x24], 0
// 0068d21d  ff1548ee7700         call dword ptr [0x77ee48]
// 0068d223  5f                   pop edi
// 0068d224  5e                   pop esi
// 0068d225  83c418               add esp, 0x18
// 0068d228  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?TrackMouseTimerProc@CXTPMouseManager@@CGXPAUHWND__@@IIK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
