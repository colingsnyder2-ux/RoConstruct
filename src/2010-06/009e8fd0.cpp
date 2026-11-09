// from server: 100% by auto
// roc 2010-06 009e8fd0  unit: seg_009e0000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e8fd0
//
// 009e8fd0  c705c869be00888ea500 mov dword ptr [0xbe69c8], 0xa58e88
// 009e8fda  e891d8deff           call 0x7d6870
// 009e8fdf  833da055c20000       cmp dword ptr [0xc255a0], 0
// 009e8fe6  751a                 jne 0x9e9002
// 009e8fe8  a19c55c200           mov eax, dword ptr [0xc2559c]
// 009e8fed  85c0                 test eax, eax
// 009e8fef  7407                 je 0x9e8ff8
// 009e8ff1  50                   push eax
// 009e8ff2  ff1514a39e00         call dword ptr [0x9ea314]
// 009e8ff8  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 009e9002  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??__Fgs_CXTPReportRow_Batch_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
