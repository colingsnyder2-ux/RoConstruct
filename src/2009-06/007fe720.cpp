// from server: 100% by auto
// roc 2009-06 007fe720  unit: CXTColorHex  size: 3251 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe720
//
// 007fe720  81ecbc000000         sub esp, 0xbc
// 007fe726  53                   push ebx
// 007fe727  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 007fe72a  55                   push ebp
// 007fe72b  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 007fe72e  56                   push esi
// 007fe72f  8b35d4e08900         mov esi, dword ptr [0x89e0d4]
// 007fe735  57                   push edi
// 007fe736  8bbc24d0000000       mov edi, dword ptr [esp + 0xd0]
// 007fe73d  83eb02               sub ebx, 2
// 007fe740  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007fe748  896c242c             mov dword ptr [esp + 0x2c], ebp
// 007fe74c  8d642400             lea esp, [esp]
// 007fe750  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007fe754  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fe758  8b5704               mov edx, dword ptr [edi + 4]
// 007fe75b  6a00                 push 0
// 007fe75d  50                   push eax
// 007fe75e  03cb                 add ecx, ebx
// 007fe760  51                   push ecx
// 007fe761  52                   push edx
// 007fe762  ffd6                 call esi
// 007fe764  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fe768  ff4c242c             dec dword ptr [esp + 0x2c]
// 007fe76c  40                   inc eax
// 007fe76d  83f803               cmp eax, 3
// 007fe770  89442410             mov dword ptr [esp + 0x10], eax
// 007fe774  7cda                 jl 0x7fe750
// 007fe776  6a00                 push 0
// 007fe778  8d45fe               lea eax, [ebp - 2]
// 007fe77b  50                   push eax
// 007fe77c  8d4b03               lea ecx, [ebx + 3]
// 007fe77f  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 007fe786  8b4704               mov eax, dword ptr [edi + 4]
// 007fe789  51                   push ecx
// 007fe78a  50                   push eax
// 007fe78b  894c2458             mov dword ptr [esp + 0x58], ecx
// 007fe78f  ffd6                 call esi
// 007fe791  6a00                 push 0
// 007fe793  8d45fd               lea eax, [ebp - 3]
// 007fe796  8d4b04               lea ecx, [ebx + 4]
// 007fe799  50                   push eax
// 007fe79a  51                   push ecx
// 007fe79b  894c245c             mov dword ptr [esp + 0x5c], ecx
// 007fe79f  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe7a2  51                   push ecx
// 007fe7a3  89442434             mov dword ptr [esp + 0x34], eax
// 007fe7a7  ffd6                 call esi
// 007fe7a9  8b542424             mov edx, dword ptr [esp + 0x24]
// 007fe7ad  6a00                 push 0
// 007fe7af  8d4305               lea eax, [ebx + 5]
// 007fe7b2  52                   push edx
// 007fe7b3  50                   push eax
// 007fe7b4  89442444             mov dword ptr [esp + 0x44], eax
// 007fe7b8  8b4704               mov eax, dword ptr [edi + 4]
// 007fe7bb  50                   push eax
// 007fe7bc  ffd6                 call esi
// 007fe7be  6a00                 push 0
// 007fe7c0  8d45fc               lea eax, [ebp - 4]
// 007fe7c3  8d4b06               lea ecx, [ebx + 6]
// 007fe7c6  50                   push eax
// 007fe7c7  51                   push ecx
// 007fe7c8  898c248c000000       mov dword ptr [esp + 0x8c], ecx
// 007fe7cf  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe7d2  51                   push ecx
// 007fe7d3  89442430             mov dword ptr [esp + 0x30], eax
// 007fe7d7  ffd6                 call esi
// 007fe7d9  8b542420             mov edx, dword ptr [esp + 0x20]
// 007fe7dd  6a00                 push 0
// 007fe7df  8d4307               lea eax, [ebx + 7]
// 007fe7e2  52                   push edx
// 007fe7e3  50                   push eax
// 007fe7e4  89842484000000       mov dword ptr [esp + 0x84], eax
// 007fe7eb  8b4704               mov eax, dword ptr [edi + 4]
// 007fe7ee  50                   push eax
// 007fe7ef  ffd6                 call esi
// 007fe7f1  6a00                 push 0
// 007fe7f3  8d45fb               lea eax, [ebp - 5]
// 007fe7f6  8d4b08               lea ecx, [ebx + 8]
// 007fe7f9  50                   push eax
// 007fe7fa  51                   push ecx
// 007fe7fb  894c247c             mov dword ptr [esp + 0x7c], ecx
// 007fe7ff  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe802  51                   push ecx
// 007fe803  89442438             mov dword ptr [esp + 0x38], eax
// 007fe807  ffd6                 call esi
// 007fe809  8b542428             mov edx, dword ptr [esp + 0x28]
// 007fe80d  6a00                 push 0
// 007fe80f  8d4309               lea eax, [ebx + 9]
// 007fe812  52                   push edx
// 007fe813  50                   push eax
// 007fe814  89442474             mov dword ptr [esp + 0x74], eax
// 007fe818  8b4704               mov eax, dword ptr [edi + 4]
// 007fe81b  50                   push eax
// 007fe81c  ffd6                 call esi
// 007fe81e  6a00                 push 0
// 007fe820  8d45fa               lea eax, [ebp - 6]
// 007fe823  8d4b0a               lea ecx, [ebx + 0xa]
// 007fe826  50                   push eax
// 007fe827  51                   push ecx
// 007fe828  894c246c             mov dword ptr [esp + 0x6c], ecx
// 007fe82c  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe82f  51                   push ecx
// 007fe830  8944244c             mov dword ptr [esp + 0x4c], eax
// 007fe834  ffd6                 call esi
// 007fe836  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007fe83a  8d430b               lea eax, [ebx + 0xb]
// 007fe83d  89842494000000       mov dword ptr [esp + 0x94], eax
// 007fe844  6a00                 push 0
// 007fe846  52                   push edx
// 007fe847  50                   push eax
// 007fe848  8b4704               mov eax, dword ptr [edi + 4]
// 007fe84b  50                   push eax
// 007fe84c  ffd6                 call esi
// 007fe84e  6a00                 push 0
// 007fe850  8d45f9               lea eax, [ebp - 7]
// 007fe853  8d4b0c               lea ecx, [ebx + 0xc]
// 007fe856  50                   push eax
// 007fe857  51                   push ecx
// 007fe858  898c24ac000000       mov dword ptr [esp + 0xac], ecx
// 007fe85f  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe862  51                   push ecx
// 007fe863  89442468             mov dword ptr [esp + 0x68], eax
// 007fe867  ffd6                 call esi
// 007fe869  8b542458             mov edx, dword ptr [esp + 0x58]
// 007fe86d  6a00                 push 0
// 007fe86f  8d430d               lea eax, [ebx + 0xd]
// 007fe872  52                   push edx
// 007fe873  50                   push eax
// 007fe874  89842498000000       mov dword ptr [esp + 0x98], eax
// 007fe87b  8b4704               mov eax, dword ptr [edi + 4]
// 007fe87e  50                   push eax
// 007fe87f  ffd6                 call esi
// 007fe881  6a00                 push 0
// 007fe883  8d45f8               lea eax, [ebp - 8]
// 007fe886  8d4b0e               lea ecx, [ebx + 0xe]
// 007fe889  50                   push eax
// 007fe88a  51                   push ecx
// 007fe88b  898c24b4000000       mov dword ptr [esp + 0xb4], ecx
// 007fe892  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe895  51                   push ecx
// 007fe896  ffd6                 call esi
// 007fe898  8b5704               mov edx, dword ptr [edi + 4]
// 007fe89b  6a00                 push 0
// 007fe89d  8d45f8               lea eax, [ebp - 8]
// 007fe8a0  8d4b0f               lea ecx, [ebx + 0xf]
// 007fe8a3  50                   push eax
// 007fe8a4  51                   push ecx
// 007fe8a5  52                   push edx
// 007fe8a6  898c2494000000       mov dword ptr [esp + 0x94], ecx
// 007fe8ad  ffd6                 call esi
// 007fe8af  6a00                 push 0
// 007fe8b1  8d45f8               lea eax, [ebp - 8]
// 007fe8b4  50                   push eax
// 007fe8b5  8b4704               mov eax, dword ptr [edi + 4]
// 007fe8b8  8d4b10               lea ecx, [ebx + 0x10]
// 007fe8bb  51                   push ecx
// 007fe8bc  50                   push eax
// 007fe8bd  898c24c4000000       mov dword ptr [esp + 0xc4], ecx
// 007fe8c4  ffd6                 call esi
// 007fe8c6  6a00                 push 0
// 007fe8c8  8d45f8               lea eax, [ebp - 8]
// 007fe8cb  8d4b11               lea ecx, [ebx + 0x11]
// 007fe8ce  50                   push eax
// 007fe8cf  51                   push ecx
// 007fe8d0  898c2488000000       mov dword ptr [esp + 0x88], ecx
// 007fe8d7  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fe8da  51                   push ecx
// 007fe8db  ffd6                 call esi
// 007fe8dd  8b5704               mov edx, dword ptr [edi + 4]
// 007fe8e0  6a00                 push 0
// 007fe8e2  8d45f8               lea eax, [ebp - 8]
// 007fe8e5  8d4b12               lea ecx, [ebx + 0x12]
// 007fe8e8  50                   push eax
// 007fe8e9  51                   push ecx
// 007fe8ea  52                   push edx
// 007fe8eb  898c24bc000000       mov dword ptr [esp + 0xbc], ecx
// 007fe8f2  ffd6                 call esi
// 007fe8f4  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 007fe8f8  8b5704               mov edx, dword ptr [edi + 4]
// 007fe8fb  6a00                 push 0
// 007fe8fd  8d4313               lea eax, [ebx + 0x13]
// 007fe900  51                   push ecx
// 007fe901  50                   push eax
// 007fe902  52                   push edx
// 007fe903  89842484000000       mov dword ptr [esp + 0x84], eax
// 007fe90a  ffd6                 call esi
// 007fe90c  8d4314               lea eax, [ebx + 0x14]
// 007fe90f  8944245c             mov dword ptr [esp + 0x5c], eax
// 007fe913  6a00                 push 0
// 007fe915  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 007fe919  8b5704               mov edx, dword ptr [edi + 4]
// 007fe91c  51                   push ecx
// 007fe91d  50                   push eax
// 007fe91e  52                   push edx
// 007fe91f  ffd6                 call esi
// 007fe921  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007fe925  8b5704               mov edx, dword ptr [edi + 4]
// 007fe928  6a00                 push 0
// 007fe92a  8d4315               lea eax, [ebx + 0x15]
// 007fe92d  51                   push ecx
// 007fe92e  50                   push eax
// 007fe92f  52                   push edx
// 007fe930  8944247c             mov dword ptr [esp + 0x7c], eax
// 007fe934  ffd6                 call esi
// 007fe936  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007fe93a  8b5704               mov edx, dword ptr [edi + 4]
// 007fe93d  6a00                 push 0
// 007fe93f  8d4316               lea eax, [ebx + 0x16]
// 007fe942  51                   push ecx
// 007fe943  50                   push eax
// 007fe944  52                   push edx
// 007fe945  898424b4000000       mov dword ptr [esp + 0xb4], eax
// 007fe94c  ffd6                 call esi
// 007fe94e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007fe952  8b5704               mov edx, dword ptr [edi + 4]
// 007fe955  6a00                 push 0
// 007fe957  8d4317               lea eax, [ebx + 0x17]
// 007fe95a  51                   push ecx
// 007fe95b  50                   push eax
// 007fe95c  52                   push edx
// 007fe95d  89442474             mov dword ptr [esp + 0x74], eax
// 007fe961  ffd6                 call esi
// 007fe963  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007fe967  8b5704               mov edx, dword ptr [edi + 4]
// 007fe96a  6a00                 push 0
// 007fe96c  8d4318               lea eax, [ebx + 0x18]
// 007fe96f  51                   push ecx
// 007fe970  50                   push eax
// 007fe971  52                   push edx
// 007fe972  89442464             mov dword ptr [esp + 0x64], eax
// 007fe976  ffd6                 call esi
// 007fe978  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007fe97c  8b5704               mov edx, dword ptr [edi + 4]
// 007fe97f  6a00                 push 0
// 007fe981  8d4319               lea eax, [ebx + 0x19]
// 007fe984  51                   push ecx
// 007fe985  50                   push eax
// 007fe986  52                   push edx
// 007fe987  898424a8000000       mov dword ptr [esp + 0xa8], eax
// 007fe98e  ffd6                 call esi
// 007fe990  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007fe994  8b5704               mov edx, dword ptr [edi + 4]
// 007fe997  6a00                 push 0
// 007fe999  8d431a               lea eax, [ebx + 0x1a]
// 007fe99c  51                   push ecx
// 007fe99d  50                   push eax
// 007fe99e  52                   push edx
// 007fe99f  89842498000000       mov dword ptr [esp + 0x98], eax
// 007fe9a6  ffd6                 call esi
// 007fe9a8  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007fe9ac  8b5704               mov edx, dword ptr [edi + 4]
// 007fe9af  6a00                 push 0
// 007fe9b1  8d431b               lea eax, [ebx + 0x1b]
// 007fe9b4  51                   push ecx
// 007fe9b5  50                   push eax
// 007fe9b6  52                   push edx
// 007fe9b7  898424ac000000       mov dword ptr [esp + 0xac], eax
// 007fe9be  ffd6                 call esi
// 007fe9c0  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007fe9c4  8b5704               mov edx, dword ptr [edi + 4]
// 007fe9c7  6a00                 push 0
// 007fe9c9  8d431c               lea eax, [ebx + 0x1c]
// 007fe9cc  51                   push ecx
// 007fe9cd  50                   push eax
// 007fe9ce  52                   push edx
// 007fe9cf  898424a0000000       mov dword ptr [esp + 0xa0], eax
// 007fe9d6  ffd6                 call esi
// 007fe9d8  8d431d               lea eax, [ebx + 0x1d]
// 007fe9db  898424b8000000       mov dword ptr [esp + 0xb8], eax
// 007fe9e2  6a00                 push 0
// 007fe9e4  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 007fe9eb  8b5704               mov edx, dword ptr [edi + 4]
// 007fe9ee  51                   push ecx
// 007fe9ef  50                   push eax
// 007fe9f0  52                   push edx
// 007fe9f1  ffd6                 call esi
// 007fe9f3  8b8c24b0000000       mov ecx, dword ptr [esp + 0xb0]
// 007fe9fa  8b5704               mov edx, dword ptr [edi + 4]
// 007fe9fd  6a00                 push 0
// 007fe9ff  8d431e               lea eax, [ebx + 0x1e]
// 007fea02  51                   push ecx
// 007fea03  50                   push eax
// 007fea04  52                   push edx
// 007fea05  898424cc000000       mov dword ptr [esp + 0xcc], eax
// 007fea0c  ffd6                 call esi
// 007fea0e  6a00                 push 0
// 007fea10  8d45ff               lea eax, [ebp - 1]
// 007fea13  50                   push eax
// 007fea14  8d4b1f               lea ecx, [ebx + 0x1f]
// 007fea17  8944244c             mov dword ptr [esp + 0x4c], eax
// 007fea1b  8b4704               mov eax, dword ptr [edi + 4]
// 007fea1e  51                   push ecx
// 007fea1f  50                   push eax
// 007fea20  898c24d0000000       mov dword ptr [esp + 0xd0], ecx
// 007fea27  ffd6                 call esi
// 007fea29  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007fea31  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fea35  8b5704               mov edx, dword ptr [edi + 4]
// 007fea38  6a00                 push 0
// 007fea3a  03cd                 add ecx, ebp
// 007fea3c  51                   push ecx
// 007fea3d  8d4320               lea eax, [ebx + 0x20]
// 007fea40  50                   push eax
// 007fea41  52                   push edx
// 007fea42  ffd6                 call esi
// 007fea44  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fea48  40                   inc eax
// 007fea49  83f811               cmp eax, 0x11
// 007fea4c  89442410             mov dword ptr [esp + 0x10], eax
// 007fea50  7cdf                 jl 0x7fea31
// 007fea52  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fea55  6a00                 push 0
// 007fea57  8d4511               lea eax, [ebp + 0x11]
// 007fea5a  50                   push eax
// 007fea5b  8944243c             mov dword ptr [esp + 0x3c], eax
// 007fea5f  8b8424c8000000       mov eax, dword ptr [esp + 0xc8]
// 007fea66  50                   push eax
// 007fea67  51                   push ecx
// 007fea68  ffd6                 call esi
// 007fea6a  8b9424bc000000       mov edx, dword ptr [esp + 0xbc]
// 007fea71  6a00                 push 0
// 007fea73  8d4512               lea eax, [ebp + 0x12]
// 007fea76  50                   push eax
// 007fea77  8944241c             mov dword ptr [esp + 0x1c], eax
// 007fea7b  8b4704               mov eax, dword ptr [edi + 4]
// 007fea7e  52                   push edx
// 007fea7f  50                   push eax
// 007fea80  ffd6                 call esi
// 007fea82  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007fea86  8b9424b8000000       mov edx, dword ptr [esp + 0xb8]
// 007fea8d  8b4704               mov eax, dword ptr [edi + 4]
// 007fea90  6a00                 push 0
// 007fea92  51                   push ecx
// 007fea93  52                   push edx
// 007fea94  50                   push eax
// 007fea95  ffd6                 call esi
// 007fea97  8b8c2490000000       mov ecx, dword ptr [esp + 0x90]
// 007fea9e  8b5704               mov edx, dword ptr [edi + 4]
// 007feaa1  6a00                 push 0
// 007feaa3  8d4513               lea eax, [ebp + 0x13]
// 007feaa6  50                   push eax
// 007feaa7  51                   push ecx
// 007feaa8  52                   push edx
// 007feaa9  8944242c             mov dword ptr [esp + 0x2c], eax
// 007feaad  ffd6                 call esi
// 007feaaf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007feab3  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 007feaba  8b5704               mov edx, dword ptr [edi + 4]
// 007feabd  6a00                 push 0
// 007feabf  50                   push eax
// 007feac0  51                   push ecx
// 007feac1  52                   push edx
// 007feac2  ffd6                 call esi
// 007feac4  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feac7  6a00                 push 0
// 007feac9  8d4514               lea eax, [ebp + 0x14]
// 007feacc  50                   push eax
// 007feacd  89442420             mov dword ptr [esp + 0x20], eax
// 007fead1  8b842490000000       mov eax, dword ptr [esp + 0x90]
// 007fead8  50                   push eax
// 007fead9  51                   push ecx
// 007feada  ffd6                 call esi
// 007feadc  8b542418             mov edx, dword ptr [esp + 0x18]
// 007feae0  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 007feae7  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feaea  6a00                 push 0
// 007feaec  52                   push edx
// 007feaed  50                   push eax
// 007feaee  51                   push ecx
// 007feaef  ffd6                 call esi
// 007feaf1  8b542454             mov edx, dword ptr [esp + 0x54]
// 007feaf5  6a00                 push 0
// 007feaf7  8d4515               lea eax, [ebp + 0x15]
// 007feafa  50                   push eax
// 007feafb  89442438             mov dword ptr [esp + 0x38], eax
// 007feaff  8b4704               mov eax, dword ptr [edi + 4]
// 007feb02  52                   push edx
// 007feb03  50                   push eax
// 007feb04  ffd6                 call esi
// 007feb06  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007feb0a  8b542464             mov edx, dword ptr [esp + 0x64]
// 007feb0e  8b4704               mov eax, dword ptr [edi + 4]
// 007feb11  6a00                 push 0
// 007feb13  51                   push ecx
// 007feb14  52                   push edx
// 007feb15  50                   push eax
// 007feb16  ffd6                 call esi
// 007feb18  8d4516               lea eax, [ebp + 0x16]
// 007feb1b  6a00                 push 0
// 007feb1d  89442450             mov dword ptr [esp + 0x50], eax
// 007feb21  50                   push eax
// 007feb22  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 007feb29  8b5704               mov edx, dword ptr [edi + 4]
// 007feb2c  51                   push ecx
// 007feb2d  52                   push edx
// 007feb2e  ffd6                 call esi
// 007feb30  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007feb34  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 007feb38  8b5704               mov edx, dword ptr [edi + 4]
// 007feb3b  6a00                 push 0
// 007feb3d  50                   push eax
// 007feb3e  51                   push ecx
// 007feb3f  52                   push edx
// 007feb40  ffd6                 call esi
// 007feb42  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feb45  6a00                 push 0
// 007feb47  8d4517               lea eax, [ebp + 0x17]
// 007feb4a  50                   push eax
// 007feb4b  89442434             mov dword ptr [esp + 0x34], eax
// 007feb4f  8b442464             mov eax, dword ptr [esp + 0x64]
// 007feb53  50                   push eax
// 007feb54  51                   push ecx
// 007feb55  ffd6                 call esi
// 007feb57  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007feb5b  8b442474             mov eax, dword ptr [esp + 0x74]
// 007feb5f  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feb62  6a00                 push 0
// 007feb64  52                   push edx
// 007feb65  50                   push eax
// 007feb66  51                   push ecx
// 007feb67  ffd6                 call esi
// 007feb69  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 007feb70  6a00                 push 0
// 007feb72  8d4518               lea eax, [ebp + 0x18]
// 007feb75  50                   push eax
// 007feb76  8b4704               mov eax, dword ptr [edi + 4]
// 007feb79  52                   push edx
// 007feb7a  50                   push eax
// 007feb7b  ffd6                 call esi
// 007feb7d  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 007feb81  8b5704               mov edx, dword ptr [edi + 4]
// 007feb84  6a00                 push 0
// 007feb86  8d4518               lea eax, [ebp + 0x18]
// 007feb89  50                   push eax
// 007feb8a  51                   push ecx
// 007feb8b  52                   push edx
// 007feb8c  ffd6                 call esi
// 007feb8e  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feb91  6a00                 push 0
// 007feb93  8d4518               lea eax, [ebp + 0x18]
// 007feb96  50                   push eax
// 007feb97  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 007feb9e  50                   push eax
// 007feb9f  51                   push ecx
// 007feba0  ffd6                 call esi
// 007feba2  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 007feba9  6a00                 push 0
// 007febab  8d4518               lea eax, [ebp + 0x18]
// 007febae  50                   push eax
// 007febaf  8b4704               mov eax, dword ptr [edi + 4]
// 007febb2  52                   push edx
// 007febb3  50                   push eax
// 007febb4  ffd6                 call esi
// 007febb6  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 007febbd  8b5704               mov edx, dword ptr [edi + 4]
// 007febc0  6a00                 push 0
// 007febc2  8d4518               lea eax, [ebp + 0x18]
// 007febc5  50                   push eax
// 007febc6  51                   push ecx
// 007febc7  52                   push edx
// 007febc8  ffd6                 call esi
// 007febca  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007febce  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 007febd5  8b5704               mov edx, dword ptr [edi + 4]
// 007febd8  6a00                 push 0
// 007febda  50                   push eax
// 007febdb  51                   push ecx
// 007febdc  52                   push edx
// 007febdd  ffd6                 call esi
// 007febdf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007febe3  6a00                 push 0
// 007febe5  50                   push eax
// 007febe6  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 007febed  8b5704               mov edx, dword ptr [edi + 4]
// 007febf0  51                   push ecx
// 007febf1  52                   push edx
// 007febf2  ffd6                 call esi
// 007febf4  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007febf8  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 007febff  8b5704               mov edx, dword ptr [edi + 4]
// 007fec02  6a00                 push 0
// 007fec04  50                   push eax
// 007fec05  51                   push ecx
// 007fec06  52                   push edx
// 007fec07  ffd6                 call esi
// 007fec09  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007fec0d  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 007fec11  8b5704               mov edx, dword ptr [edi + 4]
// 007fec14  6a00                 push 0
// 007fec16  50                   push eax
// 007fec17  51                   push ecx
// 007fec18  52                   push edx
// 007fec19  ffd6                 call esi
// 007fec1b  8b442430             mov eax, dword ptr [esp + 0x30]
// 007fec1f  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 007fec23  8b5704               mov edx, dword ptr [edi + 4]
// 007fec26  6a00                 push 0
// 007fec28  50                   push eax
// 007fec29  51                   push ecx
// 007fec2a  52                   push edx
// 007fec2b  ffd6                 call esi
// 007fec2d  8b442430             mov eax, dword ptr [esp + 0x30]
// 007fec31  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 007fec35  8b5704               mov edx, dword ptr [edi + 4]
// 007fec38  6a00                 push 0
// 007fec3a  50                   push eax
// 007fec3b  51                   push ecx
// 007fec3c  52                   push edx
// 007fec3d  ffd6                 call esi
// 007fec3f  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fec43  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 007fec47  8b5704               mov edx, dword ptr [edi + 4]
// 007fec4a  6a00                 push 0
// 007fec4c  50                   push eax
// 007fec4d  51                   push ecx
// 007fec4e  52                   push edx
// 007fec4f  ffd6                 call esi
// 007fec51  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fec55  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 007fec5c  8b5704               mov edx, dword ptr [edi + 4]
// 007fec5f  6a00                 push 0
// 007fec61  50                   push eax
// 007fec62  51                   push ecx
// 007fec63  52                   push edx
// 007fec64  ffd6                 call esi
// 007fec66  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fec6a  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007fec6e  8b5704               mov edx, dword ptr [edi + 4]
// 007fec71  6a00                 push 0
// 007fec73  50                   push eax
// 007fec74  51                   push ecx
// 007fec75  52                   push edx
// 007fec76  ffd6                 call esi
// 007fec78  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fec7c  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 007fec80  8b5704               mov edx, dword ptr [edi + 4]
// 007fec83  6a00                 push 0
// 007fec85  50                   push eax
// 007fec86  51                   push ecx
// 007fec87  52                   push edx
// 007fec88  ffd6                 call esi
// 007fec8a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fec8e  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 007fec92  8b5704               mov edx, dword ptr [edi + 4]
// 007fec95  6a00                 push 0
// 007fec97  50                   push eax
// 007fec98  51                   push ecx
// 007fec99  52                   push edx
// 007fec9a  ffd6                 call esi
// 007fec9c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007feca0  8d4302               lea eax, [ebx + 2]
// 007feca3  898424c8000000       mov dword ptr [esp + 0xc8], eax
// 007fecaa  6a00                 push 0
// 007fecac  8b5704               mov edx, dword ptr [edi + 4]
// 007fecaf  51                   push ecx
// 007fecb0  50                   push eax
// 007fecb1  52                   push edx
// 007fecb2  ffd6                 call esi
// 007fecb4  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 007fecb8  8b5704               mov edx, dword ptr [edi + 4]
// 007fecbb  6a00                 push 0
// 007fecbd  8d4301               lea eax, [ebx + 1]
// 007fecc0  51                   push ecx
// 007fecc1  50                   push eax
// 007fecc2  52                   push edx
// 007fecc3  898424d4000000       mov dword ptr [esp + 0xd4], eax
// 007fecca  ffd6                 call esi
// 007feccc  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007fecd4  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fecd8  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fecdb  6a00                 push 0
// 007fecdd  03c5                 add eax, ebp
// 007fecdf  50                   push eax
// 007fece0  53                   push ebx
// 007fece1  51                   push ecx
// 007fece2  ffd6                 call esi
// 007fece4  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fece8  40                   inc eax
// 007fece9  83f811               cmp eax, 0x11
// 007fecec  89442410             mov dword ptr [esp + 0x10], eax
// 007fecf0  7ce2                 jl 0x7fecd4
// 007fecf2  33db                 xor ebx, ebx
// 007fecf4  8b442450             mov eax, dword ptr [esp + 0x50]
// 007fecf8  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fecfb  6a00                 push 0
// 007fecfd  8d542b01             lea edx, [ebx + ebp + 1]
// 007fed01  52                   push edx
// 007fed02  50                   push eax
// 007fed03  51                   push ecx
// 007fed04  ffd6                 call esi
// 007fed06  43                   inc ebx
// 007fed07  83fb0f               cmp ebx, 0xf
// 007fed0a  7ce8                 jl 0x7fecf4
// 007fed0c  8b542438             mov edx, dword ptr [esp + 0x38]
// 007fed10  8b4704               mov eax, dword ptr [edi + 4]
// 007fed13  6a00                 push 0
// 007fed15  8d5d10               lea ebx, [ebp + 0x10]
// 007fed18  53                   push ebx
// 007fed19  52                   push edx
// 007fed1a  50                   push eax
// 007fed1b  895c2450             mov dword ptr [esp + 0x50], ebx
// 007fed1f  ffd6                 call esi
// 007fed21  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 007fed28  8b5704               mov edx, dword ptr [edi + 4]
// 007fed2b  6a00                 push 0
// 007fed2d  53                   push ebx
// 007fed2e  51                   push ecx
// 007fed2f  52                   push edx
// 007fed30  ffd6                 call esi
// 007fed32  8b442434             mov eax, dword ptr [esp + 0x34]
// 007fed36  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 007fed3a  8b5704               mov edx, dword ptr [edi + 4]
// 007fed3d  6a00                 push 0
// 007fed3f  50                   push eax
// 007fed40  51                   push ecx
// 007fed41  52                   push edx
// 007fed42  ffd6                 call esi
// 007fed44  8b442434             mov eax, dword ptr [esp + 0x34]
// 007fed48  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 007fed4c  8b5704               mov edx, dword ptr [edi + 4]
// 007fed4f  6a00                 push 0
// 007fed51  50                   push eax
// 007fed52  51                   push ecx
// 007fed53  52                   push edx
// 007fed54  ffd6                 call esi
// 007fed56  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fed5a  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 007fed5e  8b5704               mov edx, dword ptr [edi + 4]
// 007fed61  6a00                 push 0
// 007fed63  50                   push eax
// 007fed64  51                   push ecx
// 007fed65  52                   push edx
// 007fed66  ffd6                 call esi
// 007fed68  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fed6c  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 007fed70  8b5704               mov edx, dword ptr [edi + 4]
// 007fed73  6a00                 push 0
// 007fed75  50                   push eax
// 007fed76  51                   push ecx
// 007fed77  52                   push edx
// 007fed78  ffd6                 call esi
// 007fed7a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fed7e  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 007fed85  8b5704               mov edx, dword ptr [edi + 4]
// 007fed88  6a00                 push 0
// 007fed8a  50                   push eax
// 007fed8b  51                   push ecx
// 007fed8c  52                   push edx
// 007fed8d  ffd6                 call esi
// 007fed8f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fed93  8b8c24a0000000       mov ecx, dword ptr [esp + 0xa0]
// 007fed9a  8b5704               mov edx, dword ptr [edi + 4]
// 007fed9d  6a00                 push 0
// 007fed9f  50                   push eax
// 007feda0  51                   push ecx
// 007feda1  52                   push edx
// 007feda2  ffd6                 call esi
// 007feda4  8b442418             mov eax, dword ptr [esp + 0x18]
// 007feda8  8b8c248c000000       mov ecx, dword ptr [esp + 0x8c]
// 007fedaf  8b5704               mov edx, dword ptr [edi + 4]
// 007fedb2  6a00                 push 0
// 007fedb4  50                   push eax
// 007fedb5  51                   push ecx
// 007fedb6  52                   push edx
// 007fedb7  ffd6                 call esi
// 007fedb9  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fedbd  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 007fedc4  8b5704               mov edx, dword ptr [edi + 4]
// 007fedc7  6a00                 push 0
// 007fedc9  50                   push eax
// 007fedca  51                   push ecx
// 007fedcb  52                   push edx
// 007fedcc  ffd6                 call esi
// 007fedce  6a00                 push 0
// 007fedd0  8b442434             mov eax, dword ptr [esp + 0x34]
// 007fedd4  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 007feddb  8b5704               mov edx, dword ptr [edi + 4]
// 007fedde  50                   push eax
// 007feddf  51                   push ecx
// 007fede0  52                   push edx
// 007fede1  ffd6                 call esi
// 007fede3  8b442430             mov eax, dword ptr [esp + 0x30]
// 007fede7  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 007fedee  8b5704               mov edx, dword ptr [edi + 4]
// 007fedf1  6a00                 push 0
// 007fedf3  50                   push eax
// 007fedf4  51                   push ecx
// 007fedf5  52                   push edx
// 007fedf6  ffd6                 call esi
// 007fedf8  8b442430             mov eax, dword ptr [esp + 0x30]
// 007fedfc  8b4c247c             mov ecx, dword ptr [esp + 0x7c]
// 007fee00  8b5704               mov edx, dword ptr [edi + 4]
// 007fee03  6a00                 push 0
// 007fee05  50                   push eax
// 007fee06  51                   push ecx
// 007fee07  52                   push edx
// 007fee08  ffd6                 call esi
// 007fee0a  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fee0e  8b8c24ac000000       mov ecx, dword ptr [esp + 0xac]
// 007fee15  8b5704               mov edx, dword ptr [edi + 4]
// 007fee18  6a00                 push 0
// 007fee1a  50                   push eax
// 007fee1b  51                   push ecx
// 007fee1c  52                   push edx
// 007fee1d  ffd6                 call esi
// 007fee1f  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fee23  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 007fee27  8b5704               mov edx, dword ptr [edi + 4]
// 007fee2a  6a00                 push 0
// 007fee2c  50                   push eax
// 007fee2d  51                   push ecx
// 007fee2e  52                   push edx
// 007fee2f  ffd6                 call esi
// 007fee31  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fee35  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 007fee39  8b5704               mov edx, dword ptr [edi + 4]
// 007fee3c  6a00                 push 0
// 007fee3e  50                   push eax
// 007fee3f  51                   push ecx
// 007fee40  52                   push edx
// 007fee41  ffd6                 call esi
// 007fee43  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007fee47  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 007fee4b  8b5704               mov edx, dword ptr [edi + 4]
// 007fee4e  6a00                 push 0
// 007fee50  50                   push eax
// 007fee51  51                   push ecx
// 007fee52  52                   push edx
// 007fee53  ffd6                 call esi
// 007fee55  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fee59  8b8c24a4000000       mov ecx, dword ptr [esp + 0xa4]
// 007fee60  8b5704               mov edx, dword ptr [edi + 4]
// 007fee63  6a00                 push 0
// 007fee65  50                   push eax
// 007fee66  51                   push ecx
// 007fee67  52                   push edx
// 007fee68  ffd6                 call esi
// 007fee6a  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fee6e  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 007fee72  8b5704               mov edx, dword ptr [edi + 4]
// 007fee75  6a00                 push 0
// 007fee77  50                   push eax
// 007fee78  51                   push ecx
// 007fee79  52                   push edx
// 007fee7a  ffd6                 call esi
// 007fee7c  8b442434             mov eax, dword ptr [esp + 0x34]
// 007fee80  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007fee84  8b5704               mov edx, dword ptr [edi + 4]
// 007fee87  6a00                 push 0
// 007fee89  50                   push eax
// 007fee8a  51                   push ecx
// 007fee8b  52                   push edx
// 007fee8c  ffd6                 call esi
// 007fee8e  8b442434             mov eax, dword ptr [esp + 0x34]
// 007fee92  6a00                 push 0
// 007fee94  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 007fee9b  8b5704               mov edx, dword ptr [edi + 4]
// 007fee9e  50                   push eax
// 007fee9f  51                   push ecx
// 007feea0  52                   push edx
// 007feea1  ffd6                 call esi
// 007feea3  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 007feeaa  8b4f04               mov ecx, dword ptr [edi + 4]
// 007feead  6a00                 push 0
// 007feeaf  53                   push ebx
// 007feeb0  50                   push eax
// 007feeb1  51                   push ecx
// 007feeb2  ffd6                 call esi
// 007feeb4  8b94249c000000       mov edx, dword ptr [esp + 0x9c]
// 007feebb  8b4704               mov eax, dword ptr [edi + 4]
// 007feebe  6a00                 push 0
// 007feec0  53                   push ebx
// 007feec1  52                   push edx
// 007feec2  50                   push eax
// 007feec3  ffd6                 call esi
// 007feec5  33db                 xor ebx, ebx
// 007feec7  eb07                 jmp 0x7feed0
// 007feec9  8da42400000000       lea esp, [esp]
// 007feed0  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 007feed7  8b4704               mov eax, dword ptr [edi + 4]
// 007feeda  6a00                 push 0
// 007feedc  8d4c2b01             lea ecx, [ebx + ebp + 1]
// 007feee0  51                   push ecx
// 007feee1  52                   push edx
// 007feee2  50                   push eax
// 007feee3  ffd6                 call esi
// 007feee5  43                   inc ebx
// 007feee6  83fb0f               cmp ebx, 0xf
// 007feee9  7ce5                 jl 0x7feed0
// 007feeeb  8b8c249c000000       mov ecx, dword ptr [esp + 0x9c]
// 007feef2  8b5704               mov edx, dword ptr [edi + 4]
// 007feef5  6a00                 push 0
// 007feef7  55                   push ebp
// 007feef8  51                   push ecx
// 007feef9  52                   push edx
// 007feefa  ffd6                 call esi
// 007feefc  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 007fef03  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fef06  6a00                 push 0
// 007fef08  55                   push ebp
// 007fef09  50                   push eax
// 007fef0a  51                   push ecx
// 007fef0b  ffd6                 call esi
// 007fef0d  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 007fef11  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 007fef18  8b4704               mov eax, dword ptr [edi + 4]
// 007fef1b  6a00                 push 0
// 007fef1d  53                   push ebx
// 007fef1e  52                   push edx
// 007fef1f  50                   push eax
// 007fef20  ffd6                 call esi
// 007fef22  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 007fef26  8b5704               mov edx, dword ptr [edi + 4]
// 007fef29  6a00                 push 0
// 007fef2b  53                   push ebx
// 007fef2c  51                   push ecx
// 007fef2d  52                   push edx
// 007fef2e  ffd6                 call esi
// 007fef30  8b9c24b0000000       mov ebx, dword ptr [esp + 0xb0]
// 007fef37  8b442464             mov eax, dword ptr [esp + 0x64]
// 007fef3b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007fef3e  6a00                 push 0
// 007fef40  53                   push ebx
// 007fef41  50                   push eax
// 007fef42  51                   push ecx
// 007fef43  ffd6                 call esi
// 007fef45  8b9424a4000000       mov edx, dword ptr [esp + 0xa4]
// 007fef4c  8b4704               mov eax, dword ptr [edi + 4]
// 007fef4f  6a00                 push 0
// 007fef51  53                   push ebx
// 007fef52  52                   push edx
// 007fef53  50                   push eax
// 007fef54  ffd6                 call esi
// 007fef56  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007fef5a  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 007fef5e  8b4704               mov eax, dword ptr [edi + 4]
// 007fef61  6a00                 push 0
// 007fef63  51                   push ecx
// 007fef64  52                   push edx
// 007fef65  50                   push eax
// 007fef66  ffd6                 call esi
// 007fef68  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007fef6c  8b54245c             mov edx, dword ptr [esp + 0x5c]
// 007fef70  8b4704               mov eax, dword ptr [edi + 4]
// 007fef73  6a00                 push 0
// 007fef75  51                   push ecx
// 007fef76  52                   push edx
// 007fef77  50                   push eax
// 007fef78  ffd6                 call esi
// 007fef7a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007fef7e  8b542474             mov edx, dword ptr [esp + 0x74]
// 007fef82  8b4704               mov eax, dword ptr [edi + 4]
// 007fef85  6a00                 push 0
// 007fef87  51                   push ecx
// 007fef88  52                   push edx
// 007fef89  50                   push eax
// 007fef8a  ffd6                 call esi
// 007fef8c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007fef90  8b9424ac000000       mov edx, dword ptr [esp + 0xac]
// 007fef97  8b4704               mov eax, dword ptr [edi + 4]
// 007fef9a  6a00                 push 0
// 007fef9c  51                   push ecx
// 007fef9d  52                   push edx
// 007fef9e  50                   push eax
// 007fef9f  ffd6                 call esi
// 007fefa1  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007fefa5  8b54247c             mov edx, dword ptr [esp + 0x7c]
// 007fefa9  6a00                 push 0
// 007fefab  51                   push ecx
// 007fefac  52                   push edx
// 007fefad  8b4704               mov eax, dword ptr [edi + 4]
// 007fefb0  50                   push eax
// 007fefb1  ffd6                 call esi
// 007fefb3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007fefb7  8b9424b4000000       mov edx, dword ptr [esp + 0xb4]
// 007fefbe  8b4704               mov eax, dword ptr [edi + 4]
// 007fefc1  6a00                 push 0
// 007fefc3  51                   push ecx
// 007fefc4  52                   push edx
// 007fefc5  50                   push eax
// 007fefc6  ffd6                 call esi
// 007fefc8  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007fefcc  8b942484000000       mov edx, dword ptr [esp + 0x84]
// 007fefd3  8b4704               mov eax, dword ptr [edi + 4]
// 007fefd6  6a00                 push 0
// 007fefd8  51                   push ecx
// 007fefd9  52                   push edx
// 007fefda  50                   push eax
// 007fefdb  ffd6                 call esi
// 007fefdd  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007fefe1  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 007fefe8  8b4704               mov eax, dword ptr [edi + 4]
// 007fefeb  6a00                 push 0
// 007fefed  51                   push ecx
// 007fefee  52                   push edx
// 007fefef  50                   push eax
// 007feff0  ffd6                 call esi
// 007feff2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007feff6  8b94248c000000       mov edx, dword ptr [esp + 0x8c]
// 007feffd  8b4704               mov eax, dword ptr [edi + 4]
// 007ff000  6a00                 push 0
// 007ff002  51                   push ecx
// 007ff003  52                   push edx
// 007ff004  50                   push eax
// 007ff005  ffd6                 call esi
// 007ff007  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ff00b  8b9424a0000000       mov edx, dword ptr [esp + 0xa0]
// 007ff012  8b4704               mov eax, dword ptr [edi + 4]
// 007ff015  6a00                 push 0
// 007ff017  51                   push ecx
// 007ff018  52                   push edx
// 007ff019  50                   push eax
// 007ff01a  ffd6                 call esi
// 007ff01c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007ff020  8b942494000000       mov edx, dword ptr [esp + 0x94]
// 007ff027  8b4704               mov eax, dword ptr [edi + 4]
// 007ff02a  6a00                 push 0
// 007ff02c  51                   push ecx
// 007ff02d  52                   push edx
// 007ff02e  50                   push eax
// 007ff02f  ffd6                 call esi
// 007ff031  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 007ff035  8b5704               mov edx, dword ptr [edi + 4]
// 007ff038  6a00                 push 0
// 007ff03a  53                   push ebx
// 007ff03b  51                   push ecx
// 007ff03c  52                   push edx
// 007ff03d  ffd6                 call esi
// 007ff03f  8b442468             mov eax, dword ptr [esp + 0x68]
// 007ff043  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff046  6a00                 push 0
// 007ff048  53                   push ebx
// 007ff049  50                   push eax
// 007ff04a  51                   push ecx
// 007ff04b  ffd6                 call esi
// 007ff04d  8b542444             mov edx, dword ptr [esp + 0x44]
// 007ff051  8b442470             mov eax, dword ptr [esp + 0x70]
// 007ff055  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff058  6a00                 push 0
// 007ff05a  52                   push edx
// 007ff05b  50                   push eax
// 007ff05c  51                   push ecx
// 007ff05d  ffd6                 call esi
// 007ff05f  8b542444             mov edx, dword ptr [esp + 0x44]
// 007ff063  8b442478             mov eax, dword ptr [esp + 0x78]
// 007ff067  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff06a  6a00                 push 0
// 007ff06c  52                   push edx
// 007ff06d  50                   push eax
// 007ff06e  51                   push ecx
// 007ff06f  ffd6                 call esi
// 007ff071  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 007ff078  8b4704               mov eax, dword ptr [edi + 4]
// 007ff07b  6a00                 push 0
// 007ff07d  55                   push ebp
// 007ff07e  52                   push edx
// 007ff07f  50                   push eax
// 007ff080  ffd6                 call esi
// 007ff082  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007ff086  8b5704               mov edx, dword ptr [edi + 4]
// 007ff089  6a00                 push 0
// 007ff08b  55                   push ebp
// 007ff08c  51                   push ecx
// 007ff08d  52                   push edx
// 007ff08e  ffd6                 call esi
// 007ff090  896c2410             mov dword ptr [esp + 0x10], ebp
// 007ff094  c744243811000000     mov dword ptr [esp + 0x38], 0x11
// 007ff09c  8d642400             lea esp, [esp]
// 007ff0a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff0a4  8b8c24c4000000       mov ecx, dword ptr [esp + 0xc4]
// 007ff0ab  8b5704               mov edx, dword ptr [edi + 4]
// 007ff0ae  68ffffff00           push 0xffffff
// 007ff0b3  50                   push eax
// 007ff0b4  51                   push ecx
// 007ff0b5  52                   push edx
// 007ff0b6  ffd6                 call esi
// 007ff0b8  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff0bc  8b8c24c8000000       mov ecx, dword ptr [esp + 0xc8]
// 007ff0c3  8b5704               mov edx, dword ptr [edi + 4]
// 007ff0c6  68ffffff00           push 0xffffff
// 007ff0cb  50                   push eax
// 007ff0cc  51                   push ecx
// 007ff0cd  52                   push edx
// 007ff0ce  ffd6                 call esi
// 007ff0d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ff0d4  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 007ff0d8  8b5704               mov edx, dword ptr [edi + 4]
// 007ff0db  68ffffff00           push 0xffffff
// 007ff0e0  50                   push eax
// 007ff0e1  51                   push ecx
// 007ff0e2  52                   push edx
// 007ff0e3  ffd6                 call esi
// 007ff0e5  b801000000           mov eax, 1
// 007ff0ea  01442410             add dword ptr [esp + 0x10], eax
// 007ff0ee  29442438             sub dword ptr [esp + 0x38], eax
// 007ff0f2  75ac                 jne 0x7ff0a0
// 007ff0f4  8b442450             mov eax, dword ptr [esp + 0x50]
// 007ff0f8  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff0fb  68ffffff00           push 0xffffff
// 007ff100  55                   push ebp
// 007ff101  50                   push eax
// 007ff102  51                   push ecx
// 007ff103  ffd6                 call esi
// 007ff105  8b542440             mov edx, dword ptr [esp + 0x40]
// 007ff109  8b442450             mov eax, dword ptr [esp + 0x50]
// 007ff10d  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff110  68ffffff00           push 0xffffff
// 007ff115  52                   push edx
// 007ff116  50                   push eax
// 007ff117  51                   push ecx
// 007ff118  ffd6                 call esi
// 007ff11a  896c2410             mov dword ptr [esp + 0x10], ebp
// 007ff11e  c744244811000000     mov dword ptr [esp + 0x48], 0x11
// 007ff126  eb08                 jmp 0x7ff130
// 007ff128  8da42400000000       lea esp, [esp]
// 007ff12f  90                   nop 
// 007ff130  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff134  8b8424b8000000       mov eax, dword ptr [esp + 0xb8]
// 007ff13b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff13e  68ffffff00           push 0xffffff
// 007ff143  52                   push edx
// 007ff144  50                   push eax
// 007ff145  51                   push ecx
// 007ff146  ffd6                 call esi
// 007ff148  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff14c  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 007ff153  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff156  68ffffff00           push 0xffffff
// 007ff15b  52                   push edx
// 007ff15c  50                   push eax
// 007ff15d  51                   push ecx
// 007ff15e  ffd6                 call esi
// 007ff160  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ff164  8b8424c0000000       mov eax, dword ptr [esp + 0xc0]
// 007ff16b  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff16e  68ffffff00           push 0xffffff
// 007ff173  52                   push edx
// 007ff174  50                   push eax
// 007ff175  51                   push ecx
// 007ff176  ffd6                 call esi
// 007ff178  b801000000           mov eax, 1
// 007ff17d  01442410             add dword ptr [esp + 0x10], eax
// 007ff181  29442448             sub dword ptr [esp + 0x48], eax
// 007ff185  75a9                 jne 0x7ff130
// 007ff187  8b5704               mov edx, dword ptr [edi + 4]
// 007ff18a  68ffffff00           push 0xffffff
// 007ff18f  55                   push ebp
// 007ff190  8bac2498000000       mov ebp, dword ptr [esp + 0x98]
// 007ff197  55                   push ebp
// 007ff198  52                   push edx
// 007ff199  ffd6                 call esi
// 007ff19b  8b442440             mov eax, dword ptr [esp + 0x40]
// 007ff19f  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff1a2  68ffffff00           push 0xffffff
// 007ff1a7  50                   push eax
// 007ff1a8  55                   push ebp
// 007ff1a9  51                   push ecx
// 007ff1aa  ffd6                 call esi
// 007ff1ac  8b6c2454             mov ebp, dword ptr [esp + 0x54]
// 007ff1b0  c744244005000000     mov dword ptr [esp + 0x40], 5
// 007ff1b8  eb06                 jmp 0x7ff1c0
// 007ff1ba  8d9b00000000         lea ebx, [ebx]
// 007ff1c0  8b542444             mov edx, dword ptr [esp + 0x44]
// 007ff1c4  68ffffff00           push 0xffffff
// 007ff1c9  52                   push edx
// 007ff1ca  8d45ea               lea eax, [ebp - 0x16]
// 007ff1cd  50                   push eax
// 007ff1ce  8b4704               mov eax, dword ptr [edi + 4]
// 007ff1d1  50                   push eax
// 007ff1d2  ffd6                 call esi
// 007ff1d4  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff1d7  68ffffff00           push 0xffffff
// 007ff1dc  53                   push ebx
// 007ff1dd  8d45ec               lea eax, [ebp - 0x14]
// 007ff1e0  50                   push eax
// 007ff1e1  51                   push ecx
// 007ff1e2  ffd6                 call esi
// 007ff1e4  8b542424             mov edx, dword ptr [esp + 0x24]
// 007ff1e8  68ffffff00           push 0xffffff
// 007ff1ed  52                   push edx
// 007ff1ee  8d45ee               lea eax, [ebp - 0x12]
// 007ff1f1  50                   push eax
// 007ff1f2  8b4704               mov eax, dword ptr [edi + 4]
// 007ff1f5  50                   push eax
// 007ff1f6  ffd6                 call esi
// 007ff1f8  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ff1fc  8b5704               mov edx, dword ptr [edi + 4]
// 007ff1ff  68ffffff00           push 0xffffff
// 007ff204  51                   push ecx
// 007ff205  8d45f0               lea eax, [ebp - 0x10]
// 007ff208  50                   push eax
// 007ff209  52                   push edx
// 007ff20a  ffd6                 call esi
// 007ff20c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007ff210  8b5704               mov edx, dword ptr [edi + 4]
// 007ff213  68ffffff00           push 0xffffff
// 007ff218  51                   push ecx
// 007ff219  8d45f2               lea eax, [ebp - 0xe]
// 007ff21c  50                   push eax
// 007ff21d  52                   push edx
// 007ff21e  ffd6                 call esi
// 007ff220  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007ff224  8b5704               mov edx, dword ptr [edi + 4]
// 007ff227  68ffffff00           push 0xffffff
// 007ff22c  51                   push ecx
// 007ff22d  8d45f4               lea eax, [ebp - 0xc]
// 007ff230  50                   push eax
// 007ff231  52                   push edx
// 007ff232  ffd6                 call esi
// 007ff234  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 007ff238  8b5704               mov edx, dword ptr [edi + 4]
// 007ff23b  68ffffff00           push 0xffffff
// 007ff240  51                   push ecx
// 007ff241  8d45f8               lea eax, [ebp - 8]
// 007ff244  50                   push eax
// 007ff245  52                   push edx
// 007ff246  ffd6                 call esi
// 007ff248  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 007ff24c  8b5704               mov edx, dword ptr [edi + 4]
// 007ff24f  68ffffff00           push 0xffffff
// 007ff254  51                   push ecx
// 007ff255  8d45f6               lea eax, [ebp - 0xa]
// 007ff258  50                   push eax
// 007ff259  52                   push edx
// 007ff25a  ffd6                 call esi
// 007ff25c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007ff260  8b5704               mov edx, dword ptr [edi + 4]
// 007ff263  68ffffff00           push 0xffffff
// 007ff268  51                   push ecx
// 007ff269  8d45fa               lea eax, [ebp - 6]
// 007ff26c  50                   push eax
// 007ff26d  52                   push edx
// 007ff26e  ffd6                 call esi
// 007ff270  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 007ff274  8b5704               mov edx, dword ptr [edi + 4]
// 007ff277  68ffffff00           push 0xffffff
// 007ff27c  51                   push ecx
// 007ff27d  8d45fc               lea eax, [ebp - 4]
// 007ff280  50                   push eax
// 007ff281  52                   push edx
// 007ff282  ffd6                 call esi
// 007ff284  8d45fe               lea eax, [ebp - 2]
// 007ff287  68ffffff00           push 0xffffff
// 007ff28c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007ff290  8b5704               mov edx, dword ptr [edi + 4]
// 007ff293  51                   push ecx
// 007ff294  50                   push eax
// 007ff295  52                   push edx
// 007ff296  ffd6                 call esi
// 007ff298  8b4704               mov eax, dword ptr [edi + 4]
// 007ff29b  68ffffff00           push 0xffffff
// 007ff2a0  53                   push ebx
// 007ff2a1  55                   push ebp
// 007ff2a2  50                   push eax
// 007ff2a3  ffd6                 call esi
// 007ff2a5  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007ff2a9  8b5704               mov edx, dword ptr [edi + 4]
// 007ff2ac  68ffffff00           push 0xffffff
// 007ff2b1  51                   push ecx
// 007ff2b2  8d4502               lea eax, [ebp + 2]
// 007ff2b5  50                   push eax
// 007ff2b6  52                   push edx
// 007ff2b7  ffd6                 call esi
// 007ff2b9  8b442434             mov eax, dword ptr [esp + 0x34]
// 007ff2bd  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff2c0  68ffffff00           push 0xffffff
// 007ff2c5  50                   push eax
// 007ff2c6  8d4502               lea eax, [ebp + 2]
// 007ff2c9  50                   push eax
// 007ff2ca  51                   push ecx
// 007ff2cb  ffd6                 call esi
// 007ff2cd  8b542414             mov edx, dword ptr [esp + 0x14]
// 007ff2d1  8b4704               mov eax, dword ptr [edi + 4]
// 007ff2d4  68ffffff00           push 0xffffff
// 007ff2d9  52                   push edx
// 007ff2da  55                   push ebp
// 007ff2db  50                   push eax
// 007ff2dc  ffd6                 call esi
// 007ff2de  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007ff2e2  8b5704               mov edx, dword ptr [edi + 4]
// 007ff2e5  68ffffff00           push 0xffffff
// 007ff2ea  51                   push ecx
// 007ff2eb  8d45fe               lea eax, [ebp - 2]
// 007ff2ee  50                   push eax
// 007ff2ef  52                   push edx
// 007ff2f0  ffd6                 call esi
// 007ff2f2  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ff2f6  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff2f9  68ffffff00           push 0xffffff
// 007ff2fe  50                   push eax
// 007ff2ff  8d45fc               lea eax, [ebp - 4]
// 007ff302  50                   push eax
// 007ff303  51                   push ecx
// 007ff304  ffd6                 call esi
// 007ff306  8b542430             mov edx, dword ptr [esp + 0x30]
// 007ff30a  68ffffff00           push 0xffffff
// 007ff30f  52                   push edx
// 007ff310  8d45fa               lea eax, [ebp - 6]
// 007ff313  50                   push eax
// 007ff314  8b4704               mov eax, dword ptr [edi + 4]
// 007ff317  50                   push eax
// 007ff318  ffd6                 call esi
// 007ff31a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007ff31e  8b5704               mov edx, dword ptr [edi + 4]
// 007ff321  68ffffff00           push 0xffffff
// 007ff326  51                   push ecx
// 007ff327  8d45f6               lea eax, [ebp - 0xa]
// 007ff32a  50                   push eax
// 007ff32b  52                   push edx
// 007ff32c  ffd6                 call esi
// 007ff32e  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 007ff332  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff335  68ffffff00           push 0xffffff
// 007ff33a  50                   push eax
// 007ff33b  8d45f8               lea eax, [ebp - 8]
// 007ff33e  50                   push eax
// 007ff33f  51                   push ecx
// 007ff340  ffd6                 call esi
// 007ff342  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 007ff346  68ffffff00           push 0xffffff
// 007ff34b  8d45f4               lea eax, [ebp - 0xc]
// 007ff34e  52                   push edx
// 007ff34f  50                   push eax
// 007ff350  8b4704               mov eax, dword ptr [edi + 4]
// 007ff353  50                   push eax
// 007ff354  ffd6                 call esi
// 007ff356  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007ff35a  8b5704               mov edx, dword ptr [edi + 4]
// 007ff35d  68ffffff00           push 0xffffff
// 007ff362  51                   push ecx
// 007ff363  8d45f2               lea eax, [ebp - 0xe]
// 007ff366  50                   push eax
// 007ff367  52                   push edx
// 007ff368  ffd6                 call esi
// 007ff36a  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ff36e  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff371  68ffffff00           push 0xffffff
// 007ff376  50                   push eax
// 007ff377  8d45f0               lea eax, [ebp - 0x10]
// 007ff37a  50                   push eax
// 007ff37b  51                   push ecx
// 007ff37c  ffd6                 call esi
// 007ff37e  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007ff382  68ffffff00           push 0xffffff
// 007ff387  52                   push edx
// 007ff388  8d45ee               lea eax, [ebp - 0x12]
// 007ff38b  50                   push eax
// 007ff38c  8b4704               mov eax, dword ptr [edi + 4]
// 007ff38f  50                   push eax
// 007ff390  ffd6                 call esi
// 007ff392  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ff396  8b5704               mov edx, dword ptr [edi + 4]
// 007ff399  68ffffff00           push 0xffffff
// 007ff39e  51                   push ecx
// 007ff39f  8d45ec               lea eax, [ebp - 0x14]
// 007ff3a2  50                   push eax
// 007ff3a3  52                   push edx
// 007ff3a4  ffd6                 call esi
// 007ff3a6  8b442434             mov eax, dword ptr [esp + 0x34]
// 007ff3aa  8b4f04               mov ecx, dword ptr [edi + 4]
// 007ff3ad  68ffffff00           push 0xffffff
// 007ff3b2  50                   push eax
// 007ff3b3  8d45ea               lea eax, [ebp - 0x16]
// 007ff3b6  50                   push eax
// 007ff3b7  51                   push ecx
// 007ff3b8  ffd6                 call esi
// 007ff3ba  45                   inc ebp
// 007ff3bb  836c244001           sub dword ptr [esp + 0x40], 1
// 007ff3c0  0f85fafdffff         jne 0x7ff1c0
// 007ff3c6  5f                   pop edi
// 007ff3c7  5e                   pop esi
// 007ff3c8  5d                   pop ebp
// 007ff3c9  5b                   pop ebx
// 007ff3ca  81c4bc000000         add esp, 0xbc
// 007ff3d0  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawLargeSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
