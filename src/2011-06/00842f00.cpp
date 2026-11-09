// from server: 100% by auto
// roc 2011-06 00842f00  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00842f00
//
// 00842f00  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00842f03  83ec14               sub esp, 0x14
// 00842f06  85c9                 test ecx, ecx
// 00842f08  7430                 je 0x842f3a
// 00842f0a  8b542418             mov edx, dword ptr [esp + 0x18]
// 00842f0e  33c0                 xor eax, eax
// 00842f10  8944240c             mov dword ptr [esp + 0xc], eax
// 00842f14  89442410             mov dword ptr [esp + 0x10], eax
// 00842f18  890424               mov dword ptr [esp], eax
// 00842f1b  89442404             mov dword ptr [esp + 4], eax
// 00842f1f  89442408             mov dword ptr [esp + 8], eax
// 00842f23  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00842f27  8944240c             mov dword ptr [esp + 0xc], eax
// 00842f2b  8d0424               lea eax, [esp]
// 00842f2e  50                   push eax
// 00842f2f  6ab0                 push -0x50
// 00842f31  89542418             mov dword ptr [esp + 0x18], edx
// 00842f35  e82645ffff           call 0x837460
// 00842f3a  83c414               add esp, 0x14
// 00842f3d  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?_NotifySelChanging@CXTPReportSelectedRows@@QAEXW4XTPReportSelectionChangeType@@PAVCXTPReportRow@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
