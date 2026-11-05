// from server: 100% by auto
// roc 2011-06 0054c1b0  unit: G3D::_internal::DialogTemplate  size: 1183 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054c1b0
//
// 0054c1b0  83ec08               sub esp, 8
// 0054c1b3  53                   push ebx
// 0054c1b4  55                   push ebp
// 0054c1b5  56                   push esi
// 0054c1b6  8b742418             mov esi, dword ptr [esp + 0x18]
// 0054c1ba  57                   push edi
// 0054c1bb  8bf9                 mov edi, ecx
// 0054c1bd  bd01000000           mov ebp, 1
// 0054c1c2  55                   push ebp
// 0054c1c3  8bce                 mov ecx, esi
// 0054c1c5  897c2414             mov dword ptr [esp + 0x14], edi
// 0054c1c9  e8428fffff           call 0x545110
// 0054c1ce  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c1d1  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054c1d4  03c5                 add eax, ebp
// 0054c1d6  3bc8                 cmp ecx, eax
// 0054c1d8  7c02                 jl 0x54c1dc
// 0054c1da  8bc1                 mov eax, ecx
// 0054c1dc  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054c1df  894638               mov dword ptr [esi + 0x38], eax
// 0054c1e2  7e09                 jle 0x54c1ed
// 0054c1e4  51                   push ecx
// 0054c1e5  55                   push ebp
// 0054c1e6  8bce                 mov ecx, esi
// 0054c1e8  e8438fffff           call 0x545130
// 0054c1ed  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c1f0  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c1f3  c6040800             mov byte ptr [eax + ecx], 0
// 0054c1f7  016e40               add dword ptr [esi + 0x40], ebp
// 0054c1fa  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c1fd  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c200  41                   inc ecx
// 0054c201  3bc1                 cmp eax, ecx
// 0054c203  7c02                 jl 0x54c207
// 0054c205  8bc8                 mov ecx, eax
// 0054c207  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c20a  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c20d  7e09                 jle 0x54c218
// 0054c20f  50                   push eax
// 0054c210  55                   push ebp
// 0054c211  8bce                 mov ecx, esi
// 0054c213  e8188fffff           call 0x545130
// 0054c218  8b5640               mov edx, dword ptr [esi + 0x40]
// 0054c21b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054c21e  c6040200             mov byte ptr [edx + eax], 0
// 0054c222  016e40               add dword ptr [esi + 0x40], ebp
// 0054c225  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c228  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c22b  41                   inc ecx
// 0054c22c  3bc1                 cmp eax, ecx
// 0054c22e  7c02                 jl 0x54c232
// 0054c230  8bc8                 mov ecx, eax
// 0054c232  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c235  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c238  7e09                 jle 0x54c243
// 0054c23a  50                   push eax
// 0054c23b  55                   push ebp
// 0054c23c  8bce                 mov ecx, esi
// 0054c23e  e8ed8effff           call 0x545130
// 0054c243  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c246  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054c249  c6041102             mov byte ptr [ecx + edx], 2
// 0054c24d  016e40               add dword ptr [esi + 0x40], ebp
// 0054c250  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c253  8d4805               lea ecx, [eax + 5]
// 0054c256  3b4e38               cmp ecx, dword ptr [esi + 0x38]
// 0054c259  7e0f                 jle 0x54c26a
// 0054c25b  8b5648               mov edx, dword ptr [esi + 0x48]
// 0054c25e  8d440205             lea eax, [edx + eax + 5]
// 0054c262  50                   push eax
// 0054c263  8bce                 mov ecx, esi
// 0054c265  e8f6feffff           call 0x54c160
// 0054c26a  83464005             add dword ptr [esi + 0x40], 5
// 0054c26e  6a00                 push 0
// 0054c270  8bce                 mov ecx, esi
// 0054c272  e8a98fffff           call 0x545220
// 0054c277  6a00                 push 0
// 0054c279  8bce                 mov ecx, esi
// 0054c27b  e8a08fffff           call 0x545220
// 0054c280  0fb74f10             movzx ecx, word ptr [edi + 0x10]
// 0054c284  51                   push ecx
// 0054c285  8bce                 mov ecx, esi
// 0054c287  e8948fffff           call 0x545220
// 0054c28c  0fb75714             movzx edx, word ptr [edi + 0x14]
// 0054c290  52                   push edx
// 0054c291  8bce                 mov ecx, esi
// 0054c293  e8888fffff           call 0x545220
// 0054c298  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c29b  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054c29e  03c5                 add eax, ebp
// 0054c2a0  396f0c               cmp dword ptr [edi + 0xc], ebp
// 0054c2a3  7523                 jne 0x54c2c8
// 0054c2a5  3bc8                 cmp ecx, eax
// 0054c2a7  7c02                 jl 0x54c2ab
// 0054c2a9  8bc1                 mov eax, ecx
// 0054c2ab  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054c2ae  894638               mov dword ptr [esi + 0x38], eax
// 0054c2b1  7e09                 jle 0x54c2bc
// 0054c2b3  51                   push ecx
// 0054c2b4  55                   push ebp
// 0054c2b5  8bce                 mov ecx, esi
// 0054c2b7  e8748effff           call 0x545130
// 0054c2bc  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c2bf  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c2c2  c6040818             mov byte ptr [eax + ecx], 0x18
// 0054c2c6  eb29                 jmp 0x54c2f1
// 0054c2c8  8a5f0c               mov bl, byte ptr [edi + 0xc]
// 0054c2cb  02db                 add bl, bl
// 0054c2cd  02db                 add bl, bl
// 0054c2cf  02db                 add bl, bl
// 0054c2d1  3bc8                 cmp ecx, eax
// 0054c2d3  7c02                 jl 0x54c2d7
// 0054c2d5  8bc1                 mov eax, ecx
// 0054c2d7  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054c2da  894638               mov dword ptr [esi + 0x38], eax
// 0054c2dd  7e09                 jle 0x54c2e8
// 0054c2df  51                   push ecx
// 0054c2e0  55                   push ebp
// 0054c2e1  8bce                 mov ecx, esi
// 0054c2e3  e8488effff           call 0x545130
// 0054c2e8  8b5640               mov edx, dword ptr [esi + 0x40]
// 0054c2eb  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054c2ee  881c02               mov byte ptr [edx + eax], bl
// 0054c2f1  016e40               add dword ptr [esi + 0x40], ebp
// 0054c2f4  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c2f7  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054c2fa  40                   inc eax
// 0054c2fb  837f0c04             cmp dword ptr [edi + 0xc], 4
// 0054c2ff  7d23                 jge 0x54c324
// 0054c301  3bc8                 cmp ecx, eax
// 0054c303  7c02                 jl 0x54c307
// 0054c305  8bc1                 mov eax, ecx
// 0054c307  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054c30a  894638               mov dword ptr [esi + 0x38], eax
// 0054c30d  7e09                 jle 0x54c318
// 0054c30f  51                   push ecx
// 0054c310  55                   push ebp
// 0054c311  8bce                 mov ecx, esi
// 0054c313  e8188effff           call 0x545130
// 0054c318  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c31b  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054c31e  c6041100             mov byte ptr [ecx + edx], 0
// 0054c322  eb21                 jmp 0x54c345
// 0054c324  3bc8                 cmp ecx, eax
// 0054c326  7c02                 jl 0x54c32a
// 0054c328  8bc1                 mov eax, ecx
// 0054c32a  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054c32d  894638               mov dword ptr [esi + 0x38], eax
// 0054c330  7e09                 jle 0x54c33b
// 0054c332  51                   push ecx
// 0054c333  55                   push ebp
// 0054c334  8bce                 mov ecx, esi
// 0054c336  e8f58dffff           call 0x545130
// 0054c33b  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c33e  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c341  c6040808             mov byte ptr [eax + ecx], 8
// 0054c345  016e40               add dword ptr [esi + 0x40], ebp
// 0054c348  8b470c               mov eax, dword ptr [edi + 0xc]
// 0054c34b  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c34e  3bc5                 cmp eax, ebp
// 0054c350  0f85d7000000         jne 0x54c42d
// 0054c356  8b4714               mov eax, dword ptr [edi + 0x14]
// 0054c359  2bc5                 sub eax, ebp
// 0054c35b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0054c35f  0f88d4020000         js 0x54c639
// 0054c365  8bd5                 mov edx, ebp
// 0054c367  8b4710               mov eax, dword ptr [edi + 0x10]
// 0054c36a  33ed                 xor ebp, ebp
// 0054c36c  85c0                 test eax, eax
// 0054c36e  0f8eaa000000         jle 0x54c41e
// 0054c374  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 0054c379  8b5f08               mov ebx, dword ptr [edi + 8]
// 0054c37c  03c5                 add eax, ebp
// 0054c37e  8a1c18               mov bl, byte ptr [eax + ebx]
// 0054c381  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c384  41                   inc ecx
// 0054c385  3bc1                 cmp eax, ecx
// 0054c387  7c02                 jl 0x54c38b
// 0054c389  8bc8                 mov ecx, eax
// 0054c38b  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c38e  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c391  7e0f                 jle 0x54c3a2
// 0054c393  50                   push eax
// 0054c394  6a01                 push 1
// 0054c396  8bce                 mov ecx, esi
// 0054c398  e8938dffff           call 0x545130
// 0054c39d  ba01000000           mov edx, 1
// 0054c3a2  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c3a5  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c3a8  881c08               mov byte ptr [eax + ecx], bl
// 0054c3ab  015640               add dword ptr [esi + 0x40], edx
// 0054c3ae  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c3b1  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c3b4  41                   inc ecx
// 0054c3b5  3bc1                 cmp eax, ecx
// 0054c3b7  7c02                 jl 0x54c3bb
// 0054c3b9  8bc8                 mov ecx, eax
// 0054c3bb  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c3be  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c3c1  7e0f                 jle 0x54c3d2
// 0054c3c3  50                   push eax
// 0054c3c4  6a01                 push 1
// 0054c3c6  8bce                 mov ecx, esi
// 0054c3c8  e8638dffff           call 0x545130
// 0054c3cd  ba01000000           mov edx, 1
// 0054c3d2  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c3d5  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c3d8  881c08               mov byte ptr [eax + ecx], bl
// 0054c3db  015640               add dword ptr [esi + 0x40], edx
// 0054c3de  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c3e1  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c3e4  41                   inc ecx
// 0054c3e5  3bc1                 cmp eax, ecx
// 0054c3e7  7c02                 jl 0x54c3eb
// 0054c3e9  8bc8                 mov ecx, eax
// 0054c3eb  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c3ee  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c3f1  7e0f                 jle 0x54c402
// 0054c3f3  50                   push eax
// 0054c3f4  6a01                 push 1
// 0054c3f6  8bce                 mov ecx, esi
// 0054c3f8  e8338dffff           call 0x545130
// 0054c3fd  ba01000000           mov edx, 1
// 0054c402  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c405  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c408  881c08               mov byte ptr [eax + ecx], bl
// 0054c40b  015640               add dword ptr [esi + 0x40], edx
// 0054c40e  8b4710               mov eax, dword ptr [edi + 0x10]
// 0054c411  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c414  03ea                 add ebp, edx
// 0054c416  3be8                 cmp ebp, eax
// 0054c418  0f8c56ffffff         jl 0x54c374
// 0054c41e  2954241c             sub dword ptr [esp + 0x1c], edx
// 0054c422  0f893fffffff         jns 0x54c367
// 0054c428  e90c020000           jmp 0x54c639
// 0054c42d  83f803               cmp eax, 3
// 0054c430  8b4714               mov eax, dword ptr [edi + 0x14]
// 0054c433  0f85e1000000         jne 0x54c51a
// 0054c439  2bc5                 sub eax, ebp
// 0054c43b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0054c43f  0f88f4010000         js 0x54c639
// 0054c445  eb04                 jmp 0x54c44b
// 0054c447  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054c44b  8b4710               mov eax, dword ptr [edi + 0x10]
// 0054c44e  33ed                 xor ebp, ebp
// 0054c450  85c0                 test eax, eax
// 0054c452  0f8eb2000000         jle 0x54c50a
// 0054c458  eb06                 jmp 0x54c460
// 0054c45a  8d9b00000000         lea ebx, [ebx]
// 0054c460  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 0054c465  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054c469  03c5                 add eax, ebp
// 0054c46b  8d3c40               lea edi, [eax + eax*2]
// 0054c46e  037a08               add edi, dword ptr [edx + 8]
// 0054c471  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c474  8a5f02               mov bl, byte ptr [edi + 2]
// 0054c477  41                   inc ecx
// 0054c478  3bc1                 cmp eax, ecx
// 0054c47a  7c02                 jl 0x54c47e
// 0054c47c  8bc8                 mov ecx, eax
// 0054c47e  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c481  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c484  7e0a                 jle 0x54c490
// 0054c486  50                   push eax
// 0054c487  6a01                 push 1
// 0054c489  8bce                 mov ecx, esi
// 0054c48b  e8a08cffff           call 0x545130
// 0054c490  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c493  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c496  881c08               mov byte ptr [eax + ecx], bl
// 0054c499  ff4640               inc dword ptr [esi + 0x40]
// 0054c49c  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c49f  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c4a2  8a5f01               mov bl, byte ptr [edi + 1]
// 0054c4a5  41                   inc ecx
// 0054c4a6  3bc1                 cmp eax, ecx
// 0054c4a8  7c02                 jl 0x54c4ac
// 0054c4aa  8bc8                 mov ecx, eax
// 0054c4ac  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c4af  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c4b2  7e0a                 jle 0x54c4be
// 0054c4b4  50                   push eax
// 0054c4b5  6a01                 push 1
// 0054c4b7  8bce                 mov ecx, esi
// 0054c4b9  e8728cffff           call 0x545130
// 0054c4be  8b5640               mov edx, dword ptr [esi + 0x40]
// 0054c4c1  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054c4c4  881c02               mov byte ptr [edx + eax], bl
// 0054c4c7  ff4640               inc dword ptr [esi + 0x40]
// 0054c4ca  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c4cd  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c4d0  8a1f                 mov bl, byte ptr [edi]
// 0054c4d2  41                   inc ecx
// 0054c4d3  3bc1                 cmp eax, ecx
// 0054c4d5  7c02                 jl 0x54c4d9
// 0054c4d7  8bc8                 mov ecx, eax
// 0054c4d9  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c4dc  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c4df  7e0a                 jle 0x54c4eb
// 0054c4e1  50                   push eax
// 0054c4e2  6a01                 push 1
// 0054c4e4  8bce                 mov ecx, esi
// 0054c4e6  e8458cffff           call 0x545130
// 0054c4eb  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c4ee  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054c4f1  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054c4f5  881c11               mov byte ptr [ecx + edx], bl
// 0054c4f8  ff4640               inc dword ptr [esi + 0x40]
// 0054c4fb  8b4010               mov eax, dword ptr [eax + 0x10]
// 0054c4fe  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c501  45                   inc ebp
// 0054c502  3be8                 cmp ebp, eax
// 0054c504  0f8c56ffffff         jl 0x54c460
// 0054c50a  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0054c50f  0f8932ffffff         jns 0x54c447
// 0054c515  e91f010000           jmp 0x54c639
// 0054c51a  2bc5                 sub eax, ebp
// 0054c51c  8944241c             mov dword ptr [esp + 0x1c], eax
// 0054c520  0f8813010000         js 0x54c639
// 0054c526  eb0c                 jmp 0x54c534
// 0054c528  eb06                 jmp 0x54c530
// 0054c52a  8d9b00000000         lea ebx, [ebx]
// 0054c530  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054c534  8b4710               mov eax, dword ptr [edi + 0x10]
// 0054c537  33d2                 xor edx, edx
// 0054c539  89542414             mov dword ptr [esp + 0x14], edx
// 0054c53d  85c0                 test eax, eax
// 0054c53f  0f8ee9000000         jle 0x54c62e
// 0054c545  8d6a01               lea ebp, [edx + 1]
// 0054c548  eb06                 jmp 0x54c550
// 0054c54a  8d9b00000000         lea ebx, [ebx]
// 0054c550  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 0054c555  03c2                 add eax, edx
// 0054c557  8b542410             mov edx, dword ptr [esp + 0x10]
// 0054c55b  8b5208               mov edx, dword ptr [edx + 8]
// 0054c55e  8a5c8202             mov bl, byte ptr [edx + eax*4 + 2]
// 0054c562  8d3c82               lea edi, [edx + eax*4]
// 0054c565  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c568  41                   inc ecx
// 0054c569  3bc1                 cmp eax, ecx
// 0054c56b  7c02                 jl 0x54c56f
// 0054c56d  8bc8                 mov ecx, eax
// 0054c56f  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c572  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c575  7e09                 jle 0x54c580
// 0054c577  50                   push eax
// 0054c578  55                   push ebp
// 0054c579  8bce                 mov ecx, esi
// 0054c57b  e8b08bffff           call 0x545130
// 0054c580  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c583  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c586  881c08               mov byte ptr [eax + ecx], bl
// 0054c589  016e40               add dword ptr [esi + 0x40], ebp
// 0054c58c  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c58f  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c592  8a5f01               mov bl, byte ptr [edi + 1]
// 0054c595  41                   inc ecx
// 0054c596  3bc1                 cmp eax, ecx
// 0054c598  7c02                 jl 0x54c59c
// 0054c59a  8bc8                 mov ecx, eax
// 0054c59c  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c59f  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c5a2  7e09                 jle 0x54c5ad
// 0054c5a4  50                   push eax
// 0054c5a5  55                   push ebp
// 0054c5a6  8bce                 mov ecx, esi
// 0054c5a8  e8838bffff           call 0x545130
// 0054c5ad  8b5640               mov edx, dword ptr [esi + 0x40]
// 0054c5b0  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054c5b3  881c02               mov byte ptr [edx + eax], bl
// 0054c5b6  016e40               add dword ptr [esi + 0x40], ebp
// 0054c5b9  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c5bc  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c5bf  8a1f                 mov bl, byte ptr [edi]
// 0054c5c1  41                   inc ecx
// 0054c5c2  3bc1                 cmp eax, ecx
// 0054c5c4  7c02                 jl 0x54c5c8
// 0054c5c6  8bc8                 mov ecx, eax
// 0054c5c8  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c5cb  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c5ce  7e09                 jle 0x54c5d9
// 0054c5d0  50                   push eax
// 0054c5d1  55                   push ebp
// 0054c5d2  8bce                 mov ecx, esi
// 0054c5d4  e8578bffff           call 0x545130
// 0054c5d9  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c5dc  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054c5df  881c11               mov byte ptr [ecx + edx], bl
// 0054c5e2  016e40               add dword ptr [esi + 0x40], ebp
// 0054c5e5  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c5e8  8b4638               mov eax, dword ptr [esi + 0x38]
// 0054c5eb  8a5f03               mov bl, byte ptr [edi + 3]
// 0054c5ee  41                   inc ecx
// 0054c5ef  3bc1                 cmp eax, ecx
// 0054c5f1  7c02                 jl 0x54c5f5
// 0054c5f3  8bc8                 mov ecx, eax
// 0054c5f5  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0054c5f8  894e38               mov dword ptr [esi + 0x38], ecx
// 0054c5fb  7e09                 jle 0x54c606
// 0054c5fd  50                   push eax
// 0054c5fe  55                   push ebp
// 0054c5ff  8bce                 mov ecx, esi
// 0054c601  e82a8bffff           call 0x545130
// 0054c606  8b4640               mov eax, dword ptr [esi + 0x40]
// 0054c609  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0054c60c  8b542414             mov edx, dword ptr [esp + 0x14]
// 0054c610  881c08               mov byte ptr [eax + ecx], bl
// 0054c613  016e40               add dword ptr [esi + 0x40], ebp
// 0054c616  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054c61a  8b4010               mov eax, dword ptr [eax + 0x10]
// 0054c61d  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0054c620  03d5                 add edx, ebp
// 0054c622  3bd0                 cmp edx, eax
// 0054c624  89542414             mov dword ptr [esp + 0x14], edx
// 0054c628  0f8c22ffffff         jl 0x54c550
// 0054c62e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 0054c633  0f89f7feffff         jns 0x54c530
// 0054c639  68d000a800           push 0xa800d0
// 0054c63e  8bce                 mov ecx, esi
// 0054c640  e8bb8cffff           call 0x545300
// 0054c645  5f                   pop edi
// 0054c646  5e                   pop esi
// 0054c647  5d                   pop ebp
// 0054c648  5b                   pop ebx
// 0054c649  83c408               add esp, 8
// 0054c64c  c20400               ret 4
// library rbx2016-g3d/GImage_tga.cpp (function ?encodeTGA@GImage@G3D@@ABEXAAVBinaryOutput@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
