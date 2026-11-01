// from server: 100% by auto
// roc 2009-06 00743d70  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743d70
//
// 00743d70  53                   push ebx
// 00743d71  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00743d75  56                   push esi
// 00743d76  57                   push edi
// 00743d77  33ff                 xor edi, edi
// 00743d79  3bdf                 cmp ebx, edi
// 00743d7b  8bf1                 mov esi, ecx
// 00743d7d  7d05                 jge 0x743d84
// 00743d7f  e8604ffdff           call 0x718ce4
// 00743d84  8b442414             mov eax, dword ptr [esp + 0x14]
// 00743d88  3bc7                 cmp eax, edi
// 00743d8a  7c03                 jl 0x743d8f
// 00743d8c  894610               mov dword ptr [esi + 0x10], eax
// 00743d8f  3bdf                 cmp ebx, edi
// 00743d91  751f                 jne 0x743db2
// 00743d93  8b4604               mov eax, dword ptr [esi + 4]
// 00743d96  3bc7                 cmp eax, edi
// 00743d98  740c                 je 0x743da6
// 00743d9a  50                   push eax
// 00743d9b  e83e4ffdff           call 0x718cde
// 00743da0  83c404               add esp, 4
// 00743da3  897e04               mov dword ptr [esi + 4], edi
// 00743da6  897e0c               mov dword ptr [esi + 0xc], edi
// 00743da9  897e08               mov dword ptr [esi + 8], edi
// 00743dac  5f                   pop edi
// 00743dad  5e                   pop esi
// 00743dae  5b                   pop ebx
// 00743daf  c20800               ret 8
// 00743db2  8b5604               mov edx, dword ptr [esi + 4]
// 00743db5  55                   push ebp
// 00743db6  3bd7                 cmp edx, edi
// 00743db8  7533                 jne 0x743ded
// 00743dba  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 00743dbd  3bdd                 cmp ebx, ebp
// 00743dbf  7e02                 jle 0x743dc3
// 00743dc1  8beb                 mov ebp, ebx
// 00743dc3  8d7c6d00             lea edi, [ebp + ebp*2]
// 00743dc7  03ff                 add edi, edi
// 00743dc9  03ff                 add edi, edi
// 00743dcb  57                   push edi
// 00743dcc  e8494ffdff           call 0x718d1a
// 00743dd1  57                   push edi
// 00743dd2  6a00                 push 0
// 00743dd4  50                   push eax
// 00743dd5  894604               mov dword ptr [esi + 4], eax
// 00743dd8  e8975efdff           call 0x719c74
// 00743ddd  83c410               add esp, 0x10
// 00743de0  896e0c               mov dword ptr [esi + 0xc], ebp
// 00743de3  5d                   pop ebp
// 00743de4  5f                   pop edi
// 00743de5  895e08               mov dword ptr [esi + 8], ebx
// 00743de8  5e                   pop esi
// 00743de9  5b                   pop ebx
// 00743dea  c20800               ret 8
// 00743ded  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00743df0  3bd9                 cmp ebx, ecx
// 00743df2  7f31                 jg 0x743e25
// 00743df4  8b4e08               mov ecx, dword ptr [esi + 8]
// 00743df7  3bd9                 cmp ebx, ecx
// 00743df9  0f8ec6000000         jle 0x743ec5
// 00743dff  8bc3                 mov eax, ebx
// 00743e01  2bc1                 sub eax, ecx
// 00743e03  8d0440               lea eax, [eax + eax*2]
// 00743e06  03c0                 add eax, eax
// 00743e08  03c0                 add eax, eax
// 00743e0a  50                   push eax
// 00743e0b  8d0c49               lea ecx, [ecx + ecx*2]
// 00743e0e  8d148a               lea edx, [edx + ecx*4]
// 00743e11  57                   push edi
// 00743e12  52                   push edx
// 00743e13  e85c5efdff           call 0x719c74
// 00743e18  83c40c               add esp, 0xc
// 00743e1b  5d                   pop ebp
// 00743e1c  5f                   pop edi
// 00743e1d  895e08               mov dword ptr [esi + 8], ebx
// 00743e20  5e                   pop esi
// 00743e21  5b                   pop ebx
// 00743e22  c20800               ret 8
// 00743e25  8b4610               mov eax, dword ptr [esi + 0x10]
// 00743e28  3bc7                 cmp eax, edi
// 00743e2a  7524                 jne 0x743e50
// 00743e2c  8b4608               mov eax, dword ptr [esi + 8]
// 00743e2f  99                   cdq 
// 00743e30  83e207               and edx, 7
// 00743e33  03c2                 add eax, edx
// 00743e35  c1f803               sar eax, 3
// 00743e38  83f804               cmp eax, 4
// 00743e3b  7d07                 jge 0x743e44
// 00743e3d  b804000000           mov eax, 4
// 00743e42  eb0c                 jmp 0x743e50
// 00743e44  3d00040000           cmp eax, 0x400
// 00743e49  7e05                 jle 0x743e50
// 00743e4b  b800040000           mov eax, 0x400
// 00743e50  8d3c01               lea edi, [ecx + eax]
// 00743e53  3bdf                 cmp ebx, edi
// 00743e55  7d06                 jge 0x743e5d
// 00743e57  897c2414             mov dword ptr [esp + 0x14], edi
// 00743e5b  eb06                 jmp 0x743e63
// 00743e5d  895c2414             mov dword ptr [esp + 0x14], ebx
// 00743e61  8bfb                 mov edi, ebx
// 00743e63  3bf9                 cmp edi, ecx
// 00743e65  7d05                 jge 0x743e6c
// 00743e67  e8784efdff           call 0x718ce4
// 00743e6c  8d3c7f               lea edi, [edi + edi*2]
// 00743e6f  03ff                 add edi, edi
// 00743e71  03ff                 add edi, edi
// 00743e73  57                   push edi
// 00743e74  e8a14efdff           call 0x718d1a
// 00743e79  8b4e04               mov ecx, dword ptr [esi + 4]
// 00743e7c  8be8                 mov ebp, eax
// 00743e7e  8b4608               mov eax, dword ptr [esi + 8]
// 00743e81  8d0440               lea eax, [eax + eax*2]
// 00743e84  03c0                 add eax, eax
// 00743e86  03c0                 add eax, eax
// 00743e88  50                   push eax
// 00743e89  51                   push ecx
// 00743e8a  57                   push edi
// 00743e8b  55                   push ebp
// 00743e8c  e83ff0cbff           call 0x402ed0
// 00743e91  8b4e08               mov ecx, dword ptr [esi + 8]
// 00743e94  8bc3                 mov eax, ebx
// 00743e96  2bc1                 sub eax, ecx
// 00743e98  8d1440               lea edx, [eax + eax*2]
// 00743e9b  03d2                 add edx, edx
// 00743e9d  03d2                 add edx, edx
// 00743e9f  52                   push edx
// 00743ea0  8d0449               lea eax, [ecx + ecx*2]
// 00743ea3  8d4c8500             lea ecx, [ebp + eax*4]
// 00743ea7  6a00                 push 0
// 00743ea9  51                   push ecx
// 00743eaa  e8c55dfdff           call 0x719c74
// 00743eaf  8b5604               mov edx, dword ptr [esi + 4]
// 00743eb2  52                   push edx
// 00743eb3  e8264efdff           call 0x718cde
// 00743eb8  8b442438             mov eax, dword ptr [esp + 0x38]
// 00743ebc  83c424               add esp, 0x24
// 00743ebf  896e04               mov dword ptr [esi + 4], ebp
// 00743ec2  89460c               mov dword ptr [esi + 0xc], eax
// 00743ec5  5d                   pop ebp
// 00743ec6  5f                   pop edi
// 00743ec7  895e08               mov dword ptr [esi + 8], ebx
// 00743eca  5e                   pop esi
// 00743ecb  5b                   pop ebx
// 00743ecc  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPNotifyConnection.cpp (function ?SetSize@?$CArray@UCONNECTION_DESCRIPTOR@CXTPNotifyConnection@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPNotifyConnection.cpp
