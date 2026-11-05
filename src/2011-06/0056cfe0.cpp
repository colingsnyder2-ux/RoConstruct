// from server: 100% by auto
// roc 2011-06 0056cfe0  unit: seg_00560000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056cfe0
//
// 0056cfe0  83ec10               sub esp, 0x10
// 0056cfe3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056cfe7  8a4102               mov al, byte ptr [ecx + 2]
// 0056cfea  c6042474             mov byte ptr [esp], 0x74
// 0056cfee  c644240149           mov byte ptr [esp + 1], 0x49
// 0056cff3  c64424024d           mov byte ptr [esp + 2], 0x4d
// 0056cff8  c644240345           mov byte ptr [esp + 3], 0x45
// 0056cffd  c644240400           mov byte ptr [esp + 4], 0
// 0056d002  3c0c                 cmp al, 0xc
// 0056d004  776d                 ja 0x56d073
// 0056d006  3c01                 cmp al, 1
// 0056d008  7269                 jb 0x56d073
// 0056d00a  8a4103               mov al, byte ptr [ecx + 3]
// 0056d00d  3c1f                 cmp al, 0x1f
// 0056d00f  7762                 ja 0x56d073
// 0056d011  3c01                 cmp al, 1
// 0056d013  725e                 jb 0x56d073
// 0056d015  80790417             cmp byte ptr [ecx + 4], 0x17
// 0056d019  7758                 ja 0x56d073
// 0056d01b  8a5106               mov dl, byte ptr [ecx + 6]
// 0056d01e  80fa3c               cmp dl, 0x3c
// 0056d021  7750                 ja 0x56d073
// 0056d023  0fb701               movzx eax, word ptr [ecx]
// 0056d026  53                   push ebx
// 0056d027  8bd8                 mov ebx, eax
// 0056d029  8844240d             mov byte ptr [esp + 0xd], al
// 0056d02d  8a4102               mov al, byte ptr [ecx + 2]
// 0056d030  8844240e             mov byte ptr [esp + 0xe], al
// 0056d034  8a4103               mov al, byte ptr [ecx + 3]
// 0056d037  8844240f             mov byte ptr [esp + 0xf], al
// 0056d03b  8a4104               mov al, byte ptr [ecx + 4]
// 0056d03e  88442410             mov byte ptr [esp + 0x10], al
// 0056d042  0fb64105             movzx eax, byte ptr [ecx + 5]
// 0056d046  6a07                 push 7
// 0056d048  8d4c2410             lea ecx, [esp + 0x10]
// 0056d04c  88542416             mov byte ptr [esp + 0x16], dl
// 0056d050  51                   push ecx
// 0056d051  8d54240c             lea edx, [esp + 0xc]
// 0056d055  88442419             mov byte ptr [esp + 0x19], al
// 0056d059  8b442420             mov eax, dword ptr [esp + 0x20]
// 0056d05d  52                   push edx
// 0056d05e  c1eb08               shr ebx, 8
// 0056d061  50                   push eax
// 0056d062  885c241c             mov byte ptr [esp + 0x1c], bl
// 0056d066  e8a5eaffff           call 0x56bb10
// 0056d06b  83c410               add esp, 0x10
// 0056d06e  5b                   pop ebx
// 0056d06f  83c410               add esp, 0x10
// 0056d072  c3                   ret 
// 0056d073  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0056d077  68f461a800           push 0xa861f4
// 0056d07c  51                   push ecx
// 0056d07d  e85e43ffff           call 0x5613e0
// 0056d082  83c408               add esp, 8
// 0056d085  83c410               add esp, 0x10
// 0056d088  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
