// from server: 100% by auto
// roc 2009-06 00748a30  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748a30
//
// 00748a30  8b0d401aa500         mov ecx, dword ptr [0xa51a40]
// 00748a36  56                   push esi
// 00748a37  57                   push edi
// 00748a38  85c9                 test ecx, ecx
// 00748a3a  0f85bd000000         jne 0x748afd
// 00748a40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00748a44  83c008               add eax, 8
// 00748a47  8bf0                 mov esi, eax
// 00748a49  81e603000080         and esi, 0x80000003
// 00748a4f  7905                 jns 0x748a56
// 00748a51  4e                   dec esi
// 00748a52  83cefc               or esi, 0xfffffffc
// 00748a55  46                   inc esi
// 00748a56  8b3d3459a200         mov edi, dword ptr [0xa25934]
// 00748a5c  f7de                 neg esi
// 00748a5e  1bf6                 sbb esi, esi
// 00748a60  99                   cdq 
// 00748a61  83e203               and edx, 3
// 00748a64  03c2                 add eax, edx
// 00748a66  f7de                 neg esi
// 00748a68  c1f802               sar eax, 2
// 00748a6b  03f0                 add esi, eax
// 00748a6d  03f6                 add esi, esi
// 00748a6f  03f6                 add esi, esi
// 00748a71  0faffe               imul edi, esi
// 00748a74  68141aa500           push 0xa51a14
// 00748a79  83c710               add edi, 0x10
// 00748a7c  ff15d0e18900         call dword ptr [0x89e1d0]
// 00748a82  833d1c1aa50000       cmp dword ptr [0xa51a1c], 0
// 00748a89  7416                 je 0x748aa1
// 00748a8b  e8e0b0ffff           call 0x743b70
// 00748a90  a1101aa500           mov eax, dword ptr [0xa51a10]
// 00748a95  57                   push edi
// 00748a96  6a00                 push 0
// 00748a98  50                   push eax
// 00748a99  ff1524e28900         call dword ptr [0x89e224]
// 00748a9f  eb09                 jmp 0x748aaa
// 00748aa1  57                   push edi
// 00748aa2  e87302fdff           call 0x718d1a
// 00748aa7  83c404               add esp, 4
// 00748aaa  85c0                 test eax, eax
// 00748aac  0f84dc000000         je 0x748b8e
// 00748ab2  33c9                 xor ecx, ecx
// 00748ab4  894804               mov dword ptr [eax + 4], ecx
// 00748ab7  894808               mov dword ptr [eax + 8], ecx
// 00748aba  89480c               mov dword ptr [eax + 0xc], ecx
// 00748abd  8908                 mov dword ptr [eax], ecx
// 00748abf  8bf8                 mov edi, eax
// 00748ac1  a3401aa500           mov dword ptr [0xa51a40], eax
// 00748ac6  83c010               add eax, 0x10
// 00748ac9  894704               mov dword ptr [edi + 4], eax
// 00748acc  33d2                 xor edx, edx
// 00748ace  390d3459a200         cmp dword ptr [0xa25934], ecx
// 00748ad4  7e19                 jle 0x748aef
// 00748ad6  8bc8                 mov ecx, eax
// 00748ad8  03c6                 add eax, esi
// 00748ada  42                   inc edx
// 00748adb  8939                 mov dword ptr [ecx], edi
// 00748add  894104               mov dword ptr [ecx + 4], eax
// 00748ae0  3b153459a200         cmp edx, dword ptr [0xa25934]
// 00748ae6  7cee                 jl 0x748ad6
// 00748ae8  c7410400000000       mov dword ptr [ecx + 4], 0
// 00748aef  8b0d401aa500         mov ecx, dword ptr [0xa51a40]
// 00748af5  85c9                 test ecx, ecx
// 00748af7  0f8491000000         je 0x748b8e
// 00748afd  83790400             cmp dword ptr [ecx + 4], 0
// 00748b01  0f8487000000         je 0x748b8e
// 00748b07  8b4104               mov eax, dword ptr [ecx + 4]
// 00748b0a  ff01                 inc dword ptr [ecx]
// 00748b0c  ff05341aa500         inc dword ptr [0xa51a34]
// 00748b12  8b0d401aa500         mov ecx, dword ptr [0xa51a40]
// 00748b18  8b4904               mov ecx, dword ptr [ecx + 4]
// 00748b1b  8b5104               mov edx, dword ptr [ecx + 4]
// 00748b1e  c7410400000000       mov dword ptr [ecx + 4], 0
// 00748b25  8b0d401aa500         mov ecx, dword ptr [0xa51a40]
// 00748b2b  83c008               add eax, 8
// 00748b2e  895104               mov dword ptr [ecx + 4], edx
// 00748b31  85d2                 test edx, edx
// 00748b33  755b                 jne 0x748b90
// 00748b35  8b15401aa500         mov edx, dword ptr [0xa51a40]
// 00748b3b  837a0800             cmp dword ptr [edx + 8], 0
// 00748b3f  8d4a08               lea ecx, [edx + 8]
// 00748b42  8bf2                 mov esi, edx
// 00748b44  7404                 je 0x748b4a
// 00748b46  8b11                 mov edx, dword ptr [ecx]
// 00748b48  eb03                 jmp 0x748b4d
// 00748b4a  8b520c               mov edx, dword ptr [edx + 0xc]
// 00748b4d  8915401aa500         mov dword ptr [0xa51a40], edx
// 00748b53  85d2                 test edx, edx
// 00748b55  7405                 je 0x748b5c
// 00748b57  8b39                 mov edi, dword ptr [ecx]
// 00748b59  897a08               mov dword ptr [edx + 8], edi
// 00748b5c  8b15441aa500         mov edx, dword ptr [0xa51a44]
// 00748b62  89560c               mov dword ptr [esi + 0xc], edx
// 00748b65  8b15441aa500         mov edx, dword ptr [0xa51a44]
// 00748b6b  85d2                 test edx, edx
// 00748b6d  7405                 je 0x748b74
// 00748b6f  8b5208               mov edx, dword ptr [edx + 8]
// 00748b72  eb02                 jmp 0x748b76
// 00748b74  33d2                 xor edx, edx
// 00748b76  8911                 mov dword ptr [ecx], edx
// 00748b78  8b0d441aa500         mov ecx, dword ptr [0xa51a44]
// 00748b7e  85c9                 test ecx, ecx
// 00748b80  7403                 je 0x748b85
// 00748b82  897108               mov dword ptr [ecx + 8], esi
// 00748b85  5f                   pop edi
// 00748b86  8935441aa500         mov dword ptr [0xa51a44], esi
// 00748b8c  5e                   pop esi
// 00748b8d  c3                   ret 
// 00748b8e  33c0                 xor eax, eax
// 00748b90  5f                   pop edi
// 00748b91  5e                   pop esi
// 00748b92  c3                   ret 
// library xtp-15.2.1/Source\Chart\XTPChartSeriesPoint.cpp (function ?AllocData@?$CXTPBatchAllocManagerT@VCXTPChartSeriesPointAllocator@@UCXTPChartSeriesBatchPointData@@@@SAPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Chart/XTPChartSeriesPoint.cpp
