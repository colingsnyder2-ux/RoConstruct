// from server: 100% by auto
// roc 2009-06 0058c370  unit: seg_00580000  size: 512 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c370
//
// 0058c370  83ec18               sub esp, 0x18
// 0058c373  53                   push ebx
// 0058c374  55                   push ebp
// 0058c375  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0058c379  33c0                 xor eax, eax
// 0058c37b  807d0408             cmp byte ptr [ebp + 4], 8
// 0058c37f  56                   push esi
// 0058c380  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0058c383  0f95c0               setne al
// 0058c386  57                   push edi
// 0058c387  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0058c38b  c644241473           mov byte ptr [esp + 0x14], 0x73
// 0058c390  c644241550           mov byte ptr [esp + 0x15], 0x50
// 0058c395  c64424164c           mov byte ptr [esp + 0x16], 0x4c
// 0058c39a  c644241754           mov byte ptr [esp + 0x17], 0x54
// 0058c39f  8d048506000000       lea eax, [eax*4 + 6]
// 0058c3a6  0faff0               imul esi, eax
// 0058c3a9  89442430             mov dword ptr [esp + 0x30], eax
// 0058c3ad  8b4500               mov eax, dword ptr [ebp]
// 0058c3b0  c644241800           mov byte ptr [esp + 0x18], 0
// 0058c3b5  85c0                 test eax, eax
// 0058c3b7  0f849d010000         je 0x58c55a
// 0058c3bd  8d4c2410             lea ecx, [esp + 0x10]
// 0058c3c1  51                   push ecx
// 0058c3c2  50                   push eax
// 0058c3c3  57                   push edi
// 0058c3c4  e857ebffff           call 0x58af20
// 0058c3c9  8bd8                 mov ebx, eax
// 0058c3cb  83c40c               add esp, 0xc
// 0058c3ce  85db                 test ebx, ebx
// 0058c3d0  0f8484010000         je 0x58c55a
// 0058c3d6  8d543302             lea edx, [ebx + esi + 2]
// 0058c3da  52                   push edx
// 0058c3db  8d442418             lea eax, [esp + 0x18]
// 0058c3df  50                   push eax
// 0058c3e0  57                   push edi
// 0058c3e1  e8dae4ffff           call 0x58a8c0
// 0058c3e6  83c40c               add esp, 0xc
// 0058c3e9  8d7301               lea esi, [ebx + 1]
// 0058c3ec  85ff                 test edi, edi
// 0058c3ee  743f                 je 0x58c42f
// 0058c3f0  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058c3f4  85db                 test ebx, ebx
// 0058c3f6  7417                 je 0x58c40f
// 0058c3f8  85f6                 test esi, esi
// 0058c3fa  7613                 jbe 0x58c40f
// 0058c3fc  56                   push esi
// 0058c3fd  53                   push ebx
// 0058c3fe  57                   push edi
// 0058c3ff  e8dc51ffff           call 0x5815e0
// 0058c404  56                   push esi
// 0058c405  53                   push ebx
// 0058c406  57                   push edi
// 0058c407  e8b454ffff           call 0x5818c0
// 0058c40c  83c418               add esp, 0x18
// 0058c40f  85ff                 test edi, edi
// 0058c411  741c                 je 0x58c42f
// 0058c413  8d7504               lea esi, [ebp + 4]
// 0058c416  85f6                 test esi, esi
// 0058c418  7415                 je 0x58c42f
// 0058c41a  6a01                 push 1
// 0058c41c  56                   push esi
// 0058c41d  57                   push edi
// 0058c41e  e8bd51ffff           call 0x5815e0
// 0058c423  6a01                 push 1
// 0058c425  56                   push esi
// 0058c426  57                   push edi
// 0058c427  e89454ffff           call 0x5818c0
// 0058c42c  83c418               add esp, 0x18
// 0058c42f  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0058c432  8b7508               mov esi, dword ptr [ebp + 8]
// 0058c435  8d0c80               lea ecx, [eax + eax*4]
// 0058c438  8d144e               lea edx, [esi + ecx*2]
// 0058c43b  3bf2                 cmp esi, edx
// 0058c43d  0f83c8000000         jae 0x58c50b
// 0058c443  807d0408             cmp byte ptr [ebp + 4], 8
// 0058c447  7530                 jne 0x58c479
// 0058c449  0fb606               movzx eax, byte ptr [esi]
// 0058c44c  8844241c             mov byte ptr [esp + 0x1c], al
// 0058c450  8a4e02               mov cl, byte ptr [esi + 2]
// 0058c453  884c241d             mov byte ptr [esp + 0x1d], cl
// 0058c457  8a5604               mov dl, byte ptr [esi + 4]
// 0058c45a  8854241e             mov byte ptr [esp + 0x1e], dl
// 0058c45e  0fb64606             movzx eax, byte ptr [esi + 6]
// 0058c462  8844241f             mov byte ptr [esp + 0x1f], al
// 0058c466  0fb74608             movzx eax, word ptr [esi + 8]
// 0058c46a  8bc8                 mov ecx, eax
// 0058c46c  c1e908               shr ecx, 8
// 0058c46f  884c2420             mov byte ptr [esp + 0x20], cl
// 0058c473  88442421             mov byte ptr [esp + 0x21], al
// 0058c477  eb54                 jmp 0x58c4cd
// 0058c479  0fb706               movzx eax, word ptr [esi]
// 0058c47c  8bd0                 mov edx, eax
// 0058c47e  c1ea08               shr edx, 8
// 0058c481  8854241c             mov byte ptr [esp + 0x1c], dl
// 0058c485  8844241d             mov byte ptr [esp + 0x1d], al
// 0058c489  0fb74602             movzx eax, word ptr [esi + 2]
// 0058c48d  8bc8                 mov ecx, eax
// 0058c48f  c1e908               shr ecx, 8
// 0058c492  884c241e             mov byte ptr [esp + 0x1e], cl
// 0058c496  8844241f             mov byte ptr [esp + 0x1f], al
// 0058c49a  0fb74604             movzx eax, word ptr [esi + 4]
// 0058c49e  8bd0                 mov edx, eax
// 0058c4a0  c1ea08               shr edx, 8
// 0058c4a3  88542420             mov byte ptr [esp + 0x20], dl
// 0058c4a7  88442421             mov byte ptr [esp + 0x21], al
// 0058c4ab  0fb74606             movzx eax, word ptr [esi + 6]
// 0058c4af  8bc8                 mov ecx, eax
// 0058c4b1  c1e908               shr ecx, 8
// 0058c4b4  884c2422             mov byte ptr [esp + 0x22], cl
// 0058c4b8  88442423             mov byte ptr [esp + 0x23], al
// 0058c4bc  0fb74608             movzx eax, word ptr [esi + 8]
// 0058c4c0  8bd0                 mov edx, eax
// 0058c4c2  c1ea08               shr edx, 8
// 0058c4c5  88542424             mov byte ptr [esp + 0x24], dl
// 0058c4c9  88442425             mov byte ptr [esp + 0x25], al
// 0058c4cd  85ff                 test edi, edi
// 0058c4cf  7423                 je 0x58c4f4
// 0058c4d1  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0058c4d5  85db                 test ebx, ebx
// 0058c4d7  761b                 jbe 0x58c4f4
// 0058c4d9  53                   push ebx
// 0058c4da  8d442420             lea eax, [esp + 0x20]
// 0058c4de  50                   push eax
// 0058c4df  57                   push edi
// 0058c4e0  e8fb50ffff           call 0x5815e0
// 0058c4e5  53                   push ebx
// 0058c4e6  8d4c242c             lea ecx, [esp + 0x2c]
// 0058c4ea  51                   push ecx
// 0058c4eb  57                   push edi
// 0058c4ec  e8cf53ffff           call 0x5818c0
// 0058c4f1  83c418               add esp, 0x18
// 0058c4f4  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0058c4f7  8d1480               lea edx, [eax + eax*4]
// 0058c4fa  8b4508               mov eax, dword ptr [ebp + 8]
// 0058c4fd  83c60a               add esi, 0xa
// 0058c500  8d0c50               lea ecx, [eax + edx*2]
// 0058c503  3bf1                 cmp esi, ecx
// 0058c505  0f8238ffffff         jb 0x58c443
// 0058c50b  85ff                 test edi, edi
// 0058c50d  7435                 je 0x58c544
// 0058c50f  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0058c515  8bd0                 mov edx, eax
// 0058c517  c1ea18               shr edx, 0x18
// 0058c51a  88542430             mov byte ptr [esp + 0x30], dl
// 0058c51e  8bc8                 mov ecx, eax
// 0058c520  8bd0                 mov edx, eax
// 0058c522  88442433             mov byte ptr [esp + 0x33], al
// 0058c526  6a04                 push 4
// 0058c528  8d442434             lea eax, [esp + 0x34]
// 0058c52c  50                   push eax
// 0058c52d  c1e910               shr ecx, 0x10
// 0058c530  c1ea08               shr edx, 8
// 0058c533  57                   push edi
// 0058c534  884c243d             mov byte ptr [esp + 0x3d], cl
// 0058c538  8854243e             mov byte ptr [esp + 0x3e], dl
// 0058c53c  e89f50ffff           call 0x5815e0
// 0058c541  83c40c               add esp, 0xc
// 0058c544  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058c548  51                   push ecx
// 0058c549  57                   push edi
// 0058c54a  e861270000           call 0x58ecb0
// 0058c54f  83c408               add esp, 8
// 0058c552  5f                   pop edi
// 0058c553  5e                   pop esi
// 0058c554  5d                   pop ebp
// 0058c555  5b                   pop ebx
// 0058c556  83c418               add esp, 0x18
// 0058c559  c3                   ret 
// 0058c55a  6858f08c00           push 0x8cf058
// 0058c55f  57                   push edi
// 0058c560  e8ab1c0000           call 0x58e210
// 0058c565  83c408               add esp, 8
// 0058c568  5f                   pop edi
// 0058c569  5e                   pop esi
// 0058c56a  5d                   pop ebp
// 0058c56b  5b                   pop ebx
// 0058c56c  83c418               add esp, 0x18
// 0058c56f  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
