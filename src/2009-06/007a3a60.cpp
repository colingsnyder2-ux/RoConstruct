// from server: 100% by auto
// roc 2009-06 007a3a60  unit: XTPPaintThemes::CXTPDefaultTheme  size: 490 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a3a60
//
// 007a3a60  8b442408             mov eax, dword ptr [esp + 8]
// 007a3a64  83ec20               sub esp, 0x20
// 007a3a67  53                   push ebx
// 007a3a68  55                   push ebp
// 007a3a69  56                   push esi
// 007a3a6a  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 007a3a6e  03c6                 add eax, esi
// 007a3a70  99                   cdq 
// 007a3a71  2bc2                 sub eax, edx
// 007a3a73  d1f8                 sar eax, 1
// 007a3a75  837c244402           cmp dword ptr [esp + 0x44], 2
// 007a3a7a  57                   push edi
// 007a3a7b  8bd9                 mov ebx, ecx
// 007a3a7d  0f858c000000         jne 0x7a3b0f
// 007a3a83  8d70f8               lea esi, [eax - 8]
// 007a3a86  8d6808               lea ebp, [eax + 8]
// 007a3a89  3bf5                 cmp esi, ebp
// 007a3a8b  0f8daf010000         jge 0x7a3c40
// 007a3a91  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007a3a95  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007a3a99  8d4e01               lea ecx, [esi + 1]
// 007a3a9c  894c2410             mov dword ptr [esp + 0x10], ecx
// 007a3aa0  8d5004               lea edx, [eax + 4]
// 007a3aa3  8d4e03               lea ecx, [esi + 3]
// 007a3aa6  894c2418             mov dword ptr [esp + 0x18], ecx
// 007a3aaa  83c006               add eax, 6
// 007a3aad  6a05                 push 5
// 007a3aaf  8bcb                 mov ecx, ebx
// 007a3ab1  89542418             mov dword ptr [esp + 0x18], edx
// 007a3ab5  89442420             mov dword ptr [esp + 0x20], eax
// 007a3ab9  e8c2ecf7ff           call 0x722780
// 007a3abe  50                   push eax
// 007a3abf  8d542414             lea edx, [esp + 0x14]
// 007a3ac3  52                   push edx
// 007a3ac4  8bcf                 mov ecx, edi
// 007a3ac6  e8055df7ff           call 0x7197d0
// 007a3acb  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 007a3acf  8d4803               lea ecx, [eax + 3]
// 007a3ad2  894c2424             mov dword ptr [esp + 0x24], ecx
// 007a3ad6  8d5602               lea edx, [esi + 2]
// 007a3ad9  83c005               add eax, 5
// 007a3adc  6a26                 push 0x26
// 007a3ade  8bcb                 mov ecx, ebx
// 007a3ae0  89742424             mov dword ptr [esp + 0x24], esi
// 007a3ae4  8954242c             mov dword ptr [esp + 0x2c], edx
// 007a3ae8  89442430             mov dword ptr [esp + 0x30], eax
// 007a3aec  e88fecf7ff           call 0x722780
// 007a3af1  50                   push eax
// 007a3af2  8d442424             lea eax, [esp + 0x24]
// 007a3af6  50                   push eax
// 007a3af7  8bcf                 mov ecx, edi
// 007a3af9  e8d25cf7ff           call 0x7197d0
// 007a3afe  83c604               add esi, 4
// 007a3b01  3bf5                 cmp esi, ebp
// 007a3b03  7c90                 jl 0x7a3a95
// 007a3b05  5f                   pop edi
// 007a3b06  5e                   pop esi
// 007a3b07  5d                   pop ebp
// 007a3b08  5b                   pop ebx
// 007a3b09  83c420               add esp, 0x20
// 007a3b0c  c21800               ret 0x18
// 007a3b0f  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 007a3b13  83c7fc               add edi, -4
// 007a3b16  83c6fc               add esi, -4
// 007a3b19  8d4701               lea eax, [edi + 1]
// 007a3b1c  8d4e01               lea ecx, [esi + 1]
// 007a3b1f  89442424             mov dword ptr [esp + 0x24], eax
// 007a3b23  894c2420             mov dword ptr [esp + 0x20], ecx
// 007a3b27  8d5603               lea edx, [esi + 3]
// 007a3b2a  8d4703               lea eax, [edi + 3]
// 007a3b2d  6a05                 push 5
// 007a3b2f  8bcb                 mov ecx, ebx
// 007a3b31  8954242c             mov dword ptr [esp + 0x2c], edx
// 007a3b35  89442430             mov dword ptr [esp + 0x30], eax
// 007a3b39  e842ecf7ff           call 0x722780
// 007a3b3e  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 007a3b42  50                   push eax
// 007a3b43  8d442424             lea eax, [esp + 0x24]
// 007a3b47  50                   push eax
// 007a3b48  8bcd                 mov ecx, ebp
// 007a3b4a  e8815cf7ff           call 0x7197d0
// 007a3b4f  8d4e02               lea ecx, [esi + 2]
// 007a3b52  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a3b56  8d4702               lea eax, [edi + 2]
// 007a3b59  6a26                 push 0x26
// 007a3b5b  8bcb                 mov ecx, ebx
// 007a3b5d  89742424             mov dword ptr [esp + 0x24], esi
// 007a3b61  897c2428             mov dword ptr [esp + 0x28], edi
// 007a3b65  89442430             mov dword ptr [esp + 0x30], eax
// 007a3b69  e812ecf7ff           call 0x722780
// 007a3b6e  50                   push eax
// 007a3b6f  8d542424             lea edx, [esp + 0x24]
// 007a3b73  52                   push edx
// 007a3b74  8bcd                 mov ecx, ebp
// 007a3b76  e8555cf7ff           call 0x7197d0
// 007a3b7b  83ee04               sub esi, 4
// 007a3b7e  8d4601               lea eax, [esi + 1]
// 007a3b81  89442420             mov dword ptr [esp + 0x20], eax
// 007a3b85  8d4701               lea eax, [edi + 1]
// 007a3b88  8d4e03               lea ecx, [esi + 3]
// 007a3b8b  89442424             mov dword ptr [esp + 0x24], eax
// 007a3b8f  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a3b93  8d4703               lea eax, [edi + 3]
// 007a3b96  6a05                 push 5
// 007a3b98  8bcb                 mov ecx, ebx
// 007a3b9a  89442430             mov dword ptr [esp + 0x30], eax
// 007a3b9e  e8ddebf7ff           call 0x722780
// 007a3ba3  50                   push eax
// 007a3ba4  8d542424             lea edx, [esp + 0x24]
// 007a3ba8  52                   push edx
// 007a3ba9  8bcd                 mov ecx, ebp
// 007a3bab  e8205cf7ff           call 0x7197d0
// 007a3bb0  8d4602               lea eax, [esi + 2]
// 007a3bb3  89442428             mov dword ptr [esp + 0x28], eax
// 007a3bb7  8d4702               lea eax, [edi + 2]
// 007a3bba  6a26                 push 0x26
// 007a3bbc  8bcb                 mov ecx, ebx
// 007a3bbe  89742424             mov dword ptr [esp + 0x24], esi
// 007a3bc2  897c2428             mov dword ptr [esp + 0x28], edi
// 007a3bc6  89442430             mov dword ptr [esp + 0x30], eax
// 007a3bca  e8b1ebf7ff           call 0x722780
// 007a3bcf  50                   push eax
// 007a3bd0  8d4c2424             lea ecx, [esp + 0x24]
// 007a3bd4  51                   push ecx
// 007a3bd5  8bcd                 mov ecx, ebp
// 007a3bd7  e8f45bf7ff           call 0x7197d0
// 007a3bdc  83c604               add esi, 4
// 007a3bdf  83ef04               sub edi, 4
// 007a3be2  8d5601               lea edx, [esi + 1]
// 007a3be5  8d4e03               lea ecx, [esi + 3]
// 007a3be8  89542420             mov dword ptr [esp + 0x20], edx
// 007a3bec  8d4701               lea eax, [edi + 1]
// 007a3bef  894c2428             mov dword ptr [esp + 0x28], ecx
// 007a3bf3  8d5703               lea edx, [edi + 3]
// 007a3bf6  6a05                 push 5
// 007a3bf8  8bcb                 mov ecx, ebx
// 007a3bfa  89442428             mov dword ptr [esp + 0x28], eax
// 007a3bfe  89542430             mov dword ptr [esp + 0x30], edx
// 007a3c02  e879ebf7ff           call 0x722780
// 007a3c07  50                   push eax
// 007a3c08  8d442424             lea eax, [esp + 0x24]
// 007a3c0c  50                   push eax
// 007a3c0d  8bcd                 mov ecx, ebp
// 007a3c0f  e8bc5bf7ff           call 0x7197d0
// 007a3c14  89742420             mov dword ptr [esp + 0x20], esi
// 007a3c18  897c2424             mov dword ptr [esp + 0x24], edi
// 007a3c1c  83c602               add esi, 2
// 007a3c1f  83c702               add edi, 2
// 007a3c22  6a26                 push 0x26
// 007a3c24  8bcb                 mov ecx, ebx
// 007a3c26  8974242c             mov dword ptr [esp + 0x2c], esi
// 007a3c2a  897c2430             mov dword ptr [esp + 0x30], edi
// 007a3c2e  e84debf7ff           call 0x722780
// 007a3c33  50                   push eax
// 007a3c34  8d4c2424             lea ecx, [esp + 0x24]
// 007a3c38  51                   push ecx
// 007a3c39  8bcd                 mov ecx, ebp
// 007a3c3b  e8905bf7ff           call 0x7197d0
// 007a3c40  5f                   pop edi
// 007a3c41  5e                   pop esi
// 007a3c42  5d                   pop ebp
// 007a3c43  5b                   pop ebx
// 007a3c44  83c420               add esp, 0x20
// 007a3c47  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawPopupResizeGripper@CXTPDefaultTheme@@UAEXPAVCDC@@VCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDefaultTheme.cpp
