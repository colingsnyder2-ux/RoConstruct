// from server: 100% by auto
// roc 2008-06 004c0ba0  unit: ProfiledRakPeer  size: 672 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c0ba0
//
// 004c0ba0  55                   push ebp
// 004c0ba1  8bec                 mov ebp, esp
// 004c0ba3  83ec68               sub esp, 0x68
// 004c0ba6  53                   push ebx
// 004c0ba7  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004c0baa  56                   push esi
// 004c0bab  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004c0bae  33c0                 xor eax, eax
// 004c0bb0  57                   push edi
// 004c0bb1  8945dc               mov dword ptr [ebp - 0x24], eax
// 004c0bb4  8945e0               mov dword ptr [ebp - 0x20], eax
// 004c0bb7  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004c0bba  8d4598               lea eax, [ebp - 0x68]
// 004c0bbd  50                   push eax
// 004c0bbe  8d4db8               lea ecx, [ebp - 0x48]
// 004c0bc1  51                   push ecx
// 004c0bc2  53                   push ebx
// 004c0bc3  56                   push esi
// 004c0bc4  c745d801000000       mov dword ptr [ebp - 0x28], 1
// 004c0bcb  e8e0dcffff           call 0x4be8b0
// 004c0bd0  8b16                 mov edx, dword ptr [esi]
// 004c0bd2  8b4604               mov eax, dword ptr [esi + 4]
// 004c0bd5  8b4e08               mov ecx, dword ptr [esi + 8]
// 004c0bd8  8955e8               mov dword ptr [ebp - 0x18], edx
// 004c0bdb  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c0bde  8945ec               mov dword ptr [ebp - 0x14], eax
// 004c0be1  894df0               mov dword ptr [ebp - 0x10], ecx
// 004c0be4  8d45b8               lea eax, [ebp - 0x48]
// 004c0be7  8d4de8               lea ecx, [ebp - 0x18]
// 004c0bea  83c410               add esp, 0x10
// 004c0bed  8955f4               mov dword ptr [ebp - 0xc], edx
// 004c0bf0  8945f8               mov dword ptr [ebp - 8], eax
// 004c0bf3  894dfc               mov dword ptr [ebp - 4], ecx
// 004c0bf6  c7450800000000       mov dword ptr [ebp + 8], 0
// 004c0bfd  8b75f8               mov esi, dword ptr [ebp - 8]
// 004c0c00  8b7dfc               mov edi, dword ptr [ebp - 4]
// 004c0c03  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004c0c06  8b06                 mov eax, dword ptr [esi]
// 004c0c08  33d2                 xor edx, edx
// 004c0c0a  2907                 sub dword ptr [edi], eax
// 004c0c0c  8b4604               mov eax, dword ptr [esi + 4]
// 004c0c0f  194704               sbb dword ptr [edi + 4], eax
// 004c0c12  8b4608               mov eax, dword ptr [esi + 8]
// 004c0c15  194708               sbb dword ptr [edi + 8], eax
// 004c0c18  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c0c1b  19470c               sbb dword ptr [edi + 0xc], eax
// 004c0c1e  e322                 jecxz 0x4c0c42
// 004c0c20  42                   inc edx
// 004c0c21  42                   inc edx
// 004c0c22  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004c0c25  1904d7               sbb dword ptr [edi + edx*8], eax
// 004c0c28  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004c0c2c  1944d704             sbb dword ptr [edi + edx*8 + 4], eax
// 004c0c30  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004c0c34  1944d708             sbb dword ptr [edi + edx*8 + 8], eax
// 004c0c38  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004c0c3c  1944d70c             sbb dword ptr [edi + edx*8 + 0xc], eax
// 004c0c40  e2de                 loop 0x4c0c20
// 004c0c42  8b13                 mov edx, dword ptr [ebx]
// 004c0c44  8b4304               mov eax, dword ptr [ebx + 4]
// 004c0c47  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004c0c4a  8955c8               mov dword ptr [ebp - 0x38], edx
// 004c0c4d  8b530c               mov edx, dword ptr [ebx + 0xc]
// 004c0c50  8945cc               mov dword ptr [ebp - 0x34], eax
// 004c0c53  894dd0               mov dword ptr [ebp - 0x30], ecx
// 004c0c56  8955d4               mov dword ptr [ebp - 0x2c], edx
// 004c0c59  8da42400000000       lea esp, [esp]
// 004c0c60  8d45c8               lea eax, [ebp - 0x38]
// 004c0c63  50                   push eax
// 004c0c64  8d4db8               lea ecx, [ebp - 0x48]
// 004c0c67  51                   push ecx
// 004c0c68  8d5598               lea edx, [ebp - 0x68]
// 004c0c6b  52                   push edx
// 004c0c6c  50                   push eax
// 004c0c6d  e83edcffff           call 0x4be8b0
// 004c0c72  83c410               add esp, 0x10
// 004c0c75  33c0                 xor eax, eax
// 004c0c77  837c85c800           cmp dword ptr [ebp + eax*4 - 0x38], 0
// 004c0c7c  7527                 jne 0x4c0ca5
// 004c0c7e  40                   inc eax
// 004c0c7f  83f804               cmp eax, 4
// 004c0c82  72f3                 jb 0x4c0c77
// 004c0c84  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c0c87  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004c0c8a  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004c0c8d  8908                 mov dword ptr [eax], ecx
// 004c0c8f  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004c0c92  895004               mov dword ptr [eax + 4], edx
// 004c0c95  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004c0c98  5f                   pop edi
// 004c0c99  5e                   pop esi
// 004c0c9a  894808               mov dword ptr [eax + 8], ecx
// 004c0c9d  89500c               mov dword ptr [eax + 0xc], edx
// 004c0ca0  5b                   pop ebx
// 004c0ca1  8be5                 mov esp, ebp
// 004c0ca3  5d                   pop ebp
// 004c0ca4  c3                   ret 
// 004c0ca5  8b750c               mov esi, dword ptr [ebp + 0xc]
// 004c0ca8  8d4da8               lea ecx, [ebp - 0x58]
// 004c0cab  51                   push ecx
// 004c0cac  56                   push esi
// 004c0cad  8d55d8               lea edx, [ebp - 0x28]
// 004c0cb0  52                   push edx
// 004c0cb1  8d45b8               lea eax, [ebp - 0x48]
// 004c0cb4  50                   push eax
// 004c0cb5  8d4de8               lea ecx, [ebp - 0x18]
// 004c0cb8  51                   push ecx
// 004c0cb9  e8c2deffff           call 0x4beb80
// 004c0cbe  8d5598               lea edx, [ebp - 0x68]
// 004c0cc1  52                   push edx
// 004c0cc2  8d45b8               lea eax, [ebp - 0x48]
// 004c0cc5  50                   push eax
// 004c0cc6  8d4dc8               lea ecx, [ebp - 0x38]
// 004c0cc9  51                   push ecx
// 004c0cca  52                   push edx
// 004c0ccb  e8e0dbffff           call 0x4be8b0
// 004c0cd0  83c424               add esp, 0x24
// 004c0cd3  33c0                 xor eax, eax
// 004c0cd5  837c859800           cmp dword ptr [ebp + eax*4 - 0x68], 0
// 004c0cda  7527                 jne 0x4c0d03
// 004c0cdc  40                   inc eax
// 004c0cdd  83f804               cmp eax, 4
// 004c0ce0  72f3                 jb 0x4c0cd5
// 004c0ce2  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c0ce5  8b4da8               mov ecx, dword ptr [ebp - 0x58]
// 004c0ce8  8b55ac               mov edx, dword ptr [ebp - 0x54]
// 004c0ceb  8908                 mov dword ptr [eax], ecx
// 004c0ced  8b4db0               mov ecx, dword ptr [ebp - 0x50]
// 004c0cf0  895004               mov dword ptr [eax + 4], edx
// 004c0cf3  8b55b4               mov edx, dword ptr [ebp - 0x4c]
// 004c0cf6  5f                   pop edi
// 004c0cf7  5e                   pop esi
// 004c0cf8  894808               mov dword ptr [eax + 8], ecx
// 004c0cfb  89500c               mov dword ptr [eax + 0xc], edx
// 004c0cfe  5b                   pop ebx
// 004c0cff  8be5                 mov esp, ebp
// 004c0d01  5d                   pop ebp
// 004c0d02  c3                   ret 
// 004c0d03  8d45d8               lea eax, [ebp - 0x28]
// 004c0d06  50                   push eax
// 004c0d07  56                   push esi
// 004c0d08  8d4de8               lea ecx, [ebp - 0x18]
// 004c0d0b  51                   push ecx
// 004c0d0c  8d55b8               lea edx, [ebp - 0x48]
// 004c0d0f  52                   push edx
// 004c0d10  8d45a8               lea eax, [ebp - 0x58]
// 004c0d13  50                   push eax
// 004c0d14  e867deffff           call 0x4beb80
// 004c0d19  8d4dc8               lea ecx, [ebp - 0x38]
// 004c0d1c  51                   push ecx
// 004c0d1d  8d55b8               lea edx, [ebp - 0x48]
// 004c0d20  52                   push edx
// 004c0d21  8d4598               lea eax, [ebp - 0x68]
// 004c0d24  50                   push eax
// 004c0d25  51                   push ecx
// 004c0d26  e885dbffff           call 0x4be8b0
// 004c0d2b  83c424               add esp, 0x24
// 004c0d2e  33c0                 xor eax, eax
// 004c0d30  837c85c800           cmp dword ptr [ebp + eax*4 - 0x38], 0
// 004c0d35  7527                 jne 0x4c0d5e
// 004c0d37  40                   inc eax
// 004c0d38  83f804               cmp eax, 4
// 004c0d3b  72f3                 jb 0x4c0d30
// 004c0d3d  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004c0d40  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 004c0d43  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 004c0d46  8908                 mov dword ptr [eax], ecx
// 004c0d48  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 004c0d4b  895004               mov dword ptr [eax + 4], edx
// 004c0d4e  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 004c0d51  5f                   pop edi
// 004c0d52  5e                   pop esi
// 004c0d53  894808               mov dword ptr [eax + 8], ecx
// 004c0d56  89500c               mov dword ptr [eax + 0xc], edx
// 004c0d59  5b                   pop ebx
// 004c0d5a  8be5                 mov esp, ebp
// 004c0d5c  5d                   pop ebp
// 004c0d5d  c3                   ret 
// 004c0d5e  8d55e8               lea edx, [ebp - 0x18]
// 004c0d61  52                   push edx
// 004c0d62  56                   push esi
// 004c0d63  8d45a8               lea eax, [ebp - 0x58]
// 004c0d66  50                   push eax
// 004c0d67  8d4db8               lea ecx, [ebp - 0x48]
// 004c0d6a  51                   push ecx
// 004c0d6b  8d55d8               lea edx, [ebp - 0x28]
// 004c0d6e  52                   push edx
// 004c0d6f  e80cdeffff           call 0x4beb80
// 004c0d74  8d4598               lea eax, [ebp - 0x68]
// 004c0d77  50                   push eax
// 004c0d78  8d4db8               lea ecx, [ebp - 0x48]
// 004c0d7b  51                   push ecx
// 004c0d7c  8d55c8               lea edx, [ebp - 0x38]
// 004c0d7f  52                   push edx
// 004c0d80  50                   push eax
// 004c0d81  e82adbffff           call 0x4be8b0
// 004c0d86  83c424               add esp, 0x24
// 004c0d89  33c0                 xor eax, eax
// 004c0d8b  eb03                 jmp 0x4c0d90
// 004c0d8d  8d4900               lea ecx, [ecx]
// 004c0d90  837c859800           cmp dword ptr [ebp + eax*4 - 0x68], 0
// 004c0d95  750b                 jne 0x4c0da2
// 004c0d97  40                   inc eax
// 004c0d98  83f804               cmp eax, 4
// 004c0d9b  72f3                 jb 0x4c0d90
// 004c0d9d  e9e2feffff           jmp 0x4c0c84
// 004c0da2  8d4da8               lea ecx, [ebp - 0x58]
// 004c0da5  51                   push ecx
// 004c0da6  56                   push esi
// 004c0da7  8d55d8               lea edx, [ebp - 0x28]
// 004c0daa  52                   push edx
// 004c0dab  8d45b8               lea eax, [ebp - 0x48]
// 004c0dae  50                   push eax
// 004c0daf  8d4de8               lea ecx, [ebp - 0x18]
// 004c0db2  51                   push ecx
// 004c0db3  e8c8ddffff           call 0x4beb80
// 004c0db8  8d55c8               lea edx, [ebp - 0x38]
// 004c0dbb  52                   push edx
// 004c0dbc  8d45b8               lea eax, [ebp - 0x48]
// 004c0dbf  50                   push eax
// 004c0dc0  8d4d98               lea ecx, [ebp - 0x68]
// 004c0dc3  51                   push ecx
// 004c0dc4  52                   push edx
// 004c0dc5  e8e6daffff           call 0x4be8b0
// 004c0dca  83c424               add esp, 0x24
// 004c0dcd  33c0                 xor eax, eax
// 004c0dcf  90                   nop 
// 004c0dd0  837c85c800           cmp dword ptr [ebp + eax*4 - 0x38], 0
// 004c0dd5  750b                 jne 0x4c0de2
// 004c0dd7  40                   inc eax
// 004c0dd8  83f804               cmp eax, 4
// 004c0ddb  72f3                 jb 0x4c0dd0
// 004c0ddd  e900ffffff           jmp 0x4c0ce2
// 004c0de2  8d45d8               lea eax, [ebp - 0x28]
// 004c0de5  50                   push eax
// 004c0de6  56                   push esi
// 004c0de7  8d4de8               lea ecx, [ebp - 0x18]
// 004c0dea  51                   push ecx
// 004c0deb  8d55b8               lea edx, [ebp - 0x48]
// 004c0dee  52                   push edx
// 004c0def  8d45a8               lea eax, [ebp - 0x58]
// 004c0df2  50                   push eax
// 004c0df3  e888ddffff           call 0x4beb80
// 004c0df8  8d4d98               lea ecx, [ebp - 0x68]
// 004c0dfb  51                   push ecx
// 004c0dfc  8d55b8               lea edx, [ebp - 0x48]
// 004c0dff  52                   push edx
// 004c0e00  8d45c8               lea eax, [ebp - 0x38]
// 004c0e03  50                   push eax
// 004c0e04  51                   push ecx
// 004c0e05  e8a6daffff           call 0x4be8b0
// 004c0e0a  83c424               add esp, 0x24
// 004c0e0d  33c0                 xor eax, eax
// 004c0e0f  90                   nop 
// 004c0e10  837c859800           cmp dword ptr [ebp + eax*4 - 0x68], 0
// 004c0e15  750b                 jne 0x4c0e22
// 004c0e17  40                   inc eax
// 004c0e18  83f804               cmp eax, 4
// 004c0e1b  72f3                 jb 0x4c0e10
// 004c0e1d  e91bffffff           jmp 0x4c0d3d
// 004c0e22  8d55e8               lea edx, [ebp - 0x18]
// 004c0e25  52                   push edx
// 004c0e26  56                   push esi
// 004c0e27  8d45a8               lea eax, [ebp - 0x58]
// 004c0e2a  50                   push eax
// 004c0e2b  8d4db8               lea ecx, [ebp - 0x48]
// 004c0e2e  51                   push ecx
// 004c0e2f  8d55d8               lea edx, [ebp - 0x28]
// 004c0e32  52                   push edx
// 004c0e33  e848ddffff           call 0x4beb80
// 004c0e38  83c414               add esp, 0x14
// 004c0e3b  e920feffff           jmp 0x4c0c60
// library openrbx-raknet/RakPeer.cpp (function ??$computeModularInverse@$$BY03I@big@@YAXAAY03I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
