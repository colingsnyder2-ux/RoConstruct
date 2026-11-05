// from server: 100% by auto
// roc 2012-06 0064deb0  unit: seg_00640000  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0064deb0
//
// 0064deb0  53                   push ebx
// 0064deb1  55                   push ebp
// 0064deb2  56                   push esi
// 0064deb3  57                   push edi
// 0064deb4  8bf8                 mov edi, eax
// 0064deb6  33c0                 xor eax, eax
// 0064deb8  8bf1                 mov esi, ecx
// 0064deba  33ed                 xor ebp, ebp
// 0064debc  8d642400             lea esp, [esp]
// 0064dec0  0fb68c2e1c010000     movzx ecx, byte ptr [esi + ebp + 0x11c]
// 0064dec8  8d59bf               lea ebx, [ecx - 0x41]
// 0064decb  45                   inc ebp
// 0064decc  83fb39               cmp ebx, 0x39
// 0064decf  770f                 ja 0x64dee0
// 0064ded1  83f95a               cmp ecx, 0x5a
// 0064ded4  7e05                 jle 0x64dedb
// 0064ded6  83f961               cmp ecx, 0x61
// 0064ded9  7c05                 jl 0x64dee0
// 0064dedb  880c38               mov byte ptr [eax + edi], cl
// 0064dede  eb28                 jmp 0x64df08
// 0064dee0  c604385b             mov byte ptr [eax + edi], 0x5b
// 0064dee4  8bd9                 mov ebx, ecx
// 0064dee6  c1fb04               sar ebx, 4
// 0064dee9  83e30f               and ebx, 0xf
// 0064deec  8a9b746bb800         mov bl, byte ptr [ebx + 0xb86b74]
// 0064def2  40                   inc eax
// 0064def3  881c38               mov byte ptr [eax + edi], bl
// 0064def6  83e10f               and ecx, 0xf
// 0064def9  8a89746bb800         mov cl, byte ptr [ecx + 0xb86b74]
// 0064deff  40                   inc eax
// 0064df00  880c38               mov byte ptr [eax + edi], cl
// 0064df03  40                   inc eax
// 0064df04  c604385d             mov byte ptr [eax + edi], 0x5d
// 0064df08  40                   inc eax
// 0064df09  83fd04               cmp ebp, 4
// 0064df0c  7cb2                 jl 0x64dec0
// 0064df0e  85d2                 test edx, edx
// 0064df10  7508                 jne 0x64df1a
// 0064df12  881438               mov byte ptr [eax + edi], dl
// 0064df15  5f                   pop edi
// 0064df16  5e                   pop esi
// 0064df17  5d                   pop ebp
// 0064df18  5b                   pop ebx
// 0064df19  c3                   ret 
// 0064df1a  c604383a             mov byte ptr [eax + edi], 0x3a
// 0064df1e  c644380120           mov byte ptr [eax + edi + 1], 0x20
// 0064df23  40                   inc eax
// 0064df24  40                   inc eax
// 0064df25  03c7                 add eax, edi
// 0064df27  b910000000           mov ecx, 0x10
// 0064df2c  8bf2                 mov esi, edx
// 0064df2e  8bf8                 mov edi, eax
// 0064df30  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0064df32  5f                   pop edi
// 0064df33  5e                   pop esi
// 0064df34  5d                   pop ebp
// 0064df35  c6403f00             mov byte ptr [eax + 0x3f], 0
// 0064df39  5b                   pop ebx
// 0064df3a  c3                   ret 
// library libpng-1.2.24/pngerror.c (function _png_format_buffer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.24 pngerror.c
