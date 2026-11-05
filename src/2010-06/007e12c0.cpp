// from server: 100% by auto
// roc 2010-06 007e12c0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e12c0
//
// 007e12c0  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e12c3  83ec14               sub esp, 0x14
// 007e12c6  85c9                 test ecx, ecx
// 007e12c8  7430                 je 0x7e12fa
// 007e12ca  8b542418             mov edx, dword ptr [esp + 0x18]
// 007e12ce  33c0                 xor eax, eax
// 007e12d0  8944240c             mov dword ptr [esp + 0xc], eax
// 007e12d4  89442410             mov dword ptr [esp + 0x10], eax
// 007e12d8  890424               mov dword ptr [esp], eax
// 007e12db  89442404             mov dword ptr [esp + 4], eax
// 007e12df  89442408             mov dword ptr [esp + 8], eax
// 007e12e3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e12e7  8944240c             mov dword ptr [esp + 0xc], eax
// 007e12eb  8d0424               lea eax, [esp]
// 007e12ee  50                   push eax
// 007e12ef  6ab0                 push -0x50
// 007e12f1  89542418             mov dword ptr [esp + 0x18], edx
// 007e12f5  e8d65fffff           call 0x7d72d0
// 007e12fa  83c414               add esp, 0x14
// 007e12fd  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?_NotifySelChanging@CXTPReportSelectedRows@@QAEXW4XTPReportSelectionChangeType@@PAVCXTPReportRow@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
