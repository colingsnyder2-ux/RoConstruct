// from server: 100% by auto
// roc 2009-12 0081a0b0  unit: CXTPReportView  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a0b0
//
// 0081a0b0  56                   push esi
// 0081a0b1  8bf1                 mov esi, ecx
// 0081a0b3  8b4e08               mov ecx, dword ptr [esi + 8]
// 0081a0b6  85c9                 test ecx, ecx
// 0081a0b8  7405                 je 0x81a0bf
// 0081a0ba  e81d9dfdff           call 0x7f3ddc
// 0081a0bf  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0081a0c2  85c9                 test ecx, ecx
// 0081a0c4  7405                 je 0x81a0cb
// 0081a0c6  e8119dfdff           call 0x7f3ddc
// 0081a0cb  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0081a0ce  5e                   pop esi
// 0081a0cf  85c9                 test ecx, ecx
// 0081a0d1  7405                 je 0x81a0d8
// 0081a0d3  e9049dfdff           jmp 0x7f3ddc
// 0081a0d8  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?Release@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
