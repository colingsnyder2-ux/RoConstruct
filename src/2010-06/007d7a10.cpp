// from server: 100% by auto
// roc 2010-06 007d7a10  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 355 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7a10
//
// 007d7a10  8b0de455c200         mov ecx, dword ptr [0xc255e4]
// 007d7a16  56                   push esi
// 007d7a17  57                   push edi
// 007d7a18  85c9                 test ecx, ecx
// 007d7a1a  0f85bd000000         jne 0x7d7add
// 007d7a20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007d7a24  83c008               add eax, 8
// 007d7a27  8bf0                 mov esi, eax
// 007d7a29  81e603000080         and esi, 0x80000003
// 007d7a2f  7905                 jns 0x7d7a36
// 007d7a31  4e                   dec esi
// 007d7a32  83cefc               or esi, 0xfffffffc
// 007d7a35  46                   inc esi
// 007d7a36  8b3db869be00         mov edi, dword ptr [0xbe69b8]
// 007d7a3c  f7de                 neg esi
// 007d7a3e  1bf6                 sbb esi, esi
// 007d7a40  99                   cdq 
// 007d7a41  83e203               and edx, 3
// 007d7a44  03c2                 add eax, edx
// 007d7a46  f7de                 neg esi
// 007d7a48  c1f802               sar eax, 2
// 007d7a4b  03f0                 add esi, eax
// 007d7a4d  03f6                 add esi, esi
// 007d7a4f  03f6                 add esi, esi
// 007d7a51  0faffe               imul edi, esi
// 007d7a54  68a055c200           push 0xc255a0
// 007d7a59  83c710               add edi, 0x10
// 007d7a5c  ff1580a39e00         call dword ptr [0x9ea380]
// 007d7a62  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d7a69  7416                 je 0x7d7a81
// 007d7a6b  e820b0ffff           call 0x7d2a90
// 007d7a70  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d7a75  57                   push edi
// 007d7a76  6a00                 push 0
// 007d7a78  50                   push eax
// 007d7a79  ff1510a39e00         call dword ptr [0x9ea310]
// 007d7a7f  eb09                 jmp 0x7d7a8a
// 007d7a81  57                   push edi
// 007d7a82  e8fb01fdff           call 0x7a7c82
// 007d7a87  83c404               add esp, 4
// 007d7a8a  85c0                 test eax, eax
// 007d7a8c  0f84dc000000         je 0x7d7b6e
// 007d7a92  33c9                 xor ecx, ecx
// 007d7a94  894804               mov dword ptr [eax + 4], ecx
// 007d7a97  894808               mov dword ptr [eax + 8], ecx
// 007d7a9a  89480c               mov dword ptr [eax + 0xc], ecx
// 007d7a9d  8908                 mov dword ptr [eax], ecx
// 007d7a9f  8bf8                 mov edi, eax
// 007d7aa1  a3e455c200           mov dword ptr [0xc255e4], eax
// 007d7aa6  83c010               add eax, 0x10
// 007d7aa9  894704               mov dword ptr [edi + 4], eax
// 007d7aac  33d2                 xor edx, edx
// 007d7aae  390db869be00         cmp dword ptr [0xbe69b8], ecx
// 007d7ab4  7e19                 jle 0x7d7acf
// 007d7ab6  8bc8                 mov ecx, eax
// 007d7ab8  03c6                 add eax, esi
// 007d7aba  42                   inc edx
// 007d7abb  8939                 mov dword ptr [ecx], edi
// 007d7abd  894104               mov dword ptr [ecx + 4], eax
// 007d7ac0  3b15b869be00         cmp edx, dword ptr [0xbe69b8]
// 007d7ac6  7cee                 jl 0x7d7ab6
// 007d7ac8  c7410400000000       mov dword ptr [ecx + 4], 0
// 007d7acf  8b0de455c200         mov ecx, dword ptr [0xc255e4]
// 007d7ad5  85c9                 test ecx, ecx
// 007d7ad7  0f8491000000         je 0x7d7b6e
// 007d7add  83790400             cmp dword ptr [ecx + 4], 0
// 007d7ae1  0f8487000000         je 0x7d7b6e
// 007d7ae7  8b4104               mov eax, dword ptr [ecx + 4]
// 007d7aea  ff01                 inc dword ptr [ecx]
// 007d7aec  ff05d855c200         inc dword ptr [0xc255d8]
// 007d7af2  8b0de455c200         mov ecx, dword ptr [0xc255e4]
// 007d7af8  8b4904               mov ecx, dword ptr [ecx + 4]
// 007d7afb  8b5104               mov edx, dword ptr [ecx + 4]
// 007d7afe  c7410400000000       mov dword ptr [ecx + 4], 0
// 007d7b05  8b0de455c200         mov ecx, dword ptr [0xc255e4]
// 007d7b0b  83c008               add eax, 8
// 007d7b0e  895104               mov dword ptr [ecx + 4], edx
// 007d7b11  85d2                 test edx, edx
// 007d7b13  755b                 jne 0x7d7b70
// 007d7b15  8b15e455c200         mov edx, dword ptr [0xc255e4]
// 007d7b1b  837a0800             cmp dword ptr [edx + 8], 0
// 007d7b1f  8d4a08               lea ecx, [edx + 8]
// 007d7b22  8bf2                 mov esi, edx
// 007d7b24  7404                 je 0x7d7b2a
// 007d7b26  8b11                 mov edx, dword ptr [ecx]
// 007d7b28  eb03                 jmp 0x7d7b2d
// 007d7b2a  8b520c               mov edx, dword ptr [edx + 0xc]
// 007d7b2d  8915e455c200         mov dword ptr [0xc255e4], edx
// 007d7b33  85d2                 test edx, edx
// 007d7b35  7405                 je 0x7d7b3c
// 007d7b37  8b39                 mov edi, dword ptr [ecx]
// 007d7b39  897a08               mov dword ptr [edx + 8], edi
// 007d7b3c  8b15e855c200         mov edx, dword ptr [0xc255e8]
// 007d7b42  89560c               mov dword ptr [esi + 0xc], edx
// 007d7b45  8b15e855c200         mov edx, dword ptr [0xc255e8]
// 007d7b4b  85d2                 test edx, edx
// 007d7b4d  7405                 je 0x7d7b54
// 007d7b4f  8b5208               mov edx, dword ptr [edx + 8]
// 007d7b52  eb02                 jmp 0x7d7b56
// 007d7b54  33d2                 xor edx, edx
// 007d7b56  8911                 mov dword ptr [ecx], edx
// 007d7b58  8b0de855c200         mov ecx, dword ptr [0xc255e8]
// 007d7b5e  85c9                 test ecx, ecx
// 007d7b60  7403                 je 0x7d7b65
// 007d7b62  897108               mov dword ptr [ecx + 8], esi
// 007d7b65  5f                   pop edi
// 007d7b66  8935e855c200         mov dword ptr [0xc255e8], esi
// 007d7b6c  5e                   pop esi
// 007d7b6d  c3                   ret 
// 007d7b6e  33c0                 xor eax, eax
// 007d7b70  5f                   pop edi
// 007d7b71  5e                   pop esi
// 007d7b72  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?AllocData@?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@SAPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
