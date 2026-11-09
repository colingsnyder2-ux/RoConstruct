// from server: 100% by auto
// roc 2010-06 009e9010  unit: seg_009e0000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009e9010
//
// 009e9010  c705cc69be00908ea500 mov dword ptr [0xbe69cc], 0xa58e90
// 009e901a  e831dadeff           call 0x7d6a50
// 009e901f  833da055c20000       cmp dword ptr [0xc255a0], 0
// 009e9026  751a                 jne 0x9e9042
// 009e9028  a19c55c200           mov eax, dword ptr [0xc2559c]
// 009e902d  85c0                 test eax, eax
// 009e902f  7407                 je 0x9e9038
// 009e9031  50                   push eax
// 009e9032  ff1514a39e00         call dword ptr [0x9ea314]
// 009e9038  c7059c55c20000000000 mov dword ptr [0xc2559c], 0
// 009e9042  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ??__Fgs_CXTPReportRow_Batch_BlocksManager@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
