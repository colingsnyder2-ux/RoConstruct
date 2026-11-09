// from server: 100% by auto
// roc 2010-06 0056fce0  unit: G3D::LineSegment  size: 512 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056fce0
//
// 0056fce0  83ec18               sub esp, 0x18
// 0056fce3  53                   push ebx
// 0056fce4  55                   push ebp
// 0056fce5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056fce9  33c0                 xor eax, eax
// 0056fceb  807d0408             cmp byte ptr [ebp + 4], 8
// 0056fcef  56                   push esi
// 0056fcf0  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0056fcf3  0f95c0               setne al
// 0056fcf6  57                   push edi
// 0056fcf7  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056fcfb  c644241473           mov byte ptr [esp + 0x14], 0x73
// 0056fd00  c644241550           mov byte ptr [esp + 0x15], 0x50
// 0056fd05  c64424164c           mov byte ptr [esp + 0x16], 0x4c
// 0056fd0a  c644241754           mov byte ptr [esp + 0x17], 0x54
// 0056fd0f  8d048506000000       lea eax, [eax*4 + 6]
// 0056fd16  0faff0               imul esi, eax
// 0056fd19  89442430             mov dword ptr [esp + 0x30], eax
// 0056fd1d  8b4500               mov eax, dword ptr [ebp]
// 0056fd20  c644241800           mov byte ptr [esp + 0x18], 0
// 0056fd25  85c0                 test eax, eax
// 0056fd27  0f849d010000         je 0x56feca
// 0056fd2d  8d4c2410             lea ecx, [esp + 0x10]
// 0056fd31  51                   push ecx
// 0056fd32  50                   push eax
// 0056fd33  57                   push edi
// 0056fd34  e857ebffff           call 0x56e890
// 0056fd39  8bd8                 mov ebx, eax
// 0056fd3b  83c40c               add esp, 0xc
// 0056fd3e  85db                 test ebx, ebx
// 0056fd40  0f8484010000         je 0x56feca
// 0056fd46  8d543302             lea edx, [ebx + esi + 2]
// 0056fd4a  52                   push edx
// 0056fd4b  8d442418             lea eax, [esp + 0x18]
// 0056fd4f  50                   push eax
// 0056fd50  57                   push edi
// 0056fd51  e8dae4ffff           call 0x56e230
// 0056fd56  83c40c               add esp, 0xc
// 0056fd59  8d7301               lea esi, [ebx + 1]
// 0056fd5c  85ff                 test edi, edi
// 0056fd5e  743f                 je 0x56fd9f
// 0056fd60  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0056fd64  85db                 test ebx, ebx
// 0056fd66  7417                 je 0x56fd7f
// 0056fd68  85f6                 test esi, esi
// 0056fd6a  7613                 jbe 0x56fd7f
// 0056fd6c  56                   push esi
// 0056fd6d  53                   push ebx
// 0056fd6e  57                   push edi
// 0056fd6f  e88c4fffff           call 0x564d00
// 0056fd74  56                   push esi
// 0056fd75  53                   push ebx
// 0056fd76  57                   push edi
// 0056fd77  e86452ffff           call 0x564fe0
// 0056fd7c  83c418               add esp, 0x18
// 0056fd7f  85ff                 test edi, edi
// 0056fd81  741c                 je 0x56fd9f
// 0056fd83  8d7504               lea esi, [ebp + 4]
// 0056fd86  85f6                 test esi, esi
// 0056fd88  7415                 je 0x56fd9f
// 0056fd8a  6a01                 push 1
// 0056fd8c  56                   push esi
// 0056fd8d  57                   push edi
// 0056fd8e  e86d4fffff           call 0x564d00
// 0056fd93  6a01                 push 1
// 0056fd95  56                   push esi
// 0056fd96  57                   push edi
// 0056fd97  e84452ffff           call 0x564fe0
// 0056fd9c  83c418               add esp, 0x18
// 0056fd9f  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0056fda2  8b7508               mov esi, dword ptr [ebp + 8]
// 0056fda5  8d0c80               lea ecx, [eax + eax*4]
// 0056fda8  8d144e               lea edx, [esi + ecx*2]
// 0056fdab  3bf2                 cmp esi, edx
// 0056fdad  0f83c8000000         jae 0x56fe7b
// 0056fdb3  807d0408             cmp byte ptr [ebp + 4], 8
// 0056fdb7  7530                 jne 0x56fde9
// 0056fdb9  0fb606               movzx eax, byte ptr [esi]
// 0056fdbc  8844241c             mov byte ptr [esp + 0x1c], al
// 0056fdc0  8a4e02               mov cl, byte ptr [esi + 2]
// 0056fdc3  884c241d             mov byte ptr [esp + 0x1d], cl
// 0056fdc7  8a5604               mov dl, byte ptr [esi + 4]
// 0056fdca  8854241e             mov byte ptr [esp + 0x1e], dl
// 0056fdce  0fb64606             movzx eax, byte ptr [esi + 6]
// 0056fdd2  8844241f             mov byte ptr [esp + 0x1f], al
// 0056fdd6  0fb74608             movzx eax, word ptr [esi + 8]
// 0056fdda  8bc8                 mov ecx, eax
// 0056fddc  c1e908               shr ecx, 8
// 0056fddf  884c2420             mov byte ptr [esp + 0x20], cl
// 0056fde3  88442421             mov byte ptr [esp + 0x21], al
// 0056fde7  eb54                 jmp 0x56fe3d
// 0056fde9  0fb706               movzx eax, word ptr [esi]
// 0056fdec  8bd0                 mov edx, eax
// 0056fdee  c1ea08               shr edx, 8
// 0056fdf1  8854241c             mov byte ptr [esp + 0x1c], dl
// 0056fdf5  8844241d             mov byte ptr [esp + 0x1d], al
// 0056fdf9  0fb74602             movzx eax, word ptr [esi + 2]
// 0056fdfd  8bc8                 mov ecx, eax
// 0056fdff  c1e908               shr ecx, 8
// 0056fe02  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056fe06  8844241f             mov byte ptr [esp + 0x1f], al
// 0056fe0a  0fb74604             movzx eax, word ptr [esi + 4]
// 0056fe0e  8bd0                 mov edx, eax
// 0056fe10  c1ea08               shr edx, 8
// 0056fe13  88542420             mov byte ptr [esp + 0x20], dl
// 0056fe17  88442421             mov byte ptr [esp + 0x21], al
// 0056fe1b  0fb74606             movzx eax, word ptr [esi + 6]
// 0056fe1f  8bc8                 mov ecx, eax
// 0056fe21  c1e908               shr ecx, 8
// 0056fe24  884c2422             mov byte ptr [esp + 0x22], cl
// 0056fe28  88442423             mov byte ptr [esp + 0x23], al
// 0056fe2c  0fb74608             movzx eax, word ptr [esi + 8]
// 0056fe30  8bd0                 mov edx, eax
// 0056fe32  c1ea08               shr edx, 8
// 0056fe35  88542424             mov byte ptr [esp + 0x24], dl
// 0056fe39  88442425             mov byte ptr [esp + 0x25], al
// 0056fe3d  85ff                 test edi, edi
// 0056fe3f  7423                 je 0x56fe64
// 0056fe41  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0056fe45  85db                 test ebx, ebx
// 0056fe47  761b                 jbe 0x56fe64
// 0056fe49  53                   push ebx
// 0056fe4a  8d442420             lea eax, [esp + 0x20]
// 0056fe4e  50                   push eax
// 0056fe4f  57                   push edi
// 0056fe50  e8ab4effff           call 0x564d00
// 0056fe55  53                   push ebx
// 0056fe56  8d4c242c             lea ecx, [esp + 0x2c]
// 0056fe5a  51                   push ecx
// 0056fe5b  57                   push edi
// 0056fe5c  e87f51ffff           call 0x564fe0
// 0056fe61  83c418               add esp, 0x18
// 0056fe64  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0056fe67  8d1480               lea edx, [eax + eax*4]
// 0056fe6a  8b4508               mov eax, dword ptr [ebp + 8]
// 0056fe6d  83c60a               add esi, 0xa
// 0056fe70  8d0c50               lea ecx, [eax + edx*2]
// 0056fe73  3bf1                 cmp esi, ecx
// 0056fe75  0f8238ffffff         jb 0x56fdb3
// 0056fe7b  85ff                 test edi, edi
// 0056fe7d  7435                 je 0x56feb4
// 0056fe7f  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0056fe85  8bd0                 mov edx, eax
// 0056fe87  c1ea18               shr edx, 0x18
// 0056fe8a  88542430             mov byte ptr [esp + 0x30], dl
// 0056fe8e  8bc8                 mov ecx, eax
// 0056fe90  8bd0                 mov edx, eax
// 0056fe92  88442433             mov byte ptr [esp + 0x33], al
// 0056fe96  6a04                 push 4
// 0056fe98  8d442434             lea eax, [esp + 0x34]
// 0056fe9c  50                   push eax
// 0056fe9d  c1e910               shr ecx, 0x10
// 0056fea0  c1ea08               shr edx, 8
// 0056fea3  57                   push edi
// 0056fea4  884c243d             mov byte ptr [esp + 0x3d], cl
// 0056fea8  8854243e             mov byte ptr [esp + 0x3e], dl
// 0056feac  e84f4effff           call 0x564d00
// 0056feb1  83c40c               add esp, 0xc
// 0056feb4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056feb8  51                   push ecx
// 0056feb9  57                   push edi
// 0056feba  e841270000           call 0x572600
// 0056febf  83c408               add esp, 8
// 0056fec2  5f                   pop edi
// 0056fec3  5e                   pop esi
// 0056fec4  5d                   pop ebp
// 0056fec5  5b                   pop ebx
// 0056fec6  83c418               add esp, 0x18
// 0056fec9  c3                   ret 
// 0056feca  68643ca200           push 0xa23c64
// 0056fecf  57                   push edi
// 0056fed0  e88b1c0000           call 0x571b60
// 0056fed5  83c408               add esp, 8
// 0056fed8  5f                   pop edi
// 0056fed9  5e                   pop esi
// 0056feda  5d                   pop ebp
// 0056fedb  5b                   pop ebx
// 0056fedc  83c418               add esp, 0x18
// 0056fedf  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
