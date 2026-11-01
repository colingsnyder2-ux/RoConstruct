// from server: 100% by auto
// roc 2009-12 00822b30  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 560 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00822b30
//
// 00822b30  53                   push ebx
// 00822b31  56                   push esi
// 00822b32  57                   push edi
// 00822b33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00822b37  33db                 xor ebx, ebx
// 00822b39  3bfb                 cmp edi, ebx
// 00822b3b  8bf1                 mov esi, ecx
// 00822b3d  7d05                 jge 0x822b44
// 00822b3f  e8c80ffdff           call 0x7f3b0c
// 00822b44  8b442414             mov eax, dword ptr [esp + 0x14]
// 00822b48  3bc3                 cmp eax, ebx
// 00822b4a  7c03                 jl 0x822b4f
// 00822b4c  894610               mov dword ptr [esi + 0x10], eax
// 00822b4f  3bfb                 cmp edi, ebx
// 00822b51  753c                 jne 0x822b8f
// 00822b53  395e04               cmp dword ptr [esi + 4], ebx
// 00822b56  742b                 je 0x822b83
// 00822b58  33ff                 xor edi, edi
// 00822b5a  395e08               cmp dword ptr [esi + 8], ebx
// 00822b5d  7e15                 jle 0x822b74
// 00822b5f  90                   nop 
// 00822b60  8b4604               mov eax, dword ptr [esi + 4]
// 00822b63  8b14f8               mov edx, dword ptr [eax + edi*8]
// 00822b66  8d0cf8               lea ecx, [eax + edi*8]
// 00822b69  8b02                 mov eax, dword ptr [edx]
// 00822b6b  53                   push ebx
// 00822b6c  ffd0                 call eax
// 00822b6e  47                   inc edi
// 00822b6f  3b7e08               cmp edi, dword ptr [esi + 8]
// 00822b72  7cec                 jl 0x822b60
// 00822b74  8b4e04               mov ecx, dword ptr [esi + 4]
// 00822b77  51                   push ecx
// 00822b78  e8890ffdff           call 0x7f3b06
// 00822b7d  83c404               add esp, 4
// 00822b80  895e04               mov dword ptr [esi + 4], ebx
// 00822b83  5f                   pop edi
// 00822b84  895e0c               mov dword ptr [esi + 0xc], ebx
// 00822b87  895e08               mov dword ptr [esi + 8], ebx
// 00822b8a  5e                   pop esi
// 00822b8b  5b                   pop ebx
// 00822b8c  c20800               ret 8
// 00822b8f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00822b92  55                   push ebp
// 00822b93  3bcb                 cmp ecx, ebx
// 00822b95  7553                 jne 0x822bea
// 00822b97  8b4610               mov eax, dword ptr [esi + 0x10]
// 00822b9a  3bf8                 cmp edi, eax
// 00822b9c  8bdf                 mov ebx, edi
// 00822b9e  7f02                 jg 0x822ba2
// 00822ba0  8bd8                 mov ebx, eax
// 00822ba2  8d2cdd00000000       lea ebp, [ebx*8]
// 00822ba9  55                   push ebp
// 00822baa  e8930ffdff           call 0x7f3b42
// 00822baf  55                   push ebp
// 00822bb0  33ed                 xor ebp, ebp
// 00822bb2  55                   push ebp
// 00822bb3  50                   push eax
// 00822bb4  894604               mov dword ptr [esi + 4], eax
// 00822bb7  e8e81efdff           call 0x7f4aa4
// 00822bbc  83c410               add esp, 0x10
// 00822bbf  33c9                 xor ecx, ecx
// 00822bc1  3bfd                 cmp edi, ebp
// 00822bc3  7e18                 jle 0x822bdd
// 00822bc5  8b5604               mov edx, dword ptr [esi + 4]
// 00822bc8  8d04ca               lea eax, [edx + ecx*8]
// 00822bcb  3bc5                 cmp eax, ebp
// 00822bcd  7409                 je 0x822bd8
// 00822bcf  c70094509f00         mov dword ptr [eax], 0x9f5094
// 00822bd5  896804               mov dword ptr [eax + 4], ebp
// 00822bd8  41                   inc ecx
// 00822bd9  3bcf                 cmp ecx, edi
// 00822bdb  7ce8                 jl 0x822bc5
// 00822bdd  5d                   pop ebp
// 00822bde  897e08               mov dword ptr [esi + 8], edi
// 00822be1  5f                   pop edi
// 00822be2  895e0c               mov dword ptr [esi + 0xc], ebx
// 00822be5  5e                   pop esi
// 00822be6  5b                   pop ebx
// 00822be7  c20800               ret 8
// 00822bea  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00822bed  3bfd                 cmp edi, ebp
// 00822bef  0f8f96000000         jg 0x822c8b
// 00822bf5  8b4608               mov eax, dword ptr [esi + 8]
// 00822bf8  3bc7                 cmp eax, edi
// 00822bfa  7d53                 jge 0x822c4f
// 00822bfc  8bd7                 mov edx, edi
// 00822bfe  2bd0                 sub edx, eax
// 00822c00  03d2                 add edx, edx
// 00822c02  03d2                 add edx, edx
// 00822c04  03d2                 add edx, edx
// 00822c06  52                   push edx
// 00822c07  8d04c1               lea eax, [ecx + eax*8]
// 00822c0a  53                   push ebx
// 00822c0b  50                   push eax
// 00822c0c  e8931efdff           call 0x7f4aa4
// 00822c11  8bd7                 mov edx, edi
// 00822c13  2b5608               sub edx, dword ptr [esi + 8]
// 00822c16  83c40c               add esp, 0xc
// 00822c19  33c9                 xor ecx, ecx
// 00822c1b  85d2                 test edx, edx
// 00822c1d  0f8e33010000         jle 0x822d56
// 00822c23  8b4608               mov eax, dword ptr [esi + 8]
// 00822c26  8b5604               mov edx, dword ptr [esi + 4]
// 00822c29  03c1                 add eax, ecx
// 00822c2b  8d04c2               lea eax, [edx + eax*8]
// 00822c2e  3bc3                 cmp eax, ebx
// 00822c30  7409                 je 0x822c3b
// 00822c32  c70094509f00         mov dword ptr [eax], 0x9f5094
// 00822c38  895804               mov dword ptr [eax + 4], ebx
// 00822c3b  8bc7                 mov eax, edi
// 00822c3d  2b4608               sub eax, dword ptr [esi + 8]
// 00822c40  41                   inc ecx
// 00822c41  3bc8                 cmp ecx, eax
// 00822c43  7cde                 jl 0x822c23
// 00822c45  5d                   pop ebp
// 00822c46  897e08               mov dword ptr [esi + 8], edi
// 00822c49  5f                   pop edi
// 00822c4a  5e                   pop esi
// 00822c4b  5b                   pop ebx
// 00822c4c  c20800               ret 8
// 00822c4f  0f8e01010000         jle 0x822d56
// 00822c55  2bc7                 sub eax, edi
// 00822c57  85c0                 test eax, eax
// 00822c59  0f8ef7000000         jle 0x822d56
// 00822c5f  8d2cfd00000000       lea ebp, [edi*8]
// 00822c66  8b4e04               mov ecx, dword ptr [esi + 4]
// 00822c69  8b1429               mov edx, dword ptr [ecx + ebp]
// 00822c6c  8b02                 mov eax, dword ptr [edx]
// 00822c6e  03cd                 add ecx, ebp
// 00822c70  6a00                 push 0
// 00822c72  ffd0                 call eax
// 00822c74  8b4e08               mov ecx, dword ptr [esi + 8]
// 00822c77  43                   inc ebx
// 00822c78  2bcf                 sub ecx, edi
// 00822c7a  83c508               add ebp, 8
// 00822c7d  3bd9                 cmp ebx, ecx
// 00822c7f  7ce5                 jl 0x822c66
// 00822c81  5d                   pop ebp
// 00822c82  897e08               mov dword ptr [esi + 8], edi
// 00822c85  5f                   pop edi
// 00822c86  5e                   pop esi
// 00822c87  5b                   pop ebx
// 00822c88  c20800               ret 8
// 00822c8b  8b4610               mov eax, dword ptr [esi + 0x10]
// 00822c8e  3bc3                 cmp eax, ebx
// 00822c90  7524                 jne 0x822cb6
// 00822c92  8b4608               mov eax, dword ptr [esi + 8]
// 00822c95  99                   cdq 
// 00822c96  83e207               and edx, 7
// 00822c99  03c2                 add eax, edx
// 00822c9b  c1f803               sar eax, 3
// 00822c9e  83f804               cmp eax, 4
// 00822ca1  7d07                 jge 0x822caa
// 00822ca3  b804000000           mov eax, 4
// 00822ca8  eb0c                 jmp 0x822cb6
// 00822caa  3d00040000           cmp eax, 0x400
// 00822caf  7e05                 jle 0x822cb6
// 00822cb1  b800040000           mov eax, 0x400
// 00822cb6  03c5                 add eax, ebp
// 00822cb8  3bf8                 cmp edi, eax
// 00822cba  7d06                 jge 0x822cc2
// 00822cbc  89442414             mov dword ptr [esp + 0x14], eax
// 00822cc0  eb06                 jmp 0x822cc8
// 00822cc2  897c2414             mov dword ptr [esp + 0x14], edi
// 00822cc6  8bc7                 mov eax, edi
// 00822cc8  3bc5                 cmp eax, ebp
// 00822cca  7d05                 jge 0x822cd1
// 00822ccc  e83b0efdff           call 0x7f3b0c
// 00822cd1  8d1cc500000000       lea ebx, [eax*8]
// 00822cd8  53                   push ebx
// 00822cd9  e8640efdff           call 0x7f3b42
// 00822cde  8b5608               mov edx, dword ptr [esi + 8]
// 00822ce1  03d2                 add edx, edx
// 00822ce3  03d2                 add edx, edx
// 00822ce5  8be8                 mov ebp, eax
// 00822ce7  8b4604               mov eax, dword ptr [esi + 4]
// 00822cea  03d2                 add edx, edx
// 00822cec  52                   push edx
// 00822ced  50                   push eax
// 00822cee  53                   push ebx
// 00822cef  55                   push ebp
// 00822cf0  e8abfebdff           call 0x402ba0
// 00822cf5  8b4608               mov eax, dword ptr [esi + 8]
// 00822cf8  8bcf                 mov ecx, edi
// 00822cfa  2bc8                 sub ecx, eax
// 00822cfc  03c9                 add ecx, ecx
// 00822cfe  03c9                 add ecx, ecx
// 00822d00  03c9                 add ecx, ecx
// 00822d02  51                   push ecx
// 00822d03  33db                 xor ebx, ebx
// 00822d05  8d54c500             lea edx, [ebp + eax*8]
// 00822d09  53                   push ebx
// 00822d0a  52                   push edx
// 00822d0b  e8941dfdff           call 0x7f4aa4
// 00822d10  8bc7                 mov eax, edi
// 00822d12  2b4608               sub eax, dword ptr [esi + 8]
// 00822d15  83c420               add esp, 0x20
// 00822d18  33c9                 xor ecx, ecx
// 00822d1a  85c0                 test eax, eax
// 00822d1c  7e22                 jle 0x822d40
// 00822d1e  8bff                 mov edi, edi
// 00822d20  8b5608               mov edx, dword ptr [esi + 8]
// 00822d23  03d1                 add edx, ecx
// 00822d25  8d44d500             lea eax, [ebp + edx*8]
// 00822d29  3bc3                 cmp eax, ebx
// 00822d2b  7409                 je 0x822d36
// 00822d2d  c70094509f00         mov dword ptr [eax], 0x9f5094
// 00822d33  895804               mov dword ptr [eax + 4], ebx
// 00822d36  8bc7                 mov eax, edi
// 00822d38  2b4608               sub eax, dword ptr [esi + 8]
// 00822d3b  41                   inc ecx
// 00822d3c  3bc8                 cmp ecx, eax
// 00822d3e  7ce0                 jl 0x822d20
// 00822d40  8b4e04               mov ecx, dword ptr [esi + 4]
// 00822d43  51                   push ecx
// 00822d44  e8bd0dfdff           call 0x7f3b06
// 00822d49  8b542418             mov edx, dword ptr [esp + 0x18]
// 00822d4d  83c404               add esp, 4
// 00822d50  896e04               mov dword ptr [esi + 4], ebp
// 00822d53  89560c               mov dword ptr [esi + 0xc], edx
// 00822d56  5d                   pop ebp
// 00822d57  897e08               mov dword ptr [esi + 8], edi
// 00822d5a  5f                   pop edi
// 00822d5b  5e                   pop esi
// 00822d5c  5b                   pop ebx
// 00822d5d  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?SetSize@?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
