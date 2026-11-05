// from server: 100% by auto
// roc 2010-06 007d6a50  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6a50
//
// 007d6a50  56                   push esi
// 007d6a51  8b35e455c200         mov esi, dword ptr [0xc255e4]
// 007d6a57  85f6                 test esi, esi
// 007d6a59  0f84c4000000         je 0x7d6b23
// 007d6a5f  90                   nop 
// 007d6a60  8b4608               mov eax, dword ptr [esi + 8]
// 007d6a63  85c0                 test eax, eax
// 007d6a65  7408                 je 0x7d6a6f
// 007d6a67  8bf0                 mov esi, eax
// 007d6a69  85f6                 test esi, esi
// 007d6a6b  75f3                 jne 0x7d6a60
// 007d6a6d  5e                   pop esi
// 007d6a6e  c3                   ret 
// 007d6a6f  53                   push ebx
// 007d6a70  55                   push ebp
// 007d6a71  8b2d0ca39e00         mov ebp, dword ptr [0x9ea30c]
// 007d6a77  57                   push edi
// 007d6a78  eb06                 jmp 0x7d6a80
// 007d6a7a  8d9b00000000         lea ebx, [ebx]
// 007d6a80  833e00               cmp dword ptr [esi], 0
// 007d6a83  0f858c000000         jne 0x7d6b15
// 007d6a89  8b4608               mov eax, dword ptr [esi + 8]
// 007d6a8c  8bde                 mov ebx, esi
// 007d6a8e  85c0                 test eax, eax
// 007d6a90  7406                 je 0x7d6a98
// 007d6a92  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007d6a95  89480c               mov dword ptr [eax + 0xc], ecx
// 007d6a98  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d6a9b  85c0                 test eax, eax
// 007d6a9d  7406                 je 0x7d6aa5
// 007d6a9f  8b5608               mov edx, dword ptr [esi + 8]
// 007d6aa2  895008               mov dword ptr [eax + 8], edx
// 007d6aa5  3935e455c200         cmp dword ptr [0xc255e4], esi
// 007d6aab  750f                 jne 0x7d6abc
// 007d6aad  8b4608               mov eax, dword ptr [esi + 8]
// 007d6ab0  85c0                 test eax, eax
// 007d6ab2  7503                 jne 0x7d6ab7
// 007d6ab4  8b460c               mov eax, dword ptr [esi + 0xc]
// 007d6ab7  a3e455c200           mov dword ptr [0xc255e4], eax
// 007d6abc  8b760c               mov esi, dword ptr [esi + 0xc]
// 007d6abf  33ff                 xor edi, edi
// 007d6ac1  393da055c200         cmp dword ptr [0xc255a0], edi
// 007d6ac7  740d                 je 0x7d6ad6
// 007d6ac9  68a055c200           push 0xc255a0
// 007d6ace  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d6ad4  8bf8                 mov edi, eax
// 007d6ad6  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d6add  53                   push ebx
// 007d6ade  742b                 je 0x7d6b0b
// 007d6ae0  8b0d9c55c200         mov ecx, dword ptr [0xc2559c]
// 007d6ae6  6a00                 push 0
// 007d6ae8  51                   push ecx
// 007d6ae9  ffd5                 call ebp
// 007d6aeb  85ff                 test edi, edi
// 007d6aed  7529                 jne 0x7d6b18
// 007d6aef  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d6af4  85c0                 test eax, eax
// 007d6af6  7407                 je 0x7d6aff
// 007d6af8  50                   push eax
// 007d6af9  ff1514a39e00         call dword ptr [0x9ea314]
// 007d6aff  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d6b09  eb0d                 jmp 0x7d6b18
// 007d6b0b  e88a0efdff           call 0x7a799a
// 007d6b10  83c404               add esp, 4
// 007d6b13  eb03                 jmp 0x7d6b18
// 007d6b15  8b760c               mov esi, dword ptr [esi + 0xc]
// 007d6b18  85f6                 test esi, esi
// 007d6b1a  0f8560ffffff         jne 0x7d6a80
// 007d6b20  5f                   pop edi
// 007d6b21  5d                   pop ebp
// 007d6b22  5b                   pop ebx
// 007d6b23  5e                   pop esi
// 007d6b24  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?FreeExtraData@?$CXTPBatchAllocManagerT@VCXTPReportRowAllocator@@UCXTPReportRow_BatchData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
