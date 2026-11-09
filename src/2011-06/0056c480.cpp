// from server: 100% by auto
// roc 2011-06 0056c480  unit: seg_00560000  size: 487 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c480
//
// 0056c480  83ec18               sub esp, 0x18
// 0056c483  53                   push ebx
// 0056c484  55                   push ebp
// 0056c485  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0056c489  8b4d00               mov ecx, dword ptr [ebp]
// 0056c48c  33c0                 xor eax, eax
// 0056c48e  807d0408             cmp byte ptr [ebp + 4], 8
// 0056c492  56                   push esi
// 0056c493  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0056c496  0f95c0               setne al
// 0056c499  57                   push edi
// 0056c49a  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056c49e  c644241473           mov byte ptr [esp + 0x14], 0x73
// 0056c4a3  c644241550           mov byte ptr [esp + 0x15], 0x50
// 0056c4a8  c64424164c           mov byte ptr [esp + 0x16], 0x4c
// 0056c4ad  c644241754           mov byte ptr [esp + 0x17], 0x54
// 0056c4b2  8d048506000000       lea eax, [eax*4 + 6]
// 0056c4b9  89442430             mov dword ptr [esp + 0x30], eax
// 0056c4bd  0faff0               imul esi, eax
// 0056c4c0  8d442410             lea eax, [esp + 0x10]
// 0056c4c4  50                   push eax
// 0056c4c5  51                   push ecx
// 0056c4c6  57                   push edi
// 0056c4c7  c644242400           mov byte ptr [esp + 0x24], 0
// 0056c4cc  e82febffff           call 0x56b000
// 0056c4d1  8bd8                 mov ebx, eax
// 0056c4d3  83c40c               add esp, 0xc
// 0056c4d6  85db                 test ebx, ebx
// 0056c4d8  0f8481010000         je 0x56c65f
// 0056c4de  8d543302             lea edx, [ebx + esi + 2]
// 0056c4e2  52                   push edx
// 0056c4e3  8d442418             lea eax, [esp + 0x18]
// 0056c4e7  50                   push eax
// 0056c4e8  57                   push edi
// 0056c4e9  e8c2e4ffff           call 0x56a9b0
// 0056c4ee  83c40c               add esp, 0xc
// 0056c4f1  8d7301               lea esi, [ebx + 1]
// 0056c4f4  85ff                 test edi, edi
// 0056c4f6  743f                 je 0x56c537
// 0056c4f8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0056c4fc  85db                 test ebx, ebx
// 0056c4fe  7417                 je 0x56c517
// 0056c500  85f6                 test esi, esi
// 0056c502  7613                 jbe 0x56c517
// 0056c504  56                   push esi
// 0056c505  53                   push ebx
// 0056c506  57                   push edi
// 0056c507  e834e3feff           call 0x55a840
// 0056c50c  56                   push esi
// 0056c50d  53                   push ebx
// 0056c50e  57                   push edi
// 0056c50f  e83c43feff           call 0x550850
// 0056c514  83c418               add esp, 0x18
// 0056c517  85ff                 test edi, edi
// 0056c519  741c                 je 0x56c537
// 0056c51b  8d7504               lea esi, [ebp + 4]
// 0056c51e  85f6                 test esi, esi
// 0056c520  7415                 je 0x56c537
// 0056c522  6a01                 push 1
// 0056c524  56                   push esi
// 0056c525  57                   push edi
// 0056c526  e815e3feff           call 0x55a840
// 0056c52b  6a01                 push 1
// 0056c52d  56                   push esi
// 0056c52e  57                   push edi
// 0056c52f  e81c43feff           call 0x550850
// 0056c534  83c418               add esp, 0x18
// 0056c537  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0056c53a  8b7508               mov esi, dword ptr [ebp + 8]
// 0056c53d  8d0c80               lea ecx, [eax + eax*4]
// 0056c540  8d144e               lea edx, [esi + ecx*2]
// 0056c543  3bf2                 cmp esi, edx
// 0056c545  0f83cd000000         jae 0x56c618
// 0056c54b  eb03                 jmp 0x56c550
// 0056c54d  8d4900               lea ecx, [ecx]
// 0056c550  807d0408             cmp byte ptr [ebp + 4], 8
// 0056c554  7530                 jne 0x56c586
// 0056c556  0fb606               movzx eax, byte ptr [esi]
// 0056c559  8844241c             mov byte ptr [esp + 0x1c], al
// 0056c55d  8a4e02               mov cl, byte ptr [esi + 2]
// 0056c560  884c241d             mov byte ptr [esp + 0x1d], cl
// 0056c564  8a5604               mov dl, byte ptr [esi + 4]
// 0056c567  8854241e             mov byte ptr [esp + 0x1e], dl
// 0056c56b  0fb64606             movzx eax, byte ptr [esi + 6]
// 0056c56f  8844241f             mov byte ptr [esp + 0x1f], al
// 0056c573  0fb74608             movzx eax, word ptr [esi + 8]
// 0056c577  8bc8                 mov ecx, eax
// 0056c579  c1e908               shr ecx, 8
// 0056c57c  884c2420             mov byte ptr [esp + 0x20], cl
// 0056c580  88442421             mov byte ptr [esp + 0x21], al
// 0056c584  eb54                 jmp 0x56c5da
// 0056c586  0fb706               movzx eax, word ptr [esi]
// 0056c589  8bd0                 mov edx, eax
// 0056c58b  c1ea08               shr edx, 8
// 0056c58e  8854241c             mov byte ptr [esp + 0x1c], dl
// 0056c592  8844241d             mov byte ptr [esp + 0x1d], al
// 0056c596  0fb74602             movzx eax, word ptr [esi + 2]
// 0056c59a  8bc8                 mov ecx, eax
// 0056c59c  c1e908               shr ecx, 8
// 0056c59f  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056c5a3  8844241f             mov byte ptr [esp + 0x1f], al
// 0056c5a7  0fb74604             movzx eax, word ptr [esi + 4]
// 0056c5ab  8bd0                 mov edx, eax
// 0056c5ad  c1ea08               shr edx, 8
// 0056c5b0  88542420             mov byte ptr [esp + 0x20], dl
// 0056c5b4  88442421             mov byte ptr [esp + 0x21], al
// 0056c5b8  0fb74606             movzx eax, word ptr [esi + 6]
// 0056c5bc  8bc8                 mov ecx, eax
// 0056c5be  c1e908               shr ecx, 8
// 0056c5c1  884c2422             mov byte ptr [esp + 0x22], cl
// 0056c5c5  88442423             mov byte ptr [esp + 0x23], al
// 0056c5c9  0fb74608             movzx eax, word ptr [esi + 8]
// 0056c5cd  8bd0                 mov edx, eax
// 0056c5cf  c1ea08               shr edx, 8
// 0056c5d2  88542424             mov byte ptr [esp + 0x24], dl
// 0056c5d6  88442425             mov byte ptr [esp + 0x25], al
// 0056c5da  85ff                 test edi, edi
// 0056c5dc  7423                 je 0x56c601
// 0056c5de  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0056c5e2  85db                 test ebx, ebx
// 0056c5e4  761b                 jbe 0x56c601
// 0056c5e6  53                   push ebx
// 0056c5e7  8d442420             lea eax, [esp + 0x20]
// 0056c5eb  50                   push eax
// 0056c5ec  57                   push edi
// 0056c5ed  e84ee2feff           call 0x55a840
// 0056c5f2  53                   push ebx
// 0056c5f3  8d4c242c             lea ecx, [esp + 0x2c]
// 0056c5f7  51                   push ecx
// 0056c5f8  57                   push edi
// 0056c5f9  e85242feff           call 0x550850
// 0056c5fe  83c418               add esp, 0x18
// 0056c601  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0056c604  8d1480               lea edx, [eax + eax*4]
// 0056c607  8b4508               mov eax, dword ptr [ebp + 8]
// 0056c60a  83c60a               add esi, 0xa
// 0056c60d  8d0c50               lea ecx, [eax + edx*2]
// 0056c610  3bf1                 cmp esi, ecx
// 0056c612  0f8238ffffff         jb 0x56c550
// 0056c618  85ff                 test edi, edi
// 0056c61a  7435                 je 0x56c651
// 0056c61c  8b8710010000         mov eax, dword ptr [edi + 0x110]
// 0056c622  8bd0                 mov edx, eax
// 0056c624  c1ea18               shr edx, 0x18
// 0056c627  88542430             mov byte ptr [esp + 0x30], dl
// 0056c62b  8bc8                 mov ecx, eax
// 0056c62d  8bd0                 mov edx, eax
// 0056c62f  88442433             mov byte ptr [esp + 0x33], al
// 0056c633  6a04                 push 4
// 0056c635  8d442434             lea eax, [esp + 0x34]
// 0056c639  50                   push eax
// 0056c63a  c1e910               shr ecx, 0x10
// 0056c63d  c1ea08               shr edx, 8
// 0056c640  57                   push edi
// 0056c641  884c243d             mov byte ptr [esp + 0x3d], cl
// 0056c645  8854243e             mov byte ptr [esp + 0x3e], dl
// 0056c649  e8f2e1feff           call 0x55a840
// 0056c64e  83c40c               add esp, 0xc
// 0056c651  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0056c655  51                   push ecx
// 0056c656  57                   push edi
// 0056c657  e84450ffff           call 0x5616a0
// 0056c65c  83c408               add esp, 8
// 0056c65f  5f                   pop edi
// 0056c660  5e                   pop esi
// 0056c661  5d                   pop ebp
// 0056c662  5b                   pop ebx
// 0056c663  83c418               add esp, 0x18
// 0056c666  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_sPLT)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
