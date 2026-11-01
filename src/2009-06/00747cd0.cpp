// from server: 100% by auto
// roc 2009-06 00747cd0  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 560 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747cd0
//
// 00747cd0  53                   push ebx
// 00747cd1  56                   push esi
// 00747cd2  57                   push edi
// 00747cd3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00747cd7  33db                 xor ebx, ebx
// 00747cd9  3bfb                 cmp edi, ebx
// 00747cdb  8bf1                 mov esi, ecx
// 00747cdd  7d05                 jge 0x747ce4
// 00747cdf  e80010fdff           call 0x718ce4
// 00747ce4  8b442414             mov eax, dword ptr [esp + 0x14]
// 00747ce8  3bc3                 cmp eax, ebx
// 00747cea  7c03                 jl 0x747cef
// 00747cec  894610               mov dword ptr [esi + 0x10], eax
// 00747cef  3bfb                 cmp edi, ebx
// 00747cf1  753c                 jne 0x747d2f
// 00747cf3  395e04               cmp dword ptr [esi + 4], ebx
// 00747cf6  742b                 je 0x747d23
// 00747cf8  33ff                 xor edi, edi
// 00747cfa  395e08               cmp dword ptr [esi + 8], ebx
// 00747cfd  7e15                 jle 0x747d14
// 00747cff  90                   nop 
// 00747d00  8b4604               mov eax, dword ptr [esi + 4]
// 00747d03  8b14f8               mov edx, dword ptr [eax + edi*8]
// 00747d06  8d0cf8               lea ecx, [eax + edi*8]
// 00747d09  8b02                 mov eax, dword ptr [edx]
// 00747d0b  53                   push ebx
// 00747d0c  ffd0                 call eax
// 00747d0e  47                   inc edi
// 00747d0f  3b7e08               cmp edi, dword ptr [esi + 8]
// 00747d12  7cec                 jl 0x747d00
// 00747d14  8b4e04               mov ecx, dword ptr [esi + 4]
// 00747d17  51                   push ecx
// 00747d18  e8c10ffdff           call 0x718cde
// 00747d1d  83c404               add esp, 4
// 00747d20  895e04               mov dword ptr [esi + 4], ebx
// 00747d23  5f                   pop edi
// 00747d24  895e0c               mov dword ptr [esi + 0xc], ebx
// 00747d27  895e08               mov dword ptr [esi + 8], ebx
// 00747d2a  5e                   pop esi
// 00747d2b  5b                   pop ebx
// 00747d2c  c20800               ret 8
// 00747d2f  8b4e04               mov ecx, dword ptr [esi + 4]
// 00747d32  55                   push ebp
// 00747d33  3bcb                 cmp ecx, ebx
// 00747d35  7553                 jne 0x747d8a
// 00747d37  8b4610               mov eax, dword ptr [esi + 0x10]
// 00747d3a  3bf8                 cmp edi, eax
// 00747d3c  8bdf                 mov ebx, edi
// 00747d3e  7f02                 jg 0x747d42
// 00747d40  8bd8                 mov ebx, eax
// 00747d42  8d2cdd00000000       lea ebp, [ebx*8]
// 00747d49  55                   push ebp
// 00747d4a  e8cb0ffdff           call 0x718d1a
// 00747d4f  55                   push ebp
// 00747d50  33ed                 xor ebp, ebp
// 00747d52  55                   push ebp
// 00747d53  50                   push eax
// 00747d54  894604               mov dword ptr [esi + 4], eax
// 00747d57  e8181ffdff           call 0x719c74
// 00747d5c  83c410               add esp, 0x10
// 00747d5f  33c9                 xor ecx, ecx
// 00747d61  3bfd                 cmp edi, ebp
// 00747d63  7e18                 jle 0x747d7d
// 00747d65  8b5604               mov edx, dword ptr [esi + 4]
// 00747d68  8d04ca               lea eax, [edx + ecx*8]
// 00747d6b  3bc5                 cmp eax, ebp
// 00747d6d  7409                 je 0x747d78
// 00747d6f  c700ec4b8f00         mov dword ptr [eax], 0x8f4bec
// 00747d75  896804               mov dword ptr [eax + 4], ebp
// 00747d78  41                   inc ecx
// 00747d79  3bcf                 cmp ecx, edi
// 00747d7b  7ce8                 jl 0x747d65
// 00747d7d  5d                   pop ebp
// 00747d7e  897e08               mov dword ptr [esi + 8], edi
// 00747d81  5f                   pop edi
// 00747d82  895e0c               mov dword ptr [esi + 0xc], ebx
// 00747d85  5e                   pop esi
// 00747d86  5b                   pop ebx
// 00747d87  c20800               ret 8
// 00747d8a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00747d8d  3bfd                 cmp edi, ebp
// 00747d8f  0f8f96000000         jg 0x747e2b
// 00747d95  8b4608               mov eax, dword ptr [esi + 8]
// 00747d98  3bc7                 cmp eax, edi
// 00747d9a  7d53                 jge 0x747def
// 00747d9c  8bd7                 mov edx, edi
// 00747d9e  2bd0                 sub edx, eax
// 00747da0  03d2                 add edx, edx
// 00747da2  03d2                 add edx, edx
// 00747da4  03d2                 add edx, edx
// 00747da6  52                   push edx
// 00747da7  8d04c1               lea eax, [ecx + eax*8]
// 00747daa  53                   push ebx
// 00747dab  50                   push eax
// 00747dac  e8c31efdff           call 0x719c74
// 00747db1  8bd7                 mov edx, edi
// 00747db3  2b5608               sub edx, dword ptr [esi + 8]
// 00747db6  83c40c               add esp, 0xc
// 00747db9  33c9                 xor ecx, ecx
// 00747dbb  85d2                 test edx, edx
// 00747dbd  0f8e33010000         jle 0x747ef6
// 00747dc3  8b4608               mov eax, dword ptr [esi + 8]
// 00747dc6  8b5604               mov edx, dword ptr [esi + 4]
// 00747dc9  03c1                 add eax, ecx
// 00747dcb  8d04c2               lea eax, [edx + eax*8]
// 00747dce  3bc3                 cmp eax, ebx
// 00747dd0  7409                 je 0x747ddb
// 00747dd2  c700ec4b8f00         mov dword ptr [eax], 0x8f4bec
// 00747dd8  895804               mov dword ptr [eax + 4], ebx
// 00747ddb  8bc7                 mov eax, edi
// 00747ddd  2b4608               sub eax, dword ptr [esi + 8]
// 00747de0  41                   inc ecx
// 00747de1  3bc8                 cmp ecx, eax
// 00747de3  7cde                 jl 0x747dc3
// 00747de5  5d                   pop ebp
// 00747de6  897e08               mov dword ptr [esi + 8], edi
// 00747de9  5f                   pop edi
// 00747dea  5e                   pop esi
// 00747deb  5b                   pop ebx
// 00747dec  c20800               ret 8
// 00747def  0f8e01010000         jle 0x747ef6
// 00747df5  2bc7                 sub eax, edi
// 00747df7  85c0                 test eax, eax
// 00747df9  0f8ef7000000         jle 0x747ef6
// 00747dff  8d2cfd00000000       lea ebp, [edi*8]
// 00747e06  8b4e04               mov ecx, dword ptr [esi + 4]
// 00747e09  8b1429               mov edx, dword ptr [ecx + ebp]
// 00747e0c  8b02                 mov eax, dword ptr [edx]
// 00747e0e  03cd                 add ecx, ebp
// 00747e10  6a00                 push 0
// 00747e12  ffd0                 call eax
// 00747e14  8b4e08               mov ecx, dword ptr [esi + 8]
// 00747e17  43                   inc ebx
// 00747e18  2bcf                 sub ecx, edi
// 00747e1a  83c508               add ebp, 8
// 00747e1d  3bd9                 cmp ebx, ecx
// 00747e1f  7ce5                 jl 0x747e06
// 00747e21  5d                   pop ebp
// 00747e22  897e08               mov dword ptr [esi + 8], edi
// 00747e25  5f                   pop edi
// 00747e26  5e                   pop esi
// 00747e27  5b                   pop ebx
// 00747e28  c20800               ret 8
// 00747e2b  8b4610               mov eax, dword ptr [esi + 0x10]
// 00747e2e  3bc3                 cmp eax, ebx
// 00747e30  7524                 jne 0x747e56
// 00747e32  8b4608               mov eax, dword ptr [esi + 8]
// 00747e35  99                   cdq 
// 00747e36  83e207               and edx, 7
// 00747e39  03c2                 add eax, edx
// 00747e3b  c1f803               sar eax, 3
// 00747e3e  83f804               cmp eax, 4
// 00747e41  7d07                 jge 0x747e4a
// 00747e43  b804000000           mov eax, 4
// 00747e48  eb0c                 jmp 0x747e56
// 00747e4a  3d00040000           cmp eax, 0x400
// 00747e4f  7e05                 jle 0x747e56
// 00747e51  b800040000           mov eax, 0x400
// 00747e56  03c5                 add eax, ebp
// 00747e58  3bf8                 cmp edi, eax
// 00747e5a  7d06                 jge 0x747e62
// 00747e5c  89442414             mov dword ptr [esp + 0x14], eax
// 00747e60  eb06                 jmp 0x747e68
// 00747e62  897c2414             mov dword ptr [esp + 0x14], edi
// 00747e66  8bc7                 mov eax, edi
// 00747e68  3bc5                 cmp eax, ebp
// 00747e6a  7d05                 jge 0x747e71
// 00747e6c  e8730efdff           call 0x718ce4
// 00747e71  8d1cc500000000       lea ebx, [eax*8]
// 00747e78  53                   push ebx
// 00747e79  e89c0efdff           call 0x718d1a
// 00747e7e  8b5608               mov edx, dword ptr [esi + 8]
// 00747e81  03d2                 add edx, edx
// 00747e83  03d2                 add edx, edx
// 00747e85  8be8                 mov ebp, eax
// 00747e87  8b4604               mov eax, dword ptr [esi + 4]
// 00747e8a  03d2                 add edx, edx
// 00747e8c  52                   push edx
// 00747e8d  50                   push eax
// 00747e8e  53                   push ebx
// 00747e8f  55                   push ebp
// 00747e90  e83bb0cbff           call 0x402ed0
// 00747e95  8b4608               mov eax, dword ptr [esi + 8]
// 00747e98  8bcf                 mov ecx, edi
// 00747e9a  2bc8                 sub ecx, eax
// 00747e9c  03c9                 add ecx, ecx
// 00747e9e  03c9                 add ecx, ecx
// 00747ea0  03c9                 add ecx, ecx
// 00747ea2  51                   push ecx
// 00747ea3  33db                 xor ebx, ebx
// 00747ea5  8d54c500             lea edx, [ebp + eax*8]
// 00747ea9  53                   push ebx
// 00747eaa  52                   push edx
// 00747eab  e8c41dfdff           call 0x719c74
// 00747eb0  8bc7                 mov eax, edi
// 00747eb2  2b4608               sub eax, dword ptr [esi + 8]
// 00747eb5  83c420               add esp, 0x20
// 00747eb8  33c9                 xor ecx, ecx
// 00747eba  85c0                 test eax, eax
// 00747ebc  7e22                 jle 0x747ee0
// 00747ebe  8bff                 mov edi, edi
// 00747ec0  8b5608               mov edx, dword ptr [esi + 8]
// 00747ec3  03d1                 add edx, ecx
// 00747ec5  8d44d500             lea eax, [ebp + edx*8]
// 00747ec9  3bc3                 cmp eax, ebx
// 00747ecb  7409                 je 0x747ed6
// 00747ecd  c700ec4b8f00         mov dword ptr [eax], 0x8f4bec
// 00747ed3  895804               mov dword ptr [eax + 4], ebx
// 00747ed6  8bc7                 mov eax, edi
// 00747ed8  2b4608               sub eax, dword ptr [esi + 8]
// 00747edb  41                   inc ecx
// 00747edc  3bc8                 cmp ecx, eax
// 00747ede  7ce0                 jl 0x747ec0
// 00747ee0  8b4e04               mov ecx, dword ptr [esi + 4]
// 00747ee3  51                   push ecx
// 00747ee4  e8f50dfdff           call 0x718cde
// 00747ee9  8b542418             mov edx, dword ptr [esp + 0x18]
// 00747eed  83c404               add esp, 4
// 00747ef0  896e04               mov dword ptr [esi + 4], ebp
// 00747ef3  89560c               mov dword ptr [esi + 0xc], edx
// 00747ef6  5d                   pop ebp
// 00747ef7  897e08               mov dword ptr [esi + 8], edi
// 00747efa  5f                   pop edi
// 00747efb  5e                   pop esi
// 00747efc  5b                   pop ebx
// 00747efd  c20800               ret 8
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?SetSize@?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
