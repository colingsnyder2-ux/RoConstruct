// from server: 100% by auto
// roc 2007-08 00616b10  unit: seg_00610000  size: 672 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00616b10
//
// 00616b10  83ec10               sub esp, 0x10
// 00616b13  53                   push ebx
// 00616b14  55                   push ebp
// 00616b15  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00616b19  56                   push esi
// 00616b1a  57                   push edi
// 00616b1b  8bf0                 mov esi, eax
// 00616b1d  e84efeffff           call 0x616970
// 00616b22  8bf8                 mov edi, eax
// 00616b24  8d4701               lea eax, [edi + 1]
// 00616b27  3dffffff0f           cmp eax, 0xfffffff
// 00616b2c  7717                 ja 0x616b45
// 00616b2e  8b16                 mov edx, dword ptr [esi]
// 00616b30  8bcf                 mov ecx, edi
// 00616b32  c1e104               shl ecx, 4
// 00616b35  51                   push ecx
// 00616b36  6a00                 push 0
// 00616b38  6a00                 push 0
// 00616b3a  52                   push edx
// 00616b3b  e8b0ceffff           call 0x6139f0
// 00616b40  83c410               add esp, 0x10
// 00616b43  eb0b                 jmp 0x616b50
// 00616b45  8b06                 mov eax, dword ptr [esi]
// 00616b47  50                   push eax
// 00616b48  e883ceffff           call 0x6139d0
// 00616b4d  83c404               add esp, 4
// 00616b50  33db                 xor ebx, ebx
// 00616b52  3bfb                 cmp edi, ebx
// 00616b54  894508               mov dword ptr [ebp + 8], eax
// 00616b57  897d28               mov dword ptr [ebp + 0x28], edi
// 00616b5a  0f8e54010000         jle 0x616cb4
// 00616b60  33c0                 xor eax, eax
// 00616b62  8bcf                 mov ecx, edi
// 00616b64  8b5508               mov edx, dword ptr [ebp + 8]
// 00616b67  895c1008             mov dword ptr [eax + edx + 8], ebx
// 00616b6b  83c010               add eax, 0x10
// 00616b6e  83e901               sub ecx, 1
// 00616b71  75f1                 jne 0x616b64
// 00616b73  3bfb                 cmp edi, ebx
// 00616b75  0f8e39010000         jle 0x616cb4
// 00616b7b  897c2414             mov dword ptr [esp + 0x14], edi
// 00616b7f  90                   nop 
// 00616b80  8b4e04               mov ecx, dword ptr [esi + 4]
// 00616b83  8b7d08               mov edi, dword ptr [ebp + 8]
// 00616b86  6a01                 push 1
// 00616b88  8d442428             lea eax, [esp + 0x28]
// 00616b8c  50                   push eax
// 00616b8d  51                   push ecx
// 00616b8e  03fb                 add edi, ebx
// 00616b90  e82bc8ffff           call 0x6133c0
// 00616b95  83c40c               add esp, 0xc
// 00616b98  85c0                 test eax, eax
// 00616b9a  7423                 je 0x616bbf
// 00616b9c  8b560c               mov edx, dword ptr [esi + 0xc]
// 00616b9f  8b06                 mov eax, dword ptr [esi]
// 00616ba1  68e0357c00           push 0x7c35e0
// 00616ba6  52                   push edx
// 00616ba7  68c4357c00           push 0x7c35c4
// 00616bac  50                   push eax
// 00616bad  e8de82ffff           call 0x60ee90
// 00616bb2  8b0e                 mov ecx, dword ptr [esi]
// 00616bb4  6a03                 push 3
// 00616bb6  51                   push ecx
// 00616bb7  e864f4faff           call 0x5c6020
// 00616bbc  83c418               add esp, 0x18
// 00616bbf  0fbe442424           movsx eax, byte ptr [esp + 0x24]
// 00616bc4  83f804               cmp eax, 4
// 00616bc7  0f87b6000000         ja 0x616c83
// 00616bcd  ff24859c6d6100       jmp dword ptr [eax*4 + 0x616d9c]
// 00616bd4  c7470800000000       mov dword ptr [edi + 8], 0
// 00616bdb  e9c6000000           jmp 0x616ca6
// 00616be0  8b4604               mov eax, dword ptr [esi + 4]
// 00616be3  6a01                 push 1
// 00616be5  8d542417             lea edx, [esp + 0x17]
// 00616be9  52                   push edx
// 00616bea  50                   push eax
// 00616beb  e8d0c7ffff           call 0x6133c0
// 00616bf0  83c40c               add esp, 0xc
// 00616bf3  85c0                 test eax, eax
// 00616bf5  7423                 je 0x616c1a
// 00616bf7  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00616bfa  8b16                 mov edx, dword ptr [esi]
// 00616bfc  68e0357c00           push 0x7c35e0
// 00616c01  51                   push ecx
// 00616c02  68c4357c00           push 0x7c35c4
// 00616c07  52                   push edx
// 00616c08  e88382ffff           call 0x60ee90
// 00616c0d  8b06                 mov eax, dword ptr [esi]
// 00616c0f  6a03                 push 3
// 00616c11  50                   push eax
// 00616c12  e809f4faff           call 0x5c6020
// 00616c17  83c418               add esp, 0x18
// 00616c1a  0fbe4c2413           movsx ecx, byte ptr [esp + 0x13]
// 00616c1f  890f                 mov dword ptr [edi], ecx
// 00616c21  c7470801000000       mov dword ptr [edi + 8], 1
// 00616c28  eb7c                 jmp 0x616ca6
// 00616c2a  8b4604               mov eax, dword ptr [esi + 4]
// 00616c2d  6a08                 push 8
// 00616c2f  8d54241c             lea edx, [esp + 0x1c]
// 00616c33  52                   push edx
// 00616c34  50                   push eax
// 00616c35  e886c7ffff           call 0x6133c0
// 00616c3a  83c40c               add esp, 0xc
// 00616c3d  85c0                 test eax, eax
// 00616c3f  7423                 je 0x616c64
// 00616c41  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00616c44  8b16                 mov edx, dword ptr [esi]
// 00616c46  68e0357c00           push 0x7c35e0
// 00616c4b  51                   push ecx
// 00616c4c  68c4357c00           push 0x7c35c4
// 00616c51  52                   push edx
// 00616c52  e83982ffff           call 0x60ee90
// 00616c57  8b06                 mov eax, dword ptr [esi]
// 00616c59  6a03                 push 3
// 00616c5b  50                   push eax
// 00616c5c  e8bff3faff           call 0x5c6020
// 00616c61  83c418               add esp, 0x18
// 00616c64  dd442418             fld qword ptr [esp + 0x18]
// 00616c68  c7470803000000       mov dword ptr [edi + 8], 3
// 00616c6f  dd1f                 fstp qword ptr [edi]
// 00616c71  eb33                 jmp 0x616ca6
// 00616c73  e868fdffff           call 0x6169e0
// 00616c78  8907                 mov dword ptr [edi], eax
// 00616c7a  c7470804000000       mov dword ptr [edi + 8], 4
// 00616c81  eb23                 jmp 0x616ca6
// 00616c83  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00616c86  8b16                 mov edx, dword ptr [esi]
// 00616c88  68fc357c00           push 0x7c35fc
// 00616c8d  51                   push ecx
// 00616c8e  68c4357c00           push 0x7c35c4
// 00616c93  52                   push edx
// 00616c94  e8f781ffff           call 0x60ee90
// 00616c99  8b06                 mov eax, dword ptr [esi]
// 00616c9b  6a03                 push 3
// 00616c9d  50                   push eax
// 00616c9e  e87df3faff           call 0x5c6020
// 00616ca3  83c418               add esp, 0x18
// 00616ca6  83c310               add ebx, 0x10
// 00616ca9  836c241401           sub dword ptr [esp + 0x14], 1
// 00616cae  0f85ccfeffff         jne 0x616b80
// 00616cb4  8b5604               mov edx, dword ptr [esi + 4]
// 00616cb7  6a04                 push 4
// 00616cb9  8d4c2428             lea ecx, [esp + 0x28]
// 00616cbd  51                   push ecx
// 00616cbe  52                   push edx
// 00616cbf  e8fcc6ffff           call 0x6133c0
// 00616cc4  83c40c               add esp, 0xc
// 00616cc7  85c0                 test eax, eax
// 00616cc9  7423                 je 0x616cee
// 00616ccb  8b460c               mov eax, dword ptr [esi + 0xc]
// 00616cce  8b0e                 mov ecx, dword ptr [esi]
// 00616cd0  68e0357c00           push 0x7c35e0
// 00616cd5  50                   push eax
// 00616cd6  68c4357c00           push 0x7c35c4
// 00616cdb  51                   push ecx
// 00616cdc  e8af81ffff           call 0x60ee90
// 00616ce1  8b16                 mov edx, dword ptr [esi]
// 00616ce3  6a03                 push 3
// 00616ce5  52                   push edx
// 00616ce6  e835f3faff           call 0x5c6020
// 00616ceb  83c418               add esp, 0x18
// 00616cee  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00616cf2  85ff                 test edi, edi
// 00616cf4  7d27                 jge 0x616d1d
// 00616cf6  8b460c               mov eax, dword ptr [esi + 0xc]
// 00616cf9  8b0e                 mov ecx, dword ptr [esi]
// 00616cfb  68f0357c00           push 0x7c35f0
// 00616d00  50                   push eax
// 00616d01  68c4357c00           push 0x7c35c4
// 00616d06  51                   push ecx
// 00616d07  e88481ffff           call 0x60ee90
// 00616d0c  8b16                 mov edx, dword ptr [esi]
// 00616d0e  6a03                 push 3
// 00616d10  52                   push edx
// 00616d11  e80af3faff           call 0x5c6020
// 00616d16  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 00616d1a  83c418               add esp, 0x18
// 00616d1d  8d4701               lea eax, [edi + 1]
// 00616d20  3dffffff3f           cmp eax, 0x3fffffff
// 00616d25  7719                 ja 0x616d40
// 00616d27  8b16                 mov edx, dword ptr [esi]
// 00616d29  8d0cbd00000000       lea ecx, [edi*4]
// 00616d30  51                   push ecx
// 00616d31  6a00                 push 0
// 00616d33  6a00                 push 0
// 00616d35  52                   push edx
// 00616d36  e8b5ccffff           call 0x6139f0
// 00616d3b  83c410               add esp, 0x10
// 00616d3e  eb0b                 jmp 0x616d4b
// 00616d40  8b06                 mov eax, dword ptr [esi]
// 00616d42  50                   push eax
// 00616d43  e888ccffff           call 0x6139d0
// 00616d48  83c404               add esp, 4
// 00616d4b  894510               mov dword ptr [ebp + 0x10], eax
// 00616d4e  33c0                 xor eax, eax
// 00616d50  85ff                 test edi, edi
// 00616d52  897d34               mov dword ptr [ebp + 0x34], edi
// 00616d55  7e1a                 jle 0x616d71
// 00616d57  eb07                 jmp 0x616d60
// 00616d59  8da42400000000       lea esp, [esp]
// 00616d60  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00616d63  c7048100000000       mov dword ptr [ecx + eax*4], 0
// 00616d6a  83c001               add eax, 1
// 00616d6d  3bc7                 cmp eax, edi
// 00616d6f  7cef                 jl 0x616d60
// 00616d71  33db                 xor ebx, ebx
// 00616d73  85ff                 test edi, edi
// 00616d75  7e1a                 jle 0x616d91
// 00616d77  8b5520               mov edx, dword ptr [ebp + 0x20]
// 00616d7a  52                   push edx
// 00616d7b  56                   push esi
// 00616d7c  e8ef020000           call 0x617070
// 00616d81  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00616d84  890499               mov dword ptr [ecx + ebx*4], eax
// 00616d87  83c301               add ebx, 1
// 00616d8a  83c408               add esp, 8
// 00616d8d  3bdf                 cmp ebx, edi
// 00616d8f  7ce6                 jl 0x616d77
// 00616d91  5f                   pop edi
// 00616d92  5e                   pop esi
// 00616d93  5d                   pop ebp
// 00616d94  5b                   pop ebx
// 00616d95  83c410               add esp, 0x10
// 00616d98  c3                   ret 
// 00616d99  8d4900               lea ecx, [ecx]
// 00616d9c  d46b                 aam 0x6b
// 00616d9e  61                   popal 
// 00616d9f  00e0                 add al, ah
// 00616da1  6b610083             imul esp, dword ptr [ecx], -0x7d
// 00616da5  6c                   insb byte ptr es:[edi], dx
// 00616da6  61                   popal 
// 00616da7  002a                 add byte ptr [edx], ch
// 00616da9  6c                   insb byte ptr es:[edi], dx
// 00616daa  61                   popal 
// 00616dab  00736c               add byte ptr [ebx + 0x6c], dh
// 00616dae  61                   popal 
// library lua-5.1/lundump.c (function _LoadConstants)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
