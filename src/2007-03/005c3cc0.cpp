// from server: 100% by auto
// roc 2007-03 005c3cc0  unit: seg_005c0000  size: 1015 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c3cc0
//
// 005c3cc0  51                   push ecx
// 005c3cc1  53                   push ebx
// 005c3cc2  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005c3cc6  55                   push ebp
// 005c3cc7  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 005c3ccb  3beb                 cmp ebp, ebx
// 005c3ccd  0f8de0030000         jge 0x5c40b3
// 005c3cd3  56                   push esi
// 005c3cd4  8b742414             mov esi, dword ptr [esp + 0x14]
// 005c3cd8  57                   push edi
// 005c3cd9  eb0d                 jmp 0x5c3ce8
// 005c3cdb  eb03                 jmp 0x5c3ce0
// 005c3cdd  8d4900               lea ecx, [ecx]
// 005c3ce0  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005c3ce4  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005c3ce8  55                   push ebp
// 005c3ce9  6a01                 push 1
// 005c3ceb  56                   push esi
// 005c3cec  e87f56ffff           call 0x5b9370
// 005c3cf1  53                   push ebx
// 005c3cf2  6a01                 push 1
// 005c3cf4  56                   push esi
// 005c3cf5  e87656ffff           call 0x5b9370
// 005c3cfa  6a02                 push 2
// 005c3cfc  56                   push esi
// 005c3cfd  e83e4fffff           call 0x5b8c40
// 005c3d02  83c420               add esp, 0x20
// 005c3d05  85c0                 test eax, eax
// 005c3d07  743b                 je 0x5c3d44
// 005c3d09  6a02                 push 2
// 005c3d0b  56                   push esi
// 005c3d0c  e8ff4effff           call 0x5b8c10
// 005c3d11  6afe                 push -2
// 005c3d13  56                   push esi
// 005c3d14  e8f74effff           call 0x5b8c10
// 005c3d19  6afc                 push -4
// 005c3d1b  56                   push esi
// 005c3d1c  e8ef4effff           call 0x5b8c10
// 005c3d21  6a01                 push 1
// 005c3d23  6a02                 push 2
// 005c3d25  56                   push esi
// 005c3d26  e8355affff           call 0x5b9760
// 005c3d2b  6aff                 push -1
// 005c3d2d  56                   push esi
// 005c3d2e  e8ed50ffff           call 0x5b8e20
// 005c3d33  6afe                 push -2
// 005c3d35  56                   push esi
// 005c3d36  8bf8                 mov edi, eax
// 005c3d38  e8234dffff           call 0x5b8a60
// 005c3d3d  83c434               add esp, 0x34
// 005c3d40  8bc7                 mov eax, edi
// 005c3d42  eb0d                 jmp 0x5c3d51
// 005c3d44  6afe                 push -2
// 005c3d46  6aff                 push -1
// 005c3d48  56                   push esi
// 005c3d49  e81250ffff           call 0x5b8d60
// 005c3d4e  83c40c               add esp, 0xc
// 005c3d51  85c0                 test eax, eax
// 005c3d53  7417                 je 0x5c3d6c
// 005c3d55  55                   push ebp
// 005c3d56  6a01                 push 1
// 005c3d58  56                   push esi
// 005c3d59  e86258ffff           call 0x5b95c0
// 005c3d5e  53                   push ebx
// 005c3d5f  6a01                 push 1
// 005c3d61  56                   push esi
// 005c3d62  e85958ffff           call 0x5b95c0
// 005c3d67  83c418               add esp, 0x18
// 005c3d6a  eb0b                 jmp 0x5c3d77
// 005c3d6c  6afd                 push -3
// 005c3d6e  56                   push esi
// 005c3d6f  e8ec4cffff           call 0x5b8a60
// 005c3d74  83c408               add esp, 8
// 005c3d77  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005c3d7b  8beb                 mov ebp, ebx
// 005c3d7d  2be8                 sub ebp, eax
// 005c3d7f  83fd01               cmp ebp, 1
// 005c3d82  0f8429030000         je 0x5c40b1
// 005c3d88  03c3                 add eax, ebx
// 005c3d8a  99                   cdq 
// 005c3d8b  2bc2                 sub eax, edx
// 005c3d8d  8bf8                 mov edi, eax
// 005c3d8f  d1ff                 sar edi, 1
// 005c3d91  57                   push edi
// 005c3d92  6a01                 push 1
// 005c3d94  56                   push esi
// 005c3d95  e8d655ffff           call 0x5b9370
// 005c3d9a  8b442428             mov eax, dword ptr [esp + 0x28]
// 005c3d9e  50                   push eax
// 005c3d9f  6a01                 push 1
// 005c3da1  56                   push esi
// 005c3da2  e8c955ffff           call 0x5b9370
// 005c3da7  6a02                 push 2
// 005c3da9  56                   push esi
// 005c3daa  e8914effff           call 0x5b8c40
// 005c3daf  83c420               add esp, 0x20
// 005c3db2  85c0                 test eax, eax
// 005c3db4  743f                 je 0x5c3df5
// 005c3db6  6a02                 push 2
// 005c3db8  56                   push esi
// 005c3db9  e8524effff           call 0x5b8c10
// 005c3dbe  6afd                 push -3
// 005c3dc0  56                   push esi
// 005c3dc1  e84a4effff           call 0x5b8c10
// 005c3dc6  6afd                 push -3
// 005c3dc8  56                   push esi
// 005c3dc9  e8424effff           call 0x5b8c10
// 005c3dce  6a01                 push 1
// 005c3dd0  6a02                 push 2
// 005c3dd2  56                   push esi
// 005c3dd3  e88859ffff           call 0x5b9760
// 005c3dd8  6aff                 push -1
// 005c3dda  56                   push esi
// 005c3ddb  e84050ffff           call 0x5b8e20
// 005c3de0  6afe                 push -2
// 005c3de2  56                   push esi
// 005c3de3  8bd8                 mov ebx, eax
// 005c3de5  e8764cffff           call 0x5b8a60
// 005c3dea  8bc3                 mov eax, ebx
// 005c3dec  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 005c3df0  83c434               add esp, 0x34
// 005c3df3  eb0d                 jmp 0x5c3e02
// 005c3df5  6aff                 push -1
// 005c3df7  6afe                 push -2
// 005c3df9  56                   push esi
// 005c3dfa  e8614fffff           call 0x5b8d60
// 005c3dff  83c40c               add esp, 0xc
// 005c3e02  85c0                 test eax, eax
// 005c3e04  741e                 je 0x5c3e24
// 005c3e06  57                   push edi
// 005c3e07  6a01                 push 1
// 005c3e09  56                   push esi
// 005c3e0a  e8b157ffff           call 0x5b95c0
// 005c3e0f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005c3e13  51                   push ecx
// 005c3e14  6a01                 push 1
// 005c3e16  56                   push esi
// 005c3e17  e8a457ffff           call 0x5b95c0
// 005c3e1c  83c418               add esp, 0x18
// 005c3e1f  e992000000           jmp 0x5c3eb6
// 005c3e24  6afe                 push -2
// 005c3e26  56                   push esi
// 005c3e27  e8344cffff           call 0x5b8a60
// 005c3e2c  53                   push ebx
// 005c3e2d  6a01                 push 1
// 005c3e2f  56                   push esi
// 005c3e30  e83b55ffff           call 0x5b9370
// 005c3e35  6a02                 push 2
// 005c3e37  56                   push esi
// 005c3e38  e8034effff           call 0x5b8c40
// 005c3e3d  83c41c               add esp, 0x1c
// 005c3e40  85c0                 test eax, eax
// 005c3e42  743f                 je 0x5c3e83
// 005c3e44  6a02                 push 2
// 005c3e46  56                   push esi
// 005c3e47  e8c44dffff           call 0x5b8c10
// 005c3e4c  6afe                 push -2
// 005c3e4e  56                   push esi
// 005c3e4f  e8bc4dffff           call 0x5b8c10
// 005c3e54  6afc                 push -4
// 005c3e56  56                   push esi
// 005c3e57  e8b44dffff           call 0x5b8c10
// 005c3e5c  6a01                 push 1
// 005c3e5e  6a02                 push 2
// 005c3e60  56                   push esi
// 005c3e61  e8fa58ffff           call 0x5b9760
// 005c3e66  6aff                 push -1
// 005c3e68  56                   push esi
// 005c3e69  e8b24fffff           call 0x5b8e20
// 005c3e6e  6afe                 push -2
// 005c3e70  56                   push esi
// 005c3e71  8bd8                 mov ebx, eax
// 005c3e73  e8e84bffff           call 0x5b8a60
// 005c3e78  8bc3                 mov eax, ebx
// 005c3e7a  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 005c3e7e  83c434               add esp, 0x34
// 005c3e81  eb0d                 jmp 0x5c3e90
// 005c3e83  6afe                 push -2
// 005c3e85  6aff                 push -1
// 005c3e87  56                   push esi
// 005c3e88  e8d34effff           call 0x5b8d60
// 005c3e8d  83c40c               add esp, 0xc
// 005c3e90  85c0                 test eax, eax
// 005c3e92  7417                 je 0x5c3eab
// 005c3e94  57                   push edi
// 005c3e95  6a01                 push 1
// 005c3e97  56                   push esi
// 005c3e98  e82357ffff           call 0x5b95c0
// 005c3e9d  53                   push ebx
// 005c3e9e  6a01                 push 1
// 005c3ea0  56                   push esi
// 005c3ea1  e81a57ffff           call 0x5b95c0
// 005c3ea6  83c418               add esp, 0x18
// 005c3ea9  eb0b                 jmp 0x5c3eb6
// 005c3eab  6afd                 push -3
// 005c3ead  56                   push esi
// 005c3eae  e8ad4bffff           call 0x5b8a60
// 005c3eb3  83c408               add esp, 8
// 005c3eb6  83fd02               cmp ebp, 2
// 005c3eb9  0f84f2010000         je 0x5c40b1
// 005c3ebf  57                   push edi
// 005c3ec0  6a01                 push 1
// 005c3ec2  56                   push esi
// 005c3ec3  e8a854ffff           call 0x5b9370
// 005c3ec8  6aff                 push -1
// 005c3eca  56                   push esi
// 005c3ecb  e8404dffff           call 0x5b8c10
// 005c3ed0  8d6bff               lea ebp, [ebx - 1]
// 005c3ed3  55                   push ebp
// 005c3ed4  6a01                 push 1
// 005c3ed6  56                   push esi
// 005c3ed7  896c2430             mov dword ptr [esp + 0x30], ebp
// 005c3edb  e89054ffff           call 0x5b9370
// 005c3ee0  57                   push edi
// 005c3ee1  6a01                 push 1
// 005c3ee3  56                   push esi
// 005c3ee4  e8d756ffff           call 0x5b95c0
// 005c3ee9  55                   push ebp
// 005c3eea  6a01                 push 1
// 005c3eec  56                   push esi
// 005c3eed  e8ce56ffff           call 0x5b95c0
// 005c3ef2  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 005c3ef6  83c438               add esp, 0x38
// 005c3ef9  8da42400000000       lea esp, [esp]
// 005c3f00  83c301               add ebx, 1
// 005c3f03  53                   push ebx
// 005c3f04  6a01                 push 1
// 005c3f06  56                   push esi
// 005c3f07  e86454ffff           call 0x5b9370
// 005c3f0c  6a02                 push 2
// 005c3f0e  56                   push esi
// 005c3f0f  e82c4dffff           call 0x5b8c40
// 005c3f14  83c414               add esp, 0x14
// 005c3f17  85c0                 test eax, eax
// 005c3f19  743b                 je 0x5c3f56
// 005c3f1b  6a02                 push 2
// 005c3f1d  56                   push esi
// 005c3f1e  e8ed4cffff           call 0x5b8c10
// 005c3f23  6afe                 push -2
// 005c3f25  56                   push esi
// 005c3f26  e8e54cffff           call 0x5b8c10
// 005c3f2b  6afc                 push -4
// 005c3f2d  56                   push esi
// 005c3f2e  e8dd4cffff           call 0x5b8c10
// 005c3f33  6a01                 push 1
// 005c3f35  6a02                 push 2
// 005c3f37  56                   push esi
// 005c3f38  e82358ffff           call 0x5b9760
// 005c3f3d  6aff                 push -1
// 005c3f3f  56                   push esi
// 005c3f40  e8db4effff           call 0x5b8e20
// 005c3f45  6afe                 push -2
// 005c3f47  56                   push esi
// 005c3f48  8bf8                 mov edi, eax
// 005c3f4a  e8114bffff           call 0x5b8a60
// 005c3f4f  83c434               add esp, 0x34
// 005c3f52  8bc7                 mov eax, edi
// 005c3f54  eb0d                 jmp 0x5c3f63
// 005c3f56  6afe                 push -2
// 005c3f58  6aff                 push -1
// 005c3f5a  56                   push esi
// 005c3f5b  e8004effff           call 0x5b8d60
// 005c3f60  83c40c               add esp, 0xc
// 005c3f63  85c0                 test eax, eax
// 005c3f65  7429                 je 0x5c3f90
// 005c3f67  3b5c2420             cmp ebx, dword ptr [esp + 0x20]
// 005c3f6b  7e0e                 jle 0x5c3f7b
// 005c3f6d  68109c7b00           push 0x7b9c10
// 005c3f72  56                   push esi
// 005c3f73  e8d85bffff           call 0x5b9b50
// 005c3f78  83c408               add esp, 8
// 005c3f7b  6afe                 push -2
// 005c3f7d  56                   push esi
// 005c3f7e  e8dd4affff           call 0x5b8a60
// 005c3f83  83c408               add esp, 8
// 005c3f86  e975ffffff           jmp 0x5c3f00
// 005c3f8b  eb03                 jmp 0x5c3f90
// 005c3f8d  8d4900               lea ecx, [ecx]
// 005c3f90  83ed01               sub ebp, 1
// 005c3f93  55                   push ebp
// 005c3f94  6a01                 push 1
// 005c3f96  56                   push esi
// 005c3f97  e8d453ffff           call 0x5b9370
// 005c3f9c  6a02                 push 2
// 005c3f9e  56                   push esi
// 005c3f9f  e89c4cffff           call 0x5b8c40
// 005c3fa4  83c414               add esp, 0x14
// 005c3fa7  85c0                 test eax, eax
// 005c3fa9  743b                 je 0x5c3fe6
// 005c3fab  6a02                 push 2
// 005c3fad  56                   push esi
// 005c3fae  e85d4cffff           call 0x5b8c10
// 005c3fb3  6afc                 push -4
// 005c3fb5  56                   push esi
// 005c3fb6  e8554cffff           call 0x5b8c10
// 005c3fbb  6afd                 push -3
// 005c3fbd  56                   push esi
// 005c3fbe  e84d4cffff           call 0x5b8c10
// 005c3fc3  6a01                 push 1
// 005c3fc5  6a02                 push 2
// 005c3fc7  56                   push esi
// 005c3fc8  e89357ffff           call 0x5b9760
// 005c3fcd  6aff                 push -1
// 005c3fcf  56                   push esi
// 005c3fd0  e84b4effff           call 0x5b8e20
// 005c3fd5  6afe                 push -2
// 005c3fd7  56                   push esi
// 005c3fd8  8bf8                 mov edi, eax
// 005c3fda  e8814affff           call 0x5b8a60
// 005c3fdf  83c434               add esp, 0x34
// 005c3fe2  8bc7                 mov eax, edi
// 005c3fe4  eb0d                 jmp 0x5c3ff3
// 005c3fe6  6aff                 push -1
// 005c3fe8  6afd                 push -3
// 005c3fea  56                   push esi
// 005c3feb  e8704dffff           call 0x5b8d60
// 005c3ff0  83c40c               add esp, 0xc
// 005c3ff3  85c0                 test eax, eax
// 005c3ff5  7424                 je 0x5c401b
// 005c3ff7  3b6c241c             cmp ebp, dword ptr [esp + 0x1c]
// 005c3ffb  7d0e                 jge 0x5c400b
// 005c3ffd  68109c7b00           push 0x7b9c10
// 005c4002  56                   push esi
// 005c4003  e8485bffff           call 0x5b9b50
// 005c4008  83c408               add esp, 8
// 005c400b  6afe                 push -2
// 005c400d  56                   push esi
// 005c400e  e84d4affff           call 0x5b8a60
// 005c4013  83c408               add esp, 8
// 005c4016  e975ffffff           jmp 0x5c3f90
// 005c401b  3beb                 cmp ebp, ebx
// 005c401d  7c1a                 jl 0x5c4039
// 005c401f  53                   push ebx
// 005c4020  6a01                 push 1
// 005c4022  56                   push esi
// 005c4023  e89855ffff           call 0x5b95c0
// 005c4028  55                   push ebp
// 005c4029  6a01                 push 1
// 005c402b  56                   push esi
// 005c402c  e88f55ffff           call 0x5b95c0
// 005c4031  83c418               add esp, 0x18
// 005c4034  e9c7feffff           jmp 0x5c3f00
// 005c4039  6afc                 push -4
// 005c403b  56                   push esi
// 005c403c  e81f4affff           call 0x5b8a60
// 005c4041  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005c4045  57                   push edi
// 005c4046  6a01                 push 1
// 005c4048  56                   push esi
// 005c4049  e82253ffff           call 0x5b9370
// 005c404e  53                   push ebx
// 005c404f  6a01                 push 1
// 005c4051  56                   push esi
// 005c4052  e81953ffff           call 0x5b9370
// 005c4057  57                   push edi
// 005c4058  6a01                 push 1
// 005c405a  56                   push esi
// 005c405b  e86055ffff           call 0x5b95c0
// 005c4060  53                   push ebx
// 005c4061  6a01                 push 1
// 005c4063  56                   push esi
// 005c4064  e85755ffff           call 0x5b95c0
// 005c4069  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 005c406d  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 005c4071  8bd5                 mov edx, ebp
// 005c4073  8bc3                 mov eax, ebx
// 005c4075  2bd3                 sub edx, ebx
// 005c4077  2bc7                 sub eax, edi
// 005c4079  83c438               add esp, 0x38
// 005c407c  3bc2                 cmp eax, edx
// 005c407e  7d10                 jge 0x5c4090
// 005c4080  83eb01               sub ebx, 1
// 005c4083  8d4b02               lea ecx, [ebx + 2]
// 005c4086  8bc7                 mov eax, edi
// 005c4088  894c241c             mov dword ptr [esp + 0x1c], ecx
// 005c408c  8bf9                 mov edi, ecx
// 005c408e  eb0e                 jmp 0x5c409e
// 005c4090  8d4301               lea eax, [ebx + 1]
// 005c4093  8d50fe               lea edx, [eax - 2]
// 005c4096  8bdd                 mov ebx, ebp
// 005c4098  89542420             mov dword ptr [esp + 0x20], edx
// 005c409c  8bea                 mov ebp, edx
// 005c409e  53                   push ebx
// 005c409f  50                   push eax
// 005c40a0  56                   push esi
// 005c40a1  e81afcffff           call 0x5c3cc0
// 005c40a6  83c40c               add esp, 0xc
// 005c40a9  3bfd                 cmp edi, ebp
// 005c40ab  0f8c2ffcffff         jl 0x5c3ce0
// 005c40b1  5f                   pop edi
// 005c40b2  5e                   pop esi
// 005c40b3  5d                   pop ebp
// 005c40b4  5b                   pop ebx
// 005c40b5  59                   pop ecx
// 005c40b6  c3                   ret 
// library lua-5.1.1/ltablib.c (function _auxsort)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ltablib.c
