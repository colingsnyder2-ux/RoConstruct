// from server: 100% by auto
// roc 2012-06 006576f0  unit: seg_00650000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006576f0
//
// 006576f0  83ec08               sub esp, 8
// 006576f3  55                   push ebp
// 006576f4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 006576f8  57                   push edi
// 006576f9  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006576fd  f6476804             test byte ptr [edi + 0x68], 4
// 00657701  c644240849           mov byte ptr [esp + 8], 0x49
// 00657706  c644240944           mov byte ptr [esp + 9], 0x44
// 0065770b  c644240a41           mov byte ptr [esp + 0xa], 0x41
// 00657710  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 00657715  c644240c00           mov byte ptr [esp + 0xc], 0
// 0065771a  0f85df000000         jne 0x6577ff
// 00657720  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 00657727  0f85d2000000         jne 0x6577ff
// 0065772d  56                   push esi
// 0065772e  0fb67500             movzx esi, byte ptr [ebp]
// 00657732  8bc6                 mov eax, esi
// 00657734  240f                 and al, 0xf
// 00657736  3c08                 cmp al, 8
// 00657738  0f85b2000000         jne 0x6577f0
// 0065773e  8bce                 mov ecx, esi
// 00657740  81e1f0000000         and ecx, 0xf0
// 00657746  83f970               cmp ecx, 0x70
// 00657749  0f87a1000000         ja 0x6577f0
// 0065774f  837c242002           cmp dword ptr [esp + 0x20], 2
// 00657754  0f82a4000000         jb 0x6577fe
// 0065775a  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 00657760  81fa00400000         cmp edx, 0x4000
// 00657766  0f8392000000         jae 0x6577fe
// 0065776c  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 00657772  81f900400000         cmp ecx, 0x4000
// 00657778  0f8380000000         jae 0x6577fe
// 0065777e  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 00657785  53                   push ebx
// 00657786  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 0065778d  0fafc3               imul eax, ebx
// 00657790  0fafc1               imul eax, ecx
// 00657793  83c00f               add eax, 0xf
// 00657796  c1e803               shr eax, 3
// 00657799  0fafc2               imul eax, edx
// 0065779c  c1ee04               shr esi, 4
// 0065779f  8d4e07               lea ecx, [esi + 7]
// 006577a2  ba01000000           mov edx, 1
// 006577a7  d3e2                 shl edx, cl
// 006577a9  5b                   pop ebx
// 006577aa  3bc2                 cmp eax, edx
// 006577ac  7711                 ja 0x6577bf
// 006577ae  8bff                 mov edi, edi
// 006577b0  81fa00010000         cmp edx, 0x100
// 006577b6  7207                 jb 0x6577bf
// 006577b8  d1ea                 shr edx, 1
// 006577ba  4e                   dec esi
// 006577bb  3bc2                 cmp eax, edx
// 006577bd  76f1                 jbe 0x6577b0
// 006577bf  c1e604               shl esi, 4
// 006577c2  83ce08               or esi, 8
// 006577c5  8bc6                 mov eax, esi
// 006577c7  384500               cmp byte ptr [ebp], al
// 006577ca  7432                 je 0x6577fe
// 006577cc  8a4d01               mov cl, byte ptr [ebp + 1]
// 006577cf  80e1e0               and cl, 0xe0
// 006577d2  0fb6d1               movzx edx, cl
// 006577d5  884500               mov byte ptr [ebp], al
// 006577d8  c1e008               shl eax, 8
// 006577db  03c2                 add eax, edx
// 006577dd  33d2                 xor edx, edx
// 006577df  be1f000000           mov esi, 0x1f
// 006577e4  f7f6                 div esi
// 006577e6  2aca                 sub cl, dl
// 006577e8  80c11f               add cl, 0x1f
// 006577eb  884d01               mov byte ptr [ebp + 1], cl
// 006577ee  eb0e                 jmp 0x6577fe
// 006577f0  68349db800           push 0xb89d34
// 006577f5  57                   push edi
// 006577f6  e8b569ffff           call 0x64e1b0
// 006577fb  83c408               add esp, 8
// 006577fe  5e                   pop esi
// 006577ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00657803  50                   push eax
// 00657804  55                   push ebp
// 00657805  8d4c2410             lea ecx, [esp + 0x10]
// 00657809  51                   push ecx
// 0065780a  57                   push edi
// 0065780b  e810faffff           call 0x657220
// 00657810  83c410               add esp, 0x10
// 00657813  834f6804             or dword ptr [edi + 0x68], 4
// 00657817  5f                   pop edi
// 00657818  5d                   pop ebp
// 00657819  83c408               add esp, 8
// 0065781c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
