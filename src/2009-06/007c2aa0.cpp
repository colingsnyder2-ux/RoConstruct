// from server: 100% by auto
// roc 2009-06 007c2aa0  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c2aa0
//
// 007c2aa0  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 007c2aa6  83f8ff               cmp eax, -1
// 007c2aa9  7506                 jne 0x7c2ab1
// 007c2aab  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 007c2ab1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007c2ab5  50                   push eax
// 007c2ab6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007c2aba  50                   push eax
// 007c2abb  e8106df5ff           call 0x7197d0
// 007c2ac0  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillGroupByControl@CXTPReportPaintManager@@UAEXPAVCDC@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
