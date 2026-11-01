// from server: 100% by auto
// roc 2007-03 00600440  unit: seg_00600000  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600440
//
// 00600440  56                   push esi
// 00600441  57                   push edi
// 00600442  8bf0                 mov esi, eax
// 00600444  e8d7feffff           call 0x600320
// 00600449  8bf8                 mov edi, eax
// 0060044b  8d4701               lea eax, [edi + 1]
// 0060044e  3dffffff3f           cmp eax, 0x3fffffff
// 00600453  7719                 ja 0x60046e
// 00600455  8b16                 mov edx, dword ptr [esi]
// 00600457  8d0cbd00000000       lea ecx, [edi*4]
// 0060045e  51                   push ecx
// 0060045f  6a00                 push 0
// 00600461  6a00                 push 0
// 00600463  52                   push edx
// 00600464  e837cfffff           call 0x5fd3a0
// 00600469  83c410               add esp, 0x10
// 0060046c  eb0b                 jmp 0x600479
// 0060046e  8b06                 mov eax, dword ptr [esi]
// 00600470  50                   push eax
// 00600471  e80acfffff           call 0x5fd380
// 00600476  83c404               add esp, 4
// 00600479  8d0cbd00000000       lea ecx, [edi*4]
// 00600480  51                   push ecx
// 00600481  89430c               mov dword ptr [ebx + 0xc], eax
// 00600484  897b2c               mov dword ptr [ebx + 0x2c], edi
// 00600487  8b5604               mov edx, dword ptr [esi + 4]
// 0060048a  50                   push eax
// 0060048b  52                   push edx
// 0060048c  e8dfc8ffff           call 0x5fcd70
// 00600491  83c40c               add esp, 0xc
// 00600494  85c0                 test eax, eax
// 00600496  7423                 je 0x6004bb
// 00600498  8b460c               mov eax, dword ptr [esi + 0xc]
// 0060049b  8b0e                 mov ecx, dword ptr [esi]
// 0060049d  6898067c00           push 0x7c0698
// 006004a2  50                   push eax
// 006004a3  687c067c00           push 0x7c067c
// 006004a8  51                   push ecx
// 006004a9  e89283ffff           call 0x5f8840
// 006004ae  8b16                 mov edx, dword ptr [esi]
// 006004b0  6a03                 push 3
// 006004b2  52                   push edx
// 006004b3  e848fdfbff           call 0x5c0200
// 006004b8  83c418               add esp, 0x18
// 006004bb  5f                   pop edi
// 006004bc  5e                   pop esi
// 006004bd  c3                   ret 
// library lua-5.1.1/lundump.c (function _LoadCode)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lundump.c
