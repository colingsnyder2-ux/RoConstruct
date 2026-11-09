// from server: 100% by auto
// roc 2010-06 007d6710  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6710
//
// 007d6710  56                   push esi
// 007d6711  33f6                 xor esi, esi
// 007d6713  3935b055c200         cmp dword ptr [0xc255b0], esi
// 007d6719  740d                 je 0x7d6728
// 007d671b  68b055c200           push 0xc255b0
// 007d6720  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d6726  8bf0                 mov esi, eax
// 007d6728  833db855c20000       cmp dword ptr [0xc255b8], 0
// 007d672f  7434                 je 0x7d6765
// 007d6731  8b442408             mov eax, dword ptr [esp + 8]
// 007d6735  8b0dac55c200         mov ecx, dword ptr [0xc255ac]
// 007d673b  50                   push eax
// 007d673c  6a00                 push 0
// 007d673e  51                   push ecx
// 007d673f  ff150ca39e00         call dword ptr [0x9ea30c]
// 007d6745  85f6                 test esi, esi
// 007d6747  751a                 jne 0x7d6763
// 007d6749  a1ac55c200           mov eax, dword ptr [0xc255ac]
// 007d674e  85c0                 test eax, eax
// 007d6750  7407                 je 0x7d6759
// 007d6752  50                   push eax
// 007d6753  ff1514a39e00         call dword ptr [0x9ea314]
// 007d6759  c705ac55c20000000000 mov dword ptr [0xc255ac], 0
// 007d6763  5e                   pop esi
// 007d6764  c3                   ret 
// 007d6765  5e                   pop esi
// 007d6766  e92f12fdff           jmp 0x7a799a
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPReportRowAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
