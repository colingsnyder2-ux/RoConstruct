// from server: 100% by auto
// roc 2007-03 0050f110  unit: seg_00500000  size: 437 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050f110
//
// 0050f110  55                   push ebp
// 0050f111  8b6c2408             mov ebp, dword ptr [esp + 8]
// 0050f115  8a4d09               mov cl, byte ptr [ebp + 9]
// 0050f118  80f908               cmp cl, 8
// 0050f11b  56                   push esi
// 0050f11c  8b7500               mov esi, dword ptr [ebp]
// 0050f11f  0f829d010000         jb 0x50f2c2
// 0050f125  8a4508               mov al, byte ptr [ebp + 8]
// 0050f128  b202                 mov dl, 2
// 0050f12a  84c2                 test dl, al
// 0050f12c  0f8590010000         jne 0x50f2c2
// 0050f132  84c0                 test al, al
// 0050f134  53                   push ebx
// 0050f135  57                   push edi
// 0050f136  0f8599000000         jne 0x50f1d5
// 0050f13c  80f908               cmp cl, 8
// 0050f13f  753a                 jne 0x50f17b
// 0050f141  85f6                 test esi, esi
// 0050f143  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050f147  8d4c06ff             lea ecx, [esi + eax - 1]
// 0050f14b  8d0471               lea eax, [ecx + esi*2]
// 0050f14e  0f863c010000         jbe 0x50f290
// 0050f154  8bfe                 mov edi, esi
// 0050f156  0fb619               movzx ebx, byte ptr [ecx]
// 0050f159  8818                 mov byte ptr [eax], bl
// 0050f15b  0fb619               movzx ebx, byte ptr [ecx]
// 0050f15e  83e801               sub eax, 1
// 0050f161  8818                 mov byte ptr [eax], bl
// 0050f163  0fb619               movzx ebx, byte ptr [ecx]
// 0050f166  83e801               sub eax, 1
// 0050f169  8818                 mov byte ptr [eax], bl
// 0050f16b  83e801               sub eax, 1
// 0050f16e  83e901               sub ecx, 1
// 0050f171  83ef01               sub edi, 1
// 0050f174  75e0                 jne 0x50f156
// 0050f176  e915010000           jmp 0x50f290
// 0050f17b  85f6                 test esi, esi
// 0050f17d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050f181  8d4c71ff             lea ecx, [ecx + esi*2 - 1]
// 0050f185  8d04b1               lea eax, [ecx + esi*4]
// 0050f188  0f8602010000         jbe 0x50f290
// 0050f18e  8bfe                 mov edi, esi
// 0050f190  0fb619               movzx ebx, byte ptr [ecx]
// 0050f193  8818                 mov byte ptr [eax], bl
// 0050f195  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f199  8858ff               mov byte ptr [eax - 1], bl
// 0050f19c  0fb619               movzx ebx, byte ptr [ecx]
// 0050f19f  83e801               sub eax, 1
// 0050f1a2  8858ff               mov byte ptr [eax - 1], bl
// 0050f1a5  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f1a9  83e801               sub eax, 1
// 0050f1ac  83e801               sub eax, 1
// 0050f1af  8818                 mov byte ptr [eax], bl
// 0050f1b1  0fb619               movzx ebx, byte ptr [ecx]
// 0050f1b4  83e801               sub eax, 1
// 0050f1b7  8818                 mov byte ptr [eax], bl
// 0050f1b9  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f1bd  83c1ff               add ecx, -1
// 0050f1c0  83e801               sub eax, 1
// 0050f1c3  8818                 mov byte ptr [eax], bl
// 0050f1c5  83e801               sub eax, 1
// 0050f1c8  83e901               sub ecx, 1
// 0050f1cb  83ef01               sub edi, 1
// 0050f1ce  75c0                 jne 0x50f190
// 0050f1d0  e9bb000000           jmp 0x50f290
// 0050f1d5  3c04                 cmp al, 4
// 0050f1d7  0f85b3000000         jne 0x50f290
// 0050f1dd  80f908               cmp cl, 8
// 0050f1e0  7543                 jne 0x50f225
// 0050f1e2  85f6                 test esi, esi
// 0050f1e4  8b442418             mov eax, dword ptr [esp + 0x18]
// 0050f1e8  8d4c70ff             lea ecx, [eax + esi*2 - 1]
// 0050f1ec  8d0471               lea eax, [ecx + esi*2]
// 0050f1ef  0f869b000000         jbe 0x50f290
// 0050f1f5  8bfe                 mov edi, esi
// 0050f1f7  0fb619               movzx ebx, byte ptr [ecx]
// 0050f1fa  8818                 mov byte ptr [eax], bl
// 0050f1fc  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f200  83e901               sub ecx, 1
// 0050f203  83e801               sub eax, 1
// 0050f206  8818                 mov byte ptr [eax], bl
// 0050f208  0fb619               movzx ebx, byte ptr [ecx]
// 0050f20b  83e801               sub eax, 1
// 0050f20e  8818                 mov byte ptr [eax], bl
// 0050f210  0fb619               movzx ebx, byte ptr [ecx]
// 0050f213  83e801               sub eax, 1
// 0050f216  8818                 mov byte ptr [eax], bl
// 0050f218  83e801               sub eax, 1
// 0050f21b  83e901               sub ecx, 1
// 0050f21e  83ef01               sub edi, 1
// 0050f221  75d4                 jne 0x50f1f7
// 0050f223  eb6b                 jmp 0x50f290
// 0050f225  85f6                 test esi, esi
// 0050f227  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050f22b  8d4cb1ff             lea ecx, [ecx + esi*4 - 1]
// 0050f22f  8d04b1               lea eax, [ecx + esi*4]
// 0050f232  765c                 jbe 0x50f290
// 0050f234  8bfe                 mov edi, esi
// 0050f236  0fb619               movzx ebx, byte ptr [ecx]
// 0050f239  8818                 mov byte ptr [eax], bl
// 0050f23b  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f23f  8858ff               mov byte ptr [eax - 1], bl
// 0050f242  83e801               sub eax, 1
// 0050f245  83e901               sub ecx, 1
// 0050f248  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f24c  8858ff               mov byte ptr [eax - 1], bl
// 0050f24f  0fb659fe             movzx ebx, byte ptr [ecx - 2]
// 0050f253  83e901               sub ecx, 1
// 0050f256  83e801               sub eax, 1
// 0050f259  8858ff               mov byte ptr [eax - 1], bl
// 0050f25c  0fb619               movzx ebx, byte ptr [ecx]
// 0050f25f  83e801               sub eax, 1
// 0050f262  8858ff               mov byte ptr [eax - 1], bl
// 0050f265  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f269  83e801               sub eax, 1
// 0050f26c  83e801               sub eax, 1
// 0050f26f  8818                 mov byte ptr [eax], bl
// 0050f271  0fb619               movzx ebx, byte ptr [ecx]
// 0050f274  83e801               sub eax, 1
// 0050f277  8818                 mov byte ptr [eax], bl
// 0050f279  0fb659ff             movzx ebx, byte ptr [ecx - 1]
// 0050f27d  83c1ff               add ecx, -1
// 0050f280  83e801               sub eax, 1
// 0050f283  8818                 mov byte ptr [eax], bl
// 0050f285  83e801               sub eax, 1
// 0050f288  83e901               sub ecx, 1
// 0050f28b  83ef01               sub edi, 1
// 0050f28e  75a6                 jne 0x50f236
// 0050f290  00550a               add byte ptr [ebp + 0xa], dl
// 0050f293  8a4509               mov al, byte ptr [ebp + 9]
// 0050f296  8a4d0a               mov cl, byte ptr [ebp + 0xa]
// 0050f299  085508               or byte ptr [ebp + 8], dl
// 0050f29c  f6e9                 imul cl
// 0050f29e  5f                   pop edi
// 0050f29f  88450b               mov byte ptr [ebp + 0xb], al
// 0050f2a2  3c08                 cmp al, 8
// 0050f2a4  5b                   pop ebx
// 0050f2a5  0fb6c0               movzx eax, al
// 0050f2a8  720c                 jb 0x50f2b6
// 0050f2aa  c1e803               shr eax, 3
// 0050f2ad  0fafc6               imul eax, esi
// 0050f2b0  5e                   pop esi
// 0050f2b1  894504               mov dword ptr [ebp + 4], eax
// 0050f2b4  5d                   pop ebp
// 0050f2b5  c3                   ret 
// 0050f2b6  0fafc6               imul eax, esi
// 0050f2b9  83c007               add eax, 7
// 0050f2bc  c1e803               shr eax, 3
// 0050f2bf  894504               mov dword ptr [ebp + 4], eax
// 0050f2c2  5e                   pop esi
// 0050f2c3  5d                   pop ebp
// 0050f2c4  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_gray_to_rgb)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
