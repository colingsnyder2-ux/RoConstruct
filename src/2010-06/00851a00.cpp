// from server: 100% by auto
// roc 2010-06 00851a00  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00851a00
//
// 00851a00  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 00851a06  83f8ff               cmp eax, -1
// 00851a09  7506                 jne 0x851a11
// 00851a0b  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 00851a11  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00851a15  50                   push eax
// 00851a16  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00851a1a  50                   push eax
// 00851a1b  e81e6df5ff           call 0x7a873e
// 00851a20  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillGroupByControl@CXTPReportPaintManager@@UAEXPAVCDC@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
