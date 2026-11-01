// from server: 100% by auto
// roc 2009-06 007486f0  unit: CXTPReportControl  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007486f0
//
// 007486f0  83ec14               sub esp, 0x14
// 007486f3  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007486f7  33c0                 xor eax, eax
// 007486f9  8944240c             mov dword ptr [esp + 0xc], eax
// 007486fd  89442410             mov dword ptr [esp + 0x10], eax
// 00748701  890424               mov dword ptr [esp], eax
// 00748704  89442404             mov dword ptr [esp + 4], eax
// 00748708  89442408             mov dword ptr [esp + 8], eax
// 0074870c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00748710  89442410             mov dword ptr [esp + 0x10], eax
// 00748714  8d0424               lea eax, [esp]
// 00748717  50                   push eax
// 00748718  6ac0                 push -0x40
// 0074871a  89542414             mov dword ptr [esp + 0x14], edx
// 0074871e  e83dfdffff           call 0x748460
// 00748723  f7d8                 neg eax
// 00748725  1bc0                 sbb eax, eax
// 00748727  f7d8                 neg eax
// 00748729  83c414               add esp, 0x14
// 0074872c  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePasteFromText@CXTPReportControl@@MAEHAAVCStringArray@@PAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
