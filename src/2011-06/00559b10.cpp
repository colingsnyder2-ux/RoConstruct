// from server: 100% by auto
// roc 2011-06 00559b10  unit: seg_00550000  size: 549 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559b10
//
// 00559b10  57                   push edi
// 00559b11  8b7c2408             mov edi, dword ptr [esp + 8]
// 00559b15  85ff                 test edi, edi
// 00559b17  0f8416020000         je 0x559d33
// 00559b1d  56                   push esi
// 00559b1e  8b742410             mov esi, dword ptr [esp + 0x10]
// 00559b22  85f6                 test esi, esi
// 00559b24  0f8408020000         je 0x559d32
// 00559b2a  53                   push ebx
// 00559b2b  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00559b2f  55                   push ebp
// 00559b30  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00559b34  85ed                 test ebp, ebp
// 00559b36  7404                 je 0x559b3c
// 00559b38  85db                 test ebx, ebx
// 00559b3a  750e                 jne 0x559b4a
// 00559b3c  684423a800           push 0xa82344
// 00559b41  57                   push edi
// 00559b42  e8e9770000           call 0x561330
// 00559b47  83c408               add esp, 8
// 00559b4a  3baf64020000         cmp ebp, dword ptr [edi + 0x264]
// 00559b50  7708                 ja 0x559b5a
// 00559b52  3b9f68020000         cmp ebx, dword ptr [edi + 0x268]
// 00559b58  760e                 jbe 0x559b68
// 00559b5a  681c23a800           push 0xa8231c
// 00559b5f  57                   push edi
// 00559b60  e8cb770000           call 0x561330
// 00559b65  83c408               add esp, 8
// 00559b68  81fdffffff7f         cmp ebp, 0x7fffffff
// 00559b6e  7708                 ja 0x559b78
// 00559b70  81fbffffff7f         cmp ebx, 0x7fffffff
// 00559b76  760e                 jbe 0x559b86
// 00559b78  680023a800           push 0xa82300
// 00559b7d  57                   push edi
// 00559b7e  e8ad770000           call 0x561330
// 00559b83  83c408               add esp, 8
// 00559b86  81fd7effff1f         cmp ebp, 0x1fffff7e
// 00559b8c  760e                 jbe 0x559b9c
// 00559b8e  68d022a800           push 0xa822d0
// 00559b93  57                   push edi
// 00559b94  e847780000           call 0x5613e0
// 00559b99  83c408               add esp, 8
// 00559b9c  8b442424             mov eax, dword ptr [esp + 0x24]
// 00559ba0  83f801               cmp eax, 1
// 00559ba3  7422                 je 0x559bc7
// 00559ba5  83f802               cmp eax, 2
// 00559ba8  741d                 je 0x559bc7
// 00559baa  83f804               cmp eax, 4
// 00559bad  7418                 je 0x559bc7
// 00559baf  83f808               cmp eax, 8
// 00559bb2  7413                 je 0x559bc7
// 00559bb4  83f810               cmp eax, 0x10
// 00559bb7  740e                 je 0x559bc7
// 00559bb9  68b422a800           push 0xa822b4
// 00559bbe  57                   push edi
// 00559bbf  e86c770000           call 0x561330
// 00559bc4  83c408               add esp, 8
// 00559bc7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00559bcb  85db                 test ebx, ebx
// 00559bcd  7c0f                 jl 0x559bde
// 00559bcf  83fb01               cmp ebx, 1
// 00559bd2  740a                 je 0x559bde
// 00559bd4  83fb05               cmp ebx, 5
// 00559bd7  7405                 je 0x559bde
// 00559bd9  83fb06               cmp ebx, 6
// 00559bdc  7e0e                 jle 0x559bec
// 00559bde  689822a800           push 0xa82298
// 00559be3  57                   push edi
// 00559be4  e847770000           call 0x561330
// 00559be9  83c408               add esp, 8
// 00559bec  83fb03               cmp ebx, 3
// 00559bef  7509                 jne 0x559bfa
// 00559bf1  837c242408           cmp dword ptr [esp + 0x24], 8
// 00559bf6  7f18                 jg 0x559c10
// 00559bf8  eb24                 jmp 0x559c1e
// 00559bfa  83fb02               cmp ebx, 2
// 00559bfd  740a                 je 0x559c09
// 00559bff  83fb04               cmp ebx, 4
// 00559c02  7405                 je 0x559c09
// 00559c04  83fb06               cmp ebx, 6
// 00559c07  7515                 jne 0x559c1e
// 00559c09  837c242408           cmp dword ptr [esp + 0x24], 8
// 00559c0e  7d0e                 jge 0x559c1e
// 00559c10  686422a800           push 0xa82264
// 00559c15  57                   push edi
// 00559c16  e815770000           call 0x561330
// 00559c1b  83c408               add esp, 8
// 00559c1e  837c242c02           cmp dword ptr [esp + 0x2c], 2
// 00559c23  7c0e                 jl 0x559c33
// 00559c25  684022a800           push 0xa82240
// 00559c2a  57                   push edi
// 00559c2b  e800770000           call 0x561330
// 00559c30  83c408               add esp, 8
// 00559c33  837c243000           cmp dword ptr [esp + 0x30], 0
// 00559c38  740e                 je 0x559c48
// 00559c3a  681c22a800           push 0xa8221c
// 00559c3f  57                   push edi
// 00559c40  e8eb760000           call 0x561330
// 00559c45  83c408               add esp, 8
// 00559c48  bd00100000           mov ebp, 0x1000
// 00559c4d  856f68               test dword ptr [edi + 0x68], ebp
// 00559c50  7417                 je 0x559c69
// 00559c52  83bf3002000000       cmp dword ptr [edi + 0x230], 0
// 00559c59  740e                 je 0x559c69
// 00559c5b  68681fa800           push 0xa81f68
// 00559c60  57                   push edi
// 00559c61  e87a770000           call 0x5613e0
// 00559c66  83c408               add esp, 8
// 00559c69  8b442434             mov eax, dword ptr [esp + 0x34]
// 00559c6d  85c0                 test eax, eax
// 00559c6f  743e                 je 0x559caf
// 00559c71  f6873002000004       test byte ptr [edi + 0x230], 4
// 00559c78  7414                 je 0x559c8e
// 00559c7a  83f840               cmp eax, 0x40
// 00559c7d  750f                 jne 0x559c8e
// 00559c7f  856f68               test dword ptr [edi + 0x68], ebp
// 00559c82  750a                 jne 0x559c8e
// 00559c84  83fb02               cmp ebx, 2
// 00559c87  7413                 je 0x559c9c
// 00559c89  83fb06               cmp ebx, 6
// 00559c8c  740e                 je 0x559c9c
// 00559c8e  68fc21a800           push 0xa821fc
// 00559c93  57                   push edi
// 00559c94  e897760000           call 0x561330
// 00559c99  83c408               add esp, 8
// 00559c9c  856f68               test dword ptr [edi + 0x68], ebp
// 00559c9f  740e                 je 0x559caf
// 00559ca1  68dc21a800           push 0xa821dc
// 00559ca6  57                   push edi
// 00559ca7  e834770000           call 0x5613e0
// 00559cac  83c408               add esp, 8
// 00559caf  8b442420             mov eax, dword ptr [esp + 0x20]
// 00559cb3  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00559cb7  8a542424             mov dl, byte ptr [esp + 0x24]
// 00559cbb  894604               mov dword ptr [esi + 4], eax
// 00559cbe  8a442430             mov al, byte ptr [esp + 0x30]
// 00559cc2  88461a               mov byte ptr [esi + 0x1a], al
// 00559cc5  8a442434             mov al, byte ptr [esp + 0x34]
// 00559cc9  88461b               mov byte ptr [esi + 0x1b], al
// 00559ccc  8a44242c             mov al, byte ptr [esp + 0x2c]
// 00559cd0  890e                 mov dword ptr [esi], ecx
// 00559cd2  885618               mov byte ptr [esi + 0x18], dl
// 00559cd5  885e19               mov byte ptr [esi + 0x19], bl
// 00559cd8  88461c               mov byte ptr [esi + 0x1c], al
// 00559cdb  80fb03               cmp bl, 3
// 00559cde  740b                 je 0x559ceb
// 00559ce0  f6c302               test bl, 2
// 00559ce3  7406                 je 0x559ceb
// 00559ce5  c6461d03             mov byte ptr [esi + 0x1d], 3
// 00559ce9  eb04                 jmp 0x559cef
// 00559ceb  c6461d01             mov byte ptr [esi + 0x1d], 1
// 00559cef  5d                   pop ebp
// 00559cf0  f6c304               test bl, 4
// 00559cf3  5b                   pop ebx
// 00559cf4  7403                 je 0x559cf9
// 00559cf6  fe461d               inc byte ptr [esi + 0x1d]
// 00559cf9  8a461d               mov al, byte ptr [esi + 0x1d]
// 00559cfc  f6ea                 imul dl
// 00559cfe  88461e               mov byte ptr [esi + 0x1e], al
// 00559d01  81f97effff1f         cmp ecx, 0x1fffff7e
// 00559d07  760a                 jbe 0x559d13
// 00559d09  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00559d10  5e                   pop esi
// 00559d11  5f                   pop edi
// 00559d12  c3                   ret 
// 00559d13  3c08                 cmp al, 8
// 00559d15  0fb6c0               movzx eax, al
// 00559d18  720c                 jb 0x559d26
// 00559d1a  c1e803               shr eax, 3
// 00559d1d  0fafc1               imul eax, ecx
// 00559d20  89460c               mov dword ptr [esi + 0xc], eax
// 00559d23  5e                   pop esi
// 00559d24  5f                   pop edi
// 00559d25  c3                   ret 
// 00559d26  0fafc1               imul eax, ecx
// 00559d29  83c007               add eax, 7
// 00559d2c  c1e803               shr eax, 3
// 00559d2f  89460c               mov dword ptr [esi + 0xc], eax
// 00559d32  5e                   pop esi
// 00559d33  5f                   pop edi
// 00559d34  c3                   ret 
// library libpng-1.2.10/pngset.c (function _png_set_IHDR)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.10 pngset.c
