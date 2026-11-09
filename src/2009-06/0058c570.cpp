// from server: 100% by auto
// roc 2009-06 0058c570  unit: seg_00580000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c570
//
// 0058c570  83ec0c               sub esp, 0xc
// 0058c573  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058c577  53                   push ebx
// 0058c578  56                   push esi
// 0058c579  57                   push edi
// 0058c57a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0058c57e  c644241073           mov byte ptr [esp + 0x10], 0x73
// 0058c583  c644241142           mov byte ptr [esp + 0x11], 0x42
// 0058c588  c644241249           mov byte ptr [esp + 0x12], 0x49
// 0058c58d  c644241354           mov byte ptr [esp + 0x13], 0x54
// 0058c592  c644241400           mov byte ptr [esp + 0x14], 0
// 0058c597  f6c102               test cl, 2
// 0058c59a  744c                 je 0x58c5e8
// 0058c59c  b308                 mov bl, 8
// 0058c59e  83f903               cmp ecx, 3
// 0058c5a1  7406                 je 0x58c5a9
// 0058c5a3  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 0058c5a9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058c5ad  8a16                 mov dl, byte ptr [esi]
// 0058c5af  84d2                 test dl, dl
// 0058c5b1  0f8481000000         je 0x58c638
// 0058c5b7  3ad3                 cmp dl, bl
// 0058c5b9  777d                 ja 0x58c638
// 0058c5bb  8a4e01               mov cl, byte ptr [esi + 1]
// 0058c5be  84c9                 test cl, cl
// 0058c5c0  7476                 je 0x58c638
// 0058c5c2  3acb                 cmp cl, bl
// 0058c5c4  7772                 ja 0x58c638
// 0058c5c6  8a4602               mov al, byte ptr [esi + 2]
// 0058c5c9  84c0                 test al, al
// 0058c5cb  746b                 je 0x58c638
// 0058c5cd  3ac3                 cmp al, bl
// 0058c5cf  7767                 ja 0x58c638
// 0058c5d1  884c240d             mov byte ptr [esp + 0xd], cl
// 0058c5d5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058c5d9  8844240e             mov byte ptr [esp + 0xe], al
// 0058c5dd  8854240c             mov byte ptr [esp + 0xc], dl
// 0058c5e1  b803000000           mov eax, 3
// 0058c5e6  eb1c                 jmp 0x58c604
// 0058c5e8  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058c5ec  8a4603               mov al, byte ptr [esi + 3]
// 0058c5ef  84c0                 test al, al
// 0058c5f1  7445                 je 0x58c638
// 0058c5f3  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 0058c5f9  773d                 ja 0x58c638
// 0058c5fb  8844240c             mov byte ptr [esp + 0xc], al
// 0058c5ff  b801000000           mov eax, 1
// 0058c604  f6c104               test cl, 4
// 0058c607  7414                 je 0x58c61d
// 0058c609  8a4e04               mov cl, byte ptr [esi + 4]
// 0058c60c  84c9                 test cl, cl
// 0058c60e  7428                 je 0x58c638
// 0058c610  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 0058c616  7720                 ja 0x58c638
// 0058c618  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 0058c61c  40                   inc eax
// 0058c61d  50                   push eax
// 0058c61e  8d442410             lea eax, [esp + 0x10]
// 0058c622  50                   push eax
// 0058c623  8d4c2418             lea ecx, [esp + 0x18]
// 0058c627  51                   push ecx
// 0058c628  57                   push edi
// 0058c629  e8f2f3ffff           call 0x58ba20
// 0058c62e  83c410               add esp, 0x10
// 0058c631  5f                   pop edi
// 0058c632  5e                   pop esi
// 0058c633  5b                   pop ebx
// 0058c634  83c40c               add esp, 0xc
// 0058c637  c3                   ret 
// 0058c638  6874f08c00           push 0x8cf074
// 0058c63d  57                   push edi
// 0058c63e  e8cd1b0000           call 0x58e210
// 0058c643  83c408               add esp, 8
// 0058c646  5f                   pop edi
// 0058c647  5e                   pop esi
// 0058c648  5b                   pop ebx
// 0058c649  83c40c               add esp, 0xc
// 0058c64c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
