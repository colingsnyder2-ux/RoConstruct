// from server: 100% by auto
// roc 2009-06 00748ba0  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748ba0
//
// 00748ba0  8b0d581aa500         mov ecx, dword ptr [0xa51a58]
// 00748ba6  56                   push esi
// 00748ba7  57                   push edi
// 00748ba8  85c9                 test ecx, ecx
// 00748baa  0f85bd000000         jne 0x748c6d
// 00748bb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00748bb4  83c008               add eax, 8
// 00748bb7  8bf0                 mov esi, eax
// 00748bb9  81e603000080         and esi, 0x80000003
// 00748bbf  7905                 jns 0x748bc6
// 00748bc1  4e                   dec esi
// 00748bc2  83cefc               or esi, 0xfffffffc
// 00748bc5  46                   inc esi
// 00748bc6  8b3d3859a200         mov edi, dword ptr [0xa25938]
// 00748bcc  f7de                 neg esi
// 00748bce  1bf6                 sbb esi, esi
// 00748bd0  99                   cdq 
// 00748bd1  83e203               and edx, 3
// 00748bd4  03c2                 add eax, edx
// 00748bd6  f7de                 neg esi
// 00748bd8  c1f802               sar eax, 2
// 00748bdb  03f0                 add esi, eax
// 00748bdd  03f6                 add esi, esi
// 00748bdf  03f6                 add esi, esi
// 00748be1  0faffe               imul edi, esi
// 00748be4  68141aa500           push 0xa51a14
// 00748be9  83c710               add edi, 0x10
// 00748bec  ff15d0e18900         call dword ptr [0x89e1d0]
// 00748bf2  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00748bf9  7416                 je 0x748c11
// 00748bfb  e870afffff           call 0x743b70
// 00748c00  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00748c05  57                   push edi
// 00748c06  6a00                 push 0
// 00748c08  50                   push eax
// 00748c09  ff1524e28900         call dword ptr [0x89e224]
// 00748c0f  eb09                 jmp 0x748c1a
// 00748c11  57                   push edi
// 00748c12  e80301fdff           call 0x718d1a
// 00748c17  83c404               add esp, 4
// 00748c1a  85c0                 test eax, eax
// 00748c1c  0f84dc000000         je 0x748cfe
// 00748c22  33c9                 xor ecx, ecx
// 00748c24  894804               mov dword ptr [eax + 4], ecx
// 00748c27  894808               mov dword ptr [eax + 8], ecx
// 00748c2a  89480c               mov dword ptr [eax + 0xc], ecx
// 00748c2d  8908                 mov dword ptr [eax], ecx
// 00748c2f  8bf8                 mov edi, eax
// 00748c31  a3581aa500           mov dword ptr [0xa51a58], eax
// 00748c36  83c010               add eax, 0x10
// 00748c39  894704               mov dword ptr [edi + 4], eax
// 00748c3c  33d2                 xor edx, edx
// 00748c3e  390d3859a200         cmp dword ptr [0xa25938], ecx
// 00748c44  7e19                 jle 0x748c5f
// 00748c46  8bc8                 mov ecx, eax
// 00748c48  03c6                 add eax, esi
// 00748c4a  42                   inc edx
// 00748c4b  8939                 mov dword ptr [ecx], edi
// 00748c4d  894104               mov dword ptr [ecx + 4], eax
// 00748c50  3b153859a200         cmp edx, dword ptr [0xa25938]
// 00748c56  7cee                 jl 0x748c46
// 00748c58  c7410400000000       mov dword ptr [ecx + 4], 0
// 00748c5f  8b0d581aa500         mov ecx, dword ptr [0xa51a58]
// 00748c65  85c9                 test ecx, ecx
// 00748c67  0f8491000000         je 0x748cfe
// 00748c6d  83790400             cmp dword ptr [ecx + 4], 0
// 00748c71  0f8487000000         je 0x748cfe
// 00748c77  8b4104               mov eax, dword ptr [ecx + 4]
// 00748c7a  ff01                 inc dword ptr [ecx]
// 00748c7c  ff054c1aa500         inc dword ptr [0xa51a4c]
// 00748c82  8b0d581aa500         mov ecx, dword ptr [0xa51a58]
// 00748c88  8b4904               mov ecx, dword ptr [ecx + 4]
// 00748c8b  8b5104               mov edx, dword ptr [ecx + 4]
// 00748c8e  c7410400000000       mov dword ptr [ecx + 4], 0
// 00748c95  8b0d581aa500         mov ecx, dword ptr [0xa51a58]
// 00748c9b  83c008               add eax, 8
// 00748c9e  895104               mov dword ptr [ecx + 4], edx
// 00748ca1  85d2                 test edx, edx
// 00748ca3  755b                 jne 0x748d00
// 00748ca5  8b15581aa500         mov edx, dword ptr [0xa51a58]
// 00748cab  837a0800             cmp dword ptr [edx + 8], 0
// 00748caf  8d4a08               lea ecx, [edx + 8]
// 00748cb2  8bf2                 mov esi, edx
// 00748cb4  7404                 je 0x748cba
// 00748cb6  8b11                 mov edx, dword ptr [ecx]
// 00748cb8  eb03                 jmp 0x748cbd
// 00748cba  8b520c               mov edx, dword ptr [edx + 0xc]
// 00748cbd  8915581aa500         mov dword ptr [0xa51a58], edx
// 00748cc3  85d2                 test edx, edx
// 00748cc5  7405                 je 0x748ccc
// 00748cc7  8b39                 mov edi, dword ptr [ecx]
// 00748cc9  897a08               mov dword ptr [edx + 8], edi
// 00748ccc  8b155c1aa500         mov edx, dword ptr [0xa51a5c]
// 00748cd2  89560c               mov dword ptr [esi + 0xc], edx
// 00748cd5  8b155c1aa500         mov edx, dword ptr [0xa51a5c]
// 00748cdb  85d2                 test edx, edx
// 00748cdd  7405                 je 0x748ce4
// 00748cdf  8b5208               mov edx, dword ptr [edx + 8]
// 00748ce2  eb02                 jmp 0x748ce6
// 00748ce4  33d2                 xor edx, edx
// 00748ce6  8911                 mov dword ptr [ecx], edx
// 00748ce8  8b0d5c1aa500         mov ecx, dword ptr [0xa51a5c]
// 00748cee  85c9                 test ecx, ecx
// 00748cf0  7403                 je 0x748cf5
// 00748cf2  897108               mov dword ptr [ecx + 8], esi
// 00748cf5  5f                   pop edi
// 00748cf6  89355c1aa500         mov dword ptr [0xa51a5c], esi
// 00748cfc  5e                   pop esi
// 00748cfd  c3                   ret 
// 00748cfe  33c0                 xor eax, eax
// 00748d00  5f                   pop edi
// 00748d01  5e                   pop esi
// 00748d02  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?AllocData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
