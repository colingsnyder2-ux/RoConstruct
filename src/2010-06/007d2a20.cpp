// from server: 100% by auto
// roc 2010-06 007d2a20  unit: CXTPReportControl  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2a20
//
// 007d2a20  51                   push ecx
// 007d2a21  833dac55c20000       cmp dword ptr [0xc255ac], 0
// 007d2a28  755a                 jne 0x7d2a84
// 007d2a2a  56                   push esi
// 007d2a2b  6a00                 push 0
// 007d2a2d  6a00                 push 0
// 007d2a2f  6a00                 push 0
// 007d2a31  ff1518a39e00         call dword ptr [0x9ea318]
// 007d2a37  687439a000           push 0xa03974
// 007d2a3c  a3ac55c200           mov dword ptr [0xc255ac], eax
// 007d2a41  8bf0                 mov esi, eax
// 007d2a43  c744240802000000     mov dword ptr [esp + 8], 2
// 007d2a4b  ff158ca39e00         call dword ptr [0x9ea38c]
// 007d2a51  85c0                 test eax, eax
// 007d2a53  7424                 je 0x7d2a79
// 007d2a55  686039a000           push 0xa03960
// 007d2a5a  50                   push eax
// 007d2a5b  ff1590a39e00         call dword ptr [0x9ea390]
// 007d2a61  85c0                 test eax, eax
// 007d2a63  7414                 je 0x7d2a79
// 007d2a65  6a04                 push 4
// 007d2a67  8d4c2408             lea ecx, [esp + 8]
// 007d2a6b  51                   push ecx
// 007d2a6c  6a00                 push 0
// 007d2a6e  56                   push esi
// 007d2a6f  ffd0                 call eax
// 007d2a71  a3b455c200           mov dword ptr [0xc255b4], eax
// 007d2a76  5e                   pop esi
// 007d2a77  59                   pop ecx
// 007d2a78  c3                   ret 
// 007d2a79  b801000000           mov eax, 1
// 007d2a7e  a3b455c200           mov dword ptr [0xc255b4], eax
// 007d2a83  5e                   pop esi
// 007d2a84  59                   pop ecx
// 007d2a85  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?CreateHeapIfNeed@?$CXTPHeapAllocatorT@UCXTPReportDataAllocatorData@@@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
