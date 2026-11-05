// from server: 100% by auto
// roc 2010-06 005717c0  unit: G3D::LineSegment  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005717c0
//
// 005717c0  53                   push ebx
// 005717c1  55                   push ebp
// 005717c2  56                   push esi
// 005717c3  57                   push edi
// 005717c4  8bf8                 mov edi, eax
// 005717c6  33c0                 xor eax, eax
// 005717c8  8bf1                 mov esi, ecx
// 005717ca  33ed                 xor ebp, ebp
// 005717cc  8d642400             lea esp, [esp]
// 005717d0  0fb68c2e1c010000     movzx ecx, byte ptr [esi + ebp + 0x11c]
// 005717d8  8d59bf               lea ebx, [ecx - 0x41]
// 005717db  45                   inc ebp
// 005717dc  83fb39               cmp ebx, 0x39
// 005717df  770f                 ja 0x5717f0
// 005717e1  83f95a               cmp ecx, 0x5a
// 005717e4  7e05                 jle 0x5717eb
// 005717e6  83f961               cmp ecx, 0x61
// 005717e9  7c05                 jl 0x5717f0
// 005717eb  880c38               mov byte ptr [eax + edi], cl
// 005717ee  eb28                 jmp 0x571818
// 005717f0  c604385b             mov byte ptr [eax + edi], 0x5b
// 005717f4  8bd9                 mov ebx, ecx
// 005717f6  c1fb04               sar ebx, 4
// 005717f9  83e30f               and ebx, 0xf
// 005717fc  8a9b4c3fa200         mov bl, byte ptr [ebx + 0xa23f4c]
// 00571802  40                   inc eax
// 00571803  881c38               mov byte ptr [eax + edi], bl
// 00571806  83e10f               and ecx, 0xf
// 00571809  8a894c3fa200         mov cl, byte ptr [ecx + 0xa23f4c]
// 0057180f  40                   inc eax
// 00571810  880c38               mov byte ptr [eax + edi], cl
// 00571813  40                   inc eax
// 00571814  c604385d             mov byte ptr [eax + edi], 0x5d
// 00571818  40                   inc eax
// 00571819  83fd04               cmp ebp, 4
// 0057181c  7cb2                 jl 0x5717d0
// 0057181e  85d2                 test edx, edx
// 00571820  7508                 jne 0x57182a
// 00571822  881438               mov byte ptr [eax + edi], dl
// 00571825  5f                   pop edi
// 00571826  5e                   pop esi
// 00571827  5d                   pop ebp
// 00571828  5b                   pop ebx
// 00571829  c3                   ret 
// 0057182a  c604383a             mov byte ptr [eax + edi], 0x3a
// 0057182e  c644380120           mov byte ptr [eax + edi + 1], 0x20
// 00571833  40                   inc eax
// 00571834  40                   inc eax
// 00571835  03c7                 add eax, edi
// 00571837  b910000000           mov ecx, 0x10
// 0057183c  8bf2                 mov esi, edx
// 0057183e  8bf8                 mov edi, eax
// 00571840  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00571842  5f                   pop edi
// 00571843  5e                   pop esi
// 00571844  5d                   pop ebp
// 00571845  c6403f00             mov byte ptr [eax + 0x3f], 0
// 00571849  5b                   pop ebx
// 0057184a  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_format_buffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
