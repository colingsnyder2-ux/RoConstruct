// from server: 100% by auto
// roc 2010-06 009e8fa0  unit: seg_009e0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e8fa0
//
// 009e8fa0  833db055c20000       cmp dword ptr [0xc255b0], 0
// 009e8fa7  c705c469be00d491a500 mov dword ptr [0xbe69c4], 0xa591d4
// 009e8fb1  751a                 jne 0x9e8fcd
// 009e8fb3  a1ac55c200           mov eax, dword ptr [0xc255ac]
// 009e8fb8  85c0                 test eax, eax
// 009e8fba  7407                 je 0x9e8fc3
// 009e8fbc  50                   push eax
// 009e8fbd  ff1514a39e00         call dword ptr [0x9ea314]
// 009e8fc3  c705ac55c20000000000 mov dword ptr [0xc255ac], 0
// 009e8fcd  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??__Fg_objCXTPReportDataAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
