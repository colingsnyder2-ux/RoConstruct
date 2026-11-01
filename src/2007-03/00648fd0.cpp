// from server: 100% by auto
// roc 2007-03 00648fd0  unit: seg_00640000  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00648fd0
//
// 00648fd0  83ec14               sub esp, 0x14
// 00648fd3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00648fd7  33c0                 xor eax, eax
// 00648fd9  8944240c             mov dword ptr [esp + 0xc], eax
// 00648fdd  89442410             mov dword ptr [esp + 0x10], eax
// 00648fe1  890424               mov dword ptr [esp], eax
// 00648fe4  89442404             mov dword ptr [esp + 4], eax
// 00648fe8  89442408             mov dword ptr [esp + 8], eax
// 00648fec  8b442418             mov eax, dword ptr [esp + 0x18]
// 00648ff0  89442410             mov dword ptr [esp + 0x10], eax
// 00648ff4  8d0424               lea eax, [esp]
// 00648ff7  50                   push eax
// 00648ff8  6ac0                 push -0x40
// 00648ffa  89542414             mov dword ptr [esp + 0x14], edx
// 00648ffe  e8adfcffff           call 0x648cb0
// 00649003  f7d8                 neg eax
// 00649005  1bc0                 sbb eax, eax
// 00649007  f7d8                 neg eax
// 00649009  83c414               add esp, 0x14
// 0064900c  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePasteFromText@CXTPReportControl@@MAEHAAVCStringArray@@PAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
