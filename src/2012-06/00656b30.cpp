// from server: 100% by auto
// roc 2012-06 00656b30  unit: seg_00650000  size: 678 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00656b30
//
// 00656b30  83ec28               sub esp, 0x28
// 00656b33  837c243c04           cmp dword ptr [esp + 0x3c], 4
// 00656b38  56                   push esi
// 00656b39  8b742430             mov esi, dword ptr [esp + 0x30]
// 00656b3d  c644241870           mov byte ptr [esp + 0x18], 0x70
// 00656b42  c644241943           mov byte ptr [esp + 0x19], 0x43
// 00656b47  c644241a41           mov byte ptr [esp + 0x1a], 0x41
// 00656b4c  c644241b4c           mov byte ptr [esp + 0x1b], 0x4c
// 00656b51  c644241c00           mov byte ptr [esp + 0x1c], 0
// 00656b56  7c0e                 jl 0x656b66
// 00656b58  68f09ab800           push 0xb89af0
// 00656b5d  56                   push esi
// 00656b5e  e8fd76ffff           call 0x64e260
// 00656b63  83c408               add esp, 8
// 00656b66  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00656b6a  53                   push ebx
// 00656b6b  55                   push ebp
// 00656b6c  57                   push edi
// 00656b6d  8d442410             lea eax, [esp + 0x10]
// 00656b71  50                   push eax
// 00656b72  51                   push ecx
// 00656b73  56                   push esi
// 00656b74  e897fbffff           call 0x656710
// 00656b79  8be8                 mov ebp, eax
// 00656b7b  8b442460             mov eax, dword ptr [esp + 0x60]
// 00656b7f  83c40c               add esp, 0xc
// 00656b82  45                   inc ebp
// 00656b83  896c2418             mov dword ptr [esp + 0x18], ebp
// 00656b87  8d4801               lea ecx, [eax + 1]
// 00656b8a  8d9b00000000         lea ebx, [ebx]
// 00656b90  8a10                 mov dl, byte ptr [eax]
// 00656b92  40                   inc eax
// 00656b93  84d2                 test dl, dl
// 00656b95  75f9                 jne 0x656b90
// 00656b97  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 00656b9b  2bc1                 sub eax, ecx
// 00656b9d  33d2                 xor edx, edx
// 00656b9f  85db                 test ebx, ebx
// 00656ba1  0f95c2               setne dl
// 00656ba4  8d0c9d00000000       lea ecx, [ebx*4]
// 00656bab  51                   push ecx
// 00656bac  56                   push esi
// 00656bad  03d0                 add edx, eax
// 00656baf  8bfa                 mov edi, edx
// 00656bb1  8d442f0a             lea eax, [edi + ebp + 0xa]
// 00656bb5  897c2424             mov dword ptr [esp + 0x24], edi
// 00656bb9  89442444             mov dword ptr [esp + 0x44], eax
// 00656bbd  e8fe78ffff           call 0x64e4c0
// 00656bc2  83c408               add esp, 8
// 00656bc5  33c9                 xor ecx, ecx
// 00656bc7  89442450             mov dword ptr [esp + 0x50], eax
// 00656bcb  85db                 test ebx, ebx
// 00656bcd  7e50                 jle 0x656c1f
// 00656bcf  8b542458             mov edx, dword ptr [esp + 0x58]
// 00656bd3  2bd0                 sub edx, eax
// 00656bd5  8bf8                 mov edi, eax
// 00656bd7  89542414             mov dword ptr [esp + 0x14], edx
// 00656bdb  eb07                 jmp 0x656be4
// 00656bdd  8d4900               lea ecx, [ecx]
// 00656be0  8b542414             mov edx, dword ptr [esp + 0x14]
// 00656be4  8b043a               mov eax, dword ptr [edx + edi]
// 00656be7  8d6801               lea ebp, [eax + 1]
// 00656bea  8d9b00000000         lea ebx, [ebx]
// 00656bf0  8a10                 mov dl, byte ptr [eax]
// 00656bf2  40                   inc eax
// 00656bf3  84d2                 test dl, dl
// 00656bf5  75f9                 jne 0x656bf0
// 00656bf7  2bc5                 sub eax, ebp
// 00656bf9  8be8                 mov ebp, eax
// 00656bfb  33d2                 xor edx, edx
// 00656bfd  8d43ff               lea eax, [ebx - 1]
// 00656c00  3bc8                 cmp ecx, eax
// 00656c02  0f95c2               setne dl
// 00656c05  41                   inc ecx
// 00656c06  83c704               add edi, 4
// 00656c09  8d042a               lea eax, [edx + ebp]
// 00656c0c  0144243c             add dword ptr [esp + 0x3c], eax
// 00656c10  3bcb                 cmp ecx, ebx
// 00656c12  8947fc               mov dword ptr [edi - 4], eax
// 00656c15  7cc9                 jl 0x656be0
// 00656c17  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00656c1b  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00656c1f  85f6                 test esi, esi
// 00656c21  747b                 je 0x656c9e
// 00656c23  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00656c27  8bc8                 mov ecx, eax
// 00656c29  c1e918               shr ecx, 0x18
// 00656c2c  884c241c             mov byte ptr [esp + 0x1c], cl
// 00656c30  8bd0                 mov edx, eax
// 00656c32  8bc8                 mov ecx, eax
// 00656c34  c1ea10               shr edx, 0x10
// 00656c37  8844241f             mov byte ptr [esp + 0x1f], al
// 00656c3b  6a08                 push 8
// 00656c3d  8d442420             lea eax, [esp + 0x20]
// 00656c41  88542421             mov byte ptr [esp + 0x21], dl
// 00656c45  8b542428             mov edx, dword ptr [esp + 0x28]
// 00656c49  50                   push eax
// 00656c4a  c1e908               shr ecx, 8
// 00656c4d  56                   push esi
// 00656c4e  884c242a             mov byte ptr [esp + 0x2a], cl
// 00656c52  8954242c             mov dword ptr [esp + 0x2c], edx
// 00656c56  e8650affff           call 0x6476c0
// 00656c5b  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00656c5f  56                   push esi
// 00656c60  898e1c010000         mov dword ptr [esi + 0x11c], ecx
// 00656c66  e80572feff           call 0x63de70
// 00656c6b  6a04                 push 4
// 00656c6d  8d542438             lea edx, [esp + 0x38]
// 00656c71  52                   push edx
// 00656c72  56                   push esi
// 00656c73  e81872feff           call 0x63de90
// 00656c78  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00656c7c  83c41c               add esp, 0x1c
// 00656c7f  85c0                 test eax, eax
// 00656c81  741b                 je 0x656c9e
// 00656c83  85ed                 test ebp, ebp
// 00656c85  7617                 jbe 0x656c9e
// 00656c87  55                   push ebp
// 00656c88  50                   push eax
// 00656c89  56                   push esi
// 00656c8a  e8310affff           call 0x6476c0
// 00656c8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00656c93  55                   push ebp
// 00656c94  50                   push eax
// 00656c95  56                   push esi
// 00656c96  e8f571feff           call 0x63de90
// 00656c9b  83c418               add esp, 0x18
// 00656c9e  8b442444             mov eax, dword ptr [esp + 0x44]
// 00656ca2  8bc8                 mov ecx, eax
// 00656ca4  c1f918               sar ecx, 0x18
// 00656ca7  884c242c             mov byte ptr [esp + 0x2c], cl
// 00656cab  8bd0                 mov edx, eax
// 00656cad  c1fa10               sar edx, 0x10
// 00656cb0  8bc8                 mov ecx, eax
// 00656cb2  8854242d             mov byte ptr [esp + 0x2d], dl
// 00656cb6  8844242f             mov byte ptr [esp + 0x2f], al
// 00656cba  8b442448             mov eax, dword ptr [esp + 0x48]
// 00656cbe  c1f908               sar ecx, 8
// 00656cc1  8bd0                 mov edx, eax
// 00656cc3  c1fa18               sar edx, 0x18
// 00656cc6  884c242e             mov byte ptr [esp + 0x2e], cl
// 00656cca  88542430             mov byte ptr [esp + 0x30], dl
// 00656cce  8bc8                 mov ecx, eax
// 00656cd0  8bd0                 mov edx, eax
// 00656cd2  c1f910               sar ecx, 0x10
// 00656cd5  c1fa08               sar edx, 8
// 00656cd8  88442433             mov byte ptr [esp + 0x33], al
// 00656cdc  8a44244c             mov al, byte ptr [esp + 0x4c]
// 00656ce0  884c2431             mov byte ptr [esp + 0x31], cl
// 00656ce4  88542432             mov byte ptr [esp + 0x32], dl
// 00656ce8  88442434             mov byte ptr [esp + 0x34], al
// 00656cec  885c2435             mov byte ptr [esp + 0x35], bl
// 00656cf0  85f6                 test esi, esi
// 00656cf2  743c                 je 0x656d30
// 00656cf4  6a0a                 push 0xa
// 00656cf6  8d4c2430             lea ecx, [esp + 0x30]
// 00656cfa  51                   push ecx
// 00656cfb  56                   push esi
// 00656cfc  e8bf09ffff           call 0x6476c0
// 00656d01  6a0a                 push 0xa
// 00656d03  8d54243c             lea edx, [esp + 0x3c]
// 00656d07  52                   push edx
// 00656d08  56                   push esi
// 00656d09  e88271feff           call 0x63de90
// 00656d0e  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 00656d12  83c418               add esp, 0x18
// 00656d15  85ed                 test ebp, ebp
// 00656d17  7417                 je 0x656d30
// 00656d19  85ff                 test edi, edi
// 00656d1b  7613                 jbe 0x656d30
// 00656d1d  57                   push edi
// 00656d1e  55                   push ebp
// 00656d1f  56                   push esi
// 00656d20  e89b09ffff           call 0x6476c0
// 00656d25  57                   push edi
// 00656d26  55                   push ebp
// 00656d27  56                   push esi
// 00656d28  e86371feff           call 0x63de90
// 00656d2d  83c418               add esp, 0x18
// 00656d30  8b442410             mov eax, dword ptr [esp + 0x10]
// 00656d34  50                   push eax
// 00656d35  56                   push esi
// 00656d36  e8e577ffff           call 0x64e520
// 00656d3b  83c408               add esp, 8
// 00656d3e  85db                 test ebx, ebx
// 00656d40  7e45                 jle 0x656d87
// 00656d42  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 00656d46  8b442450             mov eax, dword ptr [esp + 0x50]
// 00656d4a  2bc5                 sub eax, ebp
// 00656d4c  8944243c             mov dword ptr [esp + 0x3c], eax
// 00656d50  895c244c             mov dword ptr [esp + 0x4c], ebx
// 00656d54  8b1c28               mov ebx, dword ptr [eax + ebp]
// 00656d57  8b7d00               mov edi, dword ptr [ebp]
// 00656d5a  85f6                 test esi, esi
// 00656d5c  741f                 je 0x656d7d
// 00656d5e  85ff                 test edi, edi
// 00656d60  741b                 je 0x656d7d
// 00656d62  85db                 test ebx, ebx
// 00656d64  7617                 jbe 0x656d7d
// 00656d66  53                   push ebx
// 00656d67  57                   push edi
// 00656d68  56                   push esi
// 00656d69  e85209ffff           call 0x6476c0
// 00656d6e  53                   push ebx
// 00656d6f  57                   push edi
// 00656d70  56                   push esi
// 00656d71  e81a71feff           call 0x63de90
// 00656d76  8b442454             mov eax, dword ptr [esp + 0x54]
// 00656d7a  83c418               add esp, 0x18
// 00656d7d  83c504               add ebp, 4
// 00656d80  836c244c01           sub dword ptr [esp + 0x4c], 1
// 00656d85  75cd                 jne 0x656d54
// 00656d87  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 00656d8b  51                   push ecx
// 00656d8c  56                   push esi
// 00656d8d  e88e77ffff           call 0x64e520
// 00656d92  83c408               add esp, 8
// 00656d95  5f                   pop edi
// 00656d96  5d                   pop ebp
// 00656d97  5b                   pop ebx
// 00656d98  85f6                 test esi, esi
// 00656d9a  7435                 je 0x656dd1
// 00656d9c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00656da2  8bd0                 mov edx, eax
// 00656da4  c1ea18               shr edx, 0x18
// 00656da7  88542440             mov byte ptr [esp + 0x40], dl
// 00656dab  8bc8                 mov ecx, eax
// 00656dad  8bd0                 mov edx, eax
// 00656daf  88442443             mov byte ptr [esp + 0x43], al
// 00656db3  6a04                 push 4
// 00656db5  8d442444             lea eax, [esp + 0x44]
// 00656db9  50                   push eax
// 00656dba  c1e910               shr ecx, 0x10
// 00656dbd  c1ea08               shr edx, 8
// 00656dc0  56                   push esi
// 00656dc1  884c244d             mov byte ptr [esp + 0x4d], cl
// 00656dc5  8854244e             mov byte ptr [esp + 0x4e], dl
// 00656dc9  e8f208ffff           call 0x6476c0
// 00656dce  83c40c               add esp, 0xc
// 00656dd1  5e                   pop esi
// 00656dd2  83c428               add esp, 0x28
// 00656dd5  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
