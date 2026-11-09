// from server: 100% by auto
// roc 2010-06 0056fee0  unit: G3D::LineSegment  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056fee0
//
// 0056fee0  83ec0c               sub esp, 0xc
// 0056fee3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056fee7  53                   push ebx
// 0056fee8  56                   push esi
// 0056fee9  57                   push edi
// 0056feea  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056feee  c644241073           mov byte ptr [esp + 0x10], 0x73
// 0056fef3  c644241142           mov byte ptr [esp + 0x11], 0x42
// 0056fef8  c644241249           mov byte ptr [esp + 0x12], 0x49
// 0056fefd  c644241354           mov byte ptr [esp + 0x13], 0x54
// 0056ff02  c644241400           mov byte ptr [esp + 0x14], 0
// 0056ff07  f6c102               test cl, 2
// 0056ff0a  744c                 je 0x56ff58
// 0056ff0c  b308                 mov bl, 8
// 0056ff0e  83f903               cmp ecx, 3
// 0056ff11  7406                 je 0x56ff19
// 0056ff13  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 0056ff19  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056ff1d  8a16                 mov dl, byte ptr [esi]
// 0056ff1f  84d2                 test dl, dl
// 0056ff21  0f8481000000         je 0x56ffa8
// 0056ff27  3ad3                 cmp dl, bl
// 0056ff29  777d                 ja 0x56ffa8
// 0056ff2b  8a4e01               mov cl, byte ptr [esi + 1]
// 0056ff2e  84c9                 test cl, cl
// 0056ff30  7476                 je 0x56ffa8
// 0056ff32  3acb                 cmp cl, bl
// 0056ff34  7772                 ja 0x56ffa8
// 0056ff36  8a4602               mov al, byte ptr [esi + 2]
// 0056ff39  84c0                 test al, al
// 0056ff3b  746b                 je 0x56ffa8
// 0056ff3d  3ac3                 cmp al, bl
// 0056ff3f  7767                 ja 0x56ffa8
// 0056ff41  884c240d             mov byte ptr [esp + 0xd], cl
// 0056ff45  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056ff49  8844240e             mov byte ptr [esp + 0xe], al
// 0056ff4d  8854240c             mov byte ptr [esp + 0xc], dl
// 0056ff51  b803000000           mov eax, 3
// 0056ff56  eb1c                 jmp 0x56ff74
// 0056ff58  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056ff5c  8a4603               mov al, byte ptr [esi + 3]
// 0056ff5f  84c0                 test al, al
// 0056ff61  7445                 je 0x56ffa8
// 0056ff63  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 0056ff69  773d                 ja 0x56ffa8
// 0056ff6b  8844240c             mov byte ptr [esp + 0xc], al
// 0056ff6f  b801000000           mov eax, 1
// 0056ff74  f6c104               test cl, 4
// 0056ff77  7414                 je 0x56ff8d
// 0056ff79  8a4e04               mov cl, byte ptr [esi + 4]
// 0056ff7c  84c9                 test cl, cl
// 0056ff7e  7428                 je 0x56ffa8
// 0056ff80  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 0056ff86  7720                 ja 0x56ffa8
// 0056ff88  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 0056ff8c  40                   inc eax
// 0056ff8d  50                   push eax
// 0056ff8e  8d442410             lea eax, [esp + 0x10]
// 0056ff92  50                   push eax
// 0056ff93  8d4c2418             lea ecx, [esp + 0x18]
// 0056ff97  51                   push ecx
// 0056ff98  57                   push edi
// 0056ff99  e8f2f3ffff           call 0x56f390
// 0056ff9e  83c410               add esp, 0x10
// 0056ffa1  5f                   pop edi
// 0056ffa2  5e                   pop esi
// 0056ffa3  5b                   pop ebx
// 0056ffa4  83c40c               add esp, 0xc
// 0056ffa7  c3                   ret 
// 0056ffa8  68803ca200           push 0xa23c80
// 0056ffad  57                   push edi
// 0056ffae  e8ad1b0000           call 0x571b60
// 0056ffb3  83c408               add esp, 8
// 0056ffb6  5f                   pop edi
// 0056ffb7  5e                   pop esi
// 0056ffb8  5b                   pop ebx
// 0056ffb9  83c40c               add esp, 0xc
// 0056ffbc  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
