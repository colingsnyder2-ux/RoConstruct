// from server: 100% by auto
// roc 2010-06 0085afd0  unit: CXTPReportHeaderDropWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085afd0
//
// 0085afd0  8b4154               mov eax, dword ptr [ecx + 0x54]
// 0085afd3  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 0085afd6  50                   push eax
// 0085afd7  51                   push ecx
// 0085afd8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0085afdc  6a0c                 push 0xc
// 0085afde  6a00                 push 0
// 0085afe0  6a00                 push 0
// 0085afe2  e8a31d1200           call 0x97cd8a
// 0085afe7  b801000000           mov eax, 1
// 0085afec  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?OnEraseBkgnd@CXTPReportHeaderDropWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportDragDrop.cpp
