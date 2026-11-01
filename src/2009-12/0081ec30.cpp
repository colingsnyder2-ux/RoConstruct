// from server: 100% by auto
// roc 2009-12 0081ec30  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 351 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081ec30
//
// 0081ec30  53                   push ebx
// 0081ec31  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0081ec35  56                   push esi
// 0081ec36  57                   push edi
// 0081ec37  33ff                 xor edi, edi
// 0081ec39  3bdf                 cmp ebx, edi
// 0081ec3b  8bf1                 mov esi, ecx
// 0081ec3d  7d05                 jge 0x81ec44
// 0081ec3f  e8c84efdff           call 0x7f3b0c
// 0081ec44  8b442414             mov eax, dword ptr [esp + 0x14]
// 0081ec48  3bc7                 cmp eax, edi
// 0081ec4a  7c03                 jl 0x81ec4f
// 0081ec4c  894610               mov dword ptr [esi + 0x10], eax
// 0081ec4f  3bdf                 cmp ebx, edi
// 0081ec51  751f                 jne 0x81ec72
// 0081ec53  8b4604               mov eax, dword ptr [esi + 4]
// 0081ec56  3bc7                 cmp eax, edi
// 0081ec58  740c                 je 0x81ec66
// 0081ec5a  50                   push eax
// 0081ec5b  e8a64efdff           call 0x7f3b06
// 0081ec60  83c404               add esp, 4
// 0081ec63  897e04               mov dword ptr [esi + 4], edi
// 0081ec66  897e0c               mov dword ptr [esi + 0xc], edi
// 0081ec69  897e08               mov dword ptr [esi + 8], edi
// 0081ec6c  5f                   pop edi
// 0081ec6d  5e                   pop esi
// 0081ec6e  5b                   pop ebx
// 0081ec6f  c20800               ret 8
// 0081ec72  8b5604               mov edx, dword ptr [esi + 4]
// 0081ec75  55                   push ebp
// 0081ec76  3bd7                 cmp edx, edi
// 0081ec78  7533                 jne 0x81ecad
// 0081ec7a  8b6e10               mov ebp, dword ptr [esi + 0x10]
// 0081ec7d  3bdd                 cmp ebx, ebp
// 0081ec7f  7e02                 jle 0x81ec83
// 0081ec81  8beb                 mov ebp, ebx
// 0081ec83  8d7c6d00             lea edi, [ebp + ebp*2]
// 0081ec87  03ff                 add edi, edi
// 0081ec89  03ff                 add edi, edi
// 0081ec8b  57                   push edi
// 0081ec8c  e8b14efdff           call 0x7f3b42
// 0081ec91  57                   push edi
// 0081ec92  6a00                 push 0
// 0081ec94  50                   push eax
// 0081ec95  894604               mov dword ptr [esi + 4], eax
// 0081ec98  e8075efdff           call 0x7f4aa4
// 0081ec9d  83c410               add esp, 0x10
// 0081eca0  896e0c               mov dword ptr [esi + 0xc], ebp
// 0081eca3  5d                   pop ebp
// 0081eca4  5f                   pop edi
// 0081eca5  895e08               mov dword ptr [esi + 8], ebx
// 0081eca8  5e                   pop esi
// 0081eca9  5b                   pop ebx
// 0081ecaa  c20800               ret 8
// 0081ecad  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0081ecb0  3bd9                 cmp ebx, ecx
// 0081ecb2  7f31                 jg 0x81ece5
// 0081ecb4  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081ecb7  3bd9                 cmp ebx, ecx
// 0081ecb9  0f8ec6000000         jle 0x81ed85
// 0081ecbf  8bc3                 mov eax, ebx
// 0081ecc1  2bc1                 sub eax, ecx
// 0081ecc3  8d0440               lea eax, [eax + eax*2]
// 0081ecc6  03c0                 add eax, eax
// 0081ecc8  03c0                 add eax, eax
// 0081ecca  50                   push eax
// 0081eccb  8d0c49               lea ecx, [ecx + ecx*2]
// 0081ecce  8d148a               lea edx, [edx + ecx*4]
// 0081ecd1  57                   push edi
// 0081ecd2  52                   push edx
// 0081ecd3  e8cc5dfdff           call 0x7f4aa4
// 0081ecd8  83c40c               add esp, 0xc
// 0081ecdb  5d                   pop ebp
// 0081ecdc  5f                   pop edi
// 0081ecdd  895e08               mov dword ptr [esi + 8], ebx
// 0081ece0  5e                   pop esi
// 0081ece1  5b                   pop ebx
// 0081ece2  c20800               ret 8
// 0081ece5  8b4610               mov eax, dword ptr [esi + 0x10]
// 0081ece8  3bc7                 cmp eax, edi
// 0081ecea  7524                 jne 0x81ed10
// 0081ecec  8b4608               mov eax, dword ptr [esi + 8]
// 0081ecef  99                   cdq 
// 0081ecf0  83e207               and edx, 7
// 0081ecf3  03c2                 add eax, edx
// 0081ecf5  c1f803               sar eax, 3
// 0081ecf8  83f804               cmp eax, 4
// 0081ecfb  7d07                 jge 0x81ed04
// 0081ecfd  b804000000           mov eax, 4
// 0081ed02  eb0c                 jmp 0x81ed10
// 0081ed04  3d00040000           cmp eax, 0x400
// 0081ed09  7e05                 jle 0x81ed10
// 0081ed0b  b800040000           mov eax, 0x400
// 0081ed10  8d3c01               lea edi, [ecx + eax]
// 0081ed13  3bdf                 cmp ebx, edi
// 0081ed15  7d06                 jge 0x81ed1d
// 0081ed17  897c2414             mov dword ptr [esp + 0x14], edi
// 0081ed1b  eb06                 jmp 0x81ed23
// 0081ed1d  895c2414             mov dword ptr [esp + 0x14], ebx
// 0081ed21  8bfb                 mov edi, ebx
// 0081ed23  3bf9                 cmp edi, ecx
// 0081ed25  7d05                 jge 0x81ed2c
// 0081ed27  e8e04dfdff           call 0x7f3b0c
// 0081ed2c  8d3c7f               lea edi, [edi + edi*2]
// 0081ed2f  03ff                 add edi, edi
// 0081ed31  03ff                 add edi, edi
// 0081ed33  57                   push edi
// 0081ed34  e8094efdff           call 0x7f3b42
// 0081ed39  8b4e04               mov ecx, dword ptr [esi + 4]
// 0081ed3c  8be8                 mov ebp, eax
// 0081ed3e  8b4608               mov eax, dword ptr [esi + 8]
// 0081ed41  8d0440               lea eax, [eax + eax*2]
// 0081ed44  03c0                 add eax, eax
// 0081ed46  03c0                 add eax, eax
// 0081ed48  50                   push eax
// 0081ed49  51                   push ecx
// 0081ed4a  57                   push edi
// 0081ed4b  55                   push ebp
// 0081ed4c  e84f3ebeff           call 0x402ba0
// 0081ed51  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081ed54  8bc3                 mov eax, ebx
// 0081ed56  2bc1                 sub eax, ecx
// 0081ed58  8d1440               lea edx, [eax + eax*2]
// 0081ed5b  03d2                 add edx, edx
// 0081ed5d  03d2                 add edx, edx
// 0081ed5f  52                   push edx
// 0081ed60  8d0449               lea eax, [ecx + ecx*2]
// 0081ed63  8d4c8500             lea ecx, [ebp + eax*4]
// 0081ed67  6a00                 push 0
// 0081ed69  51                   push ecx
// 0081ed6a  e8355dfdff           call 0x7f4aa4
// 0081ed6f  8b5604               mov edx, dword ptr [esi + 4]
// 0081ed72  52                   push edx
// 0081ed73  e88e4dfdff           call 0x7f3b06
// 0081ed78  8b442438             mov eax, dword ptr [esp + 0x38]
// 0081ed7c  83c424               add esp, 0x24
// 0081ed7f  896e04               mov dword ptr [esi + 4], ebp
// 0081ed82  89460c               mov dword ptr [esi + 0xc], eax
// 0081ed85  5d                   pop ebp
// 0081ed86  5f                   pop edi
// 0081ed87  895e08               mov dword ptr [esi + 8], ebx
// 0081ed8a  5e                   pop esi
// 0081ed8b  5b                   pop ebx
// 0081ed8c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPNotifyConnection.cpp (function ?SetSize@?$CArray@UCONNECTION_DESCRIPTOR@CXTPNotifyConnection@@AAU12@@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPNotifyConnection.cpp
