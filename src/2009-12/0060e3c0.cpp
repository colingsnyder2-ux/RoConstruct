// from server: 100% by auto
// roc 2009-12 0060e3c0  unit: seg_00600000  size: 512 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e3c0
//
// 0060e3c0  83ec18               sub esp, 0x18
// 0060e3c3  53                   push ebx
// 0060e3c4  55                   push ebp
// 0060e3c5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0060e3c9  33c0                 xor eax, eax
// 0060e3cb  807d0408             cmp byte ptr [ebp + 4], 8
// 0060e3cf  56                   push esi
// 0060e3d0  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0060e3d3  0f95c0               setne al
// 0060e3d6  57                   push edi
// 0060e3d7  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060e3db  c644241473           mov byte ptr [esp + 0x14], 0x73
// 0060e3e0  c644241550           mov byte ptr [esp + 0x15], 0x50
// 0060e3e5  c64424164c           mov byte ptr [esp + 0x16], 0x4c
// 0060e3ea  c644241754           mov byte ptr [esp + 0x17], 0x54
// 0060e3ef  8d048506000000       lea eax, [eax*4 + 6]
// 0060e3f6  0faff0               imul esi, eax
// 0060e3f9  89442430             mov dword ptr [esp + 0x30], eax
// 0060e3fd  8b4500               mov eax, dword ptr [ebp]
// 0060e400  c644241800           mov byte ptr [esp + 0x18], 0
// 0060e405  85c0                 test eax, eax
// 0060e407  0f849d010000         je 0x60e5aa
// 0060e40d  8d4c2410             lea ecx, [esp + 0x10]
// 0060e411  51                   push ecx
// 0060e412  50                   push eax
// 0060e413  57                   push edi
// 0060e414  e857ebffff           call 0x60cf70
// 0060e419  8bd8                 mov ebx, eax
// 0060e41b  83c40c               add esp, 0xc
// 0060e41e  85db                 test ebx, ebx
// 0060e420  0f8484010000         je 0x60e5aa
// 0060e426  8d543302             lea edx, [ebx + esi + 2]
// 0060e42a  52                   push edx
// 0060e42b  8d442418             lea eax, [esp + 0x18]
// 0060e42f  50                   push eax
// 0060e430  57                   push edi
// 0060e431  e8dae4ffff           call 0x60c910
// 0060e436  83c40c               add esp, 0xc
// 0060e439  8d7301               lea esi, [ebx + 1]
// 0060e43c  85ff                 test edi, edi
// 0060e43e  743f                 je 0x60e47f
// 0060e440  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0060e444  85db                 test ebx, ebx
// 0060e446  7417                 je 0x60e45f
// 0060e448  85f6                 test esi, esi
// 0060e44a  7613                 jbe 0x60e45f
// 0060e44c  56                   push esi
// 0060e44d  53                   push ebx
// 0060e44e  57                   push edi
// 0060e44f  e83c4fffff           call 0x603390
// 0060e454  56                   push esi
// 0060e455  53                   push ebx
// 0060e456  57                   push edi
// 0060e457  e81452ffff           call 0x603670
// 0060e45c  83c418               add esp, 0x18
// 0060e45f  85ff                 test edi, edi
// 0060e461  741c                 je 0x60e47f
// 0060e463  8d7504               lea esi, [ebp + 4]
// 0060e466  85f6                 test esi, esi
// 0060e468  7415                 je 0x60e47f
// 0060e46a  6a01                 push 1
// 0060e46c  56                   push esi
// 0060e46d  57                   push edi
// 0060e46e  e81d4fffff           call 0x603390
// 0060e473  6a01                 push 1
// 0060e475  56                   push esi
// 0060e476  57                   push edi
// 0060e477  e8f451ffff           call 0x603670
// 0060e47c  83c418               add esp, 0x18
// 0060e47f  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0060e482  8b7508               mov esi, dword ptr [ebp + 8]
// 0060e485  8d0c80               lea ecx, [eax + eax*4]
// 0060e488  8d144e               lea edx, [esi + ecx*2]
// 0060e48b  3bf2                 cmp esi, edx
// 0060e48d  0f83c8000000         jae 0x60e55b
// 0060e493  807d0408             cmp byte ptr [ebp + 4], 8
// 0060e497  7530                 jne 0x60e4c9
// 0060e499  0fb606               movzx eax, byte ptr [esi]
// 0060e49c  8844241c             mov byte ptr [esp + 0x1c], al
// 0060e4a0  8a4e02               mov cl, byte ptr [esi + 2]
// 0060e4a3  884c241d             mov byte ptr [esp + 0x1d], cl
// 0060e4a7  8a5604               mov dl, byte ptr [esi + 4]
// 0060e4aa  8854241e             mov byte ptr [esp + 0x1e], dl
// 0060e4ae  0fb64606             movzx eax, byte ptr [esi + 6]
// 0060e4b2  8844241f             mov byte ptr [esp + 0x1f], al
// 0060e4b6  0fb74608             movzx eax, word ptr [esi + 8]
// 0060e4ba  8bc8                 mov ecx, eax
// 0060e4bc  c1e908               shr ecx, 8
// 0060e4bf  884c2420             mov byte ptr [esp + 0x20], cl
// 0060e4c3  88442421             mov byte ptr [esp + 0x21], al
// 0060e4c7  eb54                 jmp 0x60e51d
// 0060e4c9  0fb706               movzx eax, word ptr [esi]
// 0060e4cc  8bd0                 mov edx, eax
// 0060e4ce  c1ea08               shr edx, 8
// 0060e4d1  8854241c             mov byte ptr [esp + 0x1c], dl
// 0060e4d5  8844241d             mov byte ptr [esp + 0x1d], al
// 0060e4d9  0fb74602             movzx eax, word ptr [esi + 2]
// 0060e4dd  8bc8                 mov ecx, eax
// 0060e4df  c1e908               shr ecx, 8
// 0060e4e2  884c241e             mov byte ptr [esp + 0x1e], cl
// 0060e4e6  8844241f             mov byte ptr [esp + 0x1f], al
// 0060e4ea  0fb74604             movzx eax, word ptr [esi + 4]
// 0060e4ee  8bd0                 mov edx, eax
// 0060e4f0  c1ea08               shr edx, 8
// 0060e4f3  88542420             mov byte ptr [esp + 0x20], dl
// 0060e4f7  88442421             mov byte ptr [esp + 0x21], al
// 0060e4fb  0fb74606             movzx eax, word ptr [esi + 6]
// 0060e4ff  8bc8                 mov ecx, eax
// 0060e501  c1e908               shr ecx, 8
// 0060e504  884c2422             mov byte ptr [esp + 0x22], cl
// 0060e508  88442423             mov byte ptr [esp + 0x23], al
// 0060e50c  0fb74608             movzx eax, word ptr [esi + 8]
// 0060e510  8bd0                 mov edx, eax
// 0060e512  c1ea08               shr edx, 8
// 0060e515  88542424             mov byte ptr [esp + 0x24], dl
// 0060e519  88442425             mov byte ptr [esp + 0x25], al
// 0060e51d  85ff                 test edi, edi
// 0060e51f  7423                 je 0x60e544
// 0060e521  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0060e525  85db                 test ebx, ebx
// 0060e527  761b                 jbe 0x60e544
// 0060e529  53                   push ebx
// 0060e52a  8d442420             lea eax, [esp + 0x20]
// 0060e52e  50                   push eax
// 0060e52f  57                   push edi
// 0060e530  e85b4effff           call 0x603390
// 0060e535  53                   push ebx
// 0060e536  8d4c242c             lea ecx, [esp + 0x2c]
// 0060e53a  51                   push ecx
// 0060e53b  57                   push edi
// 0060e53c  e82f51ffff           call 0x603670
// 0060e541  83c418               add esp, 0x18
// 0060e544  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0060e547  8d1480               lea edx, [eax + eax*4]
// 0060e54a  8b4508               mov eax, dword ptr [ebp + 8]
// 0060e54d  83c60a               add esi, 0xa
// 0060e550  8d0c50               lea ecx, [eax + edx*2]
// 0060e553  3bf1                 cmp esi, ecx
// 0060e555  0f8238ffffff         jb 0x60e493
// 0060e55b  85ff                 test edi, edi
// 0060e55d  7435                 je 0x60e594
// 0060e55f  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0060e565  8bd0                 mov edx, eax
// 0060e567  c1ea18               shr edx, 0x18
// 0060e56a  88542430             mov byte ptr [esp + 0x30], dl
// 0060e56e  8bc8                 mov ecx, eax
// 0060e570  8bd0                 mov edx, eax
// 0060e572  88442433             mov byte ptr [esp + 0x33], al
// 0060e576  6a04                 push 4
// 0060e578  8d442434             lea eax, [esp + 0x34]
// 0060e57c  50                   push eax
// 0060e57d  c1e910               shr ecx, 0x10
// 0060e580  c1ea08               shr edx, 8
// 0060e583  57                   push edi
// 0060e584  884c243d             mov byte ptr [esp + 0x3d], cl
// 0060e588  8854243e             mov byte ptr [esp + 0x3e], dl
// 0060e58c  e8ff4dffff           call 0x603390
// 0060e591  83c40c               add esp, 0xc
// 0060e594  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0060e598  51                   push ecx
// 0060e599  57                   push edi
// 0060e59a  e841270000           call 0x610ce0
// 0060e59f  83c408               add esp, 8
// 0060e5a2  5f                   pop edi
// 0060e5a3  5e                   pop esi
// 0060e5a4  5d                   pop ebp
// 0060e5a5  5b                   pop ebx
// 0060e5a6  83c418               add esp, 0x18
// 0060e5a9  c3                   ret 
// 0060e5aa  68f05e9c00           push 0x9c5ef0
// 0060e5af  57                   push edi
// 0060e5b0  e88b1c0000           call 0x610240
// 0060e5b5  83c408               add esp, 8
// 0060e5b8  5f                   pop edi
// 0060e5b9  5e                   pop esi
// 0060e5ba  5d                   pop ebp
// 0060e5bb  5b                   pop ebx
// 0060e5bc  83c418               add esp, 0x18
// 0060e5bf  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
