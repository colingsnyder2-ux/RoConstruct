// from server: 100% by auto
// roc 2010-06 007d6b90  unit: CXTPReportControlLocale::UXTP_TIMESPEC::?$CArray  size: 560 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6b90
//
// 007d6b90  53                   push ebx
// 007d6b91  56                   push esi
// 007d6b92  57                   push edi
// 007d6b93  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d6b97  33db                 xor ebx, ebx
// 007d6b99  3bfb                 cmp edi, ebx
// 007d6b9b  8bf1                 mov esi, ecx
// 007d6b9d  7d05                 jge 0x7d6ba4
// 007d6b9f  e8a810fdff           call 0x7a7c4c
// 007d6ba4  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d6ba8  3bc3                 cmp eax, ebx
// 007d6baa  7c03                 jl 0x7d6baf
// 007d6bac  894610               mov dword ptr [esi + 0x10], eax
// 007d6baf  3bfb                 cmp edi, ebx
// 007d6bb1  753c                 jne 0x7d6bef
// 007d6bb3  395e04               cmp dword ptr [esi + 4], ebx
// 007d6bb6  742b                 je 0x7d6be3
// 007d6bb8  33ff                 xor edi, edi
// 007d6bba  395e08               cmp dword ptr [esi + 8], ebx
// 007d6bbd  7e15                 jle 0x7d6bd4
// 007d6bbf  90                   nop 
// 007d6bc0  8b4604               mov eax, dword ptr [esi + 4]
// 007d6bc3  8b14f8               mov edx, dword ptr [eax + edi*8]
// 007d6bc6  8d0cf8               lea ecx, [eax + edi*8]
// 007d6bc9  8b02                 mov eax, dword ptr [edx]
// 007d6bcb  53                   push ebx
// 007d6bcc  ffd0                 call eax
// 007d6bce  47                   inc edi
// 007d6bcf  3b7e08               cmp edi, dword ptr [esi + 8]
// 007d6bd2  7cec                 jl 0x7d6bc0
// 007d6bd4  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d6bd7  51                   push ecx
// 007d6bd8  e86910fdff           call 0x7a7c46
// 007d6bdd  83c404               add esp, 4
// 007d6be0  895e04               mov dword ptr [esi + 4], ebx
// 007d6be3  5f                   pop edi
// 007d6be4  895e0c               mov dword ptr [esi + 0xc], ebx
// 007d6be7  895e08               mov dword ptr [esi + 8], ebx
// 007d6bea  5e                   pop esi
// 007d6beb  5b                   pop ebx
// 007d6bec  c20800               ret 8
// 007d6bef  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d6bf2  55                   push ebp
// 007d6bf3  3bcb                 cmp ecx, ebx
// 007d6bf5  7553                 jne 0x7d6c4a
// 007d6bf7  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d6bfa  3bf8                 cmp edi, eax
// 007d6bfc  8bdf                 mov ebx, edi
// 007d6bfe  7f02                 jg 0x7d6c02
// 007d6c00  8bd8                 mov ebx, eax
// 007d6c02  8d2cdd00000000       lea ebp, [ebx*8]
// 007d6c09  55                   push ebp
// 007d6c0a  e87310fdff           call 0x7a7c82
// 007d6c0f  55                   push ebp
// 007d6c10  33ed                 xor ebp, ebp
// 007d6c12  55                   push ebp
// 007d6c13  50                   push eax
// 007d6c14  894604               mov dword ptr [esi + 4], eax
// 007d6c17  e8c81ffdff           call 0x7a8be4
// 007d6c1c  83c410               add esp, 0x10
// 007d6c1f  33c9                 xor ecx, ecx
// 007d6c21  3bfd                 cmp edi, ebp
// 007d6c23  7e18                 jle 0x7d6c3d
// 007d6c25  8b5604               mov edx, dword ptr [esi + 4]
// 007d6c28  8d04ca               lea eax, [edx + ecx*8]
// 007d6c2b  3bc5                 cmp eax, ebp
// 007d6c2d  7409                 je 0x7d6c38
// 007d6c2f  c7008493a500         mov dword ptr [eax], 0xa59384
// 007d6c35  896804               mov dword ptr [eax + 4], ebp
// 007d6c38  41                   inc ecx
// 007d6c39  3bcf                 cmp ecx, edi
// 007d6c3b  7ce8                 jl 0x7d6c25
// 007d6c3d  5d                   pop ebp
// 007d6c3e  897e08               mov dword ptr [esi + 8], edi
// 007d6c41  5f                   pop edi
// 007d6c42  895e0c               mov dword ptr [esi + 0xc], ebx
// 007d6c45  5e                   pop esi
// 007d6c46  5b                   pop ebx
// 007d6c47  c20800               ret 8
// 007d6c4a  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007d6c4d  3bfd                 cmp edi, ebp
// 007d6c4f  0f8f96000000         jg 0x7d6ceb
// 007d6c55  8b4608               mov eax, dword ptr [esi + 8]
// 007d6c58  3bc7                 cmp eax, edi
// 007d6c5a  7d53                 jge 0x7d6caf
// 007d6c5c  8bd7                 mov edx, edi
// 007d6c5e  2bd0                 sub edx, eax
// 007d6c60  03d2                 add edx, edx
// 007d6c62  03d2                 add edx, edx
// 007d6c64  03d2                 add edx, edx
// 007d6c66  52                   push edx
// 007d6c67  8d04c1               lea eax, [ecx + eax*8]
// 007d6c6a  53                   push ebx
// 007d6c6b  50                   push eax
// 007d6c6c  e8731ffdff           call 0x7a8be4
// 007d6c71  8bd7                 mov edx, edi
// 007d6c73  2b5608               sub edx, dword ptr [esi + 8]
// 007d6c76  83c40c               add esp, 0xc
// 007d6c79  33c9                 xor ecx, ecx
// 007d6c7b  85d2                 test edx, edx
// 007d6c7d  0f8e33010000         jle 0x7d6db6
// 007d6c83  8b4608               mov eax, dword ptr [esi + 8]
// 007d6c86  8b5604               mov edx, dword ptr [esi + 4]
// 007d6c89  03c1                 add eax, ecx
// 007d6c8b  8d04c2               lea eax, [edx + eax*8]
// 007d6c8e  3bc3                 cmp eax, ebx
// 007d6c90  7409                 je 0x7d6c9b
// 007d6c92  c7008493a500         mov dword ptr [eax], 0xa59384
// 007d6c98  895804               mov dword ptr [eax + 4], ebx
// 007d6c9b  8bc7                 mov eax, edi
// 007d6c9d  2b4608               sub eax, dword ptr [esi + 8]
// 007d6ca0  41                   inc ecx
// 007d6ca1  3bc8                 cmp ecx, eax
// 007d6ca3  7cde                 jl 0x7d6c83
// 007d6ca5  5d                   pop ebp
// 007d6ca6  897e08               mov dword ptr [esi + 8], edi
// 007d6ca9  5f                   pop edi
// 007d6caa  5e                   pop esi
// 007d6cab  5b                   pop ebx
// 007d6cac  c20800               ret 8
// 007d6caf  0f8e01010000         jle 0x7d6db6
// 007d6cb5  2bc7                 sub eax, edi
// 007d6cb7  85c0                 test eax, eax
// 007d6cb9  0f8ef7000000         jle 0x7d6db6
// 007d6cbf  8d2cfd00000000       lea ebp, [edi*8]
// 007d6cc6  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d6cc9  8b1429               mov edx, dword ptr [ecx + ebp]
// 007d6ccc  8b02                 mov eax, dword ptr [edx]
// 007d6cce  03cd                 add ecx, ebp
// 007d6cd0  6a00                 push 0
// 007d6cd2  ffd0                 call eax
// 007d6cd4  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d6cd7  43                   inc ebx
// 007d6cd8  2bcf                 sub ecx, edi
// 007d6cda  83c508               add ebp, 8
// 007d6cdd  3bd9                 cmp ebx, ecx
// 007d6cdf  7ce5                 jl 0x7d6cc6
// 007d6ce1  5d                   pop ebp
// 007d6ce2  897e08               mov dword ptr [esi + 8], edi
// 007d6ce5  5f                   pop edi
// 007d6ce6  5e                   pop esi
// 007d6ce7  5b                   pop ebx
// 007d6ce8  c20800               ret 8
// 007d6ceb  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d6cee  3bc3                 cmp eax, ebx
// 007d6cf0  7524                 jne 0x7d6d16
// 007d6cf2  8b4608               mov eax, dword ptr [esi + 8]
// 007d6cf5  99                   cdq 
// 007d6cf6  83e207               and edx, 7
// 007d6cf9  03c2                 add eax, edx
// 007d6cfb  c1f803               sar eax, 3
// 007d6cfe  83f804               cmp eax, 4
// 007d6d01  7d07                 jge 0x7d6d0a
// 007d6d03  b804000000           mov eax, 4
// 007d6d08  eb0c                 jmp 0x7d6d16
// 007d6d0a  3d00040000           cmp eax, 0x400
// 007d6d0f  7e05                 jle 0x7d6d16
// 007d6d11  b800040000           mov eax, 0x400
// 007d6d16  03c5                 add eax, ebp
// 007d6d18  3bf8                 cmp edi, eax
// 007d6d1a  7d06                 jge 0x7d6d22
// 007d6d1c  89442414             mov dword ptr [esp + 0x14], eax
// 007d6d20  eb06                 jmp 0x7d6d28
// 007d6d22  897c2414             mov dword ptr [esp + 0x14], edi
// 007d6d26  8bc7                 mov eax, edi
// 007d6d28  3bc5                 cmp eax, ebp
// 007d6d2a  7d05                 jge 0x7d6d31
// 007d6d2c  e81b0ffdff           call 0x7a7c4c
// 007d6d31  8d1cc500000000       lea ebx, [eax*8]
// 007d6d38  53                   push ebx
// 007d6d39  e8440ffdff           call 0x7a7c82
// 007d6d3e  8b5608               mov edx, dword ptr [esi + 8]
// 007d6d41  03d2                 add edx, edx
// 007d6d43  03d2                 add edx, edx
// 007d6d45  8be8                 mov ebp, eax
// 007d6d47  8b4604               mov eax, dword ptr [esi + 4]
// 007d6d4a  03d2                 add edx, edx
// 007d6d4c  52                   push edx
// 007d6d4d  50                   push eax
// 007d6d4e  53                   push ebx
// 007d6d4f  55                   push ebp
// 007d6d50  e89bbec2ff           call 0x402bf0
// 007d6d55  8b4608               mov eax, dword ptr [esi + 8]
// 007d6d58  8bcf                 mov ecx, edi
// 007d6d5a  2bc8                 sub ecx, eax
// 007d6d5c  03c9                 add ecx, ecx
// 007d6d5e  03c9                 add ecx, ecx
// 007d6d60  03c9                 add ecx, ecx
// 007d6d62  51                   push ecx
// 007d6d63  33db                 xor ebx, ebx
// 007d6d65  8d54c500             lea edx, [ebp + eax*8]
// 007d6d69  53                   push ebx
// 007d6d6a  52                   push edx
// 007d6d6b  e8741efdff           call 0x7a8be4
// 007d6d70  8bc7                 mov eax, edi
// 007d6d72  2b4608               sub eax, dword ptr [esi + 8]
// 007d6d75  83c420               add esp, 0x20
// 007d6d78  33c9                 xor ecx, ecx
// 007d6d7a  85c0                 test eax, eax
// 007d6d7c  7e22                 jle 0x7d6da0
// 007d6d7e  8bff                 mov edi, edi
// 007d6d80  8b5608               mov edx, dword ptr [esi + 8]
// 007d6d83  03d1                 add edx, ecx
// 007d6d85  8d44d500             lea eax, [ebp + edx*8]
// 007d6d89  3bc3                 cmp eax, ebx
// 007d6d8b  7409                 je 0x7d6d96
// 007d6d8d  c7008493a500         mov dword ptr [eax], 0xa59384
// 007d6d93  895804               mov dword ptr [eax + 4], ebx
// 007d6d96  8bc7                 mov eax, edi
// 007d6d98  2b4608               sub eax, dword ptr [esi + 8]
// 007d6d9b  41                   inc ecx
// 007d6d9c  3bc8                 cmp ecx, eax
// 007d6d9e  7ce0                 jl 0x7d6d80
// 007d6da0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d6da3  51                   push ecx
// 007d6da4  e89d0efdff           call 0x7a7c46
// 007d6da9  8b542418             mov edx, dword ptr [esp + 0x18]
// 007d6dad  83c404               add esp, 4
// 007d6db0  896e04               mov dword ptr [esi + 4], ebp
// 007d6db3  89560c               mov dword ptr [esi + 0xc], edx
// 007d6db6  5d                   pop ebp
// 007d6db7  897e08               mov dword ptr [esi + 8], edi
// 007d6dba  5f                   pop edi
// 007d6dbb  5e                   pop esi
// 007d6dbc  5b                   pop ebx
// 007d6dbd  c20800               ret 8
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ?SetSize@?$CArray@V?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@AAV1@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
