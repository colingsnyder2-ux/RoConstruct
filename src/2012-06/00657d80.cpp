// from server: 100% by auto
// roc 2012-06 00657d80  unit: seg_00650000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657d80
//
// 00657d80  83ec0c               sub esp, 0xc
// 00657d83  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00657d87  53                   push ebx
// 00657d88  56                   push esi
// 00657d89  57                   push edi
// 00657d8a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00657d8e  c644241073           mov byte ptr [esp + 0x10], 0x73
// 00657d93  c644241142           mov byte ptr [esp + 0x11], 0x42
// 00657d98  c644241249           mov byte ptr [esp + 0x12], 0x49
// 00657d9d  c644241354           mov byte ptr [esp + 0x13], 0x54
// 00657da2  c644241400           mov byte ptr [esp + 0x14], 0
// 00657da7  f6c102               test cl, 2
// 00657daa  744c                 je 0x657df8
// 00657dac  b308                 mov bl, 8
// 00657dae  83f903               cmp ecx, 3
// 00657db1  7406                 je 0x657db9
// 00657db3  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 00657db9  8b742420             mov esi, dword ptr [esp + 0x20]
// 00657dbd  8a16                 mov dl, byte ptr [esi]
// 00657dbf  84d2                 test dl, dl
// 00657dc1  0f8481000000         je 0x657e48
// 00657dc7  3ad3                 cmp dl, bl
// 00657dc9  777d                 ja 0x657e48
// 00657dcb  8a4e01               mov cl, byte ptr [esi + 1]
// 00657dce  84c9                 test cl, cl
// 00657dd0  7476                 je 0x657e48
// 00657dd2  3acb                 cmp cl, bl
// 00657dd4  7772                 ja 0x657e48
// 00657dd6  8a4602               mov al, byte ptr [esi + 2]
// 00657dd9  84c0                 test al, al
// 00657ddb  746b                 je 0x657e48
// 00657ddd  3ac3                 cmp al, bl
// 00657ddf  7767                 ja 0x657e48
// 00657de1  884c240d             mov byte ptr [esp + 0xd], cl
// 00657de5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00657de9  8844240e             mov byte ptr [esp + 0xe], al
// 00657ded  8854240c             mov byte ptr [esp + 0xc], dl
// 00657df1  b803000000           mov eax, 3
// 00657df6  eb1c                 jmp 0x657e14
// 00657df8  8b742420             mov esi, dword ptr [esp + 0x20]
// 00657dfc  8a4603               mov al, byte ptr [esi + 3]
// 00657dff  84c0                 test al, al
// 00657e01  7445                 je 0x657e48
// 00657e03  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 00657e09  773d                 ja 0x657e48
// 00657e0b  8844240c             mov byte ptr [esp + 0xc], al
// 00657e0f  b801000000           mov eax, 1
// 00657e14  f6c104               test cl, 4
// 00657e17  7414                 je 0x657e2d
// 00657e19  8a4e04               mov cl, byte ptr [esi + 4]
// 00657e1c  84c9                 test cl, cl
// 00657e1e  7428                 je 0x657e48
// 00657e20  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 00657e26  7720                 ja 0x657e48
// 00657e28  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 00657e2c  40                   inc eax
// 00657e2d  50                   push eax
// 00657e2e  8d442410             lea eax, [esp + 0x10]
// 00657e32  50                   push eax
// 00657e33  8d4c2418             lea ecx, [esp + 0x18]
// 00657e37  51                   push ecx
// 00657e38  57                   push edi
// 00657e39  e8e2f3ffff           call 0x657220
// 00657e3e  83c410               add esp, 0x10
// 00657e41  5f                   pop edi
// 00657e42  5e                   pop esi
// 00657e43  5b                   pop ebx
// 00657e44  83c40c               add esp, 0xc
// 00657e47  c3                   ret 
// 00657e48  68509eb800           push 0xb89e50
// 00657e4d  57                   push edi
// 00657e4e  e80d64ffff           call 0x64e260
// 00657e53  83c408               add esp, 8
// 00657e56  5f                   pop edi
// 00657e57  5e                   pop esi
// 00657e58  5b                   pop ebx
// 00657e59  83c40c               add esp, 0xc
// 00657e5c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
