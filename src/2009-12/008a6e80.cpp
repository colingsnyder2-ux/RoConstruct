// from server: 100% by auto
// roc 2009-12 008a6e80  unit: CXTPReportHeaderDropWnd  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6e80
//
// 008a6e80  8b4154               mov eax, dword ptr [ecx + 0x54]
// 008a6e83  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 008a6e86  50                   push eax
// 008a6e87  51                   push ecx
// 008a6e88  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a6e8c  6a0c                 push 0xc
// 008a6e8e  6a00                 push 0
// 008a6e90  6a00                 push 0
// 008a6e92  e8fff50700           call 0x926496
// 008a6e97  b801000000           mov eax, 1
// 008a6e9c  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?OnEraseBkgnd@CXTPReportHeaderDropWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
