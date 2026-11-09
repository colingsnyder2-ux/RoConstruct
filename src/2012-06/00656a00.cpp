// from server: 100% by auto
// roc 2012-06 00656a00  unit: seg_00650000  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656a00
//
// 00656a00  83ec24               sub esp, 0x24
// 00656a03  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00656a07  55                   push ebp
// 00656a08  56                   push esi
// 00656a09  8b742430             mov esi, dword ptr [esp + 0x30]
// 00656a0d  57                   push edi
// 00656a0e  8d442410             lea eax, [esp + 0x10]
// 00656a12  50                   push eax
// 00656a13  33ff                 xor edi, edi
// 00656a15  51                   push ecx
// 00656a16  56                   push esi
// 00656a17  c64424207a           mov byte ptr [esp + 0x20], 0x7a
// 00656a1c  c644242154           mov byte ptr [esp + 0x21], 0x54
// 00656a21  c644242258           mov byte ptr [esp + 0x22], 0x58
// 00656a26  c644242374           mov byte ptr [esp + 0x23], 0x74
// 00656a2b  c644242400           mov byte ptr [esp + 0x24], 0
// 00656a30  897c2430             mov dword ptr [esp + 0x30], edi
// 00656a34  897c2434             mov dword ptr [esp + 0x34], edi
// 00656a38  897c2438             mov dword ptr [esp + 0x38], edi
// 00656a3c  897c2428             mov dword ptr [esp + 0x28], edi
// 00656a40  897c242c             mov dword ptr [esp + 0x2c], edi
// 00656a44  e8c7fcffff           call 0x656710
// 00656a49  8be8                 mov ebp, eax
// 00656a4b  83c40c               add esp, 0xc
// 00656a4e  3bef                 cmp ebp, edi
// 00656a50  7515                 jne 0x656a67
// 00656a52  8b542410             mov edx, dword ptr [esp + 0x10]
// 00656a56  52                   push edx
// 00656a57  56                   push esi
// 00656a58  e8c37affff           call 0x64e520
// 00656a5d  83c408               add esp, 8
// 00656a60  5f                   pop edi
// 00656a61  5e                   pop esi
// 00656a62  5d                   pop ebp
// 00656a63  83c424               add esp, 0x24
// 00656a66  c3                   ret 
// 00656a67  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00656a6b  53                   push ebx
// 00656a6c  3bd7                 cmp edx, edi
// 00656a6e  0f849b000000         je 0x656b0f
// 00656a74  803a00               cmp byte ptr [edx], 0
// 00656a77  0f8492000000         je 0x656b0f
// 00656a7d  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 00656a81  83fbff               cmp ebx, -1
// 00656a84  0f8485000000         je 0x656b0f
// 00656a8a  8bc2                 mov eax, edx
// 00656a8c  8d7801               lea edi, [eax + 1]
// 00656a8f  90                   nop 
// 00656a90  8a08                 mov cl, byte ptr [eax]
// 00656a92  40                   inc eax
// 00656a93  84c9                 test cl, cl
// 00656a95  75f9                 jne 0x656a90
// 00656a97  2bc7                 sub eax, edi
// 00656a99  8bc8                 mov ecx, eax
// 00656a9b  52                   push edx
// 00656a9c  8d7c2424             lea edi, [esp + 0x24]
// 00656aa0  8bc3                 mov eax, ebx
// 00656aa2  8bd6                 mov edx, esi
// 00656aa4  e807f7ffff           call 0x6561b0
// 00656aa9  8d442802             lea eax, [eax + ebp + 2]
// 00656aad  50                   push eax
// 00656aae  8d4c2420             lea ecx, [esp + 0x20]
// 00656ab2  51                   push ecx
// 00656ab3  56                   push esi
// 00656ab4  e807f6ffff           call 0x6560c0
// 00656ab9  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00656abd  45                   inc ebp
// 00656abe  55                   push ebp
// 00656abf  57                   push edi
// 00656ac0  56                   push esi
// 00656ac1  e86af6ffff           call 0x656130
// 00656ac6  57                   push edi
// 00656ac7  56                   push esi
// 00656ac8  e8537affff           call 0x64e520
// 00656acd  83c424               add esp, 0x24
// 00656ad0  885c2413             mov byte ptr [esp + 0x13], bl
// 00656ad4  85f6                 test esi, esi
// 00656ad6  741d                 je 0x656af5
// 00656ad8  6a01                 push 1
// 00656ada  8d542417             lea edx, [esp + 0x17]
// 00656ade  52                   push edx
// 00656adf  56                   push esi
// 00656ae0  e8db0bffff           call 0x6476c0
// 00656ae5  6a01                 push 1
// 00656ae7  8d442423             lea eax, [esp + 0x23]
// 00656aeb  50                   push eax
// 00656aec  56                   push esi
// 00656aed  e89e73feff           call 0x63de90
// 00656af2  83c418               add esp, 0x18
// 00656af5  8d442420             lea eax, [esp + 0x20]
// 00656af9  e832f9ffff           call 0x656430
// 00656afe  56                   push esi
// 00656aff  e86cf6ffff           call 0x656170
// 00656b04  83c404               add esp, 4
// 00656b07  5b                   pop ebx
// 00656b08  5f                   pop edi
// 00656b09  5e                   pop esi
// 00656b0a  5d                   pop ebp
// 00656b0b  83c424               add esp, 0x24
// 00656b0e  c3                   ret 
// 00656b0f  57                   push edi
// 00656b10  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00656b14  52                   push edx
// 00656b15  57                   push edi
// 00656b16  56                   push esi
// 00656b17  e8d4fdffff           call 0x6568f0
// 00656b1c  57                   push edi
// 00656b1d  56                   push esi
// 00656b1e  e8fd79ffff           call 0x64e520
// 00656b23  83c418               add esp, 0x18
// 00656b26  5b                   pop ebx
// 00656b27  5f                   pop edi
// 00656b28  5e                   pop esi
// 00656b29  5d                   pop ebp
// 00656b2a  83c424               add esp, 0x24
// 00656b2d  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
