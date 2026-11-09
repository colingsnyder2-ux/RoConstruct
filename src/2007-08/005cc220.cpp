// from server: 100% by auto
// roc 2007-08 005cc220  unit: seg_005c0000  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005cc220
//
// 005cc220  56                   push esi
// 005cc221  8b742408             mov esi, dword ptr [esp + 8]
// 005cc225  6a01                 push 1
// 005cc227  56                   push esi
// 005cc228  e8f330ffff           call 0x5bf320
// 005cc22d  6828587a00           push 0x7a5828
// 005cc232  6a01                 push 1
// 005cc234  56                   push esi
// 005cc235  e8c627ffff           call 0x5bea00
// 005cc23a  83c414               add esp, 0x14
// 005cc23d  85c0                 test eax, eax
// 005cc23f  0f85b2000000         jne 0x5cc2f7
// 005cc245  6a01                 push 1
// 005cc247  56                   push esi
// 005cc248  e82315ffff           call 0x5bd770
// 005cc24d  83c408               add esp, 8
// 005cc250  83f804               cmp eax, 4
// 005cc253  7775                 ja 0x5cc2ca
// 005cc255  ff248500c35c00       jmp dword ptr [eax*4 + 0x5cc300]
// 005cc25c  6a00                 push 0
// 005cc25e  6a01                 push 1
// 005cc260  56                   push esi
// 005cc261  e81a17ffff           call 0x5bd980
// 005cc266  50                   push eax
// 005cc267  56                   push esi
// 005cc268  e88319ffff           call 0x5bdbf0
// 005cc26d  83c414               add esp, 0x14
// 005cc270  b801000000           mov eax, 1
// 005cc275  5e                   pop esi
// 005cc276  c3                   ret 
// 005cc277  6a01                 push 1
// 005cc279  56                   push esi
// 005cc27a  e8c114ffff           call 0x5bd740
// 005cc27f  83c408               add esp, 8
// 005cc282  b801000000           mov eax, 1
// 005cc287  5e                   pop esi
// 005cc288  c3                   ret 
// 005cc289  6a01                 push 1
// 005cc28b  56                   push esi
// 005cc28c  e8bf16ffff           call 0x5bd950
// 005cc291  83c408               add esp, 8
// 005cc294  85c0                 test eax, eax
// 005cc296  b8440b7a00           mov eax, 0x7a0b44
// 005cc29b  7505                 jne 0x5cc2a2
// 005cc29d  b8d0797900           mov eax, 0x7979d0
// 005cc2a2  50                   push eax
// 005cc2a3  56                   push esi
// 005cc2a4  e84719ffff           call 0x5bdbf0
// 005cc2a9  83c408               add esp, 8
// 005cc2ac  b801000000           mov eax, 1
// 005cc2b1  5e                   pop esi
// 005cc2b2  c3                   ret 
// 005cc2b3  6a03                 push 3
// 005cc2b5  68888f7a00           push 0x7a8f88
// 005cc2ba  56                   push esi
// 005cc2bb  e8f018ffff           call 0x5bdbb0
// 005cc2c0  83c40c               add esp, 0xc
// 005cc2c3  b801000000           mov eax, 1
// 005cc2c8  5e                   pop esi
// 005cc2c9  c3                   ret 
// 005cc2ca  6a01                 push 1
// 005cc2cc  56                   push esi
// 005cc2cd  e80e18ffff           call 0x5bdae0
// 005cc2d2  83c408               add esp, 8
// 005cc2d5  50                   push eax
// 005cc2d6  6a01                 push 1
// 005cc2d8  56                   push esi
// 005cc2d9  e89214ffff           call 0x5bd770
// 005cc2de  50                   push eax
// 005cc2df  56                   push esi
// 005cc2e0  e8ab14ffff           call 0x5bd790
// 005cc2e5  83c410               add esp, 0x10
// 005cc2e8  50                   push eax
// 005cc2e9  6874a47b00           push 0x7ba474
// 005cc2ee  56                   push esi
// 005cc2ef  e89c19ffff           call 0x5bdc90
// 005cc2f4  83c410               add esp, 0x10
// 005cc2f7  b801000000           mov eax, 1
// 005cc2fc  5e                   pop esi
// 005cc2fd  c3                   ret 
// 005cc2fe  8bff                 mov edi, edi
// 005cc300  b3c2                 mov bl, 0xc2
// 005cc302  5c                   pop esp
// 005cc303  0089c25c00ca         add byte ptr [ecx - 0x35ffa33e], cl
// 005cc309  c25c00               ret 0x5c
// 005cc30c  5c                   pop esp
// 005cc30d  c25c00               ret 0x5c
// 005cc310  77c2                 ja 0x5cc2d4
// 005cc312  5c                   pop esp
// library lua-5.1/lbaselib.c (function _luaB_tostring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lbaselib.c
