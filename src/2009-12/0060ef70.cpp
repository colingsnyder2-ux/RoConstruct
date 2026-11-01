// from server: 100% by auto
// roc 2009-12 0060ef70  unit: seg_00600000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060ef70
//
// 0060ef70  83ec10               sub esp, 0x10
// 0060ef73  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0060ef77  8a4102               mov al, byte ptr [ecx + 2]
// 0060ef7a  c6042474             mov byte ptr [esp], 0x74
// 0060ef7e  c644240149           mov byte ptr [esp + 1], 0x49
// 0060ef83  c64424024d           mov byte ptr [esp + 2], 0x4d
// 0060ef88  c644240345           mov byte ptr [esp + 3], 0x45
// 0060ef8d  c644240400           mov byte ptr [esp + 4], 0
// 0060ef92  3c0c                 cmp al, 0xc
// 0060ef94  776d                 ja 0x60f003
// 0060ef96  3c01                 cmp al, 1
// 0060ef98  7269                 jb 0x60f003
// 0060ef9a  8a4103               mov al, byte ptr [ecx + 3]
// 0060ef9d  3c1f                 cmp al, 0x1f
// 0060ef9f  7762                 ja 0x60f003
// 0060efa1  3c01                 cmp al, 1
// 0060efa3  725e                 jb 0x60f003
// 0060efa5  80790417             cmp byte ptr [ecx + 4], 0x17
// 0060efa9  7758                 ja 0x60f003
// 0060efab  8a5106               mov dl, byte ptr [ecx + 6]
// 0060efae  80fa3c               cmp dl, 0x3c
// 0060efb1  7750                 ja 0x60f003
// 0060efb3  0fb701               movzx eax, word ptr [ecx]
// 0060efb6  53                   push ebx
// 0060efb7  8bd8                 mov ebx, eax
// 0060efb9  8844240d             mov byte ptr [esp + 0xd], al
// 0060efbd  8a4102               mov al, byte ptr [ecx + 2]
// 0060efc0  8844240e             mov byte ptr [esp + 0xe], al
// 0060efc4  8a4103               mov al, byte ptr [ecx + 3]
// 0060efc7  8844240f             mov byte ptr [esp + 0xf], al
// 0060efcb  8a4104               mov al, byte ptr [ecx + 4]
// 0060efce  88442410             mov byte ptr [esp + 0x10], al
// 0060efd2  0fb64105             movzx eax, byte ptr [ecx + 5]
// 0060efd6  6a07                 push 7
// 0060efd8  8d4c2410             lea ecx, [esp + 0x10]
// 0060efdc  88542416             mov byte ptr [esp + 0x16], dl
// 0060efe0  51                   push ecx
// 0060efe1  8d54240c             lea edx, [esp + 0xc]
// 0060efe5  88442419             mov byte ptr [esp + 0x19], al
// 0060efe9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0060efed  52                   push edx
// 0060efee  c1eb08               shr ebx, 8
// 0060eff1  50                   push eax
// 0060eff2  885c241c             mov byte ptr [esp + 0x1c], bl
// 0060eff6  e875eaffff           call 0x60da70
// 0060effb  83c410               add esp, 0x10
// 0060effe  5b                   pop ebx
// 0060efff  83c410               add esp, 0x10
// 0060f002  c3                   ret 
// 0060f003  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0060f007  68ac619c00           push 0x9c61ac
// 0060f00c  51                   push ecx
// 0060f00d  e82e120000           call 0x610240
// 0060f012  83c408               add esp, 8
// 0060f015  83c410               add esp, 0x10
// 0060f018  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
