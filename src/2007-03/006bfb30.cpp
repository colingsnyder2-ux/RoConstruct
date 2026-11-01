// from server: 100% by auto
// roc 2007-03 006bfb30  unit: seg_006b0000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bfb30
//
// 006bfb30  8b4154               mov eax, dword ptr [ecx + 0x54]
// 006bfb33  8b4960               mov ecx, dword ptr [ecx + 0x60]
// 006bfb36  50                   push eax
// 006bfb37  51                   push ecx
// 006bfb38  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006bfb3c  6a0c                 push 0xc
// 006bfb3e  6a00                 push 0
// 006bfb40  6a00                 push 0
// 006bfb42  e8a5af0700           call 0x73aaec
// 006bfb47  b801000000           mov eax, 1
// 006bfb4c  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportDragDrop.cpp (function ?OnEraseBkgnd@CXTPReportHeaderDropWnd@@IAEHPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportDragDrop.cpp
