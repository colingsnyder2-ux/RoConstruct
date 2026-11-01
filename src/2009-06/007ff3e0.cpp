// from server: 100% by auto
// roc 2009-06 007ff3e0  unit: CXTColorHex  size: 2261 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ff3e0
//
// 007ff3e0  83ec40               sub esp, 0x40
// 007ff3e3  53                   push ebx
// 007ff3e4  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 007ff3e7  55                   push ebp
// 007ff3e8  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 007ff3eb  56                   push esi
// 007ff3ec  8b35d4e08900         mov esi, dword ptr [0x89e0d4]
// 007ff3f2  57                   push edi
// 007ff3f3  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 007ff3f7  83eb02               sub ebx, 2
// 007ff3fa  4d                   dec ebp
// 007ff3fb  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff403  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff407  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff40a  6a00                 push 0
// 007ff40c  03c5                 add eax, ebp
// 007ff40e  50                   push eax
// 007ff40f  53                   push ebx
// 007ff410  51                   push ecx
// 007ff411  ffd6                 call esi
// 007ff413  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff417  40                   inc eax
// 007ff418  83f80b               cmp eax, 0xb
// 007ff41b  89442410             mov dword ptr [esp + 0x10], eax
// 007ff41f  7ce2                 jl 0x7ff403
// 007ff421  8b5704               mov edx, dword ptr [edi + 4]
// 007ff424  6a00                 push 0
// 007ff426  8d450b               lea eax, [ebp + 0xb]
// 007ff429  8d4b01               lea ecx, [ebx + 1]
// 007ff42c  50                   push eax
// 007ff42d  51                   push ecx
// 007ff42e  52                   push edx
// 007ff42f  894c2434             mov dword ptr [esp + 0x34], ecx
// 007ff433  ffd6                 call esi
// 007ff435  6a00                 push 0
// 007ff437  8d450b               lea eax, [ebp + 0xb]
// 007ff43a  50                   push eax
// 007ff43b  8b4704               mov eax, dword ptr [edi + 4]
// 007ff43e  8d4b02               lea ecx, [ebx + 2]
// 007ff441  51                   push ecx
// 007ff442  50                   push eax
// 007ff443  ffd6                 call esi
// 007ff445  6a00                 push 0
// 007ff447  8d450c               lea eax, [ebp + 0xc]
// 007ff44a  50                   push eax
// 007ff44b  8d4b03               lea ecx, [ebx + 3]
// 007ff44e  51                   push ecx
// 007ff44f  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff452  51                   push ecx
// 007ff453  ffd6                 call esi
// 007ff455  8b5704               mov edx, dword ptr [edi + 4]
// 007ff458  6a00                 push 0
// 007ff45a  8d450c               lea eax, [ebp + 0xc]
// 007ff45d  8d4b04               lea ecx, [ebx + 4]
// 007ff460  50                   push eax
// 007ff461  51                   push ecx
// 007ff462  52                   push edx
// 007ff463  894c2430             mov dword ptr [esp + 0x30], ecx
// 007ff467  ffd6                 call esi
// 007ff469  6a00                 push 0
// 007ff46b  8d450d               lea eax, [ebp + 0xd]
// 007ff46e  50                   push eax
// 007ff46f  8b4704               mov eax, dword ptr [edi + 4]
// 007ff472  8d4b05               lea ecx, [ebx + 5]
// 007ff475  51                   push ecx
// 007ff476  50                   push eax
// 007ff477  894c242c             mov dword ptr [esp + 0x2c], ecx
// 007ff47b  ffd6                 call esi
// 007ff47d  6a00                 push 0
// 007ff47f  8d450d               lea eax, [ebp + 0xd]
// 007ff482  8d4b06               lea ecx, [ebx + 6]
// 007ff485  50                   push eax
// 007ff486  51                   push ecx
// 007ff487  894c2424             mov dword ptr [esp + 0x24], ecx
// 007ff48b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff48e  51                   push ecx
// 007ff48f  ffd6                 call esi
// 007ff491  8d5307               lea edx, [ebx + 7]
// 007ff494  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff49c  89542414             mov dword ptr [esp + 0x14], edx
// 007ff4a0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ff4a4  8b5704               mov edx, dword ptr [edi + 4]
// 007ff4a7  6a00                 push 0
// 007ff4a9  8d450e               lea eax, [ebp + 0xe]
// 007ff4ac  50                   push eax
// 007ff4ad  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ff4b1  03c1                 add eax, ecx
// 007ff4b3  50                   push eax
// 007ff4b4  52                   push edx
// 007ff4b5  ffd6                 call esi
// 007ff4b7  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff4bb  40                   inc eax
// 007ff4bc  83f805               cmp eax, 5
// 007ff4bf  89442410             mov dword ptr [esp + 0x10], eax
// 007ff4c3  7cdb                 jl 0x7ff4a0
// 007ff4c5  6a00                 push 0
// 007ff4c7  8d4d0d               lea ecx, [ebp + 0xd]
// 007ff4ca  51                   push ecx
// 007ff4cb  8d430c               lea eax, [ebx + 0xc]
// 007ff4ce  50                   push eax
// 007ff4cf  8b4704               mov eax, dword ptr [edi + 4]
// 007ff4d2  50                   push eax
// 007ff4d3  ffd6                 call esi
// 007ff4d5  6a00                 push 0
// 007ff4d7  8d4d0d               lea ecx, [ebp + 0xd]
// 007ff4da  51                   push ecx
// 007ff4db  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff4de  8d430d               lea eax, [ebx + 0xd]
// 007ff4e1  50                   push eax
// 007ff4e2  51                   push ecx
// 007ff4e3  ffd6                 call esi
// 007ff4e5  8b5704               mov edx, dword ptr [edi + 4]
// 007ff4e8  6a00                 push 0
// 007ff4ea  8d4d0c               lea ecx, [ebp + 0xc]
// 007ff4ed  51                   push ecx
// 007ff4ee  8d430e               lea eax, [ebx + 0xe]
// 007ff4f1  50                   push eax
// 007ff4f2  52                   push edx
// 007ff4f3  ffd6                 call esi
// 007ff4f5  6a00                 push 0
// 007ff4f7  8d4d0c               lea ecx, [ebp + 0xc]
// 007ff4fa  51                   push ecx
// 007ff4fb  8d430f               lea eax, [ebx + 0xf]
// 007ff4fe  50                   push eax
// 007ff4ff  8b4704               mov eax, dword ptr [edi + 4]
// 007ff502  50                   push eax
// 007ff503  ffd6                 call esi
// 007ff505  6a00                 push 0
// 007ff507  8d4d0b               lea ecx, [ebp + 0xb]
// 007ff50a  51                   push ecx
// 007ff50b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff50e  8d4310               lea eax, [ebx + 0x10]
// 007ff511  50                   push eax
// 007ff512  51                   push ecx
// 007ff513  ffd6                 call esi
// 007ff515  8b5704               mov edx, dword ptr [edi + 4]
// 007ff518  6a00                 push 0
// 007ff51a  8d4d0b               lea ecx, [ebp + 0xb]
// 007ff51d  51                   push ecx
// 007ff51e  8d4311               lea eax, [ebx + 0x11]
// 007ff521  50                   push eax
// 007ff522  52                   push edx
// 007ff523  ffd6                 call esi
// 007ff525  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff52d  8d4900               lea ecx, [ecx]
// 007ff530  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff534  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff537  6a00                 push 0
// 007ff539  03c5                 add eax, ebp
// 007ff53b  50                   push eax
// 007ff53c  8d4312               lea eax, [ebx + 0x12]
// 007ff53f  50                   push eax
// 007ff540  51                   push ecx
// 007ff541  ffd6                 call esi
// 007ff543  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff547  40                   inc eax
// 007ff548  83f80b               cmp eax, 0xb
// 007ff54b  89442410             mov dword ptr [esp + 0x10], eax
// 007ff54f  7cdf                 jl 0x7ff530
// 007ff551  8b5704               mov edx, dword ptr [edi + 4]
// 007ff554  6a00                 push 0
// 007ff556  8d45ff               lea eax, [ebp - 1]
// 007ff559  50                   push eax
// 007ff55a  8944245c             mov dword ptr [esp + 0x5c], eax
// 007ff55e  8d4310               lea eax, [ebx + 0x10]
// 007ff561  50                   push eax
// 007ff562  52                   push edx
// 007ff563  ffd6                 call esi
// 007ff565  8b442454             mov eax, dword ptr [esp + 0x54]
// 007ff569  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff56c  6a00                 push 0
// 007ff56e  50                   push eax
// 007ff56f  8d4311               lea eax, [ebx + 0x11]
// 007ff572  50                   push eax
// 007ff573  51                   push ecx
// 007ff574  ffd6                 call esi
// 007ff576  8b5704               mov edx, dword ptr [edi + 4]
// 007ff579  6a00                 push 0
// 007ff57b  8d45fe               lea eax, [ebp - 2]
// 007ff57e  50                   push eax
// 007ff57f  8d430e               lea eax, [ebx + 0xe]
// 007ff582  50                   push eax
// 007ff583  52                   push edx
// 007ff584  ffd6                 call esi
// 007ff586  6a00                 push 0
// 007ff588  8d45fe               lea eax, [ebp - 2]
// 007ff58b  50                   push eax
// 007ff58c  8d430f               lea eax, [ebx + 0xf]
// 007ff58f  50                   push eax
// 007ff590  8b4704               mov eax, dword ptr [edi + 4]
// 007ff593  50                   push eax
// 007ff594  ffd6                 call esi
// 007ff596  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff599  6a00                 push 0
// 007ff59b  8d45fd               lea eax, [ebp - 3]
// 007ff59e  50                   push eax
// 007ff59f  8d430c               lea eax, [ebx + 0xc]
// 007ff5a2  50                   push eax
// 007ff5a3  51                   push ecx
// 007ff5a4  ffd6                 call esi
// 007ff5a6  8b5704               mov edx, dword ptr [edi + 4]
// 007ff5a9  6a00                 push 0
// 007ff5ab  8d45fd               lea eax, [ebp - 3]
// 007ff5ae  50                   push eax
// 007ff5af  8d430d               lea eax, [ebx + 0xd]
// 007ff5b2  50                   push eax
// 007ff5b3  52                   push edx
// 007ff5b4  ffd6                 call esi
// 007ff5b6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff5be  8bff                 mov edi, edi
// 007ff5c0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ff5c4  8b5704               mov edx, dword ptr [edi + 4]
// 007ff5c7  6a00                 push 0
// 007ff5c9  8d45fc               lea eax, [ebp - 4]
// 007ff5cc  50                   push eax
// 007ff5cd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ff5d1  03c1                 add eax, ecx
// 007ff5d3  50                   push eax
// 007ff5d4  52                   push edx
// 007ff5d5  ffd6                 call esi
// 007ff5d7  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff5db  40                   inc eax
// 007ff5dc  83f805               cmp eax, 5
// 007ff5df  89442410             mov dword ptr [esp + 0x10], eax
// 007ff5e3  7cdb                 jl 0x7ff5c0
// 007ff5e5  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff5e8  6a00                 push 0
// 007ff5ea  8d45fd               lea eax, [ebp - 3]
// 007ff5ed  50                   push eax
// 007ff5ee  8b442424             mov eax, dword ptr [esp + 0x24]
// 007ff5f2  50                   push eax
// 007ff5f3  51                   push ecx
// 007ff5f4  ffd6                 call esi
// 007ff5f6  8b542418             mov edx, dword ptr [esp + 0x18]
// 007ff5fa  6a00                 push 0
// 007ff5fc  8d45fd               lea eax, [ebp - 3]
// 007ff5ff  50                   push eax
// 007ff600  8b4704               mov eax, dword ptr [edi + 4]
// 007ff603  52                   push edx
// 007ff604  50                   push eax
// 007ff605  ffd6                 call esi
// 007ff607  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff60a  6a00                 push 0
// 007ff60c  8d45fe               lea eax, [ebp - 2]
// 007ff60f  50                   push eax
// 007ff610  8d4303               lea eax, [ebx + 3]
// 007ff613  50                   push eax
// 007ff614  51                   push ecx
// 007ff615  ffd6                 call esi
// 007ff617  8b542420             mov edx, dword ptr [esp + 0x20]
// 007ff61b  6a00                 push 0
// 007ff61d  8d45fe               lea eax, [ebp - 2]
// 007ff620  50                   push eax
// 007ff621  8b4704               mov eax, dword ptr [edi + 4]
// 007ff624  52                   push edx
// 007ff625  50                   push eax
// 007ff626  ffd6                 call esi
// 007ff628  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007ff62c  8b542424             mov edx, dword ptr [esp + 0x24]
// 007ff630  8b4704               mov eax, dword ptr [edi + 4]
// 007ff633  6a00                 push 0
// 007ff635  51                   push ecx
// 007ff636  52                   push edx
// 007ff637  50                   push eax
// 007ff638  ffd6                 call esi
// 007ff63a  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007ff63e  8b5704               mov edx, dword ptr [edi + 4]
// 007ff641  6a00                 push 0
// 007ff643  51                   push ecx
// 007ff644  8d4302               lea eax, [ebx + 2]
// 007ff647  50                   push eax
// 007ff648  52                   push edx
// 007ff649  ffd6                 call esi
// 007ff64b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff653  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff657  8b5704               mov edx, dword ptr [edi + 4]
// 007ff65a  6a00                 push 0
// 007ff65c  8d4c2802             lea ecx, [eax + ebp + 2]
// 007ff660  51                   push ecx
// 007ff661  8d4303               lea eax, [ebx + 3]
// 007ff664  50                   push eax
// 007ff665  52                   push edx
// 007ff666  ffd6                 call esi
// 007ff668  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff66c  40                   inc eax
// 007ff66d  83f807               cmp eax, 7
// 007ff670  89442410             mov dword ptr [esp + 0x10], eax
// 007ff674  7cdd                 jl 0x7ff653
// 007ff676  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff679  6a00                 push 0
// 007ff67b  8d4509               lea eax, [ebp + 9]
// 007ff67e  50                   push eax
// 007ff67f  8b442428             mov eax, dword ptr [esp + 0x28]
// 007ff683  50                   push eax
// 007ff684  51                   push ecx
// 007ff685  ffd6                 call esi
// 007ff687  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007ff68b  6a00                 push 0
// 007ff68d  8d4509               lea eax, [ebp + 9]
// 007ff690  50                   push eax
// 007ff691  8b4704               mov eax, dword ptr [edi + 4]
// 007ff694  52                   push edx
// 007ff695  50                   push eax
// 007ff696  ffd6                 call esi
// 007ff698  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ff69c  8b5704               mov edx, dword ptr [edi + 4]
// 007ff69f  6a00                 push 0
// 007ff6a1  8d450a               lea eax, [ebp + 0xa]
// 007ff6a4  50                   push eax
// 007ff6a5  51                   push ecx
// 007ff6a6  52                   push edx
// 007ff6a7  ffd6                 call esi
// 007ff6a9  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff6ac  6a00                 push 0
// 007ff6ae  8d450a               lea eax, [ebp + 0xa]
// 007ff6b1  50                   push eax
// 007ff6b2  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ff6b6  50                   push eax
// 007ff6b7  51                   push ecx
// 007ff6b8  ffd6                 call esi
// 007ff6ba  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff6c2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff6c6  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff6c9  6a00                 push 0
// 007ff6cb  8d450b               lea eax, [ebp + 0xb]
// 007ff6ce  50                   push eax
// 007ff6cf  8d441308             lea eax, [ebx + edx + 8]
// 007ff6d3  50                   push eax
// 007ff6d4  51                   push ecx
// 007ff6d5  ffd6                 call esi
// 007ff6d7  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff6db  40                   inc eax
// 007ff6dc  83f803               cmp eax, 3
// 007ff6df  89442410             mov dword ptr [esp + 0x10], eax
// 007ff6e3  7cdd                 jl 0x7ff6c2
// 007ff6e5  8b5704               mov edx, dword ptr [edi + 4]
// 007ff6e8  6a00                 push 0
// 007ff6ea  8d4d0a               lea ecx, [ebp + 0xa]
// 007ff6ed  51                   push ecx
// 007ff6ee  8d430b               lea eax, [ebx + 0xb]
// 007ff6f1  50                   push eax
// 007ff6f2  52                   push edx
// 007ff6f3  ffd6                 call esi
// 007ff6f5  6a00                 push 0
// 007ff6f7  8d450a               lea eax, [ebp + 0xa]
// 007ff6fa  50                   push eax
// 007ff6fb  8d430c               lea eax, [ebx + 0xc]
// 007ff6fe  50                   push eax
// 007ff6ff  8b4704               mov eax, dword ptr [edi + 4]
// 007ff702  50                   push eax
// 007ff703  ffd6                 call esi
// 007ff705  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff708  6a00                 push 0
// 007ff70a  8d4509               lea eax, [ebp + 9]
// 007ff70d  50                   push eax
// 007ff70e  8d430d               lea eax, [ebx + 0xd]
// 007ff711  50                   push eax
// 007ff712  51                   push ecx
// 007ff713  ffd6                 call esi
// 007ff715  8b5704               mov edx, dword ptr [edi + 4]
// 007ff718  6a00                 push 0
// 007ff71a  8d4509               lea eax, [ebp + 9]
// 007ff71d  50                   push eax
// 007ff71e  8d430e               lea eax, [ebx + 0xe]
// 007ff721  50                   push eax
// 007ff722  52                   push edx
// 007ff723  ffd6                 call esi
// 007ff725  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff72d  8d4900               lea ecx, [ecx]
// 007ff730  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff734  8b5704               mov edx, dword ptr [edi + 4]
// 007ff737  6a00                 push 0
// 007ff739  8d4c2802             lea ecx, [eax + ebp + 2]
// 007ff73d  51                   push ecx
// 007ff73e  8d430f               lea eax, [ebx + 0xf]
// 007ff741  50                   push eax
// 007ff742  52                   push edx
// 007ff743  ffd6                 call esi
// 007ff745  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff749  40                   inc eax
// 007ff74a  83f807               cmp eax, 7
// 007ff74d  89442410             mov dword ptr [esp + 0x10], eax
// 007ff751  7cdd                 jl 0x7ff730
// 007ff753  6a00                 push 0
// 007ff755  8d4501               lea eax, [ebp + 1]
// 007ff758  50                   push eax
// 007ff759  8d430d               lea eax, [ebx + 0xd]
// 007ff75c  50                   push eax
// 007ff75d  8b4704               mov eax, dword ptr [edi + 4]
// 007ff760  50                   push eax
// 007ff761  ffd6                 call esi
// 007ff763  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff766  6a00                 push 0
// 007ff768  8d4501               lea eax, [ebp + 1]
// 007ff76b  50                   push eax
// 007ff76c  8d430e               lea eax, [ebx + 0xe]
// 007ff76f  50                   push eax
// 007ff770  51                   push ecx
// 007ff771  ffd6                 call esi
// 007ff773  8b5704               mov edx, dword ptr [edi + 4]
// 007ff776  6a00                 push 0
// 007ff778  55                   push ebp
// 007ff779  8d430b               lea eax, [ebx + 0xb]
// 007ff77c  50                   push eax
// 007ff77d  52                   push edx
// 007ff77e  ffd6                 call esi
// 007ff780  6a00                 push 0
// 007ff782  55                   push ebp
// 007ff783  8d430c               lea eax, [ebx + 0xc]
// 007ff786  50                   push eax
// 007ff787  8b4704               mov eax, dword ptr [edi + 4]
// 007ff78a  50                   push eax
// 007ff78b  ffd6                 call esi
// 007ff78d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff795  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007ff799  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff79d  6a00                 push 0
// 007ff79f  51                   push ecx
// 007ff7a0  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff7a3  8d441308             lea eax, [ebx + edx + 8]
// 007ff7a7  50                   push eax
// 007ff7a8  51                   push ecx
// 007ff7a9  ffd6                 call esi
// 007ff7ab  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff7af  40                   inc eax
// 007ff7b0  83f803               cmp eax, 3
// 007ff7b3  89442410             mov dword ptr [esp + 0x10], eax
// 007ff7b7  7cdc                 jl 0x7ff795
// 007ff7b9  8b542418             mov edx, dword ptr [esp + 0x18]
// 007ff7bd  8b4704               mov eax, dword ptr [edi + 4]
// 007ff7c0  6a00                 push 0
// 007ff7c2  55                   push ebp
// 007ff7c3  52                   push edx
// 007ff7c4  50                   push eax
// 007ff7c5  ffd6                 call esi
// 007ff7c7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ff7cb  8b5704               mov edx, dword ptr [edi + 4]
// 007ff7ce  6a00                 push 0
// 007ff7d0  55                   push ebp
// 007ff7d1  51                   push ecx
// 007ff7d2  52                   push edx
// 007ff7d3  ffd6                 call esi
// 007ff7d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ff7d9  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff7dc  6a00                 push 0
// 007ff7de  8d5d01               lea ebx, [ebp + 1]
// 007ff7e1  53                   push ebx
// 007ff7e2  50                   push eax
// 007ff7e3  51                   push ecx
// 007ff7e4  ffd6                 call esi
// 007ff7e6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007ff7ea  8b4704               mov eax, dword ptr [edi + 4]
// 007ff7ed  6a00                 push 0
// 007ff7ef  53                   push ebx
// 007ff7f0  52                   push edx
// 007ff7f1  50                   push eax
// 007ff7f2  ffd6                 call esi
// 007ff7f4  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 007ff7f8  896c2420             mov dword ptr [esp + 0x20], ebp
// 007ff7fc  c74424240b000000     mov dword ptr [esp + 0x24], 0xb
// 007ff804  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ff808  8b5704               mov edx, dword ptr [edi + 4]
// 007ff80b  68ffffff00           push 0xffffff
// 007ff810  51                   push ecx
// 007ff811  53                   push ebx
// 007ff812  52                   push edx
// 007ff813  ffd6                 call esi
// 007ff815  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ff819  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff81c  68ffffff00           push 0xffffff
// 007ff821  50                   push eax
// 007ff822  8d4301               lea eax, [ebx + 1]
// 007ff825  50                   push eax
// 007ff826  51                   push ecx
// 007ff827  ffd6                 call esi
// 007ff829  b801000000           mov eax, 1
// 007ff82e  01442420             add dword ptr [esp + 0x20], eax
// 007ff832  29442424             sub dword ptr [esp + 0x24], eax
// 007ff836  75cc                 jne 0x7ff804
// 007ff838  8d5302               lea edx, [ebx + 2]
// 007ff83b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff843  89542444             mov dword ptr [esp + 0x44], edx
// 007ff847  eb07                 jmp 0x7ff850
// 007ff849  8da42400000000       lea esp, [esp]
// 007ff850  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff854  8b542444             mov edx, dword ptr [esp + 0x44]
// 007ff858  68ffffff00           push 0xffffff
// 007ff85d  8d4c2809             lea ecx, [eax + ebp + 9]
// 007ff861  8b4704               mov eax, dword ptr [edi + 4]
// 007ff864  51                   push ecx
// 007ff865  52                   push edx
// 007ff866  50                   push eax
// 007ff867  ffd6                 call esi
// 007ff869  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff86d  40                   inc eax
// 007ff86e  83f803               cmp eax, 3
// 007ff871  89442410             mov dword ptr [esp + 0x10], eax
// 007ff875  7cd9                 jl 0x7ff850
// 007ff877  68ffffff00           push 0xffffff
// 007ff87c  8d4d0a               lea ecx, [ebp + 0xa]
// 007ff87f  51                   push ecx
// 007ff880  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff883  8d4303               lea eax, [ebx + 3]
// 007ff886  50                   push eax
// 007ff887  51                   push ecx
// 007ff888  89442450             mov dword ptr [esp + 0x50], eax
// 007ff88c  ffd6                 call esi
// 007ff88e  8b542440             mov edx, dword ptr [esp + 0x40]
// 007ff892  68ffffff00           push 0xffffff
// 007ff897  8d450b               lea eax, [ebp + 0xb]
// 007ff89a  50                   push eax
// 007ff89b  8b4704               mov eax, dword ptr [edi + 4]
// 007ff89e  52                   push edx
// 007ff89f  50                   push eax
// 007ff8a0  ffd6                 call esi
// 007ff8a2  8d4b04               lea ecx, [ebx + 4]
// 007ff8a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff8ad  894c2420             mov dword ptr [esp + 0x20], ecx
// 007ff8b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff8b5  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ff8b9  68ffffff00           push 0xffffff
// 007ff8be  8d442a0a             lea eax, [edx + ebp + 0xa]
// 007ff8c2  8b5704               mov edx, dword ptr [edi + 4]
// 007ff8c5  50                   push eax
// 007ff8c6  51                   push ecx
// 007ff8c7  52                   push edx
// 007ff8c8  ffd6                 call esi
// 007ff8ca  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff8ce  40                   inc eax
// 007ff8cf  83f803               cmp eax, 3
// 007ff8d2  89442410             mov dword ptr [esp + 0x10], eax
// 007ff8d6  7cd9                 jl 0x7ff8b1
// 007ff8d8  68ffffff00           push 0xffffff
// 007ff8dd  8d4d0b               lea ecx, [ebp + 0xb]
// 007ff8e0  8d4305               lea eax, [ebx + 5]
// 007ff8e3  51                   push ecx
// 007ff8e4  50                   push eax
// 007ff8e5  89442428             mov dword ptr [esp + 0x28], eax
// 007ff8e9  8b4704               mov eax, dword ptr [edi + 4]
// 007ff8ec  50                   push eax
// 007ff8ed  ffd6                 call esi
// 007ff8ef  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007ff8f3  8b5704               mov edx, dword ptr [edi + 4]
// 007ff8f6  68ffffff00           push 0xffffff
// 007ff8fb  8d450c               lea eax, [ebp + 0xc]
// 007ff8fe  50                   push eax
// 007ff8ff  51                   push ecx
// 007ff900  52                   push edx
// 007ff901  ffd6                 call esi
// 007ff903  8d4306               lea eax, [ebx + 6]
// 007ff906  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff90e  89442418             mov dword ptr [esp + 0x18], eax
// 007ff912  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ff916  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ff91a  68ffffff00           push 0xffffff
// 007ff91f  8d54290b             lea edx, [ecx + ebp + 0xb]
// 007ff923  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff926  52                   push edx
// 007ff927  50                   push eax
// 007ff928  51                   push ecx
// 007ff929  ffd6                 call esi
// 007ff92b  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff92f  40                   inc eax
// 007ff930  83f803               cmp eax, 3
// 007ff933  89442410             mov dword ptr [esp + 0x10], eax
// 007ff937  7cd9                 jl 0x7ff912
// 007ff939  8b5704               mov edx, dword ptr [edi + 4]
// 007ff93c  68ffffff00           push 0xffffff
// 007ff941  8d4d0c               lea ecx, [ebp + 0xc]
// 007ff944  8d4307               lea eax, [ebx + 7]
// 007ff947  51                   push ecx
// 007ff948  50                   push eax
// 007ff949  52                   push edx
// 007ff94a  89442424             mov dword ptr [esp + 0x24], eax
// 007ff94e  ffd6                 call esi
// 007ff950  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff953  68ffffff00           push 0xffffff
// 007ff958  8d450d               lea eax, [ebp + 0xd]
// 007ff95b  50                   push eax
// 007ff95c  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ff960  50                   push eax
// 007ff961  51                   push ecx
// 007ff962  ffd6                 call esi
// 007ff964  8b5704               mov edx, dword ptr [edi + 4]
// 007ff967  68ffffff00           push 0xffffff
// 007ff96c  8d4d0c               lea ecx, [ebp + 0xc]
// 007ff96f  8d4308               lea eax, [ebx + 8]
// 007ff972  51                   push ecx
// 007ff973  50                   push eax
// 007ff974  52                   push edx
// 007ff975  89442434             mov dword ptr [esp + 0x34], eax
// 007ff979  ffd6                 call esi
// 007ff97b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff97e  68ffffff00           push 0xffffff
// 007ff983  8d450d               lea eax, [ebp + 0xd]
// 007ff986  50                   push eax
// 007ff987  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007ff98b  50                   push eax
// 007ff98c  51                   push ecx
// 007ff98d  ffd6                 call esi
// 007ff98f  8b5704               mov edx, dword ptr [edi + 4]
// 007ff992  68ffffff00           push 0xffffff
// 007ff997  8d4d0c               lea ecx, [ebp + 0xc]
// 007ff99a  8d4309               lea eax, [ebx + 9]
// 007ff99d  51                   push ecx
// 007ff99e  50                   push eax
// 007ff99f  52                   push edx
// 007ff9a0  8944244c             mov dword ptr [esp + 0x4c], eax
// 007ff9a4  ffd6                 call esi
// 007ff9a6  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff9a9  68ffffff00           push 0xffffff
// 007ff9ae  8d450d               lea eax, [ebp + 0xd]
// 007ff9b1  50                   push eax
// 007ff9b2  8b442444             mov eax, dword ptr [esp + 0x44]
// 007ff9b6  50                   push eax
// 007ff9b7  51                   push ecx
// 007ff9b8  ffd6                 call esi
// 007ff9ba  8d530a               lea edx, [ebx + 0xa]
// 007ff9bd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ff9c5  89542438             mov dword ptr [esp + 0x38], edx
// 007ff9c9  8da42400000000       lea esp, [esp]
// 007ff9d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff9d4  8b542438             mov edx, dword ptr [esp + 0x38]
// 007ff9d8  68ffffff00           push 0xffffff
// 007ff9dd  8d4c280b             lea ecx, [eax + ebp + 0xb]
// 007ff9e1  8b4704               mov eax, dword ptr [edi + 4]
// 007ff9e4  51                   push ecx
// 007ff9e5  52                   push edx
// 007ff9e6  50                   push eax
// 007ff9e7  ffd6                 call esi
// 007ff9e9  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff9ed  40                   inc eax
// 007ff9ee  83f803               cmp eax, 3
// 007ff9f1  89442410             mov dword ptr [esp + 0x10], eax
// 007ff9f5  7cd9                 jl 0x7ff9d0
// 007ff9f7  68ffffff00           push 0xffffff
// 007ff9fc  8d4d0b               lea ecx, [ebp + 0xb]
// 007ff9ff  51                   push ecx
// 007ffa00  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffa03  8d430b               lea eax, [ebx + 0xb]
// 007ffa06  50                   push eax
// 007ffa07  51                   push ecx
// 007ffa08  89442444             mov dword ptr [esp + 0x44], eax
// 007ffa0c  ffd6                 call esi
// 007ffa0e  8b542434             mov edx, dword ptr [esp + 0x34]
// 007ffa12  68ffffff00           push 0xffffff
// 007ffa17  8d450c               lea eax, [ebp + 0xc]
// 007ffa1a  50                   push eax
// 007ffa1b  8b4704               mov eax, dword ptr [edi + 4]
// 007ffa1e  52                   push edx
// 007ffa1f  50                   push eax
// 007ffa20  ffd6                 call esi
// 007ffa22  8d4b0c               lea ecx, [ebx + 0xc]
// 007ffa25  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ffa2d  894c2430             mov dword ptr [esp + 0x30], ecx
// 007ffa31  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ffa35  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007ffa39  68ffffff00           push 0xffffff
// 007ffa3e  8d442a0a             lea eax, [edx + ebp + 0xa]
// 007ffa42  8b5704               mov edx, dword ptr [edi + 4]
// 007ffa45  50                   push eax
// 007ffa46  51                   push ecx
// 007ffa47  52                   push edx
// 007ffa48  ffd6                 call esi
// 007ffa4a  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ffa4e  40                   inc eax
// 007ffa4f  83f803               cmp eax, 3
// 007ffa52  89442410             mov dword ptr [esp + 0x10], eax
// 007ffa56  7cd9                 jl 0x7ffa31
// 007ffa58  68ffffff00           push 0xffffff
// 007ffa5d  8d4d0a               lea ecx, [ebp + 0xa]
// 007ffa60  8d430d               lea eax, [ebx + 0xd]
// 007ffa63  51                   push ecx
// 007ffa64  50                   push eax
// 007ffa65  89442438             mov dword ptr [esp + 0x38], eax
// 007ffa69  8b4704               mov eax, dword ptr [edi + 4]
// 007ffa6c  50                   push eax
// 007ffa6d  ffd6                 call esi
// 007ffa6f  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007ffa73  8b5704               mov edx, dword ptr [edi + 4]
// 007ffa76  68ffffff00           push 0xffffff
// 007ffa7b  8d450b               lea eax, [ebp + 0xb]
// 007ffa7e  50                   push eax
// 007ffa7f  51                   push ecx
// 007ffa80  52                   push edx
// 007ffa81  ffd6                 call esi
// 007ffa83  8d430e               lea eax, [ebx + 0xe]
// 007ffa86  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007ffa8e  89442428             mov dword ptr [esp + 0x28], eax
// 007ffa92  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ffa96  8b442428             mov eax, dword ptr [esp + 0x28]
// 007ffa9a  68ffffff00           push 0xffffff
// 007ffa9f  8d542909             lea edx, [ecx + ebp + 9]
// 007ffaa3  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffaa6  52                   push edx
// 007ffaa7  50                   push eax
// 007ffaa8  51                   push ecx
// 007ffaa9  ffd6                 call esi
// 007ffaab  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ffaaf  40                   inc eax
// 007ffab0  83f803               cmp eax, 3
// 007ffab3  89442410             mov dword ptr [esp + 0x10], eax
// 007ffab7  7cd9                 jl 0x7ffa92
// 007ffab9  8d530f               lea edx, [ebx + 0xf]
// 007ffabc  83c310               add ebx, 0x10
// 007ffabf  895c244c             mov dword ptr [esp + 0x4c], ebx
// 007ffac3  89542448             mov dword ptr [esp + 0x48], edx
// 007ffac7  8bdd                 mov ebx, ebp
// 007ffac9  c74424100b000000     mov dword ptr [esp + 0x10], 0xb
// 007ffad1  8b442448             mov eax, dword ptr [esp + 0x48]
// 007ffad5  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffad8  68ffffff00           push 0xffffff
// 007ffadd  53                   push ebx
// 007ffade  50                   push eax
// 007ffadf  51                   push ecx
// 007ffae0  ffd6                 call esi
// 007ffae2  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 007ffae6  8b4704               mov eax, dword ptr [edi + 4]
// 007ffae9  68ffffff00           push 0xffffff
// 007ffaee  53                   push ebx
// 007ffaef  52                   push edx
// 007ffaf0  50                   push eax
// 007ffaf1  ffd6                 call esi
// 007ffaf3  43                   inc ebx
// 007ffaf4  836c241001           sub dword ptr [esp + 0x10], 1
// 007ffaf9  75d6                 jne 0x7ffad1
// 007ffafb  33db                 xor ebx, ebx
// 007ffafd  8d4900               lea ecx, [ecx]
// 007ffb00  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007ffb04  8b542428             mov edx, dword ptr [esp + 0x28]
// 007ffb08  8b4704               mov eax, dword ptr [edi + 4]
// 007ffb0b  68ffffff00           push 0xffffff
// 007ffb10  03cb                 add ecx, ebx
// 007ffb12  51                   push ecx
// 007ffb13  52                   push edx
// 007ffb14  50                   push eax
// 007ffb15  ffd6                 call esi
// 007ffb17  43                   inc ebx
// 007ffb18  83fb03               cmp ebx, 3
// 007ffb1b  7ce3                 jl 0x7ffb00
// 007ffb1d  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 007ffb21  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffb24  68ffffff00           push 0xffffff
// 007ffb29  55                   push ebp
// 007ffb2a  53                   push ebx
// 007ffb2b  51                   push ecx
// 007ffb2c  ffd6                 call esi
// 007ffb2e  8b542454             mov edx, dword ptr [esp + 0x54]
// 007ffb32  8b4704               mov eax, dword ptr [edi + 4]
// 007ffb35  68ffffff00           push 0xffffff
// 007ffb3a  52                   push edx
// 007ffb3b  53                   push ebx
// 007ffb3c  50                   push eax
// 007ffb3d  ffd6                 call esi
// 007ffb3f  33db                 xor ebx, ebx
// 007ffb41  8b542430             mov edx, dword ptr [esp + 0x30]
// 007ffb45  8b4704               mov eax, dword ptr [edi + 4]
// 007ffb48  68ffffff00           push 0xffffff
// 007ffb4d  8d4c2bfe             lea ecx, [ebx + ebp - 2]
// 007ffb51  51                   push ecx
// 007ffb52  52                   push edx
// 007ffb53  50                   push eax
// 007ffb54  ffd6                 call esi
// 007ffb56  43                   inc ebx
// 007ffb57  83fb03               cmp ebx, 3
// 007ffb5a  7ce5                 jl 0x7ffb41
// 007ffb5c  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007ffb60  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 007ffb64  8b5704               mov edx, dword ptr [edi + 4]
// 007ffb67  68ffffff00           push 0xffffff
// 007ffb6c  51                   push ecx
// 007ffb6d  53                   push ebx
// 007ffb6e  52                   push edx
// 007ffb6f  ffd6                 call esi
// 007ffb71  68ffffff00           push 0xffffff
// 007ffb76  8d45fe               lea eax, [ebp - 2]
// 007ffb79  50                   push eax
// 007ffb7a  8b4704               mov eax, dword ptr [edi + 4]
// 007ffb7d  53                   push ebx
// 007ffb7e  50                   push eax
// 007ffb7f  ffd6                 call esi
// 007ffb81  33db                 xor ebx, ebx
// 007ffb83  8b542438             mov edx, dword ptr [esp + 0x38]
// 007ffb87  8b4704               mov eax, dword ptr [edi + 4]
// 007ffb8a  68ffffff00           push 0xffffff
// 007ffb8f  8d4c2bfd             lea ecx, [ebx + ebp - 3]
// 007ffb93  51                   push ecx
// 007ffb94  52                   push edx
// 007ffb95  50                   push eax
// 007ffb96  ffd6                 call esi
// 007ffb98  43                   inc ebx
// 007ffb99  83fb03               cmp ebx, 3
// 007ffb9c  7ce5                 jl 0x7ffb83
// 007ffb9e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ffba2  8b5704               mov edx, dword ptr [edi + 4]
// 007ffba5  68ffffff00           push 0xffffff
// 007ffbaa  8d5dfe               lea ebx, [ebp - 2]
// 007ffbad  53                   push ebx
// 007ffbae  51                   push ecx
// 007ffbaf  52                   push edx
// 007ffbb0  ffd6                 call esi
// 007ffbb2  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffbb5  68ffffff00           push 0xffffff
// 007ffbba  8d45fd               lea eax, [ebp - 3]
// 007ffbbd  50                   push eax
// 007ffbbe  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ffbc2  50                   push eax
// 007ffbc3  51                   push ecx
// 007ffbc4  ffd6                 call esi
// 007ffbc6  8b542424             mov edx, dword ptr [esp + 0x24]
// 007ffbca  8b4704               mov eax, dword ptr [edi + 4]
// 007ffbcd  68ffffff00           push 0xffffff
// 007ffbd2  53                   push ebx
// 007ffbd3  52                   push edx
// 007ffbd4  50                   push eax
// 007ffbd5  ffd6                 call esi
// 007ffbd7  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ffbdb  8b5704               mov edx, dword ptr [edi + 4]
// 007ffbde  68ffffff00           push 0xffffff
// 007ffbe3  8d45fd               lea eax, [ebp - 3]
// 007ffbe6  50                   push eax
// 007ffbe7  51                   push ecx
// 007ffbe8  52                   push edx
// 007ffbe9  ffd6                 call esi
// 007ffbeb  8b4704               mov eax, dword ptr [edi + 4]
// 007ffbee  68ffffff00           push 0xffffff
// 007ffbf3  53                   push ebx
// 007ffbf4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 007ffbf8  53                   push ebx
// 007ffbf9  50                   push eax
// 007ffbfa  ffd6                 call esi
// 007ffbfc  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffbff  68ffffff00           push 0xffffff
// 007ffc04  8d45fd               lea eax, [ebp - 3]
// 007ffc07  50                   push eax
// 007ffc08  53                   push ebx
// 007ffc09  51                   push ecx
// 007ffc0a  ffd6                 call esi
// 007ffc0c  33db                 xor ebx, ebx
// 007ffc0e  8bff                 mov edi, edi
// 007ffc10  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ffc14  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffc17  68ffffff00           push 0xffffff
// 007ffc1c  8d542bfd             lea edx, [ebx + ebp - 3]
// 007ffc20  52                   push edx
// 007ffc21  50                   push eax
// 007ffc22  51                   push ecx
// 007ffc23  ffd6                 call esi
// 007ffc25  43                   inc ebx
// 007ffc26  83fb03               cmp ebx, 3
// 007ffc29  7ce5                 jl 0x7ffc10
// 007ffc2b  8b542454             mov edx, dword ptr [esp + 0x54]
// 007ffc2f  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007ffc33  8b4704               mov eax, dword ptr [edi + 4]
// 007ffc36  68ffffff00           push 0xffffff
// 007ffc3b  52                   push edx
// 007ffc3c  53                   push ebx
// 007ffc3d  50                   push eax
// 007ffc3e  ffd6                 call esi
// 007ffc40  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffc43  68ffffff00           push 0xffffff
// 007ffc48  8d45fe               lea eax, [ebp - 2]
// 007ffc4b  50                   push eax
// 007ffc4c  53                   push ebx
// 007ffc4d  51                   push ecx
// 007ffc4e  ffd6                 call esi
// 007ffc50  33db                 xor ebx, ebx
// 007ffc52  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ffc56  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ffc59  68ffffff00           push 0xffffff
// 007ffc5e  8d542bfe             lea edx, [ebx + ebp - 2]
// 007ffc62  52                   push edx
// 007ffc63  50                   push eax
// 007ffc64  51                   push ecx
// 007ffc65  ffd6                 call esi
// 007ffc67  43                   inc ebx
// 007ffc68  83fb03               cmp ebx, 3
// 007ffc6b  7ce5                 jl 0x7ffc52
// 007ffc6d  8b5704               mov edx, dword ptr [edi + 4]
// 007ffc70  68ffffff00           push 0xffffff
// 007ffc75  55                   push ebp
// 007ffc76  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 007ffc7a  55                   push ebp
// 007ffc7b  52                   push edx
// 007ffc7c  ffd6                 call esi
// 007ffc7e  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 007ffc82  8b4704               mov eax, dword ptr [edi + 4]
// 007ffc85  68ffffff00           push 0xffffff
// 007ffc8a  53                   push ebx
// 007ffc8b  55                   push ebp
// 007ffc8c  50                   push eax
// 007ffc8d  ffd6                 call esi
// 007ffc8f  33ed                 xor ebp, ebp
// 007ffc91  8b542444             mov edx, dword ptr [esp + 0x44]
// 007ffc95  8b4704               mov eax, dword ptr [edi + 4]
// 007ffc98  68ffffff00           push 0xffffff
// 007ffc9d  8d0c2b               lea ecx, [ebx + ebp]
// 007ffca0  51                   push ecx
// 007ffca1  52                   push edx
// 007ffca2  50                   push eax
// 007ffca3  ffd6                 call esi
// 007ffca5  45                   inc ebp
// 007ffca6  83fd03               cmp ebp, 3
// 007ffca9  7ce6                 jl 0x7ffc91
// 007ffcab  5f                   pop edi
// 007ffcac  5e                   pop esi
// 007ffcad  5d                   pop ebp
// 007ffcae  5b                   pop ebx
// 007ffcaf  83c440               add esp, 0x40
// 007ffcb2  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
