// from server: 100% by auto
// roc 2009-12 00862c80  unit: CXTPToolTipContext  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00862c80
//
// 00862c80  8b442404             mov eax, dword ptr [esp + 4]
// 00862c84  83ec24               sub esp, 0x24
// 00862c87  85c0                 test eax, eax
// 00862c89  757c                 jne 0x862d07
// 00862c8b  8b0d7cb6b900         mov ecx, dword ptr [0xb9b67c]
// 00862c91  85c9                 test ecx, ecx
// 00862c93  7472                 je 0x862d07
// 00862c95  398190000000         cmp dword ptr [ecx + 0x90], eax
// 00862c9b  746a                 je 0x862d07
// 00862c9d  56                   push esi
// 00862c9e  8b742434             mov esi, dword ptr [esp + 0x34]
// 00862ca2  8b06                 mov eax, dword ptr [esi]
// 00862ca4  8b5604               mov edx, dword ptr [esi + 4]
// 00862ca7  89442404             mov dword ptr [esp + 4], eax
// 00862cab  8d442404             lea eax, [esp + 4]
// 00862caf  50                   push eax
// 00862cb0  6a00                 push 0
// 00862cb2  89542410             mov dword ptr [esp + 0x10], edx
// 00862cb6  e805d0ffff           call 0x85fcc0
// 00862cbb  8b0d7cb6b900         mov ecx, dword ptr [0xb9b67c]
// 00862cc1  3b8190000000         cmp eax, dword ptr [ecx + 0x90]
// 00862cc7  7422                 je 0x862ceb
// 00862cc9  8b542404             mov edx, dword ptr [esp + 4]
// 00862ccd  8b442408             mov eax, dword ptr [esp + 8]
// 00862cd1  89542420             mov dword ptr [esp + 0x20], edx
// 00862cd5  8d54240c             lea edx, [esp + 0xc]
// 00862cd9  52                   push edx
// 00862cda  89442428             mov dword ptr [esp + 0x28], eax
// 00862cde  c744241400020000     mov dword ptr [esp + 0x14], 0x200
// 00862ce6  e825f6ffff           call 0x862310
// 00862ceb  8b442430             mov eax, dword ptr [esp + 0x30]
// 00862cef  8b0d78b6b900         mov ecx, dword ptr [0xb9b678]
// 00862cf5  56                   push esi
// 00862cf6  50                   push eax
// 00862cf7  6a00                 push 0
// 00862cf9  51                   push ecx
// 00862cfa  ff15c4ca9800         call dword ptr [0x98cac4]
// 00862d00  5e                   pop esi
// 00862d01  83c424               add esp, 0x24
// 00862d04  c20c00               ret 0xc
// 00862d07  8b542430             mov edx, dword ptr [esp + 0x30]
// 00862d0b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00862d0f  52                   push edx
// 00862d10  8b1578b6b900         mov edx, dword ptr [0xb9b678]
// 00862d16  51                   push ecx
// 00862d17  50                   push eax
// 00862d18  52                   push edx
// 00862d19  ff15c4ca9800         call dword ptr [0x98cac4]
// 00862d1f  83c424               add esp, 0x24
// 00862d22  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?MouseProc@CXTPToolTipContextToolTip@@KGJHIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
