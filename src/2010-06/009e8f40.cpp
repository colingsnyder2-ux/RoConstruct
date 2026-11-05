// from server: 100% by auto
// roc 2010-06 009e8f40  unit: seg_009e0000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e8f40
//
// 009e8f40  833d9055c20000       cmp dword ptr [0xc25590], 0
// 009e8f47  c705bc69be00c491a500 mov dword ptr [0xbe69bc], 0xa591c4
// 009e8f51  751a                 jne 0x9e8f6d
// 009e8f53  a18c55c200           mov eax, dword ptr [0xc2558c]
// 009e8f58  85c0                 test eax, eax
// 009e8f5a  7407                 je 0x9e8f63
// 009e8f5c  50                   push eax
// 009e8f5d  ff1514a39e00         call dword ptr [0x9ea314]
// 009e8f63  c7058c55c20000000000 mov dword ptr [0xc2558c], 0
// 009e8f6d  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??__Fg_objCXTPReportDataAllocator@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
