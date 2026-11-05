// from server: 100% by auto
// roc 2009-12 0060e5c0  unit: seg_00600000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e5c0
//
// 0060e5c0  83ec0c               sub esp, 0xc
// 0060e5c3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060e5c7  53                   push ebx
// 0060e5c8  56                   push esi
// 0060e5c9  57                   push edi
// 0060e5ca  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0060e5ce  c644241073           mov byte ptr [esp + 0x10], 0x73
// 0060e5d3  c644241142           mov byte ptr [esp + 0x11], 0x42
// 0060e5d8  c644241249           mov byte ptr [esp + 0x12], 0x49
// 0060e5dd  c644241354           mov byte ptr [esp + 0x13], 0x54
// 0060e5e2  c644241400           mov byte ptr [esp + 0x14], 0
// 0060e5e7  f6c102               test cl, 2
// 0060e5ea  744c                 je 0x60e638
// 0060e5ec  b308                 mov bl, 8
// 0060e5ee  83f903               cmp ecx, 3
// 0060e5f1  7406                 je 0x60e5f9
// 0060e5f3  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 0060e5f9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060e5fd  8a16                 mov dl, byte ptr [esi]
// 0060e5ff  84d2                 test dl, dl
// 0060e601  0f8481000000         je 0x60e688
// 0060e607  3ad3                 cmp dl, bl
// 0060e609  777d                 ja 0x60e688
// 0060e60b  8a4e01               mov cl, byte ptr [esi + 1]
// 0060e60e  84c9                 test cl, cl
// 0060e610  7476                 je 0x60e688
// 0060e612  3acb                 cmp cl, bl
// 0060e614  7772                 ja 0x60e688
// 0060e616  8a4602               mov al, byte ptr [esi + 2]
// 0060e619  84c0                 test al, al
// 0060e61b  746b                 je 0x60e688
// 0060e61d  3ac3                 cmp al, bl
// 0060e61f  7767                 ja 0x60e688
// 0060e621  884c240d             mov byte ptr [esp + 0xd], cl
// 0060e625  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060e629  8844240e             mov byte ptr [esp + 0xe], al
// 0060e62d  8854240c             mov byte ptr [esp + 0xc], dl
// 0060e631  b803000000           mov eax, 3
// 0060e636  eb1c                 jmp 0x60e654
// 0060e638  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060e63c  8a4603               mov al, byte ptr [esi + 3]
// 0060e63f  84c0                 test al, al
// 0060e641  7445                 je 0x60e688
// 0060e643  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 0060e649  773d                 ja 0x60e688
// 0060e64b  8844240c             mov byte ptr [esp + 0xc], al
// 0060e64f  b801000000           mov eax, 1
// 0060e654  f6c104               test cl, 4
// 0060e657  7414                 je 0x60e66d
// 0060e659  8a4e04               mov cl, byte ptr [esi + 4]
// 0060e65c  84c9                 test cl, cl
// 0060e65e  7428                 je 0x60e688
// 0060e660  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 0060e666  7720                 ja 0x60e688
// 0060e668  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 0060e66c  40                   inc eax
// 0060e66d  50                   push eax
// 0060e66e  8d442410             lea eax, [esp + 0x10]
// 0060e672  50                   push eax
// 0060e673  8d4c2418             lea ecx, [esp + 0x18]
// 0060e677  51                   push ecx
// 0060e678  57                   push edi
// 0060e679  e8f2f3ffff           call 0x60da70
// 0060e67e  83c410               add esp, 0x10
// 0060e681  5f                   pop edi
// 0060e682  5e                   pop esi
// 0060e683  5b                   pop ebx
// 0060e684  83c40c               add esp, 0xc
// 0060e687  c3                   ret 
// 0060e688  680c5f9c00           push 0x9c5f0c
// 0060e68d  57                   push edi
// 0060e68e  e8ad1b0000           call 0x610240
// 0060e693  83c408               add esp, 8
// 0060e696  5f                   pop edi
// 0060e697  5e                   pop esi
// 0060e698  5b                   pop ebx
// 0060e699  83c40c               add esp, 0xc
// 0060e69c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
