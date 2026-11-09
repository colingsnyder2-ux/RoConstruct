// from server: 100% by auto
// roc 2011-06 0056c670  unit: seg_00560000  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c670
//
// 0056c670  83ec0c               sub esp, 0xc
// 0056c673  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056c677  53                   push ebx
// 0056c678  56                   push esi
// 0056c679  57                   push edi
// 0056c67a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0056c67e  c644241073           mov byte ptr [esp + 0x10], 0x73
// 0056c683  c644241142           mov byte ptr [esp + 0x11], 0x42
// 0056c688  c644241249           mov byte ptr [esp + 0x12], 0x49
// 0056c68d  c644241354           mov byte ptr [esp + 0x13], 0x54
// 0056c692  c644241400           mov byte ptr [esp + 0x14], 0
// 0056c697  f6c102               test cl, 2
// 0056c69a  744c                 je 0x56c6e8
// 0056c69c  b308                 mov bl, 8
// 0056c69e  83f903               cmp ecx, 3
// 0056c6a1  7406                 je 0x56c6a9
// 0056c6a3  8a9f28010000         mov bl, byte ptr [edi + 0x128]
// 0056c6a9  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056c6ad  8a16                 mov dl, byte ptr [esi]
// 0056c6af  84d2                 test dl, dl
// 0056c6b1  0f8481000000         je 0x56c738
// 0056c6b7  3ad3                 cmp dl, bl
// 0056c6b9  777d                 ja 0x56c738
// 0056c6bb  8a4e01               mov cl, byte ptr [esi + 1]
// 0056c6be  84c9                 test cl, cl
// 0056c6c0  7476                 je 0x56c738
// 0056c6c2  3acb                 cmp cl, bl
// 0056c6c4  7772                 ja 0x56c738
// 0056c6c6  8a4602               mov al, byte ptr [esi + 2]
// 0056c6c9  84c0                 test al, al
// 0056c6cb  746b                 je 0x56c738
// 0056c6cd  3ac3                 cmp al, bl
// 0056c6cf  7767                 ja 0x56c738
// 0056c6d1  884c240d             mov byte ptr [esp + 0xd], cl
// 0056c6d5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056c6d9  8844240e             mov byte ptr [esp + 0xe], al
// 0056c6dd  8854240c             mov byte ptr [esp + 0xc], dl
// 0056c6e1  b803000000           mov eax, 3
// 0056c6e6  eb1c                 jmp 0x56c704
// 0056c6e8  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056c6ec  8a4603               mov al, byte ptr [esi + 3]
// 0056c6ef  84c0                 test al, al
// 0056c6f1  7445                 je 0x56c738
// 0056c6f3  3a8728010000         cmp al, byte ptr [edi + 0x128]
// 0056c6f9  773d                 ja 0x56c738
// 0056c6fb  8844240c             mov byte ptr [esp + 0xc], al
// 0056c6ff  b801000000           mov eax, 1
// 0056c704  f6c104               test cl, 4
// 0056c707  7414                 je 0x56c71d
// 0056c709  8a4e04               mov cl, byte ptr [esi + 4]
// 0056c70c  84c9                 test cl, cl
// 0056c70e  7428                 je 0x56c738
// 0056c710  3a8f28010000         cmp cl, byte ptr [edi + 0x128]
// 0056c716  7720                 ja 0x56c738
// 0056c718  884c040c             mov byte ptr [esp + eax + 0xc], cl
// 0056c71c  40                   inc eax
// 0056c71d  50                   push eax
// 0056c71e  8d442410             lea eax, [esp + 0x10]
// 0056c722  50                   push eax
// 0056c723  8d4c2418             lea ecx, [esp + 0x18]
// 0056c727  51                   push ecx
// 0056c728  57                   push edi
// 0056c729  e8e2f3ffff           call 0x56bb10
// 0056c72e  83c410               add esp, 0x10
// 0056c731  5f                   pop edi
// 0056c732  5e                   pop esi
// 0056c733  5b                   pop ebx
// 0056c734  83c40c               add esp, 0xc
// 0056c737  c3                   ret 
// 0056c738  680060a800           push 0xa86000
// 0056c73d  57                   push edi
// 0056c73e  e89d4cffff           call 0x5613e0
// 0056c743  83c408               add esp, 8
// 0056c746  5f                   pop edi
// 0056c747  5e                   pop esi
// 0056c748  5b                   pop ebx
// 0056c749  83c40c               add esp, 0xc
// 0056c74c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sBIT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
