// from server: 100% by auto
// roc 2009-06 007524d0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007524d0
//
// 007524d0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007524d3  83ec14               sub esp, 0x14
// 007524d6  85c9                 test ecx, ecx
// 007524d8  7430                 je 0x75250a
// 007524da  8b542418             mov edx, dword ptr [esp + 0x18]
// 007524de  33c0                 xor eax, eax
// 007524e0  8944240c             mov dword ptr [esp + 0xc], eax
// 007524e4  89442410             mov dword ptr [esp + 0x10], eax
// 007524e8  890424               mov dword ptr [esp], eax
// 007524eb  89442404             mov dword ptr [esp + 4], eax
// 007524ef  89442408             mov dword ptr [esp + 8], eax
// 007524f3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007524f7  8944240c             mov dword ptr [esp + 0xc], eax
// 007524fb  8d0424               lea eax, [esp]
// 007524fe  50                   push eax
// 007524ff  6ab0                 push -0x50
// 00752501  89542418             mov dword ptr [esp + 0x18], edx
// 00752505  e8565fffff           call 0x748460
// 0075250a  83c414               add esp, 0x14
// 0075250d  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?_NotifySelChanging@CXTPReportSelectedRows@@QAEXW4XTPReportSelectionChangeType@@PAVCXTPReportRow@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
