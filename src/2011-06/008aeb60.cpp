// from server: 100% by auto
// roc 2011-06 008aeb60  unit: CXTPReportPaintManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008aeb60
//
// 008aeb60  8b81cc000000         mov eax, dword ptr [ecx + 0xcc]
// 008aeb66  83f8ff               cmp eax, -1
// 008aeb69  7506                 jne 0x8aeb71
// 008aeb6b  8b81c8000000         mov eax, dword ptr [ecx + 0xc8]
// 008aeb71  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008aeb75  50                   push eax
// 008aeb76  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008aeb7a  50                   push eax
// 008aeb7b  e8a0c2f5ff           call 0x80ae20
// 008aeb80  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?FillGroupByControl@CXTPReportPaintManager@@UAEXPAVCDC@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
