// from server: 100% by auto
// roc 2009-06 0073f190  unit: CXTPReportView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f190
//
// 0073f190  56                   push esi
// 0073f191  8bf1                 mov esi, ecx
// 0073f193  8b4e08               mov ecx, dword ptr [esi + 8]
// 0073f196  85c9                 test ecx, ecx
// 0073f198  7405                 je 0x73f19f
// 0073f19a  e8099efdff           call 0x718fa8
// 0073f19f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0073f1a2  85c9                 test ecx, ecx
// 0073f1a4  7405                 je 0x73f1ab
// 0073f1a6  e8fd9dfdff           call 0x718fa8
// 0073f1ab  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0073f1ae  5e                   pop esi
// 0073f1af  85c9                 test ecx, ecx
// 0073f1b1  7405                 je 0x73f1b8
// 0073f1b3  e9f09dfdff           jmp 0x718fa8
// 0073f1b8  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?Release@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
