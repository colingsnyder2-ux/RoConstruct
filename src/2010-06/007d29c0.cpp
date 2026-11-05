// from server: 100% by auto
// roc 2010-06 007d29c0  unit: CXTPReportControl  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d29c0
//
// 007d29c0  56                   push esi
// 007d29c1  33f6                 xor esi, esi
// 007d29c3  3935a055c200         cmp dword ptr [0xc255a0], esi
// 007d29c9  740d                 je 0x7d29d8
// 007d29cb  68a055c200           push 0xc255a0
// 007d29d0  ff157ca39e00         call dword ptr [0x9ea37c]
// 007d29d6  8bf0                 mov esi, eax
// 007d29d8  833da855c20000       cmp dword ptr [0xc255a8], 0
// 007d29df  7434                 je 0x7d2a15
// 007d29e1  8b442408             mov eax, dword ptr [esp + 8]
// 007d29e5  8b0d9c55c200         mov ecx, dword ptr [0xc2559c]
// 007d29eb  50                   push eax
// 007d29ec  6a00                 push 0
// 007d29ee  51                   push ecx
// 007d29ef  ff150ca39e00         call dword ptr [0x9ea30c]
// 007d29f5  85f6                 test esi, esi
// 007d29f7  751a                 jne 0x7d2a13
// 007d29f9  a19c55c200           mov eax, dword ptr [0xc2559c]
// 007d29fe  85c0                 test eax, eax
// 007d2a00  7407                 je 0x7d2a09
// 007d2a02  50                   push eax
// 007d2a03  ff1514a39e00         call dword ptr [0x9ea314]
// 007d2a09  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 007d2a13  5e                   pop esi
// 007d2a14  c3                   ret 
// 007d2a15  5e                   pop esi
// 007d2a16  e97f4ffdff           jmp 0x7a799a
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?Free_mem@?$CXTPHeapAllocatorT@UCXTPReportRowAllocatorData@@@@SAXPAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
