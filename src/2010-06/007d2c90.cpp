// from server: 100% by auto
// roc 2010-06 007d2c90  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2c90
//
// 007d2c90  53                   push ebx
// 007d2c91  8b5c2408             mov ebx, dword ptr [esp + 8]
// 007d2c95  56                   push esi
// 007d2c96  57                   push edi
// 007d2c97  33ff                 xor edi, edi
// 007d2c99  3bdf                 cmp ebx, edi
// 007d2c9b  8bf1                 mov esi, ecx
// 007d2c9d  7d05                 jge 0x7d2ca4
// 007d2c9f  e8a84ffdff           call 0x7a7c4c
// 007d2ca4  8b442414             mov eax, dword ptr [esp + 0x14]
// 007d2ca8  3bc7                 cmp eax, edi
// 007d2caa  7c03                 jl 0x7d2caf
// 007d2cac  894610               mov dword ptr [esi + 0x10], eax
// 007d2caf  3bdf                 cmp ebx, edi
// 007d2cb1  751f                 jne 0x7d2cd2
// 007d2cb3  8b4604               mov eax, dword ptr [esi + 4]
// 007d2cb6  3bc7                 cmp eax, edi
// 007d2cb8  740c                 je 0x7d2cc6
// 007d2cba  50                   push eax
// 007d2cbb  e8864ffdff           call 0x7a7c46
// 007d2cc0  83c404               add esp, 4
// 007d2cc3  897e04               mov dword ptr [esi + 4], edi
// 007d2cc6  897e0c               mov dword ptr [esi + 0xc], edi
// 007d2cc9  897e08               mov dword ptr [esi + 8], edi
// 007d2ccc  5f                   pop edi
// 007d2ccd  5e                   pop esi
// 007d2cce  5b                   pop ebx
// 007d2ccf  c20800               ret 8
// 007d2cd2  8b5604               mov edx, dword ptr [esi + 4]
// 007d2cd5  55                   push ebp
// 007d2cd6  3bd7                 cmp edx, edi
// 007d2cd8  7533                 jne 0x7d2d0d
// 007d2cda  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 007d2cdd  3bdd                 cmp ebx, ebp
// 007d2cdf  7e02                 jle 0x7d2ce3
// 007d2ce1  8beb                 mov ebp, ebx
// 007d2ce3  8d7c6d00             lea edi, [ebp + ebp*2]
// 007d2ce7  03ff                 add edi, edi
// 007d2ce9  03ff                 add edi, edi
// 007d2ceb  57                   push edi
// 007d2cec  e8914ffdff           call 0x7a7c82
// 007d2cf1  57                   push edi
// 007d2cf2  6a00                 push 0
// 007d2cf4  50                   push eax
// 007d2cf5  894604               mov dword ptr [esi + 4], eax
// 007d2cf8  e8e75efdff           call 0x7a8be4
// 007d2cfd  83c410               add esp, 0x10
// 007d2d00  896e0c               mov dword ptr [esi + 0xc], ebp
// 007d2d03  5d                   pop ebp
// 007d2d04  5f                   pop edi
// 007d2d05  895e08               mov dword ptr [esi + 8], ebx
// 007d2d08  5e                   pop esi
// 007d2d09  5b                   pop ebx
// 007d2d0a  c20800               ret 8
// 007d2d0d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d2d10  3bd9                 cmp ebx, ecx
// 007d2d12  7f31                 jg 0x7d2d45
// 007d2d14  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d2d17  3bd9                 cmp ebx, ecx
// 007d2d19  0f8ec6000000         jle 0x7d2de5
// 007d2d1f  8bc3                 mov eax, ebx
// 007d2d21  2bc1                 sub eax, ecx
// 007d2d23  8d0440               lea eax, [eax + eax*2]
// 007d2d26  03c0                 add eax, eax
// 007d2d28  03c0                 add eax, eax
// 007d2d2a  50                   push eax
// 007d2d2b  8d0c49               lea ecx, [ecx + ecx*2]
// 007d2d2e  8d148a               lea edx, [edx + ecx*4]
// 007d2d31  57                   push edi
// 007d2d32  52                   push edx
// 007d2d33  e8ac5efdff           call 0x7a8be4
// 007d2d38  83c40c               add esp, 0xc
// 007d2d3b  5d                   pop ebp
// 007d2d3c  5f                   pop edi
// 007d2d3d  895e08               mov dword ptr [esi + 8], ebx
// 007d2d40  5e                   pop esi
// 007d2d41  5b                   pop ebx
// 007d2d42  c20800               ret 8
// 007d2d45  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d2d48  3bc7                 cmp eax, edi
// 007d2d4a  7524                 jne 0x7d2d70
// 007d2d4c  8b4608               mov eax, dword ptr [esi + 8]
// 007d2d4f  99                   cdq 
// 007d2d50  83e207               and edx, 7
// 007d2d53  03c2                 add eax, edx
// 007d2d55  c1f803               sar eax, 3
// 007d2d58  83f804               cmp eax, 4
// 007d2d5b  7d07                 jge 0x7d2d64
// 007d2d5d  b804000000           mov eax, 4
// 007d2d62  eb0c                 jmp 0x7d2d70
// 007d2d64  3d00040000           cmp eax, 0x400
// 007d2d69  7e05                 jle 0x7d2d70
// 007d2d6b  b800040000           mov eax, 0x400
// 007d2d70  8d3c01               lea edi, [ecx + eax]
// 007d2d73  3bdf                 cmp ebx, edi
// 007d2d75  7d06                 jge 0x7d2d7d
// 007d2d77  897c2414             mov dword ptr [esp + 0x14], edi
// 007d2d7b  eb06                 jmp 0x7d2d83
// 007d2d7d  895c2414             mov dword ptr [esp + 0x14], ebx
// 007d2d81  8bfb                 mov edi, ebx
// 007d2d83  3bf9                 cmp edi, ecx
// 007d2d85  7d05                 jge 0x7d2d8c
// 007d2d87  e8c04efdff           call 0x7a7c4c
// 007d2d8c  8d3c7f               lea edi, [edi + edi*2]
// 007d2d8f  03ff                 add edi, edi
// 007d2d91  03ff                 add edi, edi
// 007d2d93  57                   push edi
// 007d2d94  e8e94efdff           call 0x7a7c82
// 007d2d99  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d2d9c  8be8                 mov ebp, eax
// 007d2d9e  8b4608               mov eax, dword ptr [esi + 8]
// 007d2da1  8d0440               lea eax, [eax + eax*2]
// 007d2da4  03c0                 add eax, eax
// 007d2da6  03c0                 add eax, eax
// 007d2da8  50                   push eax
// 007d2da9  51                   push ecx
// 007d2daa  57                   push edi
// 007d2dab  55                   push ebp
// 007d2dac  e83ffec2ff           call 0x402bf0
// 007d2db1  8b4e08               mov ecx, dword ptr [esi + 8]
// 007d2db4  8bc3                 mov eax, ebx
// 007d2db6  2bc1                 sub eax, ecx
// 007d2db8  8d1440               lea edx, [eax + eax*2]
// 007d2dbb  03d2                 add edx, edx
// 007d2dbd  03d2                 add edx, edx
// 007d2dbf  52                   push edx
// 007d2dc0  8d0449               lea eax, [ecx + ecx*2]
// 007d2dc3  8d4c8500             lea ecx, [ebp + eax*4]
// 007d2dc7  6a00                 push 0
// 007d2dc9  51                   push ecx
// 007d2dca  e8155efdff           call 0x7a8be4
// 007d2dcf  8b5604               mov edx, dword ptr [esi + 4]
// 007d2dd2  52                   push edx
// 007d2dd3  e86e4efdff           call 0x7a7c46
// 007d2dd8  8b442438             mov eax, dword ptr [esp + 0x38]
// 007d2ddc  83c424               add esp, 0x24
// 007d2ddf  896e04               mov dword ptr [esi + 4], ebp
// 007d2de2  89460c               mov dword ptr [esi + 0xc], eax
// 007d2de5  5d                   pop ebp
// 007d2de6  5f                   pop edi
// 007d2de7  895e08               mov dword ptr [esi + 8], ebx
// 007d2dea  5e                   pop esi
// 007d2deb  5b                   pop ebx
// 007d2dec  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPNotifyConnection.cpp (function ?SetSize@?$CArray@UCONNECTION_DESCRIPTOR@CXTPNotifyConnection@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPNotifyConnection.cpp
