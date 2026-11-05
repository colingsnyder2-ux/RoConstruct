// from server: 100% by auto
// roc 2009-06 0058cf40  unit: seg_00580000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058cf40
//
// 0058cf40  83ec10               sub esp, 0x10
// 0058cf43  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0058cf47  8a4102               mov al, byte ptr [ecx + 2]
// 0058cf4a  c6042474             mov byte ptr [esp], 0x74
// 0058cf4e  c644240149           mov byte ptr [esp + 1], 0x49
// 0058cf53  c64424024d           mov byte ptr [esp + 2], 0x4d
// 0058cf58  c644240345           mov byte ptr [esp + 3], 0x45
// 0058cf5d  c644240400           mov byte ptr [esp + 4], 0
// 0058cf62  3c0c                 cmp al, 0xc
// 0058cf64  776d                 ja 0x58cfd3
// 0058cf66  3c01                 cmp al, 1
// 0058cf68  7269                 jb 0x58cfd3
// 0058cf6a  8a4103               mov al, byte ptr [ecx + 3]
// 0058cf6d  3c1f                 cmp al, 0x1f
// 0058cf6f  7762                 ja 0x58cfd3
// 0058cf71  3c01                 cmp al, 1
// 0058cf73  725e                 jb 0x58cfd3
// 0058cf75  80790417             cmp byte ptr [ecx + 4], 0x17
// 0058cf79  7758                 ja 0x58cfd3
// 0058cf7b  8a5106               mov dl, byte ptr [ecx + 6]
// 0058cf7e  80fa3c               cmp dl, 0x3c
// 0058cf81  7750                 ja 0x58cfd3
// 0058cf83  0fb701               movzx eax, word ptr [ecx]
// 0058cf86  53                   push ebx
// 0058cf87  8bd8                 mov ebx, eax
// 0058cf89  8844240d             mov byte ptr [esp + 0xd], al
// 0058cf8d  8a4102               mov al, byte ptr [ecx + 2]
// 0058cf90  8844240e             mov byte ptr [esp + 0xe], al
// 0058cf94  8a4103               mov al, byte ptr [ecx + 3]
// 0058cf97  8844240f             mov byte ptr [esp + 0xf], al
// 0058cf9b  8a4104               mov al, byte ptr [ecx + 4]
// 0058cf9e  88442410             mov byte ptr [esp + 0x10], al
// 0058cfa2  0fb64105             movzx eax, byte ptr [ecx + 5]
// 0058cfa6  6a07                 push 7
// 0058cfa8  8d4c2410             lea ecx, [esp + 0x10]
// 0058cfac  88542416             mov byte ptr [esp + 0x16], dl
// 0058cfb0  51                   push ecx
// 0058cfb1  8d54240c             lea edx, [esp + 0xc]
// 0058cfb5  88442419             mov byte ptr [esp + 0x19], al
// 0058cfb9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0058cfbd  52                   push edx
// 0058cfbe  c1eb08               shr ebx, 8
// 0058cfc1  50                   push eax
// 0058cfc2  885c241c             mov byte ptr [esp + 0x1c], bl
// 0058cfc6  e855eaffff           call 0x58ba20
// 0058cfcb  83c410               add esp, 0x10
// 0058cfce  5b                   pop ebx
// 0058cfcf  83c410               add esp, 0x10
// 0058cfd2  c3                   ret 
// 0058cfd3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0058cfd7  681cf38c00           push 0x8cf31c
// 0058cfdc  51                   push ecx
// 0058cfdd  e82e120000           call 0x58e210
// 0058cfe2  83c408               add esp, 8
// 0058cfe5  83c410               add esp, 0x10
// 0058cfe8  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
