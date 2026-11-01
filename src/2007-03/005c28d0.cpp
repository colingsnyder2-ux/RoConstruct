// from server: 100% by auto
// roc 2007-03 005c28d0  unit: seg_005c0000  size: 1128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c28d0
//
// 005c28d0  83ec20               sub esp, 0x20
// 005c28d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005c28d7  8b482c               mov ecx, dword ptr [eax + 0x2c]
// 005c28da  53                   push ebx
// 005c28db  8a584b               mov bl, byte ptr [eax + 0x4b]
// 005c28de  80fbfa               cmp bl, 0xfa
// 005c28e1  8d51ff               lea edx, [ecx - 1]
// 005c28e4  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005c28e8  89542418             mov dword ptr [esp + 0x18], edx
// 005c28ec  885c2407             mov byte ptr [esp + 7], bl
// 005c28f0  772b                 ja 0x5c291d
// 005c28f2  0fb65048             movzx edx, byte ptr [eax + 0x48]
// 005c28f6  395024               cmp dword ptr [eax + 0x24], edx
// 005c28f9  89542420             mov dword ptr [esp + 0x20], edx
// 005c28fd  7f1e                 jg 0x5c291d
// 005c28ff  8b5030               mov edx, dword ptr [eax + 0x30]
// 005c2902  3bd1                 cmp edx, ecx
// 005c2904  7404                 je 0x5c290a
// 005c2906  85d2                 test edx, edx
// 005c2908  7513                 jne 0x5c291d
// 005c290a  8b400c               mov eax, dword ptr [eax + 0xc]
// 005c290d  8b4c88fc             mov ecx, dword ptr [eax + ecx*4 - 4]
// 005c2911  83e13f               and ecx, 0x3f
// 005c2914  80f91e               cmp cl, 0x1e
// 005c2917  89442410             mov dword ptr [esp + 0x10], eax
// 005c291b  7407                 je 0x5c2924
// 005c291d  33c0                 xor eax, eax
// 005c291f  5b                   pop ebx
// 005c2920  83c420               add esp, 0x20
// 005c2923  c3                   ret 
// 005c2924  837c242c00           cmp dword ptr [esp + 0x2c], 0
// 005c2929  55                   push ebp
// 005c292a  56                   push esi
// 005c292b  57                   push edi
// 005c292c  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005c2934  7f1e                 jg 0x5c2954
// 005c2936  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c293a  8b0488               mov eax, dword ptr [eax + ecx*4]
// 005c293d  5f                   pop edi
// 005c293e  5e                   pop esi
// 005c293f  5d                   pop ebp
// 005c2940  5b                   pop ebx
// 005c2941  83c420               add esp, 0x20
// 005c2944  c3                   ret 
// 005c2945  eb09                 jmp 0x5c2950
// 005c2947  8da42400000000       lea esp, [esp]
// 005c294e  8bff                 mov edi, edi
// 005c2950  8a5c2413             mov bl, byte ptr [esp + 0x13]
// 005c2954  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c2958  8b442420             mov eax, dword ptr [esp + 0x20]
// 005c295c  8b0482               mov eax, dword ptr [edx + eax*4]
// 005c295f  8bf8                 mov edi, eax
// 005c2961  8be8                 mov ebp, eax
// 005c2963  c1ef06               shr edi, 6
// 005c2966  83e53f               and ebp, 0x3f
// 005c2969  33f6                 xor esi, esi
// 005c296b  81e7ff000000         and edi, 0xff
// 005c2971  83fd26               cmp ebp, 0x26
// 005c2974  89742414             mov dword ptr [esp + 0x14], esi
// 005c2978  0f8d86000000         jge 0x5c2a04
// 005c297e  0fb6cb               movzx ecx, bl
// 005c2981  3bf9                 cmp edi, ecx
// 005c2983  894c2418             mov dword ptr [esp + 0x18], ecx
// 005c2987  7d7b                 jge 0x5c2a04
// 005c2989  8a95ac087c00         mov dl, byte ptr [ebp + 0x7c08ac]
// 005c298f  0fb6da               movzx ebx, dl
// 005c2992  8bcb                 mov ecx, ebx
// 005c2994  83e103               and ecx, 3
// 005c2997  2bce                 sub ecx, esi
// 005c2999  7473                 je 0x5c2a0e
// 005c299b  83e901               sub ecx, 1
// 005c299e  744e                 je 0x5c29ee
// 005c29a0  83e901               sub ecx, 1
// 005c29a3  0f85a6000000         jne 0x5c2a4f
// 005c29a9  c1e80e               shr eax, 0xe
// 005c29ac  2dffff0100           sub eax, 0x1ffff
// 005c29b1  80e230               and dl, 0x30
// 005c29b4  80fa20               cmp dl, 0x20
// 005c29b7  8bf0                 mov esi, eax
// 005c29b9  0f8590000000         jne 0x5c2a4f
// 005c29bf  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005c29c3  8d440e01             lea eax, [esi + ecx + 1]
// 005c29c7  85c0                 test eax, eax
// 005c29c9  7c39                 jl 0x5c2a04
// 005c29cb  3b442428             cmp eax, dword ptr [esp + 0x28]
// 005c29cf  7d33                 jge 0x5c2a04
// 005c29d1  85c0                 test eax, eax
// 005c29d3  7e7a                 jle 0x5c2a4f
// 005c29d5  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c29d9  8b4482fc             mov eax, dword ptr [edx + eax*4 - 4]
// 005c29dd  8bc8                 mov ecx, eax
// 005c29df  83e13f               and ecx, 0x3f
// 005c29e2  80f922               cmp cl, 0x22
// 005c29e5  7568                 jne 0x5c2a4f
// 005c29e7  a900c07f00           test eax, 0x7fc000
// 005c29ec  eb5f                 jmp 0x5c2a4d
// 005c29ee  c1e80e               shr eax, 0xe
// 005c29f1  80e230               and dl, 0x30
// 005c29f4  80fa30               cmp dl, 0x30
// 005c29f7  8bf0                 mov esi, eax
// 005c29f9  7554                 jne 0x5c2a4f
// 005c29fb  8b542434             mov edx, dword ptr [esp + 0x34]
// 005c29ff  3b7228               cmp esi, dword ptr [edx + 0x28]
// 005c2a02  7c4b                 jl 0x5c2a4f
// 005c2a04  5f                   pop edi
// 005c2a05  5e                   pop esi
// 005c2a06  5d                   pop ebp
// 005c2a07  33c0                 xor eax, eax
// 005c2a09  5b                   pop ebx
// 005c2a0a  83c420               add esp, 0x20
// 005c2a0d  c3                   ret 
// 005c2a0e  8b542434             mov edx, dword ptr [esp + 0x34]
// 005c2a12  8bf0                 mov esi, eax
// 005c2a14  c1e80e               shr eax, 0xe
// 005c2a17  25ff010000           and eax, 0x1ff
// 005c2a1c  89442414             mov dword ptr [esp + 0x14], eax
// 005c2a20  8bc3                 mov eax, ebx
// 005c2a22  c1e804               shr eax, 4
// 005c2a25  c1ee17               shr esi, 0x17
// 005c2a28  83e003               and eax, 3
// 005c2a2b  8bce                 mov ecx, esi
// 005c2a2d  e84efeffff           call 0x5c2880
// 005c2a32  85c0                 test eax, eax
// 005c2a34  74ce                 je 0x5c2a04
// 005c2a36  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005c2a3a  8b542434             mov edx, dword ptr [esp + 0x34]
// 005c2a3e  8bc3                 mov eax, ebx
// 005c2a40  c1e802               shr eax, 2
// 005c2a43  83e003               and eax, 3
// 005c2a46  e835feffff           call 0x5c2880
// 005c2a4b  85c0                 test eax, eax
// 005c2a4d  74b5                 je 0x5c2a04
// 005c2a4f  8a85ac087c00         mov al, byte ptr [ebp + 0x7c08ac]
// 005c2a55  a840                 test al, 0x40
// 005c2a57  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005c2a5b  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005c2a5f  7408                 je 0x5c2a69
// 005c2a61  3bf9                 cmp edi, ecx
// 005c2a63  7504                 jne 0x5c2a69
// 005c2a65  895c2424             mov dword ptr [esp + 0x24], ebx
// 005c2a69  84c0                 test al, al
// 005c2a6b  8b542428             mov edx, dword ptr [esp + 0x28]
// 005c2a6f  791a                 jns 0x5c2a8b
// 005c2a71  8d4302               lea eax, [ebx + 2]
// 005c2a74  3bc2                 cmp eax, edx
// 005c2a76  7d8c                 jge 0x5c2a04
// 005c2a78  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c2a7c  8b449804             mov eax, dword ptr [eax + ebx*4 + 4]
// 005c2a80  83e03f               and eax, 0x3f
// 005c2a83  3c16                 cmp al, 0x16
// 005c2a85  0f8579ffffff         jne 0x5c2a04
// 005c2a8b  83c5fe               add ebp, -2
// 005c2a8e  83fd23               cmp ebp, 0x23
// 005c2a91  0f871d020000         ja 0x5c2cb4
// 005c2a97  0fb685142d5c00       movzx eax, byte ptr [ebp + 0x5c2d14]
// 005c2a9e  ff2485d82c5c00       jmp dword ptr [eax*4 + 0x5c2cd8]
// 005c2aa5  837c241400           cmp dword ptr [esp + 0x14], 0
// 005c2aaa  0f8404020000         je 0x5c2cb4
// 005c2ab0  8d4b02               lea ecx, [ebx + 2]
// 005c2ab3  3bca                 cmp ecx, edx
// 005c2ab5  e9f4010000           jmp 0x5c2cae
// 005c2aba  3bf9                 cmp edi, ecx
// 005c2abc  0f8ff2010000         jg 0x5c2cb4
// 005c2ac2  3bce                 cmp ecx, esi
// 005c2ac4  0f8fea010000         jg 0x5c2cb4
// 005c2aca  895c2424             mov dword ptr [esp + 0x24], ebx
// 005c2ace  e9e1010000           jmp 0x5c2cb4
// 005c2ad3  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 005c2ad7  e9d2010000           jmp 0x5c2cae
// 005c2adc  8b542434             mov edx, dword ptr [esp + 0x34]
// 005c2ae0  8b4208               mov eax, dword ptr [edx + 8]
// 005c2ae3  c1e604               shl esi, 4
// 005c2ae6  837c060804           cmp dword ptr [esi + eax + 8], 4
// 005c2aeb  0f8513ffffff         jne 0x5c2a04
// 005c2af1  e9be010000           jmp 0x5c2cb4
// 005c2af6  83c701               add edi, 1
// 005c2af9  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 005c2afd  0f8d01ffffff         jge 0x5c2a04
// 005c2b03  3bcf                 cmp ecx, edi
// 005c2b05  0f85a9010000         jne 0x5c2cb4
// 005c2b0b  895c2424             mov dword ptr [esp + 0x24], ebx
// 005c2b0f  e9a0010000           jmp 0x5c2cb4
// 005c2b14  3b742414             cmp esi, dword ptr [esp + 0x14]
// 005c2b18  e991010000           jmp 0x5c2cae
// 005c2b1d  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c2b21  83f801               cmp eax, 1
// 005c2b24  0f8cdafeffff         jl 0x5c2a04
// 005c2b2a  8d543802             lea edx, [eax + edi + 2]
// 005c2b2e  3b542418             cmp edx, dword ptr [esp + 0x18]
// 005c2b32  0f8dccfeffff         jge 0x5c2a04
// 005c2b38  83c702               add edi, 2
// 005c2b3b  3bcf                 cmp ecx, edi
// 005c2b3d  0f8c71010000         jl 0x5c2cb4
// 005c2b43  895c2424             mov dword ptr [esp + 0x24], ebx
// 005c2b47  e968010000           jmp 0x5c2cb4
// 005c2b4c  83c703               add edi, 3
// 005c2b4f  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 005c2b53  0f8dabfeffff         jge 0x5c2a04
// 005c2b59  81f9ff000000         cmp ecx, 0xff
// 005c2b5f  8d441e01             lea eax, [esi + ebx + 1]
// 005c2b63  0f844b010000         je 0x5c2cb4
// 005c2b69  3bd8                 cmp ebx, eax
// 005c2b6b  0f8d43010000         jge 0x5c2cb4
// 005c2b71  3b442438             cmp eax, dword ptr [esp + 0x38]
// 005c2b75  0f8f39010000         jg 0x5c2cb4
// 005c2b7b  03de                 add ebx, esi
// 005c2b7d  e932010000           jmp 0x5c2cb4
// 005c2b82  85f6                 test esi, esi
// 005c2b84  740e                 je 0x5c2b94
// 005c2b86  8d443eff             lea eax, [esi + edi - 1]
// 005c2b8a  3b442418             cmp eax, dword ptr [esp + 0x18]
// 005c2b8e  0f8d70feffff         jge 0x5c2a04
// 005c2b94  8b442414             mov eax, dword ptr [esp + 0x14]
// 005c2b98  83e801               sub eax, 1
// 005c2b9b  83f8ff               cmp eax, -1
// 005c2b9e  751f                 jne 0x5c2bbf
// 005c2ba0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c2ba4  8b549904             mov edx, dword ptr [ecx + ebx*4 + 4]
// 005c2ba8  52                   push edx
// 005c2ba9  e8a2fcffff           call 0x5c2850
// 005c2bae  83c404               add esp, 4
// 005c2bb1  85c0                 test eax, eax
// 005c2bb3  0f844bfeffff         je 0x5c2a04
// 005c2bb9  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005c2bbd  eb12                 jmp 0x5c2bd1
// 005c2bbf  85c0                 test eax, eax
// 005c2bc1  740e                 je 0x5c2bd1
// 005c2bc3  8d4438ff             lea eax, [eax + edi - 1]
// 005c2bc7  3b442418             cmp eax, dword ptr [esp + 0x18]
// 005c2bcb  0f8d33feffff         jge 0x5c2a04
// 005c2bd1  3bcf                 cmp ecx, edi
// 005c2bd3  0f8cdb000000         jl 0x5c2cb4
// 005c2bd9  895c2424             mov dword ptr [esp + 0x24], ebx
// 005c2bdd  e9d2000000           jmp 0x5c2cb4
// 005c2be2  83ee01               sub esi, 1
// 005c2be5  85f6                 test esi, esi
// 005c2be7  0f8ec7000000         jle 0x5c2cb4
// 005c2bed  8d4c3eff             lea ecx, [esi + edi - 1]
// 005c2bf1  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 005c2bf5  e9b4000000           jmp 0x5c2cae
// 005c2bfa  85f6                 test esi, esi
// 005c2bfc  7e0c                 jle 0x5c2c0a
// 005c2bfe  03f7                 add esi, edi
// 005c2c00  3b742418             cmp esi, dword ptr [esp + 0x18]
// 005c2c04  0f8dfafdffff         jge 0x5c2a04
// 005c2c0a  837c241400           cmp dword ptr [esp + 0x14], 0
// 005c2c0f  0f859f000000         jne 0x5c2cb4
// 005c2c15  83c301               add ebx, 1
// 005c2c18  e997000000           jmp 0x5c2cb4
// 005c2c1d  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c2c21  3b7034               cmp esi, dword ptr [eax + 0x34]
// 005c2c24  0f8ddafdffff         jge 0x5c2a04
// 005c2c2a  8b4010               mov eax, dword ptr [eax + 0x10]
// 005c2c2d  8b0cb0               mov ecx, dword ptr [eax + esi*4]
// 005c2c30  0fb64948             movzx ecx, byte ptr [ecx + 0x48]
// 005c2c34  8d0419               lea eax, [ecx + ebx]
// 005c2c37  3bc2                 cmp eax, edx
// 005c2c39  0f8dc5fdffff         jge 0x5c2a04
// 005c2c3f  85c9                 test ecx, ecx
// 005c2c41  7e71                 jle 0x5c2cb4
// 005c2c43  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005c2c47  8d3482               lea esi, [edx + eax*4]
// 005c2c4a  8d9b00000000         lea ebx, [ebx]
// 005c2c50  8b06                 mov eax, dword ptr [esi]
// 005c2c52  83e03f               and eax, 0x3f
// 005c2c55  83f804               cmp eax, 4
// 005c2c58  7408                 je 0x5c2c62
// 005c2c5a  85c0                 test eax, eax
// 005c2c5c  0f85a2fdffff         jne 0x5c2a04
// 005c2c62  83e901               sub ecx, 1
// 005c2c65  83ee04               sub esi, 4
// 005c2c68  85c9                 test ecx, ecx
// 005c2c6a  7fe4                 jg 0x5c2c50
// 005c2c6c  eb46                 jmp 0x5c2cb4
// 005c2c6e  8b442434             mov eax, dword ptr [esp + 0x34]
// 005c2c72  8a404a               mov al, byte ptr [eax + 0x4a]
// 005c2c75  a802                 test al, 2
// 005c2c77  0f8487fdffff         je 0x5c2a04
// 005c2c7d  a804                 test al, 4
// 005c2c7f  0f857ffdffff         jne 0x5c2a04
// 005c2c85  83ee01               sub esi, 1
// 005c2c88  83feff               cmp esi, -1
// 005c2c8b  7519                 jne 0x5c2ca6
// 005c2c8d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005c2c91  8b549904             mov edx, dword ptr [ecx + ebx*4 + 4]
// 005c2c95  52                   push edx
// 005c2c96  e8b5fbffff           call 0x5c2850
// 005c2c9b  83c404               add esp, 4
// 005c2c9e  85c0                 test eax, eax
// 005c2ca0  0f845efdffff         je 0x5c2a04
// 005c2ca6  8d443eff             lea eax, [esi + edi - 1]
// 005c2caa  3b442418             cmp eax, dword ptr [esp + 0x18]
// 005c2cae  0f8d50fdffff         jge 0x5c2a04
// 005c2cb4  83c301               add ebx, 1
// 005c2cb7  3b5c2438             cmp ebx, dword ptr [esp + 0x38]
// 005c2cbb  895c2420             mov dword ptr [esp + 0x20], ebx
// 005c2cbf  0f8c8bfcffff         jl 0x5c2950
// 005c2cc5  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c2cc9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c2ccd  8b0488               mov eax, dword ptr [eax + ecx*4]
// 005c2cd0  5f                   pop edi
// 005c2cd1  5e                   pop esi
// 005c2cd2  5d                   pop ebp
// 005c2cd3  5b                   pop ebx
// 005c2cd4  83c420               add esp, 0x20
// 005c2cd7  c3                   ret 
// 005c2cd8  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 005c2cd9  2a5c00ba             sub bl, byte ptr [eax + eax - 0x46]
// 005c2cdd  2a5c00d3             sub bl, byte ptr [eax + eax - 0x2d]
// 005c2ce1  2a5c00dc             sub bl, byte ptr [eax + eax - 0x24]
// 005c2ce5  2a5c00f6             sub bl, byte ptr [eax + eax - 0xa]
// 005c2ce9  2a5c0014             sub bl, byte ptr [eax + eax + 0x14]
// 005c2ced  2b5c0059             sub ebx, dword ptr [eax + eax + 0x59]
// 005c2cf1  2b5c0082             sub ebx, dword ptr [eax + eax - 0x7e]
// 005c2cf5  2b5c00e2             sub ebx, dword ptr [eax + eax - 0x1e]
// 005c2cf9  2b5c004c             sub ebx, dword ptr [eax + eax + 0x4c]
// 005c2cfd  2b5c001d             sub ebx, dword ptr [eax + eax + 0x1d]
// 005c2d01  2b5c00fa             sub ebx, dword ptr [eax + eax - 6]
// 005c2d05  2b5c001d             sub ebx, dword ptr [eax + eax + 0x1d]
// 005c2d09  2c5c                 sub al, 0x5c
// 005c2d0b  006e2c               add byte ptr [esi + 0x2c], ch
// 005c2d0e  5c                   pop esp
// 005c2d0f  00b42c5c000001       add byte ptr [esp + ebp + 0x100005c], dh
// 005c2d16  0203                 add al, byte ptr [ebx]
// 005c2d18  0e                   push cs
// 005c2d19  0302                 add eax, dword ptr [edx]
// 005c2d1b  0e                   push cs
// 005c2d1c  0e                   push cs
// 005c2d1d  040e                 add al, 0xe
// 005c2d1f  0e                   push cs
// 005c2d20  0e                   push cs
// 005c2d21  0e                   push cs
// 005c2d22  0e                   push cs
// 005c2d23  0e                   push cs
// 005c2d24  0e                   push cs
// 005c2d25  0e                   push cs
// 005c2d26  0e                   push cs
// 005c2d27  05060e0e0e           add eax, 0xe0e0e06
// 005c2d2c  0e                   push cs
// 005c2d2d  0e                   push cs
// 005c2d2e  07                   pop es
// 005c2d2f  07                   pop es
// 005c2d30  0809                 or byte ptr [ecx], cl
// 005c2d32  090a                 or dword ptr [edx], ecx
// 005c2d34  0b0e                 or ecx, dword ptr [esi]
// 005c2d36  0c0d                 or al, 0xd
// library lua-5.1.1/ldebug.c (function _symbexec)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
