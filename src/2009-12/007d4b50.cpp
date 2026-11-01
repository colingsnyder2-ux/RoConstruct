// from server: 100% by auto
// roc 2009-12 007d4b50  unit: seg_007d0000  size: 700 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d4b50
//
// 007d4b50  83ec08               sub esp, 8
// 007d4b53  53                   push ebx
// 007d4b54  55                   push ebp
// 007d4b55  56                   push esi
// 007d4b56  8bf0                 mov esi, eax
// 007d4b58  e8b3fbffff           call 0x7d4710
// 007d4b5d  8bd8                 mov ebx, eax
// 007d4b5f  8d4301               lea eax, [ebx + 1]
// 007d4b62  3dffffff3f           cmp eax, 0x3fffffff
// 007d4b67  7719                 ja 0x7d4b82
// 007d4b69  8b16                 mov edx, dword ptr [esi]
// 007d4b6b  8d0c9d00000000       lea ecx, [ebx*4]
// 007d4b72  51                   push ecx
// 007d4b73  6a00                 push 0
// 007d4b75  6a00                 push 0
// 007d4b77  52                   push edx
// 007d4b78  e833ccffff           call 0x7d17b0
// 007d4b7d  83c410               add esp, 0x10
// 007d4b80  eb0b                 jmp 0x7d4b8d
// 007d4b82  8b06                 mov eax, dword ptr [esi]
// 007d4b84  50                   push eax
// 007d4b85  e806ccffff           call 0x7d1790
// 007d4b8a  83c404               add esp, 4
// 007d4b8d  8d0c9d00000000       lea ecx, [ebx*4]
// 007d4b94  51                   push ecx
// 007d4b95  894714               mov dword ptr [edi + 0x14], eax
// 007d4b98  895f30               mov dword ptr [edi + 0x30], ebx
// 007d4b9b  8b5604               mov edx, dword ptr [esi + 4]
// 007d4b9e  50                   push eax
// 007d4b9f  52                   push edx
// 007d4ba0  e8fbc5ffff           call 0x7d11a0
// 007d4ba5  83c40c               add esp, 0xc
// 007d4ba8  85c0                 test eax, eax
// 007d4baa  7423                 je 0x7d4bcf
// 007d4bac  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d4baf  8b0e                 mov ecx, dword ptr [esi]
// 007d4bb1  6858f09e00           push 0x9ef058
// 007d4bb6  50                   push eax
// 007d4bb7  683cf09e00           push 0x9ef03c
// 007d4bbc  51                   push ecx
// 007d4bbd  e8be59fcff           call 0x79a580
// 007d4bc2  8b16                 mov edx, dword ptr [esi]
// 007d4bc4  6a03                 push 3
// 007d4bc6  52                   push edx
// 007d4bc7  e8842cfcff           call 0x797850
// 007d4bcc  83c418               add esp, 0x18
// 007d4bcf  e83cfbffff           call 0x7d4710
// 007d4bd4  8bd8                 mov ebx, eax
// 007d4bd6  8d4301               lea eax, [ebx + 1]
// 007d4bd9  3d55555515           cmp eax, 0x15555555
// 007d4bde  7719                 ja 0x7d4bf9
// 007d4be0  8b16                 mov edx, dword ptr [esi]
// 007d4be2  8d0c5b               lea ecx, [ebx + ebx*2]
// 007d4be5  03c9                 add ecx, ecx
// 007d4be7  03c9                 add ecx, ecx
// 007d4be9  51                   push ecx
// 007d4bea  6a00                 push 0
// 007d4bec  6a00                 push 0
// 007d4bee  52                   push edx
// 007d4bef  e8bccbffff           call 0x7d17b0
// 007d4bf4  83c410               add esp, 0x10
// 007d4bf7  eb0b                 jmp 0x7d4c04
// 007d4bf9  8b06                 mov eax, dword ptr [esi]
// 007d4bfb  50                   push eax
// 007d4bfc  e88fcbffff           call 0x7d1790
// 007d4c01  83c404               add esp, 4
// 007d4c04  894718               mov dword ptr [edi + 0x18], eax
// 007d4c07  895f38               mov dword ptr [edi + 0x38], ebx
// 007d4c0a  85db                 test ebx, ebx
// 007d4c0c  0f8e23010000         jle 0x7d4d35
// 007d4c12  33c0                 xor eax, eax
// 007d4c14  8bcb                 mov ecx, ebx
// 007d4c16  eb08                 jmp 0x7d4c20
// 007d4c18  8da42400000000       lea esp, [esp]
// 007d4c1f  90                   nop 
// 007d4c20  8b5718               mov edx, dword ptr [edi + 0x18]
// 007d4c23  c7041000000000       mov dword ptr [eax + edx], 0
// 007d4c2a  83c00c               add eax, 0xc
// 007d4c2d  83e901               sub ecx, 1
// 007d4c30  75ee                 jne 0x7d4c20
// 007d4c32  85db                 test ebx, ebx
// 007d4c34  0f8efb000000         jle 0x7d4d35
// 007d4c3a  33ed                 xor ebp, ebp
// 007d4c3c  8d642400             lea esp, [esp]
// 007d4c40  e83bfbffff           call 0x7d4780
// 007d4c45  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007d4c48  6a04                 push 4
// 007d4c4a  8d542410             lea edx, [esp + 0x10]
// 007d4c4e  890429               mov dword ptr [ecx + ebp], eax
// 007d4c51  8b4604               mov eax, dword ptr [esi + 4]
// 007d4c54  52                   push edx
// 007d4c55  50                   push eax
// 007d4c56  e845c5ffff           call 0x7d11a0
// 007d4c5b  83c40c               add esp, 0xc
// 007d4c5e  85c0                 test eax, eax
// 007d4c60  7423                 je 0x7d4c85
// 007d4c62  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d4c65  8b16                 mov edx, dword ptr [esi]
// 007d4c67  6858f09e00           push 0x9ef058
// 007d4c6c  51                   push ecx
// 007d4c6d  683cf09e00           push 0x9ef03c
// 007d4c72  52                   push edx
// 007d4c73  e80859fcff           call 0x79a580
// 007d4c78  8b06                 mov eax, dword ptr [esi]
// 007d4c7a  6a03                 push 3
// 007d4c7c  50                   push eax
// 007d4c7d  e8ce2bfcff           call 0x797850
// 007d4c82  83c418               add esp, 0x18
// 007d4c85  837c240c00           cmp dword ptr [esp + 0xc], 0
// 007d4c8a  7d23                 jge 0x7d4caf
// 007d4c8c  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d4c8f  8b16                 mov edx, dword ptr [esi]
// 007d4c91  6868f09e00           push 0x9ef068
// 007d4c96  51                   push ecx
// 007d4c97  683cf09e00           push 0x9ef03c
// 007d4c9c  52                   push edx
// 007d4c9d  e8de58fcff           call 0x79a580
// 007d4ca2  8b06                 mov eax, dword ptr [esi]
// 007d4ca4  6a03                 push 3
// 007d4ca6  50                   push eax
// 007d4ca7  e8a42bfcff           call 0x797850
// 007d4cac  83c418               add esp, 0x18
// 007d4caf  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007d4cb2  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007d4cb6  6a04                 push 4
// 007d4cb8  8d442414             lea eax, [esp + 0x14]
// 007d4cbc  89542904             mov dword ptr [ecx + ebp + 4], edx
// 007d4cc0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d4cc3  50                   push eax
// 007d4cc4  51                   push ecx
// 007d4cc5  e8d6c4ffff           call 0x7d11a0
// 007d4cca  83c40c               add esp, 0xc
// 007d4ccd  85c0                 test eax, eax
// 007d4ccf  7423                 je 0x7d4cf4
// 007d4cd1  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d4cd4  8b06                 mov eax, dword ptr [esi]
// 007d4cd6  6858f09e00           push 0x9ef058
// 007d4cdb  52                   push edx
// 007d4cdc  683cf09e00           push 0x9ef03c
// 007d4ce1  50                   push eax
// 007d4ce2  e89958fcff           call 0x79a580
// 007d4ce7  8b0e                 mov ecx, dword ptr [esi]
// 007d4ce9  6a03                 push 3
// 007d4ceb  51                   push ecx
// 007d4cec  e85f2bfcff           call 0x797850
// 007d4cf1  83c418               add esp, 0x18
// 007d4cf4  837c241000           cmp dword ptr [esp + 0x10], 0
// 007d4cf9  7d23                 jge 0x7d4d1e
// 007d4cfb  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d4cfe  8b06                 mov eax, dword ptr [esi]
// 007d4d00  6868f09e00           push 0x9ef068
// 007d4d05  52                   push edx
// 007d4d06  683cf09e00           push 0x9ef03c
// 007d4d0b  50                   push eax
// 007d4d0c  e86f58fcff           call 0x79a580
// 007d4d11  8b0e                 mov ecx, dword ptr [esi]
// 007d4d13  6a03                 push 3
// 007d4d15  51                   push ecx
// 007d4d16  e8352bfcff           call 0x797850
// 007d4d1b  83c418               add esp, 0x18
// 007d4d1e  8b5718               mov edx, dword ptr [edi + 0x18]
// 007d4d21  8b442410             mov eax, dword ptr [esp + 0x10]
// 007d4d25  89442a08             mov dword ptr [edx + ebp + 8], eax
// 007d4d29  83c50c               add ebp, 0xc
// 007d4d2c  83eb01               sub ebx, 1
// 007d4d2f  0f850bffffff         jne 0x7d4c40
// 007d4d35  8b5604               mov edx, dword ptr [esi + 4]
// 007d4d38  6a04                 push 4
// 007d4d3a  8d4c2414             lea ecx, [esp + 0x14]
// 007d4d3e  51                   push ecx
// 007d4d3f  52                   push edx
// 007d4d40  e85bc4ffff           call 0x7d11a0
// 007d4d45  83c40c               add esp, 0xc
// 007d4d48  85c0                 test eax, eax
// 007d4d4a  7423                 je 0x7d4d6f
// 007d4d4c  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d4d4f  8b0e                 mov ecx, dword ptr [esi]
// 007d4d51  6858f09e00           push 0x9ef058
// 007d4d56  50                   push eax
// 007d4d57  683cf09e00           push 0x9ef03c
// 007d4d5c  51                   push ecx
// 007d4d5d  e81e58fcff           call 0x79a580
// 007d4d62  8b16                 mov edx, dword ptr [esi]
// 007d4d64  6a03                 push 3
// 007d4d66  52                   push edx
// 007d4d67  e8e42afcff           call 0x797850
// 007d4d6c  83c418               add esp, 0x18
// 007d4d6f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007d4d73  85db                 test ebx, ebx
// 007d4d75  7d27                 jge 0x7d4d9e
// 007d4d77  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d4d7a  8b0e                 mov ecx, dword ptr [esi]
// 007d4d7c  6868f09e00           push 0x9ef068
// 007d4d81  50                   push eax
// 007d4d82  683cf09e00           push 0x9ef03c
// 007d4d87  51                   push ecx
// 007d4d88  e8f357fcff           call 0x79a580
// 007d4d8d  8b16                 mov edx, dword ptr [esi]
// 007d4d8f  6a03                 push 3
// 007d4d91  52                   push edx
// 007d4d92  e8b92afcff           call 0x797850
// 007d4d97  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 007d4d9b  83c418               add esp, 0x18
// 007d4d9e  8d4301               lea eax, [ebx + 1]
// 007d4da1  3dffffff3f           cmp eax, 0x3fffffff
// 007d4da6  7719                 ja 0x7d4dc1
// 007d4da8  8b16                 mov edx, dword ptr [esi]
// 007d4daa  8d0c9d00000000       lea ecx, [ebx*4]
// 007d4db1  51                   push ecx
// 007d4db2  6a00                 push 0
// 007d4db4  6a00                 push 0
// 007d4db6  52                   push edx
// 007d4db7  e8f4c9ffff           call 0x7d17b0
// 007d4dbc  83c410               add esp, 0x10
// 007d4dbf  eb0b                 jmp 0x7d4dcc
// 007d4dc1  8b06                 mov eax, dword ptr [esi]
// 007d4dc3  50                   push eax
// 007d4dc4  e8c7c9ffff           call 0x7d1790
// 007d4dc9  83c404               add esp, 4
// 007d4dcc  89471c               mov dword ptr [edi + 0x1c], eax
// 007d4dcf  33c0                 xor eax, eax
// 007d4dd1  895f24               mov dword ptr [edi + 0x24], ebx
// 007d4dd4  85db                 test ebx, ebx
// 007d4dd6  7e17                 jle 0x7d4def
// 007d4dd8  eb06                 jmp 0x7d4de0
// 007d4dda  8d9b00000000         lea ebx, [ebx]
// 007d4de0  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 007d4de3  c7048100000000       mov dword ptr [ecx + eax*4], 0
// 007d4dea  40                   inc eax
// 007d4deb  3bc3                 cmp eax, ebx
// 007d4ded  7cf1                 jl 0x7d4de0
// 007d4def  33ed                 xor ebp, ebp
// 007d4df1  85db                 test ebx, ebx
// 007d4df3  7e10                 jle 0x7d4e05
// 007d4df5  e886f9ffff           call 0x7d4780
// 007d4dfa  8b571c               mov edx, dword ptr [edi + 0x1c]
// 007d4dfd  8904aa               mov dword ptr [edx + ebp*4], eax
// 007d4e00  45                   inc ebp
// 007d4e01  3beb                 cmp ebp, ebx
// 007d4e03  7cf0                 jl 0x7d4df5
// 007d4e05  5e                   pop esi
// 007d4e06  5d                   pop ebp
// 007d4e07  5b                   pop ebx
// 007d4e08  83c408               add esp, 8
// 007d4e0b  c3                   ret 
// library lua-5.1/lundump.c (function _LoadDebug)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lundump.c
