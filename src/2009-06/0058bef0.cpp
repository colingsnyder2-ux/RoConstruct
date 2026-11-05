// from server: 100% by auto
// roc 2009-06 0058bef0  unit: seg_00580000  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058bef0
//
// 0058bef0  83ec08               sub esp, 8
// 0058bef3  55                   push ebp
// 0058bef4  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0058bef8  57                   push edi
// 0058bef9  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0058befd  f6476804             test byte ptr [edi + 0x68], 4
// 0058bf01  c644240849           mov byte ptr [esp + 8], 0x49
// 0058bf06  c644240944           mov byte ptr [esp + 9], 0x44
// 0058bf0b  c644240a41           mov byte ptr [esp + 0xa], 0x41
// 0058bf10  c644240b54           mov byte ptr [esp + 0xb], 0x54
// 0058bf15  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058bf1a  0f85df000000         jne 0x58bfff
// 0058bf20  80bf6002000000       cmp byte ptr [edi + 0x260], 0
// 0058bf27  0f85d2000000         jne 0x58bfff
// 0058bf2d  56                   push esi
// 0058bf2e  0fb67500             movzx esi, byte ptr [ebp]
// 0058bf32  8bc6                 mov eax, esi
// 0058bf34  240f                 and al, 0xf
// 0058bf36  3c08                 cmp al, 8
// 0058bf38  0f85b2000000         jne 0x58bff0
// 0058bf3e  8bce                 mov ecx, esi
// 0058bf40  81e1f0000000         and ecx, 0xf0
// 0058bf46  83f970               cmp ecx, 0x70
// 0058bf49  0f87a1000000         ja 0x58bff0
// 0058bf4f  837c242002           cmp dword ptr [esp + 0x20], 2
// 0058bf54  0f82a4000000         jb 0x58bffe
// 0058bf5a  8b97cc000000         mov edx, dword ptr [edi + 0xcc]
// 0058bf60  81fa00400000         cmp edx, 0x4000
// 0058bf66  0f8392000000         jae 0x58bffe
// 0058bf6c  8b8fc8000000         mov ecx, dword ptr [edi + 0xc8]
// 0058bf72  81f900400000         cmp ecx, 0x4000
// 0058bf78  0f8380000000         jae 0x58bffe
// 0058bf7e  0fb6872a010000       movzx eax, byte ptr [edi + 0x12a]
// 0058bf85  53                   push ebx
// 0058bf86  0fb69f27010000       movzx ebx, byte ptr [edi + 0x127]
// 0058bf8d  0fafc3               imul eax, ebx
// 0058bf90  0fafc1               imul eax, ecx
// 0058bf93  83c00f               add eax, 0xf
// 0058bf96  c1e803               shr eax, 3
// 0058bf99  0fafc2               imul eax, edx
// 0058bf9c  c1ee04               shr esi, 4
// 0058bf9f  8d4e07               lea ecx, [esi + 7]
// 0058bfa2  ba01000000           mov edx, 1
// 0058bfa7  d3e2                 shl edx, cl
// 0058bfa9  5b                   pop ebx
// 0058bfaa  3bc2                 cmp eax, edx
// 0058bfac  7711                 ja 0x58bfbf
// 0058bfae  8bff                 mov edi, edi
// 0058bfb0  81fa00010000         cmp edx, 0x100
// 0058bfb6  7207                 jb 0x58bfbf
// 0058bfb8  d1ea                 shr edx, 1
// 0058bfba  4e                   dec esi
// 0058bfbb  3bc2                 cmp eax, edx
// 0058bfbd  76f1                 jbe 0x58bfb0
// 0058bfbf  c1e604               shl esi, 4
// 0058bfc2  83ce08               or esi, 8
// 0058bfc5  8bc6                 mov eax, esi
// 0058bfc7  384500               cmp byte ptr [ebp], al
// 0058bfca  7432                 je 0x58bffe
// 0058bfcc  8a4d01               mov cl, byte ptr [ebp + 1]
// 0058bfcf  80e1e0               and cl, 0xe0
// 0058bfd2  0fb6d1               movzx edx, cl
// 0058bfd5  884500               mov byte ptr [ebp], al
// 0058bfd8  c1e008               shl eax, 8
// 0058bfdb  03c2                 add eax, edx
// 0058bfdd  33d2                 xor edx, edx
// 0058bfdf  be1f000000           mov esi, 0x1f
// 0058bfe4  f7f6                 div esi
// 0058bfe6  2aca                 sub cl, dl
// 0058bfe8  80c11f               add cl, 0x1f
// 0058bfeb  884d01               mov byte ptr [ebp + 1], cl
// 0058bfee  eb0e                 jmp 0x58bffe
// 0058bff0  6854ef8c00           push 0x8cef54
// 0058bff5  57                   push edi
// 0058bff6  e865210000           call 0x58e160
// 0058bffb  83c408               add esp, 8
// 0058bffe  5e                   pop esi
// 0058bfff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0058c003  50                   push eax
// 0058c004  55                   push ebp
// 0058c005  8d4c2410             lea ecx, [esp + 0x10]
// 0058c009  51                   push ecx
// 0058c00a  57                   push edi
// 0058c00b  e810faffff           call 0x58ba20
// 0058c010  83c410               add esp, 0x10
// 0058c013  834f6804             or dword ptr [edi + 0x68], 4
// 0058c017  5f                   pop edi
// 0058c018  5d                   pop ebp
// 0058c019  83c408               add esp, 8
// 0058c01c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IDAT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
