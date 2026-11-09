// from server: 100% by auto
// roc 2007-03 006b94e0  unit: seg_006b0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b94e0
//
// 006b94e0  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 006b94e6  83f8ff               cmp eax, -1
// 006b94e9  7506                 jne 0x6b94f1
// 006b94eb  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 006b94f1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b94f5  50                   push eax
// 006b94f6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b94fa  50                   push eax
// 006b94fb  e81a58f6ff           call 0x61ed1a
// 006b9500  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillGroupByControl@CXTPReportPaintManager@@UAEXPAVCDC@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
