// from server: 100% by auto
// roc 2011-06 0056bfe0  unit: seg_00560000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056bfe0
//
// 0056bfe0  83ec08               sub esp, 8
// 0056bfe3  55                   push ebp
// 0056bfe4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0056bfe8  57                   push edi
// 0056bfe9  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056bfed  f6476804             test byte ptr [edi + 0x68], 4
// 0056bff1  c644240849           mov byte ptr [esp + 8], 0x49
// 0056bff6  c644240944           mov byte ptr [esp + 9], 0x44
// 0056bffb  c644240a41           mov byte ptr [esp + 0xa], 0x41
// 0056c000  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0056c005  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056c00a  0f85df000000         jne 0x56c0ef
// 0056c010  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 0056c017  0f85d2000000         jne 0x56c0ef
// 0056c01d  56                   push esi
// 0056c01e  0fb67500             movzx esi, byte ptr [ebp]
// 0056c022  8bc6                 mov eax, esi
// 0056c024  240f                 and al, 0xf
// 0056c026  3c08                 cmp al, 8
// 0056c028  0f85b2000000         jne 0x56c0e0
// 0056c02e  8bce                 mov ecx, esi
// 0056c030  81e1f0000000         and ecx, 0xf0
// 0056c036  83f970               cmp ecx, 0x70
// 0056c039  0f87a1000000         ja 0x56c0e0
// 0056c03f  837c242002           cmp dword ptr [esp + 0x20], 2
// 0056c044  0f82a4000000         jb 0x56c0ee
// 0056c04a  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 0056c050  81fa00400000         cmp edx, 0x4000
// 0056c056  0f8392000000         jae 0x56c0ee
// 0056c05c  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 0056c062  81f900400000         cmp ecx, 0x4000
// 0056c068  0f8380000000         jae 0x56c0ee
// 0056c06e  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 0056c075  53                   push ebx
// 0056c076  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 0056c07d  0fafc3               imul eax, ebx
// 0056c080  0fafc1               imul eax, ecx
// 0056c083  83c00f               add eax, 0xf
// 0056c086  c1e803               shr eax, 3
// 0056c089  0fafc2               imul eax, edx
// 0056c08c  c1ee04               shr esi, 4
// 0056c08f  8d4e07               lea ecx, [esi + 7]
// 0056c092  ba01000000           mov edx, 1
// 0056c097  d3e2                 shl edx, cl
// 0056c099  5b                   pop ebx
// 0056c09a  3bc2                 cmp eax, edx
// 0056c09c  7711                 ja 0x56c0af
// 0056c09e  8bff                 mov edi, edi
// 0056c0a0  81fa00010000         cmp edx, 0x100
// 0056c0a6  7207                 jb 0x56c0af
// 0056c0a8  d1ea                 shr edx, 1
// 0056c0aa  4e                   dec esi
// 0056c0ab  3bc2                 cmp eax, edx
// 0056c0ad  76f1                 jbe 0x56c0a0
// 0056c0af  c1e604               shl esi, 4
// 0056c0b2  83ce08               or esi, 8
// 0056c0b5  8bc6                 mov eax, esi
// 0056c0b7  384500               cmp byte ptr [ebp], al
// 0056c0ba  7432                 je 0x56c0ee
// 0056c0bc  8a4d01               mov cl, byte ptr [ebp + 1]
// 0056c0bf  80e1e0               and cl, 0xe0
// 0056c0c2  0fb6d1               movzx edx, cl
// 0056c0c5  884500               mov byte ptr [ebp], al
// 0056c0c8  c1e008               shl eax, 8
// 0056c0cb  03c2                 add eax, edx
// 0056c0cd  33d2                 xor edx, edx
// 0056c0cf  be1f000000           mov esi, 0x1f
// 0056c0d4  f7f6                 div esi
// 0056c0d6  2aca                 sub cl, dl
// 0056c0d8  80c11f               add cl, 0x1f
// 0056c0db  884d01               mov byte ptr [ebp + 1], cl
// 0056c0de  eb0e                 jmp 0x56c0ee
// 0056c0e0  68e45ea800           push 0xa85ee4
// 0056c0e5  57                   push edi
// 0056c0e6  e84552ffff           call 0x561330
// 0056c0eb  83c408               add esp, 8
// 0056c0ee  5e                   pop esi
// 0056c0ef  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056c0f3  50                   push eax
// 0056c0f4  55                   push ebp
// 0056c0f5  8d4c2410             lea ecx, [esp + 0x10]
// 0056c0f9  51                   push ecx
// 0056c0fa  57                   push edi
// 0056c0fb  e810faffff           call 0x56bb10
// 0056c100  83c410               add esp, 0x10
// 0056c103  834f6804             or dword ptr [edi + 0x68], 4
// 0056c107  5f                   pop edi
// 0056c108  5d                   pop ebp
// 0056c109  83c408               add esp, 8
// 0056c10c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
