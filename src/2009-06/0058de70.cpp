// from server: 100% by auto
// roc 2009-06 0058de70  unit: seg_00580000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058de70
//
// 0058de70  53                   push ebx
// 0058de71  55                   push ebp
// 0058de72  56                   push esi
// 0058de73  57                   push edi
// 0058de74  8bf8                 mov edi, eax
// 0058de76  33c0                 xor eax, eax
// 0058de78  8bf1                 mov esi, ecx
// 0058de7a  33ed                 xor ebp, ebp
// 0058de7c  8d642400             lea esp, [esp]
// 0058de80  0fb68c2e1c010000     movzx ecx, byte ptr [esi + ebp + 0x11c]
// 0058de88  8d59bf               lea ebx, [ecx - 0x41]
// 0058de8b  45                   inc ebp
// 0058de8c  83fb39               cmp ebx, 0x39
// 0058de8f  770f                 ja 0x58dea0
// 0058de91  83f95a               cmp ecx, 0x5a
// 0058de94  7e05                 jle 0x58de9b
// 0058de96  83f961               cmp ecx, 0x61
// 0058de99  7c05                 jl 0x58dea0
// 0058de9b  880c38               mov byte ptr [eax + edi], cl
// 0058de9e  eb28                 jmp 0x58dec8
// 0058dea0  c604385b             mov byte ptr [eax + edi], 0x5b
// 0058dea4  8bd9                 mov ebx, ecx
// 0058dea6  c1fb04               sar ebx, 4
// 0058dea9  83e30f               and ebx, 0xf
// 0058deac  8a9b44f38c00         mov bl, byte ptr [ebx + 0x8cf344]
// 0058deb2  40                   inc eax
// 0058deb3  881c38               mov byte ptr [eax + edi], bl
// 0058deb6  83e10f               and ecx, 0xf
// 0058deb9  8a8944f38c00         mov cl, byte ptr [ecx + 0x8cf344]
// 0058debf  40                   inc eax
// 0058dec0  880c38               mov byte ptr [eax + edi], cl
// 0058dec3  40                   inc eax
// 0058dec4  c604385d             mov byte ptr [eax + edi], 0x5d
// 0058dec8  40                   inc eax
// 0058dec9  83fd04               cmp ebp, 4
// 0058decc  7cb2                 jl 0x58de80
// 0058dece  85d2                 test edx, edx
// 0058ded0  7508                 jne 0x58deda
// 0058ded2  881438               mov byte ptr [eax + edi], dl
// 0058ded5  5f                   pop edi
// 0058ded6  5e                   pop esi
// 0058ded7  5d                   pop ebp
// 0058ded8  5b                   pop ebx
// 0058ded9  c3                   ret 
// 0058deda  c604383a             mov byte ptr [eax + edi], 0x3a
// 0058dede  c644380120           mov byte ptr [eax + edi + 1], 0x20
// 0058dee3  40                   inc eax
// 0058dee4  40                   inc eax
// 0058dee5  03c7                 add eax, edi
// 0058dee7  b910000000           mov ecx, 0x10
// 0058deec  8bf2                 mov esi, edx
// 0058deee  8bf8                 mov edi, eax
// 0058def0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0058def2  5f                   pop edi
// 0058def3  5e                   pop esi
// 0058def4  5d                   pop ebp
// 0058def5  c6403f00             mov byte ptr [eax + 0x3f], 0
// 0058def9  5b                   pop ebx
// 0058defa  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_format_buffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
