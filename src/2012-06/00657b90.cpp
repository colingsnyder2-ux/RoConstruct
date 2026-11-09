// from server: 100% by auto
// roc 2012-06 00657b90  unit: seg_00650000  size: 487 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657b90
//
// 00657b90  83ec18               sub esp, 0x18
// 00657b93  53                   push ebx
// 00657b94  55                   push ebp
// 00657b95  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00657b99  8b4d00               mov ecx, dword ptr [ebp]
// 00657b9c  33c0                 xor eax, eax
// 00657b9e  807d0408             cmp byte ptr [ebp + 4], 8
// 00657ba2  56                   push esi
// 00657ba3  8b750c               mov esi, dword ptr [ebp + 0xc]
// 00657ba6  0f95c0               setne al
// 00657ba9  57                   push edi
// 00657baa  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00657bae  c644241473           mov byte ptr [esp + 0x14], 0x73
// 00657bb3  c644241550           mov byte ptr [esp + 0x15], 0x50
// 00657bb8  c64424164c           mov byte ptr [esp + 0x16], 0x4c
// 00657bbd  c644241754           mov byte ptr [esp + 0x17], 0x54
// 00657bc2  8d048506000000       lea eax, [eax*4 + 6]
// 00657bc9  89442430             mov dword ptr [esp + 0x30], eax
// 00657bcd  0faff0               imul esi, eax
// 00657bd0  8d442410             lea eax, [esp + 0x10]
// 00657bd4  50                   push eax
// 00657bd5  51                   push ecx
// 00657bd6  57                   push edi
// 00657bd7  c644242400           mov byte ptr [esp + 0x24], 0
// 00657bdc  e82febffff           call 0x656710
// 00657be1  8bd8                 mov ebx, eax
// 00657be3  83c40c               add esp, 0xc
// 00657be6  85db                 test ebx, ebx
// 00657be8  0f8481010000         je 0x657d6f
// 00657bee  8d543302             lea edx, [ebx + esi + 2]
// 00657bf2  52                   push edx
// 00657bf3  8d442418             lea eax, [esp + 0x18]
// 00657bf7  50                   push eax
// 00657bf8  57                   push edi
// 00657bf9  e8c2e4ffff           call 0x6560c0
// 00657bfe  83c40c               add esp, 0xc
// 00657c01  8d7301               lea esi, [ebx + 1]
// 00657c04  85ff                 test edi, edi
// 00657c06  743f                 je 0x657c47
// 00657c08  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00657c0c  85db                 test ebx, ebx
// 00657c0e  7417                 je 0x657c27
// 00657c10  85f6                 test esi, esi
// 00657c12  7613                 jbe 0x657c27
// 00657c14  56                   push esi
// 00657c15  53                   push ebx
// 00657c16  57                   push edi
// 00657c17  e8a4fafeff           call 0x6476c0
// 00657c1c  56                   push esi
// 00657c1d  53                   push ebx
// 00657c1e  57                   push edi
// 00657c1f  e86c62feff           call 0x63de90
// 00657c24  83c418               add esp, 0x18
// 00657c27  85ff                 test edi, edi
// 00657c29  741c                 je 0x657c47
// 00657c2b  8d7504               lea esi, [ebp + 4]
// 00657c2e  85f6                 test esi, esi
// 00657c30  7415                 je 0x657c47
// 00657c32  6a01                 push 1
// 00657c34  56                   push esi
// 00657c35  57                   push edi
// 00657c36  e885fafeff           call 0x6476c0
// 00657c3b  6a01                 push 1
// 00657c3d  56                   push esi
// 00657c3e  57                   push edi
// 00657c3f  e84c62feff           call 0x63de90
// 00657c44  83c418               add esp, 0x18
// 00657c47  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00657c4a  8b7508               mov esi, dword ptr [ebp + 8]
// 00657c4d  8d0c80               lea ecx, [eax + eax*4]
// 00657c50  8d144e               lea edx, [esi + ecx*2]
// 00657c53  3bf2                 cmp esi, edx
// 00657c55  0f83cd000000         jae 0x657d28
// 00657c5b  eb03                 jmp 0x657c60
// 00657c5d  8d4900               lea ecx, [ecx]
// 00657c60  807d0408             cmp byte ptr [ebp + 4], 8
// 00657c64  7530                 jne 0x657c96
// 00657c66  0fb606               movzx eax, byte ptr [esi]
// 00657c69  8844241c             mov byte ptr [esp + 0x1c], al
// 00657c6d  8a4e02               mov cl, byte ptr [esi + 2]
// 00657c70  884c241d             mov byte ptr [esp + 0x1d], cl
// 00657c74  8a5604               mov dl, byte ptr [esi + 4]
// 00657c77  8854241e             mov byte ptr [esp + 0x1e], dl
// 00657c7b  0fb64606             movzx eax, byte ptr [esi + 6]
// 00657c7f  8844241f             mov byte ptr [esp + 0x1f], al
// 00657c83  0fb74608             movzx eax, word ptr [esi + 8]
// 00657c87  8bc8                 mov ecx, eax
// 00657c89  c1e908               shr ecx, 8
// 00657c8c  884c2420             mov byte ptr [esp + 0x20], cl
// 00657c90  88442421             mov byte ptr [esp + 0x21], al
// 00657c94  eb54                 jmp 0x657cea
// 00657c96  0fb706               movzx eax, word ptr [esi]
// 00657c99  8bd0                 mov edx, eax
// 00657c9b  c1ea08               shr edx, 8
// 00657c9e  8854241c             mov byte ptr [esp + 0x1c], dl
// 00657ca2  8844241d             mov byte ptr [esp + 0x1d], al
// 00657ca6  0fb74602             movzx eax, word ptr [esi + 2]
// 00657caa  8bc8                 mov ecx, eax
// 00657cac  c1e908               shr ecx, 8
// 00657caf  884c241e             mov byte ptr [esp + 0x1e], cl
// 00657cb3  8844241f             mov byte ptr [esp + 0x1f], al
// 00657cb7  0fb74604             movzx eax, word ptr [esi + 4]
// 00657cbb  8bd0                 mov edx, eax
// 00657cbd  c1ea08               shr edx, 8
// 00657cc0  88542420             mov byte ptr [esp + 0x20], dl
// 00657cc4  88442421             mov byte ptr [esp + 0x21], al
// 00657cc8  0fb74606             movzx eax, word ptr [esi + 6]
// 00657ccc  8bc8                 mov ecx, eax
// 00657cce  c1e908               shr ecx, 8
// 00657cd1  884c2422             mov byte ptr [esp + 0x22], cl
// 00657cd5  88442423             mov byte ptr [esp + 0x23], al
// 00657cd9  0fb74608             movzx eax, word ptr [esi + 8]
// 00657cdd  8bd0                 mov edx, eax
// 00657cdf  c1ea08               shr edx, 8
// 00657ce2  88542424             mov byte ptr [esp + 0x24], dl
// 00657ce6  88442425             mov byte ptr [esp + 0x25], al
// 00657cea  85ff                 test edi, edi
// 00657cec  7423                 je 0x657d11
// 00657cee  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00657cf2  85db                 test ebx, ebx
// 00657cf4  761b                 jbe 0x657d11
// 00657cf6  53                   push ebx
// 00657cf7  8d442420             lea eax, [esp + 0x20]
// 00657cfb  50                   push eax
// 00657cfc  57                   push edi
// 00657cfd  e8bef9feff           call 0x6476c0
// 00657d02  53                   push ebx
// 00657d03  8d4c242c             lea ecx, [esp + 0x2c]
// 00657d07  51                   push ecx
// 00657d08  57                   push edi
// 00657d09  e88261feff           call 0x63de90
// 00657d0e  83c418               add esp, 0x18
// 00657d11  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00657d14  8d1480               lea edx, [eax + eax*4]
// 00657d17  8b4508               mov eax, dword ptr [ebp + 8]
// 00657d1a  83c60a               add esi, 0xa
// 00657d1d  8d0c50               lea ecx, [eax + edx*2]
// 00657d20  3bf1                 cmp esi, ecx
// 00657d22  0f8238ffffff         jb 0x657c60
// 00657d28  85ff                 test edi, edi
// 00657d2a  7435                 je 0x657d61
// 00657d2c  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 00657d32  8bd0                 mov edx, eax
// 00657d34  c1ea18               shr edx, 0x18
// 00657d37  88542430             mov byte ptr [esp + 0x30], dl
// 00657d3b  8bc8                 mov ecx, eax
// 00657d3d  8bd0                 mov edx, eax
// 00657d3f  88442433             mov byte ptr [esp + 0x33], al
// 00657d43  6a04                 push 4
// 00657d45  8d442434             lea eax, [esp + 0x34]
// 00657d49  50                   push eax
// 00657d4a  c1e910               shr ecx, 0x10
// 00657d4d  c1ea08               shr edx, 8
// 00657d50  57                   push edi
// 00657d51  884c243d             mov byte ptr [esp + 0x3d], cl
// 00657d55  8854243e             mov byte ptr [esp + 0x3e], dl
// 00657d59  e862f9feff           call 0x6476c0
// 00657d5e  83c40c               add esp, 0xc
// 00657d61  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00657d65  51                   push ecx
// 00657d66  57                   push edi
// 00657d67  e8b467ffff           call 0x64e520
// 00657d6c  83c408               add esp, 8
// 00657d6f  5f                   pop edi
// 00657d70  5e                   pop esi
// 00657d71  5d                   pop ebp
// 00657d72  5b                   pop ebx
// 00657d73  83c418               add esp, 0x18
// 00657d76  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
