// from server: 100% by auto
// roc 2010-06 0088d440  unit: CXTColorHex  size: 3251 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0088d440
//
// 0088d440  81ecbc000000         sub esp, 0xbc
// 0088d446  53                   push ebx
// 0088d447  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 0088d44a  55                   push ebp
// 0088d44b  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 0088d44e  56                   push esi
// 0088d44f  8b355ca19e00         mov esi, dword ptr [0x9ea15c]
// 0088d455  57                   push edi
// 0088d456  8bbc24d0000000       mov edi, dword ptr [esp + 0xd0]
// 0088d45d  83eb02               sub ebx, 2
// 0088d460  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088d468  896c242c             mov dword ptr [esp + 0x2c], ebp
// 0088d46c  8d642400             lea esp, [esp]
// 0088d470  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0088d474  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088d478  8b5704               mov edx, dword ptr [edi + 4]
// 0088d47b  6a00                 push 0
// 0088d47d  50                   push eax
// 0088d47e  03cb                 add ecx, ebx
// 0088d480  51                   push ecx
// 0088d481  52                   push edx
// 0088d482  ffd6                 call esi
// 0088d484  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088d488  ff4c242c             dec dword ptr [esp + 0x2c]
// 0088d48c  40                   inc eax
// 0088d48d  83f803               cmp eax, 3
// 0088d490  89442410             mov dword ptr [esp + 0x10], eax
// 0088d494  7cda                 jl 0x88d470
// 0088d496  6a00                 push 0
// 0088d498  8d45fe               lea eax, [ebp - 2]
// 0088d49b  50                   push eax
// 0088d49c  8d4b03               lea ecx, [ebx + 3]
// 0088d49f  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 0088d4a6  8b4704               mov eax, dword ptr [edi + 4]
// 0088d4a9  51                   push ecx
// 0088d4aa  50                   push eax
// 0088d4ab  894c2458             mov dword ptr [esp + 0x58], ecx
// 0088d4af  ffd6                 call esi
// 0088d4b1  6a00                 push 0
// 0088d4b3  8d45fd               lea eax, [ebp - 3]
// 0088d4b6  8d4b04               lea ecx, [ebx + 4]
// 0088d4b9  50                   push eax
// 0088d4ba  51                   push ecx
// 0088d4bb  894c245c             mov dword ptr [esp + 0x5c], ecx
// 0088d4bf  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d4c2  51                   push ecx
// 0088d4c3  89442434             mov dword ptr [esp + 0x34], eax
// 0088d4c7  ffd6                 call esi
// 0088d4c9  8b542424             mov edx, dword ptr [esp + 0x24]
// 0088d4cd  6a00                 push 0
// 0088d4cf  8d4305               lea eax, [ebx + 5]
// 0088d4d2  52                   push edx
// 0088d4d3  50                   push eax
// 0088d4d4  89442444             mov dword ptr [esp + 0x44], eax
// 0088d4d8  8b4704               mov eax, dword ptr [edi + 4]
// 0088d4db  50                   push eax
// 0088d4dc  ffd6                 call esi
// 0088d4de  6a00                 push 0
// 0088d4e0  8d45fc               lea eax, [ebp - 4]
// 0088d4e3  8d4b06               lea ecx, [ebx + 6]
// 0088d4e6  50                   push eax
// 0088d4e7  51                   push ecx
// 0088d4e8  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 0088d4ef  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d4f2  51                   push ecx
// 0088d4f3  89442430             mov dword ptr [esp + 0x30], eax
// 0088d4f7  ffd6                 call esi
// 0088d4f9  8b542420             mov edx, dword ptr [esp + 0x20]
// 0088d4fd  6a00                 push 0
// 0088d4ff  8d4307               lea eax, [ebx + 7]
// 0088d502  52                   push edx
// 0088d503  50                   push eax
// 0088d504  89842484000000       mov dword ptr [esp + 0x84], eax
// 0088d50b  8b4704               mov eax, dword ptr [edi + 4]
// 0088d50e  50                   push eax
// 0088d50f  ffd6                 call esi
// 0088d511  6a00                 push 0
// 0088d513  8d45fb               lea eax, [ebp - 5]
// 0088d516  8d4b08               lea ecx, [ebx + 8]
// 0088d519  50                   push eax
// 0088d51a  51                   push ecx
// 0088d51b  894c247c             mov dword ptr [esp + 0x7c], ecx
// 0088d51f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d522  51                   push ecx
// 0088d523  89442438             mov dword ptr [esp + 0x38], eax
// 0088d527  ffd6                 call esi
// 0088d529  8b542428             mov edx, dword ptr [esp + 0x28]
// 0088d52d  6a00                 push 0
// 0088d52f  8d4309               lea eax, [ebx + 9]
// 0088d532  52                   push edx
// 0088d533  50                   push eax
// 0088d534  89442474             mov dword ptr [esp + 0x74], eax
// 0088d538  8b4704               mov eax, dword ptr [edi + 4]
// 0088d53b  50                   push eax
// 0088d53c  ffd6                 call esi
// 0088d53e  6a00                 push 0
// 0088d540  8d45fa               lea eax, [ebp - 6]
// 0088d543  8d4b0a               lea ecx, [ebx + 0xa]
// 0088d546  50                   push eax
// 0088d547  51                   push ecx
// 0088d548  894c246c             mov dword ptr [esp + 0x6c], ecx
// 0088d54c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d54f  51                   push ecx
// 0088d550  8944244c             mov dword ptr [esp + 0x4c], eax
// 0088d554  ffd6                 call esi
// 0088d556  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0088d55a  8d430b               lea eax, [ebx + 0xb]
// 0088d55d  89842494000000       mov dword ptr [esp + 0x94], eax
// 0088d564  6a00                 push 0
// 0088d566  52                   push edx
// 0088d567  50                   push eax
// 0088d568  8b4704               mov eax, dword ptr [edi + 4]
// 0088d56b  50                   push eax
// 0088d56c  ffd6                 call esi
// 0088d56e  6a00                 push 0
// 0088d570  8d45f9               lea eax, [ebp - 7]
// 0088d573  8d4b0c               lea ecx, [ebx + 0xc]
// 0088d576  50                   push eax
// 0088d577  51                   push ecx
// 0088d578  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 0088d57f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d582  51                   push ecx
// 0088d583  89442468             mov dword ptr [esp + 0x68], eax
// 0088d587  ffd6                 call esi
// 0088d589  8b542458             mov edx, dword ptr [esp + 0x58]
// 0088d58d  6a00                 push 0
// 0088d58f  8d430d               lea eax, [ebx + 0xd]
// 0088d592  52                   push edx
// 0088d593  50                   push eax
// 0088d594  89842498000000       mov dword ptr [esp + 0x98], eax
// 0088d59b  8b4704               mov eax, dword ptr [edi + 4]
// 0088d59e  50                   push eax
// 0088d59f  ffd6                 call esi
// 0088d5a1  6a00                 push 0
// 0088d5a3  8d45f8               lea eax, [ebp - 8]
// 0088d5a6  8d4b0e               lea ecx, [ebx + 0xe]
// 0088d5a9  50                   push eax
// 0088d5aa  51                   push ecx
// 0088d5ab  898c24b4000000       mov dword ptr [esp + 0xb4], ecx
// 0088d5b2  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d5b5  51                   push ecx
// 0088d5b6  ffd6                 call esi
// 0088d5b8  8b5704               mov edx, dword ptr [edi + 4]
// 0088d5bb  6a00                 push 0
// 0088d5bd  8d45f8               lea eax, [ebp - 8]
// 0088d5c0  8d4b0f               lea ecx, [ebx + 0xf]
// 0088d5c3  50                   push eax
// 0088d5c4  51                   push ecx
// 0088d5c5  52                   push edx
// 0088d5c6  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 0088d5cd  ffd6                 call esi
// 0088d5cf  6a00                 push 0
// 0088d5d1  8d45f8               lea eax, [ebp - 8]
// 0088d5d4  50                   push eax
// 0088d5d5  8b4704               mov eax, dword ptr [edi + 4]
// 0088d5d8  8d4b10               lea ecx, [ebx + 0x10]
// 0088d5db  51                   push ecx
// 0088d5dc  50                   push eax
// 0088d5dd  898c24c4000000       mov dword ptr [esp + 0xc4], ecx
// 0088d5e4  ffd6                 call esi
// 0088d5e6  6a00                 push 0
// 0088d5e8  8d45f8               lea eax, [ebp - 8]
// 0088d5eb  8d4b11               lea ecx, [ebx + 0x11]
// 0088d5ee  50                   push eax
// 0088d5ef  51                   push ecx
// 0088d5f0  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 0088d5f7  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d5fa  51                   push ecx
// 0088d5fb  ffd6                 call esi
// 0088d5fd  8b5704               mov edx, dword ptr [edi + 4]
// 0088d600  6a00                 push 0
// 0088d602  8d45f8               lea eax, [ebp - 8]
// 0088d605  8d4b12               lea ecx, [ebx + 0x12]
// 0088d608  50                   push eax
// 0088d609  51                   push ecx
// 0088d60a  52                   push edx
// 0088d60b  898c24bc000000       mov dword ptr [esp + 0xbc], ecx
// 0088d612  ffd6                 call esi
// 0088d614  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0088d618  8b5704               mov edx, dword ptr [edi + 4]
// 0088d61b  6a00                 push 0
// 0088d61d  8d4313               lea eax, [ebx + 0x13]
// 0088d620  51                   push ecx
// 0088d621  50                   push eax
// 0088d622  52                   push edx
// 0088d623  89842484000000       mov dword ptr [esp + 0x84], eax
// 0088d62a  ffd6                 call esi
// 0088d62c  8d4314               lea eax, [ebx + 0x14]
// 0088d62f  8944245c             mov dword ptr [esp + 0x5c], eax
// 0088d633  6a00                 push 0
// 0088d635  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0088d639  8b5704               mov edx, dword ptr [edi + 4]
// 0088d63c  51                   push ecx
// 0088d63d  50                   push eax
// 0088d63e  52                   push edx
// 0088d63f  ffd6                 call esi
// 0088d641  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0088d645  8b5704               mov edx, dword ptr [edi + 4]
// 0088d648  6a00                 push 0
// 0088d64a  8d4315               lea eax, [ebx + 0x15]
// 0088d64d  51                   push ecx
// 0088d64e  50                   push eax
// 0088d64f  52                   push edx
// 0088d650  8944247c             mov dword ptr [esp + 0x7c], eax
// 0088d654  ffd6                 call esi
// 0088d656  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0088d65a  8b5704               mov edx, dword ptr [edi + 4]
// 0088d65d  6a00                 push 0
// 0088d65f  8d4316               lea eax, [ebx + 0x16]
// 0088d662  51                   push ecx
// 0088d663  50                   push eax
// 0088d664  52                   push edx
// 0088d665  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 0088d66c  ffd6                 call esi
// 0088d66e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088d672  8b5704               mov edx, dword ptr [edi + 4]
// 0088d675  6a00                 push 0
// 0088d677  8d4317               lea eax, [ebx + 0x17]
// 0088d67a  51                   push ecx
// 0088d67b  50                   push eax
// 0088d67c  52                   push edx
// 0088d67d  89442474             mov dword ptr [esp + 0x74], eax
// 0088d681  ffd6                 call esi
// 0088d683  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088d687  8b5704               mov edx, dword ptr [edi + 4]
// 0088d68a  6a00                 push 0
// 0088d68c  8d4318               lea eax, [ebx + 0x18]
// 0088d68f  51                   push ecx
// 0088d690  50                   push eax
// 0088d691  52                   push edx
// 0088d692  89442464             mov dword ptr [esp + 0x64], eax
// 0088d696  ffd6                 call esi
// 0088d698  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088d69c  8b5704               mov edx, dword ptr [edi + 4]
// 0088d69f  6a00                 push 0
// 0088d6a1  8d4319               lea eax, [ebx + 0x19]
// 0088d6a4  51                   push ecx
// 0088d6a5  50                   push eax
// 0088d6a6  52                   push edx
// 0088d6a7  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 0088d6ae  ffd6                 call esi
// 0088d6b0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088d6b4  8b5704               mov edx, dword ptr [edi + 4]
// 0088d6b7  6a00                 push 0
// 0088d6b9  8d431a               lea eax, [ebx + 0x1a]
// 0088d6bc  51                   push ecx
// 0088d6bd  50                   push eax
// 0088d6be  52                   push edx
// 0088d6bf  89842498000000       mov dword ptr [esp + 0x98], eax
// 0088d6c6  ffd6                 call esi
// 0088d6c8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088d6cc  8b5704               mov edx, dword ptr [edi + 4]
// 0088d6cf  6a00                 push 0
// 0088d6d1  8d431b               lea eax, [ebx + 0x1b]
// 0088d6d4  51                   push ecx
// 0088d6d5  50                   push eax
// 0088d6d6  52                   push edx
// 0088d6d7  898424ac000000       mov dword ptr [esp + 0xac], eax
// 0088d6de  ffd6                 call esi
// 0088d6e0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088d6e4  8b5704               mov edx, dword ptr [edi + 4]
// 0088d6e7  6a00                 push 0
// 0088d6e9  8d431c               lea eax, [ebx + 0x1c]
// 0088d6ec  51                   push ecx
// 0088d6ed  50                   push eax
// 0088d6ee  52                   push edx
// 0088d6ef  898424a0000000       mov dword ptr [esp + 0xa0], eax
// 0088d6f6  ffd6                 call esi
// 0088d6f8  8d431d               lea eax, [ebx + 0x1d]
// 0088d6fb  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 0088d702  6a00                 push 0
// 0088d704  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 0088d70b  8b5704               mov edx, dword ptr [edi + 4]
// 0088d70e  51                   push ecx
// 0088d70f  50                   push eax
// 0088d710  52                   push edx
// 0088d711  ffd6                 call esi
// 0088d713  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 0088d71a  8b5704               mov edx, dword ptr [edi + 4]
// 0088d71d  6a00                 push 0
// 0088d71f  8d431e               lea eax, [ebx + 0x1e]
// 0088d722  51                   push ecx
// 0088d723  50                   push eax
// 0088d724  52                   push edx
// 0088d725  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 0088d72c  ffd6                 call esi
// 0088d72e  6a00                 push 0
// 0088d730  8d45ff               lea eax, [ebp - 1]
// 0088d733  50                   push eax
// 0088d734  8d4b1f               lea ecx, [ebx + 0x1f]
// 0088d737  8944244c             mov dword ptr [esp + 0x4c], eax
// 0088d73b  8b4704               mov eax, dword ptr [edi + 4]
// 0088d73e  51                   push ecx
// 0088d73f  50                   push eax
// 0088d740  898c24d0000000       mov dword ptr [esp + 0xd0], ecx
// 0088d747  ffd6                 call esi
// 0088d749  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088d751  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0088d755  8b5704               mov edx, dword ptr [edi + 4]
// 0088d758  6a00                 push 0
// 0088d75a  03cd                 add ecx, ebp
// 0088d75c  51                   push ecx
// 0088d75d  8d4320               lea eax, [ebx + 0x20]
// 0088d760  50                   push eax
// 0088d761  52                   push edx
// 0088d762  ffd6                 call esi
// 0088d764  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088d768  40                   inc eax
// 0088d769  83f811               cmp eax, 0x11
// 0088d76c  89442410             mov dword ptr [esp + 0x10], eax
// 0088d770  7cdf                 jl 0x88d751
// 0088d772  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d775  6a00                 push 0
// 0088d777  8d4511               lea eax, [ebp + 0x11]
// 0088d77a  50                   push eax
// 0088d77b  8944243c             mov dword ptr [esp + 0x3c], eax
// 0088d77f  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 0088d786  50                   push eax
// 0088d787  51                   push ecx
// 0088d788  ffd6                 call esi
// 0088d78a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 0088d791  6a00                 push 0
// 0088d793  8d4512               lea eax, [ebp + 0x12]
// 0088d796  50                   push eax
// 0088d797  8944241c             mov dword ptr [esp + 0x1c], eax
// 0088d79b  8b4704               mov eax, dword ptr [edi + 4]
// 0088d79e  52                   push edx
// 0088d79f  50                   push eax
// 0088d7a0  ffd6                 call esi
// 0088d7a2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088d7a6  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 0088d7ad  8b4704               mov eax, dword ptr [edi + 4]
// 0088d7b0  6a00                 push 0
// 0088d7b2  51                   push ecx
// 0088d7b3  52                   push edx
// 0088d7b4  50                   push eax
// 0088d7b5  ffd6                 call esi
// 0088d7b7  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 0088d7be  8b5704               mov edx, dword ptr [edi + 4]
// 0088d7c1  6a00                 push 0
// 0088d7c3  8d4513               lea eax, [ebp + 0x13]
// 0088d7c6  50                   push eax
// 0088d7c7  51                   push ecx
// 0088d7c8  52                   push edx
// 0088d7c9  8944242c             mov dword ptr [esp + 0x2c], eax
// 0088d7cd  ffd6                 call esi
// 0088d7cf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088d7d3  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0088d7da  8b5704               mov edx, dword ptr [edi + 4]
// 0088d7dd  6a00                 push 0
// 0088d7df  50                   push eax
// 0088d7e0  51                   push ecx
// 0088d7e1  52                   push edx
// 0088d7e2  ffd6                 call esi
// 0088d7e4  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d7e7  6a00                 push 0
// 0088d7e9  8d4514               lea eax, [ebp + 0x14]
// 0088d7ec  50                   push eax
// 0088d7ed  89442420             mov dword ptr [esp + 0x20], eax
// 0088d7f1  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 0088d7f8  50                   push eax
// 0088d7f9  51                   push ecx
// 0088d7fa  ffd6                 call esi
// 0088d7fc  8b542418             mov edx, dword ptr [esp + 0x18]
// 0088d800  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 0088d807  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d80a  6a00                 push 0
// 0088d80c  52                   push edx
// 0088d80d  50                   push eax
// 0088d80e  51                   push ecx
// 0088d80f  ffd6                 call esi
// 0088d811  8b542454             mov edx, dword ptr [esp + 0x54]
// 0088d815  6a00                 push 0
// 0088d817  8d4515               lea eax, [ebp + 0x15]
// 0088d81a  50                   push eax
// 0088d81b  89442438             mov dword ptr [esp + 0x38], eax
// 0088d81f  8b4704               mov eax, dword ptr [edi + 4]
// 0088d822  52                   push edx
// 0088d823  50                   push eax
// 0088d824  ffd6                 call esi
// 0088d826  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0088d82a  8b542464             mov edx, dword ptr [esp + 0x64]
// 0088d82e  8b4704               mov eax, dword ptr [edi + 4]
// 0088d831  6a00                 push 0
// 0088d833  51                   push ecx
// 0088d834  52                   push edx
// 0088d835  50                   push eax
// 0088d836  ffd6                 call esi
// 0088d838  8d4516               lea eax, [ebp + 0x16]
// 0088d83b  6a00                 push 0
// 0088d83d  89442450             mov dword ptr [esp + 0x50], eax
// 0088d841  50                   push eax
// 0088d842  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 0088d849  8b5704               mov edx, dword ptr [edi + 4]
// 0088d84c  51                   push ecx
// 0088d84d  52                   push edx
// 0088d84e  ffd6                 call esi
// 0088d850  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0088d854  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0088d858  8b5704               mov edx, dword ptr [edi + 4]
// 0088d85b  6a00                 push 0
// 0088d85d  50                   push eax
// 0088d85e  51                   push ecx
// 0088d85f  52                   push edx
// 0088d860  ffd6                 call esi
// 0088d862  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d865  6a00                 push 0
// 0088d867  8d4517               lea eax, [ebp + 0x17]
// 0088d86a  50                   push eax
// 0088d86b  89442434             mov dword ptr [esp + 0x34], eax
// 0088d86f  8b442464             mov eax, dword ptr [esp + 0x64]
// 0088d873  50                   push eax
// 0088d874  51                   push ecx
// 0088d875  ffd6                 call esi
// 0088d877  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0088d87b  8b442474             mov eax, dword ptr [esp + 0x74]
// 0088d87f  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d882  6a00                 push 0
// 0088d884  52                   push edx
// 0088d885  50                   push eax
// 0088d886  51                   push ecx
// 0088d887  ffd6                 call esi
// 0088d889  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 0088d890  6a00                 push 0
// 0088d892  8d4518               lea eax, [ebp + 0x18]
// 0088d895  50                   push eax
// 0088d896  8b4704               mov eax, dword ptr [edi + 4]
// 0088d899  52                   push edx
// 0088d89a  50                   push eax
// 0088d89b  ffd6                 call esi
// 0088d89d  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 0088d8a1  8b5704               mov edx, dword ptr [edi + 4]
// 0088d8a4  6a00                 push 0
// 0088d8a6  8d4518               lea eax, [ebp + 0x18]
// 0088d8a9  50                   push eax
// 0088d8aa  51                   push ecx
// 0088d8ab  52                   push edx
// 0088d8ac  ffd6                 call esi
// 0088d8ae  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d8b1  6a00                 push 0
// 0088d8b3  8d4518               lea eax, [ebp + 0x18]
// 0088d8b6  50                   push eax
// 0088d8b7  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0088d8be  50                   push eax
// 0088d8bf  51                   push ecx
// 0088d8c0  ffd6                 call esi
// 0088d8c2  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 0088d8c9  6a00                 push 0
// 0088d8cb  8d4518               lea eax, [ebp + 0x18]
// 0088d8ce  50                   push eax
// 0088d8cf  8b4704               mov eax, dword ptr [edi + 4]
// 0088d8d2  52                   push edx
// 0088d8d3  50                   push eax
// 0088d8d4  ffd6                 call esi
// 0088d8d6  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 0088d8dd  8b5704               mov edx, dword ptr [edi + 4]
// 0088d8e0  6a00                 push 0
// 0088d8e2  8d4518               lea eax, [ebp + 0x18]
// 0088d8e5  50                   push eax
// 0088d8e6  51                   push ecx
// 0088d8e7  52                   push edx
// 0088d8e8  ffd6                 call esi
// 0088d8ea  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0088d8ee  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 0088d8f5  8b5704               mov edx, dword ptr [edi + 4]
// 0088d8f8  6a00                 push 0
// 0088d8fa  50                   push eax
// 0088d8fb  51                   push ecx
// 0088d8fc  52                   push edx
// 0088d8fd  ffd6                 call esi
// 0088d8ff  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0088d903  6a00                 push 0
// 0088d905  50                   push eax
// 0088d906  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 0088d90d  8b5704               mov edx, dword ptr [edi + 4]
// 0088d910  51                   push ecx
// 0088d911  52                   push edx
// 0088d912  ffd6                 call esi
// 0088d914  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0088d918  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0088d91f  8b5704               mov edx, dword ptr [edi + 4]
// 0088d922  6a00                 push 0
// 0088d924  50                   push eax
// 0088d925  51                   push ecx
// 0088d926  52                   push edx
// 0088d927  ffd6                 call esi
// 0088d929  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0088d92d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0088d931  8b5704               mov edx, dword ptr [edi + 4]
// 0088d934  6a00                 push 0
// 0088d936  50                   push eax
// 0088d937  51                   push ecx
// 0088d938  52                   push edx
// 0088d939  ffd6                 call esi
// 0088d93b  8b442430             mov eax, dword ptr [esp + 0x30]
// 0088d93f  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0088d943  8b5704               mov edx, dword ptr [edi + 4]
// 0088d946  6a00                 push 0
// 0088d948  50                   push eax
// 0088d949  51                   push ecx
// 0088d94a  52                   push edx
// 0088d94b  ffd6                 call esi
// 0088d94d  8b442430             mov eax, dword ptr [esp + 0x30]
// 0088d951  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0088d955  8b5704               mov edx, dword ptr [edi + 4]
// 0088d958  6a00                 push 0
// 0088d95a  50                   push eax
// 0088d95b  51                   push ecx
// 0088d95c  52                   push edx
// 0088d95d  ffd6                 call esi
// 0088d95f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088d963  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0088d967  8b5704               mov edx, dword ptr [edi + 4]
// 0088d96a  6a00                 push 0
// 0088d96c  50                   push eax
// 0088d96d  51                   push ecx
// 0088d96e  52                   push edx
// 0088d96f  ffd6                 call esi
// 0088d971  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088d975  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 0088d97c  8b5704               mov edx, dword ptr [edi + 4]
// 0088d97f  6a00                 push 0
// 0088d981  50                   push eax
// 0088d982  51                   push ecx
// 0088d983  52                   push edx
// 0088d984  ffd6                 call esi
// 0088d986  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088d98a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0088d98e  8b5704               mov edx, dword ptr [edi + 4]
// 0088d991  6a00                 push 0
// 0088d993  50                   push eax
// 0088d994  51                   push ecx
// 0088d995  52                   push edx
// 0088d996  ffd6                 call esi
// 0088d998  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088d99c  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0088d9a0  8b5704               mov edx, dword ptr [edi + 4]
// 0088d9a3  6a00                 push 0
// 0088d9a5  50                   push eax
// 0088d9a6  51                   push ecx
// 0088d9a7  52                   push edx
// 0088d9a8  ffd6                 call esi
// 0088d9aa  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088d9ae  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0088d9b2  8b5704               mov edx, dword ptr [edi + 4]
// 0088d9b5  6a00                 push 0
// 0088d9b7  50                   push eax
// 0088d9b8  51                   push ecx
// 0088d9b9  52                   push edx
// 0088d9ba  ffd6                 call esi
// 0088d9bc  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088d9c0  8d4302               lea eax, [ebx + 2]
// 0088d9c3  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 0088d9ca  6a00                 push 0
// 0088d9cc  8b5704               mov edx, dword ptr [edi + 4]
// 0088d9cf  51                   push ecx
// 0088d9d0  50                   push eax
// 0088d9d1  52                   push edx
// 0088d9d2  ffd6                 call esi
// 0088d9d4  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0088d9d8  8b5704               mov edx, dword ptr [edi + 4]
// 0088d9db  6a00                 push 0
// 0088d9dd  8d4301               lea eax, [ebx + 1]
// 0088d9e0  51                   push ecx
// 0088d9e1  50                   push eax
// 0088d9e2  52                   push edx
// 0088d9e3  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 0088d9ea  ffd6                 call esi
// 0088d9ec  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0088d9f4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088d9f8  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088d9fb  6a00                 push 0
// 0088d9fd  03c5                 add eax, ebp
// 0088d9ff  50                   push eax
// 0088da00  53                   push ebx
// 0088da01  51                   push ecx
// 0088da02  ffd6                 call esi
// 0088da04  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088da08  40                   inc eax
// 0088da09  83f811               cmp eax, 0x11
// 0088da0c  89442410             mov dword ptr [esp + 0x10], eax
// 0088da10  7ce2                 jl 0x88d9f4
// 0088da12  33db                 xor ebx, ebx
// 0088da14  8b442450             mov eax, dword ptr [esp + 0x50]
// 0088da18  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088da1b  6a00                 push 0
// 0088da1d  8d542b01             lea edx, [ebx + ebp + 1]
// 0088da21  52                   push edx
// 0088da22  50                   push eax
// 0088da23  51                   push ecx
// 0088da24  ffd6                 call esi
// 0088da26  43                   inc ebx
// 0088da27  83fb0f               cmp ebx, 0xf
// 0088da2a  7ce8                 jl 0x88da14
// 0088da2c  8b542438             mov edx, dword ptr [esp + 0x38]
// 0088da30  8b4704               mov eax, dword ptr [edi + 4]
// 0088da33  6a00                 push 0
// 0088da35  8d5d10               lea ebx, [ebp + 0x10]
// 0088da38  53                   push ebx
// 0088da39  52                   push edx
// 0088da3a  50                   push eax
// 0088da3b  895c2450             mov dword ptr [esp + 0x50], ebx
// 0088da3f  ffd6                 call esi
// 0088da41  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 0088da48  8b5704               mov edx, dword ptr [edi + 4]
// 0088da4b  6a00                 push 0
// 0088da4d  53                   push ebx
// 0088da4e  51                   push ecx
// 0088da4f  52                   push edx
// 0088da50  ffd6                 call esi
// 0088da52  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088da56  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0088da5a  8b5704               mov edx, dword ptr [edi + 4]
// 0088da5d  6a00                 push 0
// 0088da5f  50                   push eax
// 0088da60  51                   push ecx
// 0088da61  52                   push edx
// 0088da62  ffd6                 call esi
// 0088da64  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088da68  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0088da6c  8b5704               mov edx, dword ptr [edi + 4]
// 0088da6f  6a00                 push 0
// 0088da71  50                   push eax
// 0088da72  51                   push ecx
// 0088da73  52                   push edx
// 0088da74  ffd6                 call esi
// 0088da76  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088da7a  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 0088da7e  8b5704               mov edx, dword ptr [edi + 4]
// 0088da81  6a00                 push 0
// 0088da83  50                   push eax
// 0088da84  51                   push ecx
// 0088da85  52                   push edx
// 0088da86  ffd6                 call esi
// 0088da88  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088da8c  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0088da90  8b5704               mov edx, dword ptr [edi + 4]
// 0088da93  6a00                 push 0
// 0088da95  50                   push eax
// 0088da96  51                   push ecx
// 0088da97  52                   push edx
// 0088da98  ffd6                 call esi
// 0088da9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088da9e  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0088daa5  8b5704               mov edx, dword ptr [edi + 4]
// 0088daa8  6a00                 push 0
// 0088daaa  50                   push eax
// 0088daab  51                   push ecx
// 0088daac  52                   push edx
// 0088daad  ffd6                 call esi
// 0088daaf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088dab3  8b8c24a0000000       mov ecx, dword ptr [esp + 0xa0]
// 0088daba  8b5704               mov edx, dword ptr [edi + 4]
// 0088dabd  6a00                 push 0
// 0088dabf  50                   push eax
// 0088dac0  51                   push ecx
// 0088dac1  52                   push edx
// 0088dac2  ffd6                 call esi
// 0088dac4  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088dac8  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 0088dacf  8b5704               mov edx, dword ptr [edi + 4]
// 0088dad2  6a00                 push 0
// 0088dad4  50                   push eax
// 0088dad5  51                   push ecx
// 0088dad6  52                   push edx
// 0088dad7  ffd6                 call esi
// 0088dad9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088dadd  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 0088dae4  8b5704               mov edx, dword ptr [edi + 4]
// 0088dae7  6a00                 push 0
// 0088dae9  50                   push eax
// 0088daea  51                   push ecx
// 0088daeb  52                   push edx
// 0088daec  ffd6                 call esi
// 0088daee  6a00                 push 0
// 0088daf0  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088daf4  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0088dafb  8b5704               mov edx, dword ptr [edi + 4]
// 0088dafe  50                   push eax
// 0088daff  51                   push ecx
// 0088db00  52                   push edx
// 0088db01  ffd6                 call esi
// 0088db03  8b442430             mov eax, dword ptr [esp + 0x30]
// 0088db07  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 0088db0e  8b5704               mov edx, dword ptr [edi + 4]
// 0088db11  6a00                 push 0
// 0088db13  50                   push eax
// 0088db14  51                   push ecx
// 0088db15  52                   push edx
// 0088db16  ffd6                 call esi
// 0088db18  8b442430             mov eax, dword ptr [esp + 0x30]
// 0088db1c  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 0088db20  8b5704               mov edx, dword ptr [edi + 4]
// 0088db23  6a00                 push 0
// 0088db25  50                   push eax
// 0088db26  51                   push ecx
// 0088db27  52                   push edx
// 0088db28  ffd6                 call esi
// 0088db2a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088db2e  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 0088db35  8b5704               mov edx, dword ptr [edi + 4]
// 0088db38  6a00                 push 0
// 0088db3a  50                   push eax
// 0088db3b  51                   push ecx
// 0088db3c  52                   push edx
// 0088db3d  ffd6                 call esi
// 0088db3f  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088db43  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0088db47  8b5704               mov edx, dword ptr [edi + 4]
// 0088db4a  6a00                 push 0
// 0088db4c  50                   push eax
// 0088db4d  51                   push ecx
// 0088db4e  52                   push edx
// 0088db4f  ffd6                 call esi
// 0088db51  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088db55  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0088db59  8b5704               mov edx, dword ptr [edi + 4]
// 0088db5c  6a00                 push 0
// 0088db5e  50                   push eax
// 0088db5f  51                   push ecx
// 0088db60  52                   push edx
// 0088db61  ffd6                 call esi
// 0088db63  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0088db67  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0088db6b  8b5704               mov edx, dword ptr [edi + 4]
// 0088db6e  6a00                 push 0
// 0088db70  50                   push eax
// 0088db71  51                   push ecx
// 0088db72  52                   push edx
// 0088db73  ffd6                 call esi
// 0088db75  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088db79  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 0088db80  8b5704               mov edx, dword ptr [edi + 4]
// 0088db83  6a00                 push 0
// 0088db85  50                   push eax
// 0088db86  51                   push ecx
// 0088db87  52                   push edx
// 0088db88  ffd6                 call esi
// 0088db8a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088db8e  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 0088db92  8b5704               mov edx, dword ptr [edi + 4]
// 0088db95  6a00                 push 0
// 0088db97  50                   push eax
// 0088db98  51                   push ecx
// 0088db99  52                   push edx
// 0088db9a  ffd6                 call esi
// 0088db9c  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088dba0  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088dba4  8b5704               mov edx, dword ptr [edi + 4]
// 0088dba7  6a00                 push 0
// 0088dba9  50                   push eax
// 0088dbaa  51                   push ecx
// 0088dbab  52                   push edx
// 0088dbac  ffd6                 call esi
// 0088dbae  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088dbb2  6a00                 push 0
// 0088dbb4  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0088dbbb  8b5704               mov edx, dword ptr [edi + 4]
// 0088dbbe  50                   push eax
// 0088dbbf  51                   push ecx
// 0088dbc0  52                   push edx
// 0088dbc1  ffd6                 call esi
// 0088dbc3  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0088dbca  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dbcd  6a00                 push 0
// 0088dbcf  53                   push ebx
// 0088dbd0  50                   push eax
// 0088dbd1  51                   push ecx
// 0088dbd2  ffd6                 call esi
// 0088dbd4  8b94249c000000       mov edx, dword ptr [esp + 0x9c]
// 0088dbdb  8b4704               mov eax, dword ptr [edi + 4]
// 0088dbde  6a00                 push 0
// 0088dbe0  53                   push ebx
// 0088dbe1  52                   push edx
// 0088dbe2  50                   push eax
// 0088dbe3  ffd6                 call esi
// 0088dbe5  33db                 xor ebx, ebx
// 0088dbe7  eb07                 jmp 0x88dbf0
// 0088dbe9  8da42400000000       lea esp, [esp]
// 0088dbf0  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 0088dbf7  8b4704               mov eax, dword ptr [edi + 4]
// 0088dbfa  6a00                 push 0
// 0088dbfc  8d4c2b01             lea ecx, [ebx + ebp + 1]
// 0088dc00  51                   push ecx
// 0088dc01  52                   push edx
// 0088dc02  50                   push eax
// 0088dc03  ffd6                 call esi
// 0088dc05  43                   inc ebx
// 0088dc06  83fb0f               cmp ebx, 0xf
// 0088dc09  7ce5                 jl 0x88dbf0
// 0088dc0b  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 0088dc12  8b5704               mov edx, dword ptr [edi + 4]
// 0088dc15  6a00                 push 0
// 0088dc17  55                   push ebp
// 0088dc18  51                   push ecx
// 0088dc19  52                   push edx
// 0088dc1a  ffd6                 call esi
// 0088dc1c  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0088dc23  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dc26  6a00                 push 0
// 0088dc28  55                   push ebp
// 0088dc29  50                   push eax
// 0088dc2a  51                   push ecx
// 0088dc2b  ffd6                 call esi
// 0088dc2d  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0088dc31  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 0088dc38  8b4704               mov eax, dword ptr [edi + 4]
// 0088dc3b  6a00                 push 0
// 0088dc3d  53                   push ebx
// 0088dc3e  52                   push edx
// 0088dc3f  50                   push eax
// 0088dc40  ffd6                 call esi
// 0088dc42  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 0088dc46  8b5704               mov edx, dword ptr [edi + 4]
// 0088dc49  6a00                 push 0
// 0088dc4b  53                   push ebx
// 0088dc4c  51                   push ecx
// 0088dc4d  52                   push edx
// 0088dc4e  ffd6                 call esi
// 0088dc50  8b9c24b0000000       mov ebx, dword ptr [esp + 0xb0]
// 0088dc57  8b442464             mov eax, dword ptr [esp + 0x64]
// 0088dc5b  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dc5e  6a00                 push 0
// 0088dc60  53                   push ebx
// 0088dc61  50                   push eax
// 0088dc62  51                   push ecx
// 0088dc63  ffd6                 call esi
// 0088dc65  8b9424a4000000       mov edx, dword ptr [esp + 0xa4]
// 0088dc6c  8b4704               mov eax, dword ptr [edi + 4]
// 0088dc6f  6a00                 push 0
// 0088dc71  53                   push ebx
// 0088dc72  52                   push edx
// 0088dc73  50                   push eax
// 0088dc74  ffd6                 call esi
// 0088dc76  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088dc7a  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 0088dc7e  8b4704               mov eax, dword ptr [edi + 4]
// 0088dc81  6a00                 push 0
// 0088dc83  51                   push ecx
// 0088dc84  52                   push edx
// 0088dc85  50                   push eax
// 0088dc86  ffd6                 call esi
// 0088dc88  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088dc8c  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 0088dc90  8b4704               mov eax, dword ptr [edi + 4]
// 0088dc93  6a00                 push 0
// 0088dc95  51                   push ecx
// 0088dc96  52                   push edx
// 0088dc97  50                   push eax
// 0088dc98  ffd6                 call esi
// 0088dc9a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088dc9e  8b542474             mov edx, dword ptr [esp + 0x74]
// 0088dca2  8b4704               mov eax, dword ptr [edi + 4]
// 0088dca5  6a00                 push 0
// 0088dca7  51                   push ecx
// 0088dca8  52                   push edx
// 0088dca9  50                   push eax
// 0088dcaa  ffd6                 call esi
// 0088dcac  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088dcb0  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 0088dcb7  8b4704               mov eax, dword ptr [edi + 4]
// 0088dcba  6a00                 push 0
// 0088dcbc  51                   push ecx
// 0088dcbd  52                   push edx
// 0088dcbe  50                   push eax
// 0088dcbf  ffd6                 call esi
// 0088dcc1  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088dcc5  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 0088dcc9  6a00                 push 0
// 0088dccb  51                   push ecx
// 0088dccc  52                   push edx
// 0088dccd  8b4704               mov eax, dword ptr [edi + 4]
// 0088dcd0  50                   push eax
// 0088dcd1  ffd6                 call esi
// 0088dcd3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088dcd7  8b9424b4000000       mov edx, dword ptr [esp + 0xb4]
// 0088dcde  8b4704               mov eax, dword ptr [edi + 4]
// 0088dce1  6a00                 push 0
// 0088dce3  51                   push ecx
// 0088dce4  52                   push edx
// 0088dce5  50                   push eax
// 0088dce6  ffd6                 call esi
// 0088dce8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088dcec  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 0088dcf3  8b4704               mov eax, dword ptr [edi + 4]
// 0088dcf6  6a00                 push 0
// 0088dcf8  51                   push ecx
// 0088dcf9  52                   push edx
// 0088dcfa  50                   push eax
// 0088dcfb  ffd6                 call esi
// 0088dcfd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088dd01  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 0088dd08  8b4704               mov eax, dword ptr [edi + 4]
// 0088dd0b  6a00                 push 0
// 0088dd0d  51                   push ecx
// 0088dd0e  52                   push edx
// 0088dd0f  50                   push eax
// 0088dd10  ffd6                 call esi
// 0088dd12  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088dd16  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 0088dd1d  8b4704               mov eax, dword ptr [edi + 4]
// 0088dd20  6a00                 push 0
// 0088dd22  51                   push ecx
// 0088dd23  52                   push edx
// 0088dd24  50                   push eax
// 0088dd25  ffd6                 call esi
// 0088dd27  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088dd2b  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 0088dd32  8b4704               mov eax, dword ptr [edi + 4]
// 0088dd35  6a00                 push 0
// 0088dd37  51                   push ecx
// 0088dd38  52                   push edx
// 0088dd39  50                   push eax
// 0088dd3a  ffd6                 call esi
// 0088dd3c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088dd40  8b942494000000       mov edx, dword ptr [esp + 0x94]
// 0088dd47  8b4704               mov eax, dword ptr [edi + 4]
// 0088dd4a  6a00                 push 0
// 0088dd4c  51                   push ecx
// 0088dd4d  52                   push edx
// 0088dd4e  50                   push eax
// 0088dd4f  ffd6                 call esi
// 0088dd51  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0088dd55  8b5704               mov edx, dword ptr [edi + 4]
// 0088dd58  6a00                 push 0
// 0088dd5a  53                   push ebx
// 0088dd5b  51                   push ecx
// 0088dd5c  52                   push edx
// 0088dd5d  ffd6                 call esi
// 0088dd5f  8b442468             mov eax, dword ptr [esp + 0x68]
// 0088dd63  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dd66  6a00                 push 0
// 0088dd68  53                   push ebx
// 0088dd69  50                   push eax
// 0088dd6a  51                   push ecx
// 0088dd6b  ffd6                 call esi
// 0088dd6d  8b542444             mov edx, dword ptr [esp + 0x44]
// 0088dd71  8b442470             mov eax, dword ptr [esp + 0x70]
// 0088dd75  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dd78  6a00                 push 0
// 0088dd7a  52                   push edx
// 0088dd7b  50                   push eax
// 0088dd7c  51                   push ecx
// 0088dd7d  ffd6                 call esi
// 0088dd7f  8b542444             mov edx, dword ptr [esp + 0x44]
// 0088dd83  8b442478             mov eax, dword ptr [esp + 0x78]
// 0088dd87  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dd8a  6a00                 push 0
// 0088dd8c  52                   push edx
// 0088dd8d  50                   push eax
// 0088dd8e  51                   push ecx
// 0088dd8f  ffd6                 call esi
// 0088dd91  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 0088dd98  8b4704               mov eax, dword ptr [edi + 4]
// 0088dd9b  6a00                 push 0
// 0088dd9d  55                   push ebp
// 0088dd9e  52                   push edx
// 0088dd9f  50                   push eax
// 0088dda0  ffd6                 call esi
// 0088dda2  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0088dda6  8b5704               mov edx, dword ptr [edi + 4]
// 0088dda9  6a00                 push 0
// 0088ddab  55                   push ebp
// 0088ddac  51                   push ecx
// 0088ddad  52                   push edx
// 0088ddae  ffd6                 call esi
// 0088ddb0  896c2410             mov dword ptr [esp + 0x10], ebp
// 0088ddb4  c744243811000000     mov dword ptr [esp + 0x38], 0x11
// 0088ddbc  8d642400             lea esp, [esp]
// 0088ddc0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088ddc4  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 0088ddcb  8b5704               mov edx, dword ptr [edi + 4]
// 0088ddce  68ffffff00           push 0xffffff
// 0088ddd3  50                   push eax
// 0088ddd4  51                   push ecx
// 0088ddd5  52                   push edx
// 0088ddd6  ffd6                 call esi
// 0088ddd8  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088dddc  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 0088dde3  8b5704               mov edx, dword ptr [edi + 4]
// 0088dde6  68ffffff00           push 0xffffff
// 0088ddeb  50                   push eax
// 0088ddec  51                   push ecx
// 0088dded  52                   push edx
// 0088ddee  ffd6                 call esi
// 0088ddf0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0088ddf4  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 0088ddf8  8b5704               mov edx, dword ptr [edi + 4]
// 0088ddfb  68ffffff00           push 0xffffff
// 0088de00  50                   push eax
// 0088de01  51                   push ecx
// 0088de02  52                   push edx
// 0088de03  ffd6                 call esi
// 0088de05  b801000000           mov eax, 1
// 0088de0a  01442410             add dword ptr [esp + 0x10], eax
// 0088de0e  29442438             sub dword ptr [esp + 0x38], eax
// 0088de12  75ac                 jne 0x88ddc0
// 0088de14  8b442450             mov eax, dword ptr [esp + 0x50]
// 0088de18  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088de1b  68ffffff00           push 0xffffff
// 0088de20  55                   push ebp
// 0088de21  50                   push eax
// 0088de22  51                   push ecx
// 0088de23  ffd6                 call esi
// 0088de25  8b542440             mov edx, dword ptr [esp + 0x40]
// 0088de29  8b442450             mov eax, dword ptr [esp + 0x50]
// 0088de2d  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088de30  68ffffff00           push 0xffffff
// 0088de35  52                   push edx
// 0088de36  50                   push eax
// 0088de37  51                   push ecx
// 0088de38  ffd6                 call esi
// 0088de3a  896c2410             mov dword ptr [esp + 0x10], ebp
// 0088de3e  c744244811000000     mov dword ptr [esp + 0x48], 0x11
// 0088de46  eb08                 jmp 0x88de50
// 0088de48  8da42400000000       lea esp, [esp]
// 0088de4f  90                   nop 
// 0088de50  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088de54  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 0088de5b  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088de5e  68ffffff00           push 0xffffff
// 0088de63  52                   push edx
// 0088de64  50                   push eax
// 0088de65  51                   push ecx
// 0088de66  ffd6                 call esi
// 0088de68  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088de6c  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 0088de73  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088de76  68ffffff00           push 0xffffff
// 0088de7b  52                   push edx
// 0088de7c  50                   push eax
// 0088de7d  51                   push ecx
// 0088de7e  ffd6                 call esi
// 0088de80  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088de84  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 0088de8b  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088de8e  68ffffff00           push 0xffffff
// 0088de93  52                   push edx
// 0088de94  50                   push eax
// 0088de95  51                   push ecx
// 0088de96  ffd6                 call esi
// 0088de98  b801000000           mov eax, 1
// 0088de9d  01442410             add dword ptr [esp + 0x10], eax
// 0088dea1  29442448             sub dword ptr [esp + 0x48], eax
// 0088dea5  75a9                 jne 0x88de50
// 0088dea7  8b5704               mov edx, dword ptr [edi + 4]
// 0088deaa  68ffffff00           push 0xffffff
// 0088deaf  55                   push ebp
// 0088deb0  8bac2498000000       mov ebp, dword ptr [esp + 0x98]
// 0088deb7  55                   push ebp
// 0088deb8  52                   push edx
// 0088deb9  ffd6                 call esi
// 0088debb  8b442440             mov eax, dword ptr [esp + 0x40]
// 0088debf  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dec2  68ffffff00           push 0xffffff
// 0088dec7  50                   push eax
// 0088dec8  55                   push ebp
// 0088dec9  51                   push ecx
// 0088deca  ffd6                 call esi
// 0088decc  8b6c2454             mov ebp, dword ptr [esp + 0x54]
// 0088ded0  c744244005000000     mov dword ptr [esp + 0x40], 5
// 0088ded8  eb06                 jmp 0x88dee0
// 0088deda  8d9b00000000         lea ebx, [ebx]
// 0088dee0  8b542444             mov edx, dword ptr [esp + 0x44]
// 0088dee4  68ffffff00           push 0xffffff
// 0088dee9  52                   push edx
// 0088deea  8d45ea               lea eax, [ebp - 0x16]
// 0088deed  50                   push eax
// 0088deee  8b4704               mov eax, dword ptr [edi + 4]
// 0088def1  50                   push eax
// 0088def2  ffd6                 call esi
// 0088def4  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088def7  68ffffff00           push 0xffffff
// 0088defc  53                   push ebx
// 0088defd  8d45ec               lea eax, [ebp - 0x14]
// 0088df00  50                   push eax
// 0088df01  51                   push ecx
// 0088df02  ffd6                 call esi
// 0088df04  8b542424             mov edx, dword ptr [esp + 0x24]
// 0088df08  68ffffff00           push 0xffffff
// 0088df0d  52                   push edx
// 0088df0e  8d45ee               lea eax, [ebp - 0x12]
// 0088df11  50                   push eax
// 0088df12  8b4704               mov eax, dword ptr [edi + 4]
// 0088df15  50                   push eax
// 0088df16  ffd6                 call esi
// 0088df18  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088df1c  8b5704               mov edx, dword ptr [edi + 4]
// 0088df1f  68ffffff00           push 0xffffff
// 0088df24  51                   push ecx
// 0088df25  8d45f0               lea eax, [ebp - 0x10]
// 0088df28  50                   push eax
// 0088df29  52                   push edx
// 0088df2a  ffd6                 call esi
// 0088df2c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088df30  8b5704               mov edx, dword ptr [edi + 4]
// 0088df33  68ffffff00           push 0xffffff
// 0088df38  51                   push ecx
// 0088df39  8d45f2               lea eax, [ebp - 0xe]
// 0088df3c  50                   push eax
// 0088df3d  52                   push edx
// 0088df3e  ffd6                 call esi
// 0088df40  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0088df44  8b5704               mov edx, dword ptr [edi + 4]
// 0088df47  68ffffff00           push 0xffffff
// 0088df4c  51                   push ecx
// 0088df4d  8d45f4               lea eax, [ebp - 0xc]
// 0088df50  50                   push eax
// 0088df51  52                   push edx
// 0088df52  ffd6                 call esi
// 0088df54  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0088df58  8b5704               mov edx, dword ptr [edi + 4]
// 0088df5b  68ffffff00           push 0xffffff
// 0088df60  51                   push ecx
// 0088df61  8d45f8               lea eax, [ebp - 8]
// 0088df64  50                   push eax
// 0088df65  52                   push edx
// 0088df66  ffd6                 call esi
// 0088df68  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 0088df6c  8b5704               mov edx, dword ptr [edi + 4]
// 0088df6f  68ffffff00           push 0xffffff
// 0088df74  51                   push ecx
// 0088df75  8d45f6               lea eax, [ebp - 0xa]
// 0088df78  50                   push eax
// 0088df79  52                   push edx
// 0088df7a  ffd6                 call esi
// 0088df7c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088df80  8b5704               mov edx, dword ptr [edi + 4]
// 0088df83  68ffffff00           push 0xffffff
// 0088df88  51                   push ecx
// 0088df89  8d45fa               lea eax, [ebp - 6]
// 0088df8c  50                   push eax
// 0088df8d  52                   push edx
// 0088df8e  ffd6                 call esi
// 0088df90  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0088df94  8b5704               mov edx, dword ptr [edi + 4]
// 0088df97  68ffffff00           push 0xffffff
// 0088df9c  51                   push ecx
// 0088df9d  8d45fc               lea eax, [ebp - 4]
// 0088dfa0  50                   push eax
// 0088dfa1  52                   push edx
// 0088dfa2  ffd6                 call esi
// 0088dfa4  8d45fe               lea eax, [ebp - 2]
// 0088dfa7  68ffffff00           push 0xffffff
// 0088dfac  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0088dfb0  8b5704               mov edx, dword ptr [edi + 4]
// 0088dfb3  51                   push ecx
// 0088dfb4  50                   push eax
// 0088dfb5  52                   push edx
// 0088dfb6  ffd6                 call esi
// 0088dfb8  8b4704               mov eax, dword ptr [edi + 4]
// 0088dfbb  68ffffff00           push 0xffffff
// 0088dfc0  53                   push ebx
// 0088dfc1  55                   push ebp
// 0088dfc2  50                   push eax
// 0088dfc3  ffd6                 call esi
// 0088dfc5  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0088dfc9  8b5704               mov edx, dword ptr [edi + 4]
// 0088dfcc  68ffffff00           push 0xffffff
// 0088dfd1  51                   push ecx
// 0088dfd2  8d4502               lea eax, [ebp + 2]
// 0088dfd5  50                   push eax
// 0088dfd6  52                   push edx
// 0088dfd7  ffd6                 call esi
// 0088dfd9  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088dfdd  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088dfe0  68ffffff00           push 0xffffff
// 0088dfe5  50                   push eax
// 0088dfe6  8d4502               lea eax, [ebp + 2]
// 0088dfe9  50                   push eax
// 0088dfea  51                   push ecx
// 0088dfeb  ffd6                 call esi
// 0088dfed  8b542414             mov edx, dword ptr [esp + 0x14]
// 0088dff1  8b4704               mov eax, dword ptr [edi + 4]
// 0088dff4  68ffffff00           push 0xffffff
// 0088dff9  52                   push edx
// 0088dffa  55                   push ebp
// 0088dffb  50                   push eax
// 0088dffc  ffd6                 call esi
// 0088dffe  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0088e002  8b5704               mov edx, dword ptr [edi + 4]
// 0088e005  68ffffff00           push 0xffffff
// 0088e00a  51                   push ecx
// 0088e00b  8d45fe               lea eax, [ebp - 2]
// 0088e00e  50                   push eax
// 0088e00f  52                   push edx
// 0088e010  ffd6                 call esi
// 0088e012  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088e016  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e019  68ffffff00           push 0xffffff
// 0088e01e  50                   push eax
// 0088e01f  8d45fc               lea eax, [ebp - 4]
// 0088e022  50                   push eax
// 0088e023  51                   push ecx
// 0088e024  ffd6                 call esi
// 0088e026  8b542430             mov edx, dword ptr [esp + 0x30]
// 0088e02a  68ffffff00           push 0xffffff
// 0088e02f  52                   push edx
// 0088e030  8d45fa               lea eax, [ebp - 6]
// 0088e033  50                   push eax
// 0088e034  8b4704               mov eax, dword ptr [edi + 4]
// 0088e037  50                   push eax
// 0088e038  ffd6                 call esi
// 0088e03a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0088e03e  8b5704               mov edx, dword ptr [edi + 4]
// 0088e041  68ffffff00           push 0xffffff
// 0088e046  51                   push ecx
// 0088e047  8d45f6               lea eax, [ebp - 0xa]
// 0088e04a  50                   push eax
// 0088e04b  52                   push edx
// 0088e04c  ffd6                 call esi
// 0088e04e  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0088e052  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e055  68ffffff00           push 0xffffff
// 0088e05a  50                   push eax
// 0088e05b  8d45f8               lea eax, [ebp - 8]
// 0088e05e  50                   push eax
// 0088e05f  51                   push ecx
// 0088e060  ffd6                 call esi
// 0088e062  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 0088e066  68ffffff00           push 0xffffff
// 0088e06b  8d45f4               lea eax, [ebp - 0xc]
// 0088e06e  52                   push edx
// 0088e06f  50                   push eax
// 0088e070  8b4704               mov eax, dword ptr [edi + 4]
// 0088e073  50                   push eax
// 0088e074  ffd6                 call esi
// 0088e076  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0088e07a  8b5704               mov edx, dword ptr [edi + 4]
// 0088e07d  68ffffff00           push 0xffffff
// 0088e082  51                   push ecx
// 0088e083  8d45f2               lea eax, [ebp - 0xe]
// 0088e086  50                   push eax
// 0088e087  52                   push edx
// 0088e088  ffd6                 call esi
// 0088e08a  8b442418             mov eax, dword ptr [esp + 0x18]
// 0088e08e  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e091  68ffffff00           push 0xffffff
// 0088e096  50                   push eax
// 0088e097  8d45f0               lea eax, [ebp - 0x10]
// 0088e09a  50                   push eax
// 0088e09b  51                   push ecx
// 0088e09c  ffd6                 call esi
// 0088e09e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0088e0a2  68ffffff00           push 0xffffff
// 0088e0a7  52                   push edx
// 0088e0a8  8d45ee               lea eax, [ebp - 0x12]
// 0088e0ab  50                   push eax
// 0088e0ac  8b4704               mov eax, dword ptr [edi + 4]
// 0088e0af  50                   push eax
// 0088e0b0  ffd6                 call esi
// 0088e0b2  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088e0b6  8b5704               mov edx, dword ptr [edi + 4]
// 0088e0b9  68ffffff00           push 0xffffff
// 0088e0be  51                   push ecx
// 0088e0bf  8d45ec               lea eax, [ebp - 0x14]
// 0088e0c2  50                   push eax
// 0088e0c3  52                   push edx
// 0088e0c4  ffd6                 call esi
// 0088e0c6  8b442434             mov eax, dword ptr [esp + 0x34]
// 0088e0ca  8b4f04               mov ecx, dword ptr [edi + 4]
// 0088e0cd  68ffffff00           push 0xffffff
// 0088e0d2  50                   push eax
// 0088e0d3  8d45ea               lea eax, [ebp - 0x16]
// 0088e0d6  50                   push eax
// 0088e0d7  51                   push ecx
// 0088e0d8  ffd6                 call esi
// 0088e0da  45                   inc ebp
// 0088e0db  836c244001           sub dword ptr [esp + 0x40], 1
// 0088e0e0  0f85fafdffff         jne 0x88dee0
// 0088e0e6  5f                   pop edi
// 0088e0e7  5e                   pop esi
// 0088e0e8  5d                   pop ebp
// 0088e0e9  5b                   pop ebx
// 0088e0ea  81c4bc000000         add esp, 0xbc
// 0088e0f0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawLargeSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
