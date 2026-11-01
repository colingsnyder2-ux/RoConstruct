// from server: 100% by auto
// roc 2009-12 0089d8a0  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089d8a0
//
// 0089d8a0  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 0089d8a6  83f8ff               cmp eax, -1
// 0089d8a9  7506                 jne 0x89d8b1
// 0089d8ab  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 0089d8b1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089d8b5  50                   push eax
// 0089d8b6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0089d8ba  50                   push eax
// 0089d8bb  e83e6df5ff           call 0x7f45fe
// 0089d8c0  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillGroupByControl@CXTPReportPaintManager@@UAEXPAVCDC@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
