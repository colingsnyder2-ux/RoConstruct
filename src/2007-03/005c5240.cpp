// from server: 100% by auto
// roc 2007-03 005c5240  unit: seg_005c0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5240
//
// 005c5240  8b460c               mov eax, dword ptr [esi + 0xc]
// 005c5243  83e801               sub eax, 1
// 005c5246  57                   push edi
// 005c5247  7816                 js 0x5c525f
// 005c5249  8d4cc614             lea ecx, [esi + eax*8 + 0x14]
// 005c524d  8d4900               lea ecx, [ecx]
// 005c5250  8339ff               cmp dword ptr [ecx], -1
// 005c5253  741b                 je 0x5c5270
// 005c5255  83e801               sub eax, 1
// 005c5258  83e908               sub ecx, 8
// 005c525b  85c0                 test eax, eax
// 005c525d  7df1                 jge 0x5c5250
// 005c525f  8b4608               mov eax, dword ptr [esi + 8]
// 005c5262  68809f7b00           push 0x7b9f80
// 005c5267  50                   push eax
// 005c5268  e8e348ffff           call 0x5b9b50
// 005c526d  83c408               add esp, 8
// 005c5270  8b542408             mov edx, dword ptr [esp + 8]
// 005c5274  8bf8                 mov edi, eax
// 005c5276  52                   push edx
// 005c5277  8bcb                 mov ecx, ebx
// 005c5279  2b4cfe10             sub ecx, dword ptr [esi + edi*8 + 0x10]
// 005c527d  53                   push ebx
// 005c527e  56                   push esi
// 005c527f  894cfe14             mov dword ptr [esi + edi*8 + 0x14], ecx
// 005c5283  e8e8000000           call 0x5c5370
// 005c5288  83c40c               add esp, 0xc
// 005c528b  85c0                 test eax, eax
// 005c528d  7508                 jne 0x5c5297
// 005c528f  c744fe14ffffffff     mov dword ptr [esi + edi*8 + 0x14], 0xffffffff
// 005c5297  5f                   pop edi
// 005c5298  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _end_capture)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
