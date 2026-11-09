// from server: 100% by auto
// roc 2012-06 006397f0  unit: G3D::_internal::DialogTemplate  size: 1183 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006397f0
//
// 006397f0  83ec08               sub esp, 8
// 006397f3  53                   push ebx
// 006397f4  55                   push ebp
// 006397f5  56                   push esi
// 006397f6  8b742418             mov esi, dword ptr [esp + 0x18]
// 006397fa  57                   push edi
// 006397fb  8bf9                 mov edi, ecx
// 006397fd  bd01000000           mov ebp, 1
// 00639802  55                   push ebp
// 00639803  8bce                 mov ecx, esi
// 00639805  897c2414             mov dword ptr [esp + 0x14], edi
// 00639809  e892bdffff           call 0x6355a0
// 0063980e  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639811  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 00639814  03c5                 add eax, ebp
// 00639816  3bc8                 cmp ecx, eax
// 00639818  7c02                 jl 0x63981c
// 0063981a  8bc1                 mov eax, ecx
// 0063981c  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0063981f  894638               mov dword ptr [esi + 0x38], eax
// 00639822  7e09                 jle 0x63982d
// 00639824  51                   push ecx
// 00639825  55                   push ebp
// 00639826  8bce                 mov ecx, esi
// 00639828  e893bdffff           call 0x6355c0
// 0063982d  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639830  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639833  c6040800             mov byte ptr [eax + ecx], 0
// 00639837  016e40               add dword ptr [esi + 0x40], ebp
// 0063983a  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0063983d  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639840  41                   inc ecx
// 00639841  3bc1                 cmp eax, ecx
// 00639843  7c02                 jl 0x639847
// 00639845  8bc8                 mov ecx, eax
// 00639847  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 0063984a  894e38               mov dword ptr [esi + 0x38], ecx
// 0063984d  7e09                 jle 0x639858
// 0063984f  50                   push eax
// 00639850  55                   push ebp
// 00639851  8bce                 mov ecx, esi
// 00639853  e868bdffff           call 0x6355c0
// 00639858  8b5640               mov edx, dword ptr [esi + 0x40]
// 0063985b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0063985e  c6040200             mov byte ptr [edx + eax], 0
// 00639862  016e40               add dword ptr [esi + 0x40], ebp
// 00639865  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639868  8b4638               mov eax, dword ptr [esi + 0x38]
// 0063986b  41                   inc ecx
// 0063986c  3bc1                 cmp eax, ecx
// 0063986e  7c02                 jl 0x639872
// 00639870  8bc8                 mov ecx, eax
// 00639872  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639875  894e38               mov dword ptr [esi + 0x38], ecx
// 00639878  7e09                 jle 0x639883
// 0063987a  50                   push eax
// 0063987b  55                   push ebp
// 0063987c  8bce                 mov ecx, esi
// 0063987e  e83dbdffff           call 0x6355c0
// 00639883  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639886  8b5634               mov edx, dword ptr [esi + 0x34]
// 00639889  c6041102             mov byte ptr [ecx + edx], 2
// 0063988d  016e40               add dword ptr [esi + 0x40], ebp
// 00639890  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639893  8d4805               lea ecx, [eax + 5]
// 00639896  3b4e38               cmp ecx, dword ptr [esi + 0x38]
// 00639899  7e0f                 jle 0x6398aa
// 0063989b  8b5648               mov edx, dword ptr [esi + 0x48]
// 0063989e  8d440205             lea eax, [edx + eax + 5]
// 006398a2  50                   push eax
// 006398a3  8bce                 mov ecx, esi
// 006398a5  e8f6feffff           call 0x6397a0
// 006398aa  83464005             add dword ptr [esi + 0x40], 5
// 006398ae  6a00                 push 0
// 006398b0  8bce                 mov ecx, esi
// 006398b2  e8f9bdffff           call 0x6356b0
// 006398b7  6a00                 push 0
// 006398b9  8bce                 mov ecx, esi
// 006398bb  e8f0bdffff           call 0x6356b0
// 006398c0  0fb74f10             movzx ecx, word ptr [edi + 0x10]
// 006398c4  51                   push ecx
// 006398c5  8bce                 mov ecx, esi
// 006398c7  e8e4bdffff           call 0x6356b0
// 006398cc  0fb75714             movzx edx, word ptr [edi + 0x14]
// 006398d0  52                   push edx
// 006398d1  8bce                 mov ecx, esi
// 006398d3  e8d8bdffff           call 0x6356b0
// 006398d8  8b4640               mov eax, dword ptr [esi + 0x40]
// 006398db  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 006398de  03c5                 add eax, ebp
// 006398e0  396f0c               cmp dword ptr [edi + 0xc], ebp
// 006398e3  7523                 jne 0x639908
// 006398e5  3bc8                 cmp ecx, eax
// 006398e7  7c02                 jl 0x6398eb
// 006398e9  8bc1                 mov eax, ecx
// 006398eb  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 006398ee  894638               mov dword ptr [esi + 0x38], eax
// 006398f1  7e09                 jle 0x6398fc
// 006398f3  51                   push ecx
// 006398f4  55                   push ebp
// 006398f5  8bce                 mov ecx, esi
// 006398f7  e8c4bcffff           call 0x6355c0
// 006398fc  8b4640               mov eax, dword ptr [esi + 0x40]
// 006398ff  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639902  c6040818             mov byte ptr [eax + ecx], 0x18
// 00639906  eb29                 jmp 0x639931
// 00639908  8a5f0c               mov bl, byte ptr [edi + 0xc]
// 0063990b  02db                 add bl, bl
// 0063990d  02db                 add bl, bl
// 0063990f  02db                 add bl, bl
// 00639911  3bc8                 cmp ecx, eax
// 00639913  7c02                 jl 0x639917
// 00639915  8bc1                 mov eax, ecx
// 00639917  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0063991a  894638               mov dword ptr [esi + 0x38], eax
// 0063991d  7e09                 jle 0x639928
// 0063991f  51                   push ecx
// 00639920  55                   push ebp
// 00639921  8bce                 mov ecx, esi
// 00639923  e898bcffff           call 0x6355c0
// 00639928  8b5640               mov edx, dword ptr [esi + 0x40]
// 0063992b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0063992e  881c02               mov byte ptr [edx + eax], bl
// 00639931  016e40               add dword ptr [esi + 0x40], ebp
// 00639934  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639937  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0063993a  40                   inc eax
// 0063993b  837f0c04             cmp dword ptr [edi + 0xc], 4
// 0063993f  7d23                 jge 0x639964
// 00639941  3bc8                 cmp ecx, eax
// 00639943  7c02                 jl 0x639947
// 00639945  8bc1                 mov eax, ecx
// 00639947  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0063994a  894638               mov dword ptr [esi + 0x38], eax
// 0063994d  7e09                 jle 0x639958
// 0063994f  51                   push ecx
// 00639950  55                   push ebp
// 00639951  8bce                 mov ecx, esi
// 00639953  e868bcffff           call 0x6355c0
// 00639958  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0063995b  8b5634               mov edx, dword ptr [esi + 0x34]
// 0063995e  c6041100             mov byte ptr [ecx + edx], 0
// 00639962  eb21                 jmp 0x639985
// 00639964  3bc8                 cmp ecx, eax
// 00639966  7c02                 jl 0x63996a
// 00639968  8bc1                 mov eax, ecx
// 0063996a  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0063996d  894638               mov dword ptr [esi + 0x38], eax
// 00639970  7e09                 jle 0x63997b
// 00639972  51                   push ecx
// 00639973  55                   push ebp
// 00639974  8bce                 mov ecx, esi
// 00639976  e845bcffff           call 0x6355c0
// 0063997b  8b4640               mov eax, dword ptr [esi + 0x40]
// 0063997e  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639981  c6040808             mov byte ptr [eax + ecx], 8
// 00639985  016e40               add dword ptr [esi + 0x40], ebp
// 00639988  8b470c               mov eax, dword ptr [edi + 0xc]
// 0063998b  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 0063998e  3bc5                 cmp eax, ebp
// 00639990  0f85d7000000         jne 0x639a6d
// 00639996  8b4714               mov eax, dword ptr [edi + 0x14]
// 00639999  2bc5                 sub eax, ebp
// 0063999b  8944241c             mov dword ptr [esp + 0x1c], eax
// 0063999f  0f88d4020000         js 0x639c79
// 006399a5  8bd5                 mov edx, ebp
// 006399a7  8b4710               mov eax, dword ptr [edi + 0x10]
// 006399aa  33ed                 xor ebp, ebp
// 006399ac  85c0                 test eax, eax
// 006399ae  0f8eaa000000         jle 0x639a5e
// 006399b4  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 006399b9  8b5f08               mov ebx, dword ptr [edi + 8]
// 006399bc  03c5                 add eax, ebp
// 006399be  8a1c18               mov bl, byte ptr [eax + ebx]
// 006399c1  8b4638               mov eax, dword ptr [esi + 0x38]
// 006399c4  41                   inc ecx
// 006399c5  3bc1                 cmp eax, ecx
// 006399c7  7c02                 jl 0x6399cb
// 006399c9  8bc8                 mov ecx, eax
// 006399cb  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 006399ce  894e38               mov dword ptr [esi + 0x38], ecx
// 006399d1  7e0f                 jle 0x6399e2
// 006399d3  50                   push eax
// 006399d4  6a01                 push 1
// 006399d6  8bce                 mov ecx, esi
// 006399d8  e8e3bbffff           call 0x6355c0
// 006399dd  ba01000000           mov edx, 1
// 006399e2  8b4640               mov eax, dword ptr [esi + 0x40]
// 006399e5  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 006399e8  881c08               mov byte ptr [eax + ecx], bl
// 006399eb  015640               add dword ptr [esi + 0x40], edx
// 006399ee  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 006399f1  8b4638               mov eax, dword ptr [esi + 0x38]
// 006399f4  41                   inc ecx
// 006399f5  3bc1                 cmp eax, ecx
// 006399f7  7c02                 jl 0x6399fb
// 006399f9  8bc8                 mov ecx, eax
// 006399fb  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 006399fe  894e38               mov dword ptr [esi + 0x38], ecx
// 00639a01  7e0f                 jle 0x639a12
// 00639a03  50                   push eax
// 00639a04  6a01                 push 1
// 00639a06  8bce                 mov ecx, esi
// 00639a08  e8b3bbffff           call 0x6355c0
// 00639a0d  ba01000000           mov edx, 1
// 00639a12  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639a15  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639a18  881c08               mov byte ptr [eax + ecx], bl
// 00639a1b  015640               add dword ptr [esi + 0x40], edx
// 00639a1e  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639a21  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639a24  41                   inc ecx
// 00639a25  3bc1                 cmp eax, ecx
// 00639a27  7c02                 jl 0x639a2b
// 00639a29  8bc8                 mov ecx, eax
// 00639a2b  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639a2e  894e38               mov dword ptr [esi + 0x38], ecx
// 00639a31  7e0f                 jle 0x639a42
// 00639a33  50                   push eax
// 00639a34  6a01                 push 1
// 00639a36  8bce                 mov ecx, esi
// 00639a38  e883bbffff           call 0x6355c0
// 00639a3d  ba01000000           mov edx, 1
// 00639a42  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639a45  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639a48  881c08               mov byte ptr [eax + ecx], bl
// 00639a4b  015640               add dword ptr [esi + 0x40], edx
// 00639a4e  8b4710               mov eax, dword ptr [edi + 0x10]
// 00639a51  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639a54  03ea                 add ebp, edx
// 00639a56  3be8                 cmp ebp, eax
// 00639a58  0f8c56ffffff         jl 0x6399b4
// 00639a5e  2954241c             sub dword ptr [esp + 0x1c], edx
// 00639a62  0f893fffffff         jns 0x6399a7
// 00639a68  e90c020000           jmp 0x639c79
// 00639a6d  83f803               cmp eax, 3
// 00639a70  8b4714               mov eax, dword ptr [edi + 0x14]
// 00639a73  0f85e1000000         jne 0x639b5a
// 00639a79  2bc5                 sub eax, ebp
// 00639a7b  8944241c             mov dword ptr [esp + 0x1c], eax
// 00639a7f  0f88f4010000         js 0x639c79
// 00639a85  eb04                 jmp 0x639a8b
// 00639a87  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00639a8b  8b4710               mov eax, dword ptr [edi + 0x10]
// 00639a8e  33ed                 xor ebp, ebp
// 00639a90  85c0                 test eax, eax
// 00639a92  0f8eb2000000         jle 0x639b4a
// 00639a98  eb06                 jmp 0x639aa0
// 00639a9a  8d9b00000000         lea ebx, [ebx]
// 00639aa0  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 00639aa5  8b542410             mov edx, dword ptr [esp + 0x10]
// 00639aa9  03c5                 add eax, ebp
// 00639aab  8d3c40               lea edi, [eax + eax*2]
// 00639aae  037a08               add edi, dword ptr [edx + 8]
// 00639ab1  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639ab4  8a5f02               mov bl, byte ptr [edi + 2]
// 00639ab7  41                   inc ecx
// 00639ab8  3bc1                 cmp eax, ecx
// 00639aba  7c02                 jl 0x639abe
// 00639abc  8bc8                 mov ecx, eax
// 00639abe  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639ac1  894e38               mov dword ptr [esi + 0x38], ecx
// 00639ac4  7e0a                 jle 0x639ad0
// 00639ac6  50                   push eax
// 00639ac7  6a01                 push 1
// 00639ac9  8bce                 mov ecx, esi
// 00639acb  e8f0baffff           call 0x6355c0
// 00639ad0  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639ad3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639ad6  881c08               mov byte ptr [eax + ecx], bl
// 00639ad9  ff4640               inc dword ptr [esi + 0x40]
// 00639adc  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639adf  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639ae2  8a5f01               mov bl, byte ptr [edi + 1]
// 00639ae5  41                   inc ecx
// 00639ae6  3bc1                 cmp eax, ecx
// 00639ae8  7c02                 jl 0x639aec
// 00639aea  8bc8                 mov ecx, eax
// 00639aec  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639aef  894e38               mov dword ptr [esi + 0x38], ecx
// 00639af2  7e0a                 jle 0x639afe
// 00639af4  50                   push eax
// 00639af5  6a01                 push 1
// 00639af7  8bce                 mov ecx, esi
// 00639af9  e8c2baffff           call 0x6355c0
// 00639afe  8b5640               mov edx, dword ptr [esi + 0x40]
// 00639b01  8b4634               mov eax, dword ptr [esi + 0x34]
// 00639b04  881c02               mov byte ptr [edx + eax], bl
// 00639b07  ff4640               inc dword ptr [esi + 0x40]
// 00639b0a  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639b0d  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639b10  8a1f                 mov bl, byte ptr [edi]
// 00639b12  41                   inc ecx
// 00639b13  3bc1                 cmp eax, ecx
// 00639b15  7c02                 jl 0x639b19
// 00639b17  8bc8                 mov ecx, eax
// 00639b19  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639b1c  894e38               mov dword ptr [esi + 0x38], ecx
// 00639b1f  7e0a                 jle 0x639b2b
// 00639b21  50                   push eax
// 00639b22  6a01                 push 1
// 00639b24  8bce                 mov ecx, esi
// 00639b26  e895baffff           call 0x6355c0
// 00639b2b  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639b2e  8b5634               mov edx, dword ptr [esi + 0x34]
// 00639b31  8b442410             mov eax, dword ptr [esp + 0x10]
// 00639b35  881c11               mov byte ptr [ecx + edx], bl
// 00639b38  ff4640               inc dword ptr [esi + 0x40]
// 00639b3b  8b4010               mov eax, dword ptr [eax + 0x10]
// 00639b3e  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639b41  45                   inc ebp
// 00639b42  3be8                 cmp ebp, eax
// 00639b44  0f8c56ffffff         jl 0x639aa0
// 00639b4a  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00639b4f  0f8932ffffff         jns 0x639a87
// 00639b55  e91f010000           jmp 0x639c79
// 00639b5a  2bc5                 sub eax, ebp
// 00639b5c  8944241c             mov dword ptr [esp + 0x1c], eax
// 00639b60  0f8813010000         js 0x639c79
// 00639b66  eb0c                 jmp 0x639b74
// 00639b68  eb06                 jmp 0x639b70
// 00639b6a  8d9b00000000         lea ebx, [ebx]
// 00639b70  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00639b74  8b4710               mov eax, dword ptr [edi + 0x10]
// 00639b77  33d2                 xor edx, edx
// 00639b79  89542414             mov dword ptr [esp + 0x14], edx
// 00639b7d  85c0                 test eax, eax
// 00639b7f  0f8ee9000000         jle 0x639c6e
// 00639b85  8d6a01               lea ebp, [edx + 1]
// 00639b88  eb06                 jmp 0x639b90
// 00639b8a  8d9b00000000         lea ebx, [ebx]
// 00639b90  0faf44241c           imul eax, dword ptr [esp + 0x1c]
// 00639b95  03c2                 add eax, edx
// 00639b97  8b542410             mov edx, dword ptr [esp + 0x10]
// 00639b9b  8b5208               mov edx, dword ptr [edx + 8]
// 00639b9e  8a5c8202             mov bl, byte ptr [edx + eax*4 + 2]
// 00639ba2  8d3c82               lea edi, [edx + eax*4]
// 00639ba5  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639ba8  41                   inc ecx
// 00639ba9  3bc1                 cmp eax, ecx
// 00639bab  7c02                 jl 0x639baf
// 00639bad  8bc8                 mov ecx, eax
// 00639baf  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639bb2  894e38               mov dword ptr [esi + 0x38], ecx
// 00639bb5  7e09                 jle 0x639bc0
// 00639bb7  50                   push eax
// 00639bb8  55                   push ebp
// 00639bb9  8bce                 mov ecx, esi
// 00639bbb  e800baffff           call 0x6355c0
// 00639bc0  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639bc3  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639bc6  881c08               mov byte ptr [eax + ecx], bl
// 00639bc9  016e40               add dword ptr [esi + 0x40], ebp
// 00639bcc  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639bcf  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639bd2  8a5f01               mov bl, byte ptr [edi + 1]
// 00639bd5  41                   inc ecx
// 00639bd6  3bc1                 cmp eax, ecx
// 00639bd8  7c02                 jl 0x639bdc
// 00639bda  8bc8                 mov ecx, eax
// 00639bdc  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639bdf  894e38               mov dword ptr [esi + 0x38], ecx
// 00639be2  7e09                 jle 0x639bed
// 00639be4  50                   push eax
// 00639be5  55                   push ebp
// 00639be6  8bce                 mov ecx, esi
// 00639be8  e8d3b9ffff           call 0x6355c0
// 00639bed  8b5640               mov edx, dword ptr [esi + 0x40]
// 00639bf0  8b4634               mov eax, dword ptr [esi + 0x34]
// 00639bf3  881c02               mov byte ptr [edx + eax], bl
// 00639bf6  016e40               add dword ptr [esi + 0x40], ebp
// 00639bf9  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639bfc  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639bff  8a1f                 mov bl, byte ptr [edi]
// 00639c01  41                   inc ecx
// 00639c02  3bc1                 cmp eax, ecx
// 00639c04  7c02                 jl 0x639c08
// 00639c06  8bc8                 mov ecx, eax
// 00639c08  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639c0b  894e38               mov dword ptr [esi + 0x38], ecx
// 00639c0e  7e09                 jle 0x639c19
// 00639c10  50                   push eax
// 00639c11  55                   push ebp
// 00639c12  8bce                 mov ecx, esi
// 00639c14  e8a7b9ffff           call 0x6355c0
// 00639c19  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639c1c  8b5634               mov edx, dword ptr [esi + 0x34]
// 00639c1f  881c11               mov byte ptr [ecx + edx], bl
// 00639c22  016e40               add dword ptr [esi + 0x40], ebp
// 00639c25  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639c28  8b4638               mov eax, dword ptr [esi + 0x38]
// 00639c2b  8a5f03               mov bl, byte ptr [edi + 3]
// 00639c2e  41                   inc ecx
// 00639c2f  3bc1                 cmp eax, ecx
// 00639c31  7c02                 jl 0x639c35
// 00639c33  8bc8                 mov ecx, eax
// 00639c35  3b4e3c               cmp ecx, dword ptr [esi + 0x3c]
// 00639c38  894e38               mov dword ptr [esi + 0x38], ecx
// 00639c3b  7e09                 jle 0x639c46
// 00639c3d  50                   push eax
// 00639c3e  55                   push ebp
// 00639c3f  8bce                 mov ecx, esi
// 00639c41  e87ab9ffff           call 0x6355c0
// 00639c46  8b4640               mov eax, dword ptr [esi + 0x40]
// 00639c49  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00639c4c  8b542414             mov edx, dword ptr [esp + 0x14]
// 00639c50  881c08               mov byte ptr [eax + ecx], bl
// 00639c53  016e40               add dword ptr [esi + 0x40], ebp
// 00639c56  8b442410             mov eax, dword ptr [esp + 0x10]
// 00639c5a  8b4010               mov eax, dword ptr [eax + 0x10]
// 00639c5d  8b4e40               mov ecx, dword ptr [esi + 0x40]
// 00639c60  03d5                 add edx, ebp
// 00639c62  3bd0                 cmp edx, eax
// 00639c64  89542414             mov dword ptr [esp + 0x14], edx
// 00639c68  0f8c22ffffff         jl 0x639b90
// 00639c6e  836c241c01           sub dword ptr [esp + 0x1c], 1
// 00639c73  0f89f7feffff         jns 0x639b70
// 00639c79  68303fb800           push 0xb83f30
// 00639c7e  8bce                 mov ecx, esi
// 00639c80  e80bbbffff           call 0x635790
// 00639c85  5f                   pop edi
// 00639c86  5e                   pop esi
// 00639c87  5d                   pop ebp
// 00639c88  5b                   pop ebx
// 00639c89  83c408               add esp, 8
// 00639c8c  c20400               ret 4
// library rbx2016-g3d/GImage_tga.cpp (function ?encodeTGA@GImage@G3D@@ABEXAAVBinaryOutput@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_tga.cpp
