// from server: 100% by auto
// roc 2010-06 007ce170  unit: CXTPReportView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce170
//
// 007ce170  56                   push esi
// 007ce171  8bf1                 mov esi, ecx
// 007ce173  8b4e08               mov ecx, dword ptr [esi + 8]
// 007ce176  85c9                 test ecx, ecx
// 007ce178  7405                 je 0x7ce17f
// 007ce17a  e89d9dfdff           call 0x7a7f1c
// 007ce17f  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007ce182  85c9                 test ecx, ecx
// 007ce184  7405                 je 0x7ce18b
// 007ce186  e8919dfdff           call 0x7a7f1c
// 007ce18b  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007ce18e  5e                   pop esi
// 007ce18f  85c9                 test ecx, ecx
// 007ce191  7405                 je 0x7ce198
// 007ce193  e9849dfdff           jmp 0x7a7f1c
// 007ce198  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?Release@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
