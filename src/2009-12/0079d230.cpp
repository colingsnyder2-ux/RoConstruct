// from server: 100% by auto
// roc 2009-12 0079d230  unit: seg_00790000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d230
//
// 0079d230  56                   push esi
// 0079d231  8bf0                 mov esi, eax
// 0079d233  0fbe06               movsx eax, byte ptr [esi]
// 0079d236  46                   inc esi
// 0079d237  83f825               cmp eax, 0x25
// 0079d23a  7442                 je 0x79d27e
// 0079d23c  83f85b               cmp eax, 0x5b
// 0079d23f  7404                 je 0x79d245
// 0079d241  8bc6                 mov eax, esi
// 0079d243  5e                   pop esi
// 0079d244  c3                   ret 
// 0079d245  803e5e               cmp byte ptr [esi], 0x5e
// 0079d248  7506                 jne 0x79d250
// 0079d24a  46                   inc esi
// 0079d24b  eb03                 jmp 0x79d250
// 0079d24d  8d4900               lea ecx, [ecx]
// 0079d250  803e00               cmp byte ptr [esi], 0
// 0079d253  7511                 jne 0x79d266
// 0079d255  8b4708               mov eax, dword ptr [edi + 8]
// 0079d258  680cb19e00           push 0x9eb10c
// 0079d25d  50                   push eax
// 0079d25e  e88dcafeff           call 0x789cf0
// 0079d263  83c408               add esp, 8
// 0079d266  8a0e                 mov cl, byte ptr [esi]
// 0079d268  46                   inc esi
// 0079d269  80f925               cmp cl, 0x25
// 0079d26c  7506                 jne 0x79d274
// 0079d26e  803e00               cmp byte ptr [esi], 0
// 0079d271  7401                 je 0x79d274
// 0079d273  46                   inc esi
// 0079d274  803e5d               cmp byte ptr [esi], 0x5d
// 0079d277  75d7                 jne 0x79d250
// 0079d279  8d4601               lea eax, [esi + 1]
// 0079d27c  5e                   pop esi
// 0079d27d  c3                   ret 
// 0079d27e  803e00               cmp byte ptr [esi], 0
// 0079d281  7511                 jne 0x79d294
// 0079d283  8b5708               mov edx, dword ptr [edi + 8]
// 0079d286  68e8b09e00           push 0x9eb0e8
// 0079d28b  52                   push edx
// 0079d28c  e85fcafeff           call 0x789cf0
// 0079d291  83c408               add esp, 8
// 0079d294  8d4601               lea eax, [esi + 1]
// 0079d297  5e                   pop esi
// 0079d298  c3                   ret 
// library lua-5.1/lstrlib.c (function _classend)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
