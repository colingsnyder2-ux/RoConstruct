// from server: 100% by auto
// roc 2010-06 00570890  unit: G3D::LineSegment  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00570890
//
// 00570890  83ec10               sub esp, 0x10
// 00570893  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00570897  8a4102               mov al, byte ptr [ecx + 2]
// 0057089a  c6042474             mov byte ptr [esp], 0x74
// 0057089e  c644240149           mov byte ptr [esp + 1], 0x49
// 005708a3  c64424024d           mov byte ptr [esp + 2], 0x4d
// 005708a8  c644240345           mov byte ptr [esp + 3], 0x45
// 005708ad  c644240400           mov byte ptr [esp + 4], 0
// 005708b2  3c0c                 cmp al, 0xc
// 005708b4  776d                 ja 0x570923
// 005708b6  3c01                 cmp al, 1
// 005708b8  7269                 jb 0x570923
// 005708ba  8a4103               mov al, byte ptr [ecx + 3]
// 005708bd  3c1f                 cmp al, 0x1f
// 005708bf  7762                 ja 0x570923
// 005708c1  3c01                 cmp al, 1
// 005708c3  725e                 jb 0x570923
// 005708c5  80790417             cmp byte ptr [ecx + 4], 0x17
// 005708c9  7758                 ja 0x570923
// 005708cb  8a5106               mov dl, byte ptr [ecx + 6]
// 005708ce  80fa3c               cmp dl, 0x3c
// 005708d1  7750                 ja 0x570923
// 005708d3  0fb701               movzx eax, word ptr [ecx]
// 005708d6  53                   push ebx
// 005708d7  8bd8                 mov ebx, eax
// 005708d9  8844240d             mov byte ptr [esp + 0xd], al
// 005708dd  8a4102               mov al, byte ptr [ecx + 2]
// 005708e0  8844240e             mov byte ptr [esp + 0xe], al
// 005708e4  8a4103               mov al, byte ptr [ecx + 3]
// 005708e7  8844240f             mov byte ptr [esp + 0xf], al
// 005708eb  8a4104               mov al, byte ptr [ecx + 4]
// 005708ee  88442410             mov byte ptr [esp + 0x10], al
// 005708f2  0fb64105             movzx eax, byte ptr [ecx + 5]
// 005708f6  6a07                 push 7
// 005708f8  8d4c2410             lea ecx, [esp + 0x10]
// 005708fc  88542416             mov byte ptr [esp + 0x16], dl
// 00570900  51                   push ecx
// 00570901  8d54240c             lea edx, [esp + 0xc]
// 00570905  88442419             mov byte ptr [esp + 0x19], al
// 00570909  8b442420             mov eax, dword ptr [esp + 0x20]
// 0057090d  52                   push edx
// 0057090e  c1eb08               shr ebx, 8
// 00570911  50                   push eax
// 00570912  885c241c             mov byte ptr [esp + 0x1c], bl
// 00570916  e875eaffff           call 0x56f390
// 0057091b  83c410               add esp, 0x10
// 0057091e  5b                   pop ebx
// 0057091f  83c410               add esp, 0x10
// 00570922  c3                   ret 
// 00570923  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00570927  68243fa200           push 0xa23f24
// 0057092c  51                   push ecx
// 0057092d  e82e120000           call 0x571b60
// 00570932  83c408               add esp, 8
// 00570935  83c410               add esp, 0x10
// 00570938  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
