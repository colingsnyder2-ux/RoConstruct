// from server: 100% by auto
// roc 2007-03 005f9440  unit: seg_005f0000  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9440
//
// 005f9440  55                   push ebp
// 005f9441  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005f9445  56                   push esi
// 005f9446  57                   push edi
// 005f9447  8db598000000         lea esi, [ebp + 0x98]
// 005f944d  bf09000000           mov edi, 9
// 005f9452  8b06                 mov eax, dword ptr [esi]
// 005f9454  85c0                 test eax, eax
// 005f9456  7410                 je 0x5f9468
// 005f9458  f6400503             test byte ptr [eax + 5], 3
// 005f945c  740a                 je 0x5f9468
// 005f945e  50                   push eax
// 005f945f  55                   push ebp
// 005f9460  e85bf5ffff           call 0x5f89c0
// 005f9465  83c408               add esp, 8
// 005f9468  83c604               add esi, 4
// 005f946b  83ef01               sub edi, 1
// 005f946e  75e2                 jne 0x5f9452
// 005f9470  5f                   pop edi
// 005f9471  5e                   pop esi
// 005f9472  5d                   pop ebp
// 005f9473  c3                   ret 
// library lua-5.1.1/lgc.c (function _markmt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
