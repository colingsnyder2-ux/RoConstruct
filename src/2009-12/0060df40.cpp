// from server: 100% by auto
// roc 2009-12 0060df40  unit: seg_00600000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060df40
//
// 0060df40  83ec08               sub esp, 8
// 0060df43  55                   push ebp
// 0060df44  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0060df48  57                   push edi
// 0060df49  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0060df4d  f6476804             test byte ptr [edi + 0x68], 4
// 0060df51  c644240849           mov byte ptr [esp + 8], 0x49
// 0060df56  c644240944           mov byte ptr [esp + 9], 0x44
// 0060df5b  c644240a41           mov byte ptr [esp + 0xa], 0x41
// 0060df60  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0060df65  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060df6a  0f85df000000         jne 0x60e04f
// 0060df70  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 0060df77  0f85d2000000         jne 0x60e04f
// 0060df7d  56                   push esi
// 0060df7e  0fb67500             movzx esi, byte ptr [ebp]
// 0060df82  8bc6                 mov eax, esi
// 0060df84  240f                 and al, 0xf
// 0060df86  3c08                 cmp al, 8
// 0060df88  0f85b2000000         jne 0x60e040
// 0060df8e  8bce                 mov ecx, esi
// 0060df90  81e1f0000000         and ecx, 0xf0
// 0060df96  83f970               cmp ecx, 0x70
// 0060df99  0f87a1000000         ja 0x60e040
// 0060df9f  837c242002           cmp dword ptr [esp + 0x20], 2
// 0060dfa4  0f82a4000000         jb 0x60e04e
// 0060dfaa  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 0060dfb0  81fa00400000         cmp edx, 0x4000
// 0060dfb6  0f8392000000         jae 0x60e04e
// 0060dfbc  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 0060dfc2  81f900400000         cmp ecx, 0x4000
// 0060dfc8  0f8380000000         jae 0x60e04e
// 0060dfce  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 0060dfd5  53                   push ebx
// 0060dfd6  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 0060dfdd  0fafc3               imul eax, ebx
// 0060dfe0  0fafc1               imul eax, ecx
// 0060dfe3  83c00f               add eax, 0xf
// 0060dfe6  c1e803               shr eax, 3
// 0060dfe9  0fafc2               imul eax, edx
// 0060dfec  c1ee04               shr esi, 4
// 0060dfef  8d4e07               lea ecx, [esi + 7]
// 0060dff2  ba01000000           mov edx, 1
// 0060dff7  d3e2                 shl edx, cl
// 0060dff9  5b                   pop ebx
// 0060dffa  3bc2                 cmp eax, edx
// 0060dffc  7711                 ja 0x60e00f
// 0060dffe  8bff                 mov edi, edi
// 0060e000  81fa00010000         cmp edx, 0x100
// 0060e006  7207                 jb 0x60e00f
// 0060e008  d1ea                 shr edx, 1
// 0060e00a  4e                   dec esi
// 0060e00b  3bc2                 cmp eax, edx
// 0060e00d  76f1                 jbe 0x60e000
// 0060e00f  c1e604               shl esi, 4
// 0060e012  83ce08               or esi, 8
// 0060e015  8bc6                 mov eax, esi
// 0060e017  384500               cmp byte ptr [ebp], al
// 0060e01a  7432                 je 0x60e04e
// 0060e01c  8a4d01               mov cl, byte ptr [ebp + 1]
// 0060e01f  80e1e0               and cl, 0xe0
// 0060e022  0fb6d1               movzx edx, cl
// 0060e025  884500               mov byte ptr [ebp], al
// 0060e028  c1e008               shl eax, 8
// 0060e02b  03c2                 add eax, edx
// 0060e02d  33d2                 xor edx, edx
// 0060e02f  be1f000000           mov esi, 0x1f
// 0060e034  f7f6                 div esi
// 0060e036  2aca                 sub cl, dl
// 0060e038  80c11f               add cl, 0x1f
// 0060e03b  884d01               mov byte ptr [ebp + 1], cl
// 0060e03e  eb0e                 jmp 0x60e04e
// 0060e040  68ec5d9c00           push 0x9c5dec
// 0060e045  57                   push edi
// 0060e046  e845210000           call 0x610190
// 0060e04b  83c408               add esp, 8
// 0060e04e  5e                   pop esi
// 0060e04f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060e053  50                   push eax
// 0060e054  55                   push ebp
// 0060e055  8d4c2410             lea ecx, [esp + 0x10]
// 0060e059  51                   push ecx
// 0060e05a  57                   push edi
// 0060e05b  e810faffff           call 0x60da70
// 0060e060  83c410               add esp, 0x10
// 0060e063  834f6804             or dword ptr [edi + 0x68], 4
// 0060e067  5f                   pop edi
// 0060e068  5d                   pop ebp
// 0060e069  83c408               add esp, 8
// 0060e06c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
