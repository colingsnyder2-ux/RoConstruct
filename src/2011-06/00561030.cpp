// from server: 100% by auto
// roc 2011-06 00561030  unit: seg_00560000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00561030
//
// 00561030  53                   push ebx
// 00561031  55                   push ebp
// 00561032  56                   push esi
// 00561033  57                   push edi
// 00561034  8bf8                 mov edi, eax
// 00561036  33c0                 xor eax, eax
// 00561038  8bf1                 mov esi, ecx
// 0056103a  33ed                 xor ebp, ebp
// 0056103c  8d642400             lea esp, [esp]
// 00561040  0fb68c2e1c010000     movzx ecx, byte ptr [esi + ebp + 0x11c]
// 00561048  8d59bf               lea ebx, [ecx - 0x41]
// 0056104b  45                   inc ebp
// 0056104c  83fb39               cmp ebx, 0x39
// 0056104f  770f                 ja 0x561060
// 00561051  83f95a               cmp ecx, 0x5a
// 00561054  7e05                 jle 0x56105b
// 00561056  83f961               cmp ecx, 0x61
// 00561059  7c05                 jl 0x561060
// 0056105b  880c38               mov byte ptr [eax + edi], cl
// 0056105e  eb28                 jmp 0x561088
// 00561060  c604385b             mov byte ptr [eax + edi], 0x5b
// 00561064  8bd9                 mov ebx, ecx
// 00561066  c1fb04               sar ebx, 4
// 00561069  83e30f               and ebx, 0xf
// 0056106c  8a9bcc2ca800         mov bl, byte ptr [ebx + 0xa82ccc]
// 00561072  40                   inc eax
// 00561073  881c38               mov byte ptr [eax + edi], bl
// 00561076  83e10f               and ecx, 0xf
// 00561079  8a89cc2ca800         mov cl, byte ptr [ecx + 0xa82ccc]
// 0056107f  40                   inc eax
// 00561080  880c38               mov byte ptr [eax + edi], cl
// 00561083  40                   inc eax
// 00561084  c604385d             mov byte ptr [eax + edi], 0x5d
// 00561088  40                   inc eax
// 00561089  83fd04               cmp ebp, 4
// 0056108c  7cb2                 jl 0x561040
// 0056108e  85d2                 test edx, edx
// 00561090  7508                 jne 0x56109a
// 00561092  881438               mov byte ptr [eax + edi], dl
// 00561095  5f                   pop edi
// 00561096  5e                   pop esi
// 00561097  5d                   pop ebp
// 00561098  5b                   pop ebx
// 00561099  c3                   ret 
// 0056109a  c604383a             mov byte ptr [eax + edi], 0x3a
// 0056109e  c644380120           mov byte ptr [eax + edi + 1], 0x20
// 005610a3  40                   inc eax
// 005610a4  40                   inc eax
// 005610a5  03c7                 add eax, edi
// 005610a7  b910000000           mov ecx, 0x10
// 005610ac  8bf2                 mov esi, edx
// 005610ae  8bf8                 mov edi, eax
// 005610b0  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005610b2  5f                   pop edi
// 005610b3  5e                   pop esi
// 005610b4  5d                   pop ebp
// 005610b5  c6403f00             mov byte ptr [eax + 0x3f], 0
// 005610b9  5b                   pop ebx
// 005610ba  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_format_buffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
