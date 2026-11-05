// from server: 100% by auto
// roc 2010-06 0056f860  unit: G3D::LineSegment  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056f860
//
// 0056f860  83ec08               sub esp, 8
// 0056f863  55                   push ebp
// 0056f864  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056f868  57                   push edi
// 0056f869  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056f86d  f6476804             test byte ptr [edi + 0x68], 4
// 0056f871  c644240849           mov byte ptr [esp + 8], 0x49
// 0056f876  c644240944           mov byte ptr [esp + 9], 0x44
// 0056f87b  c644240a41           mov byte ptr [esp + 0xa], 0x41
// 0056f880  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0056f885  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056f88a  0f85df000000         jne 0x56f96f
// 0056f890  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 0056f897  0f85d2000000         jne 0x56f96f
// 0056f89d  56                   push esi
// 0056f89e  0fb67500             movzx esi, byte ptr [ebp]
// 0056f8a2  8bc6                 mov eax, esi
// 0056f8a4  240f                 and al, 0xf
// 0056f8a6  3c08                 cmp al, 8
// 0056f8a8  0f85b2000000         jne 0x56f960
// 0056f8ae  8bce                 mov ecx, esi
// 0056f8b0  81e1f0000000         and ecx, 0xf0
// 0056f8b6  83f970               cmp ecx, 0x70
// 0056f8b9  0f87a1000000         ja 0x56f960
// 0056f8bf  837c242002           cmp dword ptr [esp + 0x20], 2
// 0056f8c4  0f82a4000000         jb 0x56f96e
// 0056f8ca  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 0056f8d0  81fa00400000         cmp edx, 0x4000
// 0056f8d6  0f8392000000         jae 0x56f96e
// 0056f8dc  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 0056f8e2  81f900400000         cmp ecx, 0x4000
// 0056f8e8  0f8380000000         jae 0x56f96e
// 0056f8ee  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 0056f8f5  53                   push ebx
// 0056f8f6  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 0056f8fd  0fafc3               imul eax, ebx
// 0056f900  0fafc1               imul eax, ecx
// 0056f903  83c00f               add eax, 0xf
// 0056f906  c1e803               shr eax, 3
// 0056f909  0fafc2               imul eax, edx
// 0056f90c  c1ee04               shr esi, 4
// 0056f90f  8d4e07               lea ecx, [esi + 7]
// 0056f912  ba01000000           mov edx, 1
// 0056f917  d3e2                 shl edx, cl
// 0056f919  5b                   pop ebx
// 0056f91a  3bc2                 cmp eax, edx
// 0056f91c  7711                 ja 0x56f92f
// 0056f91e  8bff                 mov edi, edi
// 0056f920  81fa00010000         cmp edx, 0x100
// 0056f926  7207                 jb 0x56f92f
// 0056f928  d1ea                 shr edx, 1
// 0056f92a  4e                   dec esi
// 0056f92b  3bc2                 cmp eax, edx
// 0056f92d  76f1                 jbe 0x56f920
// 0056f92f  c1e604               shl esi, 4
// 0056f932  83ce08               or esi, 8
// 0056f935  8bc6                 mov eax, esi
// 0056f937  384500               cmp byte ptr [ebp], al
// 0056f93a  7432                 je 0x56f96e
// 0056f93c  8a4d01               mov cl, byte ptr [ebp + 1]
// 0056f93f  80e1e0               and cl, 0xe0
// 0056f942  0fb6d1               movzx edx, cl
// 0056f945  884500               mov byte ptr [ebp], al
// 0056f948  c1e008               shl eax, 8
// 0056f94b  03c2                 add eax, edx
// 0056f94d  33d2                 xor edx, edx
// 0056f94f  be1f000000           mov esi, 0x1f
// 0056f954  f7f6                 div esi
// 0056f956  2aca                 sub cl, dl
// 0056f958  80c11f               add cl, 0x1f
// 0056f95b  884d01               mov byte ptr [ebp + 1], cl
// 0056f95e  eb0e                 jmp 0x56f96e
// 0056f960  68603ba200           push 0xa23b60
// 0056f965  57                   push edi
// 0056f966  e845210000           call 0x571ab0
// 0056f96b  83c408               add esp, 8
// 0056f96e  5e                   pop esi
// 0056f96f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056f973  50                   push eax
// 0056f974  55                   push ebp
// 0056f975  8d4c2410             lea ecx, [esp + 0x10]
// 0056f979  51                   push ecx
// 0056f97a  57                   push edi
// 0056f97b  e810faffff           call 0x56f390
// 0056f980  83c410               add esp, 0x10
// 0056f983  834f6804             or dword ptr [edi + 0x68], 4
// 0056f987  5f                   pop edi
// 0056f988  5d                   pop ebp
// 0056f989  83c408               add esp, 8
// 0056f98c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
