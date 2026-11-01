// from server: 100% by auto
// roc 2009-12 0060fea0  unit: seg_00600000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060fea0
//
// 0060fea0  53                   push ebx
// 0060fea1  55                   push ebp
// 0060fea2  56                   push esi
// 0060fea3  57                   push edi
// 0060fea4  8bf8                 mov edi, eax
// 0060fea6  33c0                 xor eax, eax
// 0060fea8  8bf1                 mov esi, ecx
// 0060feaa  33ed                 xor ebp, ebp
// 0060feac  8d642400             lea esp, [esp]
// 0060feb0  0fb68c2e1c010000     movzx ecx, byte ptr [esi + ebp + 0x11c]
// 0060feb8  8d59bf               lea ebx, [ecx - 0x41]
// 0060febb  45                   inc ebp
// 0060febc  83fb39               cmp ebx, 0x39
// 0060febf  770f                 ja 0x60fed0
// 0060fec1  83f95a               cmp ecx, 0x5a
// 0060fec4  7e05                 jle 0x60fecb
// 0060fec6  83f961               cmp ecx, 0x61
// 0060fec9  7c05                 jl 0x60fed0
// 0060fecb  880c38               mov byte ptr [eax + edi], cl
// 0060fece  eb28                 jmp 0x60fef8
// 0060fed0  c604385b             mov byte ptr [eax + edi], 0x5b
// 0060fed4  8bd9                 mov ebx, ecx
// 0060fed6  c1fb04               sar ebx, 4
// 0060fed9  83e30f               and ebx, 0xf
// 0060fedc  8a9bd4619c00         mov bl, byte ptr [ebx + 0x9c61d4]
// 0060fee2  40                   inc eax
// 0060fee3  881c38               mov byte ptr [eax + edi], bl
// 0060fee6  83e10f               and ecx, 0xf
// 0060fee9  8a89d4619c00         mov cl, byte ptr [ecx + 0x9c61d4]
// 0060feef  40                   inc eax
// 0060fef0  880c38               mov byte ptr [eax + edi], cl
// 0060fef3  40                   inc eax
// 0060fef4  c604385d             mov byte ptr [eax + edi], 0x5d
// 0060fef8  40                   inc eax
// 0060fef9  83fd04               cmp ebp, 4
// 0060fefc  7cb2                 jl 0x60feb0
// 0060fefe  85d2                 test edx, edx
// 0060ff00  7508                 jne 0x60ff0a
// 0060ff02  881438               mov byte ptr [eax + edi], dl
// 0060ff05  5f                   pop edi
// 0060ff06  5e                   pop esi
// 0060ff07  5d                   pop ebp
// 0060ff08  5b                   pop ebx
// 0060ff09  c3                   ret 
// 0060ff0a  c604383a             mov byte ptr [eax + edi], 0x3a
// 0060ff0e  c644380120           mov byte ptr [eax + edi + 1], 0x20
// 0060ff13  40                   inc eax
// 0060ff14  40                   inc eax
// 0060ff15  03c7                 add eax, edi
// 0060ff17  b910000000           mov ecx, 0x10
// 0060ff1c  8bf2                 mov esi, edx
// 0060ff1e  8bf8                 mov edi, eax
// 0060ff20  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0060ff22  5f                   pop edi
// 0060ff23  5e                   pop esi
// 0060ff24  5d                   pop ebp
// 0060ff25  c6403f00             mov byte ptr [eax + 0x3f], 0
// 0060ff29  5b                   pop ebx
// 0060ff2a  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_format_buffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
