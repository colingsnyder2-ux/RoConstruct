// from server: 100% by auto
// roc 2009-06 007cc080  unit: CXTPReportHeaderDropWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cc080
//
// 007cc080  8b4154               mov eax, dword ptr [ecx + 0x54]
// 007cc083  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 007cc086  50                   push eax
// 007cc087  51                   push ecx
// 007cc088  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007cc08c  6a0c                 push 0xc
// 007cc08e  6a00                 push 0
// 007cc090  6a00                 push 0
// 007cc092  e899fe0700           call 0x84bf30
// 007cc097  b801000000           mov eax, 1
// 007cc09c  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?OnEraseBkgnd@CXTPReportHeaderDropWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
