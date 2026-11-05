// from server: 100% by auto
// roc 2009-12 0082d240  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082d240
//
// 0082d240  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0082d243  83ec14               sub esp, 0x14
// 0082d246  85c9                 test ecx, ecx
// 0082d248  7430                 je 0x82d27a
// 0082d24a  8b542418             mov edx, dword ptr [esp + 0x18]
// 0082d24e  33c0                 xor eax, eax
// 0082d250  8944240c             mov dword ptr [esp + 0xc], eax
// 0082d254  89442410             mov dword ptr [esp + 0x10], eax
// 0082d258  890424               mov dword ptr [esp], eax
// 0082d25b  89442404             mov dword ptr [esp + 4], eax
// 0082d25f  89442408             mov dword ptr [esp + 8], eax
// 0082d263  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0082d267  8944240c             mov dword ptr [esp + 0xc], eax
// 0082d26b  8d0424               lea eax, [esp]
// 0082d26e  50                   push eax
// 0082d26f  6ab0                 push -0x50
// 0082d271  89542418             mov dword ptr [esp + 0x18], edx
// 0082d275  e8f65fffff           call 0x823270
// 0082d27a  83c414               add esp, 0x14
// 0082d27d  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportRows.cpp (function ?_NotifySelChanging@CXTPReportSelectedRows@@QAEXW4XTPReportSelectionChangeType@@PAVCXTPReportRow@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRows.cpp
