// from server: 100% by auto
// roc 2010-06 009e8f70  unit: seg_009e0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e8f70
//
// 009e8f70  833da055c20000       cmp dword ptr [0xc255a0], 0
// 009e8f77  c705c069be00cc91a500 mov dword ptr [0xbe69c0], 0xa591cc
// 009e8f81  751a                 jne 0x9e8f9d
// 009e8f83  a19c55c200           mov eax, dword ptr [0xc2559c]
// 009e8f88  85c0                 test eax, eax
// 009e8f8a  7407                 je 0x9e8f93
// 009e8f8c  50                   push eax
// 009e8f8d  ff1514a39e00         call dword ptr [0x9ea314]
// 009e8f93  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 009e8f9d  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??__Fg_objCXTPReportDataAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
