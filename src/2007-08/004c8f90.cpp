// from server: 74% by EspClaude
// from server: 100% by auto
// roc 2008-06 004d2c70  unit: seg_004d0000  size: 2458 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d2c70
//
// 004d2c70  64a100000000         mov eax, dword ptr fs:[0]
// 004d2c76  6aff                 push -1
// 004d2c78  68169c7c00           push 0x7c9c16
// 004d2c7d  50                   push eax
// 004d2c7e  64892500000000       mov dword ptr fs:[0], esp
// 004d2c85  81ec48010000         sub esp, 0x148
// 004d2c8b  83bc245c01000002     cmp dword ptr [esp + 0x15c], 2
// 004d2c93  56                   push esi
// 004d2c94  57                   push edi
// 004d2c95  8bf1                 mov esi, ecx
// 004d2c97  0f8e66090000         jle 0x4d3603
// 004d2c9d  8bbc2460010000       mov edi, dword ptr [esp + 0x160]
// 004d2ca4  85ff                 test edi, edi
// 004d2ca6  0f8457090000         je 0x4d3603
// 004d2cac  80be8c07000000       cmp byte ptr [esi + 0x78c], 0
// 004d2cb3  c644240b00           mov byte ptr [esp + 0xb], 0
// 004d2cb8  7407                 je 0x4d2cc1
// 004d2cba  c6868c07000000       mov byte ptr [esi + 0x78c], 0
// 004d2cc1  55                   push ebp
// 004d2cc2  8dae28050000         lea ebp, [esi + 0x528]
// 004d2cc8  8bcd                 mov ecx, ebp
// 004d2cca  e8c12c0000           call 0x4d5990
// 004d2ccf  84c0                 test al, al
// 004d2cd1  743e                 je 0x4d2d11
// 004d2cd3  8b8c2468010000       mov ecx, dword ptr [esp + 0x168]
// 004d2cda  8d842468010000       lea eax, [esp + 0x168]
// 004d2ce1  50                   push eax
// 004d2ce2  57                   push edi
// 004d2ce3  51                   push ecx
// 004d2ce4  57                   push edi
// 004d2ce5  8bcd                 mov ecx, ebp
// 004d2ce7  e8842e0000           call 0x4d5b70
// 004d2cec  84c0                 test al, al
// 004d2cee  7521                 jne 0x4d2d11
// 004d2cf0  8b942468010000       mov edx, dword ptr [esp + 0x168]
// 004d2cf7  ff8670040000         inc dword ptr [esi + 0x470]
// 004d2cfd  8d04d500000000       lea eax, [edx*8]
// 004d2d04  018678040000         add dword ptr [esi + 0x478], eax
// 004d2d0a  32c0                 xor al, al
// 004d2d0c  e98b010000           jmp 0x4d2e9c
// 004d2d11  8b842468010000       mov eax, dword ptr [esp + 0x168]
// 004d2d18  ff866c040000         inc dword ptr [esi + 0x46c]
// 004d2d1e  53                   push ebx
// 004d2d1f  33ed                 xor ebp, ebp
// 004d2d21  55                   push ebp
// 004d2d22  8d0cc500000000       lea ecx, [eax*8]
// 004d2d29  018e74040000         add dword ptr [esi + 0x474], ecx
// 004d2d2f  50                   push eax
// 004d2d30  57                   push edi
// 004d2d31  8d4c2450             lea ecx, [esp + 0x50]
// 004d2d35  e8e623fdff           call 0x4a5120
// 004d2d3a  89ac2460010000       mov dword ptr [esp + 0x160], ebp
// 004d2d41  e84a6affff           call 0x4c9790
// 004d2d46  8bd8                 mov ebx, eax
// 004d2d48  895c2418             mov dword ptr [esp + 0x18], ebx
// 004d2d4c  8954241c             mov dword ptr [esp + 0x1c], edx
// 004d2d50  896c2428             mov dword ptr [esp + 0x28], ebp
// 004d2d54  896c2420             mov dword ptr [esp + 0x20], ebp
// 004d2d58  896c2424             mov dword ptr [esp + 0x24], ebp
// 004d2d5c  8d542413             lea edx, [esp + 0x13]
// 004d2d60  52                   push edx
// 004d2d61  8d4c2448             lea ecx, [esp + 0x48]
// 004d2d65  c684246401000001     mov byte ptr [esp + 0x164], 1
// 004d2d6d  e8de22fdff           call 0x4a5050
// 004d2d72  807c241300           cmp byte ptr [esp + 0x13], 0
// 004d2d77  0f84d4020000         je 0x4d3051
// 004d2d7d  6a01                 push 1
// 004d2d7f  6a20                 push 0x20
// 004d2d81  8d442434             lea eax, [esp + 0x34]
// 004d2d85  50                   push eax
// 004d2d86  8d4c2450             lea ecx, [esp + 0x50]
// 004d2d8a  e88124fdff           call 0x4a5210
// 004d2d8f  8d4c2444             lea ecx, [esp + 0x44]
// 004d2d93  51                   push ecx
// 004d2d94  8d4c2424             lea ecx, [esp + 0x24]
// 004d2d98  e8e3e8ffff           call 0x4d1680
// 004d2d9d  84c0                 test al, al
// 004d2d9f  0f84cf000000         je 0x4d2e74
// 004d2da5  396c2424             cmp dword ptr [esp + 0x24], ebp
// 004d2da9  767d                 jbe 0x4d2e28
// 004d2dab  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d2daf  90                   nop 
// 004d2db0  8b14e8               mov edx, dword ptr [eax + ebp*8]
// 004d2db3  3b54e804             cmp edx, dword ptr [eax + ebp*8 + 4]
// 004d2db7  0f87b7000000         ja 0x4d2e74
// 004d2dbd  8bfa                 mov edi, edx
// 004d2dbf  3bff                 cmp edi, edi
// 004d2dc1  725e                 jb 0x4d2e21
// 004d2dc3  3b7ce804             cmp edi, dword ptr [eax + ebp*8 + 4]
// 004d2dc7  7758                 ja 0x4d2e21
// 004d2dc9  8d442414             lea eax, [esp + 0x14]
// 004d2dcd  50                   push eax
// 004d2dce  57                   push edi
// 004d2dcf  8d4e38               lea ecx, [esi + 0x38]
// 004d2dd2  c644241b01           mov byte ptr [esp + 0x1b], 1
// 004d2dd7  e8a4e9ffff           call 0x4d1780
// 004d2ddc  84c0                 test al, al
// 004d2dde  7412                 je 0x4d2df2
// 004d2de0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004d2de4  33c0                 xor eax, eax
// 004d2de6  894130               mov dword ptr [ecx + 0x30], eax
// 004d2de9  8b542414             mov edx, dword ptr [esp + 0x14]
// 004d2ded  894234               mov dword ptr [edx + 0x34], eax
// 004d2df0  eb08                 jmp 0x4d2dfa
// 004d2df2  ff8680040000         inc dword ptr [esi + 0x480]
// 004d2df8  33c0                 xor eax, eax
// 004d2dfa  39464c               cmp dword ptr [esi + 0x4c], eax
// 004d2dfd  7508                 jne 0x4d2e07
// 004d2dff  8986b8000000         mov dword ptr [esi + 0xb8], eax
// 004d2e05  eb0a                 jmp 0x4d2e11
// 004d2e07  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004d2e0b  899eb8000000         mov dword ptr [esi + 0xb8], ebx
// 004d2e11  8986bc000000         mov dword ptr [esi + 0xbc], eax
// 004d2e17  8b442420             mov eax, dword ptr [esp + 0x20]
// 004d2e1b  47                   inc edi
// 004d2e1c  3b3ce8               cmp edi, dword ptr [eax + ebp*8]
// 004d2e1f  73a2                 jae 0x4d2dc3
// 004d2e21  45                   inc ebp
// 004d2e22  3b6c2424             cmp ebp, dword ptr [esp + 0x24]
// 004d2e26  7288                 jb 0x4d2db0
// 004d2e28  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004d2e2c  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 004d2e30  b9e8030000           mov ecx, 0x3e8
// 004d2e35  f7e1                 mul ecx
// 004d2e37  8bcb                 mov ecx, ebx
// 004d2e39  2bc8                 sub ecx, eax
// 004d2e3b  8bc5                 mov eax, ebp
// 004d2e3d  1bc2                 sbb eax, edx
// 004d2e3f  8986fc040000         mov dword ptr [esi + 0x4fc], eax
// 004d2e45  8b86f0040000         mov eax, dword ptr [esi + 0x4f0]
// 004d2e4b  898ef8040000         mov dword ptr [esi + 0x4f8], ecx
// 004d2e51  8b8ef4040000         mov ecx, dword ptr [esi + 0x4f4]
// 004d2e57  8bd0                 mov edx, eax
// 004d2e59  0bd1                 or edx, ecx
// 004d2e5b  7459                 je 0x4d2eb6
// 004d2e5d  51                   push ecx
// 004d2e5e  8b8ee8040000         mov ecx, dword ptr [esi + 0x4e8]
// 004d2e64  50                   push eax
// 004d2e65  8b86ec040000         mov eax, dword ptr [esi + 0x4ec]
// 004d2e6b  50                   push eax
// 004d2e6c  51                   push ecx
// 004d2e6d  e8beed1c00           call 0x6a1c30
// 004d2e72  eb4e                 jmp 0x4d2ec2
// 004d2e74  8d4c2420             lea ecx, [esp + 0x20]
// 004d2e78  c684246001000000     mov byte ptr [esp + 0x160], 0
// 004d2e80  e85bf6ffff           call 0x4d24e0
// 004d2e85  8d4c2444             lea ecx, [esp + 0x44]
// 004d2e89  c7842460010000ffffffff mov dword ptr [esp + 0x160], 0xffffffff
// 004d2e94  e80723fdff           call 0x4a51a0
// 004d2e99  32c0                 xor al, al
// 004d2e9b  5b                   pop ebx
// 004d2e9c  5d                   pop ebp
// 004d2e9d  8b8c2450010000       mov ecx, dword ptr [esp + 0x150]
// 004d2ea4  5f                   pop edi
// 004d2ea5  5e                   pop esi
// 004d2ea6  64890d00000000       mov dword ptr fs:[0], ecx
// 004d2ead  81c454010000         add esp, 0x154
// 004d2eb3  c21800               ret 0x18
// 004d2eb6  8b86f8040000         mov eax, dword ptr [esi + 0x4f8]
// 004d2ebc  8b96fc040000         mov edx, dword ptr [esi + 0x4fc]
// 004d2ec2  80be0405000000       cmp byte ptr [esi + 0x504], 0
// 004d2ec9  0f8482010000         je 0x4d3051
// 004d2ecf  3bae1c050000         cmp ebp, dword ptr [esi + 0x51c]
// 004d2ed5  0f8c76010000         jl 0x4d3051
// 004d2edb  7f0c                 jg 0x4d2ee9
// 004d2edd  3b9e18050000         cmp ebx, dword ptr [esi + 0x518]
// 004d2ee3  0f8268010000         jb 0x4d3051
// 004d2ee9  33ff                 xor edi, edi
// 004d2eeb  57                   push edi
// 004d2eec  6a06                 push 6
// 004d2eee  52                   push edx
// 004d2eef  50                   push eax
// 004d2ef0  e8dbe71c00           call 0x6a16d0
// 004d2ef5  57                   push edi
// 004d2ef6  6a05                 push 5
// 004d2ef8  52                   push edx
// 004d2ef9  50                   push eax
// 004d2efa  e831ed1c00           call 0x6a1c30
// 004d2eff  8b8efc040000         mov ecx, dword ptr [esi + 0x4fc]
// 004d2f05  05e8030000           add eax, 0x3e8
// 004d2f0a  13d7                 adc edx, edi
// 004d2f0c  3bca                 cmp ecx, edx
// 004d2f0e  0f8f98000000         jg 0x4d2fac
// 004d2f14  7c0e                 jl 0x4d2f24
// 004d2f16  8b96f8040000         mov edx, dword ptr [esi + 0x4f8]
// 004d2f1c  3bd0                 cmp edx, eax
// 004d2f1e  0f8788000000         ja 0x4d2fac
// 004d2f24  dfaed8040000         fild qword ptr [esi + 0x4d8]
// 004d2f2a  83ec08               sub esp, 8
// 004d2f2d  dc0d006b8200         fmul qword ptr [0x826b00]
// 004d2f33  dd1c24               fstp qword ptr [esp]
// 004d2f36  e845baffff           call 0x4ce980
// 004d2f3b  83c408               add esp, 8
// 004d2f3e  e8e3e81c00           call 0x6a1826
// 004d2f43  8b8edc040000         mov ecx, dword ptr [esi + 0x4dc]
// 004d2f49  3bd1                 cmp edx, ecx
// 004d2f4b  8bbed8040000         mov edi, dword ptr [esi + 0x4d8]
// 004d2f51  7f22                 jg 0x4d2f75
// 004d2f53  7c04                 jl 0x4d2f59
// 004d2f55  3bc7                 cmp eax, edi
// 004d2f57  731c                 jae 0x4d2f75
// 004d2f59  2986e0040000         sub dword ptr [esi + 0x4e0], eax
// 004d2f5f  1996e4040000         sbb dword ptr [esi + 0x4e4], edx
// 004d2f65  2bf8                 sub edi, eax
// 004d2f67  1bca                 sbb ecx, edx
// 004d2f69  89bed8040000         mov dword ptr [esi + 0x4d8], edi
// 004d2f6f  898edc040000         mov dword ptr [esi + 0x4dc], ecx
// 004d2f75  8b86f8040000         mov eax, dword ptr [esi + 0x4f8]
// 004d2f7b  0186e8040000         add dword ptr [esi + 0x4e8], eax
// 004d2f81  8b8efc040000         mov ecx, dword ptr [esi + 0x4fc]
// 004d2f87  899e10050000         mov dword ptr [esi + 0x510], ebx
// 004d2f8d  118eec040000         adc dword ptr [esi + 0x4ec], ecx
// 004d2f93  8386f004000001       add dword ptr [esi + 0x4f0], 1
// 004d2f9a  89ae14050000         mov dword ptr [esi + 0x514], ebp
// 004d2fa0  8396f404000000       adc dword ptr [esi + 0x4f4], 0
// 004d2fa7  e989000000           jmp 0x4d3035
// 004d2fac  dfaed8040000         fild qword ptr [esi + 0x4d8]
// 004d2fb2  83ec08               sub esp, 8
// 004d2fb5  dc0df86a8200         fmul qword ptr [0x826af8]
// 004d2fbb  dd1c24               fstp qword ptr [esp]
// 004d2fbe  e8bdb9ffff           call 0x4ce980
// 004d2fc3  83c408               add esp, 8
// 004d2fc6  e85be81c00           call 0x6a1826
// 004d2fcb  0186e0040000         add dword ptr [esi + 0x4e0], eax
// 004d2fd1  899e08050000         mov dword ptr [esi + 0x508], ebx
// 004d2fd7  89ae0c050000         mov dword ptr [esi + 0x50c], ebp
// 004d2fdd  1196e4040000         adc dword ptr [esi + 0x4e4], edx
// 004d2fe3  0186d8040000         add dword ptr [esi + 0x4d8], eax
// 004d2fe9  1196dc040000         adc dword ptr [esi + 0x4dc], edx
// 004d2fef  39bedc040000         cmp dword ptr [esi + 0x4dc], edi
// 004d2ff5  7c3e                 jl 0x4d3035
// 004d2ff7  7f0c                 jg 0x4d3005
// 004d2ff9  81bed8040000a0860100 cmp dword ptr [esi + 0x4d8], 0x186a0
// 004d3003  7630                 jbe 0x4d3035
// 004d3005  c786d8040000a0860100 mov dword ptr [esi + 0x4d8], 0x186a0
// 004d300f  89bedc040000         mov dword ptr [esi + 0x4dc], edi
// 004d3015  c786e804000040420f00 mov dword ptr [esi + 0x4e8], 0xf4240
// 004d301f  89beec040000         mov dword ptr [esi + 0x4ec], edi
// 004d3025  c786f004000001000000 mov dword ptr [esi + 0x4f0], 1
// 004d302f  89bef4040000         mov dword ptr [esi + 0x4f4], edi
// 004d3035  8b96f8040000         mov edx, dword ptr [esi + 0x4f8]
// 004d303b  8b86fc040000         mov eax, dword ptr [esi + 0x4fc]
// 004d3041  03d3                 add edx, ebx
// 004d3043  13c5                 adc eax, ebp
// 004d3045  899618050000         mov dword ptr [esi + 0x518], edx
// 004d304b  89861c050000         mov dword ptr [esi + 0x51c], eax
// 004d3051  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 004d3055  8d7801               lea edi, [eax + 1]
// 004d3058  3b7c2444             cmp edi, dword ptr [esp + 0x44]
// 004d305c  7f1f                 jg 0x4d307d
// 004d305e  8bc8                 mov ecx, eax
// 004d3060  83e107               and ecx, 7
// 004d3063  ba80000000           mov edx, 0x80
// 004d3068  d3fa                 sar edx, cl
// 004d306a  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 004d306e  c1f803               sar eax, 3
// 004d3071  841408               test byte ptr [eax + ecx], dl
// 004d3074  897c244c             mov dword ptr [esp + 0x4c], edi
// 004d3078  0f95c0               setne al
// 004d307b  eb04                 jmp 0x4d3081
// 004d307d  8a442413             mov al, byte ptr [esp + 0x13]
// 004d3081  84c0                 test al, al
// 004d3083  7414                 je 0x4d3099
// 004d3085  6a01                 push 1
// 004d3087  8d8600050000         lea eax, [esi + 0x500]
// 004d308d  6a20                 push 0x20
// 004d308f  50                   push eax
// 004d3090  8d4c2450             lea ecx, [esp + 0x50]
// 004d3094  e87721fdff           call 0x4a5210
// 004d3099  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004d309d  52                   push edx
// 004d309e  53                   push ebx
// 004d309f  8d44244c             lea eax, [esp + 0x4c]
// 004d30a3  50                   push eax
// 004d30a4  8bce                 mov ecx, esi
// 004d30a6  e885d5ffff           call 0x4d0630
// 004d30ab  8be8                 mov ebp, eax
// 004d30ad  896c2414             mov dword ptr [esp + 0x14], ebp
// 004d30b1  85ed                 test ebp, ebp
// 004d30b3  752d                 jne 0x4d30e2
// 004d30b5  8d4c2420             lea ecx, [esp + 0x20]
// 004d30b9  88842460010000       mov byte ptr [esp + 0x160], al
// 004d30c0  e81bf4ffff           call 0x4d24e0
// 004d30c5  8d4c2444             lea ecx, [esp + 0x44]
// 004d30c9  c7842460010000ffffffff mov dword ptr [esp + 0x160], 0xffffffff
// 004d30d4  e8c720fdff           call 0x4a51a0
// 004d30d9  8a442413             mov al, byte ptr [esp + 0x13]
// 004d30dd  e9b9fdffff           jmp 0x4d2e9b
// 004d30e2  8b8c2478010000       mov ecx, dword ptr [esp + 0x178]
// 004d30e9  33ff                 xor edi, edi
// 004d30eb  397904               cmp dword ptr [ecx + 4], edi
// 004d30ee  765b                 jbe 0x4d314b
// 004d30f0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004d30f4  8b442418             mov eax, dword ptr [esp + 0x18]
// 004d30f8  57                   push edi
// 004d30f9  68e8030000           push 0x3e8
// 004d30fe  52                   push edx
// 004d30ff  50                   push eax
// 004d3100  e82beb1c00           call 0x6a1c30
// 004d3105  8bd8                 mov ebx, eax
// 004d3107  89542430             mov dword ptr [esp + 0x30], edx
// 004d310b  eb03                 jmp 0x4d3110
// 004d310d  8d4900               lea ecx, [ecx]
// 004d3110  8b8c2478010000       mov ecx, dword ptr [esp + 0x178]
// 004d3117  8b11                 mov edx, dword ptr [ecx]
// 004d3119  8b0cba               mov ecx, dword ptr [edx + edi*4]
// 004d311c  8b942474010000       mov edx, dword ptr [esp + 0x174]
// 004d3123  8b01                 mov eax, dword ptr [ecx]
// 004d3125  8b4028               mov eax, dword ptr [eax + 0x28]
// 004d3128  6a00                 push 0
// 004d312a  53                   push ebx
// 004d312b  52                   push edx
// 004d312c  8b94247c010000       mov edx, dword ptr [esp + 0x17c]
// 004d3133  52                   push edx
// 004d3134  8b9688070000         mov edx, dword ptr [esi + 0x788]
// 004d313a  52                   push edx
// 004d313b  55                   push ebp
// 004d313c  ffd0                 call eax
// 004d313e  8b8c2478010000       mov ecx, dword ptr [esp + 0x178]
// 004d3145  47                   inc edi
// 004d3146  3b7904               cmp edi, dword ptr [ecx + 4]
// 004d3149  72c5                 jb 0x4d3110
// 004d314b  80bec804000000       cmp byte ptr [esi + 0x4c8], 0
// 004d3152  7454                 je 0x4d31a8
// 004d3154  8b86b4040000         mov eax, dword ptr [esi + 0x4b4]
// 004d315a  50                   push eax
// 004d315b  e81ad51c00           call 0x6a067a
// 004d3160  33c9                 xor ecx, ecx
// 004d3162  b800020000           mov eax, 0x200
// 004d3167  ba08000000           mov edx, 8
// 004d316c  f7e2                 mul edx
// 004d316e  0f90c1               seto cl
// 004d3171  f7d9                 neg ecx
// 004d3173  0bc8                 or ecx, eax
// 004d3175  51                   push ecx
// 004d3176  e8a5d71c00           call 0x6a0920
// 004d317b  8986b4040000         mov dword ptr [esi + 0x4b4], eax
// 004d3181  83c408               add esp, 8
// 004d3184  33c0                 xor eax, eax
// 004d3186  c786c004000000020000 mov dword ptr [esi + 0x4c0], 0x200
// 004d3190  8986b8040000         mov dword ptr [esi + 0x4b8], eax
// 004d3196  8986bc040000         mov dword ptr [esi + 0x4bc], eax
// 004d319c  8986c4040000         mov dword ptr [esi + 0x4c4], eax
// 004d31a2  8886c8040000         mov byte ptr [esi + 0x4c8], al
// 004d31a8  8b4d00               mov ecx, dword ptr [ebp]
// 004d31ab  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004d31ae  8bd9                 mov ebx, ecx
// 004d31b0  2b9ec4040000         sub ebx, dword ptr [esi + 0x4c4]
// 004d31b6  83f804               cmp eax, 4
// 004d31b9  740a                 je 0x4d31c5
// 004d31bb  83f803               cmp eax, 3
// 004d31be  7405                 je 0x4d31c5
// 004d31c0  83f802               cmp eax, 2
// 004d31c3  750f                 jne 0x4d31d4
// 004d31c5  ff8624040000         inc dword ptr [esi + 0x424]
// 004d31cb  51                   push ecx
// 004d31cc  8d4e1c               lea ecx, [esi + 0x1c]
// 004d31cf  e85ce3ffff           call 0x4d1530
// 004d31d4  85db                 test ebx, ebx
// 004d31d6  7544                 jne 0x4d321c
// 004d31d8  8b96b8040000         mov edx, dword ptr [esi + 0x4b8]
// 004d31de  8b8ebc040000         mov ecx, dword ptr [esi + 0x4bc]
// 004d31e4  8dbeb4040000         lea edi, [esi + 0x4b4]
// 004d31ea  3bd1                 cmp edx, ecx
// 004d31ec  7706                 ja 0x4d31f4
// 004d31ee  2bca                 sub ecx, edx
// 004d31f0  8bc1                 mov eax, ecx
// 004d31f2  eb07                 jmp 0x4d31fb
// 004d31f4  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d31f7  2bc2                 sub eax, edx
// 004d31f9  03c1                 add eax, ecx
// 004d31fb  85c0                 test eax, eax
// 004d31fd  7412                 je 0x4d3211
// 004d31ff  ff4704               inc dword ptr [edi + 4]
// 004d3202  8b4704               mov eax, dword ptr [edi + 4]
// 004d3205  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004d3208  7507                 jne 0x4d3211
// 004d320a  c7470400000000       mov dword ptr [edi + 4], 0
// 004d3211  ff86c4040000         inc dword ptr [esi + 0x4c4]
// 004d3217  e9f1000000           jmp 0x4d330d
// 004d321c  81fb00000080         cmp ebx, 0x80000000
// 004d3222  760b                 jbe 0x4d322f
// 004d3224  ff868c040000         inc dword ptr [esi + 0x48c]
// 004d322a  e967030000           jmp 0x4d3596
// 004d322f  8b96b8040000         mov edx, dword ptr [esi + 0x4b8]
// 004d3235  8b8ebc040000         mov ecx, dword ptr [esi + 0x4bc]
// 004d323b  8dbeb4040000         lea edi, [esi + 0x4b4]
// 004d3241  3bd1                 cmp edx, ecx
// 004d3243  7706                 ja 0x4d324b
// 004d3245  2bca                 sub ecx, edx
// 004d3247  8bc1                 mov eax, ecx
// 004d3249  eb07                 jmp 0x4d3252
// 004d324b  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d324e  2bc2                 sub eax, edx
// 004d3250  03c1                 add eax, ecx
// 004d3252  3bd8                 cmp ebx, eax
// 004d3254  735f                 jae 0x4d32b5
// 004d3256  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004d3259  8bc2                 mov eax, edx
// 004d325b  8d1418               lea edx, [eax + ebx]
// 004d325e  3bd1                 cmp edx, ecx
// 004d3260  720b                 jb 0x4d326d
// 004d3262  2bc1                 sub eax, ecx
// 004d3264  8b0f                 mov ecx, dword ptr [edi]
// 004d3266  03c3                 add eax, ebx
// 004d3268  8d04c1               lea eax, [ecx + eax*8]
// 004d326b  eb05                 jmp 0x4d3272
// 004d326d  8b07                 mov eax, dword ptr [edi]
// 004d326f  8d04d0               lea eax, [eax + edx*8]
// 004d3272  8b08                 mov ecx, dword ptr [eax]
// 004d3274  0b4804               or ecx, dword ptr [eax + 4]
// 004d3277  74ab                 je 0x4d3224
// 004d3279  8b4704               mov eax, dword ptr [edi + 4]
// 004d327c  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004d327f  8d1418               lea edx, [eax + ebx]
// 004d3282  3bd1                 cmp edx, ecx
// 004d3284  721b                 jb 0x4d32a1
// 004d3286  8b17                 mov edx, dword ptr [edi]
// 004d3288  2bc1                 sub eax, ecx
// 004d328a  03c3                 add eax, ebx
// 004d328c  8d04c2               lea eax, [edx + eax*8]
// 004d328f  c70000000000         mov dword ptr [eax], 0
// 004d3295  c7400400000000       mov dword ptr [eax + 4], 0
// 004d329c  e96c000000           jmp 0x4d330d
// 004d32a1  8b07                 mov eax, dword ptr [edi]
// 004d32a3  8d04d0               lea eax, [eax + edx*8]
// 004d32a6  c70000000000         mov dword ptr [eax], 0
// 004d32ac  c7400400000000       mov dword ptr [eax + 4], 0
// 004d32b3  eb58                 jmp 0x4d330d
// 004d32b5  8b5704               mov edx, dword ptr [edi + 4]
// 004d32b8  8b4f08               mov ecx, dword ptr [edi + 8]
// 004d32bb  3bd1                 cmp edx, ecx
// 004d32bd  7706                 ja 0x4d32c5
// 004d32bf  2bca                 sub ecx, edx
// 004d32c1  8bc1                 mov eax, ecx
// 004d32c3  eb07                 jmp 0x4d32cc
// 004d32c5  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d32c8  2bc2                 sub eax, edx
// 004d32ca  03c1                 add eax, ecx
// 004d32cc  3bd8                 cmp ebx, eax
// 004d32ce  7627                 jbe 0x4d32f7
// 004d32d0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004d32d4  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004d32d8  81c100879303         add ecx, 0x3938700
// 004d32de  8d44243c             lea eax, [esp + 0x3c]
// 004d32e2  83d200               adc edx, 0
// 004d32e5  894c243c             mov dword ptr [esp + 0x3c], ecx
// 004d32e9  50                   push eax
// 004d32ea  8bcf                 mov ecx, edi
// 004d32ec  89542444             mov dword ptr [esp + 0x44], edx
// 004d32f0  e8cbbcffff           call 0x4cefc0
// 004d32f5  ebbe                 jmp 0x4d32b5
// 004d32f7  8d4c2434             lea ecx, [esp + 0x34]
// 004d32fb  33c0                 xor eax, eax
// 004d32fd  51                   push ecx
// 004d32fe  8bcf                 mov ecx, edi
// 004d3300  89442438             mov dword ptr [esp + 0x38], eax
// 004d3304  8944243c             mov dword ptr [esp + 0x3c], eax
// 004d3308  e8b3bcffff           call 0x4cefc0
// 004d330d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004d3311  8b5704               mov edx, dword ptr [edi + 4]
// 004d3314  8b4f08               mov ecx, dword ptr [edi + 8]
// 004d3317  3bd1                 cmp edx, ecx
// 004d3319  7706                 ja 0x4d3321
// 004d331b  2bca                 sub ecx, edx
// 004d331d  8bc1                 mov eax, ecx
// 004d331f  eb07                 jmp 0x4d3328
// 004d3321  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d3324  2bc2                 sub eax, edx
// 004d3326  03c1                 add eax, ecx
// 004d3328  85c0                 test eax, eax
// 004d332a  7634                 jbe 0x4d3360
// 004d332c  8b07                 mov eax, dword ptr [edi]
// 004d332e  8bca                 mov ecx, edx
// 004d3330  395cc804             cmp dword ptr [eax + ecx*8 + 4], ebx
// 004d3334  8b14c8               mov edx, dword ptr [eax + ecx*8]
// 004d3337  7f27                 jg 0x4d3360
// 004d3339  7c06                 jl 0x4d3341
// 004d333b  3b542418             cmp edx, dword ptr [esp + 0x18]
// 004d333f  731f                 jae 0x4d3360
// 004d3341  b901000000           mov ecx, 1
// 004d3346  014f04               add dword ptr [edi + 4], ecx
// 004d3349  8b4704               mov eax, dword ptr [edi + 4]
// 004d334c  3b470c               cmp eax, dword ptr [edi + 0xc]
// 004d334f  7507                 jne 0x4d3358
// 004d3351  c7470400000000       mov dword ptr [edi + 4], 0
// 004d3358  018ec4040000         add dword ptr [esi + 0x4c4], ecx
// 004d335e  ebb1                 jmp 0x4d3311
// 004d3360  8b9ec0040000         mov ebx, dword ptr [esi + 0x4c0]
// 004d3366  ff8684040000         inc dword ptr [esi + 0x484]
// 004d336c  81fb00020000         cmp ebx, 0x200
// 004d3372  7625                 jbe 0x4d3399
// 004d3374  8b5704               mov edx, dword ptr [edi + 4]
// 004d3377  8b4f08               mov ecx, dword ptr [edi + 8]
// 004d337a  3bd1                 cmp edx, ecx
// 004d337c  7706                 ja 0x4d3384
// 004d337e  2bca                 sub ecx, edx
// 004d3380  8bc1                 mov eax, ecx
// 004d3382  eb07                 jmp 0x4d338b
// 004d3384  8b470c               mov eax, dword ptr [edi + 0xc]
// 004d3387  2bc2                 sub eax, edx
// 004d3389  03c1                 add eax, ecx
// 004d338b  8d1440               lea edx, [eax + eax*2]
// 004d338e  3bda                 cmp ebx, edx
// 004d3390  7607                 jbe 0x4d3399
// 004d3392  8bcf                 mov ecx, edi
// 004d3394  e827bdffff           call 0x4cf0c0
// 004d3399  837d2400             cmp dword ptr [ebp + 0x24], 0
// 004d339d  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 004d33a1  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004d33a5  7609                 jbe 0x4d33b0
// 004d33a7  53                   push ebx
// 004d33a8  57                   push edi
// 004d33a9  8bce                 mov ecx, esi
// 004d33ab  e810f0ffff           call 0x4d23c0
// 004d33b0  8b4510               mov eax, dword ptr [ebp + 0x10]
// 004d33b3  83f804               cmp eax, 4
// 004d33b6  0f8448010000         je 0x4d3504
// 004d33bc  83f801               cmp eax, 1
// 004d33bf  0f843f010000         je 0x4d3504
// 004d33c5  837d2400             cmp dword ptr [ebp + 0x24], 0
// 004d33c9  762f                 jbe 0x4d33fa
// 004d33cb  83f803               cmp eax, 3
// 004d33ce  7404                 je 0x4d33d4
// 004d33d0  c64514ff             mov byte ptr [ebp + 0x14], 0xff
// 004d33d4  53                   push ebx
// 004d33d5  57                   push edi
// 004d33d6  55                   push ebp
// 004d33d7  8bce                 mov ecx, esi
// 004d33d9  e842ecffff           call 0x4d2020
// 004d33de  0fb7451c             movzx eax, word ptr [ebp + 0x1c]
// 004d33e2  53                   push ebx
// 004d33e3  57                   push edi
// 004d33e4  50                   push eax
// 004d33e5  8bce                 mov ecx, esi
// 004d33e7  e814eeffff           call 0x4d2200
// 004d33ec  8be8                 mov ebp, eax
// 004d33ee  896c2414             mov dword ptr [esp + 0x14], ebp
// 004d33f2  85ed                 test ebp, ebp
// 004d33f4  0f84b4010000         je 0x4d35ae
// 004d33fa  837d1003             cmp dword ptr [ebp + 0x10], 3
// 004d33fe  0f85ee000000         jne 0x4d34f2
// 004d3404  8a5d14               mov bl, byte ptr [ebp + 0x14]
// 004d3407  80fb20               cmp bl, 0x20
// 004d340a  0f8386010000         jae 0x4d3596
// 004d3410  0fb6cb               movzx ecx, bl
// 004d3413  8b948ed4020000       mov edx, dword ptr [esi + ecx*4 + 0x2d4]
// 004d341a  3b5518               cmp edx, dword ptr [ebp + 0x18]
// 004d341d  0f85bc000000         jne 0x4d34df
// 004d3423  8d442414             lea eax, [esp + 0x14]
// 004d3427  bf01000000           mov edi, 1
// 004d342c  01be68040000         add dword ptr [esi + 0x468], edi
// 004d3432  8d4e0c               lea ecx, [esi + 0xc]
// 004d3435  50                   push eax
// 004d3436  e8a5b9ffff           call 0x4cede0
// 004d343b  0fb6eb               movzx ebp, bl
// 004d343e  01bcaed4020000       add dword ptr [esi + ebp*4 + 0x2d4], edi
// 004d3445  3b6e04               cmp ebp, dword ptr [esi + 4]
// 004d3448  0f8360010000         jae 0x4d35ae
// 004d344e  8b0e                 mov ecx, dword ptr [esi]
// 004d3450  8b3ca9               mov edi, dword ptr [ecx + ebp*4]
// 004d3453  85ff                 test edi, edi
// 004d3455  0f8453010000         je 0x4d35ae
// 004d345b  833f00               cmp dword ptr [edi], 0
// 004d345e  0f864a010000         jbe 0x4d35ae
// 004d3464  8b4704               mov eax, dword ptr [edi + 4]
// 004d3467  85c0                 test eax, eax
// 004d3469  7403                 je 0x4d346e
// 004d346b  894708               mov dword ptr [edi + 8], eax
// 004d346e  8b07                 mov eax, dword ptr [edi]
// 004d3470  32c9                 xor cl, cl
// 004d3472  85c0                 test eax, eax
// 004d3474  0f8e34010000         jle 0x4d35ae
// 004d347a  89442414             mov dword ptr [esp + 0x14], eax
// 004d347e  8bff                 mov edi, edi
// 004d3480  8b4708               mov eax, dword ptr [edi + 8]
// 004d3483  8b10                 mov edx, dword ptr [eax]
// 004d3485  8b5218               mov edx, dword ptr [edx + 0x18]
// 004d3488  3b94aed4020000       cmp edx, dword ptr [esi + ebp*4 + 0x2d4]
// 004d348f  7525                 jne 0x4d34b6
// 004d3491  8b18                 mov ebx, dword ptr [eax]
// 004d3493  8bcf                 mov ecx, edi
// 004d3495  e8f6bfffff           call 0x4cf490
// 004d349a  8d44242c             lea eax, [esp + 0x2c]
// 004d349e  50                   push eax
// 004d349f  8d4e0c               lea ecx, [esi + 0xc]
// 004d34a2  895c2430             mov dword ptr [esp + 0x30], ebx
// 004d34a6  e835b9ffff           call 0x4cede0
// 004d34ab  ff84aed4020000       inc dword ptr [esi + ebp*4 + 0x2d4]
// 004d34b2  b101                 mov cl, 1
// 004d34b4  eb10                 jmp 0x4d34c6
// 004d34b6  833f00               cmp dword ptr [edi], 0
// 004d34b9  740b                 je 0x4d34c6
// 004d34bb  8b4008               mov eax, dword ptr [eax + 8]
// 004d34be  3b4704               cmp eax, dword ptr [edi + 4]
// 004d34c1  7403                 je 0x4d34c6
// 004d34c3  894708               mov dword ptr [edi + 8], eax
// 004d34c6  836c241401           sub dword ptr [esp + 0x14], 1
// 004d34cb  75b3                 jne 0x4d3480
// 004d34cd  84c9                 test cl, cl
// 004d34cf  0f84d9000000         je 0x4d35ae
// 004d34d5  833f00               cmp dword ptr [edi], 0
// 004d34d8  778a                 ja 0x4d3464
// 004d34da  e9cf000000           jmp 0x4d35ae
// 004d34df  ff8664040000         inc dword ptr [esi + 0x464]
// 004d34e5  55                   push ebp
// 004d34e6  8bce                 mov ecx, esi
// 004d34e8  e8f3ddffff           call 0x4d12e0
// 004d34ed  e9bc000000           jmp 0x4d35ae
// 004d34f2  8d4c2414             lea ecx, [esp + 0x14]
// 004d34f6  51                   push ecx
// 004d34f7  8d4e0c               lea ecx, [esi + 0xc]
// 004d34fa  e8e1b8ffff           call 0x4cede0
// 004d34ff  e9aa000000           jmp 0x4d35ae
// 004d3504  8a4514               mov al, byte ptr [ebp + 0x14]
// 004d3507  3c20                 cmp al, 0x20
// 004d3509  0f8387000000         jae 0x4d3596
// 004d350f  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004d3512  0fb6d0               movzx edx, al
// 004d3515  8b849654030000       mov eax, dword ptr [esi + edx*4 + 0x354]
// 004d351c  3dffffff7f           cmp eax, 0x7fffffff
// 004d3521  760c                 jbe 0x4d352f
// 004d3523  8d9002000080         lea edx, [eax - 0x7ffffffe]
// 004d3529  3bca                 cmp ecx, edx
// 004d352b  7210                 jb 0x4d353d
// 004d352d  eb0a                 jmp 0x4d3539
// 004d352f  8d9000000080         lea edx, [eax - 0x80000000]
// 004d3535  3bca                 cmp ecx, edx
// 004d3537  7357                 jae 0x4d3590
// 004d3539  3bc8                 cmp ecx, eax
// 004d353b  7253                 jb 0x4d3590
// 004d353d  ff8660040000         inc dword ptr [esi + 0x460]
// 004d3543  837d2400             cmp dword ptr [ebp + 0x24], 0
// 004d3547  7629                 jbe 0x4d3572
// 004d3549  53                   push ebx
// 004d354a  57                   push edi
// 004d354b  55                   push ebp
// 004d354c  8bce                 mov ecx, esi
// 004d354e  e8cdeaffff           call 0x4d2020
// 004d3553  0fb7451c             movzx eax, word ptr [ebp + 0x1c]
// 004d3557  53                   push ebx
// 004d3558  57                   push edi
// 004d3559  50                   push eax
// 004d355a  8bce                 mov ecx, esi
// 004d355c  e89fecffff           call 0x4d2200
// 004d3561  89442414             mov dword ptr [esp + 0x14], eax
// 004d3565  85c0                 test eax, eax
// 004d3567  7445                 je 0x4d35ae
// 004d3569  8b4818               mov ecx, dword ptr [eax + 0x18]
// 004d356c  0fb65014             movzx edx, byte ptr [eax + 0x14]
// 004d3570  eb07                 jmp 0x4d3579
// 004d3572  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004d3575  0fb65514             movzx edx, byte ptr [ebp + 0x14]
// 004d3579  41                   inc ecx
// 004d357a  8d442414             lea eax, [esp + 0x14]
// 004d357e  898c9654030000       mov dword ptr [esi + edx*4 + 0x354], ecx
// 004d3585  50                   push eax
// 004d3586  8d4e0c               lea ecx, [esi + 0xc]
// 004d3589  e852b8ffff           call 0x4cede0
// 004d358e  eb1e                 jmp 0x4d35ae
// 004d3590  ff865c040000         inc dword ptr [esi + 0x45c]
// 004d3596  8b453c               mov eax, dword ptr [ebp + 0x3c]
// 004d3599  50                   push eax
// 004d359a  e8dbd01c00           call 0x6a067a
// 004d359f  83c404               add esp, 4
// 004d35a2  55                   push ebp
// 004d35a3  8d8eb0070000         lea ecx, [esi + 0x7b0]
// 004d35a9  e8f2c3ffff           call 0x4cf9a0
// 004d35ae  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004d35b2  8b542418             mov edx, dword ptr [esp + 0x18]
// 004d35b6  51                   push ecx
// 004d35b7  52                   push edx
// 004d35b8  8d44244c             lea eax, [esp + 0x4c]
// 004d35bc  50                   push eax
// 004d35bd  8bce                 mov ecx, esi
// 004d35bf  e86cd0ffff           call 0x4d0630
// 004d35c4  8be8                 mov ebp, eax
// 004d35c6  896c2414             mov dword ptr [esp + 0x14], ebp
// 004d35ca  85ed                 test ebp, ebp
// 004d35cc  0f8510fbffff         jne 0x4d30e2
// 004d35d2  ff8688070000         inc dword ptr [esi + 0x788]
// 004d35d8  8d4c2420             lea ecx, [esp + 0x20]
// 004d35dc  88842460010000       mov byte ptr [esp + 0x160], al
// 004d35e3  e8f8eeffff           call 0x4d24e0
// 004d35e8  8d4c2444             lea ecx, [esp + 0x44]
// 004d35ec  c7842460010000ffffffff mov dword ptr [esp + 0x160], 0xffffffff
// 004d35f7  e8a41bfdff           call 0x4a51a0
// 004d35fc  b001                 mov al, 1
// 004d35fe  e998f8ffff           jmp 0x4d2e9b
// 004d3603  b001                 mov al, 1
// 004d3605  e993f8ffff           jmp 0x4d2e9d
// library openrbx-raknet/ReliabilityLayer.cpp (function ?HandleSocketReceiveFromConnectedPlayer@ReliabilityLayer@@QAE_NPBDHUSystemAddress@@AAV?$List@PAVPluginInterface@@@DataStructures@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
