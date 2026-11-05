// from server: 100% by auto
// roc 2010-06 0088e100  unit: CXTColorHex  size: 2261 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088e100
//
// 0088e100  83ec40               sub esp, 0x40
// 0088e103  53                   push ebx
// 0088e104  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 0088e107  55                   push ebp
// 0088e108  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 0088e10b  56                   push esi
// 0088e10c  8b355ca19e00         mov esi, dword ptr [0x9ea15c]
// 0088e112  57                   push edi
// 0088e113  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 0088e117  83eb02               sub ebx, 2
// 0088e11a  4d                   dec ebp
// 0088e11b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e123  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e127  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e12a  6a00                 push 0
// 0088e12c  03c5                 add eax, ebp
// 0088e12e  50                   push eax
// 0088e12f  53                   push ebx
// 0088e130  51                   push ecx
// 0088e131  ffd6                 call esi
// 0088e133  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e137  40                   inc eax
// 0088e138  83f80b               cmp eax, 0xb
// 0088e13b  89442410             mov dword ptr [esp + 0x10], eax
// 0088e13f  7ce2                 jl 0x88e123
// 0088e141  8b5704               mov edx, dword ptr [edi + 4]
// 0088e144  6a00                 push 0
// 0088e146  8d450b               lea eax, [ebp + 0xb]
// 0088e149  8d4b01               lea ecx, [ebx + 1]
// 0088e14c  50                   push eax
// 0088e14d  51                   push ecx
// 0088e14e  52                   push edx
// 0088e14f  894c2434             mov dword ptr [esp + 0x34], ecx
// 0088e153  ffd6                 call esi
// 0088e155  6a00                 push 0
// 0088e157  8d450b               lea eax, [ebp + 0xb]
// 0088e15a  50                   push eax
// 0088e15b  8b4704               mov eax, dword ptr [edi + 4]
// 0088e15e  8d4b02               lea ecx, [ebx + 2]
// 0088e161  51                   push ecx
// 0088e162  50                   push eax
// 0088e163  ffd6                 call esi
// 0088e165  6a00                 push 0
// 0088e167  8d450c               lea eax, [ebp + 0xc]
// 0088e16a  50                   push eax
// 0088e16b  8d4b03               lea ecx, [ebx + 3]
// 0088e16e  51                   push ecx
// 0088e16f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e172  51                   push ecx
// 0088e173  ffd6                 call esi
// 0088e175  8b5704               mov edx, dword ptr [edi + 4]
// 0088e178  6a00                 push 0
// 0088e17a  8d450c               lea eax, [ebp + 0xc]
// 0088e17d  8d4b04               lea ecx, [ebx + 4]
// 0088e180  50                   push eax
// 0088e181  51                   push ecx
// 0088e182  52                   push edx
// 0088e183  894c2430             mov dword ptr [esp + 0x30], ecx
// 0088e187  ffd6                 call esi
// 0088e189  6a00                 push 0
// 0088e18b  8d450d               lea eax, [ebp + 0xd]
// 0088e18e  50                   push eax
// 0088e18f  8b4704               mov eax, dword ptr [edi + 4]
// 0088e192  8d4b05               lea ecx, [ebx + 5]
// 0088e195  51                   push ecx
// 0088e196  50                   push eax
// 0088e197  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0088e19b  ffd6                 call esi
// 0088e19d  6a00                 push 0
// 0088e19f  8d450d               lea eax, [ebp + 0xd]
// 0088e1a2  8d4b06               lea ecx, [ebx + 6]
// 0088e1a5  50                   push eax
// 0088e1a6  51                   push ecx
// 0088e1a7  894c2424             mov dword ptr [esp + 0x24], ecx
// 0088e1ab  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e1ae  51                   push ecx
// 0088e1af  ffd6                 call esi
// 0088e1b1  8d5307               lea edx, [ebx + 7]
// 0088e1b4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e1bc  89542414             mov dword ptr [esp + 0x14], edx
// 0088e1c0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088e1c4  8b5704               mov edx, dword ptr [edi + 4]
// 0088e1c7  6a00                 push 0
// 0088e1c9  8d450e               lea eax, [ebp + 0xe]
// 0088e1cc  50                   push eax
// 0088e1cd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088e1d1  03c1                 add eax, ecx
// 0088e1d3  50                   push eax
// 0088e1d4  52                   push edx
// 0088e1d5  ffd6                 call esi
// 0088e1d7  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e1db  40                   inc eax
// 0088e1dc  83f805               cmp eax, 5
// 0088e1df  89442410             mov dword ptr [esp + 0x10], eax
// 0088e1e3  7cdb                 jl 0x88e1c0
// 0088e1e5  6a00                 push 0
// 0088e1e7  8d4d0d               lea ecx, [ebp + 0xd]
// 0088e1ea  51                   push ecx
// 0088e1eb  8d430c               lea eax, [ebx + 0xc]
// 0088e1ee  50                   push eax
// 0088e1ef  8b4704               mov eax, dword ptr [edi + 4]
// 0088e1f2  50                   push eax
// 0088e1f3  ffd6                 call esi
// 0088e1f5  6a00                 push 0
// 0088e1f7  8d4d0d               lea ecx, [ebp + 0xd]
// 0088e1fa  51                   push ecx
// 0088e1fb  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e1fe  8d430d               lea eax, [ebx + 0xd]
// 0088e201  50                   push eax
// 0088e202  51                   push ecx
// 0088e203  ffd6                 call esi
// 0088e205  8b5704               mov edx, dword ptr [edi + 4]
// 0088e208  6a00                 push 0
// 0088e20a  8d4d0c               lea ecx, [ebp + 0xc]
// 0088e20d  51                   push ecx
// 0088e20e  8d430e               lea eax, [ebx + 0xe]
// 0088e211  50                   push eax
// 0088e212  52                   push edx
// 0088e213  ffd6                 call esi
// 0088e215  6a00                 push 0
// 0088e217  8d4d0c               lea ecx, [ebp + 0xc]
// 0088e21a  51                   push ecx
// 0088e21b  8d430f               lea eax, [ebx + 0xf]
// 0088e21e  50                   push eax
// 0088e21f  8b4704               mov eax, dword ptr [edi + 4]
// 0088e222  50                   push eax
// 0088e223  ffd6                 call esi
// 0088e225  6a00                 push 0
// 0088e227  8d4d0b               lea ecx, [ebp + 0xb]
// 0088e22a  51                   push ecx
// 0088e22b  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e22e  8d4310               lea eax, [ebx + 0x10]
// 0088e231  50                   push eax
// 0088e232  51                   push ecx
// 0088e233  ffd6                 call esi
// 0088e235  8b5704               mov edx, dword ptr [edi + 4]
// 0088e238  6a00                 push 0
// 0088e23a  8d4d0b               lea ecx, [ebp + 0xb]
// 0088e23d  51                   push ecx
// 0088e23e  8d4311               lea eax, [ebx + 0x11]
// 0088e241  50                   push eax
// 0088e242  52                   push edx
// 0088e243  ffd6                 call esi
// 0088e245  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e24d  8d4900               lea ecx, [ecx]
// 0088e250  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e254  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e257  6a00                 push 0
// 0088e259  03c5                 add eax, ebp
// 0088e25b  50                   push eax
// 0088e25c  8d4312               lea eax, [ebx + 0x12]
// 0088e25f  50                   push eax
// 0088e260  51                   push ecx
// 0088e261  ffd6                 call esi
// 0088e263  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e267  40                   inc eax
// 0088e268  83f80b               cmp eax, 0xb
// 0088e26b  89442410             mov dword ptr [esp + 0x10], eax
// 0088e26f  7cdf                 jl 0x88e250
// 0088e271  8b5704               mov edx, dword ptr [edi + 4]
// 0088e274  6a00                 push 0
// 0088e276  8d45ff               lea eax, [ebp - 1]
// 0088e279  50                   push eax
// 0088e27a  8944245c             mov dword ptr [esp + 0x5c], eax
// 0088e27e  8d4310               lea eax, [ebx + 0x10]
// 0088e281  50                   push eax
// 0088e282  52                   push edx
// 0088e283  ffd6                 call esi
// 0088e285  8b442454             mov eax, dword ptr [esp + 0x54]
// 0088e289  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e28c  6a00                 push 0
// 0088e28e  50                   push eax
// 0088e28f  8d4311               lea eax, [ebx + 0x11]
// 0088e292  50                   push eax
// 0088e293  51                   push ecx
// 0088e294  ffd6                 call esi
// 0088e296  8b5704               mov edx, dword ptr [edi + 4]
// 0088e299  6a00                 push 0
// 0088e29b  8d45fe               lea eax, [ebp - 2]
// 0088e29e  50                   push eax
// 0088e29f  8d430e               lea eax, [ebx + 0xe]
// 0088e2a2  50                   push eax
// 0088e2a3  52                   push edx
// 0088e2a4  ffd6                 call esi
// 0088e2a6  6a00                 push 0
// 0088e2a8  8d45fe               lea eax, [ebp - 2]
// 0088e2ab  50                   push eax
// 0088e2ac  8d430f               lea eax, [ebx + 0xf]
// 0088e2af  50                   push eax
// 0088e2b0  8b4704               mov eax, dword ptr [edi + 4]
// 0088e2b3  50                   push eax
// 0088e2b4  ffd6                 call esi
// 0088e2b6  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e2b9  6a00                 push 0
// 0088e2bb  8d45fd               lea eax, [ebp - 3]
// 0088e2be  50                   push eax
// 0088e2bf  8d430c               lea eax, [ebx + 0xc]
// 0088e2c2  50                   push eax
// 0088e2c3  51                   push ecx
// 0088e2c4  ffd6                 call esi
// 0088e2c6  8b5704               mov edx, dword ptr [edi + 4]
// 0088e2c9  6a00                 push 0
// 0088e2cb  8d45fd               lea eax, [ebp - 3]
// 0088e2ce  50                   push eax
// 0088e2cf  8d430d               lea eax, [ebx + 0xd]
// 0088e2d2  50                   push eax
// 0088e2d3  52                   push edx
// 0088e2d4  ffd6                 call esi
// 0088e2d6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e2de  8bff                 mov edi, edi
// 0088e2e0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088e2e4  8b5704               mov edx, dword ptr [edi + 4]
// 0088e2e7  6a00                 push 0
// 0088e2e9  8d45fc               lea eax, [ebp - 4]
// 0088e2ec  50                   push eax
// 0088e2ed  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088e2f1  03c1                 add eax, ecx
// 0088e2f3  50                   push eax
// 0088e2f4  52                   push edx
// 0088e2f5  ffd6                 call esi
// 0088e2f7  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e2fb  40                   inc eax
// 0088e2fc  83f805               cmp eax, 5
// 0088e2ff  89442410             mov dword ptr [esp + 0x10], eax
// 0088e303  7cdb                 jl 0x88e2e0
// 0088e305  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e308  6a00                 push 0
// 0088e30a  8d45fd               lea eax, [ebp - 3]
// 0088e30d  50                   push eax
// 0088e30e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0088e312  50                   push eax
// 0088e313  51                   push ecx
// 0088e314  ffd6                 call esi
// 0088e316  8b542418             mov edx, dword ptr [esp + 0x18]
// 0088e31a  6a00                 push 0
// 0088e31c  8d45fd               lea eax, [ebp - 3]
// 0088e31f  50                   push eax
// 0088e320  8b4704               mov eax, dword ptr [edi + 4]
// 0088e323  52                   push edx
// 0088e324  50                   push eax
// 0088e325  ffd6                 call esi
// 0088e327  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e32a  6a00                 push 0
// 0088e32c  8d45fe               lea eax, [ebp - 2]
// 0088e32f  50                   push eax
// 0088e330  8d4303               lea eax, [ebx + 3]
// 0088e333  50                   push eax
// 0088e334  51                   push ecx
// 0088e335  ffd6                 call esi
// 0088e337  8b542420             mov edx, dword ptr [esp + 0x20]
// 0088e33b  6a00                 push 0
// 0088e33d  8d45fe               lea eax, [ebp - 2]
// 0088e340  50                   push eax
// 0088e341  8b4704               mov eax, dword ptr [edi + 4]
// 0088e344  52                   push edx
// 0088e345  50                   push eax
// 0088e346  ffd6                 call esi
// 0088e348  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088e34c  8b542424             mov edx, dword ptr [esp + 0x24]
// 0088e350  8b4704               mov eax, dword ptr [edi + 4]
// 0088e353  6a00                 push 0
// 0088e355  51                   push ecx
// 0088e356  52                   push edx
// 0088e357  50                   push eax
// 0088e358  ffd6                 call esi
// 0088e35a  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088e35e  8b5704               mov edx, dword ptr [edi + 4]
// 0088e361  6a00                 push 0
// 0088e363  51                   push ecx
// 0088e364  8d4302               lea eax, [ebx + 2]
// 0088e367  50                   push eax
// 0088e368  52                   push edx
// 0088e369  ffd6                 call esi
// 0088e36b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e373  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e377  8b5704               mov edx, dword ptr [edi + 4]
// 0088e37a  6a00                 push 0
// 0088e37c  8d4c2802             lea ecx, [eax + ebp + 2]
// 0088e380  51                   push ecx
// 0088e381  8d4303               lea eax, [ebx + 3]
// 0088e384  50                   push eax
// 0088e385  52                   push edx
// 0088e386  ffd6                 call esi
// 0088e388  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e38c  40                   inc eax
// 0088e38d  83f807               cmp eax, 7
// 0088e390  89442410             mov dword ptr [esp + 0x10], eax
// 0088e394  7cdd                 jl 0x88e373
// 0088e396  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e399  6a00                 push 0
// 0088e39b  8d4509               lea eax, [ebp + 9]
// 0088e39e  50                   push eax
// 0088e39f  8b442428             mov eax, dword ptr [esp + 0x28]
// 0088e3a3  50                   push eax
// 0088e3a4  51                   push ecx
// 0088e3a5  ffd6                 call esi
// 0088e3a7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0088e3ab  6a00                 push 0
// 0088e3ad  8d4509               lea eax, [ebp + 9]
// 0088e3b0  50                   push eax
// 0088e3b1  8b4704               mov eax, dword ptr [edi + 4]
// 0088e3b4  52                   push edx
// 0088e3b5  50                   push eax
// 0088e3b6  ffd6                 call esi
// 0088e3b8  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0088e3bc  8b5704               mov edx, dword ptr [edi + 4]
// 0088e3bf  6a00                 push 0
// 0088e3c1  8d450a               lea eax, [ebp + 0xa]
// 0088e3c4  50                   push eax
// 0088e3c5  51                   push ecx
// 0088e3c6  52                   push edx
// 0088e3c7  ffd6                 call esi
// 0088e3c9  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e3cc  6a00                 push 0
// 0088e3ce  8d450a               lea eax, [ebp + 0xa]
// 0088e3d1  50                   push eax
// 0088e3d2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088e3d6  50                   push eax
// 0088e3d7  51                   push ecx
// 0088e3d8  ffd6                 call esi
// 0088e3da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e3e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088e3e6  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e3e9  6a00                 push 0
// 0088e3eb  8d450b               lea eax, [ebp + 0xb]
// 0088e3ee  50                   push eax
// 0088e3ef  8d441308             lea eax, [ebx + edx + 8]
// 0088e3f3  50                   push eax
// 0088e3f4  51                   push ecx
// 0088e3f5  ffd6                 call esi
// 0088e3f7  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e3fb  40                   inc eax
// 0088e3fc  83f803               cmp eax, 3
// 0088e3ff  89442410             mov dword ptr [esp + 0x10], eax
// 0088e403  7cdd                 jl 0x88e3e2
// 0088e405  8b5704               mov edx, dword ptr [edi + 4]
// 0088e408  6a00                 push 0
// 0088e40a  8d4d0a               lea ecx, [ebp + 0xa]
// 0088e40d  51                   push ecx
// 0088e40e  8d430b               lea eax, [ebx + 0xb]
// 0088e411  50                   push eax
// 0088e412  52                   push edx
// 0088e413  ffd6                 call esi
// 0088e415  6a00                 push 0
// 0088e417  8d450a               lea eax, [ebp + 0xa]
// 0088e41a  50                   push eax
// 0088e41b  8d430c               lea eax, [ebx + 0xc]
// 0088e41e  50                   push eax
// 0088e41f  8b4704               mov eax, dword ptr [edi + 4]
// 0088e422  50                   push eax
// 0088e423  ffd6                 call esi
// 0088e425  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e428  6a00                 push 0
// 0088e42a  8d4509               lea eax, [ebp + 9]
// 0088e42d  50                   push eax
// 0088e42e  8d430d               lea eax, [ebx + 0xd]
// 0088e431  50                   push eax
// 0088e432  51                   push ecx
// 0088e433  ffd6                 call esi
// 0088e435  8b5704               mov edx, dword ptr [edi + 4]
// 0088e438  6a00                 push 0
// 0088e43a  8d4509               lea eax, [ebp + 9]
// 0088e43d  50                   push eax
// 0088e43e  8d430e               lea eax, [ebx + 0xe]
// 0088e441  50                   push eax
// 0088e442  52                   push edx
// 0088e443  ffd6                 call esi
// 0088e445  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e44d  8d4900               lea ecx, [ecx]
// 0088e450  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e454  8b5704               mov edx, dword ptr [edi + 4]
// 0088e457  6a00                 push 0
// 0088e459  8d4c2802             lea ecx, [eax + ebp + 2]
// 0088e45d  51                   push ecx
// 0088e45e  8d430f               lea eax, [ebx + 0xf]
// 0088e461  50                   push eax
// 0088e462  52                   push edx
// 0088e463  ffd6                 call esi
// 0088e465  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e469  40                   inc eax
// 0088e46a  83f807               cmp eax, 7
// 0088e46d  89442410             mov dword ptr [esp + 0x10], eax
// 0088e471  7cdd                 jl 0x88e450
// 0088e473  6a00                 push 0
// 0088e475  8d4501               lea eax, [ebp + 1]
// 0088e478  50                   push eax
// 0088e479  8d430d               lea eax, [ebx + 0xd]
// 0088e47c  50                   push eax
// 0088e47d  8b4704               mov eax, dword ptr [edi + 4]
// 0088e480  50                   push eax
// 0088e481  ffd6                 call esi
// 0088e483  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e486  6a00                 push 0
// 0088e488  8d4501               lea eax, [ebp + 1]
// 0088e48b  50                   push eax
// 0088e48c  8d430e               lea eax, [ebx + 0xe]
// 0088e48f  50                   push eax
// 0088e490  51                   push ecx
// 0088e491  ffd6                 call esi
// 0088e493  8b5704               mov edx, dword ptr [edi + 4]
// 0088e496  6a00                 push 0
// 0088e498  55                   push ebp
// 0088e499  8d430b               lea eax, [ebx + 0xb]
// 0088e49c  50                   push eax
// 0088e49d  52                   push edx
// 0088e49e  ffd6                 call esi
// 0088e4a0  6a00                 push 0
// 0088e4a2  55                   push ebp
// 0088e4a3  8d430c               lea eax, [ebx + 0xc]
// 0088e4a6  50                   push eax
// 0088e4a7  8b4704               mov eax, dword ptr [edi + 4]
// 0088e4aa  50                   push eax
// 0088e4ab  ffd6                 call esi
// 0088e4ad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e4b5  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088e4b9  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088e4bd  6a00                 push 0
// 0088e4bf  51                   push ecx
// 0088e4c0  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e4c3  8d441308             lea eax, [ebx + edx + 8]
// 0088e4c7  50                   push eax
// 0088e4c8  51                   push ecx
// 0088e4c9  ffd6                 call esi
// 0088e4cb  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e4cf  40                   inc eax
// 0088e4d0  83f803               cmp eax, 3
// 0088e4d3  89442410             mov dword ptr [esp + 0x10], eax
// 0088e4d7  7cdc                 jl 0x88e4b5
// 0088e4d9  8b542418             mov edx, dword ptr [esp + 0x18]
// 0088e4dd  8b4704               mov eax, dword ptr [edi + 4]
// 0088e4e0  6a00                 push 0
// 0088e4e2  55                   push ebp
// 0088e4e3  52                   push edx
// 0088e4e4  50                   push eax
// 0088e4e5  ffd6                 call esi
// 0088e4e7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088e4eb  8b5704               mov edx, dword ptr [edi + 4]
// 0088e4ee  6a00                 push 0
// 0088e4f0  55                   push ebp
// 0088e4f1  51                   push ecx
// 0088e4f2  52                   push edx
// 0088e4f3  ffd6                 call esi
// 0088e4f5  8b442420             mov eax, dword ptr [esp + 0x20]
// 0088e4f9  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e4fc  6a00                 push 0
// 0088e4fe  8d5d01               lea ebx, [ebp + 1]
// 0088e501  53                   push ebx
// 0088e502  50                   push eax
// 0088e503  51                   push ecx
// 0088e504  ffd6                 call esi
// 0088e506  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0088e50a  8b4704               mov eax, dword ptr [edi + 4]
// 0088e50d  6a00                 push 0
// 0088e50f  53                   push ebx
// 0088e510  52                   push edx
// 0088e511  50                   push eax
// 0088e512  ffd6                 call esi
// 0088e514  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0088e518  896c2420             mov dword ptr [esp + 0x20], ebp
// 0088e51c  c74424240b000000     mov dword ptr [esp + 0x24], 0xb
// 0088e524  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088e528  8b5704               mov edx, dword ptr [edi + 4]
// 0088e52b  68ffffff00           push 0xffffff
// 0088e530  51                   push ecx
// 0088e531  53                   push ebx
// 0088e532  52                   push edx
// 0088e533  ffd6                 call esi
// 0088e535  8b442420             mov eax, dword ptr [esp + 0x20]
// 0088e539  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e53c  68ffffff00           push 0xffffff
// 0088e541  50                   push eax
// 0088e542  8d4301               lea eax, [ebx + 1]
// 0088e545  50                   push eax
// 0088e546  51                   push ecx
// 0088e547  ffd6                 call esi
// 0088e549  b801000000           mov eax, 1
// 0088e54e  01442420             add dword ptr [esp + 0x20], eax
// 0088e552  29442424             sub dword ptr [esp + 0x24], eax
// 0088e556  75cc                 jne 0x88e524
// 0088e558  8d5302               lea edx, [ebx + 2]
// 0088e55b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e563  89542444             mov dword ptr [esp + 0x44], edx
// 0088e567  eb07                 jmp 0x88e570
// 0088e569  8da42400000000       lea esp, [esp]
// 0088e570  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e574  8b542444             mov edx, dword ptr [esp + 0x44]
// 0088e578  68ffffff00           push 0xffffff
// 0088e57d  8d4c2809             lea ecx, [eax + ebp + 9]
// 0088e581  8b4704               mov eax, dword ptr [edi + 4]
// 0088e584  51                   push ecx
// 0088e585  52                   push edx
// 0088e586  50                   push eax
// 0088e587  ffd6                 call esi
// 0088e589  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e58d  40                   inc eax
// 0088e58e  83f803               cmp eax, 3
// 0088e591  89442410             mov dword ptr [esp + 0x10], eax
// 0088e595  7cd9                 jl 0x88e570
// 0088e597  68ffffff00           push 0xffffff
// 0088e59c  8d4d0a               lea ecx, [ebp + 0xa]
// 0088e59f  51                   push ecx
// 0088e5a0  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e5a3  8d4303               lea eax, [ebx + 3]
// 0088e5a6  50                   push eax
// 0088e5a7  51                   push ecx
// 0088e5a8  89442450             mov dword ptr [esp + 0x50], eax
// 0088e5ac  ffd6                 call esi
// 0088e5ae  8b542440             mov edx, dword ptr [esp + 0x40]
// 0088e5b2  68ffffff00           push 0xffffff
// 0088e5b7  8d450b               lea eax, [ebp + 0xb]
// 0088e5ba  50                   push eax
// 0088e5bb  8b4704               mov eax, dword ptr [edi + 4]
// 0088e5be  52                   push edx
// 0088e5bf  50                   push eax
// 0088e5c0  ffd6                 call esi
// 0088e5c2  8d4b04               lea ecx, [ebx + 4]
// 0088e5c5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e5cd  894c2420             mov dword ptr [esp + 0x20], ecx
// 0088e5d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088e5d5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088e5d9  68ffffff00           push 0xffffff
// 0088e5de  8d442a0a             lea eax, [edx + ebp + 0xa]
// 0088e5e2  8b5704               mov edx, dword ptr [edi + 4]
// 0088e5e5  50                   push eax
// 0088e5e6  51                   push ecx
// 0088e5e7  52                   push edx
// 0088e5e8  ffd6                 call esi
// 0088e5ea  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e5ee  40                   inc eax
// 0088e5ef  83f803               cmp eax, 3
// 0088e5f2  89442410             mov dword ptr [esp + 0x10], eax
// 0088e5f6  7cd9                 jl 0x88e5d1
// 0088e5f8  68ffffff00           push 0xffffff
// 0088e5fd  8d4d0b               lea ecx, [ebp + 0xb]
// 0088e600  8d4305               lea eax, [ebx + 5]
// 0088e603  51                   push ecx
// 0088e604  50                   push eax
// 0088e605  89442428             mov dword ptr [esp + 0x28], eax
// 0088e609  8b4704               mov eax, dword ptr [edi + 4]
// 0088e60c  50                   push eax
// 0088e60d  ffd6                 call esi
// 0088e60f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0088e613  8b5704               mov edx, dword ptr [edi + 4]
// 0088e616  68ffffff00           push 0xffffff
// 0088e61b  8d450c               lea eax, [ebp + 0xc]
// 0088e61e  50                   push eax
// 0088e61f  51                   push ecx
// 0088e620  52                   push edx
// 0088e621  ffd6                 call esi
// 0088e623  8d4306               lea eax, [ebx + 6]
// 0088e626  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e62e  89442418             mov dword ptr [esp + 0x18], eax
// 0088e632  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088e636  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088e63a  68ffffff00           push 0xffffff
// 0088e63f  8d54290b             lea edx, [ecx + ebp + 0xb]
// 0088e643  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e646  52                   push edx
// 0088e647  50                   push eax
// 0088e648  51                   push ecx
// 0088e649  ffd6                 call esi
// 0088e64b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e64f  40                   inc eax
// 0088e650  83f803               cmp eax, 3
// 0088e653  89442410             mov dword ptr [esp + 0x10], eax
// 0088e657  7cd9                 jl 0x88e632
// 0088e659  8b5704               mov edx, dword ptr [edi + 4]
// 0088e65c  68ffffff00           push 0xffffff
// 0088e661  8d4d0c               lea ecx, [ebp + 0xc]
// 0088e664  8d4307               lea eax, [ebx + 7]
// 0088e667  51                   push ecx
// 0088e668  50                   push eax
// 0088e669  52                   push edx
// 0088e66a  89442424             mov dword ptr [esp + 0x24], eax
// 0088e66e  ffd6                 call esi
// 0088e670  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e673  68ffffff00           push 0xffffff
// 0088e678  8d450d               lea eax, [ebp + 0xd]
// 0088e67b  50                   push eax
// 0088e67c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088e680  50                   push eax
// 0088e681  51                   push ecx
// 0088e682  ffd6                 call esi
// 0088e684  8b5704               mov edx, dword ptr [edi + 4]
// 0088e687  68ffffff00           push 0xffffff
// 0088e68c  8d4d0c               lea ecx, [ebp + 0xc]
// 0088e68f  8d4308               lea eax, [ebx + 8]
// 0088e692  51                   push ecx
// 0088e693  50                   push eax
// 0088e694  52                   push edx
// 0088e695  89442434             mov dword ptr [esp + 0x34], eax
// 0088e699  ffd6                 call esi
// 0088e69b  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e69e  68ffffff00           push 0xffffff
// 0088e6a3  8d450d               lea eax, [ebp + 0xd]
// 0088e6a6  50                   push eax
// 0088e6a7  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0088e6ab  50                   push eax
// 0088e6ac  51                   push ecx
// 0088e6ad  ffd6                 call esi
// 0088e6af  8b5704               mov edx, dword ptr [edi + 4]
// 0088e6b2  68ffffff00           push 0xffffff
// 0088e6b7  8d4d0c               lea ecx, [ebp + 0xc]
// 0088e6ba  8d4309               lea eax, [ebx + 9]
// 0088e6bd  51                   push ecx
// 0088e6be  50                   push eax
// 0088e6bf  52                   push edx
// 0088e6c0  8944244c             mov dword ptr [esp + 0x4c], eax
// 0088e6c4  ffd6                 call esi
// 0088e6c6  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e6c9  68ffffff00           push 0xffffff
// 0088e6ce  8d450d               lea eax, [ebp + 0xd]
// 0088e6d1  50                   push eax
// 0088e6d2  8b442444             mov eax, dword ptr [esp + 0x44]
// 0088e6d6  50                   push eax
// 0088e6d7  51                   push ecx
// 0088e6d8  ffd6                 call esi
// 0088e6da  8d530a               lea edx, [ebx + 0xa]
// 0088e6dd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e6e5  89542438             mov dword ptr [esp + 0x38], edx
// 0088e6e9  8da42400000000       lea esp, [esp]
// 0088e6f0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e6f4  8b542438             mov edx, dword ptr [esp + 0x38]
// 0088e6f8  68ffffff00           push 0xffffff
// 0088e6fd  8d4c280b             lea ecx, [eax + ebp + 0xb]
// 0088e701  8b4704               mov eax, dword ptr [edi + 4]
// 0088e704  51                   push ecx
// 0088e705  52                   push edx
// 0088e706  50                   push eax
// 0088e707  ffd6                 call esi
// 0088e709  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e70d  40                   inc eax
// 0088e70e  83f803               cmp eax, 3
// 0088e711  89442410             mov dword ptr [esp + 0x10], eax
// 0088e715  7cd9                 jl 0x88e6f0
// 0088e717  68ffffff00           push 0xffffff
// 0088e71c  8d4d0b               lea ecx, [ebp + 0xb]
// 0088e71f  51                   push ecx
// 0088e720  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e723  8d430b               lea eax, [ebx + 0xb]
// 0088e726  50                   push eax
// 0088e727  51                   push ecx
// 0088e728  89442444             mov dword ptr [esp + 0x44], eax
// 0088e72c  ffd6                 call esi
// 0088e72e  8b542434             mov edx, dword ptr [esp + 0x34]
// 0088e732  68ffffff00           push 0xffffff
// 0088e737  8d450c               lea eax, [ebp + 0xc]
// 0088e73a  50                   push eax
// 0088e73b  8b4704               mov eax, dword ptr [edi + 4]
// 0088e73e  52                   push edx
// 0088e73f  50                   push eax
// 0088e740  ffd6                 call esi
// 0088e742  8d4b0c               lea ecx, [ebx + 0xc]
// 0088e745  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e74d  894c2430             mov dword ptr [esp + 0x30], ecx
// 0088e751  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088e755  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0088e759  68ffffff00           push 0xffffff
// 0088e75e  8d442a0a             lea eax, [edx + ebp + 0xa]
// 0088e762  8b5704               mov edx, dword ptr [edi + 4]
// 0088e765  50                   push eax
// 0088e766  51                   push ecx
// 0088e767  52                   push edx
// 0088e768  ffd6                 call esi
// 0088e76a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e76e  40                   inc eax
// 0088e76f  83f803               cmp eax, 3
// 0088e772  89442410             mov dword ptr [esp + 0x10], eax
// 0088e776  7cd9                 jl 0x88e751
// 0088e778  68ffffff00           push 0xffffff
// 0088e77d  8d4d0a               lea ecx, [ebp + 0xa]
// 0088e780  8d430d               lea eax, [ebx + 0xd]
// 0088e783  51                   push ecx
// 0088e784  50                   push eax
// 0088e785  89442438             mov dword ptr [esp + 0x38], eax
// 0088e789  8b4704               mov eax, dword ptr [edi + 4]
// 0088e78c  50                   push eax
// 0088e78d  ffd6                 call esi
// 0088e78f  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0088e793  8b5704               mov edx, dword ptr [edi + 4]
// 0088e796  68ffffff00           push 0xffffff
// 0088e79b  8d450b               lea eax, [ebp + 0xb]
// 0088e79e  50                   push eax
// 0088e79f  51                   push ecx
// 0088e7a0  52                   push edx
// 0088e7a1  ffd6                 call esi
// 0088e7a3  8d430e               lea eax, [ebx + 0xe]
// 0088e7a6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088e7ae  89442428             mov dword ptr [esp + 0x28], eax
// 0088e7b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088e7b6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0088e7ba  68ffffff00           push 0xffffff
// 0088e7bf  8d542909             lea edx, [ecx + ebp + 9]
// 0088e7c3  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e7c6  52                   push edx
// 0088e7c7  50                   push eax
// 0088e7c8  51                   push ecx
// 0088e7c9  ffd6                 call esi
// 0088e7cb  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088e7cf  40                   inc eax
// 0088e7d0  83f803               cmp eax, 3
// 0088e7d3  89442410             mov dword ptr [esp + 0x10], eax
// 0088e7d7  7cd9                 jl 0x88e7b2
// 0088e7d9  8d530f               lea edx, [ebx + 0xf]
// 0088e7dc  83c310               add ebx, 0x10
// 0088e7df  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0088e7e3  89542448             mov dword ptr [esp + 0x48], edx
// 0088e7e7  8bdd                 mov ebx, ebp
// 0088e7e9  c74424100b000000     mov dword ptr [esp + 0x10], 0xb
// 0088e7f1  8b442448             mov eax, dword ptr [esp + 0x48]
// 0088e7f5  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e7f8  68ffffff00           push 0xffffff
// 0088e7fd  53                   push ebx
// 0088e7fe  50                   push eax
// 0088e7ff  51                   push ecx
// 0088e800  ffd6                 call esi
// 0088e802  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0088e806  8b4704               mov eax, dword ptr [edi + 4]
// 0088e809  68ffffff00           push 0xffffff
// 0088e80e  53                   push ebx
// 0088e80f  52                   push edx
// 0088e810  50                   push eax
// 0088e811  ffd6                 call esi
// 0088e813  43                   inc ebx
// 0088e814  836c241001           sub dword ptr [esp + 0x10], 1
// 0088e819  75d6                 jne 0x88e7f1
// 0088e81b  33db                 xor ebx, ebx
// 0088e81d  8d4900               lea ecx, [ecx]
// 0088e820  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088e824  8b542428             mov edx, dword ptr [esp + 0x28]
// 0088e828  8b4704               mov eax, dword ptr [edi + 4]
// 0088e82b  68ffffff00           push 0xffffff
// 0088e830  03cb                 add ecx, ebx
// 0088e832  51                   push ecx
// 0088e833  52                   push edx
// 0088e834  50                   push eax
// 0088e835  ffd6                 call esi
// 0088e837  43                   inc ebx
// 0088e838  83fb03               cmp ebx, 3
// 0088e83b  7ce3                 jl 0x88e820
// 0088e83d  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0088e841  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e844  68ffffff00           push 0xffffff
// 0088e849  55                   push ebp
// 0088e84a  53                   push ebx
// 0088e84b  51                   push ecx
// 0088e84c  ffd6                 call esi
// 0088e84e  8b542454             mov edx, dword ptr [esp + 0x54]
// 0088e852  8b4704               mov eax, dword ptr [edi + 4]
// 0088e855  68ffffff00           push 0xffffff
// 0088e85a  52                   push edx
// 0088e85b  53                   push ebx
// 0088e85c  50                   push eax
// 0088e85d  ffd6                 call esi
// 0088e85f  33db                 xor ebx, ebx
// 0088e861  8b542430             mov edx, dword ptr [esp + 0x30]
// 0088e865  8b4704               mov eax, dword ptr [edi + 4]
// 0088e868  68ffffff00           push 0xffffff
// 0088e86d  8d4c2bfe             lea ecx, [ebx + ebp - 2]
// 0088e871  51                   push ecx
// 0088e872  52                   push edx
// 0088e873  50                   push eax
// 0088e874  ffd6                 call esi
// 0088e876  43                   inc ebx
// 0088e877  83fb03               cmp ebx, 3
// 0088e87a  7ce5                 jl 0x88e861
// 0088e87c  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088e880  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0088e884  8b5704               mov edx, dword ptr [edi + 4]
// 0088e887  68ffffff00           push 0xffffff
// 0088e88c  51                   push ecx
// 0088e88d  53                   push ebx
// 0088e88e  52                   push edx
// 0088e88f  ffd6                 call esi
// 0088e891  68ffffff00           push 0xffffff
// 0088e896  8d45fe               lea eax, [ebp - 2]
// 0088e899  50                   push eax
// 0088e89a  8b4704               mov eax, dword ptr [edi + 4]
// 0088e89d  53                   push ebx
// 0088e89e  50                   push eax
// 0088e89f  ffd6                 call esi
// 0088e8a1  33db                 xor ebx, ebx
// 0088e8a3  8b542438             mov edx, dword ptr [esp + 0x38]
// 0088e8a7  8b4704               mov eax, dword ptr [edi + 4]
// 0088e8aa  68ffffff00           push 0xffffff
// 0088e8af  8d4c2bfd             lea ecx, [ebx + ebp - 3]
// 0088e8b3  51                   push ecx
// 0088e8b4  52                   push edx
// 0088e8b5  50                   push eax
// 0088e8b6  ffd6                 call esi
// 0088e8b8  43                   inc ebx
// 0088e8b9  83fb03               cmp ebx, 3
// 0088e8bc  7ce5                 jl 0x88e8a3
// 0088e8be  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088e8c2  8b5704               mov edx, dword ptr [edi + 4]
// 0088e8c5  68ffffff00           push 0xffffff
// 0088e8ca  8d5dfe               lea ebx, [ebp - 2]
// 0088e8cd  53                   push ebx
// 0088e8ce  51                   push ecx
// 0088e8cf  52                   push edx
// 0088e8d0  ffd6                 call esi
// 0088e8d2  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e8d5  68ffffff00           push 0xffffff
// 0088e8da  8d45fd               lea eax, [ebp - 3]
// 0088e8dd  50                   push eax
// 0088e8de  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088e8e2  50                   push eax
// 0088e8e3  51                   push ecx
// 0088e8e4  ffd6                 call esi
// 0088e8e6  8b542424             mov edx, dword ptr [esp + 0x24]
// 0088e8ea  8b4704               mov eax, dword ptr [edi + 4]
// 0088e8ed  68ffffff00           push 0xffffff
// 0088e8f2  53                   push ebx
// 0088e8f3  52                   push edx
// 0088e8f4  50                   push eax
// 0088e8f5  ffd6                 call esi
// 0088e8f7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088e8fb  8b5704               mov edx, dword ptr [edi + 4]
// 0088e8fe  68ffffff00           push 0xffffff
// 0088e903  8d45fd               lea eax, [ebp - 3]
// 0088e906  50                   push eax
// 0088e907  51                   push ecx
// 0088e908  52                   push edx
// 0088e909  ffd6                 call esi
// 0088e90b  8b4704               mov eax, dword ptr [edi + 4]
// 0088e90e  68ffffff00           push 0xffffff
// 0088e913  53                   push ebx
// 0088e914  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0088e918  53                   push ebx
// 0088e919  50                   push eax
// 0088e91a  ffd6                 call esi
// 0088e91c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e91f  68ffffff00           push 0xffffff
// 0088e924  8d45fd               lea eax, [ebp - 3]
// 0088e927  50                   push eax
// 0088e928  53                   push ebx
// 0088e929  51                   push ecx
// 0088e92a  ffd6                 call esi
// 0088e92c  33db                 xor ebx, ebx
// 0088e92e  8bff                 mov edi, edi
// 0088e930  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088e934  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e937  68ffffff00           push 0xffffff
// 0088e93c  8d542bfd             lea edx, [ebx + ebp - 3]
// 0088e940  52                   push edx
// 0088e941  50                   push eax
// 0088e942  51                   push ecx
// 0088e943  ffd6                 call esi
// 0088e945  43                   inc ebx
// 0088e946  83fb03               cmp ebx, 3
// 0088e949  7ce5                 jl 0x88e930
// 0088e94b  8b542454             mov edx, dword ptr [esp + 0x54]
// 0088e94f  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0088e953  8b4704               mov eax, dword ptr [edi + 4]
// 0088e956  68ffffff00           push 0xffffff
// 0088e95b  52                   push edx
// 0088e95c  53                   push ebx
// 0088e95d  50                   push eax
// 0088e95e  ffd6                 call esi
// 0088e960  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e963  68ffffff00           push 0xffffff
// 0088e968  8d45fe               lea eax, [ebp - 2]
// 0088e96b  50                   push eax
// 0088e96c  53                   push ebx
// 0088e96d  51                   push ecx
// 0088e96e  ffd6                 call esi
// 0088e970  33db                 xor ebx, ebx
// 0088e972  8b442420             mov eax, dword ptr [esp + 0x20]
// 0088e976  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e979  68ffffff00           push 0xffffff
// 0088e97e  8d542bfe             lea edx, [ebx + ebp - 2]
// 0088e982  52                   push edx
// 0088e983  50                   push eax
// 0088e984  51                   push ecx
// 0088e985  ffd6                 call esi
// 0088e987  43                   inc ebx
// 0088e988  83fb03               cmp ebx, 3
// 0088e98b  7ce5                 jl 0x88e972
// 0088e98d  8b5704               mov edx, dword ptr [edi + 4]
// 0088e990  68ffffff00           push 0xffffff
// 0088e995  55                   push ebp
// 0088e996  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 0088e99a  55                   push ebp
// 0088e99b  52                   push edx
// 0088e99c  ffd6                 call esi
// 0088e99e  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 0088e9a2  8b4704               mov eax, dword ptr [edi + 4]
// 0088e9a5  68ffffff00           push 0xffffff
// 0088e9aa  53                   push ebx
// 0088e9ab  55                   push ebp
// 0088e9ac  50                   push eax
// 0088e9ad  ffd6                 call esi
// 0088e9af  33ed                 xor ebp, ebp
// 0088e9b1  8b542444             mov edx, dword ptr [esp + 0x44]
// 0088e9b5  8b4704               mov eax, dword ptr [edi + 4]
// 0088e9b8  68ffffff00           push 0xffffff
// 0088e9bd  8d0c2b               lea ecx, [ebx + ebp]
// 0088e9c0  51                   push ecx
// 0088e9c1  52                   push edx
// 0088e9c2  50                   push eax
// 0088e9c3  ffd6                 call esi
// 0088e9c5  45                   inc ebp
// 0088e9c6  83fd03               cmp ebp, 3
// 0088e9c9  7ce6                 jl 0x88e9b1
// 0088e9cb  5f                   pop edi
// 0088e9cc  5e                   pop esi
// 0088e9cd  5d                   pop ebp
// 0088e9ce  5b                   pop ebx
// 0088e9cf  83c440               add esp, 0x40
// 0088e9d2  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
